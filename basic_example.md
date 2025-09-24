# Geant4 Masterclass: Running a basic example
> Author: Adriana Vásquez Ramírez adrianacvr67@gmail.com

This guide walks you through running a **Geant4 simulation inside a container** on a remote server. 


## 1. Connect to the remote server (with graphical interface enabled)
    ssh -Y user@200.16.117.76

## 2. Create the Geant4 container from the provided repository
Reference: https://gitmilab.redclara.net/halleyUIS/geant4

## 3. Start the container
    docker start geant4

## 4. Access the container
    docker exec -it geant4 bash

## 5. Inside the container: 
### a. Copy the example to be tested
    cp -r examples-geant4/basic/B4/B4a/ .

### b. Create a build directory
    mkdir B4a-build

Go to the directory 
    
    cd B4a-build

### c. Compile the code
    cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../B4a/

    make -j2

### d. Run the executable
    ./exampleB4a

### e. In the visualization window, generate events with the following command 
    /run/beamOn 1

### f. Compare particle interactions with 2 MeV 
To set the energy

    /gun/energy 2 MeV

To change the particle try 
    
    /gun/particle gamma
    
To see the interaction     
    
    /run/beamOn 1

---
Try with an electron 

    /gun/particle e-
    /run/beamOn 1

---
Now with a muon 

    /gun/particle mu-
    /run/beamOn 1


### g. Repeat (f) with higher energy (100 MeV or 1 GeV)

### h. Run simulations without visualization 
    ./exampleB4a -m run2.mac > outputfile.out

### i. Open ROOT to inspect histograms in the output file
    root

In root: 
    
    new TBrowser

Select the file and explore the data
    
    outputfile.out

Quit ROOT

    .q  

## 6. Exit and stop the container to close the session
    exit

Stop 
    
    docker stop geant4
