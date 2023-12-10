#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "maxMonticulo.h"


void nuevoMaxMonticulo(tipoMaxMonticulo *m, int nelem){
	m->pos = -1;
	m->numEl = nelem;
	m->array = ((tipoElementoMaxMonticulo*) malloc (nelem * sizeof(tipoElementoMaxMonticulo)));
}

bool esVacio(tipoMaxMonticulo m){
	return(m.pos == -1);
}

bool estaLleno(tipoMaxMonticulo m){
	return (m.pos + 1 == m.numEl);
}

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo m){
	return (m.array[0]);
}

void insertarMaxMonticulo(tipoMaxMonticulo* m, tipoElementoMaxMonticulo elem){
	
	int posaux;
	tipoElementoMaxMonticulo cambio;
	
	if (m->pos == -1){ //Insertar primer elemento
		(m->pos) = (m->pos) + 1;
		m->array[m->pos].distancia = elem.distancia;
		m->array[m->pos].stressLevel = elem.stressLevel;
		
	}
	else{
		if (m->pos + 1 == m->numEl)
		{
			printf("ERROR No se pueden introducir mas elementos\n");
		}
		else
		{
			m->pos = m->pos + 1; //apunta al siguiente hueco
			posaux = (m->pos);
			m->array[m->pos].distancia = elem.distancia;//lleno el siguiente hueco
			m->array[m->pos].stressLevel = elem.stressLevel;
			for (posaux ; posaux > (-1) ; ((posaux-1) / 2)){//Encontar la posicion hasta la que tiene que subir
				
				if (m->array[posaux].distancia <= (m->array[(posaux-1) / 2].distancia))
				{//si es mayor se cambia y sino se queda como está
					posaux = -1;
				}
				else
				{
					cambio.distancia = m->array[(posaux-1) / 2].distancia;
					cambio.stressLevel = m->array[(posaux-1) / 2].stressLevel;
						
					m->array[(posaux-1) / 2].distancia = m->array[posaux].distancia;
					m->array[(posaux-1) / 2].stressLevel = m->array[posaux].stressLevel;
						
					m->array[posaux].distancia = cambio.distancia;
					m->array[posaux].stressLevel = cambio.stressLevel;
				}
			}
		}
	}	
}


void cambiarRaiz(tipoMaxMonticulo *m, tipoElementoMaxMonticulo elem){
	/*La funcion esta compara la distancia del elemento nuevo con la distancia de la raiz y si es menor cambia la raiz por el nuevo elemento
	 * hay que cambiar distancia y stressLevel. Luego compara con sus dos hijo aver si tiene que bajar o no y si es asi compara los hijos 
	 * para ver por cual se tiene que sustituir. Si tiene solo hijo derecho se compara con el. Por como esta hecho no es posible que tenga 
	 * solo hijo izquierdo asique no hay que meter esa alternativa. Realiza esto hasta que la distancia del elemento sea mayor que 
	 * la de sus o cuando llega a ser una hoja el elemento que si introduce.
	 * */
	
	int posaux;
	tipoElementoMaxMonticulo cambio;
	
	if (m->array[0].distancia > elem.distancia)
	{
		
		m->array[0].distancia = elem.distancia;
		m->array[0].stressLevel = elem.stressLevel;
		
		posaux = 0;
		
		while ((2*posaux+1) < m->numEl)
		{
			
			if ((2*posaux+2) >= m->numEl)
			{
				cambio.distancia = m->array[2*posaux+1].distancia;
				cambio.stressLevel = m->array[2*posaux+1].stressLevel;
						
				m->array[2*posaux+1].distancia = m->array[posaux].distancia;
				m->array[2*posaux+1].stressLevel = m->array[posaux].stressLevel;
						
				m->array[posaux].distancia = cambio.distancia;
				m->array[posaux].stressLevel = cambio.stressLevel;
				posaux = 2*posaux+1;
			}
			
			else
			{
				if ((m->array[posaux].distancia > m->array[2*posaux+1].distancia) && (m->array[posaux].distancia > m->array[2*posaux+2].distancia))
				{
					if (m->array[2*posaux+1].distancia > m->array[2*posaux+2].distancia)
					{
						cambio.distancia = m->array[2*posaux+1].distancia;
						cambio.stressLevel = m->array[2*posaux+1].stressLevel;
						
						m->array[2*posaux+1].distancia = m->array[posaux].distancia;
						m->array[2*posaux+1].stressLevel = m->array[posaux].stressLevel;
						
						m->array[posaux].distancia = cambio.distancia;
						m->array[posaux].stressLevel = cambio.stressLevel;
						posaux = 2*posaux+1;
					} 
					else
					{
						cambio.distancia = m->array[2*posaux+2].distancia;
						cambio.stressLevel = m->array[2*posaux+2].stressLevel;
						
						m->array[2*posaux+2].distancia = m->array[posaux].distancia;
						m->array[2*posaux+2].stressLevel = m->array[posaux].stressLevel;
						
						m->array[posaux].distancia = cambio.distancia;
						m->array[posaux].stressLevel = cambio.stressLevel;
						posaux = 2*posaux+2;
					}
				}
				
				else if ((m->array[posaux].distancia > m->array[2*posaux+1].distancia) && (m->array[posaux].distancia <= m->array[2*posaux+2].distancia))
				{
					cambio.distancia = m->array[2*posaux+1].distancia;
					cambio.stressLevel = m->array[2*posaux+1].stressLevel;
						
					m->array[2*posaux+1].distancia = m->array[posaux].distancia;
					m->array[2*posaux+1].stressLevel = m->array[posaux].stressLevel;
						
					m->array[posaux].distancia = cambio.distancia;
					m->array[posaux].stressLevel = cambio.stressLevel;
					posaux = 2*posaux+1;
				}
				
				else if ((m->array[posaux].distancia <= m->array[2*posaux+1].distancia) && (m->array[posaux].distancia > m->array[2*posaux+2].distancia))
				{
					cambio.distancia = m->array[2*posaux+2].distancia;
					cambio.stressLevel = m->array[2*posaux+2].stressLevel;
						
					m->array[2*posaux+2].distancia = m->array[posaux].distancia;
					m->array[2*posaux+2].stressLevel = m->array[posaux].stressLevel;
						
					m->array[posaux].distancia = cambio.distancia;
					m->array[posaux].stressLevel = cambio.stressLevel;
					posaux = 2*posaux+2;
				}
				else
				{
					posaux = m-> numEl;
				}
			}
		}
	}
}
