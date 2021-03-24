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
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "RecoEgamma/EgammaTools/interface/ECALGapCoordinates.h"

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

  std::vector<int>  ele_isEB; // true if particle is in ECAL Barrel
  std::vector<int>  ele_isEE; // true if particle is in ECAL Endcaps
  std::vector<int>  ele_isGap_cmssw; 
  std::vector<int>  ele_isGap_custom_with4060; 
  std::vector<int>  ele_genmatched;
  std::vector<float>  dR_recoEle_genEle;
  std::vector<float>  ptRecoEle_by_ptGenEle;
  std::vector<float>  eleSCRawEn;
  std::vector<float>  cmssw_eleHoE;
  std::vector<float>  cmssw_eleHoE_tower;
  std::vector<float>  eleScEta;
  std::vector<float>  eleScPhi;
  std::vector<float>  elePt;
  std::vector<float>  eleGenPt;
  std::vector<float>  eleGenEta;
  std::vector<float>  eleGenPhi;
  std::vector<float>  ele_full5x5_r9;
  std::vector<float>  elePhi;
  std::vector<float>  eleSigmaIEtaIEtaFull5x5;
  std::vector<int>    eleSeedIeta;
  std::vector<int>    eleSeedIphi;

  std::vector<int>  pho_isEB; // true if particle is in ECAL Barrel
  std::vector<int>  pho_isEE; // true if particle is in ECAL Endcaps
  std::vector<int>  pho_isGap_cmssw; 
  std::vector<int>  pho_isGap_custom_with4060; 
  std::vector<int>  pho_genmatched;
  std::vector<float>  dR_recoPho_genPho;
  std::vector<float>  ptRecoPho_by_ptGenPho;
  std::vector<float>  phoSCRawEn;
  std::vector<float>  cmssw_phoHoE;
  std::vector<float>  cmssw_phoHoE_tower;
  std::vector<float>  phoScEta;
  std::vector<float>  phoScPhi;
  std::vector<float>  phoPt;
  std::vector<float>  phoGenPt;
  std::vector<float>  phoGenEta;
  std::vector<float>  phoGenPhi;
  std::vector<float>  pho_full5x5_r9;
  std::vector<float>  phoPhi;
  std::vector<float>  phoSigmaIEtaIEtaFull5x5;
  std::vector<int>    phoSeedIeta;
  std::vector<int>    phoSeedIphi;

  std::vector<float>  puTrue;
  //for event-display
  std::vector<int> run_number;
  std::vector<int> lumi_number;
  std::vector<int> event_number;
  //

  std::vector<float> rho;

  
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
  //  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  edm::EDGetTokenT<edm::View<pat::Electron> > eleToken_;
  edm::EDGetTokenT<edm::View<pat::Photon> > phoToken_;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >     puCollection_;
  // edm::EDGetTokenT<HBHERecHitCollection> hbhe_rechits_;
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
  eleToken_(consumes<edm::View<pat::Electron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
  phoToken_(consumes<edm::View<pat::Photon> >(iConfig.getParameter<edm::InputTag>("photons"))),
  //  eleToken_(consumes<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
  puCollection_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupCollection"))),
  // hbhe_rechits_(consumes<HBHERecHitCollection>(iConfig.getParameter<edm::InputTag>("hbheInput"))),
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
  tree->Branch("ele_isGap_cmssw_",&ele_isGap_cmssw);
  tree->Branch("ele_isGap_custom_with4060_",&ele_isGap_custom_with4060);
  tree->Branch("ele_genmatched_",&ele_genmatched);
  tree->Branch("dR_recoEle_genEle_",&dR_recoEle_genEle);
  tree->Branch("ptRecoEle_by_ptGenEle_",&ptRecoEle_by_ptGenEle);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("cmssw_eleHoE_tower_",&cmssw_eleHoE_tower);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("eleScPhi_",&eleScPhi);
  tree->Branch("elePt_",&elePt);
  tree->Branch("eleGenPt_",&eleGenPt);
  tree->Branch("eleGenEta_",&eleGenEta);
  tree->Branch("eleGenPhi_",&eleGenPhi);
  tree->Branch("ele_full5x5_r9_",&ele_full5x5_r9);
  tree->Branch("elePhi_",&elePhi);
  tree->Branch("eleSigmaIEtaIEtaFull5x5_",&eleSigmaIEtaIEtaFull5x5);
  tree->Branch("eleSeedIeta_",&eleSeedIeta);
  tree->Branch("eleSeedIphi_",&eleSeedIphi);

  tree->Branch("pho_isEB_",&pho_isEB);
  tree->Branch("pho_isEE_",&pho_isEE);
  tree->Branch("pho_isGap_cmssw_",&pho_isGap_cmssw);
  tree->Branch("pho_isGap_custom_with4060_",&pho_isGap_custom_with4060);
  tree->Branch("pho_genmatched_",&pho_genmatched);
  tree->Branch("dR_recoPho_genPho_",&dR_recoPho_genPho);
  tree->Branch("ptRecoPho_by_ptGenPho_",&ptRecoPho_by_ptGenPho);
  tree->Branch("cmssw_phoHoE_",&cmssw_phoHoE);
  tree->Branch("cmssw_phoHoE_tower_",&cmssw_phoHoE_tower);
  tree->Branch("phoScEta_",&phoScEta);
  tree->Branch("phoScPhi_",&phoScPhi);
  tree->Branch("phoPt_",&phoPt);
  tree->Branch("phoGenPt_",&phoGenPt);
  tree->Branch("phoGenEta_",&phoGenEta);
  tree->Branch("phoGenPhi_",&phoGenPhi);
  tree->Branch("pho_full5x5_r9_",&pho_full5x5_r9);
  tree->Branch("phoPhi_",&phoPhi);
  tree->Branch("phoSigmaIEtaIEtaFull5x5_",&phoSigmaIEtaIEtaFull5x5);
  tree->Branch("phoSeedIeta_",&phoSeedIeta);
  tree->Branch("phoSeedIphi_",&phoSeedIphi);

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
  ele_isGap_cmssw.clear();
  ele_isGap_custom_with4060.clear();
  ele_genmatched.clear();
  ptRecoEle_by_ptGenEle.clear();
  dR_recoEle_genEle.clear();
  cmssw_eleHoE.clear();
  cmssw_eleHoE_tower.clear();
  eleScEta.clear();
  eleScPhi.clear();
  elePt.clear();
  eleGenPt.clear();
  eleGenEta.clear();
  eleGenPhi.clear();
  ele_full5x5_r9.clear();
  elePhi.clear();
  eleSigmaIEtaIEtaFull5x5.clear();
  eleSeedIeta.clear();
  eleSeedIphi.clear();

  pho_isEB.clear();
  pho_isEE.clear();
  pho_isGap_cmssw.clear();
  pho_isGap_custom_with4060.clear();
  pho_genmatched.clear();
  ptRecoPho_by_ptGenPho.clear();
  dR_recoPho_genPho.clear();
  cmssw_phoHoE.clear();
  cmssw_phoHoE_tower.clear();
  phoScEta.clear();
  phoScPhi.clear();
  phoPt.clear();
  phoGenPt.clear();
  phoGenEta.clear();
  phoGenPhi.clear();
  pho_full5x5_r9.clear();
  phoPhi.clear();
  phoSigmaIEtaIEtaFull5x5.clear();
  phoSeedIeta.clear();
  phoSeedIphi.clear();

  rho.clear();
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
  rho.push_back(*(rhoHandle.product()));

  edm::Handle<std::vector<PileupSummaryInfo> > genPileupHandle;
  iEvent.getByToken(puCollection_, genPileupHandle);
  
  if (genPileupHandle.isValid()) {
    for (std::vector<PileupSummaryInfo>::const_iterator pu = genPileupHandle->begin(); pu != genPileupHandle->end(); ++pu) {
      puTrue.push_back(pu->getTrueNumInteractions());
    }
  }
  
  //  edm::Handle<HBHERecHitCollection> hbheRechitsHandle;
  // iEvent.getByToken(hbhe_rechits_, hbheRechitsHandle);
  // iSetup.get<CaloGeometryRecord>().get(theCaloGeometry);
  // iSetup.get<CaloGeometryRecord>().get(towerMap_);

    
  edm::Handle<std::vector<reco::GenParticle> > genParticlesHandle;
  iEvent.getByToken(genParticlesCollection_, genParticlesHandle);
  
  
  for(const auto& ele : iEvent.get(eleToken_) ) {
    //    std::cout << "\n new electron ...\n" ;


    int genmatched=0;
    double min_dr=9999.9;
    double ptR=9999.9;
    double this_eleGenPt=-99;
    double this_eleGenEta=-99;
    double this_eleGenPhi=-99;
    //double this_eleGenE=-99;
   
    if (genParticlesHandle.isValid()) {
      //std::cout << "starting gen particle loop \n " ;
      for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	if ( (p->status()==1) &&  ((abs(p->pdgId())) == 11)  ) {
	  double this_dr=reco::deltaR(ele,*p);
	  if (this_dr<min_dr) {
	    min_dr=this_dr;
	    ptR=ele.pt()/p->pt();
	    this_eleGenPt=p->pt();
	    this_eleGenEta=p->eta();
	    this_eleGenPhi=p->phi();
	    //this_eleGenE=p->energy();
	  }
	}  
      }

    }
  
    if ( (min_dr<0.04) && (ptR>0.7) && (ptR<1.3) )  genmatched=1; // these cuts were decided looking at min_dr and ptR distributions.
    dR_recoEle_genEle.push_back(min_dr);
    ptRecoEle_by_ptGenEle.push_back(ptR);
    ele_genmatched.push_back(genmatched);
    
    eleScEta.push_back(ele.superCluster()->eta());
    eleScPhi.push_back(ele.superCluster()->phi());
    elePt.push_back(ele.pt());
    eleGenPt.push_back(this_eleGenPt);
    eleGenEta.push_back(this_eleGenEta);
    eleGenPhi.push_back(this_eleGenPhi);
    ele_full5x5_r9.push_back(ele.full5x5_r9());
    elePhi.push_back(ele.phi());
    eleSigmaIEtaIEtaFull5x5.push_back(ele.full5x5_sigmaIetaIeta());
  
    //gap, geometry etc
    ele_isEB.push_back(ele.isEB()) ;
    ele_isEE.push_back(ele.isEE()) ;
    ele_isGap_cmssw.push_back(ele.isGap());

    const reco::SuperCluster& superClus = *ele.superCluster();
    const reco::CaloCluster &seedCluster = *superClus.seed();

    DetId seedId = seedCluster.seed() ;

    //// Now I'm convinced that CMSSW isGap() is crap for EE. 
    //// Instead, tag the gap electrons by hardcoding the gaps ieta/iphi, ix/iy 
    //// Taking help from TrigNtup/src/EGRegTreeStruct.cc from Sam-Harper/usercode ////
   
    int isGapcustom=0;

    if ( seedCluster.seed().subdetId()==EcalBarrel ) {                                                                                                       
      EBDetId ebdetid(seedCluster.seed()); 
      int thisIEtaUnit=ebdetid.ietaAbs();
      if ( std::any_of(barrelGapIEta.begin(), barrelGapIEta.end(), [thisIEtaUnit](int gapUnit){return thisIEtaUnit==gapUnit;}) == true) {
	isGapcustom = 1;
      }
      if ( (ebdetid.iphi()%barrelGapIphiStepSize==0) ||  
	   (ebdetid.iphi()%barrelGapIphiStepSize==1) ) {
	isGapcustom = 1;
      }
    } else {
      EEDetId eedetid(seedCluster.seed());
      int thisIxUnit=eedetid.ix();
      if ( std::any_of(endcapGapIxIy.begin(), endcapGapIxIy.end(), [thisIxUnit](int gapUnit){return thisIxUnit==gapUnit;}) == true) {
	isGapcustom = 1;
      }
      int thisIyUnit=eedetid.iy();
      if ( std::any_of(endcapGapIxIy.begin(), endcapGapIxIy.end(), [thisIyUnit](int gapUnit){return thisIyUnit==gapUnit;}) == true) {
	isGapcustom = 1;
      }
    } 
    ele_isGap_custom_with4060.push_back(isGapcustom);

    int var_eleSeedIeta=-999;
    int var_eleSeedIphi=-999;
    
    if ( seedId.det() == DetId::Ecal ) {
      if (seedId.subdetId() == EcalBarrel) {
	EBDetId ebId(seedId);
	var_eleSeedIeta=ebId.ieta();
	var_eleSeedIphi=ebId.iphi();
      }
      
      else if (seedId.subdetId() == EcalEndcap) {
	EEDetId eeId(seedId);
	var_eleSeedIeta=eeId.ix();
        var_eleSeedIphi=eeId.iy();
      }
    }
    
  
    eleSCRawEn.push_back(superClus.rawEnergy());
    cmssw_eleHoE.push_back(ele.hcalOverEcal());
    cmssw_eleHoE_tower.push_back(ele.hcalOverEcalBc());
    eleSeedIeta.push_back(var_eleSeedIeta);
    eleSeedIphi.push_back(var_eleSeedIphi);
     
     
  }

  ////// photon_loop
  for(const auto& pho : iEvent.get(phoToken_) ) {
    //if (pho.pt() < 10.)   
    //    std::cout << "pho_pt " << pho.pt() << "  pho_pt_fast " << pho.superCluster().energy() * std::sqrt(v.perp2() / v.mag2());  << std::endl;

    int genmatched=0;
    double min_dr=9999.9;
    double ptR=9999.9;
    double this_phoGenPt=-99;
    double this_phoGenEta=-99;
    double this_phoGenPhi=-99;
     
    if (genParticlesHandle.isValid()) {
      //std::cout << "starting gen particle loop \n " ;
      for (std::vector<reco::GenParticle>::const_iterator ip = genParticlesHandle->begin(); ip != genParticlesHandle->end(); ++ip) {
	const reco::Candidate *p = (const reco::Candidate*)&(*ip);
	if ( (p->status()==1) &&  ((abs(p->pdgId())) == 22)  ) {
	  double this_dr=reco::deltaR(pho,*p);
	  if (this_dr<min_dr) {
	    min_dr=this_dr;
	    ptR=pho.pt()/p->pt();
	    this_phoGenPt=p->pt();
	    this_phoGenEta=p->eta();
	    this_phoGenPhi=p->phi();
	    //this_phoGenE=p->energy();
	  }
	}  
      }
    }
  
    if ( (min_dr<0.04) && (ptR>0.7) && (ptR<1.3) )  genmatched=1; // these cuts were decided looking at min_dr and ptR distributions.
    dR_recoPho_genPho.push_back(min_dr);
    ptRecoPho_by_ptGenPho.push_back(ptR);
    //  std::cout << "genmatched = " << genmatched <<  " min_dr " << min_dr << " ptR " << ptR   <<  std::endl;    
    pho_genmatched.push_back(genmatched);

    phoScEta.push_back(pho.superCluster()->eta());
    phoScPhi.push_back(pho.superCluster()->phi());
    phoPt.push_back(pho.pt());
    phoGenPt.push_back(this_phoGenPt);
    phoGenEta.push_back(this_phoGenEta);
    phoGenPhi.push_back(this_phoGenPhi);
    pho_full5x5_r9.push_back(pho.full5x5_r9());
    phoPhi.push_back(pho.phi());
    phoSigmaIEtaIEtaFull5x5.push_back(pho.full5x5_sigmaIetaIeta());
  
    //gap, geometry etc
    pho_isEB.push_back(pho.isEB()) ;
    pho_isEE.push_back(pho.isEE()) ;

    int phoIsInGap = 0;
    if (pho.isEBGap() || pho.isEEGap() || pho.isEBEEGap() ) {
      phoIsInGap = 1;
    }
    pho_isGap_cmssw.push_back(phoIsInGap);

    const reco::SuperCluster& superClus = *pho.superCluster();
    const reco::CaloCluster &seedCluster = *superClus.seed();

    DetId seedId = seedCluster.seed() ;

    int isGapcustom=0;

    if ( seedCluster.seed().subdetId()==EcalBarrel ) {                                                                                                       
      EBDetId ebdetid(seedCluster.seed()); 
      int thisIEtaUnit=ebdetid.ietaAbs();
      if ( std::any_of(barrelGapIEta.begin(), barrelGapIEta.end(), [thisIEtaUnit](int gapUnit){return thisIEtaUnit==gapUnit;}) == true) {
	isGapcustom = 1;
      }
      if ( (ebdetid.iphi()%barrelGapIphiStepSize==0) ||  
	   (ebdetid.iphi()%barrelGapIphiStepSize==1) ) {
	isGapcustom = 1;
      }
    } else {
      EEDetId eedetid(seedCluster.seed());
      int thisIxUnit=eedetid.ix();
      if ( std::any_of(endcapGapIxIy.begin(), endcapGapIxIy.end(), [thisIxUnit](int gapUnit){return thisIxUnit==gapUnit;}) == true) {
	isGapcustom = 1;
      }
      int thisIyUnit=eedetid.iy();
      if ( std::any_of(endcapGapIxIy.begin(), endcapGapIxIy.end(), [thisIyUnit](int gapUnit){return thisIyUnit==gapUnit;}) == true) {
	isGapcustom = 1;
      }
    } 
    pho_isGap_custom_with4060.push_back(isGapcustom);

    int var_phoSeedIeta=-999;
    int var_phoSeedIphi=-999;

    if ( seedId.det() == DetId::Ecal ) {
      if (seedId.subdetId() == EcalBarrel) {
	EBDetId ebId(seedId);
	var_phoSeedIeta=ebId.ieta();
	var_phoSeedIphi=ebId.iphi();
	//var_phoSeedRawID=ebId.rawId();       
      }
      
      else if (seedId.subdetId() == EcalEndcap) {
	EEDetId eeId(seedId);
	var_phoSeedIeta=eeId.ix();
        var_phoSeedIphi=eeId.iy();
        //var_phoSeedRawID=eeId.rawId();

      }

    }
  
  
    phoSCRawEn.push_back(superClus.rawEnergy());
    cmssw_phoHoE.push_back(pho.hadronicOverEm());
    cmssw_phoHoE_tower.push_back(pho.hadTowOverEm());
    phoSeedIeta.push_back(var_phoSeedIeta);
    phoSeedIphi.push_back(var_phoSeedIphi);

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
