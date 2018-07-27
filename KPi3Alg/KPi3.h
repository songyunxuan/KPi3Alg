#ifndef Physics_Analysis_KPi3_H
#define Physics_Analysis_KPi3_H 

#include "GaudiKernel/AlgFactory.h"
#include "GaudiKernel/Algorithm.h"
#include "GaudiKernel/NTuple.h"    //No NTuple!
//#include "VertexFit/ReadBeamParFromDb.h"
#include "PartPropSvc/PartPropSvc.h"  

#include <string>
#include <TTree.h>
#include <TROOT.h>
#include <TLorentzVector.h>
#include <TFile.h>

#include "EvtRecEvent/EvtRecEvent.h"
#include "EvtRecEvent/EvtRecTrack.h"
#include "RootCnvSvc/RootCnvSvc.h"

#include "TROOT.h"
#include "TBenchmark.h"

#include "CLHEP/Matrix/SymMatrix.h"
#include "CLHEP/Matrix/Matrix.h"
#include "CLHEP/Matrix/Vector.h"
#include "CLHEP/Vector/LorentzVector.h"
#include "CLHEP/Vector/ThreeVector.h"
#include "VertexFit/WTrackParameter.h"
#include "MdcRecEvent/RecMdcTrack.h"
#include "MdcRecEvent/RecMdcKalTrack.h"

class KPi3 : public Algorithm {

	public:
		KPi3(const std::string& name, ISvcLocator* pSvcLocator);
		StatusCode initialize();
		StatusCode execute();
		StatusCode finalize();
        StatusCode corset();
        StatusCode corgen();
        StatusCode calibration();  

	private:
		IPartPropSvc *p_PartPropSvc;
		HepPDT::ParticleDataTable* m_particleTable;

        void corgen(HepMatrix &, HepVector &, int );
        void corset(HepSymMatrix &, HepMatrix &, int );
        void calibration(RecMdcKalTrack * , HepVector &, int );
		//Declare r0, z0 and cos cut for charged tracks
		Double_t m_vr0cut;
		Double_t m_vz0cut;
		Double_t m_ccoscut;
		Double_t m_ptcut;
		Double_t m_pcut;

		//Declare energy, dphi, dthe cuts for fake gamma's
		Double_t m_isoAngleCut;
		
		//Declare flag for cut flow
		Int_t m_cutFlow;

		//Declare flag for analysis
		Int_t m_readSig;

		//Declare flag for MCTruth
		Int_t m_mcTruth;

		//Declare type of psi. For Jpsi psitype=1, for psip psitype=0
		Int_t m_psiType;
                
        Int_t m_useVxfitCut;
        Int_t m_useKmfitCut;
		//Declare name of output file
		std::string m_OutputFileName;
		TFile *saveFile;

		//Define TCutFlow here
		TTree *TCutFlow;
		Int_t cutflow;

		//Define TreeAna here
		TTree *TreeAna;

		//For header
		Int_t runid;
		Int_t evtid;
		Int_t nevt;
        Int_t n_gamma;

        //Number of good photons.
        Int_t nGamma;

        Int_t n_endgamma;
        Int_t n_charged;
               
		Double_t m_dang[500];
        Double_t m_Rxy[500];
        Double_t m_tdc[500];
        Double_t m_z0[500];

        TLorentzVector *kp;
        TLorentzVector *pim;
        TLorentzVector *pips;
        TLorentzVector *pims;

		//For storing 4-mom of particles. Change names below according to your channel
        //After 4c
/*
        TLorentzVector *pip;
        TLorentzVector *pim;
        TLorentzVector *kp;
        TLorentzVector *km;
*/
        //Before 4c

        TLorentzVector *pip_unfitted;
        TLorentzVector *pim_unfitted;
        TLorentzVector *kp_unfitted;
        TLorentzVector *km_unfitted;

        TLorentzVector *ep_unfitted;
        TLorentzVector *em_unfitted;
		//For further cut. Add your own cut here
 		TLorentzVector *etap_mc;
 		TLorentzVector *pi0_mc;
 		TLorentzVector *eta_mc;
 		TLorentzVector *gamma2_mc;
		TLorentzVector *ep_mc;
		TLorentzVector *em_mc;

      	Double_t V_xy;
		Double_t vxchisq;
		Double_t kmchisq_4c;
        Double_t Chisq_low;
		Double_t EOP_p;
		Double_t Edpop;
		Double_t Edpom;
        Double_t EOP_m;
		Double_t Prob_ep;
		Double_t Prob_em;
		Double_t Prob_pip;
        Double_t Prob_pim;
        Double_t P_ep;
        Double_t P_ep2;
        Double_t P_em;
        Double_t P_em2;
		Double_t PD_p;
        Double_t PD_m;
          //gamma conversion
	 	Double_t m_xconv1;
        Double_t m_yconv1;
	 	Double_t m_zconv1;
		Double_t m_rconv1;
        Double_t m_xconv2;
        Double_t m_yconv2;
        Double_t m_zconv2;
        Double_t m_rconv2;
        Double_t m_xiep;
        Double_t m_deltaxy;
               
   		Double_t m_deltaz1;
        Double_t m_deltaz2;

        Double_t m_lep;
        Double_t m_psipair;
//      Double_t m_dgamma;
        Double_t MEE;
        Double_t m_vx_x;
        Double_t m_vx_y;
        Double_t m_vx_r;
        Double_t m_thetaeg1;
        Double_t m_thetaeg2; 
 		Double_t m_cthep;
        Double_t m_ptrkp;
        Double_t m_ptrkm;
        Double_t m_mgamma;
        Double_t m_egamma;
        Double_t m_theta;
        Double_t m_cosTheta;
        Double_t m_phi;
		Double_t m_rp;
        Double_t m_re;
        Double_t m_deltaeq;
  		Double_t m_case;
   		//Define TMCTruth Here

		TTree *TMCTruth;

		Int_t pdgid[500];
		Int_t indexmc;
		Int_t motheridx[500];

        TLorentzVector *p_f0_mctruth;
        //The P of photon in the truth level.
        /*
        TLorentzVector *p_g1_mctruth;
        TLorentzVector *p_g2_mctruth;
        TLorentzVector *p_g3_mctruth;
        TLorentzVector *p_g4_mctruth;
        */
        TLorentzVector *p_pip_mctruth;
        TLorentzVector *p_pim_mctruth;
        TLorentzVector *p_kp_mctruth;
        TLorentzVector *p_km_mctruth;
        TLorentzVector *p_etap_mctruth;

        //Define TCount, record the number of events generated.
        TTree *TCount;
        Int_t num_event;

		//Record the number of photons in end cap.
		Int_t my_ngam_end;

        //Tag whether 4 charged track
        Int_t tag_4charged;
        Int_t tag_Ks_PID;
};

#endif 
