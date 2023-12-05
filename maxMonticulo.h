#include <stdbool.h>

typedef struct tipoElementoMaxMonticulo{
	int valor;
	int repeticiones;
}tipoElementoMaxMonticulo;

typedef struct tipoMaxMonticulo{
	tipoElementoMaxMonticulo* array;
	int pos;
	int numEl;
}tipoMaxMonticulo;

void nuevoMaxMonticulo(tipoMaxMonticulo*, int);

bool esVacio(tipoMaxMonticulo);

bool estaLleno(tipoMaxMonticulo);

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo);

void insertarMaxMonticulo(tipoMaxMonticulo*, int);

void eliminarElemento(tipoMaxMonticulo*, int);

void mostrarAnchura(tipoMaxMonticulo);




