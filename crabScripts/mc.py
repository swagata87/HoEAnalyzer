from CRABClient.UserUtilities import config #, getUsernameFromSiteDB
config = config()

config.General.requestName = ''
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../python/ConfFile_cfg.py'

config.Data.inputDataset = ''
config.Data.inputDBS = 'global'
#config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 5

config.Data.outLFNDirBase = '/store/group/phys_egamma/swmukher/HoE_Feb16_2020/winter20_MVA_depth/' #% (getUsernameFromSiteDB())
config.Data.publication = False
config.Data.outputDatasetTag = 'HoE_2021'
config.Site.storageSite = 'T2_CH_CERN'
config.Site.ignoreGlobalBlacklist = True

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    
    config.General.workArea = 'crab_mc_Feb21_2020' 

    def submit(config):
        try:
            crabCommand('submit', config = config)
        except HTTPException as hte:
            print "Failed submitting task: %s" % (hte.headers)
        except ClientException as cle:
            print "Failed submitting task: %s" % (cle)

#2024
#    config.General.requestName = 'TTToSemiLeptonic_2024'
#    config.Data.inputDataset = '/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/Run3Summer19DRPremix-2024Scenario_106X_mcRun3_2024_realistic_v4-v2/AODSIM'
#    submit(config)

#    config.General.requestName = 'QCD_2024'
#    config.Data.inputDataset = '/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/Run3Summer19DR-106X_mcRun3_2024_realistic_v4-v2/AODSIM'
#    submit(config)

#    config.General.requestName = 'DYToEE_2024'
#    config.Data.inputDataset = '/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/Run3Summer19DRPremix-2024Scenario_106X_mcRun3_2024_realistic_v4-v2/AODSIM'
#    submit(config)

#2023
#    config.General.requestName = 'DYToEE_2023'
#    config.Data.inputDataset = '/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/Run3Summer19MiniAOD-2023Scenario_106X_mcRun3_2023_realistic_v3-v2/MINIAODSIM'
#    submit(config)

#    config.General.requestName = 'GJet_2023'
#    config.Data.inputDataset = '/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_14TeV_Pythia8/Run3Summer19DRPremix-2023Scenario_106X_mcRun3_2023_realistic_v3-v1/AODSIM'
#    submit(config)


#    config.General.requestName = 'QCD_2023'
#    config.Data.inputDataset = '/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/Run3Summer19MiniAOD-106X_mcRun3_2023_realistic_v3-v2/MINIAODSIM'
#    submit(config)

#    config.General.requestName = 'TTToSemiLeptonic_2023'
#    config.Data.inputDataset = '/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/Run3Summer19MiniAOD-2023Scenario_106X_mcRun3_2023_realistic_v3-v2/MINIAODSIM'
#    submit(config)

#2021
#    config.General.requestName = 'TTToSemiLeptonic_2021'
#    config.Data.inputDataset = '/TTToSemiLeptonic_TuneCP5_14TeV-powheg-pythia8/Run3Summer19DRPremix-2021Scenario_106X_mcRun3_2021_realistic_v3-v2/AODSIM'
#    submit(config)

#    config.General.requestName = 'QCD_2021'
#    config.Data.inputDataset = '/QCD_Pt_15to7000_TuneCP5_Flat_14TeV_pythia8/Run3Summer19DR-106X_mcRun3_2021_realistic_v3-v2/AODSIM'
#    submit(config)

#    config.General.requestName = 'DYToEE_2021'
#    config.Data.inputDataset = '/DYToEE_M-50_NNPDF31_TuneCP5_14TeV-powheg-pythia8/Run3Summer19DRPremix-2021Scenario_106X_mcRun3_2021_realistic_v3-v2/AODSIM'
#    submit(config)

#2018
#    config.General.requestName = 'QCD_2018'
#    config.Data.inputDataset = '/QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_ext1-v1/MINIAODSIM'
#    submit(config)

#    config.General.requestName = 'DYToEE_2018'
#    config.Data.inputDataset = '/DYToEE_M-50_NNPDF31_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'
#    submit(config)

#    config.General.requestName = 'TTToSemiLeptonic_2018'
#    config.Data.inputDataset = '/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-v1/MINIAODSIM'
#    submit(config)

#    config.General.requestName = 'SingleElectronPt2to100_addGapinfo'
#    config.Data.inputDataset = '/SingleElectronPt2to100/swmukher-SingleEle_MINIAOD_v3-dc6c4d7cf95a40d6b181c54570d8d0c3/USER'
#    submit(config)


    config.General.requestName = 'DYToLL_pythia'
    config.Data.inputDataset = '/DYToLL_M-50_TuneCP5_14TeV-pythia8/Run3Winter20DRMiniAOD-DRFlatPU30to80_110X_mcRun3_2021_realistic_v6-v2/MINIAODSIM'
    submit(config)  

    config.General.requestName = 'QCD_pythia'
    config.Data.inputDataset = '/QCD_Pt-15to3000_TuneCP5_Flat_14TeV_pythia8/Run3Winter20DRMiniAOD-DRFlatPU30to80_110X_mcRun3_2021_realistic_v6-v2/MINIAODSIM'
    submit(config)  
