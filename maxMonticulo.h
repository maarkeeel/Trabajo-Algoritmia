#include <stdbool.h>

typedef struct tipoElementoMaxMonticulo{
	int distancia;
	int stress_level;
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

void insertarMaxMonticulo(tipoMaxMonticulo*, tipoElementoMaxMonticulo);

void borrarraiz(tipoMaxMonticulo*);

void mostrarAnchura(tipoMaxMonticulo);



