#define RedefHoverE_cxx
#include "RedefHoverE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TProfile.h>

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
  /// cone size deltaR=0.20 ////
  ////////////////////////////// 
  //sig barrel
  TH1D* h1_myHoE_conedR0p20_sig_Barrel = new TH1D("h1_myHoE_conedR0p20_sig_Barrel", "myHoE_conedR0p20_sig_Barrel", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p20_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p20_sig_Barrel_vs_PU","myHoE_conedR0p20_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
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
  TH1D* h1_myHoE_conedR0p15_sig_Barrel = new TH1D("h1_myHoE_conedR0p15_sig_Barrel", "myHoE_conedR0p15_sig_Barrel", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth1 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d1", "myHoE_conedR0p15_sig_Barrel_d1", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth2 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d2", "myHoE_conedR0p15_sig_Barrel_d2", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth3 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d3", "myHoE_conedR0p15_sig_Barrel_d3", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth4 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d4", "myHoE_conedR0p15_sig_Barrel_d4", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth5 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d5", "myHoE_conedR0p15_sig_Barrel_d5", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth6 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d6", "myHoE_conedR0p15_sig_Barrel_d6", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth7 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d7", "myHoE_conedR0p15_sig_Barrel_d7", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Barrel_Depth8 = new TH1D("h1_myHoE_conedR0p15_sig_Barrel_d8", "myHoE_conedR0p15_sig_Barrel_d8", 1000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D2overD1_conedR0p15_sig_Barrel", "H_D2overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D3overD1_conedR0p15_sig_Barrel", "H_D3overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D4overD1_conedR0p15_sig_Barrel", "H_D4overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_sig_Barrel = new TH1D("h1_H_D5overD1_conedR0p15_sig_Barrel", "H_D5overD1_conedR0p15_sig_Barrel", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_sig_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p15_sig_Barrel_vs_PU","myHoE_conedR0p15_sig_Barrel_vs_PU", 40,0,80,0,15);
  //
  //sig endcap
  TH1D* h1_myHoE_conedR0p15_sig_Endcap = new TH1D("h1_myHoE_conedR0p15_sig_Endcap", "myHoE_conedR0p15_sig_Endcap", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth1 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d1", "myHoE_conedR0p15_sig_Endcap_d1", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth2 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d2", "myHoE_conedR0p15_sig_Endcap_d2", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth3 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d3", "myHoE_conedR0p15_sig_Endcap_d3", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth4 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d4", "myHoE_conedR0p15_sig_Endcap_d4", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth5 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d5", "myHoE_conedR0p15_sig_Endcap_d5", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth6 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d6", "myHoE_conedR0p15_sig_Endcap_d6", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth7 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d7", "myHoE_conedR0p15_sig_Endcap_d7", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_sig_Endcap_Depth8 = new TH1D("h1_myHoE_conedR0p15_sig_Endcap_d8", "myHoE_conedR0p15_sig_Endcap_d8", 1000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D2overD1_conedR0p15_sig_Endcap", "H_D2overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D3overD1_conedR0p15_sig_Endcap", "H_D3overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D4overD1_conedR0p15_sig_Endcap", "H_D4overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_sig_Endcap = new TH1D("h1_H_D5overD1_conedR0p15_sig_Endcap", "H_D5overD1_conedR0p15_sig_Endcap", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_sig_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p15_sig_Endcap_vs_PU","myHoE_conedR0p15_sig_Endcap_vs_PU", 40,0,80,0,15);
  //
  //bkg barrel
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel", "myHoE_conedR0p15_bkg_Barrel", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth1 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d1", "myHoE_conedR0p15_bkg_Barrel_d1", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth2 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d2", "myHoE_conedR0p15_bkg_Barrel_d2", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth3 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d3", "myHoE_conedR0p15_bkg_Barrel_d3", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth4 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d4", "myHoE_conedR0p15_bkg_Barrel_d4", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth5 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d5", "myHoE_conedR0p15_bkg_Barrel_d5", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth6 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d6", "myHoE_conedR0p15_bkg_Barrel_d6", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth7 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d7", "myHoE_conedR0p15_bkg_Barrel_d7", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Barrel_Depth8 = new TH1D("h1_myHoE_conedR0p15_bkg_Barrel_d8", "myHoE_conedR0p15_bkg_Barrel_d8", 1000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D2overD1_conedR0p15_bkg_Barrel", "H_D2overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D3overD1_conedR0p15_bkg_Barrel", "H_D3overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D4overD1_conedR0p15_bkg_Barrel", "H_D4overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_bkg_Barrel = new TH1D("h1_H_D5overD1_conedR0p15_bkg_Barrel", "H_D5overD1_conedR0p15_bkg_Barrel", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_bkg_Barrel_vs_PU = new TProfile("prof_myHoE_conedR0p15_bkg_Barrel_vs_PU","myHoE_conedR0p15_bkg_Barrel_vs_PU", 40,0,80,0,15);
  //
  //bkg endcap
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap", "myHoE_conedR0p15_bkg_Endcap", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth1 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d1", "myHoE_conedR0p15_bkg_Endcap_d1", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth2 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d2", "myHoE_conedR0p15_bkg_Endcap_d2", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth3 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d3", "myHoE_conedR0p15_bkg_Endcap_d3", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth4 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d4", "myHoE_conedR0p15_bkg_Endcap_d4", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth5 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d5", "myHoE_conedR0p15_bkg_Endcap_d5", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth6 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d6", "myHoE_conedR0p15_bkg_Endcap_d6", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth7 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d7", "myHoE_conedR0p15_bkg_Endcap_d7", 1000, 0, 20);
  TH1D* h1_myHoE_conedR0p15_bkg_Endcap_Depth8 = new TH1D("h1_myHoE_conedR0p15_bkg_Endcap_d8", "myHoE_conedR0p15_bkg_Endcap_d8", 1000, 0, 20);
  TH1D* h1_H_D2overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D2overD1_conedR0p15_bkg_Endcap", "H_D2overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TH1D* h1_H_D3overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D3overD1_conedR0p15_bkg_Endcap", "H_D3overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TH1D* h1_H_D4overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D4overD1_conedR0p15_bkg_Endcap", "H_D4overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TH1D* h1_H_D5overD1_conedR0p15_bkg_Endcap = new TH1D("h1_H_D5overD1_conedR0p15_bkg_Endcap", "H_D5overD1_conedR0p15_bkg_Endcap", 100, 0, 5);
  TProfile* prof_myHoE_conedR0p15_bkg_Endcap_vs_PU = new TProfile("prof_myHoE_conedR0p15_bkg_Endcap_vs_PU","myHoE_conedR0p15_bkg_Endcap_vs_PU", 40,0,80,0,15);



  //////////////////////////////////////////
  //
  TH1D* h1_myHoE_conedR0p15_allEle_Endcap = new TH1D("h1_myHoE_conedR0p15_allEle_Endcap", "myHoE_conedR0p15_allEle_Endcap", 1000, 0, 20);
  TProfile* prof_myHoE_conedR0p15_allEle_Barrel_vs_pt = new TProfile("prof_myHoE_conedR0p15_allEle_Barrel_vs_pt","myHoE_conedR0p15_allEle_Barrel_vs_pt", 20,0,200,0,15);
  //
  TProfile* prof_myHoE_conedR0p15_sig_vs_eta = new TProfile("prof_myHoE_conedR0p15_sig_vs_eta","myHoE_conedR0p15_sig_vs_eta", 240,-3,3,0,15);
  TProfile* prof_myHoE_conedR0p15_bkg_vs_eta = new TProfile("prof_myHoE_conedR0p15_bkg_vs_eta","myHoE_conedR0p15_bkg_vs_eta", 240,-3,3,0,15);

  int Event_counter=0;
  int electron_counter=0;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      std::cout << "\n ******* New event " << std::endl;
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
	std::cout << "\n new ele with pT " << elePt_->at(iele) << " genmatched? " << ele_genmatched_->at(iele)  << std::endl;
	std::cout << "Number of hcal rechit associated " << (hcalRechitEta_->at(iele)).size() << std::endl;
	int nhrh=(hcalRechitEta_->at(iele)).size() ;
	if (nhrh==0) std::cout << "This ele has no hcal energy deposit, so H/E=0" << std::endl;
	  float this_DeltaR = 999.9;

	  float hcalE_0p30=0;
	  float hcalE_0p25=0;
	  float hcalE_0p20=0;
	  float hcalE_0p10=0;

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
	  float this_DeltaR = DeltaR(eleSeedEta_->at(iele), eleSeedPhi_->at(iele), hcalRechitEta_->at(iele).at(ihrh), hcalRechitPhi_->at(iele).at(ihrh)); 

	  if (this_DeltaR <= 0.15) {
	    hcalE_0p15 = hcalE_0p15+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    int hcal_depth=hcalRechitDepth_->at(iele).at(ihrh);
	    if (hcal_depth==1) {
	      hcalE_0p15_d1=hcalE_0p15_d1+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } 	 else if (hcal_depth==2) {
	      hcalE_0p15_d2=hcalE_0p15_d2+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    }  	 else if (hcal_depth==3) {
	      hcalE_0p15_d3=hcalE_0p15_d3+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    }    else if (hcal_depth==4) {
	      hcalE_0p15_d4=hcalE_0p15_d4+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    }    else if (hcal_depth==5) {
	      hcalE_0p15_d5=hcalE_0p15_d5+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    }    else if (hcal_depth==6) {
	      hcalE_0p15_d6=hcalE_0p15_d6+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    }    else if (hcal_depth==7) {
	      hcalE_0p15_d7=hcalE_0p15_d7+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    }    else if (hcal_depth==8) {
	      hcalE_0p15_d8=hcalE_0p15_d8+hcalRechitEnergy_->at(iele).at(ihrh) ;
	    } 
    	  } //deltaR cone of 0.15

	  // deltaR cone of 0.30
	  if (this_DeltaR <= 0.30) {
	    hcalE_0p30 = hcalE_0p30+hcalRechitEnergy_->at(iele).at(ihrh) ;
    	  } //deltaR cone of 0.30

	  // deltaR cone of 0.25
	  if (this_DeltaR <= 0.25) {
	    hcalE_0p25 = hcalE_0p25+hcalRechitEnergy_->at(iele).at(ihrh) ;
    	  } //deltaR cone of 0.25

	  // deltaR cone of 0.20
	  if (this_DeltaR <= 0.20) {
	    hcalE_0p20 = hcalE_0p20+hcalRechitEnergy_->at(iele).at(ihrh) ;
    	  } //deltaR cone of 0.20

	  // deltaR cone of 0.10
	  if (this_DeltaR <= 0.10) {
	    hcalE_0p10 = hcalE_0p10+hcalRechitEnergy_->at(iele).at(ihrh) ;
    	  } //deltaR cone of 0.10

	  
	  //  std::cout << "ele eta, phi " << eleSeedEta_->at(iele) << " , " << eleSeedPhi_->at(iele) << std::endl;
	  // std::cout << "hcal rechit eta, phi " << hcalRechitEta_->at(iele).at(ihrh) << " , " << hcalRechitPhi_->at(iele).at(ihrh) << std::endl;
	  // std::cout << "ihrh " << ihrh << " dR " << this_DeltaR << std::endl;

	} // hcal rechit loop ends //

	float HoE_0p30 = hcalE_0p30/(scEn_->at(iele));
	float HoE_0p25 = hcalE_0p25/(scEn_->at(iele));
	float HoE_0p20 = hcalE_0p20/(scEn_->at(iele));
	float HoE_0p10 = hcalE_0p10/(scEn_->at(iele));

	float HoE_0p15 = hcalE_0p15/(scEn_->at(iele));
	float HoE_0p15_d1 = hcalE_0p15_d1/(scEn_->at(iele));
	float HoE_0p15_d2 = hcalE_0p15_d2/(scEn_->at(iele));
	float HoE_0p15_d3 = hcalE_0p15_d3/(scEn_->at(iele));
	float HoE_0p15_d4 = hcalE_0p15_d4/(scEn_->at(iele));
	float HoE_0p15_d5 = hcalE_0p15_d5/(scEn_->at(iele));
	float HoE_0p15_d6 = hcalE_0p15_d6/(scEn_->at(iele));
	float HoE_0p15_d7 = hcalE_0p15_d7/(scEn_->at(iele));
	float HoE_0p15_d8 = hcalE_0p15_d8/(scEn_->at(iele));

	float H_D2overD1_0p15=hcalE_0p15_d2/hcalE_0p15_d1 ;
	float H_D3overD1_0p15=hcalE_0p15_d3/hcalE_0p15_d1 ;
	float H_D4overD1_0p15=hcalE_0p15_d4/hcalE_0p15_d1 ;
	float H_D5overD1_0p15=hcalE_0p15_d5/hcalE_0p15_d1 ;

	//std::cout << "hcalE_0p15 = " << hcalE_0p15 << " my H/E " << HoE_0p15 << " cmssw_eleHoE_full5x5_ " << cmssw_eleHoE_full5x5_->at(iele) 
	//<< " cmssw_eleHoE_" << cmssw_eleHoE_->at(iele) << std::endl;

	//Barrel+Endcap, Sig+Bkg
	h1_myHoE_conedR0p15_allEle_fullEta->Fill(HoE_0p15);

	if (elePt_->at(iele) > 2) { // ele pt > 2 GeV
	  //Barrel
	  if ( fabs(eleScEta_->at(iele)) < 1.44 ) {
	    prof_myHoE_conedR0p15_allEle_Barrel_vs_pt->Fill(elePt_->at(iele),HoE_0p15);
	    h1_myHoE_conedR0p15_allEle_Barrel->Fill(HoE_0p15);
	    h1_myHoE_conedR0p15_allEle_Barrel_Depth1->Fill(HoE_0p15_d1);
	    h1_myHoE_conedR0p15_allEle_Barrel_Depth2->Fill(HoE_0p15_d2);
	    
	    if ( ele_genmatched_->at(iele)==1 ) { //signal
	      h1_myHoE_conedR0p30_sig_Barrel->Fill(HoE_0p30);
	      h1_myHoE_conedR0p25_sig_Barrel->Fill(HoE_0p25);
	      h1_myHoE_conedR0p20_sig_Barrel->Fill(HoE_0p20);
	      h1_myHoE_conedR0p10_sig_Barrel->Fill(HoE_0p10);
	      
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
	    }
	    
	    else if ( ele_genmatched_->at(iele)==0 ) { //background
	      h1_myHoE_conedR0p30_bkg_Barrel->Fill(HoE_0p30);
	      h1_myHoE_conedR0p25_bkg_Barrel->Fill(HoE_0p25);
	      h1_myHoE_conedR0p20_bkg_Barrel->Fill(HoE_0p20);
	      h1_myHoE_conedR0p10_bkg_Barrel->Fill(HoE_0p10);
	      h1_myHoE_conedR0p15_bkg_Barrel->Fill(HoE_0p15);
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
	      h1_myHoE_conedR0p30_sig_Endcap->Fill(HoE_0p30);
	      h1_myHoE_conedR0p25_sig_Endcap->Fill(HoE_0p25);
	      h1_myHoE_conedR0p20_sig_Endcap->Fill(HoE_0p20);
	      h1_myHoE_conedR0p10_sig_Endcap->Fill(HoE_0p10);
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
	      
	    }
	    
	    else if ( ele_genmatched_->at(iele)==0 ) { //background
	      h1_myHoE_conedR0p30_bkg_Endcap->Fill(HoE_0p30);
	      h1_myHoE_conedR0p25_bkg_Endcap->Fill(HoE_0p25);
	      h1_myHoE_conedR0p20_bkg_Endcap->Fill(HoE_0p20);
	      h1_myHoE_conedR0p10_bkg_Endcap->Fill(HoE_0p10);
	      h1_myHoE_conedR0p15_bkg_Endcap->Fill(HoE_0p15);
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
	  
	  
	  
	} //ele pt>2 GeV
	
      }
      
   }
   
   h1_myHoE_conedR0p15_allEle_fullEta->Write();
   h1_myHoE_conedR0p15_allEle_Barrel->Write();
   h1_myHoE_conedR0p15_allEle_Barrel_Depth1->Write();
   h1_myHoE_conedR0p15_allEle_Barrel_Depth2->Write();
   h1_myHoE_conedR0p15_allEle_Endcap->Write();
   prof_myHoE_conedR0p15_allEle_Barrel_vs_pt->Write();
   prof_myHoE_conedR0p15_sig_vs_eta->Write();
   prof_myHoE_conedR0p15_bkg_vs_eta->Write();

   h1_myHoE_conedR0p30_bkg_Barrel->Write();
   h1_myHoE_conedR0p25_bkg_Barrel->Write();
   h1_myHoE_conedR0p20_bkg_Barrel->Write();
   h1_myHoE_conedR0p15_bkg_Barrel->Write();
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

   h1_myHoE_conedR0p30_sig_Barrel->Write();
   h1_myHoE_conedR0p25_sig_Barrel->Write();
   h1_myHoE_conedR0p20_sig_Barrel->Write();
   h1_myHoE_conedR0p15_sig_Barrel->Write();
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

   h1_myHoE_conedR0p30_bkg_Endcap->Write();
   h1_myHoE_conedR0p25_bkg_Endcap->Write();
   h1_myHoE_conedR0p20_bkg_Endcap->Write();
   h1_myHoE_conedR0p15_bkg_Endcap->Write();
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

   h1_myHoE_conedR0p30_sig_Endcap->Write();
   h1_myHoE_conedR0p25_sig_Endcap->Write();
   h1_myHoE_conedR0p20_sig_Endcap->Write();
   h1_myHoE_conedR0p15_sig_Endcap->Write();
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

   std::cout  << "Number of events processed " << Event_counter << std::endl;
   std::cout  << "Number of electrons(sig+bkg) " << electron_counter << std::endl;
}
