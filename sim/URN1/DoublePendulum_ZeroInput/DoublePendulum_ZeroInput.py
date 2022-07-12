import os
import numpy
import pandas
import matplotlib.pyplot as plt
import matplotlib.animation as animation

folder = os.path.dirname(os.path.realpath(__file__))
file = os.path.join(folder, "state.txt")

# Import the data
data = pandas.read_csv(file, sep='\t').values
data = numpy.delete(data, -1, axis=1) # ignore last column as it is just an extra tab that results in nan values

# Parse the data
q1  = data[:, 0] # theta1
q2  = data[:, 2] # theta2

# Plot the pendulum
l1 = 1 # link 1 length [m]
l2 = 1 # link 2 length [m]

x0 = 5 # pendulum origin x
y0 = 5 # pendulum origin y

x1 = x0 + l1 * numpy.sin(q1[0]) # mass 1 x
y1 = y0 - l1 * numpy.cos(q1[0]) # mass 1 y

x2 = x1 + l2 * numpy.sin(q2[0]) # mass 2 x
y2 = y1 - l2 * numpy.cos(q2[0]) # mass 2 y

fig = plt.figure()
ax = fig.add_subplot(aspect='equal')
fig.subplots_adjust(left=0, bottom=0, right=1, top=1, wspace=None, hspace=None)
plt.axis('off')

ax.plot([x0 - 1, x0 + 1], [y0, y0], 'k') # plot the base

link1, = ax.plot([x0, x1], [y0, y1], 'k') # plot the first link
link2, = ax.plot([x1, x2], [y1, y2], 'k') # plot the second link

mass1 = ax.add_patch(plt.Circle([x1, y1], 0.1, fc='r', zorder=4)) # plot the first mass
mass2 = ax.add_patch(plt.Circle([x2, y2], 0.1, fc='r', zorder=5)) # plot the second mass

def animate(i):
    x1 = x0 + l1 * numpy.sin(q1[i])
    y1 = y0 - l1 * numpy.cos(q1[i])

    x2 = x1 + l2 * numpy.sin(q2[i])
    y2 = y1 - l2 * numpy.cos(q2[i])

    link1.set_data([x0, x1], [y0, y1])
    link2.set_data([x1, x2], [y1, y2])

    mass1.set_center((x1, y1))
    mass2.set_center((x2, y2))

    plt.xlim(2, 8)
    plt.ylim(2, 6)

anim = animation.FuncAnimation(fig, animate, frames=q1.size, repeat=False, interval=20)
anim.save(os.path.join(folder, "BP13_URN1_F2.gif"), writer='pillow')
plt.show()



