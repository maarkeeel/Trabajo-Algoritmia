#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "maxMonticulo.h"

/*typedef struct tipoElementoMaxMonticulo{
	int valor;
	int repeticiones;
}tipoElementoMaxMonticulo;

typedef struct tipoMaxMonticulo{
	tipoElementoMaxMonticulo* array;
	int pos;
	int numEl;
}tipoMaxMonticulo;*/

void nuevoMaxMonticulo(tipoMaxMonticulo *m, int nelem){
	m->pos = -1;
	m->numEl = nelem;
	m->array = ((tipoElementoMaxMonticulo*) malloc (nelem * sizeof(tipoElementoMaxMonticulo)));
}

bool esVacio(tipoMaxMonticulo m){
	return(m.pos == -1);
}

bool estaLleno(tipoMaxMonticulo m){
	return (m.pos == m.numEl);
}

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo m){
	return (m.array[0]);
}

void insertarMaxMonticulo(tipoMaxMonticulo* m, int valor){
	
	int posaux, cambio;
	
	if (m->pos == -1){ //Insertar primer elemento
		(m->pos) = (m->pos) + 1;
		m->array[m->pos].valor = valor;
	}
	else{
		if (m->pos = m->numEl){
			printf("ERROR No se pueden introducir mas elementos\n");
		}
		else{
			posaux = (m->(pos-1) / 2);
			for (posaux ; 0 ; ((posaux-1) / 2)){//Encontar la posicion hasta la que tiene que subir
				if (valor < (m->array[posaux].valor)){
					m->array[m->pos].valor = valor;
					posaux = 0;
				}
				else{
					cambio = m->array[m->pos].valor;
					m->array[m->pos].valor = m->array[posaux].valor;
					m->array[posaux].valor = cambio;
				}
			}
		}
	}	
}


void eliminarElemento(tipoMaxMonticulo *m, int valor){
	
	int posaux, esta;
	esta = 0;
	
	posaux = m->pos;
	for (posaux; 0; posaux--){
		if	(valor == (m->array[posaux].valor)){//Comprobar si el valor esta en el monticulo.
			
			m->pos = (m->pos) - 1;
			if (((2*posaux)+1) > m->pos){//No tiene hijos
				while(posaux != m->pos){
					m->array[posaux].valor = m->array[posaux + 1].valor;
					posaux = posaux + 1;
				}
			}
			else if (((2*posaux)+1) == m->pos){//Tiene solo hijo derecho.
				m->array[posaux].valor = m->array[m->pos].valor; //pos es el ultimo valor que es el hijo derecho del valor a eliminar
			}
			else if (((2*posaux)+1) < m->pos){//Tiene hijo izquierdo y derecho
				if (m->array[((2*posaux)+1)].valor > m->array[((2*posaux)+1)].valor)
				{
					m->array[posaux].valor = m->array[((2*posaux)+1)].valor;
				}
				else{
					m->array[posaux].valor = m->array[((2*posaux)+2)].valor;
				}
				while(posaux != m->pos){
					m->array[posaux].valor = m->array[posaux + 1].valor;
					posaux = posaux + 1;
				}
			}
		}
	}
}
	if (esta = 0){
		printf("El valor introducido no esta en el monticulo\n");
	}
}

void mostrarAnchura(tipoMaxMonticulo m){
	int posaux;
	posaux = 0;
	for (posaux; m.pos; posaux++){
		for (m.array[posaux].repeticiones; 0; (m.array[posaux].repeticiones) --)
		{
			printf("%d ", m.array[posaux].valor);
		}
	}
}


	
	
	
	
	
		
