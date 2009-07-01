////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// AliFemtoCorrFctnDEtaDPhi - A correlation function that analyzes            //
// two particle correlations with respect to the azimuthal angle (phi)        //
// and pseudorapidity (eta) difference                                        //
//                                                                            //
// Authors: Adam Kisiel Adam.Kisiel@cern.ch                                   //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef ALIFEMTOCORRFCTNDETADPHI_H
#define ALIFEMTOCORRFCTNDETADPHI_H

#include "TH1D.h"
#include "TH2D.h"
#include "AliFemtoCorrFctn.h"

class AliFemtoCorrFctnDEtaDPhi : public AliFemtoCorrFctn {
public:
  AliFemtoCorrFctnDEtaDPhi(char* title, const int& aPhiBins, const int& aEtaBins);
  AliFemtoCorrFctnDEtaDPhi(const AliFemtoCorrFctnDEtaDPhi& aCorrFctn);
  virtual ~AliFemtoCorrFctnDEtaDPhi();

  AliFemtoCorrFctnDEtaDPhi& operator=(const AliFemtoCorrFctnDEtaDPhi& aCorrFctn);

  virtual AliFemtoString Report();
  virtual void AddRealPair(AliFemtoPair* aPair);
  virtual void AddMixedPair(AliFemtoPair* aPair);

  virtual void Finish();

  void WriteHistos();
  virtual TList* GetOutputList();
private:
  
  TH2D *fDPhiDEtaNumerator;          // Numerator of dEta dPhi function
  TH2D *fDPhiDEtaDenominator;        // Denominator of dEta dPhi function

  TH2D *fDPhiDEtaColNumerator;       // Numerator of colinear dEta dPhi function 
  TH2D *fDPhiDEtaColDenominator;     // Denominator of colinear dEta dPhi function

  TH1D *fDPhiNumerator;              // Numerator of dPhi correlation
  TH1D *fDPhiDenominator;            // Denominator of dPhi correlation

  TH1D *fDCosNumerator;              // Numerator of colinearity correlation
  TH1D *fDCosDenominator;            // Denominator of colinearity correlation

  TH2D *fDPhiPtNumerator;            // Numerator of dPhi correlation vs. Pt min
  TH2D *fDPhiPtDenominator;          // Denominator of dPhi correlation vs. Pt min

  TH2D *fDCosPtNumerator;            // Numerator of colinearity correlation vs. Pt min
  TH2D *fDCosPtDenominator;          // Denominator of colinearity correlation vs. Pt min

#ifdef __ROOT__
  ClassDef(AliFemtoCorrFctnDEtaDPhi, 1)
#endif
};


#endif

