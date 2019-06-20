Main: Main.o leerArchivo.o
	g++ Main.o leerArchivo.o -lncurses
Main.o: Main.cpp
	g++ -c Main.cpp
leerArchivo.o: leerArchivo.cpp leerArchivo.h
	g++ -c leerArchivo.cpp