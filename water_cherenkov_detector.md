# Geant4 Masterclass: The Water Cherenkov Detector (WCD)
> Author: Adriana Vásquez Ramírez adrianacvr67@gmail.com

## 1. In docker:

Clone this repository and use the folder `wcd_flux_corsika`, which contains the WCD source code.

## 2. In your local: 

Download the CORSIKA file `salidasimu.shw.bz2` in:

https://drive.google.com/file/d/16BHZksUYniZ5w_Vg9jZYT5K5iQEjy4jt/view

Copy it into the `wcd_flux_corsika` source folder as follows:  

    docker cp LOCAL_PATH CONTAINER_NAME:CONTAINER_PATH

**On my computer** it would be:  

    cp /Users/macbookpro/Downloads/salidasimu.shw.bz2 geant4-mc:/root/wcd_flux_corsika

## 3. Check in your docker if the file was copied into the `wcd_flux_corsika` folder with the `ls` command:     
    cd wcd_flux_corsika  
    ls *.shw.bz2

## 4. Create a new folder to compile the WCD program:  
    mkdir wcd-build  
    cd wcd-build  
    cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../wcd_flux_corsika/; make -j2;

## 5. Visualize the detector:  
    ./wcd  
    /run/beamOn

## 6. To simulate the WCD response to the flux of secondary particles in Bucaramanga:  
Check or modify the number of secondary particles in the `input.in` file:  

    /run/beamOn 10000   #Recommendation for today’s class 
    /run/beamOn 3855333 #This corresponds to 1 hour of flux per m2 in Bucaramanga

To run the simulation:  

    time ./wcd -m input.in

## 7. Review and analyze the histograms obtained with 10000 particles.
