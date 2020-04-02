// -*- C++ -*-
//
// Package:    HoE/HoEAnalyzer
// Class:      HoEAnalyzer
//
/**\class HoEAnalyzer HoEAnalyzer.cc HoE/HoEAnalyzer/plugins/HoEAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Swagata Mukherjee
//         Created:  Mon, 04 Nov 2019 14:29:29 GMT
//
//


// system include files
#include <memory>
// user include files
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHadTower.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
#include "Geometry/Records/interface/CaloTopologyRecord.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloEventSetup/plugins/CaloTopologyBuilder.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/CaloTopology/interface/CaloSubdetectorTopology.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "DataFormats/CaloTowers/interface/CaloTower.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaTowerIsolation.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "TTree.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#include "RecoEgamma/EgammaElectronAlgos/interface/GsfElectronTools.h"
#include "RecoEgamma/EgammaElectronAlgos/interface/GsfElectronAlgo.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include <cmath>
#include "TVector3.h"
#include "TLorentzVector.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/CaloRecHit/interface/CaloCluster.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"
#include "RecoEgamma/EgammaElectronAlgos/interface/ElectronHcalHelper.h"
#include "Geometry/CaloTopology/interface/CaloTowerConstituentsMap.h"
#include "DataFormats/CaloTowers/interface/CaloTowerDetId.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EGHcalRecHitSelector.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.


class HoEAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
public:
  explicit HoEAnalyzer(const edm::ParameterSet&);
  ~HoEAnalyzer();
  
  static edm::ParameterSetDescription makePSetDescription();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  edm::Service<TFileService> fs;
  TTree   *tree = fs->make<TTree>("EventTree", "EventData");
  //
  //geometry & gap info
  //
  std::vector<int>  ele_isEB; // true if particle is in ECAL Barrel
  std::vector<int>  ele_isEE; // true if particle is in ECAL Endcaps
  std::vector<int>  ele_isEBEEGap; // true if particle is in the crack between EB and EE
  std::vector<int>  ele_isEBEtaGap; // true if particle is in EB, and inside the eta gaps between modules
  std::vector<int>  ele_isEBPhiGap; // true if particle is in EB, and inside the phi gaps between modules
  std::vector<int>  ele_isEEDeeGap; // true if particle is in EE, and inside the gaps between dees
  std::vector<int>  ele_isEERingGap; // true if particle is in EE, and inside the gaps between rings
  std::vector<int>  ele_isGap_cmssw; 
  std::vector<int>  ele_isGap_custom_without4060; 
  std::vector<int>  ele_isGap_custom_with4060; 
  std::vector<int>  ele_nearGap_cmssw;
  std::vector<int>  ele_nearGap_custom_with4060; 
  std::vector<int>  ele_nearGap_custom_without4060; 
  //
  std::vector<int>  ele_golden;
  std::vector<int>  ele_unknown;
  std::vector<int>  ele_bigbrem;
  std::vector<int>  ele_badtrack;
  std::vector<int>  ele_showering;
  std::vector<int>  ele_gap;
  std::vector<float> ele_trackFbrem;
  std::vector<float> ele_superClusterFbrem;
  std::vector<int> ele_numberOfBrems;
  std::vector<int>  ele_genmatched;
  std::vector<float>  scEn;
  std::vector<float>  dR_recoEle_genEle;
  std::vector<float>  ptRecoEle_by_ptGenEle;
  std::vector<float>  eleSCRawEn;
  std::vector<float>  ecalEn;
  std::vector<float>  seedEn;
  std::vector<float>  seedEnCorr;
  std::vector<float>  cmssw_eleHoE;
  std::vector<float>  cmssw_eleHoE_tower;
  std::vector<float>  cmssw_eleHoE_full5x5;
  std::vector<float>  eleScEta;
  std::vector<float>  eleScPhi;
  std::vector<float>  elePt;
  std::vector<float>  eleGenPt;
  std::vector<float>  ele_full5x5_r9;
  std::vector<float>  elePhi;
  std::vector<float>  eleSigmaIEtaIEtaFull5x5;
  //
  std::vector<float>  elePFNeuIso;
  std::vector<float>  elePFChIso;
  std::vector<float>  elePFPhoIso;
  std::vector<float>  elePFPUIso;
  std::vector<float>  ele_hcalPFClusterIso;
  std::vector<float>  ele_ecalPFClusterIso;
  std::vector<float>  ele_dr03EcalRecHitSumEt;
  std::vector<float>  ele_dr03HcalTowerSumEt;
  std::vector<float>  ele_dr03HcalDepth1TowerSumEt;
  std::vector<float>  ele_dr03HcalDepth2TowerSumEt;
  std::vector<float>  ele_dr03TkSumPt;
  std::vector<float>  ele_dr03TkSumPtHEEP;

  //
  std::vector<int>    eleSeedDet;
  std::vector<int>    eleSeedSubdet;
  std::vector<int>    eleSeedIeta;
  std::vector<int>    eleSeedIphi;
  std::vector<float>  eleSeedEta;
  std::vector<float>  eleSeedPhi;
  std::vector<int>    eleSeedRawID;
  std::vector<int>    seedHcalIeta;
  std::vector<int>    seedHcalIphi;

  std::vector<std::vector<int>>    hcalRechitIeta;
  std::vector<std::vector<int>>    hcalRechitIphi;
  std::vector<std::vector<float>>  hcalRechitEnergy;
  std::vector<std::vector<int>>    hcalRechitAbsDIetaFromEleSeed;
  std::vector<std::vector<int>>    hcalRechitAbsDIphiFromEleSeed;
  std::vector<std::vector<int>>    hcalRechitRawID;
  std::vector<std::vector<int>>    hcalRechitDepth; // mostly for Run 3 //
  std::vector<std::vector<float>>    hcalRechitEta;
  std::vector<std::vector<float>>    hcalRechitPhi;

  std::vector<int>    perEle_hcalRechitIeta;
  std::vector<int>    perEle_hcalRechitIphi;
  std::vector<float>  perEle_hcalRechitEnergy;
  std::vector<int>    perEle_hcalRechitAbsDIetaFromEleSeed;
  std::vector<int>    perEle_hcalRechitAbsDIphiFromEleSeed;
  std::vector<int>    perEle_hcalRechitRawID;
  std::vector<int>    perEle_hcalRechitDepth; // mostly for Run 3 //
  std::vector<float>  perEle_hcalRechitEta;
  std::vector<float>  perEle_hcalRechitPhi;

  std::vector<float>  puTrue;
  //for event-display
  std::vector<int> run_number;
  std::vector<int> lumi_number;
  std::vector<int> event_number;
  //

  float rho;

  
private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  static int calDIEta(int iEta1, int iEta2);
  static int calDIPhi(int iPhi1, int iPhi2);
  float getMinEnergyHCAL_(HcalDetId id) const;
  
  int maxDIEta_=5;
  int maxDIPhi_=5;

  // ----------member data ---------------------------
  edm::EDGetTokenT<double> rhoLabel_;
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >     puCollection_;
  edm::EDGetTokenT<HBHERecHitCollection> hbhe_rechits_;
  edm::EDGetTokenT<EcalRecHitCollection> ebReducedRecHitCollection_;
  edm::EDGetTokenT<EcalRecHitCollection> eeReducedRecHitCollection_;
  edm::EDGetTokenT<EcalRecHitCollection> esReducedRecHitCollection_;
  edm::ESHandle<CaloGeometry> theCaloGeometry;  
  edm::ESHandle<CaloTowerConstituentsMap> towerMap_;
  edm::EDGetTokenT<std::vector<reco::GenParticle> >     genParticlesCollection_;

  bool Run2_2018 ; // Now two options are supported, Run2_2018 and Run3
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
HoEAnalyzer::HoEAnalyzer(const edm::ParameterSet& iConfig)
  :
  rhoLabel_(consumes<double>(iConfig.getParameter<edm::InputTag>("rhoLabel"))),
  eleToken_(consumes<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
  puCollection_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupCollection"))),
  hbhe_rechits_(consumes<HBHERecHitCollection>(iConfig.getParameter<edm::InputTag>("hbheInput"))),
  ebReducedRecHitCollection_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("ebReducedRecHitCollection"))),
  eeReducedRecHitCollection_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("eeReducedRecHitCollection"))),
  esReducedRecHitCollection_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("esReducedRecHitCollection"))),
  genParticlesCollection_(consumes<std::vector<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("genParticleSrc"))),
  Run2_2018(iConfig.getParameter<bool>("Run2_2018_"))

{
  //now do what ever initialization is needed

  // geometry, gaps etc info
  tree->Branch("ele_isEB_",&ele_isEB);
  tree->Branch("ele_isEE_",&ele_isEE);
  tree->Branch("ele_isEBEEGap_",&ele_isEBEEGap);
  tree->Branch("ele_isEBEtaGap_",&ele_isEBEtaGap);
  tree->Branch("ele_isEBPhiGap_",&ele_isEBPhiGap);
  tree->Branch("ele_isEEDeeGap_",&ele_isEEDeeGap);
  tree->Branch("ele_isEERingGap_",&ele_isEERingGap);
  tree->Branch("ele_isGap_cmssw_",&ele_isGap_cmssw);
  tree->Branch("ele_isGap_custom_without4060_",&ele_isGap_custom_without4060);
  tree->Branch("ele_isGap_custom_with4060_",&ele_isGap_custom_with4060);
  tree->Branch("ele_nearGap_cmssw_",&ele_nearGap_cmssw);
  tree->Branch("ele_nearGap_custom_with4060_",&ele_nearGap_custom_with4060);
  tree->Branch("ele_nearGap_custom_without4060_",&ele_nearGap_custom_without4060);
  //
  tree->Branch("ele_golden_",&ele_golden);
  tree->Branch("ele_unknown_",&ele_unknown);
  tree->Branch("ele_bigbrem_",&ele_bigbrem);
  tree->Branch("ele_gap_",&ele_gap);
  tree->Branch("ele_badtrack_",&ele_badtrack);
  tree->Branch("ele_showering_",&ele_showering);
  tree->Branch("ele_trackFbrem_",&ele_trackFbrem);
  tree->Branch("ele_superClusterFbrem_",&ele_superClusterFbrem);
  tree->Branch("ele_numberOfBrems_",&ele_numberOfBrems);
  tree->Branch("ele_genmatched_",&ele_genmatched);
  tree->Branch("dR_recoEle_genEle_",&dR_recoEle_genEle);
  tree->Branch("ptRecoEle_by_ptGenEle_",&ptRecoEle_by_ptGenEle);
  tree->Branch("scEn_",&scEn);
  tree->Branch("eleSCRawEn_",&eleSCRawEn);
  tree->Branch("ecalEn_",&ecalEn);
  tree->Branch("seedEn_",&seedEn);
  tree->Branch("seedEnCorr_",&seedEnCorr);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("cmssw_eleHoE_tower_",&cmssw_eleHoE_tower);
  tree->Branch("cmssw_eleHoE_full5x5_",&cmssw_eleHoE_full5x5);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("eleScPhi_",&eleScPhi);
  tree->Branch("elePt_",&elePt);
  tree->Branch("eleGenPt_",&eleGenPt);
  tree->Branch("ele_full5x5_r9_",&ele_full5x5_r9);
  tree->Branch("elePhi_",&elePhi);
  tree->Branch("eleSigmaIEtaIEtaFull5x5_",&eleSigmaIEtaIEtaFull5x5);
  tree->Branch("elePFNeuIso_",&elePFNeuIso);
  tree->Branch("elePFChIso_",&elePFChIso);
  tree->Branch("elePFPhoIso_",&elePFPhoIso);
  tree->Branch("elePFPUIso_",&elePFPUIso);
  tree->Branch("ele_hcalPFClusterIso_",&ele_hcalPFClusterIso);
  tree->Branch("ele_ecalPFClusterIso_",&ele_ecalPFClusterIso);
  tree->Branch("ele_dr03EcalRecHitSumEt_",&ele_dr03EcalRecHitSumEt);
  tree->Branch("ele_dr03HcalTowerSumEt_",&ele_dr03HcalTowerSumEt);
  tree->Branch("ele_dr03HcalDepth1TowerSumEt_",&ele_dr03HcalDepth1TowerSumEt);
  tree->Branch("ele_dr03HcalDepth2TowerSumEt_",&ele_dr03HcalDepth2TowerSumEt);
  tree->Branch("ele_dr03TkSumPt_",&ele_dr03TkSumPt);
  tree->Branch("ele_dr03TkSumPtHEEP_",&ele_dr03TkSumPtHEEP);

  tree->Branch("eleSeedDet_",&eleSeedDet);
  tree->Branch("eleSeedSubdet_",&eleSeedSubdet);
  tree->Branch("eleSeedIeta_",&eleSeedIeta);
  tree->Branch("eleSeedIphi_",&eleSeedIphi);
  tree->Branch("eleSeedEta_",&eleSeedEta);
  tree->Branch("eleSeedPhi_",&eleSeedPhi);
  tree->Branch("eleSeedRawID_",&eleSeedRawID);
  tree->Branch("seedHcalIeta_",&seedHcalIeta);
  tree->Branch("seedHcalIphi_",&seedHcalIphi);
  tree->Branch("hcalRechitIeta_",&hcalRechitIeta);
  tree->Branch("hcalRechitIphi_",&hcalRechitIphi);
  tree->Branch("hcalRechitEnergy_",&hcalRechitEnergy);
  tree->Branch("hcalRechitAbsDIetaFromEleSeed_",&hcalRechitAbsDIetaFromEleSeed);
  tree->Branch("hcalRechitAbsDIphiFromEleSeed_",&hcalRechitAbsDIphiFromEleSeed);
  tree->Branch("hcalRechitRawID_",&hcalRechitRawID);
  tree->Branch("hcalRechitDepth_",&hcalRechitDepth);
  tree->Branch("hcalRechitEta_",&hcalRechitEta);
  tree->Branch("hcalRechitPhi_",&hcalRechitPhi);
  tree->Branch("puTrue_", &puTrue);
  tree->Branch("rho_", &rho);
  tree->Branch("run_number_", &run_number);
  tree->Branch("lumi_number_", &lumi_number);
  tree->Branch("event_number_", &event_number);

}


HoEAnalyzer::~HoEAnalyzer()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void
HoEAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  ///  std::cout << " \n ****** new event ... " << std::endl; 
  using namespace edm;
  
  ele_isEB.clear();
  ele_isEE.clear();
  ele_isEBEEGap.clear();
  ele_isEBEtaGap.clear();
  ele_isEBPhiGap.clear();
  ele_isEEDeeGap.clear();
  ele_isEERingGap.clear();
  ele_isGap_cmssw.clear();
  ele_isGap_custom_without4060.clear();
  ele_isGap_custom_with4060.clear();
  ele_nearGap_cmssw.clear();
  ele_nearGap_custom_with4060.clear();
  ele_nearGap_custom_without4060.clear();
  //
  ele_golden.clear();
  ele_unknown.clear();
  ele_badtrack.clear();
  ele_bigbrem.clear();
  ele_showering.clear();
  ele_gap.clear();
  ele_trackFbrem.clear();
  ele_superClusterFbrem.clear();
  ele_numberOfBrems.clear();
  ele_genmatched.clear();
  ptRecoEle_by_ptGenEle.clear();
  dR_recoEle_genEle.clear();
  scEn.clear();
  eleSCRawEn.clear();
  ecalEn.clear();
  seedEn.clear();
  seedEnCorr.clear();
  cmssw_eleHoE.clear();
  cmssw_eleHoE_tower.clear();
  cmssw_eleHoE_full5x5.clear();
  eleScEta.clear();
  eleScPhi.clear();
  elePt.clear();
  eleGenPt.clear();
  ele_full5x5_r9.clear();
  elePhi.clear();
  eleSigmaIEtaIEtaFull5x5.clear();
  elePFNeuIso.clear();
  elePFChIso.clear();
  elePFPhoIso.clear();
  elePFPUIso.clear();
  ele_hcalPFClusterIso.clear();
  ele_ecalPFClusterIso.clear();
  ele_dr03EcalRecHitSumEt.clear();
  ele_dr03HcalTowerSumEt.clear();
  ele_dr03HcalDepth1TowerSumEt.clear();
  ele_dr03HcalDepth2TowerSumEt.clear();
  ele_dr03TkSumPt.clear();
  ele_dr03TkSumPtHEEP.clear();

  eleSeedDet.clear();
  eleSeedSubdet.clear();
  eleSeedIeta.clear();
  eleSeedIphi.clear();
  eleSeedEta.clear();
  eleSeedPhi.clear();
  eleSeedRawID.clear();
  seedHcalIeta.clear();
  seedHcalIphi.clear();

  hcalRechitIeta.clear();
  hcalRechitIphi.clear();
  hcalRechitEnergy.clear();
  hcalRechitAbsDIetaFromEleSeed.clear();
  hcalRechitAbsDIphiFromEleSeed.clear();
  hcalRechitRawID.clear();
  hcalRechitDepth.clear();
  hcalRechitEta.clear();
  hcalRechitPhi.clear();

  puTrue.clear();
  run_number.clear();
  lumi_number.clear(); 
  event_number.clear();

  run_number.push_back(iEvent.id().run());
  lumi_number.push_back(iEvent.luminosityBlock()); 
  event_number.push_back(iEvent.id().event());

  //  std::cout << "run/lumi/event " << run_number << "/" << lumi_number << "/" << event_number << std::endl;

  edm::Handle<double> rhoHandle;
  iEvent.getByToken(rhoLabel_, rhoHandle);
  rho = *(rhoHandle.product());

  edm::Handle<std::vector<PileupSummaryInfo> > genPileupHandle;
  iEvent.getByToken(puCollection_, genPileupHandle);
  
  if (genPileupHandle.isValid()) {
    for (std::vector<PileupSummaryInfo>::const_iterator pu = genPileupHandle->begin(); pu != genPileupHandle->end(); ++pu) {
      puTrue.push_back(pu->getTrueNumInteractions());
    }
  }
  
  edm::Handle<HBHERecHitCollection> hbheRechitsHandle;
  iEvent.getByToken(hbhe_rechits_, hbheRechitsHandle);
  iSetup.get<CaloGeometryRecord>().get(theCaloGeometry);
  iSetup.get<CaloGeometryRecord>().get(towerMap_);

    
  edm::Handle<std::vector<reco::GenParticle> > genParticlesHandle;
  iEvent.getByToken(genParticlesCollection_, genParticlesHandle);
  
  
  for(const auto& ele : iEvent.get(eleToken_) ) {
    //    std::cout << "\n new electron ...\n" ;
    int genmatched=0;
    double min_dr=9999.9;
    double ptR=9999.9;
    double this_eleGenPt=-99;
    //double this_eleGenE=-99;
   
    if (genParticlesHandle.isValid()) {
      //std::cout << "starting gen particle loop \n " ;
      for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	//std::cout << " p->pdgId() " << p->pdgId() << std::endl;
	//	if ( (abs(p->pdgId())) ==11 ) { 
	  //std::cout << "-----  p->status() " << p->status() << " p->pdgId() " << p->pdgId() << std::endl;
	//}
	if ( (p->status()==1) &&  ((abs(p->pdgId())) == 11)  ) {
	  // std::cout <<  "ndaughter" << p->numberOfDaughters() << std::endl;

	  //std::cout << "checking if the reco ele match with this one" << std::endl;
	  double this_dr=reco::deltaR(ele,*p);
	  //std::cout << "this_dr " << this_dr << std::endl;
	  if (this_dr<min_dr) {
	    min_dr=this_dr;
	    ptR=ele.pt()/p->pt();
	    this_eleGenPt=p->pt();
	    //this_eleGenE=p->energy();
	  }
	}  
      }

    }
  
    if ( (min_dr<0.04) && (ptR>0.7) && (ptR<1.3) )  genmatched=1; // these cuts were decided looking at min_dr and ptR distributions.
    dR_recoEle_genEle.push_back(min_dr);
    ptRecoEle_by_ptGenEle.push_back(ptR);
    //  std::cout << "genmatched = " << genmatched <<  " min_dr " << min_dr << " ptR " << ptR   <<  std::endl;    
    ele_genmatched.push_back(genmatched);

    //  std::cout << " genmatched = " << genmatched  << ", eleGenPt = " << this_eleGenPt << " recoPt=" << ele.pt() <<  std::endl;   
    
    perEle_hcalRechitIeta.clear();
    perEle_hcalRechitIphi.clear();
    perEle_hcalRechitEnergy.clear();
    perEle_hcalRechitAbsDIetaFromEleSeed.clear();
    perEle_hcalRechitAbsDIphiFromEleSeed.clear();
    perEle_hcalRechitRawID.clear();
    perEle_hcalRechitDepth.clear();
    perEle_hcalRechitEta.clear();
    perEle_hcalRechitPhi.clear();
        
    eleScEta.push_back(ele.superCluster()->eta());
    eleScPhi.push_back(ele.superCluster()->phi());
    elePt.push_back(ele.pt());
    eleGenPt.push_back(this_eleGenPt);
    ele_full5x5_r9.push_back(ele.full5x5_r9());
    elePhi.push_back(ele.phi());
    eleSigmaIEtaIEtaFull5x5.push_back(ele.full5x5_sigmaIetaIeta());
  
    //gap, geometry etc
    ele_isEB.push_back(ele.isEB()) ;
    ele_isEE.push_back(ele.isEE()) ;
    ele_isEBEEGap.push_back(ele.isEBEEGap()) ;
    ele_isEBEtaGap.push_back(ele.isEBEtaGap()) ;
    ele_isEBPhiGap.push_back(ele.isEBPhiGap()) ;
    ele_isEEDeeGap.push_back(ele.isEEDeeGap());
    ele_isEERingGap.push_back(ele.isEERingGap());
    ele_isGap_cmssw.push_back(ele.isGap());
    //   std::cout << "ele.isGap() = " << ele.isGap() << std::endl;

    reco::GsfElectron::PflowIsolationVariables pfIso = ele.pfIsolationVariables();
    elePFNeuIso.push_back(pfIso.sumNeutralHadronEt);
    elePFChIso.push_back(pfIso.sumChargedHadronPt);
    elePFPhoIso.push_back(pfIso.sumPhotonEt);
    elePFPUIso.push_back(pfIso.sumPUPt);
    ele_hcalPFClusterIso.push_back(ele.hcalPFClusterIso());
    ele_ecalPFClusterIso.push_back(ele.ecalPFClusterIso());
    ele_dr03EcalRecHitSumEt.push_back(ele.dr03EcalRecHitSumEt());
    ele_dr03HcalTowerSumEt.push_back(ele.dr03HcalTowerSumEt());
    ele_dr03HcalDepth1TowerSumEt.push_back(ele.dr03HcalDepth1TowerSumEt());
    ele_dr03HcalDepth2TowerSumEt.push_back(ele.dr03HcalDepth2TowerSumEt());
    ele_dr03TkSumPt.push_back(ele.dr03TkSumPt());
    ele_dr03TkSumPtHEEP.push_back(ele.dr03TkSumPtHEEP());

    EcalClusterLazyTools       lazyTool    (iEvent, iSetup, ebReducedRecHitCollection_, eeReducedRecHitCollection_, esReducedRecHitCollection_);

    const reco::SuperCluster& superClus = *ele.superCluster();
    const reco::CaloCluster &seedCluster = *superClus.seed();

    int nClusNextToBoundary=0;
    int isNearGap_cmssw=0;
    //tag ele near gap
    if (superClus.clusters().isAvailable()) {
      for (auto& bc : superClus.clusters() ) {
	DetId bcId = bc->hitsAndFractions()[0].first;
	int detector = bcId.subdetId();
	//barrel
	if (detector == EcalBarrel) {
	  EBDetId ebdetid(bcId);
	  if (  (EBDetId::isNextToEtaBoundary(ebdetid))  ||   (EBDetId::isNextToPhiBoundary(ebdetid))   ) {
	    nClusNextToBoundary++;
	  } //next to eta or phi boundary 
	} //barrel
	//
	//endcap
	else if (detector == EcalEndcap) {
	  EEDetId eedetid(bcId);
	  if (  (EEDetId::isNextToRingBoundary(eedetid))  ||   (EEDetId::isNextToDBoundary(eedetid))   ) {
	    nClusNextToBoundary++;
	  } //next to ring or dee boundary 
	} //endcap

      }
    }
    if  (nClusNextToBoundary>0)  {
      isNearGap_cmssw=1;
    }
    ele_nearGap_cmssw.push_back(isNearGap_cmssw);


    DetId seedId = seedCluster.seed() ;

    //// Now I'm convinced that CMSSW isGap() is crap for EE. 
    //// Instead, tag the gap electrons by hardcoding the gaps ieta/iphi, ix/iy 
    //// Taking help from TrigNtup/src/EGRegTreeStruct.cc from Sam-Harper/usercode ////
    int isGapcustom=0;
    float   etaGapCode, phiGapCode ;
    if ( seedCluster.seed().subdetId()==EcalBarrel ) {
      EBDetId ebDetId(seedCluster.seed());
      auto gapCode=[](int iEtaAbs){
	if(iEtaAbs==25 || iEtaAbs==45 || iEtaAbs==65 || iEtaAbs==85) return -1;//before gap
	else if(iEtaAbs==1 || iEtaAbs==26 || iEtaAbs==46 || iEtaAbs==66) return 1;//after gap
	else return 0; //no gap
      };
      etaGapCode = gapCode(ebDetId.ietaAbs());
      phiGapCode = ebDetId.iphi()%20 == 0 ? -1 : ebDetId.iphi()%20 ==1 ? 1 : 0;
    }else{
      EEDetId eeDetId(seedCluster.seed());
      auto gapCode=[](int iAbs){
	if(iAbs==40 || iAbs==45 || iAbs==50 || iAbs==55 || iAbs==60) return -1;//before gap
	else if(iAbs==41 || iAbs==46 || iAbs==51 || iAbs==56 || iAbs==61) return 1;//after gap
	else return 0; //no gap
      };
      etaGapCode = gapCode(eeDetId.ix());
      phiGapCode = gapCode(eeDetId.iy());
    }
    if ( (etaGapCode!=0) || (phiGapCode!=0) ) isGapcustom=1 ;
    ele_isGap_custom_with4060.push_back(isGapcustom);

    //// without 40 60
    int isGapcustom_without4060=0;
    float   etaGapCode_without4060, phiGapCode_without4060 ;
    if ( seedCluster.seed().subdetId()==EcalBarrel ) {
      EBDetId ebDetId(seedCluster.seed());
      auto gapCode_without4060=[](int iEtaAbs_without4060){
	if(iEtaAbs_without4060==25 || iEtaAbs_without4060==45 || iEtaAbs_without4060==65 || iEtaAbs_without4060==85) return -1;//before gap
	else if(iEtaAbs_without4060==1 || iEtaAbs_without4060==26 || iEtaAbs_without4060==46 || iEtaAbs_without4060==66) return 1;//after gap
	else return 0; //no gap
      };
      etaGapCode_without4060 = gapCode_without4060(ebDetId.ietaAbs());
      phiGapCode_without4060 = ebDetId.iphi()%20 == 0 ? -1 : ebDetId.iphi()%20 ==1 ? 1 : 0;
    }else{
      EEDetId eeDetId(seedCluster.seed());
      auto gapCode_without4060=[](int iAbs_without4060){
	if(iAbs_without4060==45 || iAbs_without4060==50 || iAbs_without4060==55 ) return -1;//before gap
	else if(iAbs_without4060==46 || iAbs_without4060==51 || iAbs_without4060==56 ) return 1;//after gap
	else return 0; //no gap
      };
      etaGapCode_without4060 = gapCode_without4060(eeDetId.ix());
      phiGapCode_without4060 = gapCode_without4060(eeDetId.iy());
    }
    if ( (etaGapCode_without4060!=0) || (phiGapCode_without4060!=0) ) isGapcustom_without4060=1 ;
    ele_isGap_custom_without4060.push_back(isGapcustom_without4060);

    //////near gap //// with 40 60 ////
    int nClusNextToBoundary_custom=0;
    int isNearGapCustom=0;
    float   etaGapCode2, phiGapCode2 ;
    if (superClus.clusters().isAvailable()) {
      for (auto& bc : superClus.clusters() ) {
	//std::cout << "new basic cluster (custom)\n" ;
	DetId bcId = bc->hitsAndFractions()[0].first;
	int detector = bcId.subdetId();
	if ( detector==EcalBarrel ) {
	  EBDetId ebDetId(bcId);
	  auto gapCode2=[](int iEtaAbs2){
	    if(iEtaAbs2==25 || iEtaAbs2==45 || iEtaAbs2==65 || iEtaAbs2==85) return -1;//before gap
	    else if(iEtaAbs2==1 || iEtaAbs2==26 || iEtaAbs2==46 || iEtaAbs2==66) return 1;//after gap
	    else return 0; //no gap
	  };
	  etaGapCode2 = gapCode2(ebDetId.ietaAbs());
	  phiGapCode2 = ebDetId.iphi()%20 == 0 ? -1 : ebDetId.iphi()%20 ==1 ? 1 : 0;
	}else{
	  EEDetId eeDetId(bcId);
	  auto gapCode2=[](int iAbs2){
	    if(iAbs2==40 || iAbs2==45 || iAbs2==50 || iAbs2==55 || iAbs2==60) return -1;//before gap
	    else if(iAbs2==41 || iAbs2==46 || iAbs2==51 || iAbs2==56 || iAbs2==61) return 1;//after gap
	    else return 0; //no gap
	  };
	  etaGapCode2 = gapCode2(eeDetId.ix());
	  phiGapCode2 = gapCode2(eeDetId.iy());
	}
	if ( (etaGapCode2!=0) || (phiGapCode2!=0) ) nClusNextToBoundary_custom++ ;
	//	std::cout << "eta/phi gap ? " << etaGapCode2 << " / " << phiGapCode2 << std::endl;
      }
    }
    if ( nClusNextToBoundary_custom > 0) isNearGapCustom=1;
    ele_nearGap_custom_with4060.push_back(isNearGapCustom);
    ////////
 
    //// near gap custom w/o 40 60
    int nClusNextToBoundary_custom_without4060=0;
    int isNearGapCustom_without4060=0;
    float   etaGapCode2_without4060, phiGapCode2_without4060 ;
    if (superClus.clusters().isAvailable()) {
      for (auto& bc : superClus.clusters() ) {
	DetId bcId = bc->hitsAndFractions()[0].first;
	int detector = bcId.subdetId();
	if ( detector==EcalBarrel ) {
	  EBDetId ebDetId(bcId);
	  auto gapCode2_without4060=[](int iEtaAbs2_without4060){
	    if(iEtaAbs2_without4060==25 || iEtaAbs2_without4060==45 || iEtaAbs2_without4060==65 || iEtaAbs2_without4060==85) return -1;//before gap
	    else if(iEtaAbs2_without4060==1 || iEtaAbs2_without4060==26 || iEtaAbs2_without4060==46 || iEtaAbs2_without4060==66) return 1;//after gap
	    else return 0; //no gap
	  };
	  etaGapCode2_without4060 = gapCode2_without4060(ebDetId.ietaAbs());
	  phiGapCode2_without4060 = ebDetId.iphi()%20 == 0 ? -1 : ebDetId.iphi()%20 ==1 ? 1 : 0;
	}else{
	  EEDetId eeDetId(bcId);
	  auto gapCode2_without4060=[](int iAbs2_without4060){
	    if(iAbs2_without4060==45 || iAbs2_without4060==50 || iAbs2_without4060==55) return -1;//before gap
	    else if(iAbs2_without4060==46 || iAbs2_without4060==51 || iAbs2_without4060==56 ) return 1;//after gap
	    else return 0; //no gap
	  };
	  etaGapCode2_without4060 = gapCode2_without4060(eeDetId.ix());
	  phiGapCode2_without4060 = gapCode2_without4060(eeDetId.iy());
	}
	if ( (etaGapCode2_without4060!=0) || (phiGapCode2_without4060!=0) ) nClusNextToBoundary_custom_without4060++ ;
      }
    }
    if ( nClusNextToBoundary_custom_without4060 > 0) isNearGapCustom_without4060=1;
    ele_nearGap_custom_without4060.push_back(isNearGapCustom_without4060);
    ////////


    eleSeedDet.push_back(seedId.det());
    eleSeedSubdet.push_back(seedId.subdetId());

    float var_eleSeedEta=-99;
    float var_eleSeedPhi=-99;

    DetId seed = (seedCluster.hitsAndFractions())[0].first;
    bool isBarrel = seed.subdetId() == EcalBarrel;
    const EcalRecHitCollection * rechits = (isBarrel?lazyTool.getEcalEBRecHitCollection():lazyTool.getEcalEERecHitCollection());
    EcalRecHitCollection::const_iterator theSeedHit = rechits->find(seed);
    if (theSeedHit != rechits->end()) {
      
      if ( (theSeedHit->id().rawId() != 0 ) ) {
	if (theCaloGeometry.product() != nullptr) {
	  const CaloSubdetectorGeometry *ecalgeo = theCaloGeometry->getSubdetectorGeometry(theSeedHit->id());
	  
	  if(ecalgeo->getGeometry(theSeedHit->id()) !=nullptr){
	    const GlobalPoint & ecalrechitPoint = (theCaloGeometry.product())->getPosition(theSeedHit->id());
	    var_eleSeedEta=ecalrechitPoint.eta();
	    var_eleSeedPhi=ecalrechitPoint.phi();
	  }
	}
	
      }
    }
  
    eleSeedEta.push_back(var_eleSeedEta);
    eleSeedPhi.push_back(var_eleSeedPhi);
    
    //     if( seedId.det() == DetId::Forward ) return; // i guess this is not needed for ntuplizing purpose
  
    int var_eleSeedIeta=-999;
    int var_eleSeedIphi=-999;
    int var_eleSeedRawID=-999;
    
    int  var_seedHcalIeta=-999;
    int  var_seedHcalIphi=-999;
    
    if ( seedId.det() == DetId::Ecal ) {
      if (seedId.subdetId() == EcalBarrel) {
	EBDetId ebId(seedId);
	var_eleSeedIeta=ebId.ieta();
	var_eleSeedIphi=ebId.iphi();
	var_eleSeedRawID=ebId.rawId();       
      }
      
      else if (seedId.subdetId() == EcalEndcap) {
	EEDetId eeId(seedId);
	var_eleSeedIeta=eeId.ix();
        var_eleSeedIphi=eeId.iy();
        var_eleSeedRawID=eeId.rawId();

      }

      //Get hold of the seed hcal behind ele seed. Then loop over hcal recHits.
      //Condition to save HCAL recHits is:
      //it's close to ele seed and recHit energy greater than noise.
      //taken from RecoEgamma/EgammaIsolationAlgos/src/EGHcalRecHitSelector.cc //
      
      CaloTowerDetId towerId(towerMap_->towerOf(seedId)); 
      int seedHcalIEta = towerId.ieta();
      int seedHcalIPhi = towerId.iphi();
      
      var_seedHcalIeta=seedHcalIEta;
      var_seedHcalIphi=seedHcalIPhi;

      for (auto& hcalrh : iEvent.get(hbhe_rechits_) ) {
	int dIEtaAbs = std::abs(calDIEta(seedHcalIEta, hcalrh.id().ieta()));
	int dIPhiAbs = std::abs(calDIPhi(seedHcalIPhi, hcalrh.id().iphi()));

	if ( (dIEtaAbs <= maxDIEta_) && (dIPhiAbs <= maxDIPhi_) &&  (hcalrh.energy()>getMinEnergyHCAL_(hcalrh.id()) ) ) {
	  // std::cout << "close to ele, save " << std::endl;
	  perEle_hcalRechitIeta.push_back(hcalrh.id().ieta());
	  perEle_hcalRechitIphi.push_back(hcalrh.id().iphi());
	  perEle_hcalRechitEnergy.push_back(hcalrh.energy());
	  perEle_hcalRechitAbsDIetaFromEleSeed.push_back(dIEtaAbs);
	  perEle_hcalRechitAbsDIphiFromEleSeed.push_back(dIPhiAbs);
	 
	  perEle_hcalRechitRawID.push_back(hcalrh.id().rawId());
	  perEle_hcalRechitDepth.push_back(hcalrh.id().depth());

	  float rechitEta=-99;
	  float rechitPhi=-99;
	  if ( (hcalrh.id().rawId() != 0 ) ) {
	    if (theCaloGeometry.product() != nullptr) {
	      const CaloSubdetectorGeometry *geo = theCaloGeometry->getSubdetectorGeometry(hcalrh.id());
	      if(geo->getGeometry(hcalrh.id()) !=nullptr){
		const GlobalPoint & rechitPoint = theCaloGeometry.product()->getPosition(hcalrh.id());
		
		rechitEta=rechitPoint.eta();
		rechitPhi=rechitPoint.phi();

		float myDR2= reco::deltaR2(ele.superCluster()->eta(), ele.superCluster()->phi(), rechitEta, rechitPhi) ;
		float myDR=sqrt(myDR2);

		float myDR2seed= reco::deltaR2(var_eleSeedEta, var_eleSeedPhi, rechitEta, rechitPhi) ;
		float myDRseed=sqrt(myDR2seed);

		/*		if ( (hcalrh.energy() > 6)  && ( myDR > 0.28 )  )  {
		  std::cout << "\nele_SC_eta " << ele.superCluster()->eta() << " ele_SC_phi " << ele.superCluster()->phi() << std::endl;
		  std::cout << "ele_seed_eta " << var_eleSeedEta << " ele_seed_phi " << var_eleSeedPhi  << std::endl;
		  std::cout << "ele gen pt " << this_eleGenPt << " GeV, ele gen energy " << this_eleGenE << " GeV" <<std::endl;
		  std::cout << "hcal rechit eta " << rechitEta << " hcal rechit phi " << rechitPhi << " hcal rechit energy " << hcalrh.energy() << " GeV" << std::endl;
		  std::cout << "ele in gap? " << ele.isGap() << std::endl;
		  std::cout << "dR(ele,hcal rechit) " << myDR << std::endl;
		  std::cout << "dR(ele seed,hcal rechit) " << myDRseed << std::endl;
		  std::cout << "run:lumi:event " << iEvent.id().run()<< ":" << iEvent.luminosityBlock() << ":" << iEvent.id().event() << std::endl ;
		  }*/	
		
	      }
	    }
	  }
	  perEle_hcalRechitEta.push_back(rechitEta);
	  perEle_hcalRechitPhi.push_back(rechitPhi);
	  
	}
	
      }
      
    }
  
    ele_trackFbrem.push_back(ele.trackFbrem());
    ele_superClusterFbrem.push_back(ele.superClusterFbrem());
    ele_numberOfBrems.push_back(ele.numberOfBrems());
    
    //    std::cout << "track_fbrem=" << ele.trackFbrem() << " sc_fbrem=" << ele.superClusterFbrem() << " nBrem="  <<  ele.numberOfBrems()  << std::endl;
    // std::cout << "classification " << ele.classificationVariables().ClassificationVariables << std::endl;
    int var_golden=0;
    int var_unknown=0;
    int var_gap=0;
    int var_badtrack=0;
    int var_showering=0;
    int var_bigbrem=0;

    if (ele.classification() == reco::GsfElectron::GOLDEN) {
      // std::cout << "golden ele!!!" << std::endl;
      var_golden=1;
    }

    if (ele.classification() == reco::GsfElectron::UNKNOWN) {
      // std::cout << "UNKNOWN ele!!!" << std::endl;
      var_unknown=1;
    }

    if (ele.classification() == reco::GsfElectron::BIGBREM) {
      //std::cout << "BIGBREM ele!!!" << std::endl;
      var_bigbrem=1;
    }

    if (ele.classification() == reco::GsfElectron::BADTRACK) {
      //std::cout << "BADTRACK ele!!!" << std::endl;
      var_badtrack=1;
    }

    if (ele.classification() == reco::GsfElectron::SHOWERING) {
      // std::cout << "SHOWERING ele!!!" << std::endl;
      var_showering=1;
    }

    if (ele.classification() == reco::GsfElectron::GAP) {
      // std::cout << "GAP ele!!!" << std::endl;
      var_gap=1;
    }

    ele_golden.push_back(var_golden);
    ele_unknown.push_back(var_unknown);
    ele_gap.push_back(var_gap);
    ele_badtrack.push_back(var_badtrack);
    ele_showering.push_back(var_showering);
    ele_bigbrem.push_back(var_bigbrem);
    scEn.push_back(superClus.energy());
    eleSCRawEn.push_back(superClus.rawEnergy());
    seedEn.push_back(seedCluster.energy());
    seedEnCorr.push_back(seedCluster.correctedEnergy());
    ecalEn.push_back(ele.ecalEnergy());
    cmssw_eleHoE.push_back(ele.hcalOverEcal());
    cmssw_eleHoE_tower.push_back(ele.hcalOverEcalBc());
    cmssw_eleHoE_full5x5.push_back(ele.full5x5_hcalOverEcal());
    eleSeedIeta.push_back(var_eleSeedIeta);
    eleSeedIphi.push_back(var_eleSeedIphi);
    eleSeedRawID.push_back(var_eleSeedRawID);
    seedHcalIeta.push_back(var_seedHcalIeta);
    seedHcalIphi.push_back(var_seedHcalIphi);
    hcalRechitIeta.push_back(perEle_hcalRechitIeta);
    hcalRechitIphi.push_back(perEle_hcalRechitIphi);
    hcalRechitEnergy.push_back(perEle_hcalRechitEnergy);
    hcalRechitAbsDIetaFromEleSeed.push_back(perEle_hcalRechitAbsDIetaFromEleSeed);
    hcalRechitAbsDIphiFromEleSeed.push_back(perEle_hcalRechitAbsDIphiFromEleSeed);
    hcalRechitRawID.push_back(perEle_hcalRechitRawID);
    hcalRechitDepth.push_back(perEle_hcalRechitDepth);
    hcalRechitEta.push_back(perEle_hcalRechitEta);
    hcalRechitPhi.push_back(perEle_hcalRechitPhi);
    
    
    
  }
   
  tree->Fill();
  
  
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
  ESHandle<SetupData> pSetup;
  iSetup.get<SetupRecord>().get(pSetup);
#endif
}

//doing some blatant copy paste from RecoEgamma/EgammaIsolationAlgos/src/EGHcalRecHitSelector.cc //

int HoEAnalyzer::calDIPhi(int iPhi1, int iPhi2) {
  int dPhi = iPhi1 - iPhi2;
  if (dPhi > 72 / 2)
    dPhi -= 72;
  else if (dPhi < -72 / 2)
    dPhi += 72;
  return dPhi;
}

//

int HoEAnalyzer::calDIEta(int iEta1, int iEta2) {
  int dEta = iEta1 - iEta2;
  if (iEta1 * iEta2 < 0) {  //-ve to +ve transistion and no crystal at zero
    if (dEta < 0)
      dEta++;
    else
      dEta--;
  }
  return dEta;
}

//HCAL thresholds from here https://cmssdt.cern.ch/lxr/source/RecoLocalCalo/CaloTowersCreator/python/calotowermaker_cfi.py?%21v=CMSSW_10_6_2
//Note: As far as I understood, 
//for 2018, HB threshold is 0.7, and for Run 3 it becomes 0.1 in depth1, 0.2 in depth2, 0.3 in other depths.
//In HE, 2018 and Run3 is same, and it is 0.1 in depth1, and 0.2 in other depths.

float HoEAnalyzer::getMinEnergyHCAL_(HcalDetId id) const {
  if ( (id.subdetId() == HcalBarrel)  ) {
    if ( (Run2_2018 == 1) )
      return 0.7;
    else if ( (Run2_2018 == 0) ) { //means Run3
      if (id.depth() == 1)
	return 0.1;
      else if (id.depth() == 2)
	return 0.2;
      else
	return 0.3;
    }
    else //neither 2018 , nor Run3, not supported
      return 9999.0;
  } 

  else if (id.subdetId() == HcalEndcap) {
    if (id.depth() == 1)
      return 0.1;
    else
      return 0.2;
  } else
    return 9999.0;
}


// ------------ method called once each job just before starting event loop  ------------
void
HoEAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
HoEAnalyzer::endJob()
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HoEAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);


}

//define this as a plug-in
DEFINE_FWK_MODULE(HoEAnalyzer);
