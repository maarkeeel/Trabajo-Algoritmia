#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "colaEnteros.h"


void nuevaCola(tipoCola* c){
	c->ini = NULL;
	c->fin = NULL; 
}

bool esNulaCola(tipoCola c){
	return (c.ini == NULL);
}

void encolar(tipoCola* c, tipoElementoCola elem){
	celdaCola* nueva;
	nueva = ((celdaCola*) malloc (sizeof(celdaCola)));
	nueva->elem = elem;
	if (c->ini == NULL && c->fin == NULL){
		c->ini = nueva;
		c->fin = nueva;
		nueva->sig = NULL;
	}
	else{
		nueva->sig = NULL;
		c->fin->sig = nueva;
		c->fin = nueva;
	}
}

void desencolar(tipoCola* c){
	celdaCola* nueva;
	nueva = c->ini;
	c->ini = c->ini->sig;
	free (nueva);
}

tipoElementoCola frente(tipoCola c){
	int elem;
	elem = c.ini->elem;
	return (elem);
}

