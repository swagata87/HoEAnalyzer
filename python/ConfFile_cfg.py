import FWCore.ParameterSet.Config as cms

process = cms.Process("HoE")

process.load("FWCore.MessageService.MessageLogger_cfi")
#process.load("Configuration.StandardSequences.GeometryRecoDB_cff")
#process.load("Configuration.StandardSequences.MagneticField_cff")
#process.load("Configuration.EventContent.EventContent_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Geometry.CaloEventSetup.CaloTopology_cfi");
process.load("Geometry.CaloEventSetup.CaloGeometry_cfi");
process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi");
process.load("Configuration.Geometry.GeometryECALHCAL_cff")
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('PhysicsTools.HepMCCandAlgos.genParticles_cfi')

#from SimGeneral.HepPDTESSource.pythiapdt_cfi import *
#from RecoJets.Configuration.GenJetParticles_cff import *

process.MessageLogger.cerr.FwkReport.reportEvery = 500

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_mc', '')     # MC

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(2000) )

process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring(
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/270000/FE2EA85F-2F46-9B41-B6FF-E724174EE4CE.root',#2018 AOD
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/72DDC91F-6BC8-D343-A44C-6D537B8547FC.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/76FA30CA-F518-ED4D-8AA4-AD2D43E74742.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/77299BB6-3845-E246-B8BE-22A4D464B5EA.root',
#                '/store/mc/RunIIAutumn18DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/AODSIM/102X_upgrade2018_realistic_v15-v1/120001/7A836983-300B-CD4D-8765-EFC6496BA19C.root',
#'/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/NoPUEcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/FF27DADE-0845-2E4E-94D7-98E1486239F8.root'
#'/store/mc/RunIIAutumn18DR/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/GEN-SIM-RECO/FlatPU0to70EcalAging2022_102X_upgrade2018_realistic_EcalAging_mid2022_315fb_v1-v1/100000/FDE6F828-19D1-2A44-A770-B93744C6A7CC.root'
#2023
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/FFD71080-0F4A-1340-962F-D23AC2252C7C.root', #2023 AOD
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DE8D397F-BC95-4546-A75C-4ABCAAEF312B.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DEE779FF-58CF-1549-9998-5C0B977B484F.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DF106A6B-F79C-604F-803A-3AC0B943E48C.root',
#               '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2023Scenario_106X_mcRun3_2023_realistic_v3-v2/260000/DF1555B1-2759-774B-AB6A-41F634BC4249.root'
#2021
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/FF3F1F82-05A1-5247-BF2D-10CC42EF827B.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/DE7689B8-0271-A844-B24D-A9A842DB07FE.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/DF62A0BD-0D6C-1E43-8B98-FC720604AB7F.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/F27584A0-93BA-A549-9233-F121DE8B987A.root',
#                '/store/mc/Run3Summer19DRPremix/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/AODSIM/2021Scenario_106X_mcRun3_2021_realistic_v3-v2/270000/E040E1D7-5ADD-EE49-923F-FF232F91A4A6.root'
#miniAOD 2018
'/store/mc/RunIIAutumn18MiniAOD/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/270000/D0F66982-B732-0D4F-BA52-AC8868C57CFE.root'
                )
                            )

process.demo = cms.EDAnalyzer('HoEAnalyzer',
#       tracks = cms.untracked.InputTag('generalTracks'),
#       electrons = cms.InputTag('gedGsfElectrons'),
       electrons = cms.InputTag('slimmedElectrons'),
       #electrons = cms.InputTag('slimmedElectrons'),
       #EBRecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEB"), #RECO 
       #EERecHitCollection = cms.InputTag("ecalRecHit","EcalRecHitsEE"), #RECO
       #EERecHitCollection = cms.InputTag("reducedEcalRecHitsEE"), #AOD
       #EBRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"), #AOD
#      pfrechits = cms.InputTag('particleFlowRecHitECAL'   , 'Cleaned'  ,       'RECO'), #AOD    
       #EERecHitCollection = cms.InputTag("reducedEERecHits"), #miniAOD
       #EBRecHitCollection = cms.InputTag("reducedEBRecHits"), #miniAOD
       #pileupCollection     = cms.InputTag("addPileupInfo"),
       #genParticleSrc       = cms.InputTag("genParticles"),
#       caloTowersTag = cms.untracked.InputTag("towerMaker"),
       pileupCollection     = cms.InputTag("slimmedAddPileupInfo"),
#       hbheInput = cms.InputTag("reducedHcalRecHits","hbhereco","RECO" ),
       hbheInput = cms.InputTag("reducedEgamma" ,  "reducedHBHEHits" ,  "PAT"),
                              )
#process.TFileService = cms.Service("TFileService", fileName = cms.string('RedefNtup_AOD_2018.root'))
process.TFileService = cms.Service("TFileService", fileName = cms.string('test_AOD_2018.root'))

process.p = cms.Path(process.demo)
