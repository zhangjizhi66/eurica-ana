//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Mar 23 13:34:27 2013 by ROOT version 5.34/01
// from TTree tree/data
// found on file: decay3009.root
//////////////////////////////////////////////////////////

#ifndef decay_h
#define decay_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <string>
//using namespace std;

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class decay {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

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
   Int_t           bgid[60];   //[bghit]
   Double_t        bge[60];   //[bghit]
   Double_t        bgt[60];   //[bghit]
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
   Int_t           gid[60];   //[ghit]
   Int_t           gtdcs[60];   //[ghit]
   Int_t           gtdcl[60];   //[ghit]
   Double_t        ge[60];   //[ghit]
   Double_t        gt[60];   //[ghit]
   Int_t           ahit;
   Int_t           aid[18];   //[ahit]
   Int_t           atdcs[18];   //[ahit]
   Int_t           atdcl[18];   //[ahit]
   Double_t        ae[18];   //[ahit]
   Double_t        at[18];   //[ahit]
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
   virtual void     ReadSlew();
   virtual void     Correct(Long64_t jentry);
   virtual Double_t dt(int id, Double_t ge, Long64_t jentry);
   //   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
    
   Double_t p[12][7][6]; //cluster,segment,p;
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

void decay::ReadSlew()
{
   std::ifstream slew("slew_DGF.dat");
   std::string aa;
    
   for(int i=0;i<12;i++)
       for(int j=0;j<7;j++) {
           Int_t i1=0,j1=0;
           slew >> i1 >> j1 >> p[i][j][0] >> p[i][j][1] >> p[i][j][2] >> p[i][j][3] >> p[i][j][4] >> p[i][j][5];
       }
}

Double_t decay::dt(int id, Double_t ge, Long64_t jentry)
{
   int i=id/7;
   int j=id%7;
   Double_t dt1=0;
    
   if(ge>1.&&id<1000)
        dt1=p[i][j][0] + p[i][j][1]/ge + p[i][j][2]/(ge*ge) + p[i][j][3]/(ge*ge*ge)+ p[i][j][4]/(ge*ge*ge*ge) + p[i][j][5]*ge;
    else
        dt1=0;
    
    return 25.*dt1;
}

void decay::Correct(Long64_t jentry)
{
    for(int i=0;i<bghit;i++)
        if(abs(bgid[i])<1000) bgt[i]+=dt(bgid[i],bge[i],jentry);
    for(int i=0;i<ghit;i++)
        if(abs(gid[i])<1000)  gt[i]+=dt(gid[i],ge[i],jentry); 
    for(int i=0;i<ahit;i++)
        if(abs(aid[i])<1000)  at[i]+=dt(aid[i],ae[i],jentry);
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
