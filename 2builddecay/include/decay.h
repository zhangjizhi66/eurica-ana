//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 13 12:58:46 2013 by ROOT version 5.34/01
// from TTree tree/data
// found on file: com3050.root
//////////////////////////////////////////////////////////

#ifndef decay_h
#define decay_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TRandom3.h>
#include <map>
//using namespace std;

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class decay {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           bx;
   Int_t           by;
   Int_t           bz;
   Long64_t        bts;
   Int_t           ionx[8];
   Int_t           iony[8];
   Int_t           bnaie[3];
   Int_t           bnait[3];
   Double_t        bdelta;
   Double_t        btof;
   Double_t        bbeta1;
   Double_t        bbeta2;
   Double_t        baoq;
   Double_t        bzet;

   Long64_t        ts;
   Int_t           ndecayhit;
   Int_t           x1[2580];   //[ndecayhit]
   Int_t           x2[2580];   //[ndecayhit]
   Int_t           ex[2580];   //[ndecayhit]
   Double_t        x[2580];   //[ndecayhit]
   Int_t           y1[2580];   //[ndecayhit]
   Int_t           y2[2580];   //[ndecayhit]
   Int_t           ey[2580];   //[ndecayhit]
   Double_t        y[2580];   //[ndecayhit]
   Int_t           z[2580];   //[ndecayhit]
   Int_t           tx[2580];   //[ndecayhit]
   Int_t           ty[2580];   //[ndecayhit]

   Int_t           dssd_mulhit;
   Int_t           dssd_fire[8];
   Int_t           dssd_ex[8];
   Int_t           dssd_ey[8];
   Int_t           dssd_E;

   Long64_t        bgts;
   Int_t           bghit;
   Int_t           bgid[550];   //[bghit]
   Int_t           bgtdcs[550];   //[bghit]
   Int_t           bgtdcl[550];   //[bghit]
   Double_t        bge[550];   //[bghit]
   Double_t        bgt[550];   //[bghit]


   Int_t           bahit;
   Int_t           baid[240];   //[bahit]
   Int_t           batdcs[240];   //[bahit]
   Int_t           batdcl[240];   //[bahit]
   Double_t        bae[240];   //[bahit]
   Double_t        bat[240];   //[bahit]

   Long64_t        gts;
   Int_t           ghit;
   Int_t           gid[520];   //[ghit]
   Int_t           gtdcs[520];   //[ghit]
   Int_t           gtdcl[520];   //[ghit]
   Double_t        ge[520];   //[ghit]
   Double_t        gt[520];   //[ghit]

   Int_t           ahit;
   Int_t           aid[180];   //[ahit]
   Int_t           atdcs[180];   //[ahit]
   Int_t           atdcl[180];   //[ahit]
   Double_t        ae[180];   //[ahit]
   Double_t        at[18];   //[ahit]
   Int_t           zrun;
   Long64_t        zts;

   Int_t           nfocus;
   Double_t        delta[2];   //[nfocus]
   Double_t        angle[2];   //[nfocus]
   Int_t           npid;
   Double_t        aoq[1];   //[npid]
   Double_t        zet[1];   //[npid]
   Double_t        aaoq;
   Double_t        zzet;
   Double_t        beta[1];   //[npid]
   Int_t           aa;
   Int_t           zz;
   Int_t           nevent;
    //////
   Long64_t        bts_;
   Int_t           bx_,by_,bz_;
   Int_t           ionx_[8],iony_[8];
   //////
   Int_t           x1_,x2_,ex_,y1_,y2_,ey_,z_,tx_,ty_;
   Double_t        x_,y_,delxy;
   Int_t           delz;
   //////
   Int_t           eex,eey,ee;
   //////
   Long64_t        bgts_;
   Int_t           bghit_;
   Int_t           bgid_[550];   //[bghit]
   Int_t           bgtdcs_[550];   //[bghit]
   Int_t           bgtdcl_[550];   //[bghit]
   Double_t        bge_[550];   //[bghit]
   Double_t        bgt_[550];   //[bghit]
   /////
   Long64_t        zts_;
   /////
   Double_t        aaoq_;
   Double_t        zzet_;
   Double_t        beta_;   //[npid]
   Int_t           aa_;
   Int_t           zz_;    
   /////
   Double_t        chg,mas;
   TRandom3        ran;
   Int_t           ibeta;
   Int_t           run;
   Double_t        decaytime;
   ////
   // List of branches
   TBranch        *b_bx;   //!
   TBranch        *b_by;   //!
   TBranch        *b_bz;   //!
   TBranch        *b_bts;   //!
   TBranch        *b_ionx;   //!
   TBranch        *b_iony;   //!
   TBranch        *b_bnaie;   //!
   TBranch        *b_bnait;   //!
   TBranch        *b_bdelta;   //!
   TBranch        *b_btof;   //!
   TBranch        *b_bbeta1;   //!
   TBranch        *b_bbeta2;   //!
   TBranch        *b_baoq;   //!
   TBranch        *b_bzet;   //!
   TBranch        *b_ts;   //!
   TBranch        *b_ndecayhit;   //!
   TBranch        *b_x1;   //!
   TBranch        *b_x2;   //!
   TBranch        *b_ex;   //!
   TBranch        *b_x;   //!
   TBranch        *b_y1;   //!
   TBranch        *b_y2;   //!
   TBranch        *b_ey;   //!
   TBranch        *b_y;   //!
   TBranch        *b_z;   //!
   TBranch        *b_tx;   //!
   TBranch        *b_ty;   //!
   TBranch        *b_dssd_mulhit;   //!
   TBranch        *b_dssd_fire;   //!
   TBranch        *b_dssd_ex;   //!
   TBranch        *b_dssd_ey;   //!
   TBranch        *b_dssd_E;   //!
   TBranch        *b_bgts;   //!
   TBranch        *b_bghit;   //!
   TBranch        *b_bgid;   //!
   TBranch        *b_bgtdcs;   //!
   TBranch        *b_bgtdcl;   //!
   TBranch        *b_bge;   //!
   TBranch        *b_bgt;   //!
   TBranch        *b_bahit;   //!
   TBranch        *b_baid;   //!
   TBranch        *b_batdcs;   //!
   TBranch        *b_batdcl;   //!
   TBranch        *b_bae;   //!
   TBranch        *b_bat;   //!
   TBranch        *b_gts;   //!
   TBranch        *b_ghit;   //!
   TBranch        *b_gid;   //!
   TBranch        *b_gtdcs;   //!
   TBranch        *b_gtdcl;   //!
   TBranch        *b_ge;   //!
   TBranch        *b_gt;   //!
   TBranch        *b_ahit;   //!
   TBranch        *b_aid;   //!
   TBranch        *b_atdcs;   //!
   TBranch        *b_atdcl;   //!
   TBranch        *b_ae;   //!
   TBranch        *b_at;   //!
   TBranch        *b_zrun;   //!
   TBranch        *b_zts;   //!
   TBranch        *b_nfocus;   //!
   TBranch        *b_delta;   //!
   TBranch        *b_angle;   //!
   TBranch        *b_npid;   //!
   TBranch        *b_aoq;   //!
   TBranch        *b_zet;   //!
   TBranch        *b_aaoq;   //!
   TBranch        *b_zzet;   //!
   TBranch        *b_beta;   //!
   TBranch        *b_aa;   //!
   TBranch        *b_zz;   //!
   TBranch        *b_nevent;   //!

   decay(char *file, TTree *tree=0);
   virtual ~decay();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   //   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     SyncIonInfo(Long64_t entry);
   virtual void     SetDecayInfo(int inbeta,int ibeta);
   virtual void     TreeBranch_Ion(TTree *tree);
   virtual void     TreeBranch_Decay(TTree *tree);
   virtual void     GetTsEntry(std::map<Long64_t,Long64_t> &mbeta, std::map<Long64_t,Long64_t> &mbeam);

};

//#endif

//#ifdef decay_cxx
decay::decay(char* file,TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(file);
      if (!f || !f->IsOpen()) {
         f = new TFile(file);
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

decay::~decay()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t decay::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t decay::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void decay::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("by", &by, &b_by);
   fChain->SetBranchAddress("bz", &bz, &b_bz);
   fChain->SetBranchAddress("bts", &bts, &b_bts);

   fChain->SetBranchAddress("ts", &ts, &b_ts);
   fChain->SetBranchAddress("ndecayhit", &ndecayhit, &b_ndecayhit);
   fChain->SetBranchAddress("x1", x1, &b_x1);
   fChain->SetBranchAddress("x2", x2, &b_x2);
   fChain->SetBranchAddress("ex", ex, &b_ex);
   fChain->SetBranchAddress("x", x, &b_x);
   fChain->SetBranchAddress("y1", y1, &b_y1);
   fChain->SetBranchAddress("y2", y2, &b_y2);
   fChain->SetBranchAddress("ey", ey, &b_ey);
   fChain->SetBranchAddress("y", y, &b_y);
   fChain->SetBranchAddress("z", z, &b_z);

   fChain->SetBranchAddress("bgts", &bgts, &b_bgts);
   fChain->SetBranchAddress("bghit", &bghit, &b_bghit);
   fChain->SetBranchAddress("bgid", bgid, &b_bgid);
   fChain->SetBranchAddress("bgtdcs", bgtdcs, &b_bgtdcs);
   fChain->SetBranchAddress("bgtdcl", bgtdcl, &b_bgtdcl);
   fChain->SetBranchAddress("bge", bge, &b_bge);
   fChain->SetBranchAddress("bgt", bgt, &b_bgt);

   fChain->SetBranchAddress("bahit", &bahit, &b_bahit);
   fChain->SetBranchAddress("baid", baid, &b_baid);
   fChain->SetBranchAddress("batdcs", batdcs, &b_batdcs);
   fChain->SetBranchAddress("batdcl", batdcl, &b_batdcl);
   fChain->SetBranchAddress("bae", bae, &b_bae);
   fChain->SetBranchAddress("bat", bat, &b_bat);

   fChain->SetBranchAddress("gts", &gts, &b_gts);
   fChain->SetBranchAddress("ghit", &ghit, &b_ghit);
   fChain->SetBranchAddress("gid", gid, &b_gid);
   fChain->SetBranchAddress("gtdcs", gtdcs, &b_gtdcs);
   fChain->SetBranchAddress("gtdcl", gtdcl, &b_gtdcl);
   fChain->SetBranchAddress("ge", ge, &b_ge);
   fChain->SetBranchAddress("gt", gt, &b_gt);

   fChain->SetBranchAddress("ahit", &ahit, &b_ahit);
   fChain->SetBranchAddress("aid", aid, &b_aid);
   fChain->SetBranchAddress("atdcs", atdcs, &b_atdcs);
   fChain->SetBranchAddress("atdcl", atdcl, &b_atdcl);
   fChain->SetBranchAddress("ae", ae, &b_ae);
   fChain->SetBranchAddress("at", at, &b_at);

   fChain->SetBranchAddress("zrun", &zrun, &b_zrun);
   fChain->SetBranchAddress("zts", &zts, &b_zts);

   fChain->SetBranchAddress("aaoq", &aaoq, &b_aaoq);
   fChain->SetBranchAddress("zzet", &zzet, &b_zzet);

   fChain->SetBranchAddress("aa", &aa, &b_aa);
   fChain->SetBranchAddress("zz", &zz, &b_zz);
   fChain->SetBranchAddress("nevent", &nevent, &b_nevent);
   Notify();
}

void decay::GetTsEntry(std::map<Long64_t,Long64_t> &mbeta,std::map<Long64_t,Long64_t>&mbeam)
{
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for(Long64_t jentries=0; jentries<nentries; jentries++){
      Long64_t ientry = LoadTree(jentries);
      if(ientry<0){
         break;
      }
      nb = fChain->GetEntry(jentries);
      nbytes+=nb;

      if(ts>0)  mbeta.insert(std::pair<Long64_t,Long64_t> (ts,jentries));
      if( bts>0 && bz>-1 && bz<8 
       && bx>-1 && by>-1 && aaoq>2 && zzet>20)
	mbeam.insert(std::pair<Long64_t,Long64_t> (bts,jentries));
   }
}

void decay::SyncIonInfo(Long64_t entry)
{

   LoadTree(entry);
   GetEntry(entry);
  //bigrips 
   run=zrun; 
   zts_=zts;
   aaoq_=aaoq;
   zzet_=zzet;
   aa_=aa;
   zz_=zz;

   mas=aa+(ran.Rndm()-0.5)*0.5;
   chg=zz+(ran.Rndm()-0.5)*0.5;

   //dssd
   bx_=bx;
   by_=by;
   bz_=bz;   
   bts_=bts;
   //cout<<bts_<<" "<<bts<<endl;
   memcpy(ionx_, ionx, sizeof(ionx));
   memcpy(iony_, iony, sizeof(iony));

   //eurica
   bgts_=bgts;
   bghit_=bghit;
   memcpy(bgid_, bgid, sizeof(bgid));
   memcpy(bgtdcl_, bgtdcl, sizeof(bgtdcl));
   memcpy(bgtdcs_, bgtdcs, sizeof(bgtdcs));
   memcpy(bge_, bge, sizeof(bge));
   memcpy(bgt_, bgt, sizeof(bgt));
   
}

void decay::SetDecayInfo(int i,int ibeta1)
{  
   z_ =z[i];
   x_ =x[i];
   y_ =y[i];
   ex_=ex[i];
   ey_=ey[i];
   x1_=x1[i];
   y1_=y1[i];
   x2_=x2[i];
   y2_=y2[i];
   tx_=tx[i];
   ty_=ty[i];
   delz=abs(bz_-z_);
   delxy=sqrt((bx_-x_)*(bx_-x_)+(by_-y_)*(by_-y_)+(bz_-z_)*(bz_-z_));
   eex=dssd_ex[z_];
   eey=dssd_ey[z_];
   ee=dssd_E;
   ibeta=ibeta1;
   Double_t ms=100*1000;
   decaytime=(ts-bts_)/ms; 
}


void decay::TreeBranch_Ion(TTree *tree)
{
 
   tree->Branch("decaytime",&decaytime,"decaytime/D"); 
  //bigrips 
   tree->Branch("run", &run,  "run/I"); 
   tree->Branch("zts", &zts_, "zts/L");
   tree->Branch("aaoq",&aaoq_,"aaoq/D");
   tree->Branch("zzet",&zzet_,"zzet/D");
   tree->Branch("aa",  &aa_,  "aa/I");
   tree->Branch("zz",  &zz_,  "zz/I");
   tree->Branch("mas" ,&mas,  "mas/D");
   tree->Branch("chg", &chg,  "chg/D");   

   //dssd
   tree->Branch("bx",   &bx_,   "bx/I");
   tree->Branch("by",   &by_,   "by/I");
   tree->Branch("bz",   &bz_,   "bz/I");   
   tree->Branch("bts",  &bts_,  "bts/L");
   tree->Branch("ionx", &ionx_, "ionx[8]/I");
   tree->Branch("iony", &iony_, "iony[8]/I");

   //eurica
   tree->Branch("bgts",  &bgts_,  "bgts/L");
   tree->Branch("bghit", &bghit_, "bghit/I");
   tree->Branch("bgid",  &bgid_,  "bgid[bghit]/I");
   tree->Branch("bge",   &bge_,   "bge[bghit]/D");
   tree->Branch("bgt",   &bgt_,   "bgt[bghit]/D");

}
void decay::TreeBranch_Decay(TTree *tree)
{
   tree->Branch("ts",   &ts,   "ts/L");
   tree->Branch("ibeta", &ibeta,"ibeta/I");
   tree->Branch("x1",   &x1_,  "x1/I");
   tree->Branch("x2",   &x2_,  "x2/I");
   tree->Branch("ex",   &ex_,  "ex/I");
   tree->Branch("x",    &x_,   "x/D");
   tree->Branch("y1",   &y1_,  "y1/I");
   tree->Branch("y2",   &y2_,  "y2/I");
   tree->Branch("ey",   &ey_,  "ey/I");
   tree->Branch("y",    &y_,   "y/D");
   tree->Branch("z",    &z_,   "z/I");
   tree->Branch("delz", &delz, "delz/I");
   tree->Branch("delxy",&delxy,"delxy/D");   

   tree->Branch("eex",  &eex,  "eex/I");
   tree->Branch("eey",  &eey,  "eey/I");
   tree->Branch("ee",   &ee,   "ee/I");

   //eurica
   tree->Branch("gts",   &gts,"gts/L");

   /****** without addback ******/
   tree->Branch("ghit", &ghit, "ghit/I");
   tree->Branch("gid",  &gid,  "gid[ghit]/I");
   tree->Branch("gtdcs",&gtdcs,"gtdcs[ghit]/I");
   tree->Branch("gtdcl",&gtdcl,"gtdcl[ghit]/I");
   tree->Branch("ge",   &ge,   "ge[ghit]/D");
   tree->Branch("gt",   &gt,   "gt[ghit]/D");

   /****** with addback ******/
   tree->Branch("ahit", &ahit, "ahit/I");
   tree->Branch("aid",  &aid,  "aid[ahit]/I");
   tree->Branch("atdcs",&atdcs,"atdcs[ahit]/I");
   tree->Branch("atdcl",&atdcl,"atdcl[ahit]/I");
   tree->Branch("ae",   &ae,   "ae[ahit]/D");
   tree->Branch("at",   &at,   "at[ahit]/D");
}


Bool_t decay::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void decay::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t decay::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef decay_cxx
