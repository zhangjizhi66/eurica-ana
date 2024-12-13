// 子核与孙子核的关联

// Last Modified zhangjizhi, 20220609

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
TString fNameFormat = "../MergedData/decay47_128.root";
TString treeName = "tree";

//gamma Tree Branches in the input file
TString ghitBranch = "ahit";//hit
TString geBranch = "ae";//ge[hit]
TString gtBranch = "at";//gt[hit]

//output
int nBin = 1500;
int MaxE = 1500;
TString fOutName = "root/cchist.root";

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.
TH2F *h2xy_raw,*h2xy_bg,*h2xy_bgsub;
TH2F *h2edt;
clock_t start,stop;

void root2g2hist();

void r2cchist()
{
    start = clock();
    h2xy_raw = new TH2F("hg2xy_raw","daughter:parent raw data",nBin,0,MaxE,nBin,0,MaxE);
    h2xy_bg = new TH2F("hg2xy_bg","daughter:parent bg data",nBin,0,MaxE,nBin,0,MaxE);
    h2xy_bgsub = new TH2F("hg2xy_bgsub","daughter:parent bgsub data",nBin,0,MaxE,nBin,0,MaxE);
    
    h2edt = new TH2F("h2edt","decaytime of daughter - E",nBin,0,MaxE,50,0,4000);
    
    root2g2hist();

    TFile *fout = new TFile(fOutName.Data(),"recreate");//output file 
    h2xy_raw->Write();
    h2xy_bg->Write();
    h2xy_bgsub->Write();
    h2edt->Write();
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
    
    Int_t ghit;
    Double_t ge[1000];
    Double_t gt[1000];
    Double_t decaytime;
    Int_t ibeta;
    tree->SetBranchAddress(ghitBranch.Data(),&ghit); //hit
    tree->SetBranchAddress(geBranch.Data(),&ge);     //energy
    tree->SetBranchAddress(gtBranch.Data(),&gt);     //time
    tree->SetBranchAddress("decaytime",&decaytime);
    tree->SetBranchAddress("ibeta",&ibeta);
    
    Double_t parent_halflife = 60;     // ms
    Double_t daughter_halflife = 280;  // ms
    
    std::vector<double> e_parent,e_daughter,ebg_daughter;
    Double_t t0_daughter = -1;
    
    Long64_t nentries=tree->GetEntries();
    for (Long64_t ientry=0; ientry<nentries; ientry++){  // parent
        tree->GetEntry(ientry);
        if (decaytime > 3*parent_halflife) continue;     // parent window
        
        t0_daughter = decaytime;   //if (ientry<100) std::cout<<decaytime<<'\n';
        for (int i=0;i<ghit;i++){
            if (ge[i]<20 || ge[i]>MaxE) continue;
            e_parent.push_back(ge[i]);
        }
        
        for (Long64_t jentry=ientry+1; jentry<nentries; jentry++){   // daughter
            tree->GetEntry(jentry);
            if (ibeta == 1) break;
            
            if (decaytime-t0_daughter < 3*daughter_halflife){      // daughter window
                for (int i=0;i<ghit;i++){
                    if (ge[i]<20 || ge[i]>MaxE) continue;
                    e_daughter.push_back(ge[i]);
                }
            }
            else if (decaytime-t0_daughter > 3500 && decaytime-t0_daughter < 3500+3*daughter_halflife){  // daughter bg window
                for (int i=0;i<ghit;i++){
                    if (ge[i]<20 || ge[i]>MaxE) continue;
                    ebg_daughter.push_back(ge[i]);
                }
            }
            
            for (double e0 : e_parent)
                h2edt->Fill(e0, decaytime-t0_daughter);
        }

        if (!e_parent.empty() && !e_daughter.empty()){  //if (jentry<100) std::cout<<"out!"<<'\n';
            for (double e1 : e_parent)
                for (double e2 : e_daughter)
                    h2xy_raw->Fill(e1,e2);
        }
        if (!e_parent.empty() && !ebg_daughter.empty()){  //if (jentry<100) std::cout<<"out!"<<'\n';
            for (double e1 : e_parent)
                for (double e2 : ebg_daughter)
                    h2xy_bg->Fill(e1,e2);
        }
        e_parent.clear();
        e_daughter.clear();
        ebg_daughter.clear();
        t0_daughter = -1;      //if (ientry<100) std::cout<<'\n';
    }
    h2xy_bgsub->Add(h2xy_raw,h2xy_bg,1,-1);
}
