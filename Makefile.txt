all: trabajo
	./trabajo
Trabajo: colaDeDatos.o maxMonticulo.o
	gcc Trabajo.c colaDeDatos.o maxMonticulo.o -lm -o trabajo -g
maxMonticulo.o: maxMonticulo.c
	gcc -c maxMonticulo.c
colaDeDatos.o: colaDeDatos.c
	gcc -c colaDeDatos.c

clean:
	 rm *.o
