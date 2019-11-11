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
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"
#include "RecoEgamma/EgammaElectronAlgos/interface/ElectronHcalHelper.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.


//using reco::TrackCollection;

class HoEAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
public:
  explicit HoEAnalyzer(const edm::ParameterSet&);
  ~HoEAnalyzer();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  edm::Service<TFileService> fs;
  TTree   *tree = fs->make<TTree>("EventTree", "EventData");
  
  std::vector<float>  HadEnergy_depth1;
  std::vector<float>  HadEnergy_depth2;
  std::vector<float>  scEn;
  std::vector<float>  ecalEn;
  std::vector<float>  seedEn;
  std::vector<float>  seedEnCorr;
  std::vector<float>  cmssw_eleHoE;
  std::vector<float>  cmssw_eleHoE_full5x5;
  std::vector<float>  my_eleHoE_default;
  std::vector<float>  eleScEta;
  std::vector<float>  puTrue;
  
private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  
  // ----------member data ---------------------------
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  //  edm::EDGetTokenT<CaloTowerCollection> caloTowersTag_;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >     puCollection_;
  edm::EDGetTokenT<HBHERecHitCollection> hbhe_rechits_;
  edm::ESHandle<CaloGeometry> theCaloGeometry;
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
  eleToken_(consumes<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("electrons"))),
  //caloTowersTag_(consumes<CaloTowerCollection>(iConfig.getUntrackedParameter<edm::InputTag>("caloTowersTag"))),
  puCollection_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupCollection"))),
  hbhe_rechits_(consumes<HBHERecHitCollection>(iConfig.getParameter<edm::InputTag>("hbheInput")))

{
   //now do what ever initialization is needed

  tree->Branch("HadEnergy_depth1_",&HadEnergy_depth1);
  tree->Branch("HadEnergy_depth2_",&HadEnergy_depth2);
  tree->Branch("scEn_",&scEn);
  tree->Branch("ecalEn_",&ecalEn);
  tree->Branch("seedEn_",&seedEn);
  tree->Branch("seedEnCorr_",&seedEnCorr);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("cmssw_eleHoE_full5x5_",&cmssw_eleHoE_full5x5);
  tree->Branch("my_eleHoE_default_",&my_eleHoE_default);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("puTrue_", &puTrue);

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
  using namespace edm;

  HadEnergy_depth1.clear();
  HadEnergy_depth2.clear();
  scEn.clear();
  ecalEn.clear();
  seedEn.clear();
  seedEnCorr.clear();
  cmssw_eleHoE.clear();
  cmssw_eleHoE_full5x5.clear();
  my_eleHoE_default.clear();
  eleScEta.clear();
  puTrue.clear();

   edm::Handle<std::vector<PileupSummaryInfo> > genPileupHandle;
   iEvent.getByToken(puCollection_, genPileupHandle);
  
   if (genPileupHandle.isValid()) {
     for (std::vector<PileupSummaryInfo>::const_iterator pu = genPileupHandle->begin(); pu != genPileupHandle->end(); ++pu) {
       puTrue.push_back(pu->getTrueNumInteractions());
     }
   }

   for(const auto& ele : iEvent.get(eleToken_) ) {

     eleScEta.push_back(ele.superCluster()->eta());
     
     std::cout << "\n New Ele, eta= " << ele.superCluster()->eta() << std::endl;
     const reco::SuperCluster& superClus = *ele.superCluster();
     const reco::CaloCluster &seedCluster = *superClus.seed();
     
     //   edm::Handle<CaloTowerCollection> caloTowerHandle;
     // iEvent.getByToken(caloTowersTag_,caloTowerHandle);
     
     edm::Handle<HBHERecHitCollection> hbheRechitsHandle;
     iEvent.getByToken(hbhe_rechits_, hbheRechitsHandle);
     
     iSetup.get<CaloGeometryRecord>().get(theCaloGeometry);

     //calculate default H/E using recHit (NOT caloTower) 
     EgammaHcalIsolation *class_myHoE_recHit_default = new EgammaHcalIsolation( 0.15, 0, 0.7, 0.1, 0., 0., theCaloGeometry.product(), *hbheRechitsHandle);
     
     float myHoE_recHit_default_d1 = (class_myHoE_recHit_default->getHcalESumDepth1(&superClus) ) / ( superClus.energy() );
     float myHoE_recHit_default_d2 = (class_myHoE_recHit_default->getHcalESumDepth2(&superClus) ) / ( superClus.energy() );
     float myHoE_recHit_default = myHoE_recHit_default_d1 + myHoE_recHit_default_d2  ;  
     
     std::cout << "cmsswHoE(full5x5) " << ele.full5x5_hcalOverEcal() << " cmsswHoE " << ele.hcalOverEcal()  << std::endl;   
     std::cout << "my HoE: from recHits " << myHoE_recHit_default << std::endl;

     HadEnergy_depth1.push_back(class_myHoE_recHit_default->getHcalESumDepth1(&superClus));   
     HadEnergy_depth2.push_back(class_myHoE_recHit_default->getHcalESumDepth2(&superClus));   
     scEn.push_back(superClus.energy());
     seedEn.push_back(seedCluster.energy());
     seedEnCorr.push_back(seedCluster.correctedEnergy());
     ecalEn.push_back(ele.ecalEnergy());
     cmssw_eleHoE.push_back(ele.hcalOverEcal());
     cmssw_eleHoE_full5x5.push_back(ele.full5x5_hcalOverEcal());
     my_eleHoE_default.push_back(myHoE_recHit_default);

     ///// using caloTowers  /// obsolete
     /*
       EgammaTowerIsolation had1(0.15,0,0,1,caloTowerHandle.product() );
       EgammaTowerIsolation had2(0.15,0,0,2,caloTowerHandle.product() );
       float hcalDepth1OverEcal =had1.getTowerESum(&superClus)/superClus.energy();
       float hcalDepth2OverEcal =had2.getTowerESum(&superClus)/superClus.energy();
       float myHoE_default =  hcalDepth1OverEcal+hcalDepth2OverEcal ;
     */
     
   }
   
   tree->Fill();
   
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
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

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(HoEAnalyzer);
