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
#include "Geometry/CaloTopology/interface/CaloTowerConstituentsMap.h"
#include "DataFormats/CaloTowers/interface/CaloTowerDetId.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EGHcalRecHitSelector.h"

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
  
  std::vector<float>  scEn;
  std::vector<float>  eleSCRawEn;
  std::vector<float>  ecalEn;
  std::vector<float>  seedEn;
  std::vector<float>  seedEnCorr;
  std::vector<float>  cmssw_eleHoE;
  std::vector<float>  cmssw_eleHoE_full5x5;
  std::vector<float>  eleScEta;
  std::vector<float>  elePt;
  std::vector<float>  elePhi;
  std::vector<float>  eleSigmaIEtaIEtaFull5x5;
  std::vector<float>  elePFNeuIso;
  std::vector<float>  elePFChIso;
  std::vector<int>    eleSeedDet;
  std::vector<int>    eleSeedSubdet;
  std::vector<int>    eleSeedIeta;
  std::vector<int>    eleSeedIphi;
  std::vector<int>    seedHcalIeta;
  std::vector<int>    seedHcalIphi;
  std::vector<int>    hcalRechitIeta;
  std::vector<int>    hcalRechitIphi;
  std::vector<float>  hcalRechitEnergy;
  std::vector<float>  hcalRechitAbsDIetaFromEleSeed;
  std::vector<float>  hcalRechitAbsDIphiFromEleSeed;
  std::vector<float>  puTrue;
  
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
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > eleToken_;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> >     puCollection_;
  edm::EDGetTokenT<HBHERecHitCollection> hbhe_rechits_;
  edm::ESHandle<CaloGeometry> theCaloGeometry;
  edm::ESHandle<CaloTowerConstituentsMap> towerMap_;

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
  puCollection_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("pileupCollection"))),
  hbhe_rechits_(consumes<HBHERecHitCollection>(iConfig.getParameter<edm::InputTag>("hbheInput")))
  
{
  //now do what ever initialization is needed
  
  tree->Branch("scEn_",&scEn);
  tree->Branch("eleSCRawEn_",&eleSCRawEn);
  tree->Branch("ecalEn_",&ecalEn);
  tree->Branch("seedEn_",&seedEn);
  tree->Branch("seedEnCorr_",&seedEnCorr);
  tree->Branch("cmssw_eleHoE_",&cmssw_eleHoE);
  tree->Branch("cmssw_eleHoE_full5x5_",&cmssw_eleHoE_full5x5);
  tree->Branch("eleScEta_",&eleScEta);
  tree->Branch("elePt_",&elePt);
  tree->Branch("elePhi_",&elePhi);
  tree->Branch("eleSigmaIEtaIEtaFull5x5_",&eleSigmaIEtaIEtaFull5x5);
  tree->Branch("elePFNeuIso_",&elePFNeuIso);
  tree->Branch("elePFChIso_",&elePFChIso);
  tree->Branch("eleSeedDet_",&eleSeedDet);
  tree->Branch("eleSeedSubdet_",&eleSeedSubdet);
  tree->Branch("eleSeedIeta_",&eleSeedIeta);
  tree->Branch("eleSeedIphi_",&eleSeedIphi);
  tree->Branch("seedHcalIeta_",&seedHcalIeta);
  tree->Branch("seedHcalIphi_",&seedHcalIphi);
  tree->Branch("hcalRechitIeta_",&hcalRechitIeta);
  tree->Branch("hcalRechitIphi_",&hcalRechitIphi);
  tree->Branch("hcalRechitEnergy_",&hcalRechitEnergy);
  tree->Branch("hcalRechitAbsDIetaFromEleSeed_",&hcalRechitAbsDIetaFromEleSeed);
  tree->Branch("hcalRechitAbsDIphiFromEleSeed_",&hcalRechitAbsDIphiFromEleSeed);
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
  
  //  std::cout << "\n \n ****** new event ... " << std::endl; 
  using namespace edm;
  
  scEn.clear();
  eleSCRawEn.clear();
  ecalEn.clear();
  seedEn.clear();
  seedEnCorr.clear();
  cmssw_eleHoE.clear();
  cmssw_eleHoE_full5x5.clear();
  eleScEta.clear();
  elePt.clear();
  elePhi.clear();
  eleSigmaIEtaIEtaFull5x5.clear();
  elePFNeuIso.clear();
  elePFChIso.clear();
  eleSeedDet.clear();
  eleSeedSubdet.clear();
  eleSeedIeta.clear();
  eleSeedIphi.clear();
  seedHcalIeta.clear();
  seedHcalIphi.clear();
  hcalRechitIeta.clear();
  hcalRechitIphi.clear();
  hcalRechitEnergy.clear();
  hcalRechitAbsDIetaFromEleSeed.clear();
  hcalRechitAbsDIphiFromEleSeed.clear();
  puTrue.clear();
  
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
  
  for(const auto& ele : iEvent.get(eleToken_) ) {
    
    eleScEta.push_back(ele.superCluster()->eta());
    elePt.push_back(ele.pt());
    elePhi.push_back(ele.phi());
    eleSigmaIEtaIEtaFull5x5.push_back(ele.full5x5_sigmaIetaIeta());

    reco::GsfElectron::PflowIsolationVariables pfIso = ele.pfIsolationVariables();
    elePFNeuIso.push_back(pfIso.sumNeutralHadronEt);
    elePFChIso.push_back(pfIso.sumChargedHadronPt);
    
    const reco::SuperCluster& superClus = *ele.superCluster();
    const reco::CaloCluster &seedCluster = *superClus.seed();
    DetId seedId = seedCluster.seed() ;
    eleSeedDet.push_back(seedId.det());
    eleSeedSubdet.push_back(seedId.subdetId());
    
    //     if( seedId.det() == DetId::Forward ) return; // i guess this is not needed for ntuplizing purpose
    
    if ( seedId.det() == DetId::Ecal ) {
      if (seedId.subdetId() == EcalBarrel) {
	EBDetId ebId(seedId);
	eleSeedIeta.push_back(ebId.ieta());
	eleSeedIphi.push_back(ebId.iphi());
      }
      
      else if (seedId.subdetId() == EcalEndcap) {
	EEDetId eeId(seedId);
	eleSeedIeta.push_back(eeId.ix());
	eleSeedIphi.push_back(eeId.iy());
	
      }
      
      else {
	//neither barrel nor endcap
	eleSeedIeta.push_back(9999);
	eleSeedIphi.push_back(9999);
	
      }
      
      CaloTowerDetId towerId(towerMap_->towerOf(seedId)); 
      int seedHcalIEta = towerId.ieta();
      int seedHcalIPhi = towerId.iphi();
      
      seedHcalIeta.push_back(seedHcalIEta);
      seedHcalIphi.push_back(seedHcalIPhi);
      
      for (auto& hcalrh : iEvent.get(hbhe_rechits_) ) {
	int dIEtaAbs = std::abs(calDIEta(seedHcalIEta, hcalrh.id().ieta()));
	int dIPhiAbs = std::abs(calDIPhi(seedHcalIPhi, hcalrh.id().iphi()));
	
	if ( (dIEtaAbs <= maxDIEta_) && (dIPhiAbs <= maxDIPhi_) &&  (hcalrh.energy()>getMinEnergyHCAL_(hcalrh.id()) ) ) {
	  //std::cout << "close to ele, save " << std::endl;
	  hcalRechitIeta.push_back(hcalrh.id().ieta());
	  hcalRechitIphi.push_back(hcalrh.id().iphi());
	  hcalRechitEnergy.push_back(hcalrh.energy());
	  hcalRechitAbsDIetaFromEleSeed.push_back(dIEtaAbs);
	  hcalRechitAbsDIphiFromEleSeed.push_back(dIPhiAbs);
	}
	
      }
      
    }
    else { 
      // std::cout << "seed is NOT in ecal !!!! " << std::endl;
      eleSeedIeta.push_back(8888);
      eleSeedIphi.push_back(8888);
      
      seedHcalIeta.push_back(9999);
      seedHcalIphi.push_back(9999);
      
    }
    
    //    std::cout << "cmsswHoE(full5x5) " << ele.full5x5_hcalOverEcal() << " cmsswHoE " << ele.hcalOverEcal()  << std::endl;   
    
    scEn.push_back(superClus.energy());
    eleSCRawEn.push_back(superClus.rawEnergy());
    seedEn.push_back(seedCluster.energy());
    seedEnCorr.push_back(seedCluster.correctedEnergy());
    ecalEn.push_back(ele.ecalEnergy());
    cmssw_eleHoE.push_back(ele.hcalOverEcal());
    cmssw_eleHoE_full5x5.push_back(ele.full5x5_hcalOverEcal());
    
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

//

float HoEAnalyzer::getMinEnergyHCAL_(HcalDetId id) const {
  if (id.subdetId() == HcalBarrel)
    return 0.8;
  else if (id.subdetId() == HcalEndcap) {
    if (id.depth() == 1)
      return 0.1;
    else
      return 0.2;
  } else
    return 99999;
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
