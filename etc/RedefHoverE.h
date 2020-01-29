//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec 17 18:53:15 2019 by ROOT version 6.14/09
// from TTree EventTree/EventData
// found on file: ../test_MINIAOD_2018.root
//////////////////////////////////////////////////////////

#ifndef RedefHoverE_h
#define RedefHoverE_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class RedefHoverE {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxele_genmatched = 1;
   static constexpr Int_t kMaxscEn = 1;
   static constexpr Int_t kMaxeleSCRawEn = 1;
   static constexpr Int_t kMaxecalEn = 1;
   static constexpr Int_t kMaxseedEn = 1;
   static constexpr Int_t kMaxseedEnCorr = 1;
   static constexpr Int_t kMaxcmssw_eleHoE = 1;
   static constexpr Int_t kMaxcmssw_eleHoE_full5x5 = 1;
   static constexpr Int_t kMaxeleScEta = 1;
   static constexpr Int_t kMaxelePt = 1;
   static constexpr Int_t kMaxelePhi = 1;
   static constexpr Int_t kMaxeleSigmaIEtaIEtaFull5x5 = 1;
   static constexpr Int_t kMaxelePFNeuIso = 1;
   static constexpr Int_t kMaxelePFChIso = 1;
   static constexpr Int_t kMaxeleSeedDet = 1;
   static constexpr Int_t kMaxeleSeedSubdet = 1;
   static constexpr Int_t kMaxeleSeedIeta = 1;
   static constexpr Int_t kMaxeleSeedIphi = 1;
   static constexpr Int_t kMaxeleSeedEta = 1;
   static constexpr Int_t kMaxeleSeedPhi = 1;
   static constexpr Int_t kMaxeleSeedRawID = 1;
   static constexpr Int_t kMaxseedHcalIeta = 1;
   static constexpr Int_t kMaxseedHcalIphi = 1;
   static constexpr Int_t kMaxhcalRechitIeta = 1;
   static constexpr Int_t kMaxhcalRechitIphi = 1;
   static constexpr Int_t kMaxhcalRechitEnergy = 1;
   static constexpr Int_t kMaxhcalRechitAbsDIetaFromEleSeed = 1;
   static constexpr Int_t kMaxhcalRechitAbsDIphiFromEleSeed = 1;
   static constexpr Int_t kMaxhcalRechitRawID = 1;
   static constexpr Int_t kMaxhcalRechitDepth = 1;
   static constexpr Int_t kMaxhcalRechitEta = 1;
   static constexpr Int_t kMaxhcalRechitPhi = 1;
   static constexpr Int_t kMaxpuTrue = 1;

   // Declaration of leaf types
   vector<int>   *ele_genmatched_;
   vector<float>   *scEn_;
   vector<float>   *eleSCRawEn_;
   vector<float>   *ecalEn_;
   vector<float>   *seedEn_;
   vector<float>   *seedEnCorr_;
   vector<float>   *cmssw_eleHoE_;
   vector<float>   *cmssw_eleHoE_full5x5_;
   vector<float>   *eleScEta_;
   vector<float>   *elePt_;
   vector<float>   *elePhi_;
   vector<float>   *eleSigmaIEtaIEtaFull5x5_;
   vector<float>   *elePFNeuIso_;
   vector<float>   *elePFChIso_;
   vector<int>     *eleSeedDet_;
   vector<int>     *eleSeedSubdet_;
   vector<int>     *eleSeedIeta_;
   vector<int>     *eleSeedIphi_;
   vector<float>   *eleSeedEta_;
   vector<float>   *eleSeedPhi_;
   vector<int>     *eleSeedRawID_;
   vector<int>     *seedHcalIeta_;
   vector<int>     *seedHcalIphi_;
   vector<vector<int> > *hcalRechitIeta_;
   vector<vector<int> > *hcalRechitIphi_;
   vector<vector<float> > *hcalRechitEnergy_;
   vector<vector<int> > *hcalRechitAbsDIetaFromEleSeed_;
   vector<vector<int> > *hcalRechitAbsDIphiFromEleSeed_;
   vector<vector<int> > *hcalRechitRawID_;
   vector<vector<int> > *hcalRechitDepth_;
   vector<vector<float> > *hcalRechitEta_;
   vector<vector<float> > *hcalRechitPhi_;
   vector<float>   *puTrue_;

   // List of branches
   TBranch        *b_ele_genmatched_;   //!
   TBranch        *b_scEn_;   //!
   TBranch        *b_eleSCRawEn_;   //!
   TBranch        *b_ecalEn_;   //!
   TBranch        *b_seedEn_;   //!
   TBranch        *b_seedEnCorr_;   //!
   TBranch        *b_cmssw_eleHoE_;   //!
   TBranch        *b_cmssw_eleHoE_full5x5_;   //!
   TBranch        *b_eleScEta_;   //!
   TBranch        *b_elePt_;   //!
   TBranch        *b_elePhi_;   //!
   TBranch        *b_eleSigmaIEtaIEtaFull5x5_;   //!
   TBranch        *b_elePFNeuIso_;   //!
   TBranch        *b_elePFChIso_;   //!
   TBranch        *b_eleSeedDet_;   //!
   TBranch        *b_eleSeedSubdet_;   //!
   TBranch        *b_eleSeedIeta_;   //!
   TBranch        *b_eleSeedIphi_;   //!
   TBranch        *b_eleSeedEta_;   //!
   TBranch        *b_eleSeedPhi_;   //!
   TBranch        *b_eleSeedRawID_;   //!
   TBranch        *b_seedHcalIeta_;   //!
   TBranch        *b_seedHcalIphi_;   //!
   TBranch        *b_hcalRechitIeta_;   //!
   TBranch        *b_hcalRechitIphi_;   //!
   TBranch        *b_hcalRechitEnergy_;   //!
   TBranch        *b_hcalRechitAbsDIetaFromEleSeed_;   //!
   TBranch        *b_hcalRechitAbsDIphiFromEleSeed_;   //!
   TBranch        *b_hcalRechitRawID_;   //!
   TBranch        *b_hcalRechitDepth_;   //!
   TBranch        *b_hcalRechitEta_;   //!
   TBranch        *b_hcalRechitPhi_;   //!
   TBranch        *b_puTrue_;   //!

   RedefHoverE(TTree *tree=0);
   virtual ~RedefHoverE();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef RedefHoverE_cxx
RedefHoverE::RedefHoverE(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
//DYtoEE2023.root  SingleEle2018noPU.root
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/phys_egamma/swmukher/");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/cms/store/group/phys_egamma/swmukher/");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/phys_egamma/swmukher/:/demo");
      dir->GetObject("EventTree",tree);

   }
   Init(tree);
}

RedefHoverE::~RedefHoverE()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t RedefHoverE::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t RedefHoverE::LoadTree(Long64_t entry)
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

void RedefHoverE::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ele_genmatched_ = 0;
   scEn_ = 0;
   eleSCRawEn_ = 0;
   ecalEn_ = 0;
   seedEn_ = 0;
   seedEnCorr_ = 0;
   cmssw_eleHoE_ = 0;
   cmssw_eleHoE_full5x5_ = 0;
   eleScEta_ = 0;
   elePt_ = 0;
   elePhi_ = 0;
   eleSigmaIEtaIEtaFull5x5_ = 0;
   elePFNeuIso_ = 0;
   elePFChIso_ = 0;
   eleSeedDet_ = 0;
   eleSeedSubdet_ = 0;
   eleSeedIeta_ = 0;
   eleSeedIphi_ = 0;
   eleSeedEta_ = 0;
   eleSeedPhi_ = 0;
   eleSeedRawID_ = 0;
   seedHcalIeta_ = 0;
   seedHcalIphi_ = 0;
   hcalRechitIeta_ = 0;
   hcalRechitIphi_ = 0;
   hcalRechitEnergy_ = 0;
   hcalRechitAbsDIetaFromEleSeed_ = 0;
   hcalRechitAbsDIphiFromEleSeed_ = 0;
   hcalRechitRawID_ = 0;
   hcalRechitDepth_ = 0;
   hcalRechitEta_ = 0;
   hcalRechitPhi_ = 0;
   puTrue_ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ele_genmatched_", &ele_genmatched_, &b_ele_genmatched_);
   fChain->SetBranchAddress("scEn_", &scEn_, &b_scEn_);
   fChain->SetBranchAddress("eleSCRawEn_", &eleSCRawEn_, &b_eleSCRawEn_);
   fChain->SetBranchAddress("ecalEn_", &ecalEn_, &b_ecalEn_);
   fChain->SetBranchAddress("seedEn_", &seedEn_, &b_seedEn_);
   fChain->SetBranchAddress("seedEnCorr_", &seedEnCorr_, &b_seedEnCorr_);
   fChain->SetBranchAddress("cmssw_eleHoE_", &cmssw_eleHoE_, &b_cmssw_eleHoE_);
   fChain->SetBranchAddress("cmssw_eleHoE_full5x5_", &cmssw_eleHoE_full5x5_, &b_cmssw_eleHoE_full5x5_);
   fChain->SetBranchAddress("eleScEta_", &eleScEta_, &b_eleScEta_);
   fChain->SetBranchAddress("elePt_", &elePt_, &b_elePt_);
   fChain->SetBranchAddress("elePhi_", &elePhi_, &b_elePhi_);
   fChain->SetBranchAddress("eleSigmaIEtaIEtaFull5x5_", &eleSigmaIEtaIEtaFull5x5_, &b_eleSigmaIEtaIEtaFull5x5_);
   fChain->SetBranchAddress("elePFNeuIso_", &elePFNeuIso_, &b_elePFNeuIso_);
   fChain->SetBranchAddress("elePFChIso_", &elePFChIso_, &b_elePFChIso_);
   fChain->SetBranchAddress("eleSeedDet_", &eleSeedDet_, &b_eleSeedDet_);
   fChain->SetBranchAddress("eleSeedSubdet_", &eleSeedSubdet_, &b_eleSeedSubdet_);
   fChain->SetBranchAddress("eleSeedIeta_", &eleSeedIeta_, &b_eleSeedIeta_);
   fChain->SetBranchAddress("eleSeedIphi_", &eleSeedIphi_, &b_eleSeedIphi_);
   fChain->SetBranchAddress("eleSeedEta_", &eleSeedEta_, &b_eleSeedEta_);
   fChain->SetBranchAddress("eleSeedPhi_", &eleSeedPhi_, &b_eleSeedPhi_);
   fChain->SetBranchAddress("eleSeedRawID_", &eleSeedRawID_, &b_eleSeedRawID_);
   fChain->SetBranchAddress("seedHcalIeta_", &seedHcalIeta_, &b_seedHcalIeta_);
   fChain->SetBranchAddress("seedHcalIphi_", &seedHcalIphi_, &b_seedHcalIphi_);
   fChain->SetBranchAddress("hcalRechitIeta_", &hcalRechitIeta_, &b_hcalRechitIeta_);
   fChain->SetBranchAddress("hcalRechitIphi_", &hcalRechitIphi_, &b_hcalRechitIphi_);
   fChain->SetBranchAddress("hcalRechitEnergy_", &hcalRechitEnergy_, &b_hcalRechitEnergy_);
   fChain->SetBranchAddress("hcalRechitAbsDIetaFromEleSeed_", &hcalRechitAbsDIetaFromEleSeed_, &b_hcalRechitAbsDIetaFromEleSeed_);
   fChain->SetBranchAddress("hcalRechitAbsDIphiFromEleSeed_", &hcalRechitAbsDIphiFromEleSeed_, &b_hcalRechitAbsDIphiFromEleSeed_);
   fChain->SetBranchAddress("hcalRechitRawID_", &hcalRechitRawID_, &b_hcalRechitRawID_);
   fChain->SetBranchAddress("hcalRechitDepth_", &hcalRechitDepth_, &b_hcalRechitDepth_);
   fChain->SetBranchAddress("hcalRechitEta_", &hcalRechitEta_, &b_hcalRechitEta_);
   fChain->SetBranchAddress("hcalRechitPhi_", &hcalRechitPhi_, &b_hcalRechitPhi_);
   fChain->SetBranchAddress("puTrue_", &puTrue_, &b_puTrue_);
   Notify();
}

Bool_t RedefHoverE::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void RedefHoverE::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t RedefHoverE::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef RedefHoverE_cxx
