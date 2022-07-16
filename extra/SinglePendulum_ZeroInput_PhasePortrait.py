import os
import numpy
import pandas
import matplotlib.pyplot as plt

folder = os.path.dirname(os.path.realpath(__file__))
file1 = os.path.join(folder, "state.txt")
file2 = os.path.join(folder, "input.txt")

# Import the data
state = pandas.read_csv(file1, sep='\t').values
state = numpy.delete(state, -1, axis=1) # ignore last column as it is just an extra tab that results in nan values

input = pandas.read_csv(file2, sep='\t').values
input = numpy.delete(state, -1, axis=1) # ignore last column as it is just an extra tab that results in nan values

# Parse the data
x1 = state[:, 0]
x2 = state[:, 1]

u = input[:, 0]

# Compute dxdt
dx1 = x2
dx2 = u - 9.81 * numpy.sin(x1)

# Plot the phase portrait (plot every i'th point to avoid cluttering the plot)
i = numpy.arange(0, len(x1), 500)

plt.quiver(x1[i], x2[i], dx1[i], dx2[i])
plt.xlabel("$ \\theta $")
plt.ylabel("$ \\dot{\\theta} $")

plt.show()