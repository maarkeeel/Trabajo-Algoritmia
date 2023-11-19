#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "colaDeDatos.h"


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
	tipoElementoCola elem;
	elem = c.ini->elem;
	return (elem);
}

void Normalizar(tipoElementoCola *datos)
{
    datos->anxiety_level = datos->anxiety_level / 21;
    datos->self_esteem = datos->self_esteem / 30;
    datos->mental_health_history = datos->mental_health_history / 1;
    datos->depression = datos->depression / 27;
    datos->headache = datos->headache - 1 / 5 - 1;
    datos->blood_pressure = datos->blood_pressure - 1 / 2;
    datos->sleep_quality = datos->sleep_quality / 5;
    datos->breathing_problem = datos->breathing_problem / 5;
    datos->noise_level = datos->noise_level / 5;
    datos->living_conditions = datos->living_conditions / 5;
    datos->safety = datos->safety / 5;
    datos->basic_needs = datos->basic_needs / 5;
    datos->academic_performance = datos->academic_performance / 5;
    datos->study_load = datos->study_load / 5;
    datos->teacher_student_relationship = datos->teacher_student_relationship / 5;
    datos->future_career_concerns = datos->future_career_concerns / 5;
    datos->social_support = datos->social_support / 3;
    datos->peer_pressure = datos->peer_pressure / 5;
    datos->extracurricular_activities = datos->extracurricular_activities / 5;
    datos->bullying = datos->bullying / 5;
}
