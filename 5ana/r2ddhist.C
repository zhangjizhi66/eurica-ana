// Last Modified zhangjizhi, 20220503

// Make 2-fold gg-matrix(TH2) from ROOT files(TTree) 
// Author: Li Zhihuan, Peking University

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TString.h"
#include "TROOT.h"
#include "TSystem.h"
#include <iostream>
#include <ctime>

using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.

//input
//TString fNameFormat = "../SeperateData/decay47_128.root";
TString fNameFormat = "/data/d2/zhli/hepfarm/ur12ana/test/srootall/bg47_128_all.root";
TString treeName = "tree";

//gamma Tree Branches in the input file
TString ghitBranch = "ghit";//hit
TString geBranch = "ge";//ge[hit]
TString gtBranch = "gt";//gt[hit]

//output
int nBin = 1500;
int MaxE = 1500;
TString fOutName = "root/ddhist.root";

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.
TH2F *h2xy_raw = nullptr;
TCutG *delaycut = nullptr;
clock_t start,stop;

void root2g2hist();

void r2ddhist()
{
    start = clock();
    h2xy_raw = new TH2F("hg2xy","data",nBin,0,MaxE,nBin,0,MaxE);
    
    gROOT->ProcessLine(".x bdelaycut.C");
    delaycut = (TCutG*)gROOT->FindObject("delaycut");
    
    root2g2hist();

    TFile *fout = new TFile(fOutName.Data(),"recreate");//output file 
    h2xy_raw->Write();
    fout->Close();
    cout<<"Write Histgrams to "<<fOutName.Data()<<'\n';

    stop=clock();
    double seconds=(double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Time taken by program is : "<<seconds<<" seconds."<<'\n'<<"Done!"<<'\n';
    gROOT->ProcessLine(".q");
}

void root2g2hist()
{
    if(gSystem->AccessPathName(fNameFormat.Data())){
        cout <<fNameFormat.Data()<< " does not exist!" <<endl;
        return 0;
    }
    start = clock();

    TFile *f = new TFile(fNameFormat.Data()); 
    TTree *tree = (TTree*)f->Get(treeName.Data());
    
    Int_t ghit,ibeta;
    Double_t ge[1000];
    Double_t gt[1000];
    tree->SetBranchAddress(ghitBranch.Data(),&ghit); //hit
    tree->SetBranchAddress(geBranch.Data(),&ge);     //energy
    tree->SetBranchAddress(gtBranch.Data(),&gt);     //time
    //tree->SetBranchAddress("ibeta",&ibeta);     //time
    
    Long64_t nentries=tree->GetEntries();
    for (Long64_t jentry=0;jentry<nentries;jentry++){
        tree->GetEntry(jentry);
        //if (ibeta > 1) continue;
        if (ghit < 1) continue;
        
        for (int i=0;i<ghit;i++)
            for (int j=0;j<ghit;j++) {
                if(i==j) continue;
                if(ge[i]<20 || ge[i]>MaxE) continue;
                if(ge[j]<20 || ge[j]>MaxE) continue;
                
                //if (!delaycut->IsInside(gt[i],ge[i])) continue;
                //if (!delaycut->IsInside(gt[j],ge[j])) continue;
                if (gt[i]>-150 || gt[i]<-10000) continue;
                if (gt[j]>-150 || gt[j]<-10000) continue;
                
                // coincidence
                float dgt = 200;
                if (abs(gt[i]-gt[j]) > dgt) continue;
                
                h2xy_raw->Fill(ge[i],ge[j]);
            }
    }
}
