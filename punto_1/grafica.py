import numpy as np
import matplotlib.pyplot as plt

datos=np.genfromtxt("test.txt",delimiter=" ")

n=np.shape(datos)[0]
m=int(np.sqrt(np.shape(datos)[1]))

dato=datos[0,:].reshape((m,m))
ex=datos[1,:].reshape((m,m))
ey=datos[2,:].reshape((m,m))

plt.imshow(dato, cmap='bone',aspect="auto", extent=[0, 5, 0, 5])
plt.xlabel("cm")
plt.ylabel("cm")
plt.colorbar().set_label("Voltaje",rotation=270)
nombre="placas.pdf"
plt.savefig(nombre)



