# Geant4 Masterclass: The Scintillator Bar of MuTe
> Author: Adriana Vásquez Ramírez adrianacvr67@gmail.com

## 1. In your container, clone the MuTe scintillator bar repository:
    git clone https://github.com/adrianacvr/Simulacion-barra-MuTe.git

## 2. Create and enter the folder where the code will be compiled:
    mkdir barra
    cd barra
## 3. Compile:
    cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../Simulacion-barra-MuTe/; make -j2;

## 4. Run the program to visualize the bar:
    ./bar

## 5. Launch a test simulation:
    ./bar -m input.in

## 6. Check the histograms in the output file `scintbar.root`:
    root
    new TBrowser
    .q 

## To do:
- Launch 100 mu- of 1 GeV at both ends of the bar (z = -58 cm and 58 cm).
- Launch 100 e- of 1 GeV at both ends of the bar (z = -58 cm and 58 cm).
- Analyze the differences between the histograms in each case.

## For further details on this simulation check the repo https://github.com/adrianacvr/Simulacion-barra-MuTe
