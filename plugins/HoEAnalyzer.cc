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
  std::vector<int>  ele_genmatched;
  std::vector<float>  scEn;
  std::vector<float>  dR_recoEle_genEle;
  std::vector<float>  ptRecoEle_by_ptGenEle;
  std::vector<float>  eleSCRawEn;
  std::vector<float>  ecalEn;
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
  std::vector<float>  eleSigmaIPhiIPhiFull5x5;
  //
  std::vector<float>  elePFNeuIso;
  std::vector<float>  elePFChIso;
  std::vector<float>  elePFPhoIso;
  std::vector<float>  ele_hcalPFClusterIso;
  std::vector<float>  ele_dr03HcalTowerSumEt;

  std::vector<float>  puTrue;
  std::vector<int> run_number;
  std::vector<int> lumi_number;
  std::vector<int> event_number;
  std::vector<float> rho;
  std::vector<float>  ele_etaWidth;
  std::vector<float>  ele_phiWidth;
  std::vector<float>  ele_closestCtfTrackNLayers;
  std::vector<float>  ele_closestCtfTrackNormChi2;
  std::vector<float>  ele_1mE1x5oE5x5;
  std::vector<float>  ele_fbrem;
  std::vector<float>  ele_missingHit;
  std::vector<float>  ele_psEorawE;
  std::vector<float>  ele_1oEm1op;
  std::vector<float>  ele_eSCoPout;
  std::vector<float>  ele_eSCoP;
  std::vector<float>  ele_convVtxFitProb;
  std::vector<float>  ele_gsfTrackChi2;
  std::vector<float>  ele_nHit;
  std::vector<float>  ele_deltaEtaSuperClusterTrackAtVtx;
  std::vector<float>  ele_deltaPhiSuperClusterTrackAtVtx;
  std::vector<float>  ele_deltaEtaSeedClusterTrackAtCalo;

  ///H/E
  std::vector<float>  my_eleH;
  std::vector<float>  my_eleHoEsc;
  std::vector<float>  my_eleHoEecal;
  std::vector<float>  my_eleHoEraw;

  std::vector<float>  my_eleHd1;
  std::vector<float>  my_eleHd1oEsc;
  std::vector<float>  my_eleHd1oEecal;
  std::vector<float>  my_eleHd1oEraw;

  std::vector<float>  my_eleHd2;
  std::vector<float>  my_eleHd2oEsc;
  std::vector<float>  my_eleHd2oEecal;
  std::vector<float>  my_eleHd2oEraw;

  std::vector<float>  my_eleHd3;
  std::vector<float>  my_eleHd3oEsc;
  std::vector<float>  my_eleHd3oEecal;
  std::vector<float>  my_eleHd3oEraw;

  std::vector<float>  my_eleHd4;
  std::vector<float>  my_eleHd4oEsc;
  std::vector<float>  my_eleHd4oEecal;
  std::vector<float>  my_eleHd4oEraw;

  std::vector<float>  my_eleHd5;
  std::vector<float>  my_eleHd5oEsc;
  std::vector<float>  my_eleHd5oEecal;
  std::vector<float>  my_eleHd5oEraw;

  std::vector<float>  my_eleHd6;
  std::vector<float>  my_eleHd6oEsc;
  std::vector<float>  my_eleHd6oEecal;
  std::vector<float>  my_eleHd6oEraw;

  std::vector<float>  my_eleHd7;
  std::vector<float>  my_eleHd7oEsc;
  std::vector<float>  my_eleHd7oEecal;
  std::vector<float>  my_eleHd7oEraw;

  std::vector<float>  my_eleHd8;
  std::vector<float>  my_eleHd8oEsc;
  std::vector<float>  my_eleHd8oEecal;
  std::vector<float>  my_eleHd8oEraw;

  
private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  static int calDIEta(int iEta1, int iEta2);
  static int calDIPhi(int iPhi1, int iPhi2);
  float getMinEnergyHCAL_(HcalDetId id) const;
  

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
  tree->Branch("ele_genmatched_",&ele_genmatched);
  tree->Branch("dR_recoEle_genEle_",&dR_recoEle_genEle);
  tree->Branch("ptRecoEle_by_ptGenEle_",&ptRecoEle_by_ptGenEle);
  tree->Branch("scEn_",&scEn);
  tree->Branch("eleSCRawEn_",&eleSCRawEn);
  tree->Branch("ecalEn_",&ecalEn);
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
  tree->Branch("eleSigmaIPhiIPhiFull5x5_",&eleSigmaIPhiIPhiFull5x5);

  tree->Branch("elePFNeuIso_",&elePFNeuIso);
  tree->Branch("elePFChIso_",&elePFChIso);
  tree->Branch("elePFPhoIso_",&elePFPhoIso);
  tree->Branch("ele_hcalPFClusterIso_",&ele_hcalPFClusterIso);
  tree->Branch("ele_dr03HcalTowerSumEt_",&ele_dr03HcalTowerSumEt);
  tree->Branch("puTrue_", &puTrue);
  tree->Branch("rho_", &rho);
  tree->Branch("run_number_", &run_number);
  tree->Branch("lumi_number_", &lumi_number);
  tree->Branch("event_number_", &event_number);
  tree->Branch("ele_1mE1x5oE5x5_",&ele_1mE1x5oE5x5);
  tree->Branch("ele_etaWidth_",&ele_etaWidth);
  tree->Branch("ele_phiWidth_",&ele_phiWidth);
  tree->Branch("ele_closestCtfTrackNLayers_",&ele_closestCtfTrackNLayers);
  tree->Branch("ele_closestCtfTrackNormChi2_",&ele_closestCtfTrackNormChi2);
  tree->Branch("ele_fbrem_",&ele_fbrem);
  tree->Branch("ele_missingHit_",&ele_missingHit);
  tree->Branch("ele_psEorawE_",&ele_psEorawE);
  tree->Branch("ele_1oEm1op_",&ele_1oEm1op);
  tree->Branch("ele_eSCoP_",&ele_eSCoP);
  tree->Branch("ele_eSCoPout_",&ele_eSCoPout);
  tree->Branch("ele_convVtxFitProb_",&ele_convVtxFitProb);
  tree->Branch("ele_gsfTrackChi2_",&ele_gsfTrackChi2);
  tree->Branch("ele_nHit_",&ele_nHit);
  tree->Branch("ele_deltaEtaSuperClusterTrackAtVtx_",&ele_deltaEtaSuperClusterTrackAtVtx);
  tree->Branch("ele_deltaPhiSuperClusterTrackAtVtx_",&ele_deltaPhiSuperClusterTrackAtVtx);
  tree->Branch("ele_deltaEtaSeedClusterTrackAtCalo_",&ele_deltaEtaSeedClusterTrackAtCalo);

  //H/E
  tree->Branch("my_eleH_", &my_eleH);
  tree->Branch("my_eleHoEsc_", &my_eleHoEsc);
  tree->Branch("my_eleHoEecal_", &my_eleHoEecal);
  tree->Branch("my_eleHoEraw_", &my_eleHoEraw);

  tree->Branch("my_eleHd1_", &my_eleHd1);
  tree->Branch("my_eleHd1oEsc_", &my_eleHd1oEsc);
  tree->Branch("my_eleHd1oEecal_", &my_eleHd1oEecal);
  tree->Branch("my_eleHd1oEraw_", &my_eleHd1oEraw);

  tree->Branch("my_eleHd2_", &my_eleHd2);
  tree->Branch("my_eleHd2oEsc_", &my_eleHd2oEsc);
  tree->Branch("my_eleHd2oEecal_", &my_eleHd2oEecal);
  tree->Branch("my_eleHd2oEraw_", &my_eleHd2oEraw);

  tree->Branch("my_eleHd3_", &my_eleHd3);
  tree->Branch("my_eleHd3oEsc_", &my_eleHd3oEsc);
  tree->Branch("my_eleHd3oEecal_", &my_eleHd3oEecal);
  tree->Branch("my_eleHd3oEraw_", &my_eleHd3oEraw);

  tree->Branch("my_eleHd4_", &my_eleHd4);
  tree->Branch("my_eleHd4oEsc_", &my_eleHd4oEsc);
  tree->Branch("my_eleHd4oEecal_", &my_eleHd4oEecal);
  tree->Branch("my_eleHd4oEraw_", &my_eleHd4oEraw);

  tree->Branch("my_eleHd5_", &my_eleHd5);
  tree->Branch("my_eleHd5oEsc_", &my_eleHd5oEsc);
  tree->Branch("my_eleHd5oEecal_", &my_eleHd5oEecal);
  tree->Branch("my_eleHd5oEraw_", &my_eleHd5oEraw);

  tree->Branch("my_eleHd6_", &my_eleHd6);
  tree->Branch("my_eleHd6oEsc_", &my_eleHd6oEsc);
  tree->Branch("my_eleHd6oEecal_", &my_eleHd6oEecal);
  tree->Branch("my_eleHd6oEraw_", &my_eleHd6oEraw);

  tree->Branch("my_eleHd7_", &my_eleHd7);
  tree->Branch("my_eleHd7oEsc_", &my_eleHd7oEsc);
  tree->Branch("my_eleHd7oEecal_", &my_eleHd7oEecal);
  tree->Branch("my_eleHd7oEraw_", &my_eleHd7oEraw);

  tree->Branch("my_eleHd8_", &my_eleHd8);
  tree->Branch("my_eleHd8oEsc_", &my_eleHd8oEsc);
  tree->Branch("my_eleHd8oEecal_", &my_eleHd8oEecal);
  tree->Branch("my_eleHd8oEraw_", &my_eleHd8oEraw);


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
  ele_genmatched.clear();
  ptRecoEle_by_ptGenEle.clear();
  dR_recoEle_genEle.clear();
  scEn.clear();
  eleSCRawEn.clear();
  ecalEn.clear();
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
  eleSigmaIPhiIPhiFull5x5.clear();
  elePFNeuIso.clear();
  elePFChIso.clear();
  elePFPhoIso.clear();
  ele_hcalPFClusterIso.clear();
  ele_dr03HcalTowerSumEt.clear();
  puTrue.clear();
  run_number.clear();
  lumi_number.clear(); 
  event_number.clear();
  run_number.push_back(iEvent.id().run());
  lumi_number.push_back(iEvent.luminosityBlock()); 
  event_number.push_back(iEvent.id().event());
  ele_1mE1x5oE5x5.clear();
  ele_etaWidth.clear();
  ele_phiWidth.clear();
  ele_closestCtfTrackNLayers.clear();
  ele_closestCtfTrackNormChi2.clear();
  ele_fbrem.clear();
  ele_missingHit.clear();
  ele_psEorawE.clear();
  ele_1oEm1op.clear();
  ele_eSCoP.clear();
  ele_eSCoPout.clear();
  ele_convVtxFitProb.clear();
  ele_gsfTrackChi2.clear();
  ele_nHit.clear();
  ele_deltaEtaSuperClusterTrackAtVtx.clear();
  ele_deltaPhiSuperClusterTrackAtVtx.clear();
  ele_deltaEtaSeedClusterTrackAtCalo.clear();

  my_eleH.clear();
  my_eleHoEsc.clear();
  my_eleHoEecal.clear();
  my_eleHoEraw.clear();

  my_eleHd1.clear();
  my_eleHd1oEsc.clear();
  my_eleHd1oEecal.clear();
  my_eleHd1oEraw.clear();

  my_eleHd2.clear();
  my_eleHd2oEsc.clear();
  my_eleHd2oEecal.clear();
  my_eleHd2oEraw.clear();

  my_eleHd3.clear();
  my_eleHd3oEsc.clear();
  my_eleHd3oEecal.clear();
  my_eleHd3oEraw.clear();

  my_eleHd4.clear();
  my_eleHd4oEsc.clear();
  my_eleHd4oEecal.clear();
  my_eleHd4oEraw.clear();

  my_eleHd5.clear();
  my_eleHd5oEsc.clear();
  my_eleHd5oEecal.clear();
  my_eleHd5oEraw.clear();

  my_eleHd6.clear();
  my_eleHd6oEsc.clear();
  my_eleHd6oEecal.clear();
  my_eleHd6oEraw.clear();

  my_eleHd7.clear();
  my_eleHd7oEsc.clear();
  my_eleHd7oEecal.clear();
  my_eleHd7oEraw.clear();

  my_eleHd8.clear();
  my_eleHd8oEsc.clear();
  my_eleHd8oEecal.clear();
  my_eleHd8oEraw.clear();

  //  std::cout << "run/lumi/event " << run_number << "/" << lumi_number << "/" << event_number << std::endl;

  edm::Handle<double> rhoHandle;
  iEvent.getByToken(rhoLabel_, rhoHandle);
  float myrho = *(rhoHandle.product());

  edm::Handle<std::vector<PileupSummaryInfo> > genPileupHandle;
  iEvent.getByToken(puCollection_, genPileupHandle);

  float mypu=0;

  if (genPileupHandle.isValid()) {
    for (std::vector<PileupSummaryInfo>::const_iterator pu = genPileupHandle->begin(); pu != genPileupHandle->end(); ++pu) {
      mypu=pu->getTrueNumInteractions();
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

    rho.push_back(myrho);
    puTrue.push_back(mypu);

    int genmatched=0;
    double min_dr=9999.9;
    double ptR=9999.9;
    double this_eleGenPt=-99;
    //double this_eleGenE=-99;
   
    if (genParticlesHandle.isValid()) {
      for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	if ( (p->status()==1) &&  ((abs(p->pdgId())) == 11)  ) {
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
    eleGenPt.push_back(this_eleGenPt);

    //  std::cout << " genmatched = " << genmatched  << ", eleGenPt = " << this_eleGenPt << " recoPt=" << ele.pt() <<  std::endl;   

    //    EcalClusterLazyTools       lazyTool    (iEvent, iSetup, ebReducedRecHitCollection_, eeReducedRecHitCollection_, esReducedRecHitCollection_);
    const reco::SuperCluster& superClus = *ele.superCluster();
    //    const reco::CaloCluster &seedCluster = *superClus.seed();

    float hcalE = 0;
    float hcalEd1 = 0;
    float hcalEd2 = 0;
    float hcalEd3 = 0;
    float hcalEd4 = 0;
    float hcalEd5 = 0;
    float hcalEd6 = 0;
    float hcalEd7 = 0;
    float hcalEd8 = 0;
    
    for (auto& hcalrh : iEvent.get(hbhe_rechits_) ) {
      if ( hcalrh.energy()>getMinEnergyHCAL_(hcalrh.id()) ) {
	if ( (hcalrh.id().rawId() != 0 ) ) {
	  if (theCaloGeometry.product() != nullptr) {
	    const CaloSubdetectorGeometry *geo = theCaloGeometry->getSubdetectorGeometry(hcalrh.id());
	    if(geo->getGeometry(hcalrh.id()) !=nullptr){
	      const GlobalPoint & rechitPoint = theCaloGeometry.product()->getPosition(hcalrh.id());
	      
	      float rechitEta=rechitPoint.eta();
	      float rechitPhi=rechitPoint.phi();
	      
	      float myDR2= reco::deltaR2(ele.superCluster()->eta(), ele.superCluster()->phi(), rechitEta, rechitPhi) ;
	      float myDR=sqrt(myDR2);
	      
	      int mydepth = hcalrh.id().depth() ;
	      
	      if (myDR < 0.15) {
		hcalE = hcalE+hcalrh.energy();
		
		//depth 1
		if (mydepth==1) { 
		  hcalEd1 = hcalEd1+hcalrh.energy();
		}
		//depth 2
		else if (mydepth==2) { 
		  hcalEd2 = hcalEd2+hcalrh.energy();
		}
		//depth 3
		else if (mydepth==3) {
		  hcalEd3 = hcalEd3+hcalrh.energy();
		}
		//depth 4
		else if (mydepth==4) {
		  hcalEd4 = hcalEd4+hcalrh.energy();
		}
		//depth 5
		else if (mydepth==5) {
		  hcalEd5 = hcalEd5+hcalrh.energy();
		}
		//depth 6
		else if (mydepth==6) {
		  hcalEd6 = hcalEd6+hcalrh.energy();
		}
		//depth 7
		else if (mydepth==7) {
		  hcalEd7 = hcalEd7+hcalrh.energy();
		}
		//depth 8
		else if (mydepth==8) {
		  hcalEd8 = hcalEd8+hcalrh.energy();
		}
	      } // dR=0.15
	    }
	  }
	}
      }
    } //loop on hcal rechits end here
    
    my_eleH.push_back(hcalE);
    my_eleHoEsc.push_back(hcalE/superClus.energy());
    my_eleHoEecal.push_back(hcalE/ele.ecalEnergy());
    my_eleHoEraw.push_back(hcalE/superClus.rawEnergy());
    
    my_eleHd1.push_back(hcalEd1);
    my_eleHd1oEsc.push_back(hcalEd1/superClus.energy());
    my_eleHd1oEecal.push_back(hcalEd1/ele.ecalEnergy());
    my_eleHd1oEraw.push_back(hcalEd1/superClus.rawEnergy());
    
    my_eleHd2.push_back(hcalEd2);
    my_eleHd2oEsc.push_back(hcalEd2/superClus.energy());
    my_eleHd2oEecal.push_back(hcalEd2/ele.ecalEnergy());
    my_eleHd2oEraw.push_back(hcalEd2/superClus.rawEnergy());
    
    my_eleHd3.push_back(hcalEd3);
    my_eleHd3oEsc.push_back(hcalEd3/superClus.energy());
    my_eleHd3oEecal.push_back(hcalEd3/ele.ecalEnergy());
    my_eleHd3oEraw.push_back(hcalEd3/superClus.rawEnergy());
    
    my_eleHd4.push_back(hcalEd4);
    my_eleHd4oEsc.push_back(hcalEd4/superClus.energy());
    my_eleHd4oEecal.push_back(hcalEd4/ele.ecalEnergy());
    my_eleHd4oEraw.push_back(hcalEd4/superClus.rawEnergy());
    
    my_eleHd5.push_back(hcalEd5);
    my_eleHd5oEsc.push_back(hcalEd5/superClus.energy());
    my_eleHd5oEecal.push_back(hcalEd5/ele.ecalEnergy());
    my_eleHd5oEraw.push_back(hcalEd5/superClus.rawEnergy());
    
    my_eleHd6.push_back(hcalEd6);
    my_eleHd6oEsc.push_back(hcalEd6/superClus.energy());
    my_eleHd6oEecal.push_back(hcalEd6/ele.ecalEnergy());
    my_eleHd6oEraw.push_back(hcalEd6/superClus.rawEnergy());
    
    my_eleHd7.push_back(hcalEd7);
    my_eleHd7oEsc.push_back(hcalEd7/superClus.energy());
    my_eleHd7oEecal.push_back(hcalEd7/ele.ecalEnergy());
    my_eleHd7oEraw.push_back(hcalEd7/superClus.rawEnergy());
    
    my_eleHd8.push_back(hcalEd8);
    my_eleHd8oEsc.push_back(hcalEd8/superClus.energy());
    my_eleHd8oEecal.push_back(hcalEd8/ele.ecalEnergy());
    my_eleHd8oEraw.push_back(hcalEd8/superClus.rawEnergy());
    
    ele_isEB.push_back(ele.isEB()) ;
    ele_isEE.push_back(ele.isEE()) ;
    scEn.push_back(superClus.energy());
    eleSCRawEn.push_back(superClus.rawEnergy());
    ecalEn.push_back(ele.ecalEnergy());
    cmssw_eleHoE.push_back(ele.hcalOverEcal());
    cmssw_eleHoE_tower.push_back(ele.hcalOverEcalBc());
    cmssw_eleHoE_full5x5.push_back(ele.full5x5_hcalOverEcal());
    eleScEta.push_back(ele.superCluster()->eta());
    eleScPhi.push_back(ele.superCluster()->phi());
    elePt.push_back(ele.pt());
    ele_full5x5_r9.push_back(ele.full5x5_r9());
    elePhi.push_back(ele.phi());
    eleSigmaIEtaIEtaFull5x5.push_back(ele.full5x5_sigmaIetaIeta());
    eleSigmaIPhiIPhiFull5x5.push_back(ele.full5x5_sigmaIphiIphi());
    ele_1mE1x5oE5x5.push_back(1-(ele.full5x5_e1x5()/ele.full5x5_e5x5()));      
    ele_etaWidth.push_back(ele.superCluster()->etaWidth());
    ele_phiWidth.push_back(ele.superCluster()->phiWidth());
    
    ele_closestCtfTrackNLayers.push_back(ele.closestCtfTrackNLayers());
    ele_closestCtfTrackNormChi2.push_back(ele.closestCtfTrackNormChi2());
    ele_deltaEtaSuperClusterTrackAtVtx.push_back(ele.deltaEtaSuperClusterTrackAtVtx());
    ele_deltaPhiSuperClusterTrackAtVtx.push_back(ele.deltaPhiSuperClusterTrackAtVtx());
    ele_deltaEtaSeedClusterTrackAtCalo.push_back(ele.deltaEtaSeedClusterTrackAtCalo());
    ele_fbrem.push_back(ele.fbrem());
    ele_missingHit.push_back(ele.gsfTrack()->hitPattern().numberOfLostHits(reco::HitPattern::MISSING_INNER_HITS));
    ele_nHit.push_back(ele.gsfTrack()->hitPattern().trackerLayersWithMeasurement());
    ele_gsfTrackChi2.push_back(ele.gsfTrack()->normalizedChi2());
    ele_convVtxFitProb.push_back(ele.convVtxFitProb());
    ele_eSCoP.push_back(ele.eSuperClusterOverP());
    ele_eSCoPout.push_back(ele.eEleClusterOverPout());
    ele_1oEm1op.push_back( (1.0/ele.ecalEnergy()) - (1.0/ele.trackMomentumAtVtx().r()) );
    ele_psEorawE.push_back( ele.superCluster()->preshowerEnergy()/ele.superCluster()->rawEnergy() );
    
    reco::GsfElectron::PflowIsolationVariables pfIso = ele.pfIsolationVariables();
    elePFNeuIso.push_back(pfIso.sumNeutralHadronEt);
    elePFChIso.push_back(pfIso.sumChargedHadronPt);
    elePFPhoIso.push_back(pfIso.sumPhotonEt);
    ele_hcalPFClusterIso.push_back(ele.hcalPFClusterIso());
    ele_dr03HcalTowerSumEt.push_back(ele.dr03HcalTowerSumEt());
    
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
