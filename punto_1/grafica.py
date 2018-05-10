import numpy as np
import matplotlib.pyplot as plt

datos=np.genfromtxt("test.txt",delimiter=" ")

n=np.shape(datos)[0]
m=int(np.sqrt(np.shape(datos)[1]))

dato=datos[0,:].reshape((m,m))
ex=np.transpose(datos[1,:].reshape((m,m)))
ey=np.transpose(datos[2,:].reshape((m,m)))
pos=np.linspace(0,5,num=512)

plt.imshow(np.transpose(dato), cmap='bone',aspect="auto", extent=[0, 5, 0, 5])
plt.xlabel("cm")
plt.ylabel("cm")
plt.colorbar().set_label("Voltaje",rotation=270)
plt.streamplot(pos,pos,ex,ey,density=0.8,linewidth=0.4,color="b")
nombre="placas.pdf"
plt.savefig(nombre)



