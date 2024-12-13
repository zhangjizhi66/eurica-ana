
#ifndef decay_h
#define decay_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class decay {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        decaytime;
   Int_t           run;
   Long64_t        zts;
   Double_t        aaoq;
   Double_t        zzet;
   Int_t           aa;
   Int_t           zz;
   Double_t        mas;
   Double_t        chg;
   Int_t           bx;
   Int_t           by;
   Int_t           bz;
   Long64_t        bts;
   Int_t           ionx[8];
   Int_t           iony[8];
   Long64_t        bgts;
   Int_t           bghit;
   Int_t           bgid[480];   //[bghit]
   Double_t        bge[480];   //[bghit]
   Double_t        bgt[480];   //[bghit]
   Long64_t        ts;
   Int_t           ibeta;
   Int_t           x1;
   Int_t           x2;
   Int_t           ex;
   Double_t        x;
   Int_t           y1;
   Int_t           y2;
   Int_t           ey;
   Double_t        y;
   Int_t           z;
   Int_t           delz;
   Double_t        delxy;
   Int_t           eex;
   Int_t           eey;
   Int_t           ee;
   Long64_t        gts;
   Int_t           ghit;
   Int_t           gid[420];   //[ghit]
   Int_t           gtdcs[420];   //[ghit]
   Int_t           gtdcl[420];   //[ghit]
   Double_t        ge[420];   //[ghit]
   Double_t        gt[420];   //[ghit]
   Int_t           ahit;
   Int_t           aid[150];   //[ahit]
   Int_t           atdcs[150];   //[ahit]
   Int_t           atdcl[150];   //[ahit]
   Double_t        ae[150];   //[ahit]
   Double_t        at[150];   //[ahit]
   Int_t           nevent;

   // List of branches
   TBranch        *b_decaytime;   //!
   TBranch        *b_run;   //!
   TBranch        *b_zts;   //!
   TBranch        *b_aaoq;   //!
   TBranch        *b_zzet;   //!
   TBranch        *b_aa;   //!
   TBranch        *b_zz;   //!
   TBranch        *b_mas;   //!
   TBranch        *b_chg;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_by;   //!
   TBranch        *b_bz;   //!
   TBranch        *b_bts;   //!
   TBranch        *b_ionx;   //!
   TBranch        *b_iony;   //!
   TBranch        *b_bgts;   //!
   TBranch        *b_bghit;   //!
   TBranch        *b_bgid;   //!
   TBranch        *b_bge;   //!
   TBranch        *b_bgt;   //!
   TBranch        *b_ts;   //!
   TBranch        *b_ibeta;   //!
   TBranch        *b_x1;   //!
   TBranch        *b_x2;   //!
   TBranch        *b_ex;   //!
   TBranch        *b_x;   //!
   TBranch        *b_y1;   //!
   TBranch        *b_y2;   //!
   TBranch        *b_ey;   //!
   TBranch        *b_y;   //!
   TBranch        *b_z;   //!
   TBranch        *b_delz;   //!
   TBranch        *b_delxy;   //!
   TBranch        *b_eex;   //!
   TBranch        *b_eey;   //!
   TBranch        *b_ee;   //!
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
   TBranch        *b_nevent;   //!

   decay(char *file,TTree *tree=0);
   virtual ~decay();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   // virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

//#endif

//#ifdef decay_cxx
decay::decay(char *file,TTree *tree) : fChain(0) 
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

   fChain->SetBranchAddress("decaytime", &decaytime, &b_decaytime);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("zts", &zts, &b_zts);
   fChain->SetBranchAddress("aaoq", &aaoq, &b_aaoq);
   fChain->SetBranchAddress("zzet", &zzet, &b_zzet);
   fChain->SetBranchAddress("aa", &aa, &b_aa);
   fChain->SetBranchAddress("zz", &zz, &b_zz);
   fChain->SetBranchAddress("mas", &mas, &b_mas);
   fChain->SetBranchAddress("chg", &chg, &b_chg);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("by", &by, &b_by);
   fChain->SetBranchAddress("bz", &bz, &b_bz);
   fChain->SetBranchAddress("bts", &bts, &b_bts);
   fChain->SetBranchAddress("ionx", ionx, &b_ionx);
   fChain->SetBranchAddress("iony", iony, &b_iony);
   fChain->SetBranchAddress("bgts", &bgts, &b_bgts);
   fChain->SetBranchAddress("bghit", &bghit, &b_bghit);
   fChain->SetBranchAddress("bgid", bgid, &b_bgid);
   fChain->SetBranchAddress("bge", bge, &b_bge);
   fChain->SetBranchAddress("bgt", bgt, &b_bgt);
   fChain->SetBranchAddress("ts", &ts, &b_ts);
   fChain->SetBranchAddress("ibeta", &ibeta, &b_ibeta);
   fChain->SetBranchAddress("x1", &x1, &b_x1);
   fChain->SetBranchAddress("x2", &x2, &b_x2);
   fChain->SetBranchAddress("ex", &ex, &b_ex);
   fChain->SetBranchAddress("x", &x, &b_x);
   fChain->SetBranchAddress("y1", &y1, &b_y1);
   fChain->SetBranchAddress("y2", &y2, &b_y2);
   fChain->SetBranchAddress("ey", &ey, &b_ey);
   fChain->SetBranchAddress("y", &y, &b_y);
   fChain->SetBranchAddress("z", &z, &b_z);
   fChain->SetBranchAddress("delz", &delz, &b_delz);
   fChain->SetBranchAddress("delxy", &delxy, &b_delxy);
   fChain->SetBranchAddress("eex", &eex, &b_eex);
   fChain->SetBranchAddress("eey", &eey, &b_eey);
   fChain->SetBranchAddress("ee", &ee, &b_ee);
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
   fChain->SetBranchAddress("nevent", &nevent, &b_nevent);
   Notify();
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
