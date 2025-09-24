# Geant4 Masterclass: Creating and modifying histograms 
> Author: Adriana Vásquez Ramírez adrianacvr67@gmail.com

This guide walks you through the process of starting a Docker container, modifying the `B4RunAction.cc` file to change histogram parameters, recompiling the code, and finally visualizing the updated histograms in ROOT. 

## 1. Start a container locally or in remote (Obatala):
    docker start "docker_name"
Execute 

    docker exec -it "docker_name" bash

## 2. Create a new folder where the updated version of example B4a will be compiled:
    mkdir histos

## 3. Modify the source file B4RunAction.cc:
The file is in 

    cd B4a/src/
Open the file     
    
    vim B4RunAction.cc

#### Inside B4RunAction.cc:
#### - Press i to enter insert mode.
#### - Update the histogram values at line 64:

    // Creating histograms
    analysisManager->CreateH1("Eabs","Edep in absorber", 10000, 0., 100MeV);
    analysisManager->CreateH1("Egap","Edep in gap", 10000, 0., 100MeV);
    analysisManager->CreateH1("Labs","trackL in absorber", 1000, 0., 1m);
    analysisManager->CreateH1("Lgap","trackL in gap", 1000, 0., 1m);
#### - Save changes and exit vim
    :wq

## 4. Compile the new version in the histos folder:
    cd ../../histos/
Recompile the example

    cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../B4a/; make -j2;

## 5. Modify run2.mac to send 1000 gammas of 4 MeV:
    vim run2.mac

Run the new simulation
    
    ./exampleB4a -m run2.mac

## 6. Visualize the histograms in B4.root with the new resolution (number of bins):
    root
Open your file 
    
    new TBrowser
Exit root 
    
    .q


