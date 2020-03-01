//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Feb 28 21:12:44 2020 by ROOT version 6.18/04
// from TTree EventTree/EventData
// found on file: /eos/cms/store/group/phys_egamma/swmukher/HoE_Feb16_2020/addGapInfo/EleGun2018.root
//////////////////////////////////////////////////////////

#ifndef testMax2x2_h
#define testMax2x2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class testMax2x2 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxele_isEB = 1;
   static constexpr Int_t kMaxele_isEE = 1;
   static constexpr Int_t kMaxele_isEBEEGap = 1;
   static constexpr Int_t kMaxele_isEBEtaGap = 1;
   static constexpr Int_t kMaxele_isEBPhiGap = 1;
   static constexpr Int_t kMaxele_isEEDeeGap = 1;
   static constexpr Int_t kMaxele_isEERingGap = 1;
   static constexpr Int_t kMaxele_isGap = 1;
   static constexpr Int_t kMaxele_golden = 1;
   static constexpr Int_t kMaxele_unknown = 1;
   static constexpr Int_t kMaxele_bigbrem = 1;
   static constexpr Int_t kMaxele_gap = 1;
   static constexpr Int_t kMaxele_badtrack = 1;
   static constexpr Int_t kMaxele_showering = 1;
   static constexpr Int_t kMaxele_trackFbrem = 1;
   static constexpr Int_t kMaxele_superClusterFbrem = 1;
   static constexpr Int_t kMaxele_numberOfBrems = 1;
   static constexpr Int_t kMaxele_genmatched = 1;
   static constexpr Int_t kMaxdR_recoEle_genEle = 1;
   static constexpr Int_t kMaxptRecoEle_by_ptGenEle = 1;
   static constexpr Int_t kMaxscEn = 1;
   static constexpr Int_t kMaxeleSCRawEn = 1;
   static constexpr Int_t kMaxecalEn = 1;
   static constexpr Int_t kMaxseedEn = 1;
   static constexpr Int_t kMaxseedEnCorr = 1;
   static constexpr Int_t kMaxcmssw_eleHoE = 1;
   static constexpr Int_t kMaxcmssw_eleHoE_tower = 1;
   static constexpr Int_t kMaxcmssw_eleHoE_full5x5 = 1;
   static constexpr Int_t kMaxeleScEta = 1;
   static constexpr Int_t kMaxeleScPhi = 1;
   static constexpr Int_t kMaxelePt = 1;
   static constexpr Int_t kMaxeleGenPt = 1;
   static constexpr Int_t kMaxele_full5x5_r9 = 1;
   static constexpr Int_t kMaxelePhi = 1;
   static constexpr Int_t kMaxeleSigmaIEtaIEtaFull5x5 = 1;
   static constexpr Int_t kMaxelePFNeuIso = 1;
   static constexpr Int_t kMaxelePFChIso = 1;
   static constexpr Int_t kMaxelePFPhoIso = 1;
   static constexpr Int_t kMaxelePFPUIso = 1;
   static constexpr Int_t kMaxele_hcalPFClusterIso = 1;
   static constexpr Int_t kMaxele_ecalPFClusterIso = 1;
   static constexpr Int_t kMaxele_dr03EcalRecHitSumEt = 1;
   static constexpr Int_t kMaxele_dr03HcalTowerSumEt = 1;
   static constexpr Int_t kMaxele_dr03HcalDepth1TowerSumEt = 1;
   static constexpr Int_t kMaxele_dr03HcalDepth2TowerSumEt = 1;
   static constexpr Int_t kMaxele_dr03TkSumPt = 1;
   static constexpr Int_t kMaxele_dr03TkSumPtHEEP = 1;
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
   static constexpr Int_t kMaxrho = 1;
   static constexpr Int_t kMaxrun_number = 1;
   static constexpr Int_t kMaxlumi_number = 1;
   static constexpr Int_t kMaxevent_number = 1;

   // Declaration of leaf types
   vector<int>     *ele_isEB_;
   vector<int>     *ele_isEE_;
   vector<int>     *ele_isEBEEGap_;
   vector<int>     *ele_isEBEtaGap_;
   vector<int>     *ele_isEBPhiGap_;
   vector<int>     *ele_isEEDeeGap_;
   vector<int>     *ele_isEERingGap_;
   vector<int>     *ele_isGap_;
   vector<int>     *ele_golden_;
   vector<int>     *ele_unknown_;
   vector<int>     *ele_bigbrem_;
   vector<int>     *ele_gap_;
   vector<int>     *ele_badtrack_;
   vector<int>     *ele_showering_;
   vector<float>   *ele_trackFbrem_;
   vector<float>   *ele_superClusterFbrem_;
   vector<int>     *ele_numberOfBrems_;
   vector<int>     *ele_genmatched_;
   vector<float>   *dR_recoEle_genEle_;
   vector<float>   *ptRecoEle_by_ptGenEle_;
   vector<float>   *scEn_;
   vector<float>   *eleSCRawEn_;
   vector<float>   *ecalEn_;
   vector<float>   *seedEn_;
   vector<float>   *seedEnCorr_;
   vector<float>   *cmssw_eleHoE_;
   vector<float>   *cmssw_eleHoE_tower_;
   vector<float>   *cmssw_eleHoE_full5x5_;
   vector<float>   *eleScEta_;
   vector<float>   *eleScPhi_;
   vector<float>   *elePt_;
   vector<float>   *eleGenPt_;
   vector<float>   *ele_full5x5_r9_;
   vector<float>   *elePhi_;
   vector<float>   *eleSigmaIEtaIEtaFull5x5_;
   vector<float>   *elePFNeuIso_;
   vector<float>   *elePFChIso_;
   vector<float>   *elePFPhoIso_;
   vector<float>   *elePFPUIso_;
   vector<float>   *ele_hcalPFClusterIso_;
   vector<float>   *ele_ecalPFClusterIso_;
   vector<float>   *ele_dr03EcalRecHitSumEt_;
   vector<float>   *ele_dr03HcalTowerSumEt_;
   vector<float>   *ele_dr03HcalDepth1TowerSumEt_;
   vector<float>   *ele_dr03HcalDepth2TowerSumEt_;
   vector<float>   *ele_dr03TkSumPt_;
   vector<float>   *ele_dr03TkSumPtHEEP_;
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
   Float_t         rho_;
   vector<int>     *run_number_;
   vector<int>     *lumi_number_;
   vector<int>     *event_number_;

   // List of branches
   TBranch        *b_ele_isEB_;   //!
   TBranch        *b_ele_isEE_;   //!
   TBranch        *b_ele_isEBEEGap_;   //!
   TBranch        *b_ele_isEBEtaGap_;   //!
   TBranch        *b_ele_isEBPhiGap_;   //!
   TBranch        *b_ele_isEEDeeGap_;   //!
   TBranch        *b_ele_isEERingGap_;   //!
   TBranch        *b_ele_isGap_;   //!
   TBranch        *b_ele_golden_;   //!
   TBranch        *b_ele_unknown_;   //!
   TBranch        *b_ele_bigbrem_;   //!
   TBranch        *b_ele_gap_;   //!
   TBranch        *b_ele_badtrack_;   //!
   TBranch        *b_ele_showering_;   //!
   TBranch        *b_ele_trackFbrem_;   //!
   TBranch        *b_ele_superClusterFbrem_;   //!
   TBranch        *b_ele_numberOfBrems_;   //!
   TBranch        *b_ele_genmatched_;   //!
   TBranch        *b_dR_recoEle_genEle_;   //!
   TBranch        *b_ptRecoEle_by_ptGenEle_;   //!
   TBranch        *b_scEn_;   //!
   TBranch        *b_eleSCRawEn_;   //!
   TBranch        *b_ecalEn_;   //!
   TBranch        *b_seedEn_;   //!
   TBranch        *b_seedEnCorr_;   //!
   TBranch        *b_cmssw_eleHoE_;   //!
   TBranch        *b_cmssw_eleHoE_tower_;   //!
   TBranch        *b_cmssw_eleHoE_full5x5_;   //!
   TBranch        *b_eleScEta_;   //!
   TBranch        *b_eleScPhi_;   //!
   TBranch        *b_elePt_;   //!
   TBranch        *b_eleGenPt_;   //!
   TBranch        *b_ele_full5x5_r9_;   //!
   TBranch        *b_elePhi_;   //!
   TBranch        *b_eleSigmaIEtaIEtaFull5x5_;   //!
   TBranch        *b_elePFNeuIso_;   //!
   TBranch        *b_elePFChIso_;   //!
   TBranch        *b_elePFPhoIso_;   //!
   TBranch        *b_elePFPUIso_;   //!
   TBranch        *b_ele_hcalPFClusterIso_;   //!
   TBranch        *b_ele_ecalPFClusterIso_;   //!
   TBranch        *b_ele_dr03EcalRecHitSumEt_;   //!
   TBranch        *b_ele_dr03HcalTowerSumEt_;   //!
   TBranch        *b_ele_dr03HcalDepth1TowerSumEt_;   //!
   TBranch        *b_ele_dr03HcalDepth2TowerSumEt_;   //!
   TBranch        *b_ele_dr03TkSumPt_;   //!
   TBranch        *b_ele_dr03TkSumPtHEEP_;   //!
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
   TBranch        *b_rho_;   //!
   TBranch        *b_run_number_;   //!
   TBranch        *b_lumi_number_;   //!
   TBranch        *b_event_number_;   //!

   testMax2x2(TTree *tree=0);
   virtual ~testMax2x2();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef testMax2x2_cxx
testMax2x2::testMax2x2(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/phys_egamma/swmukher/HoE_Feb16_2020/EleGun2021.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/cms/store/group/phys_egamma/swmukher/HoE_Feb16_2020/EleGun2021.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/phys_egamma/swmukher/HoE_Feb16_2020/EleGun2021.root:/demo");
      ///      TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/phys_egamma/swmukher/HoE_Feb16_2020/addGapInfo/EleGun2018.root:/demo");
      dir->GetObject("EventTree",tree);

   }
   Init(tree);
}

testMax2x2::~testMax2x2()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t testMax2x2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t testMax2x2::LoadTree(Long64_t entry)
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

void testMax2x2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ele_isEB_ = 0;
   ele_isEE_ = 0;
   ele_isEBEEGap_ = 0;
   ele_isEBEtaGap_ = 0;
   ele_isEBPhiGap_ = 0;
   ele_isEEDeeGap_ = 0;
   ele_isEERingGap_ = 0;
   ele_isGap_ = 0;
   ele_golden_ = 0;
   ele_unknown_ = 0;
   ele_bigbrem_ = 0;
   ele_gap_ = 0;
   ele_badtrack_ = 0;
   ele_showering_ = 0;
   ele_trackFbrem_ = 0;
   ele_superClusterFbrem_ = 0;
   ele_numberOfBrems_ = 0;
   ele_genmatched_ = 0;
   dR_recoEle_genEle_ = 0;
   ptRecoEle_by_ptGenEle_ = 0;
   scEn_ = 0;
   eleSCRawEn_ = 0;
   ecalEn_ = 0;
   seedEn_ = 0;
   seedEnCorr_ = 0;
   cmssw_eleHoE_ = 0;
   cmssw_eleHoE_tower_ = 0;
   cmssw_eleHoE_full5x5_ = 0;
   eleScEta_ = 0;
   eleScPhi_ = 0;
   elePt_ = 0;
   eleGenPt_ = 0;
   ele_full5x5_r9_ = 0;
   elePhi_ = 0;
   eleSigmaIEtaIEtaFull5x5_ = 0;
   elePFNeuIso_ = 0;
   elePFChIso_ = 0;
   elePFPhoIso_ = 0;
   elePFPUIso_ = 0;
   ele_hcalPFClusterIso_ = 0;
   ele_ecalPFClusterIso_ = 0;
   ele_dr03EcalRecHitSumEt_ = 0;
   ele_dr03HcalTowerSumEt_ = 0;
   ele_dr03HcalDepth1TowerSumEt_ = 0;
   ele_dr03HcalDepth2TowerSumEt_ = 0;
   ele_dr03TkSumPt_ = 0;
   ele_dr03TkSumPtHEEP_ = 0;
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
   run_number_ = 0;
   lumi_number_ = 0;
   event_number_ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ele_isEB_", &ele_isEB_, &b_ele_isEB_);
   fChain->SetBranchAddress("ele_isEE_", &ele_isEE_, &b_ele_isEE_);
   fChain->SetBranchAddress("ele_isEBEEGap_", &ele_isEBEEGap_, &b_ele_isEBEEGap_);
   fChain->SetBranchAddress("ele_isEBEtaGap_", &ele_isEBEtaGap_, &b_ele_isEBEtaGap_);
   fChain->SetBranchAddress("ele_isEBPhiGap_", &ele_isEBPhiGap_, &b_ele_isEBPhiGap_);
   fChain->SetBranchAddress("ele_isEEDeeGap_", &ele_isEEDeeGap_, &b_ele_isEEDeeGap_);
   fChain->SetBranchAddress("ele_isEERingGap_", &ele_isEERingGap_, &b_ele_isEERingGap_);
   fChain->SetBranchAddress("ele_isGap_", &ele_isGap_, &b_ele_isGap_);
   fChain->SetBranchAddress("ele_golden_", &ele_golden_, &b_ele_golden_);
   fChain->SetBranchAddress("ele_unknown_", &ele_unknown_, &b_ele_unknown_);
   fChain->SetBranchAddress("ele_bigbrem_", &ele_bigbrem_, &b_ele_bigbrem_);
   fChain->SetBranchAddress("ele_gap_", &ele_gap_, &b_ele_gap_);
   fChain->SetBranchAddress("ele_badtrack_", &ele_badtrack_, &b_ele_badtrack_);
   fChain->SetBranchAddress("ele_showering_", &ele_showering_, &b_ele_showering_);
   fChain->SetBranchAddress("ele_trackFbrem_", &ele_trackFbrem_, &b_ele_trackFbrem_);
   fChain->SetBranchAddress("ele_superClusterFbrem_", &ele_superClusterFbrem_, &b_ele_superClusterFbrem_);
   fChain->SetBranchAddress("ele_numberOfBrems_", &ele_numberOfBrems_, &b_ele_numberOfBrems_);
   fChain->SetBranchAddress("ele_genmatched_", &ele_genmatched_, &b_ele_genmatched_);
   fChain->SetBranchAddress("dR_recoEle_genEle_", &dR_recoEle_genEle_, &b_dR_recoEle_genEle_);
   fChain->SetBranchAddress("ptRecoEle_by_ptGenEle_", &ptRecoEle_by_ptGenEle_, &b_ptRecoEle_by_ptGenEle_);
   fChain->SetBranchAddress("scEn_", &scEn_, &b_scEn_);
   fChain->SetBranchAddress("eleSCRawEn_", &eleSCRawEn_, &b_eleSCRawEn_);
   fChain->SetBranchAddress("ecalEn_", &ecalEn_, &b_ecalEn_);
   fChain->SetBranchAddress("seedEn_", &seedEn_, &b_seedEn_);
   fChain->SetBranchAddress("seedEnCorr_", &seedEnCorr_, &b_seedEnCorr_);
   fChain->SetBranchAddress("cmssw_eleHoE_", &cmssw_eleHoE_, &b_cmssw_eleHoE_);
   fChain->SetBranchAddress("cmssw_eleHoE_tower_", &cmssw_eleHoE_tower_, &b_cmssw_eleHoE_tower_);
   fChain->SetBranchAddress("cmssw_eleHoE_full5x5_", &cmssw_eleHoE_full5x5_, &b_cmssw_eleHoE_full5x5_);
   fChain->SetBranchAddress("eleScEta_", &eleScEta_, &b_eleScEta_);
   fChain->SetBranchAddress("eleScPhi_", &eleScPhi_, &b_eleScPhi_);
   fChain->SetBranchAddress("elePt_", &elePt_, &b_elePt_);
   fChain->SetBranchAddress("eleGenPt_", &eleGenPt_, &b_eleGenPt_);
   fChain->SetBranchAddress("ele_full5x5_r9_", &ele_full5x5_r9_, &b_ele_full5x5_r9_);
   fChain->SetBranchAddress("elePhi_", &elePhi_, &b_elePhi_);
   fChain->SetBranchAddress("eleSigmaIEtaIEtaFull5x5_", &eleSigmaIEtaIEtaFull5x5_, &b_eleSigmaIEtaIEtaFull5x5_);
   fChain->SetBranchAddress("elePFNeuIso_", &elePFNeuIso_, &b_elePFNeuIso_);
   fChain->SetBranchAddress("elePFChIso_", &elePFChIso_, &b_elePFChIso_);
   fChain->SetBranchAddress("elePFPhoIso_", &elePFPhoIso_, &b_elePFPhoIso_);
   fChain->SetBranchAddress("elePFPUIso_", &elePFPUIso_, &b_elePFPUIso_);
   fChain->SetBranchAddress("ele_hcalPFClusterIso_", &ele_hcalPFClusterIso_, &b_ele_hcalPFClusterIso_);
   fChain->SetBranchAddress("ele_ecalPFClusterIso_", &ele_ecalPFClusterIso_, &b_ele_ecalPFClusterIso_);
   fChain->SetBranchAddress("ele_dr03EcalRecHitSumEt_", &ele_dr03EcalRecHitSumEt_, &b_ele_dr03EcalRecHitSumEt_);
   fChain->SetBranchAddress("ele_dr03HcalTowerSumEt_", &ele_dr03HcalTowerSumEt_, &b_ele_dr03HcalTowerSumEt_);
   fChain->SetBranchAddress("ele_dr03HcalDepth1TowerSumEt_", &ele_dr03HcalDepth1TowerSumEt_, &b_ele_dr03HcalDepth1TowerSumEt_);
   fChain->SetBranchAddress("ele_dr03HcalDepth2TowerSumEt_", &ele_dr03HcalDepth2TowerSumEt_, &b_ele_dr03HcalDepth2TowerSumEt_);
   fChain->SetBranchAddress("ele_dr03TkSumPt_", &ele_dr03TkSumPt_, &b_ele_dr03TkSumPt_);
   fChain->SetBranchAddress("ele_dr03TkSumPtHEEP_", &ele_dr03TkSumPtHEEP_, &b_ele_dr03TkSumPtHEEP_);
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
   fChain->SetBranchAddress("rho_", &rho_, &b_rho_);
   fChain->SetBranchAddress("run_number_", &run_number_, &b_run_number_);
   fChain->SetBranchAddress("lumi_number_", &lumi_number_, &b_lumi_number_);
   fChain->SetBranchAddress("event_number_", &event_number_, &b_event_number_);
   Notify();
}

Bool_t testMax2x2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void testMax2x2::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t testMax2x2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef testMax2x2_cxx
