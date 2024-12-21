/************************************
combine root files for bigrips and Go4,
************************************/

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

int main(int argc, char* argv[])
{
   if (argc < 1) {
       std::cout<<"USAGE: "<<argv[0]<<" #RUN"<<std::endl;
       return 0;
   }
   int runB = atoi(argv[1]);
   std::cout<<"run="<<runB<<'\n';
    
   TRandom3 r;
   char infile[128];
   char outfile[128];

   sprintf(infile,"../DecayData/decay%d.root",runB);
   sprintf(outfile,"../CorrectData/decay%d.root",runB);

   std::ifstream ifinfile(infile);
   if (!ifinfile.good()) {
     std::cout<<"runnum "<<infile<<" does not exist!"<<'\n'<<'\n';
     return 0;
   }
   else
     ifinfile.close();
   
   TFile *ipf1 = new TFile(infile);
   TTree *ipt1 = (TTree*)ipf1->Get("tree");
   if (!ipt1){
     std::cout<<'\n'<<"empty tree in "<<infile<<" !"<<'\n'<<'\n';
     return 0;
   }
     
   decay bga(infile);
   bga.ReadSlew();

   TFile *rootfile = new TFile(outfile,"RECREATE");
   TTree *tree = bga.fChain->CloneTree(0);
   if (bga.fChain == 0) return 0;
   Long64_t nentries = bga.fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry = 0; jentry < nentries; jentry++) {
      Long64_t ientry = bga.fChain->LoadTree(jentry);
      if (ientry < 0) break;
      nb = bga.fChain->GetEntry(jentry);
      nbytes += nb;

      bga.Correct(jentry);
      tree->Fill();
   }
   rootfile->Write();
   rootfile->Close();
}
