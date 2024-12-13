// Last Modified 20220503

// Generate background spectrum and gg-matrix using Radware approch.
// Author: Li Zhihuan, Peking University

//> root -l gate2matrix.C
//root[1] genBackground() //generate background spectrum
//root[2] gate2mat() // gg-matrix

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TString.h"
#include "TROOT.h"
#include "TSpectrum.h"
#include <iostream>
#include <ctime>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
using namespace std;
/*
//input 
TString fInName = "root/bbhist.root";//root file 
TString h2name = "hg2xy_raw";//gg-matrix 
//output 
TString fOutName = "root/bbmatrix_raw.root";//root file
*/

//input 
TString fInName = "root/gpdhist.root";//root file 
TString h2name = "hg2xy_raw";//gg-matrix 
//output 
TString fOutName = "root/gpdmatrix_raw.root";//root file

////////////////////////////////////////////////////////
TH2F *hg2xy=NULL;
int xnbin,ynbin; 
float xmin,ymin;
float xmax,ymax;

//1d total projection
TH1F *hg2x=NULL,  *hg2y=NULL;
TH1F *hg2xb=NULL, *hg2yb=NULL;
TH1F *hg2xp=NULL, *hg2yp=NULL;

//matrix
TH2F *hg2xyb=NULL;
TH2F *hg2xyp=NULL;

//canvas
TCanvas *c1;
TPad    *xPad, *yPad;

void xgenBackground(int res=10, int nosmoothing=0);
void ygenBackground(int res=18, int nosmoothing=0);
void write();

void gate2pdmatrix()
{
  TFile *fin = new TFile(fInName.Data());
  if ((!fin) || (fin->IsZombie())) {
    cout<<fInName.Data()<<" does not exist!"<<endl;
    return;
  }
  hg2xy = (TH2F*)fin->Get(h2name.Data()); //original gamma-gamma matrix
  if(!hg2xy) return;
  
  xnbin = hg2xy->GetNbinsX();
  xmin = hg2xy->GetXaxis()->GetBinLowEdge(1);
  xmax = hg2xy->GetXaxis()->GetBinLowEdge(xnbin+1);
    
  ynbin = hg2xy->GetNbinsY();
  ymin = hg2xy->GetYaxis()->GetBinLowEdge(1);
  ymax = hg2xy->GetYaxis()->GetBinLowEdge(ynbin+1);
    
  //1d total projection
  hg2x = (TH1F*)hg2xy->ProjectionX("hg2x",1,ynbin);//total projection spectrum
  hg2x->SetTitle("x Total Projection Spectrum");
  cout<<"x: "<<xnbin<<","<<xmin<<","<<xmax<<endl;
  
  hg2y = (TH1F*)hg2xy->ProjectionY("hg2y",1,xnbin);//total projection spectrum
  hg2y->SetTitle("y Total Projection Spectrum");
  cout<<"y: "<<ynbin<<","<<ymin<<","<<ymax<<endl;
  
  //matrix
  hg2xyb = new TH2F("hg2xyb","bg matrix",xnbin,xmin,xmax,ynbin,ymin,ymax);//background matrix
  hg2xyp = new TH2F("hg2xyp","bg subtracted matrix",xnbin,xmin,xmax,ynbin,ymin,ymax);//background subtracted matrix
    
  //canvas
  c1 = new TCanvas("c1","Total Projection Spectrum",800,800);
  c1->Divide(1,2);
  xPad = (TPad*)c1->GetPad(1);
  yPad = (TPad*)c1->GetPad(2);
  
  xgenBackground();
  ygenBackground();
  
  cout<<'\n'<<RED<<"(1) If the shape of the background spectrum looks OK, then run write() "<<'\n';
  cout<<"(2) If not then run xgenBackground(res) and/or ygenBackground(res) with modified res value until the (1) is meet." <<RESET<<'\n'<<'\n';
}

void xgenBackground(int res, int nosmoothing)
{
  if (hg2xb!=NULL) delete hg2xb;
  if (hg2xp!=NULL) delete hg2xp;
    
  xPad->cd();

  TSpectrum *sa = new TSpectrum(1000);
  if (nosmoothing)
      hg2xb = (TH1F*)sa->Background(hg2x,res,"nosmoothing");//background spectrum, user
  else
      hg2xb = (TH1F*)sa->Background(hg2x,res);
  hg2xp = new TH1F("hg2xp","",xnbin,xmin,xmax);//peak spectrum
  hg2x->Sumw2(0);
  hg2x->Draw();
  hg2xb->Draw("same");
  hg2xp->Add(hg2x,hg2xb,1,-1); 
}

void ygenBackground(int res, int nosmoothing)
{
  if (hg2yb!=NULL) delete hg2yb;
  if (hg2yp!=NULL) delete hg2yp;
    
  yPad->cd();

  TSpectrum *sa = new TSpectrum(1000);
  if (nosmoothing)
      hg2yb = (TH1F*)sa->Background(hg2y,res,"nosmoothing");//background spectrum, user
  else
      hg2yb = (TH1F*)sa->Background(hg2y,res);
  hg2yp = new TH1F("hg2yp","",ynbin,ymin,ymax);//peak spectrum
  hg2y->Sumw2(0);
  hg2y->Draw();
  hg2yb->Draw("same");
  hg2yp->Add(hg2y,hg2yb,1,-1); 
}

void write()
{
  //make background matrix - RADWARE approch
  Double_t T,Pi,Pj,pi,pj,bi,bj,Bij;
  T = hg2x->Integral();
  // int N=hg2x->GetNbinsX();
  for (int i=1; i<=xnbin; i++)
    for (int j=1; j<=ynbin; j++){
      // Pi=hg2x->GetBinContent(i);
      // Pj=hg2x->GetBinContent(j);
      pi = hg2xp->GetBinContent(i);
      pj = hg2yp->GetBinContent(j);
      bi = hg2xb->GetBinContent(i);
      bj = hg2yb->GetBinContent(j);
      // Bij = (bi*pj+bi*bj)/T;
      Bij = (bi*pj+bi*bj+bj*pi)/T;
      Double_t x = hg2x->GetBinCenter(i);
      Double_t y = hg2x->GetBinCenter(j);       
      hg2xyb->Fill(x,y,Bij);
    }
  hg2xyp->Sumw2(0);
  hg2xyp->Add(hg2xy,hg2xyb,1,-1);

  //output to ROOT file
  TFile *fout = new TFile(fOutName.Data(),"RECREATE");//user
  hg2xy->SetName("hg2xy");
  hg2xy->Write();
  hg2xyp->Write();
  hg2x->Write();
  hg2xyb->Write();
  fout->Close();
  cout<<"Write Histgrams hg2xyp, hg2x and hg2xb to "<<fOutName.Data()<<endl;
  gROOT->ProcessLine(".q");
}
