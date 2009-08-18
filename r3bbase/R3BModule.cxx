#include "R3BModule.h"

#include <iostream>
using namespace std;

// -----   Default constructor   -------------------------------------------
R3BModule::R3BModule() : FairModule() {
 // Create Matrix Unity
    fGlobalRot = new TGeoRotation();

 // Create a null translation
    fGlobalTrans = new TGeoTranslation();
    fGlobalTrans->SetTranslation(0.0,0.0,0.0);
}

// -----   Standard constructor   ------------------------------------------
R3BModule::R3BModule( const Char_t* Name, const Char_t* title, Bool_t Active)
    : FairModule(Name,title,Active) {

 // Create Matrix Unity
    fGlobalRot = new TGeoRotation();

 // Create a null translation
    fGlobalTrans = new TGeoTranslation();
    fGlobalTrans->SetTranslation(0.0,0.0,0.0);

}

// -----   Destructor   ----------------------------------------------------
R3BModule::~R3BModule() {

}

void R3BModule::SetRotAngles(Double_t phi, Double_t theta, Double_t psi){
 // Euler Angles definition
 // This represent the composition of : first a rotation about Z axis with
 // angle phi, then a rotation with theta about the rotated X axis, and
 // finally a rotation with psi about the new Z axis.

  fGlobalRot->SetAngles(phi, theta, psi); // all angles in degrees

}

void R3BModule::SetTranslation(Double_t tx, Double_t ty, Double_t tz){

  fGlobalTrans->SetTranslation(tx,ty,tz);

}


ClassImp(R3BModule)
  
