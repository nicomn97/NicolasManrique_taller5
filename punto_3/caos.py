import numpy as np
import matplotlib.pyplot as plt


datos=np.transpose(np.genfromtxt("caos.txt",delimiter=" "))



plt.figure(figsize=(18,9))
plt.scatter(datos[0,:20],datos[1,:20],label='$P_{2}\ vs\ q_{2}$', c='b')
plt.title('$Caos$')
plt.xlabel('$q_{2}$')
plt.ylabel('$P_{2}$')
plt.legend()
plt.savefig("caos.pdf")
