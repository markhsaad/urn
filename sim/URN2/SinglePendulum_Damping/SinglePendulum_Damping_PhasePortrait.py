import os
import sys

# Get the text file containing the data
folder = os.path.dirname(os.path.realpath(__file__))
file = os.path.join(folder, "phasePortrait.txt")

# Plot the phase portrait
sys.path.append(os.path.join(folder, "..")) # add higher level directory to the path to access PhasePortrait.py
import PhasePortrait
PhasePortrait.plotPhasePortrait(file)