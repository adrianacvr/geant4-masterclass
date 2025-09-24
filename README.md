# Geant4 Masterclass
> Author: Adriana Vásquez Ramírez adrianacvr67@gmail.com

This repository provides step-by-step instructions for running Geant4 exercises on a remote server using a Docker container with Geant4 pre-installed. The activities are designed as a practical introduction to detector simulations, data visualization, and data analysis workflows combining Geant4, ROOT, and Python.

The following list summarizes the activities included in this masterclass:

## 1. Running a basic example
In the file `basic_example.md`, you will find step-by-step instructions to run a simple Geant4 example. You will learn how to visualize the geometry, adjust the energy, type, and number of interacting particles, and use ROOT to inspect the results of the interaction.

## 2. Data visualization
In this module, you will practice refining the histograms obtained in the previous exercise. You will explore how to adjust the binning, range, titles, and variables to be plotted. Follow the guidelines in `basic_example_histograms.md`.

## 3. Histograms from ROOT to Python with uproot
Often, it is more practical to work with histograms directly in Python, especially when making small adjustments such as changing the binning, without recompiling the Geant4 code. 

For those who prefer Python workflows, you can convert `.root` output files into Python arrays using the `uproot` library. The file `uproot_example.md` provides an example of how to make this conversion and continue your analysis in Python.

## 4. Simulation of a particle detector: Scintillator Bar
In this module, you will move on to a more sophisticated detector: the scintillator bar of the Muon Telescope (MuTe). You will investigate how the detector responds to muons and electrons crossing the bar at different positions. Instructions can be found in `scintillator_bar.md`.

## 5. Simulation of a particle detector: Water Cherenkov Detector
Finally, you will run a full simulation to study the response of a Water Cherenkov Detector (WCD) to secondary particles in Bucaramanga, Colombia. For this, use the `wcd_flux_corsika` folder along with the instructions in `water_cherenkov_detector.md`. 

If you have any questions, feel free to contact me.
