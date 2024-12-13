// Last Modified zhangjizhi 20220504

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

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.

//input
TString fNameFormat = "../MergedData/decay47_128.root";
TString treeName = "tree";
//gamma Tree Branches in the input file
TString ghitBranch = "ahit";//hit
TString geBranch = "ae";//ge[hit]
TString gtBranch = "at";//gt[hit]

//output
int nBin = 3500;
int MaxE = 3500;
TString fOutName = "root/gpdhist.root";

//TCutG
int UseCutG = 0;
TCutG *delaycut = nullptr, *promptcut = nullptr;
TString fDelayCutName = "delaycut1.C";
TString fPromptCutName = "promptcut.C";
TString DelayCutName = "delaycut";
TString PromptCutName = "promptcut";

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.
TH2F *h2xy_raw = nullptr, *h2xy_bgsub = nullptr, *h2xy_bg = nullptr;
clock_t start,stop;

void root2pdhist();

void r2pdhist()
{
    start = clock();
    if (UseCutG && !gSystem->AccessPathName(fDelayCutName.Data())){
        gROOT->ProcessLine(Form(".x %s",fDelayCutName.Data()));
        delaycut = (TCutG*)gROOT->FindObject(DelayCutName.Data());
        if (delaycut)
            std::cout<<"using TCutG for delayed gamma from "<<fDelayCutName.Data()<<" ..."<<'\n';
    }
    if (UseCutG && !gSystem->AccessPathName(fPromptCutName.Data())){
        gROOT->ProcessLine(Form(".x %s",fPromptCutName.Data()));
        promptcut = (TCutG*)gROOT->FindObject(PromptCutName.Data());
        if (promptcut)
            std::cout<<"using TCutG for prompt gamma from "<<fPromptCutName.Data()<<" ..."<<'\n';
    }
    
    h2xy_raw = new TH2F("hg2xy_raw","raw data",nBin,0,MaxE,nBin,0,MaxE);
    h2xy_bgsub = new TH2F("hg2xy_bgsub","bgsub data",nBin,0,MaxE,nBin,0,MaxE);
    h2xy_bg = new TH2F("hg2xy_bg","bg data",nBin,0,MaxE,nBin,0,MaxE);

    root2pdhist();

    TFile *fout = new TFile(fOutName.Data(),"recreate");//output file 
    h2xy_raw->Write();
    h2xy_bgsub->Write();
    h2xy_bg->Write();
    fout->Close();
    std::cout<<"Write Histgrams to "<<fOutName.Data()<<'\n';

    stop=clock();
    double seconds=(double)(stop-start)/CLOCKS_PER_SEC;
    std::cout<<"Time taken by program is : "<<seconds<<" seconds."<<'\n'<<"Done!"<<'\n';
    gROOT->ProcessLine(".q");
}

void root2pdhist()
{
    if (gSystem->AccessPathName(fNameFormat.Data())){
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
    tree->SetBranchAddress(ghitBranch.Data(),&ghit); //hit
    tree->SetBranchAddress(geBranch.Data(),&ge);     //energy
    tree->SetBranchAddress(gtBranch.Data(),&gt);     //time
    tree->SetBranchAddress("decaytime",&decaytime);
    
    Long64_t nentries=tree->GetEntries();
    for (Long64_t jentry=0;jentry<nentries;jentry++){
        tree->GetEntry(jentry);
        if (ghit<1) continue;
        for (int i=0;i<ghit;i++)
            for(int j=0;j<ghit;j++) {
                if (i==j) continue;
                if (ge[i]<20 || ge[i]>MaxE) continue;
                if (ge[j]<20 || ge[j]>MaxE) continue;
                
                double offset = 366.143;   // according to Delayed_gamma.ipynb
                
                // delayed
                if (delaycut){
                    if (!delaycut->IsInside(offset-gt[i],ge[i])) continue;
                    if (offset-gt[i] > 10000) continue;   // according to isomer's lifetime
                }
                else {
                    if (offset-gt[i] < 300) continue;
                    //if (offset-gt[i] > 10000) continue;   // according to isomer's lifetime
                    if (offset-gt[i] > 1000) continue;   // according to isomer's lifetime
                }
                
                // prompt
                if (promptcut){
                    if (!promptcut->IsInside(offset-gt[j],ge[j])) continue;
                }
                else {
                    if (offset-gt[j] < -200) continue;
                    if (offset-gt[j] > 200) continue;
                }
                
                double halflife = 60;
                if (decaytime < 3*halflife) h2xy_raw->Fill(ge[i],ge[j]);
                if (decaytime > 4000 && decaytime < 4000+3*halflife) h2xy_bg->Fill(ge[i],ge[j]);
            }
    }
    h2xy_bgsub->Add(h2xy_raw,h2xy_bg,1,-1);
}
