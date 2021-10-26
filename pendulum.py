'''hello everyone!!! I am Pratyush and this is a basic matplotlib project to visualize damped oscillations of pendulum using Euler's integration method.

Basically Euler's Integration uses Taylor's series to decompose second order diff. eqn to a two variable first order iterative sequence(here omega and theta of pendulum)

this code will create plot the damped oscillation graph and gif of animation of pendulum will be save in the same folder where code was saved'''

import numpy as np
import matplotlib.pyplot as plt
import math
import matplotlib.animation as animation

def model(theta,t,b,g,l,m):
    theta1 = theta[0]
    theta2 = theta[1]
    dtheta1_dt = theta2
    dtheta2_dt = -(b/m)*theta2 - (g/l)*math.sin(theta1)
    dtheta_dt =[dtheta1_dt, dtheta2_dt]
    return dtheta_dt

b=0.15         #damping constant

g=-9.8         #gravity

l=1            #length of rod of pendulum

m=0.5         #mass of pendulum in kg

theta_0 = [math.pi/2,0]  #declaring initial angle as 90 and initial angular speed as 0

t =np.linspace(0,10,140)

def euler_integration_pendulum(theta_init, t, l, g): #algorithm
    theta1 = [theta_0[0]]
    theta2 = [theta_0[1]]
    dt = t[1] - t[0]
    for i, t_ in enumerate(t[:-1]):
        next_theta1 = theta1[-1] + theta2[-1] * dt                     #iterations
        next_theta2 = theta2[-1] - (b/(m*l**2) * theta2[-1] - g/l *
            np.sin(next_theta1)) * dt
        theta1.append(next_theta1)
        theta2.append(next_theta2)
    return np.stack([theta1, theta2]).T

theta = euler_integration_pendulum(theta_0, t, l, g)

plt.figure()                                             #plotting of damping oscilations
plt.plot(t, theta[:,0], 'y-')
plt.plot(t, theta[:,1], 'g-')
plt.ylabel('Plot(yellow is of angle and green is of omega)')
plt.xlabel('time')
plt.legend (loc='best')
plt.show()

fig= plt.figure(figsize=(5, 5), facecolor='w')
ax=fig.add_subplot(1, 1, 1)
plt.rcParams['font.size'] = 15

lns =[]
for i in range (len(theta)):
#plotting the string/chord
    ln,=ax.plot([0, np.sin(theta[i, 0])], [0, -np.cos(theta[i, 0])], color='k', lw=2)

#plotting the bob
    bob, = ax.plot(np.sin(theta[i, 0]), -np.cos(theta[i, 0]), 'o',markersize=20, color='g')

#plotting the time for simulation
    tm = ax.text(-0.9, 0.25, 'Time = %.1fs' % t[i])
    lns.append([ln, bob, tm])

ax.set_aspect('equal', 'datalim')


ani = animation. ArtistAnimation(fig, lns, interval=50)                  #animation of pendulum

writergif = animation.PillowWriter(fps=30)
ani.save('pendulum.gif',writer=writergif)
