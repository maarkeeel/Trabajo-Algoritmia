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
	for (int i = 0; i < nelem; i++)//lleno el array de distancias 0 y stress -1
	{
		m->array[i]->distancia = -1;
		m->array[i]->stress_level = -1;
	}
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

void insertarMaxMonticulo(tipoMaxMonticulo* m, tipoElementoMaxMonticulo* elemento){
	
	int pospadre, guardapos, cambiod, cambios;
	tipoElementoMaxMonticulo *nuevoElem;
	
	if (m->pos == -1)
	{ //Insertar primer elemento
		(m->pos) = (m->pos) + 1;
		m->array[m->pos]->distancia = elemento->distancia;
		m->array[m->pos]->stress_level = elemento->stress_level;
	}
	else if (m->pos == 0)//caso trivial, m->pos = 0 es la cima del monticulo, si ha llegado hasta aquí tiene que tener la distancia mayor
	{
		m->array[m->pos]->distancia = elemento->distancia;
		m->array[m->pos]->stress_level = elemento->stress_level;
	}
	else//m->pos >= 0 aquí, y ya hemos metido el primer elemento
	{
		if (m->pos == m->numEl) //comprobamos si el siguiente valor es el del numero de elementos que nos han pedido(recordemos que la tabla va de [0, N-1]) por lo tanto estaríamos fuera de la tabla
		{
			printf("ERROR No se pueden introducir mas elementos\n");
		}
		else if (m->pos + 1 != m->numEl && m->pos % 2 == 0)//m->pos < m->numEl && hijo Derecho
		{
			pospadre = (m->pos / 2) - 1;
			if (elemento.distancia > (m->array[pospadre].distancia))//si el elemento que introducimos tiene distancia mayor que el elemento en la posición padre
			{
				guardapos = m->pos;
				m->pos = pospadre;
				insertarMaxMonticulo(&m, elemento);//llamada pero ahora m->pos es la posición del padre
				m->pos = guardapos;
			}
			else
			{
				m->array[m->pos].distancia = elemento.distancia;
				m->array[m->pos].stress_level = elemento.stress_level;
			}
		}
		else if (m->pos + 1 != m->numEl && m->pos % 2 != 0)//m->pos < m->numEl && hijo Izquierdo
		{
			pospadre = (m->pos - 1) / 2;
			if (elemento.distancia > (m->array[pospadre].distancia))//si el elemento que introducimos tiene distancia mayor que el elemento en la posición padre
			{
				guardapos = m->pos;
				m->pos = pospadre;
				insertarMaxMonticulo(&m, elemento);//llamada pero ahora m->pos es la posición del padre
				m->pos = guardapos;
			}
			else
			{
				m->array[m->pos].distancia = elemento.distancia;
				m->array[m->pos].stress_level = elemento.stress_level;
			}
		}
	}
	m->pos = m->pos + 1;
}


void borrarraiz(tipoMaxMonticulo* m){
{
	subirMayor(m, 0);
	m->pos = m->pos - 1;
}

void mostrarAnchura(tipoMaxMonticulo m){
	int posaux;
	posaux = 0;
	for (posaux; m.pos; posaux++){
		for (m.array[posaux].repeticiones; 0; (m.array[posaux].repeticiones) --)
		{
			printf("%d ", m.array[posaux].distancia);
		}
	}
}

void subirMayor(tipoElementoMaxMonticulo* m, int pospadre)
{
	if ((pospadre * 2) + 1 >= m->numEl)
	{
		if(m->array[(pospadre * 2) + 1]->distancia >= m->array[(pospadre * 2) + 2]->distancia)
		{
			m->array[pospadre]->distancia = m->array[(pospadre * 2) + 1]->distancia;
			m->array[pospadre]->stress_level = m->array[(pospadre * 2) + 1]->stress_level;
			subirMayor(m, (pospadre * 2) + 1);
		}
		else if(m->array[(pospadre * 2) + 2]->distancia > m->array[(pospadre * 2) + 1]->distancia)
		{
			m->array[pospadre]->distancia = m->array[(pospadre * 2) + 2]->distancia;
			m->array[pospadre]->stress_level = m->array[(pospadre * 2) + 2]->stress_level;
			subirMayor(m, (pospadre * 2) + 2);
		}
	}
	else
	{
		m->array[pospadre]->distancia = -1;
		m->array[pospadre]->stress_level = -1;
	}
}


	
	
	
	
	
		
