import numpy
import pandas
import matplotlib.pyplot as plt

def plotPhasePortrait(file, fig):
    # Import the data
    data = pandas.read_csv(file, sep='\t', header=None).values
    data = numpy.delete(data, -1, axis=1) # ignore last column as it is just an extra tab that results in nan values

    # Parse the data
    x1 = data[:, 0]
    x2 = data[:, 1]

    dx1 = data[:, 2]
    dx2 = data[:, 3]

    # Reshape the data into matrices to work with streamplot
    numRows = (int)(numpy.nonzero(numpy.diff(x1))[0][0]) + 1
    numCols = (int)(x1.shape[0] / numRows)

    x1 = x1.reshape(numRows, numCols).T
    x2 = x2.reshape(numRows, numCols).T

    dx1 = dx1.reshape(numRows, numCols).T
    dx2 = dx2.reshape(numRows, numCols).T

    # Plot the phase portrait
    plt.streamplot(x1, x2, dx1, dx2, density=2)

    # Place the origin in the center of the plot
    ax = plt.gca()

    ax.spines['top'].set_color('none')
    ax.spines['left'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_position('zero')

    # Mark the downward and upward equilibrium points
    plt.plot(-3.14, 0, 'rx')
    plt.plot(0, 0, 'rx')
    plt.plot(3.14, 0, 'rx')

    # Save the figure
    plt.savefig(fig)

    # Display the phase portrait
    plt.show()

