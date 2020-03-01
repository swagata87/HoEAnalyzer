#define testMax2x2_cxx
#include "testMax2x2.h"
#include <iomanip>
#include <TH2.h>
#include <TProfile.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <algorithm>

void testMax2x2::Loop()
{
//   In a ROOT session, you can do:
//      root> .L testMax2x2.C
//      root> testMax2x2 t
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
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   TFile* outputFile = new TFile("Out_ele_towerHoE_2021.root","RECREATE");

   ////
   TProfile*   prof_H_tot_m_singleTower_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_singleTower_vs_genPt_barrel_gap","prof_H_tot_m_singleTower_vs_genPt_barrel_gap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_2x2_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_max_2x2_vs_genPt_barrel_gap","prof_H_tot_m_max_2x2_vs_genPt_barrel_gap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_seedplus1_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_max_seedplus1_vs_genPt_barrel_gap","prof_H_tot_m_max_seedplus1_vs_genPt_barrel_gap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_cross_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_max_cross_vs_genPt_barrel_gap","prof_H_tot_m_max_cross_vs_genPt_barrel_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_max_L_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_max_L_vs_genPt_barrel_gap","prof_H_tot_m_max_L_vs_genPt_barrel_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell2maxE_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_cell2maxE_vs_genPt_barrel_gap","prof_H_tot_m_cell2maxE_vs_genPt_barrel_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell3maxE_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_cell3maxE_vs_genPt_barrel_gap","prof_H_tot_m_cell3maxE_vs_genPt_barrel_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell4maxE_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_cell4maxE_vs_genPt_barrel_gap","prof_H_tot_m_cell4maxE_vs_genPt_barrel_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell5maxE_vs_genPt_barrel_gap = new TProfile("prof_H_tot_m_cell5maxE_vs_genPt_barrel_gap","prof_H_tot_m_cell5maxE_vs_genPt_barrel_gap",8,50,250,0,200) ;
   
   TProfile*   prof_H_tot_m_singleTower_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_singleTower_vs_genPt_barrel_nogap","prof_H_tot_m_singleTower_vs_genPt_barrel_nogap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_2x2_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_max_2x2_vs_genPt_barrel_nogap","prof_H_tot_m_max_2x2_vs_genPt_barrel_nogap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_seedplus1_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_max_seedplus1_vs_genPt_barrel_nogap","prof_H_tot_m_max_seedplus1_vs_genPt_barrel_nogap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_cross_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_max_cross_vs_genPt_barrel_nogap","prof_H_tot_m_max_cross_vs_genPt_barrel_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_max_L_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_max_L_vs_genPt_barrel_nogap","prof_H_tot_m_max_L_vs_genPt_barrel_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell2maxE_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_cell2maxE_vs_genPt_barrel_nogap","prof_H_tot_m_cell2maxE_vs_genPt_barrel_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell3maxE_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_cell3maxE_vs_genPt_barrel_nogap","prof_H_tot_m_cell3maxE_vs_genPt_barrel_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell4maxE_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_cell4maxE_vs_genPt_barrel_nogap","prof_H_tot_m_cell4maxE_vs_genPt_barrel_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell5maxE_vs_genPt_barrel_nogap = new TProfile("prof_H_tot_m_cell5maxE_vs_genPt_barrel_nogap","prof_H_tot_m_cell5maxE_vs_genPt_barrel_nogap",8,50,250,0,200) ;
   /////

   TProfile*   prof_H_tot_m_singleTower_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_singleTower_vs_genPt_endcap_gap","prof_H_tot_m_singleTower_vs_genPt_endcap_gap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_2x2_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_max_2x2_vs_genPt_endcap_gap","prof_H_tot_m_max_2x2_vs_genPt_endcap_gap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_seedplus1_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_max_seedplus1_vs_genPt_endcap_gap","prof_H_tot_m_max_seedplus1_vs_genPt_endcap_gap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_cross_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_max_cross_vs_genPt_endcap_gap","prof_H_tot_m_max_cross_vs_genPt_endcap_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_max_L_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_max_L_vs_genPt_endcap_gap","prof_H_tot_m_max_L_vs_genPt_endcap_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell2maxE_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_cell2maxE_vs_genPt_endcap_gap","prof_H_tot_m_cell2maxE_vs_genPt_endcap_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell3maxE_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_cell3maxE_vs_genPt_endcap_gap","prof_H_tot_m_cell3maxE_vs_genPt_endcap_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell4maxE_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_cell4maxE_vs_genPt_endcap_gap","prof_H_tot_m_cell4maxE_vs_genPt_endcap_gap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell5maxE_vs_genPt_endcap_gap = new TProfile("prof_H_tot_m_cell5maxE_vs_genPt_endcap_gap","prof_H_tot_m_cell5maxE_vs_genPt_endcap_gap",8,50,250,0,200) ;
   
   TProfile*   prof_H_tot_m_singleTower_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_singleTower_vs_genPt_endcap_nogap","prof_H_tot_m_singleTower_vs_genPt_endcap_nogap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_2x2_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_max_2x2_vs_genPt_endcap_nogap","prof_H_tot_m_max_2x2_vs_genPt_endcap_nogap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_seedplus1_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_max_seedplus1_vs_genPt_endcap_nogap","prof_H_tot_m_max_seedplus1_vs_genPt_endcap_nogap",8,50,250,0,200);
   TProfile*   prof_H_tot_m_max_cross_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_max_cross_vs_genPt_endcap_nogap","prof_H_tot_m_max_cross_vs_genPt_endcap_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_max_L_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_max_L_vs_genPt_endcap_nogap","prof_H_tot_m_max_L_vs_genPt_endcap_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell2maxE_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_cell2maxE_vs_genPt_endcap_nogap","prof_H_tot_m_cell2maxE_vs_genPt_endcap_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell3maxE_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_cell3maxE_vs_genPt_endcap_nogap","prof_H_tot_m_cell3maxE_vs_genPt_endcap_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell4maxE_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_cell4maxE_vs_genPt_endcap_nogap","prof_H_tot_m_cell4maxE_vs_genPt_endcap_nogap",8,50,250,0,200) ;
   TProfile*   prof_H_tot_m_cell5maxE_vs_genPt_endcap_nogap = new TProfile("prof_H_tot_m_cell5maxE_vs_genPt_endcap_nogap","prof_H_tot_m_cell5maxE_vs_genPt_endcap_nogap",8,50,250,0,200) ;

   int nEle_highR9_highpT_genmatched=0;
   int nEle_highR9_highpT_genmatched_EnergyInEachCell=0;
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      for (int iele=0; iele < elePt_->size(); iele++) {
	
	//std::cout << "seed hcal ieta " << seedHcalIeta_->at(iele) ;
	//	std::cout << " seed hcal iphi " << seedHcalIphi_->at(iele) << std::endl ;

	int seed_hcal_ieta=seedHcalIeta_->at(iele) ;
	int seed_hcal_iphi=seedHcalIphi_->at(iele) ;

	float E_cell_11 = 0.0;
	float E_cell_12 = 0.0;
	float E_cell_13 = 0.0;
	float E_cell_21 = 0.0;
	float E_cell_22 = 0.0; ////seed
	float E_cell_23 = 0.0;
	float E_cell_31 = 0.0;
	float E_cell_32 = 0.0;
	float E_cell_33 = 0.0;

	int nhrh=(hcalRechitEta_->at(iele)).size() ;
	for (int ihrh=0; ihrh<nhrh; ihrh++) {
	  int my_ieta=hcalRechitIeta_->at(iele).at(ihrh);
	  int my_iphi=hcalRechitIphi_->at(iele).at(ihrh);
	  
	  if ( (my_ieta==seed_hcal_ieta) && (my_iphi==seed_hcal_iphi) ) { // ieta, iphi // cell 22
	    //	    std::cout << "sum up this hcal rechit energy " << hcalRechitEnergy_->at(iele).at(ihrh)  << " as cell 22, seed " << std::endl;
	    // std::cout << "cell22, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_22 = E_cell_22 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 22 (seed hcal)

	  if ( (my_ieta==seed_hcal_ieta-1) && (my_iphi==seed_hcal_iphi+1) ) { // ieta-1, iphi+1 // cell 11
	    // std::cout << "cell11, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_11 = E_cell_11 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 11 

	  if ( (my_ieta==seed_hcal_ieta) && (my_iphi==seed_hcal_iphi+1) ) { // ieta, iphi+1 // cell 12
	    //std::cout << "cell12, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_12 = E_cell_12 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 12 

	  if ( (my_ieta==seed_hcal_ieta+1) && (my_iphi==seed_hcal_iphi+1) ) { // ieta+1, iphi+1 // cell 13
	    // std::cout << "cell13, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_13 = E_cell_13 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 13 

	  if ( (my_ieta==seed_hcal_ieta-1) && (my_iphi==seed_hcal_iphi) ) { // ieta-1, iphi // cell 21
	    // std::cout << "cell21, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_21 = E_cell_21 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 21 

	  if ( (my_ieta==seed_hcal_ieta+1) && (my_iphi==seed_hcal_iphi) ) { // ieta+1, iphi // cell 23
	    // std::cout << "cell23, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_23 = E_cell_23 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 23 

	  if ( (my_ieta==seed_hcal_ieta-1) && (my_iphi==seed_hcal_iphi-1) ) { // ieta-1, iphi-1 // cell 31
	    // std::cout << "cell31, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_31 = E_cell_31 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 31

	  if ( (my_ieta==seed_hcal_ieta) && (my_iphi==seed_hcal_iphi-1) ) { // ieta, iphi-1 // cell 32
	    // std::cout << "cell32, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_32 = E_cell_32 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 32

	  if ( (my_ieta==seed_hcal_ieta+1) && (my_iphi==seed_hcal_iphi-1) ) { // ieta+1, iphi-1 // cell 33
	    //  std::cout << "cell33, this rechit ieta/iphi " << my_ieta << "/" << my_iphi << std::endl; 
	    E_cell_33 = E_cell_33 + hcalRechitEnergy_->at(iele).at(ihrh) ;
	  } // cell 33

	} //hcal rechit loop ends

	

	/*	
	std::cout << "for this electron, E_cell_22(seed hcal) " << E_cell_22 << std::endl;
	std::cout << "for this electron, E_cell_11 " << E_cell_11 << std::endl;
	std::cout << "for this electron, E_cell_12 " << E_cell_12 << std::endl;
	std::cout << "for this electron, E_cell_13 " << E_cell_13 << std::endl;
	std::cout << "for this electron, E_cell_21 " << E_cell_21 << std::endl;
	std::cout << "for this electron, E_cell_23 " << E_cell_23 << std::endl;
	std::cout << "for this electron, E_cell_31 " << E_cell_31 << std::endl;
	std::cout << "for this electron, E_cell_32 " << E_cell_32 << std::endl;
	std::cout << "for this electron, E_cell_33 " << E_cell_33 << std::endl;
	*/
	////////

	float E3x3_tot = E_cell_11 + E_cell_12 + E_cell_13 + E_cell_21 + E_cell_22 + E_cell_23 + E_cell_31 + E_cell_32 + E_cell_33 ;

	/////// Max(2x2) ////////
	float my_2x2_1 = E_cell_11 + E_cell_12 + E_cell_21 + E_cell_22;
	float my_2x2_2 = E_cell_21 + E_cell_22 + E_cell_31 + E_cell_32;
	float my_2x2_3 = E_cell_12 + E_cell_13 + E_cell_22 + E_cell_23;
	float my_2x2_4 = E_cell_22 + E_cell_23 + E_cell_32 + E_cell_33;
	//	std::cout << "4 possible choices are " << my_2x2_1 << " " << my_2x2_2 << " " << my_2x2_3 << " " << my_2x2_4 << std::endl;
	float max_2x2 = std::max({my_2x2_1,my_2x2_2,my_2x2_3,my_2x2_4});

	////// Max(seed+1) //////
	float my_seedplus1_1 = E_cell_22 + E_cell_11;
	float my_seedplus1_2 = E_cell_22 + E_cell_12;
	float my_seedplus1_3 = E_cell_22 + E_cell_13;
	float my_seedplus1_4 = E_cell_22 + E_cell_21;
	float my_seedplus1_5 = E_cell_22 + E_cell_23;
	float my_seedplus1_6 = E_cell_22 + E_cell_31;
	float my_seedplus1_7 = E_cell_22 + E_cell_32;
	float my_seedplus1_8 = E_cell_22 + E_cell_33;
	//	std::cout << "8 possible choices are " << my_seedplus1_1 << " " << my_seedplus1_2 << " " << my_seedplus1_3 << " " << my_seedplus1_4 << " " << my_seedplus1_5 << " " << my_seedplus1_6 << " " << my_seedplus1_7 << " " << my_seedplus1_8 << std::endl; 
	float max_seedplus1 = std::max({my_seedplus1_1,my_seedplus1_2,my_seedplus1_3,my_seedplus1_4,my_seedplus1_5,my_seedplus1_6,my_seedplus1_7,my_seedplus1_8});

	///// Max(cross) //////
	float my_cross_1 = E_cell_22 + E_cell_12 + E_cell_32 + E_cell_21 + E_cell_23 ;
	float my_cross_2 = E_cell_22 + E_cell_13 + E_cell_31 + E_cell_11 + E_cell_33 ;
	//	std::cout << "2 possible choices are " << my_cross_1 << " " << my_cross_2 << std::endl;
	float max_cross = std::max(my_cross_1,my_cross_2);

	///// Max(L) //////
	float my_L_1 = E_cell_22 + E_cell_12 + E_cell_23 ; 
	float my_L_2 = E_cell_22 + E_cell_23 + E_cell_32 ; 
	float my_L_3 = E_cell_22 + E_cell_12 + E_cell_21 ; 
	float my_L_4 = E_cell_22 + E_cell_21 + E_cell_32 ; 
	float max_L = std::max({my_L_1,my_L_2,my_L_3,my_L_4});
	
	////cellXmaxE
	float arr[] = {E_cell_11, E_cell_12, E_cell_13, E_cell_21, E_cell_22, E_cell_23, E_cell_31, E_cell_32, E_cell_33}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	//	std::sort(arr, arr+n);
	std::sort(arr, arr+n, greater<float>());
	float cell2maxE = arr[0]+arr[1]; 
	float cell3maxE = arr[0]+arr[1]+arr[2]; 
	float cell4maxE = arr[0]+arr[1]+arr[2]+arr[3]; 
	float cell5maxE = arr[0]+arr[1]+arr[2]+arr[3]+arr[4]; 
	//	if (arr[0] > 0) {
	//std::cout << "\n\nArray after sorting using default sort is : \n"; 
	//for (int i = 0; i < n; ++i) {
	//  std::cout << arr[i] << " " ; 
	//}
	//}

	float tot_m_singleTower = E3x3_tot - E_cell_22 ;
	float tot_m_max_2x2 = E3x3_tot - max_2x2 ;
	float tot_m_max_seedplus1 = E3x3_tot - max_seedplus1 ; 
	float tot_m_max_cross = E3x3_tot - max_cross ; 
	float tot_m_max_L = E3x3_tot - max_L ;
	float tot_m_cell2maxE = E3x3_tot - cell2maxE ;
	float tot_m_cell3maxE = E3x3_tot - cell3maxE ;
	float tot_m_cell4maxE = E3x3_tot - cell4maxE ;
	float tot_m_cell5maxE = E3x3_tot - cell5maxE ;

	//	std::cout << "total - others " << tot_m_singleTower << " " << tot_m_max_2x2 << " " << tot_m_max_seedplus1 << " " << tot_m_max_cross << " " << tot_m_max_L 
	//	  << " " << tot_m_cell2maxE << " " << tot_m_cell3maxE << " " << tot_m_cell4maxE << " " << tot_m_cell5maxE << std::endl;

	float myHoE_singleTower = E_cell_22 / ecalEn_->at(iele);
	float myHoE_max_2x2 = max_2x2 / ecalEn_->at(iele);
	float myHoE_max_seedplus1 = max_seedplus1 / ecalEn_->at(iele);
	float myHoE_max_cross = max_cross / ecalEn_->at(iele);
	float myHoE_max_L = max_L / ecalEn_->at(iele);
	float myHoE_cell2maxE = cell2maxE / ecalEn_->at(iele);
	float myHoE_cell3maxE = cell3maxE / ecalEn_->at(iele);
	float myHoE_cell4maxE = cell4maxE / ecalEn_->at(iele);
	float myHoE_cell5maxE = cell5maxE / ecalEn_->at(iele);


	if  (	( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) ) {
	  nEle_highR9_highpT_genmatched++;
	  
	  if (  (E_cell_11 != 0) &&  (E_cell_12 != 0) &&   (E_cell_13 != 0) &&  (E_cell_21 != 0) &&  (E_cell_22 != 0) &&  (E_cell_23 != 0) &&  (E_cell_31 != 0) &&  (E_cell_32 != 0) &&  (E_cell_33 != 0)   )  {
	    nEle_highR9_highpT_genmatched_EnergyInEachCell++;
	    
	    std::cout << "\nElectron with reco pt " << elePt_->at(iele) << " SC eta " << eleScEta_->at(iele)  << std::endl;
	    std::cout << "E_3x3 = " << E3x3_tot << std::endl;
	    std::cout << "E_seed " << E_cell_22 << std::endl;
	    std::cout << "E_max_2x2 " << max_2x2 << std::endl;
	    std::cout << "E_max_seed+1 = " << max_seedplus1 << std::endl;
	    std::cout << "E_max_cross = " << max_cross << std::endl;
	    std::cout << "E_max_L " << max_L << std::endl;
	    std::cout << "E_cell2maxE, E_cell3maxE, E_cell4maxE, E_cell5maxE " << cell2maxE << ", " << cell3maxE  << ", " << cell4maxE << ", " << cell5maxE << std::endl;
	    std::cout << "Run:Lumi:Event " << run_number_->at(0) << ":" << lumi_number_->at(0) << ":" << event_number_ << std::endl ; 

	    //	std::cout.setprecision(4) ;
	    std::cout << " ---------------------------" << std::endl;
	    std::cout << std::setprecision(4) << fixed << " | " <<  E_cell_11 << " | "  << E_cell_12 << " | "  << E_cell_13 << " | "  << std::endl;
	    std::cout << " ---------------------------" << std::endl;
	    std::cout << std::setprecision(4) << fixed << " | " <<  E_cell_21 << " | "  << E_cell_22 << " | "  << E_cell_23 << " | "  << std::endl; 
	    std::cout << " ---------------------------" << std::endl;
	    std::cout << std::setprecision(4) << fixed << " | " <<  E_cell_31 << " | "  << E_cell_32 << " | "  << E_cell_33 << " | "  << std::endl; 
	    std::cout << " ---------------------------" << std::endl;
	  }
	}
	/// Barrel Gap
	if ( (ele_isEB_->at(iele)==1) && 
	     ( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && ( ele_isGap_->at(iele)==1 ) ) {
	  
	  prof_H_tot_m_singleTower_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_singleTower);
	  prof_H_tot_m_max_2x2_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_max_2x2);
	  prof_H_tot_m_max_seedplus1_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_max_seedplus1);
	  prof_H_tot_m_max_cross_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_max_cross);
	  prof_H_tot_m_max_L_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_max_L);
	  prof_H_tot_m_cell2maxE_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_cell2maxE);
	  prof_H_tot_m_cell3maxE_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_cell3maxE);
	  prof_H_tot_m_cell4maxE_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_cell4maxE);
	  prof_H_tot_m_cell5maxE_vs_genPt_barrel_gap->Fill(eleGenPt_->at(iele),tot_m_cell5maxE);

	} //barrel gap + genmatched + highR9 + pt>50//
	//////////////
	/// Barrel noGap
	if ( (ele_isEB_->at(iele)==1) && 
	     ( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && ( ele_isGap_->at(iele)==0 ) ) {
	  
	  prof_H_tot_m_singleTower_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_singleTower);
	  prof_H_tot_m_max_2x2_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_max_2x2);
	  prof_H_tot_m_max_seedplus1_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_max_seedplus1);
	  prof_H_tot_m_max_cross_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_max_cross);
	  prof_H_tot_m_max_L_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_max_L);
	  prof_H_tot_m_cell2maxE_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_cell2maxE);
	  prof_H_tot_m_cell3maxE_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_cell3maxE);
	  prof_H_tot_m_cell4maxE_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_cell4maxE);
	  prof_H_tot_m_cell5maxE_vs_genPt_barrel_nogap->Fill(eleGenPt_->at(iele),tot_m_cell5maxE);

	} //barrel nogap + genmatched + highR9 + pt>50//
	////////////
	/// Endcap Gap
	if ( (ele_isEE_->at(iele)==1) && 
	     ( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && ( ele_isGap_->at(iele)==1 ) ) {
	  
	  prof_H_tot_m_singleTower_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_singleTower);
	  prof_H_tot_m_max_2x2_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_max_2x2);
	  prof_H_tot_m_max_seedplus1_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_max_seedplus1);
	  prof_H_tot_m_max_cross_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_max_cross);
	  prof_H_tot_m_max_L_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_max_L);
	  prof_H_tot_m_cell2maxE_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_cell2maxE);
	  prof_H_tot_m_cell3maxE_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_cell3maxE);
	  prof_H_tot_m_cell4maxE_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_cell4maxE);
	  prof_H_tot_m_cell5maxE_vs_genPt_endcap_gap->Fill(eleGenPt_->at(iele),tot_m_cell5maxE);

	} //endcap gap + genmatched + highR9 + pt>50//
	////////////
	/// Endcap noGap
	if ( (ele_isEE_->at(iele)==1) && 
	     ( ele_genmatched_->at(iele)==1 ) && ( eleGenPt_->at(iele) > 50 ) && ( ele_full5x5_r9_->at(iele) > 0.9 ) && ( ele_isGap_->at(iele)==0 ) ) {
	  
	  prof_H_tot_m_singleTower_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_singleTower);
	  prof_H_tot_m_max_2x2_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_max_2x2);
	  prof_H_tot_m_max_seedplus1_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_max_seedplus1);
	  prof_H_tot_m_max_cross_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_max_cross);
	  prof_H_tot_m_max_L_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_max_L);
	  prof_H_tot_m_cell2maxE_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_cell2maxE);
	  prof_H_tot_m_cell3maxE_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_cell3maxE);
	  prof_H_tot_m_cell4maxE_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_cell4maxE);
	  prof_H_tot_m_cell5maxE_vs_genPt_endcap_nogap->Fill(eleGenPt_->at(iele),tot_m_cell5maxE);

	} //endcap nogap + genmatched + highR9 + pt>50//


      } //electron loop ends

   } //event loop ends

   std::cout << "counters " << nEle_highR9_highpT_genmatched << " " <<    nEle_highR9_highpT_genmatched_EnergyInEachCell << std::endl ;


   prof_H_tot_m_singleTower_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_max_2x2_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_max_seedplus1_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_max_cross_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_max_L_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_cell2maxE_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_cell3maxE_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_cell4maxE_vs_genPt_barrel_gap->Write();
   prof_H_tot_m_cell5maxE_vs_genPt_barrel_gap->Write();

   prof_H_tot_m_singleTower_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_max_2x2_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_max_seedplus1_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_max_cross_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_max_L_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_cell2maxE_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_cell3maxE_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_cell4maxE_vs_genPt_barrel_nogap->Write();
   prof_H_tot_m_cell5maxE_vs_genPt_barrel_nogap->Write();

   ////
   prof_H_tot_m_singleTower_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_max_2x2_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_max_seedplus1_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_max_cross_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_max_L_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_cell2maxE_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_cell3maxE_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_cell4maxE_vs_genPt_endcap_gap->Write();
   prof_H_tot_m_cell5maxE_vs_genPt_endcap_gap->Write();

   prof_H_tot_m_singleTower_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_max_2x2_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_max_seedplus1_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_max_cross_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_max_L_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_cell2maxE_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_cell3maxE_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_cell4maxE_vs_genPt_endcap_nogap->Write();
   prof_H_tot_m_cell5maxE_vs_genPt_endcap_nogap->Write();



} // final loop ends
