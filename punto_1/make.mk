#Make


placas.pdf : test.txt grafica.py
	python grafica.py

test.txt : a.out
	./a.out > test.txt

a.out : placas.cpp
	g++ placas.cpp
