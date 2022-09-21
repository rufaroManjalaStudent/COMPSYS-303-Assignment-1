README

Assignment 1: Making a virtual DDD_Pacemaker, and emulating using NIOS and a DE115 FPGA development board.
Group 7 (Rufaro Manjala, Caleb Brunton)


About: Required version for KIELER (SCCHARTS):  KIELER	1.2.0.202107040812
(In order to view the simulation of our SCCHART on Windows you must have GCC installed.
Verify opening Command Prompt (CMD) and running the following command
"gcc --version").

To open and view the scchart, download the DDD_Pacemaker project file. Open the project using KIELER, and open the file DDD_Pacemaker_V2.sctx.
To view the simulation click the green "Start new simulation" button, in top right hand corner and make sure "Netlist-based Simulation (C)" is selected as the compiler.
Otherwise you may run into issues (caused by, what we believe to be, the use of clocks as they are buggy in this version of KIELER.). 

There are several test values you can use in the simulation of the SCChart. These are found in the "timing.h" header file.

Breakdown of values
// All values are in milliseconds
// Descriptions of values are taken from assignment brief
#define AVI_VALUE 300 // Atrioventricular Interval - The maximum time between an atrial event and its subsequent ventricular event
#define AEI_VALUE 800 // Atrial Escape Interval - The maximum time between a ventricular event and its subsequent atrial event.
#define PVARP_VALUE 50 // Post-Ventricular Atrial Refractory Period - The time after a ventricular event where any atrial events are ignored as Atrial Refractory (AR) signals
#define VRP_VALUE 150 // Ventricular Refractory Period - The time after a ventricular event where any other ventricular events are ignored as Ventricular Refractory (VR) signals.
#define LRI_VALUE 950 // Lower Rate Interval - The slowest rate at which the heart is allowed to operate. This is measured as the time between ventricular events
#define URI_VALUE 900 //  Upper Rate Interval - The fastest rate at which the pacemaker will ever pace the heart at. This is measured as the time between ventricular events



Unfortunately we could not complete the assignment due to our poor time management skills.
This means our SCCHART of the DDD Pacemaker doesn't exhibit 100% behaviour, and that we did not implement the pacemaker 
on the FPGA.

