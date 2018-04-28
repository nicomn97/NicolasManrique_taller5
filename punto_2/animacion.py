import numpy as np
import matplotlib.pyplot as plt
import glob
import imageio

datos=np.genfromtxt("cuerda.txt",delimiter=" ")

n=np.shape(datos)[0]-1
i=1

nombres=[]
while i <=n:
    plt.figure(figsize=(18,9))
    plt.plot(datos[0,:],datos[i,:],c="b")
    plt.ylabel("$u(x,t)\ (m)$")
    plt.xlabel("$x\ (m)$")
    plt.xlim(-0.1, 100.1)
    plt.ylim(-1.1, 1.1)
    nombre="cuerda_"+str(i)+".png"
    plt.savefig(nombre)
    nombres.append(nombre)
    i+=1


imagenes = []
for nombre in nombres:
    imagenes.append(imageio.imread(nombre))
imageio.mimsave("animacion.gif", imagenes, duration = 0.2)
