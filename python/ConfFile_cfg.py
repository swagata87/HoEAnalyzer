import FWCore.ParameterSet.Config as cms

process = cms.Process("HoE")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Geometry.CaloEventSetup.CaloTopology_cfi");
process.load("Geometry.CaloEventSetup.CaloGeometry_cfi");
process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi");
process.load("Configuration.Geometry.GeometryECALHCAL_cff")
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('PhysicsTools.HepMCCandAlgos.genParticles_cfi')
process.load("Geometry.HcalEventSetup.CaloTowerTopology_cfi")
#process.load("Configuration.Geometry.GeometryExtended2017_cff")
#process.load("Configuration.Geometry.GeometryExtended2017Reco_cff")
process.load("RecoJets.Configuration.CaloTowersES_cfi")
process.load("Geometry.HcalEventSetup.hcalTopologyIdeal_cfi")

process.MessageLogger.cerr.FwkReport.reportEvery = 500

from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_upgrade2018_realistic_v15', '')     # 2018 MC
#process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mcRun3_2023_realistic_v3', '')     # 2023 MC
process.GlobalTag = GlobalTag(process.GlobalTag, '113X_mcRun3_2021_realistic_v2', '')     # 2021 MC
#process.GlobalTag = GlobalTag(process.GlobalTag, '106X_dataRun2_v33', '')     # 2018 UL data
#
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring(
#                    '/store/group/phys_egamma/afiqaize/DoubleEle-FlatPt2To250-PU0/DoubleEle-FlatPt2To250-PU0_13TeV-110X_mcRun3_2021_realistic_v6/GEN-SIM-RAW/200224_141502/0000/test_1.root'
           #       '/store/mc/Run3Winter20DRMiniAOD/DoublePhoton_FlatPt-5To300/MINIAODSIM/FlatPU0to80_110X_mcRun3_2021_realistic_v6-v2/240000/03C64AA9-D7DC-044B-880D-B89ECF5AD74F.root'
                   ####samples i made (Single Ele gun )
#                  '/store/user/swmukher/SingleElectronPt2to100/SingleEle_MINIAOD_v3/191125_090555/0000/miniaod_50.root',
#                  '/store/user/swmukher/SingleElectronPt2to100/SingleEle_MINIAOD_v3/191125_090555/0000/miniaod_96.root'
#Run3 file to check hcal depths
#                   '/store/mc/Run3Summer19MiniAOD/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/MINIAODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FE3A7D24-F46E-8744-B92B-F6115FD395A0.root'
#2021 ele gun from Afiq
#                    '/store/group/phys_egamma/afiqaize/DoubleEle-FlatPt2To250-PU0/DoubleEle-FlatPt2To250-PU0_13TeV-110X_mcRun3_2021_realistic_v6/MINIAODSIM/200226_172748/0000/test_10.root'
#                    '/store/mc/Run3Winter20DRMiniAOD/ZprimeToEE_M-6000_TuneCP5_14TeV-pythia8/MINIAODSIM/FlatPU0to80_110X_mcRun3_2021_realistic_v6-v3/230000/FB256519-697F-B948-9022-AA9F5C3F8775.root'
#                    '/store/mc/Run3Winter20DRMiniAOD/DYToLL_M-50_TuneCP5_14TeV-pythia8/MINIAODSIM/DRFlatPU30to80_110X_mcRun3_2021_realistic_v6-v2/50000/FE203EF9-D824-8547-A809-FAF05F010C3F.root'
                    '/store/data/Run2018A/EGamma/MINIAOD/UL2018_MiniAODv2-v1/260000/02C33FEB-8CBF-0348-9D81-F54DF16AE9F9.root'
                                    
                )
                            )

process.demo = cms.EDAnalyzer('HoEAnalyzer',
#       rhoLabel  = cms.InputTag("fixedGridRhoFastjetAll"),
       electrons = cms.InputTag('slimmedElectrons'),
       photons = cms.InputTag('slimmedPhotons'),
       pileupCollection     = cms.InputTag("slimmedAddPileupInfo"),
       #hbheInput = cms.InputTag("reducedEgamma" ,  "reducedHBHEHits" ,  "RECO"),
       #hbheInput = cms.InputTag("reducedEgamma" ,  "reducedHBHEHits" ,  ""),
       ebReducedRecHitCollection = cms.InputTag("reducedEgamma", "reducedEBRecHits"),
       eeReducedRecHitCollection = cms.InputTag("reducedEgamma", "reducedEERecHits"),
       esReducedRecHitCollection = cms.InputTag("reducedEgamma", "reducedESRecHits"),
       genParticleSrc       = cms.InputTag("prunedGenParticles"),
#       genParticleSrc       = cms.InputTag("genParticles"),
       Run2_2018_ = cms.bool(False),
                              )
process.TFileService = cms.Service("TFileService", fileName = cms.string('test_MINIAOD.root'))

process.p = cms.Path(process.demo)
