all: Programa

Programa: gaussSeidel.o funciones.o
	gcc gaussSeidel.o funciones.o -o gaussSeidel

gaussSeidel.o: gaussSeidel.c
	gcc -c gaussSeidel.c

funciones.o: funciones.c
	gcc -c funciones.c

clean:
	rm -rf *o gaussSeidel
