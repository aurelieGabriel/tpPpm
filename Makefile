all : ppmModification.out

ppmModification.out : ppmModification.cpp Image.o
	g++ -Wall -o ppmModification.out ppmModification.cpp Image.o

biblio.o : Image.h Image.cpp
	g++ -Wall -o Image.o Image.cpp -c

clean:
	rm *.o
mrproper: clean
	rm ppmModification.out

