//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// -------------------------------------------------------------------
//
// GEANT4 Class header file
//
//
// File name:     G4SCProcessorStand
//
// Author:        Vladimir Ivanchenko
//
// Creation date: 03.01.2002
//
// Modifications:
//
// 26-12-02 Secondary production moved to derived classes (V.Ivanchenko)
// 29-12-02 Change interface (V.Ivanchenko)
// 27-01-03 Make models region aware (V.Ivanchenko)
// 13-02-03 Add name (V.Ivanchenko)
//
// Class Description:
//
// Class for simualtion of subCutoff

// -------------------------------------------------------------------
//

#ifndef G4SCProcessorStand_h
#define G4SCProcessorStand_h 1


#include "G4VSubCutoffProcessor.hh"
#include "G4PhysicsTable.hh"
#include "G4DataVector.hh"

class G4Navigator;
class G4MaterialCutsCouple;

class G4SCProcessorStand   :  public G4VSubCutoffProcessor
{

public:

  G4SCProcessorStand(const G4String& nam = "ProcSTD");

  ~G4SCProcessorStand();

  virtual G4std::vector<G4Track*>* SampleSecondaries(const G4Step&,
						           G4double& tmax,
						           G4double& meanLoss,
                                                           G4VEmModel*) = 0;

  virtual void Initialise(const G4ParticleDefinition*,
                          const G4ParticleDefinition*,
                          const G4DataVector*,
                          const G4DataVector*) = 0;

  virtual void SetLambdaSubTable(G4PhysicsTable*);

  virtual G4PhysicsTable* LambdaSubTable();

protected:

private:

  // hide assignment operator
  G4SCProcessorStand & operator=(const  G4SCProcessorStand &right);
  G4SCProcessorStand(const  G4SCProcessorStand&);

  G4PhysicsTable* theLambdaSubTable;
  const G4ParticleDefinition* particle;
  const G4ParticleDefinition* secondaryParticle;
  const G4ParticleDefinition* thePositron;
  G4Navigator* navigator;
  const G4DataVector* theCuts;
  const G4DataVector* theSubCuts;

  // cash
  G4double initialMass;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void G4SCProcessorStand::SetLambdaSubTable(G4PhysicsTable* table)
{
  if(theLambdaSubTable) theLambdaSubTable->clearAndDestroy();
  theLambdaSubTable = table;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline G4PhysicsTable* G4SCProcessorStand::LambdaSubTable()
{
  return theLambdaSubTable;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#endif
