
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<sstream>
#include<cmath>
#include<TProfile.h>
#include<TXMLNode.h>
#include<TRandom3.h>
#include"TFile.h"
#include"TSystem.h"
#include"TTree.h"
#include"TROOT.h"
#include"TString.h"
#include"TRandom.h"
#include "TDatime.h"
#include<signal.h>
#include "TChain.h"
//#include "TArtEventStore.hh"
#include "decay.h"
//using namespace std;

int main(int argc, char* argv[]){

   if(argc<3) {
       std::cout<<"USAGE: "<<argv[0]<<" #RUN Z A"<<std::endl;
       return 0;
   }
   int zet,mass;
   std::istringstream(argv[2])>>zet;
   std::istringstream(argv[3])>>mass;
   int runB = atoi(argv[1]);
   std::cout<<"zet="<<zet<<"  mass="<<mass<<"  run="<<runB<<std::endl;
    
   char infile[128];
   char outfile[128];
   TRandom3 r;
   //sprintf(infile,"../DecayData/decay%d.root",runB);
   sprintf(infile,"../CorrectData/decay%d.root",runB);
   sprintf(outfile,"../SeperateData/decay%02d_%03d_%04d.root",zet,mass,runB);

   std::ifstream ifinfile(infile);
   if(!ifinfile.good()) {
     std::cout<<"runnum "<<infile<<" does not exist!"<<std::endl;
     return 0;
   }else
     { ifinfile.close();}
    
   TFile *ipf1 = new TFile(infile);
   TTree *ipt1 = (TTree*)ipf1->Get("tree");
   if (!ipt1){
     std::cout<<'\n'<<"empty tree in "<<infile<<" !"<<'\n'<<'\n';
     return 0;
   }
     
   decay bg(infile);

   TFile *rootfile = new TFile(outfile,"RECREATE");
   TTree *tree = bg.fChain->CloneTree(0);
   if (bg.fChain == 0) return 0;
   Long64_t nentries = bg.fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = bg.fChain->LoadTree(jentry);
      if (ientry < 0) break;
      nb = bg.fChain->GetEntry(jentry);   nbytes += nb;

      if(bg.aa==mass&&bg.zz==zet) tree->Fill();
   }
   rootfile->Write();
   rootfile->Close();
}
