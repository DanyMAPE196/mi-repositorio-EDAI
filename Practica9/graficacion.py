print("\n===Ejemplo 1===\n")
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

x = np.linspace(0, 5, 20)  

fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot(x, np.sin(x), marker='o', color='r', linestyle='None')
ax.set_xlabel('x')      
ax.set_ylabel('y')      
ax.grid(True)
ax.legend(["y = sin(x)"])

plt.title("Puntos")
plt.show()

fig.savefig("grafica.png")