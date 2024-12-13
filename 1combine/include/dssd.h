//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 12 11:25:07 2012 by ROOT version 5.32/00
// from TTree WASABI/data
// found on file: /home/ur12/treefiles/sistopper/WASABI1012.root
//////////////////////////////////////////////////////////


#ifndef dssd_h
#define dssd_h

#include <TROOT.h>
#include <TFile.h>
#include <TChain.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TNamed.h>

#define NumDSSD 8
#define NumStrX 60
#define NumStrY 40
#define NumADC 24 //23ADC+1QDC
#define NumTDC 7
#define NumTDCmulti 10
#define TDC_Pos_minchan 4

const Int_t kMaxEventInfo = 1;
using namespace std; 
struct betapos
{
  Int_t ndecayhit;
  Int_t    z[300];
  Int_t    x1[300], x2[300],ex[300],tx[300];
  Int_t    y1[300], y2[300],ey[300],ty[300];
  Double_t x[300],  y[300];
};
class dssd {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           EventInfo_;
   UInt_t          EventInfo_fUniqueID[kMaxEventInfo];   //[EventInfo_]
   UInt_t          EventInfo_fBits[kMaxEventInfo];   //[EventInfo_]
   TString         EventInfo_fName[kMaxEventInfo];
   TString         EventInfo_fTitle[kMaxEventInfo];
   Int_t           EventInfo_runnumber[kMaxEventInfo];   //[EventInfo_]
   Int_t           EventInfo_eventnumber[kMaxEventInfo];   //[EventInfo_]
   TString         EventInfo_subsysname[kMaxEventInfo];
   ULong64_t       EventInfo_timestamp[kMaxEventInfo];   //[EventInfo_]
   Int_t           EventInfo_comp_val[kMaxEventInfo];   //[EventInfo_]
   UInt_t          EventInfo_fBit[kMaxEventInfo];   //[EventInfo_]
   Int_t           IF_BETA;
   Int_t           IF_ION;
   Int_t           numdssd;
   Int_t           numadc;
   Int_t           numtdc;
   Int_t           dstrx;
   Int_t           dstry;
   Int_t           scal[32];
   Int_t           dssd_E_X[8][60];   //[numdssd]
   Int_t           dssd_ch_X[8][60];   //[numdssd]
   Int_t           dssd_id_X[8][60];   //[numdssd]
   Int_t           dssd_E_Y[8][40];   //[numdssd]
   Int_t           dssd_ch_Y[8][40];   //[numdssd]
   Int_t           dssd_id_Y[8][40];   //[numdssd]
   Int_t           dssd_T_X[8][60][3];   //[numdssd]
   Int_t           dssd_T_Y[8][40][3];   //[numdssd]
   Int_t           dssd_X[8];   //[numdssd]
   Int_t           dssd_Y[8];   //[numdssd]
   Int_t           dssd_Z;  
   Int_t           dssd_fireX[8];   //[numdssd]
   Int_t           dssd_fireY[8];   //[numdssd]
   Int_t           ADC[24][32];   //[numadc]
   Int_t           TDC[7][128][3];   //[numtdc]
   Int_t           dssd_fastout[64][3];
   Int_t           DSSD_E[8][100];   //[numdssd]
   Int_t           DSSD_T[8][100][3];   //[numdssd]

   Int_t           bigrips_F3PPAC1X1;
   Int_t           bigrips_F3PPAC1X2;
   Int_t           bigrips_F3PPAC2X1;
   Int_t           bigrips_F3PPAC2X2;
   Int_t           bigrips_F5PPAC1X1;
   Int_t           bigrips_F5PPAC1X2;
   Int_t           bigrips_F5PPAC2X1;
   Int_t           bigrips_F5PPAC2X2;
   Int_t           bigrips_F3L;
   Int_t           bigrips_F3R;
   Int_t           bigrips_F7L;
   Int_t           bigrips_F7R;
   Int_t           bigrips_F11L;
   Int_t           bigrips_F11R;
   Int_t           bigrips_ICe[6];
   Int_t           Qbeta_E;
   Int_t           Qbeta_T;
   Int_t           Qveto_E;
   Int_t           Qveto_T;
   Int_t           NaI_E[3];
   Int_t           NaI_T[3];
   Double_t        bigrips_F3PPAC1_TDiffX;
   Double_t        bigrips_F3PPAC2_TDiffX;
   Double_t        bigrips_F5PPAC1_TDiffX;
   Double_t        bigrips_F5PPAC2_TDiffX;
   Double_t        bigrips_F3PPAC1_X;
   Double_t        bigrips_F3PPAC2_X;
   Double_t        bigrips_F5PPAC1_X;
   Double_t        bigrips_F5PPAC2_X;
   Double_t        bigrips_F3_X;
   Double_t        bigrips_F3_A;
   Double_t        bigrips_F5_X;
   Double_t        bigrips_F5_A;
   Double_t        bigrips_dERaw;
   Double_t        bigrips_dE;
   Double_t        pid_Delta_F3F5;
   Double_t        pid_TOF_F3F7;
   Double_t        pid_Beta_F3F5;
   Double_t        pid_Beta_F5F7;
   Double_t        pid_AoQ_F3F5;
   Double_t        pid_Zet_F11;

   Long64_t        bts;
   Int_t           ionx[NumDSSD];
   Int_t           iony[NumDSSD];
   Int_t           bx,by,bz;
   Double_t        bnaie[3],bnait[3];

   Int_t           dssd_mulhit;
   Int_t           dssd_fire[NumDSSD];
   Int_t           dssd_ex[NumDSSD];
   Int_t           dssd_ey[NumDSSD];
   Int_t           dssd_E;
   betapos         b;
   Long64_t        ts;
   //   Int_t           zz[100];
   //Int_t           xx[100];
   //Int_t           yy[100];
   //Int_t           xxe[100];
   //Int_t           yye[100];
   Int_t           nbeta;
   betapos         beta;
   Int_t        naie[3],nait[3];
   Int_t        decaytime;//decay time in ms
   Int_t        qbetae,qbetat,qvetoe,qvetot;

   // List of branches
   TBranch        *b_EventInfo_;   //!
   TBranch        *b_EventInfo_fUniqueID;   //!
   TBranch        *b_EventInfo_fBits;   //!
   TBranch        *b_EventInfo_fName;   //!
   TBranch        *b_EventInfo_fTitle;   //!
   TBranch        *b_EventInfo_runnumber;   //!
   TBranch        *b_EventInfo_eventnumber;   //!
   TBranch        *b_EventInfo_subsysname;   //!
   TBranch        *b_EventInfo_timestamp;   //!
   TBranch        *b_EventInfo_comp_val;   //!
   TBranch        *b_EventInfo_fBit;   //!
   TBranch        *b_IF_BETA;   //!
   TBranch        *b_IF_ION;   //!
   TBranch        *b_numdssd;   //!
   TBranch        *b_numadc;   //!
   TBranch        *b_numtdc;   //!
   TBranch        *b_dstrx;   //!
   TBranch        *b_dstry;   //!
   TBranch        *b_scal;   //!
   TBranch        *b_dssd_E_X;   //!
   TBranch        *b_dssd_ch_X;   //!
   TBranch        *b_dssd_id_X;   //!
   TBranch        *b_dssd_E_Y;   //!
   TBranch        *b_dssd_ch_Y;   //!
   TBranch        *b_dssd_id_Y;   //!
   TBranch        *b_dssd_T_X;   //!
   TBranch        *b_dssd_T_Y;   //!
   TBranch        *b_dssd_X;   //!
   TBranch        *b_dssd_Y;   //!
   TBranch        *b_dssd_Z;   //!
   TBranch        *b_dssd_fireX;   //!
   TBranch        *b_dssd_fireY;   //!
   TBranch        *b_ADC;   //!
   TBranch        *b_TDC;   //!
   TBranch        *b_dssd_fastout;   //!
   TBranch        *b_DSSD_E;   //!
   TBranch        *b_DSSD_T;   //!
   TBranch        *b_bigrips_F3PPAC1X1;   //!
   TBranch        *b_bigrips_F3PPAC1X2;   //!
   TBranch        *b_bigrips_F3PPAC2X1;   //!
   TBranch        *b_bigrips_F3PPAC2X2;   //!
   TBranch        *b_bigrips_F5PPAC1X1;   //!
   TBranch        *b_bigrips_F5PPAC1X2;   //!
   TBranch        *b_bigrips_F5PPAC2X1;   //!
   TBranch        *b_bigrips_F5PPAC2X2;   //!
   TBranch        *b_bigrips_F3L;   //!
   TBranch        *b_bigrips_F3R;   //!
   TBranch        *b_bigrips_F7L;   //!
   TBranch        *b_bigrips_F7R;   //!
   TBranch        *b_bigrips_F11L;   //!
   TBranch        *b_bigrips_F11R;   //!
   TBranch        *b_bigrips_ICe;   //!
   TBranch        *b_Qbeta_E;   //!
   TBranch        *b_Qbeta_T;   //!
   TBranch        *b_Qveto_E;   //!
   TBranch        *b_Qveto_T;   //!
   TBranch        *b_NaI_E;   //!
   TBranch        *b_NaI_T;   //!
   TBranch        *b_bigrips_F3PPAC1_TDiffX;   //!
   TBranch        *b_bigrips_F3PPAC2_TDiffX;   //!
   TBranch        *b_bigrips_F5PPAC1_TDiffX;   //!
   TBranch        *b_bigrips_F5PPAC2_TDiffX;   //!
   TBranch        *b_bigrips_F3PPAC1_X;   //!
   TBranch        *b_bigrips_F3PPAC2_X;   //!
   TBranch        *b_bigrips_F5PPAC1_X;   //!
   TBranch        *b_bigrips_F5PPAC2_X;   //!
   TBranch        *b_bigrips_F3_X;   //!
   TBranch        *b_bigrips_F3_A;   //!
   TBranch        *b_bigrips_F5_X;   //!
   TBranch        *b_bigrips_F5_A;   //!
   TBranch        *b_bigrips_dERaw;   //!
   TBranch        *b_bigrips_dE;   //!
   TBranch        *b_pid_Delta_F3F5;   //!
   TBranch        *b_pid_TOF_F3F7;   //!
   TBranch        *b_pid_Beta_F3F5;   //!
   TBranch        *b_pid_Beta_F5F7;   //!
   TBranch        *b_pid_AoQ_F3F5;   //!
   TBranch        *b_pid_Zet_F11;   //!

   dssd(char* file,TTree *tree=0);
   virtual ~dssd();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     GetTsEntry(map<Long64_t,Long64_t> &mts, map<Long64_t,Long64_t> &mtsbeta, map<Long64_t,Long64_t>&mtsbeam);
   
   virtual void     GetIonInfo(Long64_t entry);
   virtual void     GetDecayInfo(Long64_t entry);
   virtual void     TreeBranch_Ion(TTree *tree);
   virtual void     TreeBranch_Decay(TTree *tree);
   
   //  virtual void     IfBeta(Int_t &IF_BETA, Int_t &IF_ION);
   virtual void     BetaGetPos(Int_t &mult, 
                      map <Int_t,vector <pair<Int_t,Int_t> > > &beta_event);
   virtual void     BetaGetPos(Int_t &mult, std::map<Int_t,vector<pair<pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> >,
			   pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> > > > > &beta_event);
   virtual void     ResetIon();
   virtual void     ResetDecay();

};


dssd::dssd(char* file,TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(file);
      if (!f || !f->IsOpen()) {
         f = new TFile(file);
      }
      f->GetObject("WASABI",tree);

   }
   Init(tree);
}

dssd::~dssd()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dssd::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dssd::LoadTree(Long64_t entry)
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

void dssd::Init(TTree *tree)
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


   fChain->SetBranchAddress("EventInfo", &EventInfo_, &b_EventInfo_);
   fChain->SetBranchAddress("EventInfo.fUniqueID", EventInfo_fUniqueID, &b_EventInfo_fUniqueID);
   fChain->SetBranchAddress("EventInfo.fBits", EventInfo_fBits, &b_EventInfo_fBits);
   fChain->SetBranchAddress("EventInfo.fName", EventInfo_fName, &b_EventInfo_fName);
   fChain->SetBranchAddress("EventInfo.fTitle", EventInfo_fTitle, &b_EventInfo_fTitle);
   fChain->SetBranchAddress("EventInfo.runnumber", EventInfo_runnumber, &b_EventInfo_runnumber);
   fChain->SetBranchAddress("EventInfo.eventnumber", EventInfo_eventnumber, &b_EventInfo_eventnumber);
   fChain->SetBranchAddress("EventInfo.subsysname", EventInfo_subsysname, &b_EventInfo_subsysname);
   fChain->SetBranchAddress("EventInfo.timestamp", EventInfo_timestamp, &b_EventInfo_timestamp);
   fChain->SetBranchAddress("EventInfo.comp_val", EventInfo_comp_val, &b_EventInfo_comp_val);
   fChain->SetBranchAddress("EventInfo.fBit", EventInfo_fBit, &b_EventInfo_fBit);
   fChain->SetBranchAddress("IF_BETA", &IF_BETA, &b_IF_BETA);
   fChain->SetBranchAddress("IF_ION", &IF_ION, &b_IF_ION);
   fChain->SetBranchAddress("numdssd", &numdssd, &b_numdssd);
   fChain->SetBranchAddress("numadc", &numadc, &b_numadc);
   fChain->SetBranchAddress("numtdc", &numtdc, &b_numtdc);
   fChain->SetBranchAddress("dstrx", &dstrx, &b_dstrx);
   fChain->SetBranchAddress("dstry", &dstry, &b_dstry);
   fChain->SetBranchAddress("scal", scal, &b_scal);
   fChain->SetBranchAddress("dssd_E_X", dssd_E_X, &b_dssd_E_X);
   fChain->SetBranchAddress("dssd_ch_X", dssd_ch_X, &b_dssd_ch_X);
   fChain->SetBranchAddress("dssd_id_X", dssd_id_X, &b_dssd_id_X);
   fChain->SetBranchAddress("dssd_E_Y", dssd_E_Y, &b_dssd_E_Y);
   fChain->SetBranchAddress("dssd_ch_Y", dssd_ch_Y, &b_dssd_ch_Y);
   fChain->SetBranchAddress("dssd_id_Y", dssd_id_Y, &b_dssd_id_Y);
   fChain->SetBranchAddress("dssd_T_X", dssd_T_X, &b_dssd_T_X);
   fChain->SetBranchAddress("dssd_T_Y", dssd_T_Y, &b_dssd_T_Y);
   fChain->SetBranchAddress("dssd_X", dssd_X, &b_dssd_X);
   fChain->SetBranchAddress("dssd_Y", dssd_Y, &b_dssd_Y);
   fChain->SetBranchAddress("dssd_Z", &dssd_Z, &b_dssd_Z);
   fChain->SetBranchAddress("dssd_fireX", dssd_fireX, &b_dssd_fireX);
   fChain->SetBranchAddress("dssd_fireY", dssd_fireY, &b_dssd_fireY);
   fChain->SetBranchAddress("ADC", ADC, &b_ADC);
   fChain->SetBranchAddress("TDC", TDC, &b_TDC);
   fChain->SetBranchAddress("dssd_fastout", dssd_fastout, &b_dssd_fastout);
   fChain->SetBranchAddress("DSSD_E", DSSD_E, &b_DSSD_E);
   fChain->SetBranchAddress("DSSD_T", DSSD_T, &b_DSSD_T);
   fChain->SetBranchAddress("bigrips_F3PPAC1X1", &bigrips_F3PPAC1X1, &b_bigrips_F3PPAC1X1);
   fChain->SetBranchAddress("bigrips_F3PPAC1X2", &bigrips_F3PPAC1X2, &b_bigrips_F3PPAC1X2);
   fChain->SetBranchAddress("bigrips_F3PPAC2X1", &bigrips_F3PPAC2X1, &b_bigrips_F3PPAC2X1);
   fChain->SetBranchAddress("bigrips_F3PPAC2X2", &bigrips_F3PPAC2X2, &b_bigrips_F3PPAC2X2);
   fChain->SetBranchAddress("bigrips_F5PPAC1X1", &bigrips_F5PPAC1X1, &b_bigrips_F5PPAC1X1);
   fChain->SetBranchAddress("bigrips_F5PPAC1X2", &bigrips_F5PPAC1X2, &b_bigrips_F5PPAC1X2);
   fChain->SetBranchAddress("bigrips_F5PPAC2X1", &bigrips_F5PPAC2X1, &b_bigrips_F5PPAC2X1);
   fChain->SetBranchAddress("bigrips_F5PPAC2X2", &bigrips_F5PPAC2X2, &b_bigrips_F5PPAC2X2);
   fChain->SetBranchAddress("bigrips_F3L", &bigrips_F3L, &b_bigrips_F3L);
   fChain->SetBranchAddress("bigrips_F3R", &bigrips_F3R, &b_bigrips_F3R);
   fChain->SetBranchAddress("bigrips_F7L", &bigrips_F7L, &b_bigrips_F7L);
   fChain->SetBranchAddress("bigrips_F7R", &bigrips_F7R, &b_bigrips_F7R);
   fChain->SetBranchAddress("bigrips_F11L", &bigrips_F11L, &b_bigrips_F11L);
   fChain->SetBranchAddress("bigrips_F11R", &bigrips_F11R, &b_bigrips_F11R);
   fChain->SetBranchAddress("bigrips_ICe", bigrips_ICe, &b_bigrips_ICe);
   fChain->SetBranchAddress("Qbeta_E", &Qbeta_E, &b_Qbeta_E);
   fChain->SetBranchAddress("Qbeta_T", &Qbeta_T, &b_Qbeta_T);
   fChain->SetBranchAddress("Qveto_E", &Qveto_E, &b_Qveto_E);
   fChain->SetBranchAddress("Qveto_T", &Qveto_T, &b_Qveto_T);
   fChain->SetBranchAddress("NaI_E", NaI_E, &b_NaI_E);
   fChain->SetBranchAddress("NaI_T", NaI_T, &b_NaI_T);
   fChain->SetBranchAddress("bigrips_F3PPAC1_TDiffX", &bigrips_F3PPAC1_TDiffX, &b_bigrips_F3PPAC1_TDiffX);
   fChain->SetBranchAddress("bigrips_F3PPAC2_TDiffX", &bigrips_F3PPAC2_TDiffX, &b_bigrips_F3PPAC2_TDiffX);
   fChain->SetBranchAddress("bigrips_F5PPAC1_TDiffX", &bigrips_F5PPAC1_TDiffX, &b_bigrips_F5PPAC1_TDiffX);
   fChain->SetBranchAddress("bigrips_F5PPAC2_TDiffX", &bigrips_F5PPAC2_TDiffX, &b_bigrips_F5PPAC2_TDiffX);
   fChain->SetBranchAddress("bigrips_F3PPAC1_X", &bigrips_F3PPAC1_X, &b_bigrips_F3PPAC1_X);
   fChain->SetBranchAddress("bigrips_F3PPAC2_X", &bigrips_F3PPAC2_X, &b_bigrips_F3PPAC2_X);
   fChain->SetBranchAddress("bigrips_F5PPAC1_X", &bigrips_F5PPAC1_X, &b_bigrips_F5PPAC1_X);
   fChain->SetBranchAddress("bigrips_F5PPAC2_X", &bigrips_F5PPAC2_X, &b_bigrips_F5PPAC2_X);
   fChain->SetBranchAddress("bigrips_F3_X", &bigrips_F3_X, &b_bigrips_F3_X);
   fChain->SetBranchAddress("bigrips_F3_A", &bigrips_F3_A, &b_bigrips_F3_A);
   fChain->SetBranchAddress("bigrips_F5_X", &bigrips_F5_X, &b_bigrips_F5_X);
   fChain->SetBranchAddress("bigrips_F5_A", &bigrips_F5_A, &b_bigrips_F5_A);
   fChain->SetBranchAddress("bigrips_dERaw", &bigrips_dERaw, &b_bigrips_dERaw);
   fChain->SetBranchAddress("bigrips_dE", &bigrips_dE, &b_bigrips_dE);
   fChain->SetBranchAddress("pid_Delta_F3F5", &pid_Delta_F3F5, &b_pid_Delta_F3F5);
   fChain->SetBranchAddress("pid_TOF_F3F7", &pid_TOF_F3F7, &b_pid_TOF_F3F7);
   fChain->SetBranchAddress("pid_Beta_F3F5", &pid_Beta_F3F5, &b_pid_Beta_F3F5);
   fChain->SetBranchAddress("pid_Beta_F5F7", &pid_Beta_F5F7, &b_pid_Beta_F5F7);
   fChain->SetBranchAddress("pid_AoQ_F3F5", &pid_AoQ_F3F5, &b_pid_AoQ_F3F5);
   fChain->SetBranchAddress("pid_Zet_F11", &pid_Zet_F11, &b_pid_Zet_F11);


   Notify();
}

Bool_t dssd::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dssd::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t dssd::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
void dssd::GetTsEntry(map<Long64_t,Long64_t> &mts, map<Long64_t,Long64_t> &mtsbeta,map<Long64_t,Long64_t>&mtsbeam)
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
      Long64_t ts=(Long64_t)EventInfo_timestamp[0];
      //for(int i=0;i<60;i++)
	//	cout<<EventInfo_timestamp[0]<<" "<<dssd_T_X[3][i][0] <<" "<<dssd_E_X[3][i]<<endl;
      //     IfBeta(IF_BETA,IF_ION);
      if(IF_ION || IF_BETA) mts.insert(pair<Long64_t,Long64_t> (ts,jentries));
      if(IF_BETA)  mtsbeta.insert(pair<Long64_t,Long64_t> (jentries,ts));
      if(IF_ION)   mtsbeam.insert(pair<Long64_t,Long64_t> (jentries,ts));
   }
   cout<<"complete ts mapping for DSSD"<<endl;
}

void dssd::BetaGetPos(Int_t &mult, map<Int_t,vector<pair<Int_t,Int_t> > > &beta_event)
{//mult is the multiplicity of beta event. map(z,vector(pair(x,y))) restore position
   //information of beta decay.
   mult=0;
   for(Int_t z=0; z<NumDSSD; z++){
      vector<pair<Int_t,Int_t> > beta_dssd;
      for(Int_t x=0; x<NumStrX; x++){
         if(dssd_T_X[z][x][0]>-50000 && dssd_E_X[z][x]>10){
            //cout << "x-strip found" << endl;
            for(Int_t y=0; y<NumStrY; y++){
               //cout << dssd_T_Y[z][y][0] << "  " << dssd_E_Y[z][y] <<endl;
               if(dssd_T_Y[z][y][0]>-50000 && dssd_E_Y[z][y]>10){
                  //cout << "y-strip found" << endl;
                  mult++;
                  beta_dssd.push_back(pair<Int_t,Int_t> (x,y));
               }
            }
         }
      }
      if(beta_dssd.size()>0){
         beta_event[z]=beta_dssd;
      }
   }
}

void dssd::BetaGetPos(Int_t &mult, std::map<Int_t,vector<pair<pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> >,pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> > > > > &beta_event)
{//mult is the multiplicity of beta event. map(z,vector(pair(x,y))) restore position
   //information of beta decay.
   Int_t beta_x1[60], beta_x2[60], beta_ex[60], beta_nhitx;
   Int_t beta_y1[40], beta_y2[40], beta_ey[60], beta_nhity;
   Int_t ch_last, x, y;
   Int_t x1, x2, ex, y1, y2, ey;
   Double_t x0, y0, beta_x[60], beta_y[40];
   mult=0;
   for(Int_t z=0; z<NumDSSD; z++){
      beta_nhitx = -1;
      ch_last = -2;
      for(int i=0; i<60; i++){
         beta_x[i] = 0;
         beta_ex[i] = 0;
      }
      for(x=1; x<NumStrX-1; x++){
         if(dssd_T_X[z][x][0]<4000 && dssd_T_X[z][x][0]>-4000 && dssd_E_X[z][x]>10){
         // cout<<"xpos:"<<x<<" "<<z<<" "<<dssd_T_X[z][x][0] <<" "<<dssd_E_X[z][x]<<endl;
            if(x!=ch_last+1){
               if(beta_nhitx>=0){
                  beta_x[beta_nhitx] = beta_x[beta_nhitx]/beta_ex[beta_nhitx];
               }
               beta_nhitx ++;
               beta_ex[beta_nhitx] = dssd_E_X[z][x];
               beta_x[beta_nhitx] = x*dssd_E_X[z][x];
               beta_x1[beta_nhitx] = x;
               beta_x2[beta_nhitx] = x;
               ch_last = x;
            }else{
               beta_ex[beta_nhitx] = beta_ex[beta_nhitx] + dssd_E_X[z][x];
               beta_x[beta_nhitx] = beta_x[beta_nhitx] + x*dssd_E_X[z][x];
               beta_x2[beta_nhitx] = x;
               ch_last ++;
            }
         }
      }
      if(beta_nhitx>=0){
         beta_x[beta_nhitx] = beta_x[beta_nhitx]/beta_ex[beta_nhitx];
      }
      beta_nhity = -1;
      ch_last = -2;
      for(int i=0; i<40; i++){
         beta_y[i] = 0;
         beta_ey[i] = 0;
      }
      for(y=1; y<NumStrY-1; y++){
         if(dssd_T_Y[z][y][0]<4000 && dssd_T_Y[z][y][0]>-4000 && dssd_E_Y[z][y]>10){
         // cout<<"ypos:"<<y<<" "<<z<<endl;
            if(y!=ch_last+1){
               if(beta_nhity>=0){
                  beta_y[beta_nhity] = beta_y[beta_nhity]/beta_ey[beta_nhity];
               }
               beta_nhity ++;
               beta_ey[beta_nhity] = dssd_E_Y[z][y];
               beta_y[beta_nhity] = y*dssd_E_Y[z][y];
               beta_y1[beta_nhity] = y;
               beta_y2[beta_nhity] = y;
               ch_last = y;
            }else{
               beta_ey[beta_nhity] = beta_ey[beta_nhity] + dssd_E_Y[z][y];
               beta_y[beta_nhity] = beta_y[beta_nhity] + y*dssd_E_Y[z][y];
               beta_y2[beta_nhity] = y;
               ch_last ++;
            }
         }
      }
      if(beta_nhity>=0){
         beta_y[beta_nhity] = beta_y[beta_nhity]/beta_ey[beta_nhity];
      }

      vector<pair<pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> >,pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> > > > beta_dssd;
      for(int i=0; i<beta_nhitx+1; i++){
         for(int j=0; j<beta_nhity+1; j++){
            x0 = beta_x[i];
            x1 = beta_x1[i];
            x2 = beta_x2[i];
            ex = beta_ex[i];
            if(z>=4){
               ex = ex/2;
            }
            y0 = beta_y[j];
            y1 = beta_y1[j];
            y2 = beta_y2[j];
            ey = beta_ey[j];
            Int_t fill = 1;
            if(beta_nhitx==beta_nhity && (ey>1.1*ex+200 || ey<0.9*ex-200)){
               fill = 0;
            }
            if(fill==1)
            {
               mult++;
               //cout<<"x1 = "<<beta_x1[i]<<", x0 = "<<beta_x[i]<<", x2 = "<<beta_x2[i]<<endl;
               //beta_dssd.push_back(pair<pair<Int_t,Int_t>,pair<Int_t,Int_t> > ((x,ex),(y,ey) ) );
               //  cout<<"x:"<<x1<<" "<<x2<<" "<<z<<endl;
               //cout<<"y:"<<y1<<" "<<y2<<" "<<z<<endl;
               beta_dssd.push_back(make_pair(make_pair(make_pair(x1,x2),make_pair(x0,ex) ),make_pair(make_pair(y1,y2),make_pair(y0,ey) ) ) );
            }
         }
      }
      if(beta_dssd.size()>0){
         beta_event[z]=beta_dssd;
      }
   }
}



void dssd::GetIonInfo(Long64_t entry)
{
  fChain->LoadTree(entry);
  fChain->GetEntry(entry);
  bz=dssd_Z;
  memcpy(ionx,dssd_X,sizeof(dssd_X));
  memcpy(iony,dssd_Y,sizeof(dssd_Y));

  if(bz<0 || bz>7) { bx=-1; by=-1;}
  if(bx==59 || bx==0 || by==0 || by==39) {bx=-1;by=-1;}
  else{
    bx=ionx[bz]; by=iony[bz];
  }
  memcpy(bnaie,NaI_E,sizeof(NaI_E));
  memcpy(bnait,NaI_T,sizeof(NaI_T));  
  bts=(Long64_t)EventInfo_timestamp[0];
}
void dssd::ResetIon()
{
  bx=-1;
  by=-1;
  bz=-1;
  bts=-1;
  for(int i=0;i<8;i++) {
    ionx[i]=-1;iony[i]=-1;
  }
  for(int i=0;i<3;i++) {
    bnaie[i]=-1;
    bnait[i]=-1000000;
  }
  
}
void dssd::TreeBranch_Ion(TTree *tree)
{

   tree->Branch("bx",&bx,"bx/I");
   tree->Branch("by",&by,"by/I");
   tree->Branch("bz",&bz,"bz/I");   
   tree->Branch("bts",&bts,"bts/L");
}

void dssd::GetDecayInfo(Long64_t entry)
{ 
   map<Int_t,vector<pair<pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> >,
                    pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> > > > > map_beta;
   map<Int_t,vector<pair<pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> >,
                    pair<pair<Int_t,Int_t>,pair<Double_t,Int_t> > > > >::iterator imap_beta;
   fChain->LoadTree(entry);
   fChain->GetEntry(entry);
   Int_t beta_multi;
   BetaGetPos(beta_multi,map_beta);
   dssd_mulhit=0;
   int nd=0;
   dssd_E=0;
   for(int zz2=0; zz2<NumDSSD; zz2++){
     dssd_fire[zz2]=0;
     dssd_ex[zz2]=-1;
     dssd_ey[zz2]=-1;
     imap_beta = map_beta.find(zz2);
     if(imap_beta != map_beta.end()){
        dssd_fire[zz2]=1;
        dssd_ex[zz2]=0;
        dssd_ey[zz2]=0;
        dssd_mulhit++;
        for(unsigned int j=0; j<imap_beta->second.size(); j++){
          int ex=imap_beta->second[j].first.second.second;
          int ey=imap_beta->second[j].second.second.second;
          dssd_ex[zz2]=dssd_ex[zz2]+ex;
          dssd_ey[zz2]=dssd_ey[zz2]+ey;
        }
     }
     dssd_E=dssd_E+dssd_ex[zz2];
   }
   if(dssd_fire[0]==1&&dssd_fire[7]==1) {
     b.ndecayhit=0;return;
   }
   b.ndecayhit=0;
   for(int zz2=0; zz2<NumDSSD; zz2++){
     imap_beta = map_beta.find(zz2);
     if(imap_beta != map_beta.end()){
       for(unsigned int j=0; j<imap_beta->second.size(); j++){
         b.z[nd]=zz2;
         b.x1[nd]=imap_beta->second[j].first.first.first;
         b.x2[nd]=imap_beta->second[j].first.first.second;
         b.x[nd]=imap_beta->second[j].first.second.first;
         b.ex[nd]=imap_beta->second[j].first.second.second;
         b.y1[nd]=imap_beta->second[j].second.first.first;
         b.y2[nd]=imap_beta->second[j].second.first.second;
         b.y[nd]=imap_beta->second[j].second.second.first;
         b.ey[nd]=imap_beta->second[j].second.second.second;
         b.tx[nd]=(dssd_T_X[zz2][b.x1[nd]][0]+dssd_T_X[zz2][b.x2[nd]][0])/2;
         b.ty[nd]=(dssd_T_Y[zz2][b.y1[nd]][0]+dssd_T_Y[zz2][b.y2[nd]][0])/2;
         nd++;
         b.ndecayhit=nd;
       }
     }
   }    
   ///////////////////////////////////////////////////////////
   nbeta=0;
   map <Int_t,vector<pair<Int_t,Int_t> > > map_beta1;
   map <Int_t,vector<pair<Int_t,Int_t> > >::iterator imap_beta1;
   BetaGetPos(beta_multi,map_beta1);
   for(int z1=0; z1<NumDSSD; z1++){
     imap_beta1 = map_beta1.find(z1);
     if(imap_beta1 != map_beta1.end()){
        for(unsigned int j=0; j<imap_beta1->second.size(); j++){
            //Int_t x1,y1;
            //Int_t xe1,ye1;
            //x1=imap_beta1->second[j].first;
            //y1=imap_beta1->second[j].second;
            //xe1=dssd_E_X[z1][x1];
            //ye1=dssd_E_Y[z1][y1];
            //xx[nbeta]=x1; yy[nbeta]=y1; zz[nbeta]=z1;
            //xxe[nbeta]=xe1; yye[nbeta]=ye1;
            if(nbeta>16)cout<<nbeta<<endl; 
        }
        nbeta++;
     }
   
   }
  qbetae=Qbeta_E; qbetat=Qbeta_T;
  qvetoe=Qveto_E; qvetot=Qveto_T;
  memcpy(naie,NaI_E,sizeof(NaI_E));
  memcpy(nait,NaI_T,sizeof(NaI_T)); 
   ts=(Long64_t)EventInfo_timestamp[0]; 
}

void dssd::ResetDecay()
{

  ts=-1; 
  nbeta=0; 
  b.ndecayhit=0;
  dssd_mulhit=0;
  for(int i=0;i<NumDSSD;i++) {
    dssd_fire[i]=0;
    dssd_ex[i]=0;
    dssd_ey[i]=0;
  }
  dssd_E=0;    
  for(int i=0;i<3;i++) {
    naie[i]=-1;nait[i]=-100000;
  }
  qbetae=-1;qvetoe=-1;
  qbetat=-100000;qvetoe=-100000;
 
}
void dssd::TreeBranch_Decay(TTree *tree)
{
   tree->Branch("ts",&ts,"ts/L");
   tree->Branch("ndecayhit",&b.ndecayhit,"ndecayhit/I");
   tree->Branch("x1",&b.x1,"x1[ndecayhit]/I");
   tree->Branch("x2",&b.x2,"x2[ndecayhit]/I");
   tree->Branch("ex",&b.ex,"ex[ndecayhit]/I");
   tree->Branch("x", &b.x,"x[ndecayhit]/D");
   tree->Branch("y1",&b.y1,"y1[ndecayhit]/I");
   tree->Branch("y2",&b.y2,"y2[ndecayhit]/I");
   tree->Branch("ey",&b.ey,"ey[ndecayhit]/I");
   tree->Branch("y", &b.y,"y[ndecayhit]/D");
   tree->Branch("z", &b.z,"z[ndecayhit]/I");
}

#endif // #ifdef dssd_cxx
