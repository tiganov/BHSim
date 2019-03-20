# THIS REPO IS NOT COMPLETE - SRC FILES NOT ADDED YET

# Black Hole Simulator
Black hole simulator created for ASTRO 101 Creative Work assignment. This repo is mostly self contained and is basically a pruned ![openFrameworks repo](https://github.com/openframeworks/openFrameworks). 

![](https://github.com/tiganov/BHSim/blob/master/gifs/example.gif)

## Description
I'm working on a spinless stellar-mass black hole simulator written using openFrameworks (C++ creative coding framework).

Basically I am just having a stationary black hole with a bunch of 'protons' (constant-speed particles) randomly populating the space around, then simulating the black hole's effect on them. I am using the proper formulas for calculating Schwarzchild radius and gravitational pull on a particle, then scaling their outputs down. I added some parameters for assisting the visualization.

Some issues I am having:
- Simulating at the speed of light is too computationally expensive and doesn't help the visualization (duh)
- The 3D draw distance is too small and there's not enough particles in play to see an accretion disk forming (more particles = more lag, so there is a practical particle limit)
- Pretty sure the ISCO is not even close to where it's supposed to be (due to the weird scaling)
- I have to scale everything down (hence the scale slider - everything is * 1/SCALE)
- Don't know how to account for angular momentum (hence spinless) - might also be extremely computationally expensive to do so

I can't really deploy it so that everyone can interact and use it since the framework I use isn't meant for cross-platform  deployment. There are, however, build instructions if would like to compile it yourself.

## Suggestions
- Basically turn it into a visualization rather than a simulation
- Simplify the model

## Build instructions (with QT Creator)
1. Using Ubuntu 18.04 LTS
2. Install Qt Creator from https://www.qt.io/download-qt-installer
3. Download openFrameworks from https://openframeworks.cc/download/
4. Follow these instructions https://openframeworks.cc/setup/linux-install/
5. Run `install_template.sh` script in `scripts/qtcreator`
6. Clone this repo
7. Open `apps/Sim/Sim.qbs` in Qt Creator
8. Click `Configure Project`
9. If you like, change the build folder in `Projects` for Debug and Release. Add these new directories to `.gitignore`
