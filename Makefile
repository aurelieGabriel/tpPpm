all : ppmModification.out

ppmModification.out : ppmModification.cpp biblio.o
	g++ -Wall -o ppmModification.out ppmModification.cpp biblio.o

biblio.o : biblio.h biblio.cpp
	g++ -Wall -o biblio.o biblio.cpp -c

clean:
	rm *.o
mrproper: clean
	rm ppmModification.out
