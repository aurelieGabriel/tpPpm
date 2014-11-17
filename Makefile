all : ppmModification.out

ppmModification.out : ppmModification.c biblio.o
	gcc -Wall -o ppmModification.out ppmModification.c biblio.o

biblio.o : biblio.h biblio.c
	gcc -Wall -o biblio.o biblio.c -c

clean:
	rm *.o
mrproper: clean
	rm ppmModification.out
