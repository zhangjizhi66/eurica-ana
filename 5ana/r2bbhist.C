// 重离子注入与衰变子核的关联

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
TString fOutName = "root/bbhist.root";

//TCutG
TCutG *delaycut = nullptr;
TString fDelayCutName = "bdelaycut.C";
TString DelayCutName = "delaycut";

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.
TH3I *h3xyt_raw,*h3xyt_bg,*h3xyt_bgsub;
TH3I *h3xydt;
TH2F *h2xy_raw,*h2xy_bg,*h2xy_bgsub;
TH2F *h2edt;
clock_t start,stop;

void root2g2hist();

void r2bbhist()
{
    start = clock();
    
    // cut delayed gamma of ion
    gROOT->ProcessLine(Form(".x %s",fDelayCutName.Data()));
    delaycut = (TCutG*)gROOT->FindObject(DelayCutName.Data());
    if (!delaycut){
        std::cout<<"No available TCutG from "<<fDelayCutName.Data()<<" ..."<<'\n';
        return;
    }
    
    h2xy_raw = new TH2F("hg2xy_raw","daughter:ion raw data",nBin,0,MaxE,nBin,0,MaxE);
    h2xy_bg = new TH2F("hg2xy_bg","daughter:ion bg data",nBin,0,MaxE,nBin,0,MaxE);
    h2xy_bgsub = new TH2F("hg2xy_bgsub","daughter:ion bgsub data",nBin,0,MaxE,nBin,0,MaxE);
    
    h3xyt_raw = new TH3I("h3xyt_raw","raw data",nBin,0,MaxE,nBin,0,MaxE,100,-500,8000);
    h3xyt_bg = new TH3I("h3xyt_bg","bg data",nBin,0,MaxE,nBin,0,MaxE,100,-500,8000);
    h3xyt_bgsub = new TH3I("h3xyt_bgsub","bgsub data",nBin,0,MaxE,nBin,0,MaxE,100,-500,8000);
    
    h3xydt = new TH3I("h3xydt","raw data",nBin,0,MaxE,nBin,0,MaxE,100,0,2000);
    
    h2edt = new TH2F("h2edt","decaytime of ion - E",nBin,0,MaxE,250,0,5000);
    
    root2g2hist();

    TFile *fout = new TFile(fOutName.Data(),"recreate");//output file
    h2xy_raw->Write();
    h2xy_bg->Write();
    h2xy_bgsub->Write();
    h3xyt_raw->Write();
    h3xyt_bg->Write();
    h3xyt_bgsub->Write();
    h2edt->Write();
    h3xydt->Write();
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
    
    Int_t ghit,bghit;
    Double_t ge[1000],bge[1000];
    Double_t gt[1000],bgt[1000];
    Double_t decaytime;
    Int_t ibeta;
    
    // ion
    tree->SetBranchAddress("bghit",&bghit); //hit
    tree->SetBranchAddress("bge",&bge);     //energy
    tree->SetBranchAddress("bgt",&bgt);     //time
    
    // decay
    tree->SetBranchAddress(ghitBranch.Data(),&ghit); //hit
    tree->SetBranchAddress(geBranch.Data(),&ge);     //energy
    tree->SetBranchAddress(gtBranch.Data(),&gt);     //time
    
    tree->SetBranchAddress("decaytime",&decaytime);
    tree->SetBranchAddress("ibeta",&ibeta);
    
    Double_t parent_halflife = 60;     // ms
    
    std::vector<double> e_ion,e_daughter,ebg_daughter,gt_daughter,gtbg_daughter;
    
    Long64_t nentries=tree->GetEntries();
    for (Long64_t ientry=0; ientry<nentries; ientry++){  // parent
        tree->GetEntry(ientry);
        if (ibeta == 1){     // ion
            if (!e_ion.empty() && !e_daughter.empty()){
                for (double e1 : e_ion){
                    for (unsigned int j=0; j<e_daughter.size(); j++){
                        int e2 = e_daughter[j];
                        int e2t = gt_daughter[j];
                        h2xy_raw->Fill(e1,e2);
                        h3xyt_raw->Fill(int(e1),e2,e2t);
                    }
                }
            }
            if (!e_ion.empty() && !ebg_daughter.empty()){
                for (double e1 : e_ion)
                    for (unsigned int j=0; j<ebg_daughter.size(); j++){
                        int e2 = ebg_daughter[j];
                        int e2t = gtbg_daughter[j];
                        h2xy_bg->Fill(e1,e2);
                        h3xyt_bg->Fill(int(e1),e2,e2t);
                    }
            }
            
            e_ion.clear();
            e_daughter.clear();
            ebg_daughter.clear();
            gt_daughter.clear();
            gtbg_daughter.clear();
            
            for (int i=0;i<bghit;i++){
                if (bge[i]<25 || bge[i]>MaxE) continue;
                if (!delaycut->IsInside(bgt[i],bge[i])) continue;  // dispose prompt flush
                
                e_ion.push_back(bge[i]);
            }
        }
        
        for (double e1 : e_ion)
            for (int i=0;i<ghit;i++){
                if (ge[i]<20 || ge[i]>MaxE) continue;
                h3xydt->Fill(int(e1),ge[i],decaytime);
            }
        
        if (decaytime < 3*parent_halflife && decaytime > 10){   // parent window
            for (int i=0;i<ghit;i++){
                if (ge[i]<20 || ge[i]>MaxE) continue;
                if (abs(366.143-gt[i])>30000) continue;
                e_daughter.push_back(ge[i]);
                gt_daughter.push_back(366.143-gt[i]);
            }
        }
        //else if (decaytime > 4500 && decaytime < 4500+3*parent_halflife-10){
        else if (decaytime > 4*parent_halflife && decaytime < 7*parent_halflife-10){
            for (int i=0;i<ghit;i++){
                if (ge[i]<20 || ge[i]>MaxE) continue;
                if (abs(366.143-gt[i])>30000) continue;
                ebg_daughter.push_back(ge[i]);
                gtbg_daughter.push_back(366.143-gt[i]);
            }
        }
            
        for (double e0 : e_ion)
            h2edt->Fill(e0, decaytime);
    }
    h2xy_bgsub->Add(h2xy_raw,h2xy_bg,1,-1);
    h3xyt_bgsub->Add(h3xyt_raw,h3xyt_bg,1,-1);
}
