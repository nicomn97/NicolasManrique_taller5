#Make


caos.pdf : caos.txt caos.py
	python caos.py

caos.txt : caos.x
	./caos.x > caos.txt

caos.x : caos.cpp
	g++ -o caos.x caos.cpp
