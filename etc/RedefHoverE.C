#define RedefHoverE_cxx
#include "RedefHoverE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TProfile.h>
#include <string>

float DeltaR(float ecalEta, float ecalPhi, float hcalEta, float hcalPhi)
{
  //  std::cout << "inside DeltaR function " << std::endl;
  float dR=999.9;
  const double pi = 3.14159;

  float deltaphi = fabs(ecalPhi - hcalPhi);
  if (deltaphi > pi) deltaphi = 2. * pi - deltaphi;

  float deltaeta = fabs(ecalEta - hcalEta);
  //  std::cout << "dphi, deta " << deltaphi << ", " << deltaeta << std::endl;
  
  dR = sqrt(deltaphi*deltaphi + deltaeta*deltaeta);

  return dR;
}

void RedefHoverE::Loop()
{
//   In a ROOT session, you can do:
//      root> .L RedefHoverE.C
//      root> RedefHoverE t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  TFile* outputFile = new TFile("Out_redefhists_HoE_2018.root","RECREATE");
//  TFile* outputFile = new TFile("testOut.root","RECREATE");

  TH1D* h1_myHoE_conedR0p15_allEle_fullEta = new TH1D("h1_myHoE_conedR0p15_allEle_fullEta", "myHoE_conedR0p15_allEle_fullEta", 1000, 0, 20);

  //all Ele
  TH1D* h1_myHoE_conedR0p15_allEle_Barrel = new TH1D("h1_myHoE_conedR0p15_allEle_Barrel", "myHoE_conedR0p15_allEle_Barrel", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_allEle_Barrel_Depth1 = new TH1D("h1_myHoE_conedR0p15_allEle_Barrel_d1", "myHoE_conedR0p15_allEle_Barrel_d1", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_allEle_Barrel_Depth2 = new TH1D("h1_myHoE_conedR0p15_allEle_Barrel_d2", "myHoE_conedR0p15_allEle_Barrel_d2", 1000, 0, 20);


  //////////////////////////////
  /// cone size deltaR=0.30 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p30_sig_Barrel = new TH1D("h1_myHoE_conedR0p30_sig_Barrel", "myHoE_conedR0p30_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p30_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p30_sig_Barrel_vs_PU","myHoE_conedR0p30_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p30_sig_Endcap = new TH1D("h1_myHoE_conedR0p30_sig_Endcap", "myHoE_conedR0p30_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p30_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p30_sig_Endcap_vs_PU","myHoE_conedR0p30_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p30_bkg_Barrel = new TH1D("h1_myHoE_conedR0p30_bkg_Barrel", "myHoE_conedR0p30_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p30_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p30_bkg_Barrel_vs_PU","myHoE_conedR0p30_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p30_bkg_Endcap = new TH1D("h1_myHoE_conedR0p30_bkg_Endcap", "myHoE_conedR0p30_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p30_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p30_bkg_Endcap_vs_PU","myHoE_conedR0p30_bkg_Endcap_vs_PU", 40,0,80,0,15);

  //////////////////////////////
  /// cone size deltaR=0.40 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p40_sig_Barrel = new TH1D("h1_myHoE_conedR0p40_sig_Barrel", "myHoE_conedR0p40_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p40_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p40_sig_Barrel_vs_PU","myHoE_conedR0p40_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p40_sig_Endcap = new TH1D("h1_myHoE_conedR0p40_sig_Endcap", "myHoE_conedR0p40_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p40_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p40_sig_Endcap_vs_PU","myHoE_conedR0p40_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p40_bkg_Barrel = new TH1D("h1_myHoE_conedR0p40_bkg_Barrel", "myHoE_conedR0p40_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p40_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p40_bkg_Barrel_vs_PU","myHoE_conedR0p40_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p40_bkg_Endcap = new TH1D("h1_myHoE_conedR0p40_bkg_Endcap", "myHoE_conedR0p40_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p40_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p40_bkg_Endcap_vs_PU","myHoE_conedR0p40_bkg_Endcap_vs_PU", 40,0,80,0,15);

  //////////////////////////////
  /// cone size deltaR=0.50 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p50_sig_Barrel = new TH1D("h1_myHoE_conedR0p50_sig_Barrel", "myHoE_conedR0p50_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p50_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p50_sig_Barrel_vs_PU","myHoE_conedR0p50_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p50_sig_Endcap = new TH1D("h1_myHoE_conedR0p50_sig_Endcap", "myHoE_conedR0p50_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p50_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p50_sig_Endcap_vs_PU","myHoE_conedR0p50_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p50_bkg_Barrel = new TH1D("h1_myHoE_conedR0p50_bkg_Barrel", "myHoE_conedR0p50_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p50_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p50_bkg_Barrel_vs_PU","myHoE_conedR0p50_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p50_bkg_Endcap = new TH1D("h1_myHoE_conedR0p50_bkg_Endcap", "myHoE_conedR0p50_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p50_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p50_bkg_Endcap_vs_PU","myHoE_conedR0p50_bkg_Endcap_vs_PU", 40,0,80,0,15);

  //////////////////////////////
  /// cone size deltaR=0.60 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p60_sig_Barrel = new TH1D("h1_myHoE_conedR0p60_sig_Barrel", "myHoE_conedR0p60_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p60_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p60_sig_Barrel_vs_PU","myHoE_conedR0p60_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p60_sig_Endcap = new TH1D("h1_myHoE_conedR0p60_sig_Endcap", "myHoE_conedR0p60_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p60_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p60_sig_Endcap_vs_PU","myHoE_conedR0p60_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p60_bkg_Barrel = new TH1D("h1_myHoE_conedR0p60_bkg_Barrel", "myHoE_conedR0p60_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p60_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p60_bkg_Barrel_vs_PU","myHoE_conedR0p60_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p60_bkg_Endcap = new TH1D("h1_myHoE_conedR0p60_bkg_Endcap", "myHoE_conedR0p60_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p60_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p60_bkg_Endcap_vs_PU","myHoE_conedR0p60_bkg_Endcap_vs_PU", 40,0,80,0,15);

  //////////////////////////////
  /// cone size deltaR=0.70 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p70_sig_Barrel = new TH1D("h1_myHoE_conedR0p70_sig_Barrel", "myHoE_conedR0p70_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p70_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p70_sig_Barrel_vs_PU","myHoE_conedR0p70_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p70_sig_Endcap = new TH1D("h1_myHoE_conedR0p70_sig_Endcap", "myHoE_conedR0p70_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p70_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p70_sig_Endcap_vs_PU","myHoE_conedR0p70_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p70_bkg_Barrel = new TH1D("h1_myHoE_conedR0p70_bkg_Barrel", "myHoE_conedR0p70_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p70_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p70_bkg_Barrel_vs_PU","myHoE_conedR0p70_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p70_bkg_Endcap = new TH1D("h1_myHoE_conedR0p70_bkg_Endcap", "myHoE_conedR0p70_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p70_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p70_bkg_Endcap_vs_PU","myHoE_conedR0p70_bkg_Endcap_vs_PU", 40,0,80,0,15);


  //////////////////////////////
  /// cone size deltaR=0.20 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p20_sig_Barrel = new TH1D("h1_myHoE_conedR0p20_sig_Barrel", "myHoE_conedR0p20_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p20_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p20_sig_Barrel_vs_PU","myHoE_conedR0p20_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  TProfile* prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt = new TProfile("prof_myH_conedR0p20_sig_Barrel_vs_pt","myH_conedR0p20_sig_Barrel_vs_pt", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d1 = new TProfile("prof_myH_conedR0p20_sig_Barrel_vs_pt_d1","myH_conedR0p20_sig_Barrel_vs_pt_d1", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d2 = new TProfile("prof_myH_conedR0p20_sig_Barrel_vs_pt_d2","myH_conedR0p20_sig_Barrel_vs_pt_d2", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d3 = new TProfile("prof_myH_conedR0p20_sig_Barrel_vs_pt_d3","myH_conedR0p20_sig_Barrel_vs_pt_d3", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d4 = new TProfile("prof_myH_conedR0p20_sig_Barrel_vs_pt_d4","myH_conedR0p20_sig_Barrel_vs_pt_d4", 200,0,200,0,200);
  //
  TProfile* prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d1 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d1","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d1",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d2 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d2","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d2",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d3 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d3","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d3",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d4 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d4","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden_d4",200,0,200,0,200);
  //
  //
  //sig endcap
  //
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt","myH_conedR0p20_sig_Endcap_vs_pt", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d1 = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt_d1","myH_conedR0p20_sig_Endcap_vs_pt_d1", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d2 = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt_d2","myH_conedR0p20_sig_Endcap_vs_pt_d2", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d3 = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt_d3","myH_conedR0p20_sig_Endcap_vs_pt_d3", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d4 = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt_d4","myH_conedR0p20_sig_Endcap_vs_pt_d4", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d5 = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt_d5","myH_conedR0p20_sig_Endcap_vs_pt_d5", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d6 = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt_d6","myH_conedR0p20_sig_Endcap_vs_pt_d6", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d7 = new TProfile("prof_myH_conedR0p20_sig_Endcap_vs_pt_d7","myH_conedR0p20_sig_Endcap_vs_pt_d7", 200,0,200,0,200);
  //
  TProfile* prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d1 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d1","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d1",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d2 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d2","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d2",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d3 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d3","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d3",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d4 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d4","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d4",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d5 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d5","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d5",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d6 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d6","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d6",200,0,200,0,200);
  TProfile* prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d7 =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d7","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden_d7",200,0,200,0,200);
  //
  TH1D* h1_myHoE_conedR0p20_sig_Endcap = new TH1D("h1_myHoE_conedR0p20_sig_Endcap", "myHoE_conedR0p20_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p20_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p20_sig_Endcap_vs_PU","myHoE_conedR0p20_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p20_bkg_Barrel = new TH1D("h1_myHoE_conedR0p20_bkg_Barrel", "myHoE_conedR0p20_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p20_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p20_bkg_Barrel_vs_PU","myHoE_conedR0p20_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p20_bkg_Endcap = new TH1D("h1_myHoE_conedR0p20_bkg_Endcap", "myHoE_conedR0p20_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p20_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p20_bkg_Endcap_vs_PU","myHoE_conedR0p20_bkg_Endcap_vs_PU", 40,0,80,0,15);

  //////////////////////////////
  /// cone size deltaR=0.25 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p25_sig_Barrel = new TH1D("h1_myHoE_conedR0p25_sig_Barrel", "myHoE_conedR0p25_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p25_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p25_sig_Barrel_vs_PU","myHoE_conedR0p25_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p25_sig_Endcap = new TH1D("h1_myHoE_conedR0p25_sig_Endcap", "myHoE_conedR0p25_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p25_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p25_sig_Endcap_vs_PU","myHoE_conedR0p25_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p25_bkg_Barrel = new TH1D("h1_myHoE_conedR0p25_bkg_Barrel", "myHoE_conedR0p25_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p25_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p25_bkg_Barrel_vs_PU","myHoE_conedR0p25_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p25_bkg_Endcap = new TH1D("h1_myHoE_conedR0p25_bkg_Endcap", "myHoE_conedR0p25_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p25_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p25_bkg_Endcap_vs_PU","myHoE_conedR0p25_bkg_Endcap_vs_PU", 40,0,80,0,15);

  //////////////////////////////
  /// cone size deltaR=0.10 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p10_sig_Barrel = new TH1D("h1_myHoE_conedR0p10_sig_Barrel", "myHoE_conedR0p10_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p10_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p10_sig_Barrel_vs_PU","myHoE_conedR0p10_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p10_sig_Endcap = new TH1D("h1_myHoE_conedR0p10_sig_Endcap", "myHoE_conedR0p10_sig_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p10_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p10_sig_Endcap_vs_PU","myHoE_conedR0p10_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p10_bkg_Barrel = new TH1D("h1_myHoE_conedR0p10_bkg_Barrel", "myHoE_conedR0p10_bkg_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p10_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p10_bkg_Barrel_vs_PU","myHoE_conedR0p10_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p10_bkg_Endcap = new TH1D("h1_myHoE_conedR0p10_bkg_Endcap", "myHoE_conedR0p10_bkg_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p10_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p10_bkg_Endcap_vs_PU","myHoE_conedR0p10_bkg_Endcap_vs_PU", 40,0,80,0,15);

  //////////////////////////////
  /// cone size deltaR=0.15 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_cmsswHoE_conedR0p15_sig_Barrel = new TH1D("h1_cmsswHoE_conedR0p15_sig_Barrel", "cmsswHoE_conedR0p15_sig_Barrel", 2000, 0, 20);
  TH1D* h1_cmsswfull5x5HoE_conedR0p15_sig_Barrel = new TH1D("h1_cmsswfull5x5HoE_conedR0p15_sig_Barrel", "cmsswfull5x5HoE_conedR0p15_sig_Barrel", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel = new TH1D("h1_myHoE_conedR0p15_sig_Barrel", "myHoE_conedR0p15_sig_Barrel", 2000, 0, 20);
  //
  TH2D* h2D_myH_RingAnnular_0p3m0p1_sig_vs_eta_phi = new TH2D("h2D_myH_RingAnnular_0p3m0p1_sig_vs_eta_phi","h2D_myH_RingAnnular_0p3m0p1_sig_vs_eta_phi", 800,-4,4,800,-4,4);
  TH2D* h2D_myH2_RingAnnular_0p3m0p1_sig_vs_eta_phi = new TH2D("h2D_myH2_RingAnnular_0p3m0p1_sig_vs_eta_phi","h2D_myH2_RingAnnular_0p3m0p1_sig_vs_eta_phi", 800,-4,4,800,-4,4);
  TH1D* h1D_myH_RingAnnular_0p3m0p1_sig_eta = new TH1D("h1D_myH_RingAnnular_0p3m0p1_sig_eta","h1D_myH_RingAnnular_0p3m0p1_sig_eta", 800,-4,4);
  TH1D* h1D_myH2_RingAnnular_0p3m0p1_sig_eta = new TH1D("h1D_myH2_RingAnnular_0p3m0p1_sig_eta","h1D_myH2_RingAnnular_0p3m0p1_sig_eta", 800,-4,4);

  TH1D* h1D_myH_RingAnnular_0p3m0p1_sig_phi = new TH1D("h1D_myH_RingAnnular_0p3m0p1_sig_phi","h1D_myH_RingAnnular_0p3m0p1_sig_phi", 800,-4,4);
  TH1D* h1D_myH2_RingAnnular_0p3m0p1_sig_phi = new TH1D("h1D_myH2_RingAnnular_0p3m0p1_sig_phi","h1D_myH2_RingAnnular_0p3m0p1_sig_phi", 800,-4,4);

  TH1D* h1D_myH_RingAnnular_0p3m0p1_sig_genpt = new TH1D("h1D_myH_RingAnnular_0p3m0p1_sig_genpt","h1D_myH_RingAnnular_0p3m0p1_sig_genpt", 150,0,150);
  TH1D* h1D_myH2_RingAnnular_0p3m0p1_sig_genpt = new TH1D("h1D_myH2_RingAnnular_0p3m0p1_sig_genpt","h1D_myH2_RingAnnular_0p3m0p1_sig_genpt", 150,0,150);

  TH1D* h1D_myH_RingAnnular_0p3m0p1_sig_ptR_by_ptG = new TH1D("h1D_myH_RingAnnular_0p3m0p1_sig_ptR_by_ptG","h1D_myH_RingAnnular_0p3m0p1_sig_ptR_by_ptG", 200,0,2);
  TH1D* h1D_myH2_RingAnnular_0p3m0p1_sig_ptR_by_ptG = new TH1D("h1D_myH2_RingAnnular_0p3m0p1_sig_ptR_by_ptG","h1D_myH2_RingAnnular_0p3m0p1_sig_ptR_by_ptG", 200,0,2);

  TH1D* h1D_myH_RingAnnular_0p3m0p1_sig_R9 = new TH1D("h1D_myH_RingAnnular_0p3m0p1_sig_R9","h1D_myH_RingAnnular_0p3m0p1_sig_R9", 200,0.8,1.2);
  TH1D* h1D_myH2_RingAnnular_0p3m0p1_sig_R9 = new TH1D("h1D_myH2_RingAnnular_0p3m0p1_sig_R9","h1D_myH2_RingAnnular_0p3m0p1_sig_R9", 200,0.8,1.2);

  //
  TH2D* h2D_myH_conedR0p15_sig_vs_eta_phi = new TH2D("h2D_myH_conedR0p15_sig_vs_eta_phi","h2D_myH_conedR0p15_sig_vs_eta_phi", 800,-4,4,800,-4,4);
  TH2D* h2D_myH2_conedR0p15_sig_vs_eta_phi = new TH2D("h2D_myH2_conedR0p15_sig_vs_eta_phi","h2D_myH2_conedR0p15_sig_vs_eta_phi", 800,-4,4,800,-4,4);
  //
  TH1D* h1_myH_conedR0p15_sig_Barrel = new TH1D("h1_myH_conedR0p15_sig_Barrel", "myH_conedR0p15_sig_Barrel", 2000, 0, 200);
  TProfile* prof_myH_conedR0p15_sig_Barrel_vs_pt = new TProfile("prof_myH_conedR0p15_sig_Barrel_vs_pt","myH_conedR0p15_sig_Barrel_vs_pt", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p15_sig_Barrel_vs_eta = new TProfile("prof_myH_conedR0p15_sig_Barrel_vs_eta","myH_conedR0p15_sig_Barrel_vs_eta", 600,-3,3,0,200);
  TProfile* prof_myH_conedR0p15_sig_Barrel_vs_phi = new TProfile("prof_myH_conedR0p15_sig_Barrel_vs_phi","myH_conedR0p15_sig_Barrel_vs_phi", 800,-4,4,0,200);
  //
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth1 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d1", "myHoE_conedR0p15_sig_Barrel_d1", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth2 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d2", "myHoE_conedR0p15_sig_Barrel_d2", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth3 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d3", "myHoE_conedR0p15_sig_Barrel_d3", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth4 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d4", "myHoE_conedR0p15_sig_Barrel_d4", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth5 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d5", "myHoE_conedR0p15_sig_Barrel_d5", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth6 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d6", "myHoE_conedR0p15_sig_Barrel_d6", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth7 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d7", "myHoE_conedR0p15_sig_Barrel_d7", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth8 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d8", "myHoE_conedR0p15_sig_Barrel_d8", 2000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D2overD1_conedR0p15_sig_Barrel", "H_D2overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D3overD1_conedR0p15_sig_Barrel", "H_D3overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D4overD1_conedR0p15_sig_Barrel", "H_D4overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D5overD1_conedR0p15_sig_Barrel", "H_D5overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p15_sig_Barrel_vs_PU","myHoE_conedR0p15_sig_Barrel_vs_PU", 40,0,80,0,15);
  TProfile* prof_cmsswHoE_conedR0p15_sig_Barrel_vs_PU = new TProfile("prof_cmsswHoE_conedR0p15_sig_Barrel_vs_PU","cmsswHoE_conedR0p15_sig_Barrel_vs_PU", 40,0,80,0,15);
  TProfile* prof_cmsswfull5x5HoE_conedR0p15_sig_Barrel_vs_PU = new TProfile("prof_cmsswfull5x5HoE_conedR0p15_sig_Barrel_vs_PU","cmsswfull5x5HoE_conedR0p15_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_cmsswHoE_conedR0p15_sig_Endcap = new TH1D("h1_cmsswHoE_conedR0p15_sig_Endcap", "cmsswHoE_conedR0p15_sig_Endcap", 2000, 0, 20);
  TH1D* h1_cmsswfull5x5HoE_conedR0p15_sig_Endcap = new TH1D("h1_cmsswfull5x5HoE_conedR0p15_sig_Endcap", "cmsswfull5x5HoE_conedR0p15_sig_Endcap", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap = new TH1D("h1_myHoE_conedR0p15_sig_Endcap", "myHoE_conedR0p15_sig_Endcap", 2000, 0, 20);
  //
  TH1D* h1_myH_conedR0p15_sig_Endcap = new TH1D("h1_myH_conedR0p15_sig_Endcap", "myH_conedR0p15_sig_Endcap", 2000, 0, 200);
  TProfile* prof_myH_conedR0p15_sig_Endcap_vs_pt = new TProfile("prof_myH_conedR0p15_sig_Endcap_vs_pt","myH_conedR0p15_sig_Endcap_vs_pt", 200,0,200,0,200);
  TProfile* prof_myH_conedR0p15_sig_Endcap_vs_eta = new TProfile("prof_myH_conedR0p15_sig_Endcap_vs_eta","myH_conedR0p15_sig_Endcap_vs_eta", 600,-3,3,0,200);
  TProfile* prof_myH_conedR0p15_sig_Endcap_vs_phi = new TProfile("prof_myH_conedR0p15_sig_Endcap_vs_phi","myH_conedR0p15_sig_Endcap_vs_phi", 800,-4,4,0,200);
  //
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth1 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d1", "myHoE_conedR0p15_sig_Endcap_d1", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth2 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d2", "myHoE_conedR0p15_sig_Endcap_d2", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth3 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d3", "myHoE_conedR0p15_sig_Endcap_d3", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth4 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d4", "myHoE_conedR0p15_sig_Endcap_d4", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth5 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d5", "myHoE_conedR0p15_sig_Endcap_d5", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth6 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d6", "myHoE_conedR0p15_sig_Endcap_d6", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth7 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d7", "myHoE_conedR0p15_sig_Endcap_d7", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth8 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d8", "myHoE_conedR0p15_sig_Endcap_d8", 2000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D2overD1_conedR0p15_sig_Endcap", "H_D2overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D3overD1_conedR0p15_sig_Endcap", "H_D3overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D4overD1_conedR0p15_sig_Endcap", "H_D4overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D5overD1_conedR0p15_sig_Endcap", "H_D5overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p15_sig_Endcap_vs_PU","myHoE_conedR0p15_sig_Endcap_vs_PU", 40,0,80,0,15);
  TProfile* prof_cmsswHoE_conedR0p15_sig_Endcap_vs_PU = new TProfile("prof_cmsswHoE_conedR0p15_sig_Endcap_vs_PU","cmsswHoE_conedR0p15_sig_Endcap_vs_PU", 40,0,80,0,15);
  TProfile* prof_cmsswfull5x5HoE_conedR0p15_sig_Endcap_vs_PU = new TProfile("prof_cmsswfull5x5HoE_conedR0p15_sig_Endcap_vs_PU","cmsswfull5x5HoE_conedR0p15_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_cmsswHoE_conedR0p15_bkg_Barrel = new TH1D("h1_cmsswHoE_conedR0p15_bkg_Barrel", "cmsswHoE_conedR0p15_bkg_Barrel", 2000, 0, 20);
  TH1D* h1_cmsswfull5x5HoE_conedR0p15_bkg_Barrel = new TH1D("h1_cmsswfull5x5HoE_conedR0p15_bkg_Barrel", "cmsswfull5x5HoE_conedR0p15_bkg_Barrel", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel", "myHoE_conedR0p15_bkg_Barrel", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth1 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d1", "myHoE_conedR0p15_bkg_Barrel_d1", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth2 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d2", "myHoE_conedR0p15_bkg_Barrel_d2", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth3 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d3", "myHoE_conedR0p15_bkg_Barrel_d3", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth4 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d4", "myHoE_conedR0p15_bkg_Barrel_d4", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth5 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d5", "myHoE_conedR0p15_bkg_Barrel_d5", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth6 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d6", "myHoE_conedR0p15_bkg_Barrel_d6", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth7 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d7", "myHoE_conedR0p15_bkg_Barrel_d7", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth8 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d8", "myHoE_conedR0p15_bkg_Barrel_d8", 2000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D2overD1_conedR0p15_bkg_Barrel", "H_D2overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D3overD1_conedR0p15_bkg_Barrel", "H_D3overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D4overD1_conedR0p15_bkg_Barrel", "H_D4overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D5overD1_conedR0p15_bkg_Barrel", "H_D5overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p15_bkg_Barrel_vs_PU","myHoE_conedR0p15_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_cmsswHoE_conedR0p15_bkg_Endcap = new TH1D("h1_cmsswHoE_conedR0p15_bkg_Endcap", "cmsswHoE_conedR0p15_bkg_Endcap", 2000, 0, 20);
  TH1D* h1_cmsswfull5x5HoE_conedR0p15_bkg_Endcap = new TH1D("h1_cmsswfull5x5HoE_conedR0p15_bkg_Endcap", "cmsswfull5x5HoE_conedR0p15_bkg_Endcap", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap", "myHoE_conedR0p15_bkg_Endcap", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth1 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d1", "myHoE_conedR0p15_bkg_Endcap_d1", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth2 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d2", "myHoE_conedR0p15_bkg_Endcap_d2", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth3 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d3", "myHoE_conedR0p15_bkg_Endcap_d3", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth4 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d4", "myHoE_conedR0p15_bkg_Endcap_d4", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth5 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d5", "myHoE_conedR0p15_bkg_Endcap_d5", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth6 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d6", "myHoE_conedR0p15_bkg_Endcap_d6", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth7 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d7", "myHoE_conedR0p15_bkg_Endcap_d7", 2000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth8 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d8", "myHoE_conedR0p15_bkg_Endcap_d8", 2000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D2overD1_conedR0p15_bkg_Endcap", "H_D2overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D3overD1_conedR0p15_bkg_Endcap", "H_D3overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D4overD1_conedR0p15_bkg_Endcap", "H_D4overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D5overD1_conedR0p15_bkg_Endcap", "H_D5overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p15_bkg_Endcap_vs_PU","myHoE_conedR0p15_bkg_Endcap_vs_PU", 40,0,80,0,15);



  //////////////////////////////////////////
  //
  TH1D* h1_myHoE_conedR0p15_allEle_Endcap = new TH1D("h1_myHoE_conedR0p15_allEle_Endcap", "myHoE_conedR0p15_allEle_Endcap", 2000, 0, 20);
  TProfile* prof_myHoE_conedR0p15_allEle_Barrel_vs_pt = new TProfile("prof_myHoE_conedR0p15_allEle_Barrel_vs_pt","myHoE_conedR0p15_allEle_Barrel_vs_pt", 20,0,200,0,15);
  //
  TProfile* prof_myHoE_conedR0p15_sig_vs_eta = new TProfile("prof_myHoE_conedR0p15_sig_vs_eta","myHoE_conedR0p15_sig_vs_eta", 240,-3,3,0,15);
  TProfile* prof_myHoE_conedR0p15_bkg_vs_eta = new TProfile("prof_myHoE_conedR0p15_bkg_vs_eta","myHoE_conedR0p15_bkg_vs_eta", 240,-3,3,0,15);

  //Jan9// #
  // all ele
  TH2D* h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap","h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel","h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap =new TProfile("prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap","prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel =new TProfile("prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel","prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel",200,0,200,0,200);
  //Jan9// #

  //Feb 1//
  // golden ele
  TH2D* h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden = new TH2D("h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden","h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden = new TH2D("h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden","h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden =new TProfile("prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden","prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden =new TProfile("prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden","prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //Feb 1//

  //// same plots vs ele pt instead of sc En //// Feb 13 ////
  // all ele
  TH2D* h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap = new TH2D("h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap","h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel = new TH2D("h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel","h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap =new TProfile("prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap","prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel =new TProfile("prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel","prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel",200,0,200,0,200);

  // golden ele
  TH2D* h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden",200,0,200,0,200);
  //
  TH2D* h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden = new TH2D("h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden","h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden",800,0,800,200,0,200);
  TH2D* h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden = new TH2D("h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden","h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden",800,0,800,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden =new TProfile("prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden","prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden",200,0,200,0,200);
  TProfile* prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden =new TProfile("prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden","prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden",200,0,200,0,200);

  // Feb 13 //


  TH2D* h2_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel = new TH2D("h2_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel", "h2_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel", 300,0,300,100,0,100);
  TH2D* h2_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap = new TH2D("h2_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap", "h2_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap", 300,0,300,100,0,100);
  TProfile* prof_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel = new TProfile("prof_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel", "prof_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel", 300,0,300,0,100);
  TProfile* prof_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap = new TProfile("prof_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap", "prof_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap", 300,0,300,0,100);
  // #

  //	  if (iele==0) 
  TH2D* h2_deltaR_vs_hrhE_sig_Barrel = new TH2D("h2_dR_hrhE_sig_Barrel", "dR_E_sig_Barrel", 100, 0, 1, 500, 0, 50);
  TProfile* prof_deltaR_vs_hrhE_sig_Barrel = new TProfile("prof_dR_hrhE_sig_Barrel", "p_dR_E_sig_Barrel", 100, 0, 1, 0, 50);
  TH2D* h2_elePt_vs_nhrh_sig_Barrel = new TH2D("h2_elePt_vs_nhrh_sig_Barrel", "h2_elePt_vs_nhrh_sig_Barrel", 300, 0, 300, 100, 0, 100);
  TH2D* h2_eleEta_vs_nhrh_sig_Barrel = new TH2D("h2_eleEta_vs_nhrh_sig_Barrel", "h2_eleEta_vs_nhrh_sig_Barrel", 600, -3, 3, 100, 0, 100);
  TH2D* h2_elePhi_vs_nhrh_sig_Barrel = new TH2D("h2_elePhi_vs_nhrh_sig_Barrel", "h2_elePhi_vs_nhrh_sig_Barrel", 800, -4, 4, 100, 0, 100);

  TH2D* h2_deltaR_vs_hrhE_sig_Endcap = new TH2D("h2_dR_hrhE_sig_Endcap", "dR_E_sig_Endcap", 200, 0, 2, 500, 0, 50);
  TProfile* prof_deltaR_vs_hrhE_sig_Endcap = new TProfile("prof_dR_hrhE_sig_Endcap", "p_dR_E_sig_Endcap", 200, 0, 2, 0, 50);
  TH2D* h2_elePt_vs_nhrh_sig_Endcap = new TH2D("h2_elePt_vs_nhrh_sig_Endcap", "h2_elePt_vs_nhrh_sig_Endcap", 300, 0, 300, 100, 0, 100);
  TH2D* h2_eleEta_vs_nhrh_sig_Endcap = new TH2D("h2_eleEta_vs_nhrh_sig_Endcap", "h2_eleEta_vs_nhrh_sig_Endcap", 600, -3, 3, 100, 0, 100);
  TH2D* h2_elePhi_vs_nhrh_sig_Endcap = new TH2D("h2_elePhi_vs_nhrh_sig_Endcap", "h2_elePhi_vs_nhrh_sig_Endcap", 800, -4, 4, 100, 0, 100);

  int Event_counter=0;
  int electron_counter=0;

  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    //for (Long64_t jentry=0; jentry<1000;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    //std::cout << "\n ******* New event " << std::endl;
    Event_counter++;
    /*
      std::cout << "first check if all vects have same size ... if not, we've got a problem " << std::endl;
      //
      std::cout <<       scEn_->size() << std::endl ;
      std::cout <<        eleSCRawEn_->size() << std::endl ;
      std::cout <<   ecalEn_->size() << std::endl ;
      std::cout <<    seedEn_->size() << std::endl ;
      std::cout <<    seedEnCorr_->size() << std::endl ;
      std::cout <<    cmssw_eleHoE_->size() << std::endl ;
      std::cout <<    cmssw_eleHoE_full5x5_->size() << std::endl ;
      std::cout <<    eleScEta_->size() << std::endl ;
      std::cout <<    elePt_->size() << std::endl ;
      std::cout <<     elePhi_->size() << std::endl ;
      std::cout <<    eleSigmaIEtaIEtaFull5x5_->size() << std::endl ;
      std::cout <<    elePFNeuIso_->size() << std::endl ;
      std::cout <<    elePFChIso_->size() << std::endl ;
      std::cout <<     eleSeedDet_->size() << std::endl ;
      std::cout <<    eleSeedSubdet_->size() << std::endl ;
      std::cout <<    eleSeedIeta_->size() << std::endl ;
      std::cout <<   eleSeedIphi_->size() << std::endl ;
      std::cout <<     eleSeedEta_->size() << std::endl ;
      std::cout <<    eleSeedPhi_->size() << std::endl ;
      std::cout <<     eleSeedRawID_->size() << std::endl ;
      std::cout <<     seedHcalIeta_->size() << std::endl ;
      std::cout <<      seedHcalIphi_->size() << std::endl ;
      std::cout <<     hcalRechitIeta_->size() << std::endl ;
      std::cout <<    hcalRechitIphi_->size() << std::endl ;
      std::cout <<     hcalRechitEnergy_->size() << std::endl ;
      std::cout <<   hcalRechitAbsDIetaFromEleSeed_->size() << std::endl ;
      std::cout <<    hcalRechitAbsDIphiFromEleSeed_->size() << std::endl ;
      std::cout <<     hcalRechitRawID_->size() << std::endl ;
      std::cout <<     hcalRechitDepth_->size() << std::endl ;
      std::cout <<     hcalRechitEta_->size() << std::endl ;
      std::cout <<    hcalRechitPhi_->size() << std::endl ;
      std::cout <<    puTrue_->size() << std::endl ;
      */
    
    //
    
    for(int iele=0; iele < elePt_->size(); iele++) {
      electron_counter++;
      //std::cout << "\n new ele with pT " << elePt_->at(iele) << " genmatched? " << ele_genmatched_->at(iele)  << std::endl;
      //std::cout << "Number of hcal rechit associated " << (hcalRechitEta_->at(iele)).size() << std::endl;
      int nhrh=(hcalRechitEta_->at(iele)).size() ;
      int nhrh_meaningful=0;
      //      int nhrh_0p30=0;
      //if (nhrh==0) std::cout << "This ele has no hcal energy deposit, so H/E=0" << std::endl;
      float this_DeltaR = 999.9;

	  float hcalE_0p70=0;
	  float hcalE_0p60=0;
	  float hcalE_0p50=0;
	  float hcalE_0p40=0;
	  float hcalE_0p25=0;
	  float hcalE_0p225=0;
	  float hcalE_0p08=0;
	  float hcalE_0p05=0;
	  float hcalE_0p10=0;
	  float hcalE_0p125=0;
	  float hcalE_0p175=0;

	  float hcalE_0p30=0;
	  float hcalE_0p30_d1=0;
	  float hcalE_0p30_d2=0;
	  float hcalE_0p30_d3=0;
	  float hcalE_0p30_d4=0;
	  float hcalE_0p30_d5=0;
	  float hcalE_0p30_d6=0;
	  float hcalE_0p30_d7=0;
	  float hcalE_0p30_d8=0;

	  float hcalE_0p20=0;
	  float hcalE_0p20_d1=0;
	  float hcalE_0p20_d2=0;
	  float hcalE_0p20_d3=0;
	  float hcalE_0p20_d4=0;
	  float hcalE_0p20_d5=0;
	  float hcalE_0p20_d6=0;
	  float hcalE_0p20_d7=0;
	  float hcalE_0p20_d8=0;

	  float hcalE_0p15=0;
	  float hcalE_0p15_d1=0;
	  float hcalE_0p15_d2=0;
	  float hcalE_0p15_d3=0;
	  float hcalE_0p15_d4=0;
	  float hcalE_0p15_d5=0;
	  float hcalE_0p15_d6=0;
	  float hcalE_0p15_d7=0;
	  float hcalE_0p15_d8=0;

      
	  for (int ihrh=0; ihrh<nhrh; ihrh++) {
	    float this_DeltaR = DeltaR(eleScEta_->at(iele), eleScPhi_->at(iele), hcalRechitEta_->at(iele).at(ihrh), hcalRechitPhi_->at(iele).at(ihrh)); 

	    if (this_DeltaR<0.6) nhrh_meaningful++;

	    if (this_DeltaR<0.3 && (ele_genmatched_->at(iele)==1) && (elePt_->at(iele)>50) ) {
	      //
	      if ( (fabs(eleScEta_->at(iele)) < 1.3) ) { //barrel
		h2_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel->Fill(scEn_->at(iele),hcalRechitEnergy_->at(iele).at(ihrh));
		prof_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel->Fill(scEn_->at(iele),hcalRechitEnergy_->at(iele).at(ihrh));
	      } // end barrel loop
	      //
	      if ( (fabs(eleScEta_->at(iele)) > 1.56)  &&  (fabs(eleScEta_->at(iele)) < 2.5 ) ) { //endcap
		h2_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap->Fill(scEn_->at(iele),hcalRechitEnergy_->at(iele).at(ihrh));
		prof_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap->Fill(scEn_->at(iele),hcalRechitEnergy_->at(iele).at(ihrh));
	      } // end endcap loop
	      //
	    }

	    if ( (ele_genmatched_->at(iele)==1) && (fabs(eleScEta_->at(iele)) < 1.3) )  {
	      h2_deltaR_vs_hrhE_sig_Barrel->Fill(this_DeltaR,hcalRechitEnergy_->at(iele).at(ihrh));
	      prof_deltaR_vs_hrhE_sig_Barrel->Fill(this_DeltaR,hcalRechitEnergy_->at(iele).at(ihrh));
	    }
	
	    if ( (ele_genmatched_->at(iele)==1) && (fabs(eleScEta_->at(iele)) > 1.56) && (fabs(eleScEta_->at(iele)) < 2.5 ) )  {
	      h2_deltaR_vs_hrhE_sig_Endcap->Fill(this_DeltaR,hcalRechitEnergy_->at(iele).at(ihrh));
	      prof_deltaR_vs_hrhE_sig_Endcap->Fill(this_DeltaR,hcalRechitEnergy_->at(iele).at(ihrh));
	    }
    
	  
	    if (this_DeltaR <= 0.15) {
	      hcalE_0p15 = hcalE_0p15+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      int hcal_depth=hcalRechitDepth_->at(iele).at(ihrh);
	      if (hcal_depth==1) {
		//std::cout << "d1, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d1=hcalE_0p15_d1+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      } 	 else if (hcal_depth==2) {
		//std::cout << "d2, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d2=hcalE_0p15_d2+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }  	 else if (hcal_depth==3) {
		//std::cout << "d3, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d3=hcalE_0p15_d3+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==4) {
		//std::cout << "d4, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d4=hcalE_0p15_d4+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==5) {
		//std::cout << "d5, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d5=hcalE_0p15_d5+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==6) {
		//std::cout << "d6, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d6=hcalE_0p15_d6+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==7) {
		//std::cout << "d7, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d7=hcalE_0p15_d7+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==8) {
		//std::cout << "d8, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p15_d8=hcalE_0p15_d8+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      } 
	    } //deltaR cone of 0.15
	    
	    // deltaR cone of 0.30
	    if (this_DeltaR <= 0.30) {
	      hcalE_0p30 = hcalE_0p30+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      //
              int hcal_depth=hcalRechitDepth_->at(iele).at(ihrh);
	      if (hcal_depth==1) {
		//std::cout << "d1, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d1=hcalE_0p30_d1+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      } 	 else if (hcal_depth==2) {
		//std::cout << "d2, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d2=hcalE_0p30_d2+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }  	 else if (hcal_depth==3) {
		//std::cout << "d3, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d3=hcalE_0p30_d3+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==4) {
		//std::cout << "d4, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d4=hcalE_0p30_d4+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==5) {
		//std::cout << "d5, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d5=hcalE_0p30_d5+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==6) {
		//std::cout << "d6, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d6=hcalE_0p30_d6+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==7) {
		//std::cout << "d7, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d7=hcalE_0p30_d7+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==8) {
		//std::cout << "d8, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p30_d8=hcalE_0p30_d8+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      } 
	      //
	    } //deltaR cone of 0.30

	    // deltaR cone of 0.40
	    if (this_DeltaR <= 0.40) {
	      hcalE_0p40 = hcalE_0p40+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.40

	    // deltaR cone of 0.50
	    if (this_DeltaR <= 0.50) {
	      hcalE_0p50 = hcalE_0p50+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.50

	    // deltaR cone of 0.60
	    if (this_DeltaR <= 0.60) {
	      hcalE_0p60 = hcalE_0p60+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.60

	    // deltaR cone of 0.70
	    if (this_DeltaR <= 0.70) {
	      hcalE_0p70 = hcalE_0p70+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.70
	    
	    // deltaR cone of 0.25
	    if (this_DeltaR <= 0.25) {
	      hcalE_0p25 = hcalE_0p25+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.25
	    
	    // deltaR cone of 0.225
	    if (this_DeltaR <= 0.225) {
	      hcalE_0p225 = hcalE_0p225+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.225
	    
	    // deltaR cone of 0.20
	    if (this_DeltaR <= 0.20) {
	      hcalE_0p20 = hcalE_0p20+hcalRechitEnergy_->at(iele).at(ihrh) ;
              int hcal_depth=hcalRechitDepth_->at(iele).at(ihrh);
	      if (hcal_depth==1) {
		//std::cout << "d1, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d1=hcalE_0p20_d1+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      } 	 else if (hcal_depth==2) {
		//std::cout << "d2, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d2=hcalE_0p20_d2+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }  	 else if (hcal_depth==3) {
		//std::cout << "d3, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d3=hcalE_0p20_d3+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==4) {
		//std::cout << "d4, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d4=hcalE_0p20_d4+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==5) {
		//std::cout << "d5, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d5=hcalE_0p20_d5+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==6) {
		//std::cout << "d6, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d6=hcalE_0p20_d6+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==7) {
		//std::cout << "d7, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d7=hcalE_0p20_d7+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      }    else if (hcal_depth==8) {
		//std::cout << "d8, recHitEn=" << hcalRechitEnergy_->at(iele).at(ihrh) << std::endl ;
		hcalE_0p20_d8=hcalE_0p20_d8+hcalRechitEnergy_->at(iele).at(ihrh) ;
	      } 

	    } //deltaR cone of 0.20
	    
	    // deltaR cone of 0.10
	    if (this_DeltaR <= 0.10) {
	      hcalE_0p10 = hcalE_0p10+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.10

	    // deltaR cone of 0.08
	    if (this_DeltaR <= 0.08) {
	      hcalE_0p08 = hcalE_0p08+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.08

	    // deltaR cone of 0.125
	    if (this_DeltaR <= 0.125) {
	      hcalE_0p125 = hcalE_0p125+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.125

	    // deltaR cone of 0.175
	    if (this_DeltaR <= 0.175) {
	      hcalE_0p175 = hcalE_0p175+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.125

	    // deltaR cone of 0.05
	    if (this_DeltaR <= 0.05) {
	      hcalE_0p05 = hcalE_0p05+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } //deltaR cone of 0.05
	    
	    
	    //  std::cout << "ele eta, phi " << eleSeedEta_->at(iele) << " , " << eleSeedPhi_->at(iele) << std::endl;
	    // std::cout << "hcal rechit eta, phi " << hcalRechitEta_->at(iele).at(ihrh) << " , " << hcalRechitPhi_->at(iele).at(ihrh) << std::endl;
	    // std::cout << "ihrh " << ihrh << " dR " << this_DeltaR << std::endl;
	    
	    
	  } // hcal rechit loop ends //
	  

	  float HoE_0p70 = hcalE_0p70/(ecalEn_->at(iele));
	  float HoE_0p60 = hcalE_0p60/(ecalEn_->at(iele));
	  float HoE_0p50 = hcalE_0p50/(ecalEn_->at(iele));
	  float HoE_0p40 = hcalE_0p40/(ecalEn_->at(iele));
	  float HoE_0p30 = hcalE_0p30/(ecalEn_->at(iele));
	  float HoE_0p25 = hcalE_0p25/(ecalEn_->at(iele));
	  float HoE_0p20 = hcalE_0p20/(ecalEn_->at(iele));
	  float HoE_0p10 = hcalE_0p10/(ecalEn_->at(iele));

	  //Jan9
	  float H0p3mH0p05 =  hcalE_0p30-hcalE_0p05;
	  float H0p3mH0p08 =  hcalE_0p30-hcalE_0p08;
	  float H0p3mH0p1 =  hcalE_0p30-hcalE_0p10;
	  float H0p3mH0p125 =  hcalE_0p30-hcalE_0p125;
	  float H0p3mH0p15 =  hcalE_0p30-hcalE_0p15;
	  float H0p3mH0p175 =  hcalE_0p30-hcalE_0p175;
	  float H0p3mH0p25 =  hcalE_0p30-hcalE_0p25;
	  float H0p3mH0p225 =  hcalE_0p30-hcalE_0p225;

	  float H0p3mH0p2 =  hcalE_0p30-hcalE_0p20;
	  float H0p3mH0p2_d1 =  hcalE_0p30_d1-hcalE_0p20_d1;
	  float H0p3mH0p2_d2 =  hcalE_0p30_d2-hcalE_0p20_d2;
	  float H0p3mH0p2_d3 =  hcalE_0p30_d3-hcalE_0p20_d3;
	  float H0p3mH0p2_d4 =  hcalE_0p30_d4-hcalE_0p20_d4;
	  float H0p3mH0p2_d5 =  hcalE_0p30_d5-hcalE_0p20_d5;
	  float H0p3mH0p2_d6 =  hcalE_0p30_d6-hcalE_0p20_d6;
	  float H0p3mH0p2_d7 =  hcalE_0p30_d7-hcalE_0p20_d7;
	  float H0p3mH0p2_d8 =  hcalE_0p30_d8-hcalE_0p20_d8;
	  //
	  
	  float HoE_0p15 = hcalE_0p15/(ecalEn_->at(iele));
	  float HoE_0p15_d1 = hcalE_0p15_d1/(ecalEn_->at(iele));
	  float HoE_0p15_d2 = hcalE_0p15_d2/(ecalEn_->at(iele));
	  float HoE_0p15_d3 = hcalE_0p15_d3/(ecalEn_->at(iele));
	  float HoE_0p15_d4 = hcalE_0p15_d4/(ecalEn_->at(iele));
	  float HoE_0p15_d5 = hcalE_0p15_d5/(ecalEn_->at(iele));
	  float HoE_0p15_d6 = hcalE_0p15_d6/(ecalEn_->at(iele));
	  float HoE_0p15_d7 = hcalE_0p15_d7/(ecalEn_->at(iele));
	  float HoE_0p15_d8 = hcalE_0p15_d8/(ecalEn_->at(iele));

	  float H_D2overD1_0p15=hcalE_0p15_d2/hcalE_0p15_d1 ;
	  float H_D3overD1_0p15=hcalE_0p15_d3/hcalE_0p15_d1 ;
	  float H_D4overD1_0p15=hcalE_0p15_d4/hcalE_0p15_d1 ;
	  float H_D5overD1_0p15=hcalE_0p15_d5/hcalE_0p15_d1 ;
	  
	  //std::cout << "hcalE_0p15 = " << hcalE_0p15 << " my H/E " << HoE_0p15 << " cmssw_eleHoE_full5x5_ " << cmssw_eleHoE_full5x5_->at(iele) 
	  //<< " cmssw_eleHoE_" << cmssw_eleHoE_->at(iele) << std::endl;
	  
	  //Barrel+Endcap, 
	  h1_myHoE_conedR0p15_allEle_fullEta->Fill(HoE_0p15);
	  
	  if ( (elePt_->at(iele) > 2) && (elePt_->at(iele) < 30000) ) { // ele pt > 2
	    
	    if (( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && (hcalE_0p15>1) ) {
	      h2D_myH_conedR0p15_sig_vs_eta_phi->Fill(eleScEta_->at(iele),eleScPhi_->at(iele));
	    }

	    if (( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && (hcalE_0p15>2) ) {
	      h2D_myH2_conedR0p15_sig_vs_eta_phi->Fill(eleScEta_->at(iele),eleScPhi_->at(iele));
	    }

	    if (( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && (H0p3mH0p1>1) ) {
	     h2D_myH_RingAnnular_0p3m0p1_sig_vs_eta_phi->Fill(eleScEta_->at(iele),eleScPhi_->at(iele));
	     h1D_myH_RingAnnular_0p3m0p1_sig_eta->Fill(eleScEta_->at(iele));
	     h1D_myH_RingAnnular_0p3m0p1_sig_phi->Fill(eleScPhi_->at(iele));
	     h1D_myH_RingAnnular_0p3m0p1_sig_genpt->Fill(eleGenPt_->at(iele));
	     h1D_myH_RingAnnular_0p3m0p1_sig_ptR_by_ptG->Fill((elePt_->at(iele)/eleGenPt_->at(iele)));
	     h1D_myH_RingAnnular_0p3m0p1_sig_R9->Fill(ele_full5x5_r9_->at(iele));
	    }

	    if (( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && (H0p3mH0p1>2) ) {
	     h2D_myH2_RingAnnular_0p3m0p1_sig_vs_eta_phi->Fill(eleScEta_->at(iele),eleScPhi_->at(iele));
	     h1D_myH2_RingAnnular_0p3m0p1_sig_eta->Fill(eleScEta_->at(iele));
	     h1D_myH2_RingAnnular_0p3m0p1_sig_phi->Fill(eleScPhi_->at(iele));
	     h1D_myH2_RingAnnular_0p3m0p1_sig_genpt->Fill(eleGenPt_->at(iele));
	     h1D_myH2_RingAnnular_0p3m0p1_sig_ptR_by_ptG->Fill((elePt_->at(iele)/eleGenPt_->at(iele)));
	     h1D_myH2_RingAnnular_0p3m0p1_sig_R9->Fill(ele_full5x5_r9_->at(iele));
	    }

	    //Barrel
	    if ( fabs(eleScEta_->at(iele)) < 1.3 ) {
	      prof_myHoE_conedR0p15_allEle_Barrel_vs_pt->Fill(elePt_->at(iele),HoE_0p15);
	      h1_myHoE_conedR0p15_allEle_Barrel->Fill(HoE_0p15);
	      h1_myHoE_conedR0p15_allEle_Barrel_Depth1->Fill(HoE_0p15_d1);
	      h1_myHoE_conedR0p15_allEle_Barrel_Depth2->Fill(HoE_0p15_d2);
	      
	      if ( ele_genmatched_->at(iele)==1 ) { //signal
		h2_elePt_vs_nhrh_sig_Barrel->Fill(elePt_->at(iele),nhrh_meaningful);
		h2_eleEta_vs_nhrh_sig_Barrel->Fill(eleScEta_->at(iele),nhrh_meaningful);
		h2_elePhi_vs_nhrh_sig_Barrel->Fill(elePhi_->at(iele),nhrh_meaningful);

		//Jan9
		if ( ( eleGenPt_->at(iele) > 50 ) ) {

		  h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p05);
		  prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p05);
		  h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		  prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		  //
		  h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p08);
		  prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p08);
		  h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		  prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		  //
		  h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p1);
		  prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p1);
		  h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		  prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		  //
		  h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p125);
		  prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p125);
		  h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		  prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		  //
		  h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p175);
		  prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p175);
		  h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		  prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		  //
		  h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p15);
		  prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p15);
		  h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		  prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		  //
		  h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p2);
		  prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p2);
		  h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		  prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		  //
		  h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p25);
		  prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p25);
		  h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		  prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		  //
		  h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p225);
		  prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel->Fill(ecalEn_->at(iele),H0p3mH0p225);
		  h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p225);
		  prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel->Fill(eleGenPt_->at(iele),H0p3mH0p225);

		  if ( ele_full5x5_r9_->at(iele) > 0.9 ) {

		    //if (H0p3mH0p1>1) {
		      //		      std::cout << "H0p3mH0p1 " << H0p3mH0p1 << " ele gen pt " << eleGenPt_->at(iele) << " ele reco pt "<< elePt_->at(iele) << " Run/Lumi/Event " << run_number_->at(0) << "/" << lumi_number_->at(0) << "/" << event_number_->at(0) << " eleSCeta " << eleScEta_->at(iele) << std::endl;
 		    //}

		   		    
		    h1_myH_conedR0p15_sig_Barrel->Fill(hcalE_0p15);
		    prof_myH_conedR0p15_sig_Barrel_vs_pt->Fill(eleGenPt_->at(iele),hcalE_0p15);
		    prof_myH_conedR0p15_sig_Barrel_vs_eta->Fill(eleScEta_->at(iele),hcalE_0p15);
		    prof_myH_conedR0p15_sig_Barrel_vs_phi->Fill(eleScPhi_->at(iele),hcalE_0p15);

		    prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt->Fill(eleGenPt_->at(iele),hcalE_0p20);
		    prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d1->Fill(eleGenPt_->at(iele),hcalE_0p20_d1);
		    prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d2->Fill(eleGenPt_->at(iele),hcalE_0p20_d2);
		    prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d3->Fill(eleGenPt_->at(iele),hcalE_0p20_d3);
		    prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d4->Fill(eleGenPt_->at(iele),hcalE_0p20_d4);

		    prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d1->Fill(eleGenPt_->at(iele),H0p3mH0p2_d1);
		    prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d2->Fill(eleGenPt_->at(iele),H0p3mH0p2_d2);
		    prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d3->Fill(eleGenPt_->at(iele),H0p3mH0p2_d3);
		    prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d4->Fill(eleGenPt_->at(iele),H0p3mH0p2_d4);
		    
		    h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p05);
		    prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p05);
		    h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		    prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		    //
		    h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p08);
		    prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p08);
		    h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		    prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		    //
		    h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p1);
		    prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p1);
		    h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		    prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		    //
		    h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p125);
		    prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p125);
		    h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		    prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		    //
		    h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p175);
		    prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p175);
		    h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		    prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		    //
		    h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p15);
		    prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p15);
		    h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		    prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		    //
		    h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p2);
		    prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p2);
		    h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		    prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		    //
		    h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p25);
		    prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p25);
		    h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		    prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		    //
		    h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p225);
		    prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Fill(ecalEn_->at(iele),H0p3mH0p225);
		    h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p225);
		    prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Fill(eleGenPt_->at(iele),H0p3mH0p225);
		    
		  }

		}
		//Jan9

		h1_myHoE_conedR0p70_sig_Barrel->Fill(HoE_0p70);
		h1_myHoE_conedR0p60_sig_Barrel->Fill(HoE_0p60);
		h1_myHoE_conedR0p50_sig_Barrel->Fill(HoE_0p50);
		h1_myHoE_conedR0p40_sig_Barrel->Fill(HoE_0p40);
		h1_myHoE_conedR0p30_sig_Barrel->Fill(HoE_0p30);
		h1_myHoE_conedR0p25_sig_Barrel->Fill(HoE_0p25);
		h1_myHoE_conedR0p20_sig_Barrel->Fill(HoE_0p20);
		h1_myHoE_conedR0p10_sig_Barrel->Fill(HoE_0p10);
	      
		h1_cmsswHoE_conedR0p15_sig_Barrel->Fill(cmssw_eleHoE_->at(iele));
		h1_cmsswfull5x5HoE_conedR0p15_sig_Barrel->Fill(cmssw_eleHoE_full5x5_->at(iele));
		h1_myHoE_conedR0p15_sig_Barrel->Fill(HoE_0p15);
		h1_myHoE_conedR0p15_sig_Barrel_Depth1->Fill(HoE_0p15_d1);
		h1_myHoE_conedR0p15_sig_Barrel_Depth2->Fill(HoE_0p15_d2);
		h1_myHoE_conedR0p15_sig_Barrel_Depth3->Fill(HoE_0p15_d3);
		h1_myHoE_conedR0p15_sig_Barrel_Depth4->Fill(HoE_0p15_d4);
		h1_myHoE_conedR0p15_sig_Barrel_Depth5->Fill(HoE_0p15_d5);
		h1_myHoE_conedR0p15_sig_Barrel_Depth6->Fill(HoE_0p15_d6);
		h1_myHoE_conedR0p15_sig_Barrel_Depth7->Fill(HoE_0p15_d7);
		h1_myHoE_conedR0p15_sig_Barrel_Depth8->Fill(HoE_0p15_d8);
		
		h1_H_D2overD1_conedR0p15_sig_Barrel->Fill(H_D2overD1_0p15);
		h1_H_D3overD1_conedR0p15_sig_Barrel->Fill(H_D3overD1_0p15);
		h1_H_D4overD1_conedR0p15_sig_Barrel->Fill(H_D4overD1_0p15);
		h1_H_D5overD1_conedR0p15_sig_Barrel->Fill(H_D5overD1_0p15);
		
		prof_myHoE_conedR0p15_sig_vs_eta->Fill(eleScEta_->at(iele),HoE_0p15);
		prof_myHoE_conedR0p30_sig_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p30);
		prof_myHoE_conedR0p25_sig_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p25);
		prof_myHoE_conedR0p20_sig_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p20);
		prof_myHoE_conedR0p15_sig_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p15);
		prof_myHoE_conedR0p10_sig_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p10);
		prof_cmsswHoE_conedR0p15_sig_Barrel_vs_PU->Fill(puTrue_->at(0),cmssw_eleHoE_->at(iele));
		prof_cmsswfull5x5HoE_conedR0p15_sig_Barrel_vs_PU->Fill(puTrue_->at(0),cmssw_eleHoE_full5x5_->at(iele));

	      }
	      
	      else if ( ele_genmatched_->at(iele)==0 ) { //background
		h1_myHoE_conedR0p70_bkg_Barrel->Fill(HoE_0p70);
		h1_myHoE_conedR0p60_bkg_Barrel->Fill(HoE_0p60);
		h1_myHoE_conedR0p50_bkg_Barrel->Fill(HoE_0p50);
		h1_myHoE_conedR0p40_bkg_Barrel->Fill(HoE_0p40);
		h1_myHoE_conedR0p30_bkg_Barrel->Fill(HoE_0p30);
		h1_myHoE_conedR0p25_bkg_Barrel->Fill(HoE_0p25);
		h1_myHoE_conedR0p20_bkg_Barrel->Fill(HoE_0p20);
		h1_myHoE_conedR0p10_bkg_Barrel->Fill(HoE_0p10);
		h1_myHoE_conedR0p15_bkg_Barrel->Fill(HoE_0p15);
		h1_cmsswHoE_conedR0p15_bkg_Barrel->Fill(cmssw_eleHoE_->at(iele));
		h1_cmsswfull5x5HoE_conedR0p15_bkg_Barrel->Fill(cmssw_eleHoE_full5x5_->at(iele));
		h1_myHoE_conedR0p15_bkg_Barrel_Depth1->Fill(HoE_0p15_d1);
		h1_myHoE_conedR0p15_bkg_Barrel_Depth2->Fill(HoE_0p15_d2);
		h1_myHoE_conedR0p15_bkg_Barrel_Depth3->Fill(HoE_0p15_d3);
		h1_myHoE_conedR0p15_bkg_Barrel_Depth4->Fill(HoE_0p15_d4);
		h1_myHoE_conedR0p15_bkg_Barrel_Depth5->Fill(HoE_0p15_d5);
		h1_myHoE_conedR0p15_bkg_Barrel_Depth6->Fill(HoE_0p15_d6);
		h1_myHoE_conedR0p15_bkg_Barrel_Depth7->Fill(HoE_0p15_d7);
		h1_myHoE_conedR0p15_bkg_Barrel_Depth8->Fill(HoE_0p15_d8);
		
		h1_H_D2overD1_conedR0p15_bkg_Barrel->Fill(H_D2overD1_0p15);
		h1_H_D3overD1_conedR0p15_bkg_Barrel->Fill(H_D3overD1_0p15);
		h1_H_D4overD1_conedR0p15_bkg_Barrel->Fill(H_D4overD1_0p15);
		h1_H_D5overD1_conedR0p15_bkg_Barrel->Fill(H_D5overD1_0p15);
		
		prof_myHoE_conedR0p15_bkg_vs_eta->Fill(eleScEta_->at(iele),HoE_0p15);
		prof_myHoE_conedR0p30_bkg_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p30);
		prof_myHoE_conedR0p25_bkg_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p25);
		prof_myHoE_conedR0p20_bkg_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p20);
		prof_myHoE_conedR0p10_bkg_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p10);
		prof_myHoE_conedR0p15_bkg_Barrel_vs_PU->Fill(puTrue_->at(0),HoE_0p15);
		
	      }
	      
	    }
	    
	    //Endcap
	    if ( (fabs(eleScEta_->at(iele)) > 1.56) && (fabs(eleScEta_->at(iele)) < 2.5 )  ) {
	      h1_myHoE_conedR0p15_allEle_Endcap->Fill(HoE_0p15);
	      
	      if ( ele_genmatched_->at(iele)==1 ) { //signal
		h2_elePt_vs_nhrh_sig_Endcap->Fill(elePt_->at(iele),nhrh_meaningful);
		h2_eleEta_vs_nhrh_sig_Endcap->Fill(eleScEta_->at(iele),nhrh_meaningful);
		h2_elePhi_vs_nhrh_sig_Endcap->Fill(elePhi_->at(iele),nhrh_meaningful);

		//Jan9//
		if ( eleGenPt_->at(iele) > 50 ) {

		  h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p05);
		  prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p05);
		  h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		  prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		  //
		  h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p08);
		  prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p08);
		  h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		  prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		  //
		  h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p1);
		  prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p1);
		  h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		  prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		  //
		  h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p125);
		  prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p125);
		  h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		  prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		  //
		  h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p175);
		  prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p175);
		  h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		  prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		  //
		  h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p15);
		  prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p15);
		  h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		  prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		  //
		  h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p2);
		  prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p2);
		  h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		  prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		  //
		  h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p25);
		  prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p25);
		  h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		  prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		  //
		  h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p225);
		  prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap->Fill(ecalEn_->at(iele),H0p3mH0p225);
		  h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p225);
		  prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap->Fill(eleGenPt_->at(iele),H0p3mH0p225);
		  
		  if (  ele_full5x5_r9_->at(iele) > 0.9  ) {

		    //		    if (H0p3mH0p1>1) {
		    // std::cout << "H0p3mH0p1 " << H0p3mH0p1 << " ele gen pt " << eleGenPt_->at(iele) << " ele reco pt "<< elePt_->at(iele) << " Run/Lumi/Event " << run_number_->at(0) << "/" << lumi_number_->at(0) << "/" << event_number_->at(0) << " eleSCeta " << eleScEta_->at(iele) << std::endl;
		    // }


		    h1_myH_conedR0p15_sig_Endcap->Fill(hcalE_0p15);
		    prof_myH_conedR0p15_sig_Endcap_vs_pt->Fill(eleGenPt_->at(iele),hcalE_0p15);
		    prof_myH_conedR0p15_sig_Endcap_vs_eta->Fill(eleScEta_->at(iele),hcalE_0p15);
		    prof_myH_conedR0p15_sig_Endcap_vs_phi->Fill(eleScPhi_->at(iele),hcalE_0p15);

		    //
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt->Fill(eleGenPt_->at(iele),hcalE_0p20);
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d1->Fill(eleGenPt_->at(iele),hcalE_0p20_d1);
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d2->Fill(eleGenPt_->at(iele),hcalE_0p20_d2);
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d3->Fill(eleGenPt_->at(iele),hcalE_0p20_d3);
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d4->Fill(eleGenPt_->at(iele),hcalE_0p20_d4);
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d5->Fill(eleGenPt_->at(iele),hcalE_0p20_d5);
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d6->Fill(eleGenPt_->at(iele),hcalE_0p20_d6);
		    prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d7->Fill(eleGenPt_->at(iele),hcalE_0p20_d7);

		    prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d1->Fill(eleGenPt_->at(iele),H0p3mH0p2_d1);
		    prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d2->Fill(eleGenPt_->at(iele),H0p3mH0p2_d2);
		    prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d3->Fill(eleGenPt_->at(iele),H0p3mH0p2_d3);
		    prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d4->Fill(eleGenPt_->at(iele),H0p3mH0p2_d4);
		    prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d5->Fill(eleGenPt_->at(iele),H0p3mH0p2_d5);
		    prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d6->Fill(eleGenPt_->at(iele),H0p3mH0p2_d6);
		    prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d7->Fill(eleGenPt_->at(iele),H0p3mH0p2_d7);
		    //

		    h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p05);
		    prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p05);
		    h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		    prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p05);
		    //
		    h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p08);
		    prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p08);
		    h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		    prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p08);
		    //
		    h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p1);
		    prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p1);
		    h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		    prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p1);
		    //
		    h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p125);
		    prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p125);
		    h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		    prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p125);
		    //
		    h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p175);
		    prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p175);
		    h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		    prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p175);
		    //
		    h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p15);
		    prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p15);
		    h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		    prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p15);
		    //
		    h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p2);
		    prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p2);
		    h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		    prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p2);
		    //
		    h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p25);
		    prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p25);
		    h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		    prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p25);
		    //
		    h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p225);
		    prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Fill(ecalEn_->at(iele),H0p3mH0p225);
		    h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p225);
		    prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Fill(eleGenPt_->at(iele),H0p3mH0p225);
		    
		  }

		}

		//
		h1_myHoE_conedR0p70_sig_Endcap->Fill(HoE_0p70);
		h1_myHoE_conedR0p60_sig_Endcap->Fill(HoE_0p60);
		h1_myHoE_conedR0p50_sig_Endcap->Fill(HoE_0p50);
		h1_myHoE_conedR0p40_sig_Endcap->Fill(HoE_0p40);
		h1_myHoE_conedR0p30_sig_Endcap->Fill(HoE_0p30);
		h1_myHoE_conedR0p25_sig_Endcap->Fill(HoE_0p25);
		h1_myHoE_conedR0p20_sig_Endcap->Fill(HoE_0p20);
		h1_myHoE_conedR0p10_sig_Endcap->Fill(HoE_0p10);
		h1_cmsswHoE_conedR0p15_sig_Endcap->Fill(cmssw_eleHoE_->at(iele));
		h1_cmsswfull5x5HoE_conedR0p15_sig_Endcap->Fill(cmssw_eleHoE_full5x5_->at(iele));
		h1_myHoE_conedR0p15_sig_Endcap->Fill(HoE_0p15);
		h1_myHoE_conedR0p15_sig_Endcap_Depth1->Fill(HoE_0p15_d1);
		h1_myHoE_conedR0p15_sig_Endcap_Depth2->Fill(HoE_0p15_d2);
		h1_myHoE_conedR0p15_sig_Endcap_Depth3->Fill(HoE_0p15_d3);
		h1_myHoE_conedR0p15_sig_Endcap_Depth4->Fill(HoE_0p15_d4);
		h1_myHoE_conedR0p15_sig_Endcap_Depth5->Fill(HoE_0p15_d5);
		h1_myHoE_conedR0p15_sig_Endcap_Depth6->Fill(HoE_0p15_d6);
		h1_myHoE_conedR0p15_sig_Endcap_Depth7->Fill(HoE_0p15_d7);
		h1_myHoE_conedR0p15_sig_Endcap_Depth8->Fill(HoE_0p15_d8);
		
		h1_H_D2overD1_conedR0p15_sig_Endcap->Fill(H_D2overD1_0p15);
		h1_H_D3overD1_conedR0p15_sig_Endcap->Fill(H_D3overD1_0p15);
		h1_H_D4overD1_conedR0p15_sig_Endcap->Fill(H_D4overD1_0p15);
		h1_H_D5overD1_conedR0p15_sig_Endcap->Fill(H_D5overD1_0p15);
		
		prof_myHoE_conedR0p15_sig_vs_eta->Fill(eleScEta_->at(iele),HoE_0p15);	    
		prof_myHoE_conedR0p30_sig_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p30);
		prof_myHoE_conedR0p25_sig_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p25);
		prof_myHoE_conedR0p20_sig_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p20);
		prof_myHoE_conedR0p10_sig_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p10);
		prof_myHoE_conedR0p15_sig_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p15);

		prof_cmsswHoE_conedR0p15_sig_Endcap_vs_PU->Fill(puTrue_->at(0),cmssw_eleHoE_->at(iele));
		prof_cmsswfull5x5HoE_conedR0p15_sig_Endcap_vs_PU->Fill(puTrue_->at(0),cmssw_eleHoE_full5x5_->at(iele));
	      
	      }
	      
	      else if ( ele_genmatched_->at(iele)==0 ) { //background
		h1_myHoE_conedR0p70_bkg_Endcap->Fill(HoE_0p70);
		h1_myHoE_conedR0p60_bkg_Endcap->Fill(HoE_0p60);
		h1_myHoE_conedR0p50_bkg_Endcap->Fill(HoE_0p50);
		h1_myHoE_conedR0p40_bkg_Endcap->Fill(HoE_0p40);
		h1_myHoE_conedR0p30_bkg_Endcap->Fill(HoE_0p30);
		h1_myHoE_conedR0p25_bkg_Endcap->Fill(HoE_0p25);
		h1_myHoE_conedR0p20_bkg_Endcap->Fill(HoE_0p20);
		h1_myHoE_conedR0p10_bkg_Endcap->Fill(HoE_0p10);
		h1_myHoE_conedR0p15_bkg_Endcap->Fill(HoE_0p15);
		h1_cmsswHoE_conedR0p15_bkg_Endcap->Fill(cmssw_eleHoE_->at(iele));
		h1_cmsswfull5x5HoE_conedR0p15_bkg_Endcap->Fill(cmssw_eleHoE_full5x5_->at(iele));

		h1_myHoE_conedR0p15_bkg_Endcap_Depth1->Fill(HoE_0p15_d1);
		h1_myHoE_conedR0p15_bkg_Endcap_Depth2->Fill(HoE_0p15_d2);
		h1_myHoE_conedR0p15_bkg_Endcap_Depth3->Fill(HoE_0p15_d3);
		h1_myHoE_conedR0p15_bkg_Endcap_Depth4->Fill(HoE_0p15_d4);
		h1_myHoE_conedR0p15_bkg_Endcap_Depth5->Fill(HoE_0p15_d5);
		h1_myHoE_conedR0p15_bkg_Endcap_Depth6->Fill(HoE_0p15_d6);
		h1_myHoE_conedR0p15_bkg_Endcap_Depth7->Fill(HoE_0p15_d7);
		h1_myHoE_conedR0p15_bkg_Endcap_Depth8->Fill(HoE_0p15_d8);
		
		h1_H_D2overD1_conedR0p15_bkg_Endcap->Fill(H_D2overD1_0p15);
		h1_H_D3overD1_conedR0p15_bkg_Endcap->Fill(H_D3overD1_0p15);
		h1_H_D4overD1_conedR0p15_bkg_Endcap->Fill(H_D4overD1_0p15);
		h1_H_D5overD1_conedR0p15_bkg_Endcap->Fill(H_D5overD1_0p15);
		
		prof_myHoE_conedR0p15_bkg_vs_eta->Fill(eleScEta_->at(iele),HoE_0p15);	    
		prof_myHoE_conedR0p30_bkg_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p30);
		prof_myHoE_conedR0p25_bkg_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p25);
		prof_myHoE_conedR0p20_bkg_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p20);
		prof_myHoE_conedR0p10_bkg_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p10);
		prof_myHoE_conedR0p15_bkg_Endcap_vs_PU->Fill(puTrue_->at(0),HoE_0p15);
		
	      }
	      
	    }
	    
	    
	    
	  } //ele pt cut end
	  
	  
      } //electron loop
      
   }

  h1D_myH_RingAnnular_0p3m0p1_sig_R9->Write();
  h1D_myH2_RingAnnular_0p3m0p1_sig_R9->Write();

  h1D_myH_RingAnnular_0p3m0p1_sig_eta->Write();
  h1D_myH2_RingAnnular_0p3m0p1_sig_eta->Write();

  h1D_myH_RingAnnular_0p3m0p1_sig_phi->Write();
  h1D_myH2_RingAnnular_0p3m0p1_sig_phi->Write();

  h1D_myH_RingAnnular_0p3m0p1_sig_genpt->Write();
  h1D_myH2_RingAnnular_0p3m0p1_sig_genpt->Write();

  h1D_myH_RingAnnular_0p3m0p1_sig_ptR_by_ptG->Write();
  h1D_myH2_RingAnnular_0p3m0p1_sig_ptR_by_ptG->Write();

  h2D_myH_RingAnnular_0p3m0p1_sig_vs_eta_phi->Write();
  h2D_myH2_RingAnnular_0p3m0p1_sig_vs_eta_phi->Write();
  h2D_myH_conedR0p15_sig_vs_eta_phi->Write();
  h2D_myH2_conedR0p15_sig_vs_eta_phi->Write();
  prof_myH_conedR0p15_sig_Barrel_vs_pt->Write();
  prof_myH_conedR0p15_sig_Endcap_vs_pt->Write();
  prof_myH_conedR0p15_sig_Barrel_vs_eta->Write();
  prof_myH_conedR0p15_sig_Endcap_vs_eta->Write();
  prof_myH_conedR0p15_sig_Barrel_vs_phi->Write();
  prof_myH_conedR0p15_sig_Endcap_vs_phi->Write();
  h1_myH_conedR0p15_sig_Endcap->Write();
  h1_myH_conedR0p15_sig_Barrel->Write();

  prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt->Write();
  prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d1->Write();
  prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d2->Write();
  prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d3->Write();
  prof_myH_conedR0p20_Pt50_sig_Barrel_golden_vs_pt_d4->Write();

  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt->Write();
  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d1->Write();
  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d2->Write();
  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d3->Write();
  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d4->Write();
  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d5->Write();
  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d6->Write();
  prof_myH_conedR0p20_Pt50_sig_Endcap_golden_vs_pt_d7->Write();

  prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d1->Write();
  prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d2->Write();
  prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d3->Write();
  prof_H0p3mH0p2_Pt50_sig_Barrel_golden_vs_pt_d4->Write();

  prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d1->Write();
  prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d2->Write();
  prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d3->Write();
  prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d4->Write();
  prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d5->Write();
  prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d6->Write();
  prof_H0p3mH0p2_Pt50_sig_Endcap_golden_vs_pt_d7->Write();

  h2_elePt_vs_nhrh_sig_Barrel->Write();
  h2_elePt_vs_nhrh_sig_Endcap->Write();

   h2_eleEta_vs_nhrh_sig_Barrel->Write();
   h2_eleEta_vs_nhrh_sig_Endcap->Write();

   h2_elePhi_vs_nhrh_sig_Barrel->Write();
   h2_elePhi_vs_nhrh_sig_Endcap->Write();

   h2_deltaR_vs_hrhE_sig_Barrel->Write();
   prof_deltaR_vs_hrhE_sig_Barrel->Write();

   h2_deltaR_vs_hrhE_sig_Endcap->Write();
   prof_deltaR_vs_hrhE_sig_Endcap->Write();

   h1_myHoE_conedR0p15_allEle_fullEta->Write();
   h1_myHoE_conedR0p15_allEle_Barrel->Write();
   h1_myHoE_conedR0p15_allEle_Barrel_Depth1->Write();
   h1_myHoE_conedR0p15_allEle_Barrel_Depth2->Write();
   h1_myHoE_conedR0p15_allEle_Endcap->Write();
   prof_myHoE_conedR0p15_allEle_Barrel_vs_pt->Write();
   prof_myHoE_conedR0p15_sig_vs_eta->Write();
   prof_myHoE_conedR0p15_bkg_vs_eta->Write();

   h1_myHoE_conedR0p70_bkg_Barrel->Write();
   h1_myHoE_conedR0p60_bkg_Barrel->Write();
   h1_myHoE_conedR0p50_bkg_Barrel->Write();
   h1_myHoE_conedR0p40_bkg_Barrel->Write();
   h1_myHoE_conedR0p30_bkg_Barrel->Write();
   h1_myHoE_conedR0p25_bkg_Barrel->Write();
   h1_myHoE_conedR0p20_bkg_Barrel->Write();
  
   h1_myHoE_conedR0p15_bkg_Barrel->Write();
   h1_cmsswHoE_conedR0p15_bkg_Barrel->Write();
   h1_cmsswfull5x5HoE_conedR0p15_bkg_Barrel->Write();

   h1_myHoE_conedR0p10_bkg_Barrel->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth1->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth2->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth3->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth4->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth5->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth6->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth7->Write();
   h1_myHoE_conedR0p15_bkg_Barrel_Depth8->Write();
   h1_H_D2overD1_conedR0p15_bkg_Barrel->Write();
   h1_H_D3overD1_conedR0p15_bkg_Barrel->Write();
   h1_H_D4overD1_conedR0p15_bkg_Barrel->Write();
   h1_H_D5overD1_conedR0p15_bkg_Barrel->Write();
   prof_myHoE_conedR0p10_bkg_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p15_bkg_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p20_bkg_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p25_bkg_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p30_bkg_Barrel_vs_PU->Write();

   prof_cmsswHoE_conedR0p15_sig_Barrel_vs_PU->Write();
   prof_cmsswHoE_conedR0p15_sig_Endcap_vs_PU->Write();

   prof_cmsswfull5x5HoE_conedR0p15_sig_Barrel_vs_PU->Write();
   prof_cmsswfull5x5HoE_conedR0p15_sig_Endcap_vs_PU->Write();

   h1_myHoE_conedR0p70_sig_Barrel->Write();
   h1_myHoE_conedR0p60_sig_Barrel->Write();
   h1_myHoE_conedR0p50_sig_Barrel->Write();
   h1_myHoE_conedR0p40_sig_Barrel->Write();
   h1_myHoE_conedR0p30_sig_Barrel->Write();
   h1_myHoE_conedR0p25_sig_Barrel->Write();
   h1_myHoE_conedR0p20_sig_Barrel->Write();

   h1_myHoE_conedR0p15_sig_Barrel->Write();
   h1_cmsswHoE_conedR0p15_sig_Barrel->Write();
   h1_cmsswfull5x5HoE_conedR0p15_sig_Barrel->Write();

   h1_myHoE_conedR0p10_sig_Barrel->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth1->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth2->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth3->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth4->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth5->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth6->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth7->Write();
   h1_myHoE_conedR0p15_sig_Barrel_Depth8->Write();
   h1_H_D2overD1_conedR0p15_sig_Barrel->Write();
   h1_H_D3overD1_conedR0p15_sig_Barrel->Write();
   h1_H_D4overD1_conedR0p15_sig_Barrel->Write();
   h1_H_D5overD1_conedR0p15_sig_Barrel->Write();
   prof_myHoE_conedR0p10_sig_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p15_sig_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p20_sig_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p25_sig_Barrel_vs_PU->Write();
   prof_myHoE_conedR0p30_sig_Barrel_vs_PU->Write();
   //

   h1_myHoE_conedR0p70_bkg_Endcap->Write();
   h1_myHoE_conedR0p60_bkg_Endcap->Write();
   h1_myHoE_conedR0p50_bkg_Endcap->Write();
   h1_myHoE_conedR0p40_bkg_Endcap->Write();
   h1_myHoE_conedR0p30_bkg_Endcap->Write();
   h1_myHoE_conedR0p25_bkg_Endcap->Write();
   h1_myHoE_conedR0p20_bkg_Endcap->Write();
   h1_myHoE_conedR0p15_bkg_Endcap->Write();
   h1_cmsswHoE_conedR0p15_bkg_Endcap->Write();
   h1_cmsswfull5x5HoE_conedR0p15_bkg_Endcap->Write();

   h1_myHoE_conedR0p10_bkg_Endcap->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth1->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth2->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth3->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth4->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth5->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth6->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth7->Write();
   h1_myHoE_conedR0p15_bkg_Endcap_Depth8->Write();
   h1_H_D2overD1_conedR0p15_bkg_Endcap->Write();
   h1_H_D3overD1_conedR0p15_bkg_Endcap->Write();
   h1_H_D4overD1_conedR0p15_bkg_Endcap->Write();
   h1_H_D5overD1_conedR0p15_bkg_Endcap->Write();
   prof_myHoE_conedR0p10_bkg_Endcap_vs_PU->Write();
   prof_myHoE_conedR0p15_bkg_Endcap_vs_PU->Write();
   prof_myHoE_conedR0p20_bkg_Endcap_vs_PU->Write();
   prof_myHoE_conedR0p25_bkg_Endcap_vs_PU->Write();
   prof_myHoE_conedR0p30_bkg_Endcap_vs_PU->Write();
   //

   h1_myHoE_conedR0p70_sig_Endcap->Write();
   h1_myHoE_conedR0p60_sig_Endcap->Write();
   h1_myHoE_conedR0p50_sig_Endcap->Write();
   h1_myHoE_conedR0p40_sig_Endcap->Write();
   h1_myHoE_conedR0p30_sig_Endcap->Write();
   h1_myHoE_conedR0p25_sig_Endcap->Write();
   h1_myHoE_conedR0p20_sig_Endcap->Write();
  
   h1_myHoE_conedR0p15_sig_Endcap->Write();
   h1_cmsswHoE_conedR0p15_sig_Endcap->Write();
   h1_cmsswfull5x5HoE_conedR0p15_sig_Endcap->Write();

   h1_myHoE_conedR0p10_sig_Endcap->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth1->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth2->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth3->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth4->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth5->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth6->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth7->Write();
   h1_myHoE_conedR0p15_sig_Endcap_Depth8->Write();
   h1_H_D2overD1_conedR0p15_sig_Endcap->Write();
   h1_H_D3overD1_conedR0p15_sig_Endcap->Write();
   h1_H_D4overD1_conedR0p15_sig_Endcap->Write();
   h1_H_D5overD1_conedR0p15_sig_Endcap->Write();
   prof_myHoE_conedR0p10_sig_Endcap_vs_PU->Write();   
   prof_myHoE_conedR0p15_sig_Endcap_vs_PU->Write();   
   prof_myHoE_conedR0p20_sig_Endcap_vs_PU->Write();   
   prof_myHoE_conedR0p25_sig_Endcap_vs_PU->Write();   
   prof_myHoE_conedR0p30_sig_Endcap_vs_PU->Write();   

   h2_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel->Write();
   h2_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap->Write();
   prof_scEn_vs_hrhE_within0p30_Pt50_sig_Barrel->Write();
   prof_scEn_vs_hrhE_within0p30_Pt50_sig_Endcap->Write();

   //Jan9
   h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel->Write();
   //
   h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap->Write();
   h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel->Write();
   prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap->Write();
   prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel->Write();
   //

   //Feb 1
   h2_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Write();
   //
   h2_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Write();
   h2_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Write();
   prof_scEn_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Write();
   prof_scEn_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Write();

   ////////// Feb 13

   h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel->Write();
   //
   h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap->Write();
   h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel->Write();
   prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap->Write();
   prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel->Write();
   //

   h2_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p05_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p05_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p08_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p08_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p1_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p1_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p125_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p125_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p175_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p175_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p15_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p15_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p2_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p2_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p25_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p25_Pt50_sig_Barrel_golden->Write();
   //
   h2_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Write();
   h2_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Write();
   prof_elePt_vs_H0p3mH0p225_Pt50_sig_Endcap_golden->Write();
   prof_elePt_vs_H0p3mH0p225_Pt50_sig_Barrel_golden->Write();


   std::cout  << "Number of events processed " << Event_counter << std::endl;
   std::cout  << "Number of electrons(sig+bkg) " << electron_counter << std::endl;
}
