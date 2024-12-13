
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

#include"TFile.h"
#include"TSystem.h"
#include"TTree.h"
#include"TROOT.h"
#include"TString.h"
#include"TRandom.h"
#include "TDatime.h"
#include<signal.h>
#include "TChain.h"
#include "TString.h"
//#include "TArtEventStore.hh"
#include "decay.h"

int main(int argc, char* argv[]){

   if(argc<2){
     std::cout<<"USAGE: "<<argv[0]<<" #RUN [# event]"<<std::endl;
      return 0;
   }
   int nevents=0;
   if(argc==3) {
     std::string ss=argv[2];
     std::istringstream(ss)>>nevents;
   }
   int runB = atoi(argv[1]);
   TString run=argv[1];
   TString infile="../CombineData/combine"+run+".root";
   TString outfile="../DecayData/decay"+run+".root";
   std::ifstream ifinfile(infile);
   if(!ifinfile.good()) {
     std::cout<<"runnum "<<runB<<" does not exist!"<<std::endl;
     return 0;
   }else
     { ifinfile.close();}
     
   decay Decay(const_cast<char*>(infile.Data()));

   std::map<Long64_t,Long64_t> mbeta,mbeam; //time stamp table for beam and dssd
   std::map<Long64_t,Long64_t>::iterator imbeta,imbeam;

   TFile *rootfile = new TFile(outfile,"RECREATE");
   TTree *tree = new TTree("tree","data");
   Decay.TreeBranch_Ion(tree);
   Decay.TreeBranch_Decay(tree);

   Long64_t nevent;
   tree->Branch("nevent",&nevent,"nevent/I");
   std::cout<<"start building time table for decay and beam in run="<<runB<<std::endl;
   Decay.GetTsEntry(mbeta,mbeam);

   std::cout<<mbeta.size()<<" events for beta_dssd"<<std::endl;
   std::cout<<mbeam.size()<<" events for beam_dssd"<<std::endl;
   Long64_t second=100*1000*1000;
   Long64_t tsDecayL = 0*second;
   Long64_t tsDecayU = 5*second;
   imbeta=mbeta.begin();
   imbeam=mbeam.begin();
   for(int i=0;i<10;i++) {
     //std::cout<<imbeta->first<<" "<<imbeam->first<<std::endl;;
     imbeta++;
     imbeam++;
   }
   nevent=0;
   for(imbeam=mbeam.begin();imbeam!=mbeam.end();imbeam++){
      nevent++;
       if(nevents!=0 && nevents==nevent) break;
      //for heavy ion implantation
       Decay.SyncIonInfo(imbeam->second);
       //Long64_t a1=Decay.bts_;
       int bx= Decay.bx, by=Decay.by, bz=Decay.bz;
       Long64_t ts1 = imbeam->first + tsDecayL;
       Long64_t ts2 = imbeam->first + tsDecayU;
       imbeta = mbeta.lower_bound(ts1);
       int ibeta=0,ihit=0;
       while(1) {
         if (!(imbeta!=mbeta.end()&& imbeta->first < ts2)){
             if (ibeta==0){
                 Decay.decaytime=-1;
                 Decay.ibeta=0;
                 Decay.ts=-1;
                 Decay.delz=-1;
                 Decay.delxy=-1;
                 Decay.ex_=-1; Decay.x1_=-1; Decay.x2_=-1; Decay.x_=-1;
                 Decay.ey_=-1; Decay.y1_=-1; Decay.y2_=-1; Decay.y_=-1;
                 Decay.z_=-1;
                 Decay.eex=0; Decay.eey=0; Decay.ee=0;
                 Decay.gts=-1; Decay.ghit=0; Decay.ahit=0;
                 
                 tree->Fill();
             }
             break;
         }
         //Long64_t b1=Decay.bts_;
         Decay.GetEntry(imbeta->second);  //for all beta
         //Long64_t c1=Decay.bts_;
         Int_t delz=2;
         Int_t ndhit=-1;

         for(int i=0;i<Decay.ndecayhit;i++) {
           Int_t    x1=Decay.x1[i],  y1=Decay.y1[i];
           Int_t    x2=Decay.x2[i],  y2=Decay.y2[i], z=Decay.z[i];
           Int_t    delz1= abs(bz-z);
           bool xyco1 = bx>=x1-1 &&bx<=x2+1 && by>=y1-1 && by<=y2+1;
           if(xyco1)
             if(delz1<delz){
               ndhit=i;delz=delz1;
              }
	      }
         imbeta++;
         ihit++;
         if(ndhit<0) continue;
         ibeta++;

         Decay.SetDecayInfo(ndhit,ibeta);
         // std::cout<<ihit<<" "<<a1<<" "<<b1<<" "<<c1 <<std::endl;
         tree->Fill();
       }
   }
   rootfile->Write();
   rootfile->Close();
   printf("\n\n********************************builddecay %d done!********************************************\n\n",runB);
}
