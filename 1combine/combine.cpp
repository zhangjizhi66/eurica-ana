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

#include"TFile.h"
#include"TSystem.h"
#include"TTree.h"
#include"TROOT.h"
#include"TString.h"
#include"TRandom3.h"
#include "TDatime.h"
#include<signal.h>
#include "TChain.h"
//#include "TArtEventStore.hh"
#include "dssd.h"
#include "eurica.h"
#include "bigrips.h"

using namespace std;

int main(int argc, char* argv[]){
   if (argc < 2){
      cout<<"USAGE: "<<argv[0]<<" #RUN [# event]"<<endl;
      return 0;
   }
    
   TRandom3 *gr = new TRandom3(0);
    
   int nevents = 0;
   if (argc == 3) {
      string ss = argv[2];
      istringstream(ss)>>nevents;
   }
   int runB = atoi(argv[1]);
   TString run = argv[1];
   run += ".root";
   TString path="../RawData/";
   TString gfile=path+"euroball/";
   TString dfile=path+"dssd/";
   TString bfile=path+"bigrips/";
   TString ofile="../CombineData/combine"+run;
   TString dpath;
   if(runB>999  && runB<2000) dpath="ni78test/";
   if(runB>1999 && runB<3000) dpath="pd128test/";
   if(runB>2999 && runB<4000) dpath="sn136test/";
   if(runB>3999 && runB<4100) dpath="rh123test/";
   if(runB>4099 && runB<5000) dpath="nb115test/";
   if(runB>4999 && runB<6000) dpath="cu81test/";
   dfile += dpath+"WASABI"+run;
   gfile += "go4_"+run;
   bfile += "bigrips_run"+run;

   ifstream ifbeam(bfile), ifgamma(gfile), ifdssd(dfile);
   if (!(ifbeam.good() && ifgamma.good() && ifdssd.good())) {
      if (!ifbeam.good()) cout<<bfile<<" does not exist!"<<endl;
      if (!ifgamma.good()) cout<<gfile<<" does not exist!"<<endl;
      if (!ifdssd.good()) cout<<dfile<<" does not exist!"<<endl;
      printf("\n\n***************************combine %d FAILED!****************************\n\n",runB);
      return 0;
   }
   else {
      ifbeam.close();
      ifgamma.close();
      ifdssd.close();
   }
      
   dssd Dssd(const_cast<char*>(dfile.Data()));
   eurica Gamma(const_cast<char*>(gfile.Data()));
   bigrips Beam(const_cast<char*>(bfile.Data()));

   map<Long64_t,Long64_t> mtsd,mtsg,mtsb,mtsbeta,mtsbeam; //time stamp table for beam and dssd
   map<Long64_t,Long64_t>::iterator imtsd,imtsg,imtsb,imtsbeta,imtsbeam;

   map<Long64_t,Long64_t > mdg,mdb; //time stamp correlation between beam and dssd
   map<Long64_t,Long64_t>::iterator imdg,imdb;

   TFile *rootfile = new TFile(ofile,"RECREATE");
   TTree *tree = new TTree("tree","data");
   Dssd.TreeBranch_Ion(tree);
   Dssd.TreeBranch_Decay(tree);
   Gamma.TreeBranch_Ion(tree);
   Gamma.TreeBranch_Decay(tree);
   Beam.TreeBranch(tree);   
   Long64_t nevent;
   tree->Branch("nevent", &nevent, "nevent/I");

   Dssd.GetTsEntry(mtsd,mtsbeta,mtsbeam);
   Gamma.GetTsEntry(mtsg);
   Beam.GetTsEntry(mtsb);
   Long64_t tswindL = -100;
   Long64_t tswindU = 1000;
   for (imtsd = mtsd.begin(); imtsd != mtsd.end(); imtsd++){
      Long64_t ts1 = imtsd->first + tswindL;
      Long64_t ts2 = imtsd->first + tswindU;
      imtsg = mtsg.lower_bound(ts1);
      if (imtsg != mtsg.end() && imtsg->first < ts2)  
         mdg[imtsd->second] = imtsg->second;
         imtsb = mtsb.lower_bound(ts1);
         if (imtsb != mtsb.end() && imtsb->first < ts2)  
             mdb[imtsd->second]=imtsb->second;
   }
   cout<<mtsd.size()<<" events for dssd"<<endl;
   cout<<mtsbeta.size()<<" events for beta_dssd"<<endl;
   cout<<mtsbeam.size()<<" events for beam_dssd"<<endl;
   cout<<mtsb.size()<<" events for bigrips"<<endl;
   cout<<mtsg.size()<<" events for gamma"<<endl;
   cout<<"nentries = "<<mdg.size()<<" for dssd x gamma,"
       <<Int_t(Float_t(mdg.size())/mtsd.size()*100)<<"% of dssd in run="
       <<runB<<endl;
   cout<<"nentries = "<<mdb.size()<<" for dssd x bigrips,"
       <<Int_t(Float_t(mdb.size())/mtsd.size()*100)<<"% of dssd in run="
       <<runB<<endl;

   nevent = 0;
   Int_t njevent = 0;
   for (imtsd = mtsd.begin(); imtsd != mtsd.end(); imtsd++){
      nevent++;
      if (nevents != 0 && nevents == nevent) break;
      //for heavy ion implantation
       Gamma.ResetIon();
       Gamma.ResetDecay();
       Dssd.ResetIon();
       Dssd.ResetDecay();
       Beam.ResetBigRIPS(); 
       int jj = 0;
       //dssd-bigrips
       imdb = mdb.find(imtsd->second);
       if (imdb != mdb.end()) {//find beam-bigrips
           jj++;
           Beam.GetBigRIPSInfo(imdb->second); 
           Dssd.GetIonInfo(imdb->first);
           imdg=mdg.find(imdb->first);
           if (imdg != mdg.end()) Gamma.GetIonInfo(imdg->second);
       }
       //dssd-beta
       imtsbeta = mtsbeta.find(imtsd->second);
       if (imtsbeta != mtsbeta.end()) {//find beta
           jj++;
           Dssd.GetDecayInfo(imtsd->second);  //for all beta
           imdg = mdg.find(imtsd->second);
           if (imdg != mdg.end()) Gamma.GetDecayInfo(imdg->second);
       }
       
       //j==0 events can not identified as ion or beta either.
       //j==2 events with random conincidence of ion and beta.
       if(jj == 0 || jj == 2) {
           njevent++;
           continue;
       }
       
       // correct for Run 3000-3122
       if (runB >= 3000 && runB <= 3122){
           for (int hit=0; hit<Gamma.ghit; hit++) Gamma.gt[hit] = 25.*(Gamma.gt[hit]+gr->Uniform(0,1));
           for (int hit=0; hit<Gamma.ahit; hit++) Gamma.at[hit] = 25.*(Gamma.at[hit]+gr->Uniform(0,1));
           for (int hit=0; hit<Gamma.bghit; hit++) Gamma.bgt[hit] = 25.*(Gamma.bgt[hit]+gr->Uniform(0,1));
           for (int hit=0; hit<Gamma.bahit; hit++) Gamma.bat[hit] = 25.*(Gamma.bat[hit]+gr->Uniform(0,1));
       }
       
       tree->Fill();
   }
   cout<<"fake events:"<<njevent<<endl;
   rootfile->Write();
   rootfile->Close();
   printf("\n\n***************************combine %d done!****************************\n\n",runB);
}
