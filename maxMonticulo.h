#include <stdbool.h>

typedef struct tipoElementoMaxMonticulo{
	int stressLevel;
	int distancia;
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

void cambiarRaiz(tipoMaxMonticulo*, tipoElementoMaxMonticulo);




