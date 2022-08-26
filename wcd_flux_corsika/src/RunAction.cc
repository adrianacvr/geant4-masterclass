
// Geant4 Libraries
//
#include "G4Timer.hh"
#include "RunAction.hh"
#include "G4Run.hh"
#include "g4root.hh"
#include "G4SystemOfUnits.hh"



RunAction::RunAction()
 : G4UserRunAction(),
   fTimer(0)
{
  fTimer = new G4Timer;

	G4AnalysisManager* analysisManager 
      = G4AnalysisManager::Instance();

	analysisManager->SetVerboseLevel(1);
	analysisManager->SetActivation(true);
  //analysisManager->CreateH1("0","Total de fotones generados por efecto Cherenkov", 50000, 0., 50000.);
  analysisManager->CreateH1("0","Fotones detectados por el Pmt", 5000, 0., 5000.); 
  analysisManager->CreateH1("1","Distancia en agua", 3000, 0., 3000.); 
 // analysisManager->CreateH1("3","Fotones que alcanzan el Pmt", 1000, 0., 5000.);

 analysisManager->SetFirstHistoId(2);
 G4int id = analysisManager->CreateH2("2","Fotones vs Distancia en agua", 3000, 0., 3000., 5000, 0., 5000.);
 analysisManager->SetH2Activation(id, true);



  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
  delete fTimer;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  fTimer->Start();

  G4AnalysisManager* analysisManager
     = G4AnalysisManager::Instance();

  G4String rootFile = "wcdRoot";
  analysisManager->OpenFile(rootFile);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  fTimer->Stop();
  G4cout << "number of event = " << aRun->GetNumberOfEvent()
         << " " << *fTimer << G4endl;

  G4AnalysisManager* analysisManager
     = G4AnalysisManager::Instance();
  analysisManager->Write(); 
  analysisManager->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
