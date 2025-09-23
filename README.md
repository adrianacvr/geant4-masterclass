# Geant4 Masterclass: Running a basic example
> Author: Adriana Vásquez Ramírez adrianacvr67@gmail.com

This guide walks you through running a **Geant4 simulation inside a container** on a remote server. 


## 1. Connect to the remote server (with graphical interface enabled)
`ssh -Y user@200.16.117.76`

## 2. Create the Geant4 container from the provided repository
Reference: https://gitmilab.redclara.net/halleyUIS/geant4

## 3. Start the container
`docker start geant4`

## 4. Access the container
`docker exec -it geant4 bash`

## 5. Inside the container: 
### a. Copy the example to be tested
`cp -r examples-geant4/basic/B4/B4a/ .`

### b. Create and move into a build directory
`mkdir B4a-build`

`cd B4a-build`

### c. Compile the code
`cmake -DGeant4_DIR=/opt/geant4/lib/Geant4-10.3.3/ ../B4a/`

`make -j2`

### d. Run the executable
`./exampleB4a`

### e. In the visualization window, generate events
`/run/beamOn 1`

### f. Compare particle interactions with 2 MeV
`/gun/particle gamma`

`/gun/energy 2 MeV`

`/run/beamOn 1`

---

`/gun/particle e-`

`/gun/energy 2 MeV`

`/run/beamOn 1`

---

`/gun/particle mu-`

`/gun/energy 2 MeV`

`/run/beamOn 1`

---

### g. Repeat with higher energy (100 MeV)

### h. Run simulations without visualization 
`./exampleB4a -m run2.mac > outputfile.out`

### i. Open ROOT to inspect histograms in the output file
`root`

`new TBrowser`

`Select outputfile.out`

`.q`  to quit ROOT

## 6. Exit and stop the container to close the session
`exit`

`docker stop geant4`
