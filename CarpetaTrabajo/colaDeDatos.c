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

double CalcularDistancia (tipoElementoCola datos, tipoElementoCola datoNuevo){
	int distancia;
	distancia = 0;
	distancia += pow(fabs(datos.anxiety_level - datoNuevo.anxiety_level), 2);
	distancia += pow(fabs(datos.self_esteem - datoNuevo.self_esteem), 2);
	distancia += pow(fabs(datos.mental_health_history - datoNuevo.mental_health_history), 2);
	distancia += pow(fabs(datos.depression - datoNuevo.depression), 2);
	distancia += pow(fabs(datos.headache - datoNuevo.headache), 2);
	distancia += pow(fabs(datos.blood_pressure - datoNuevo.blood_pressure), 2);
	distancia += pow(fabs(datos.sleep_quality - datoNuevo.sleep_quality), 2);
	distancia += pow(fabs(datos.breathing_problem - datoNuevo.breathing_problem), 2);
	distancia += pow(fabs(datos.noise_level - datoNuevo.noise_level), 2);
	distancia += pow(fabs(datos.living_conditions - datoNuevo.living_conditions), 2);
	distancia += pow(fabs(datos.safety - datoNuevo.safety), 2);
	distancia += pow(fabs(datos.basic_needs - datoNuevo.basic_needs), 2);
	distancia += pow(fabs(datos.academic_performance - datoNuevo.academic_performance), 2);
	distancia += pow(fabs(datos.study_load - datoNuevo.study_load), 2);
	distancia += pow(fabs(datos.teacher_student_relationship - datoNuevo.teacher_student_relationship), 2);
	distancia += pow(fabs(datos.future_career_concerns - datoNuevo.future_career_concerns), 2);
	distancia += pow(fabs(datos.social_support - datoNuevo.social_support), 2);
	distancia += pow(fabs(datos.peer_pressure - datoNuevo.peer_pressure), 2);
	distancia += pow(fabs(datos.extracurricular_activities - datoNuevo.extracurricular_activities), 2);
	distancia += pow(fabs(datos.bullying - datoNuevo.bullying), 2);
	distancia = sqrt(distancia);
	return distancia;
}
	
tipoElementoCola copiarDatos (tipoCola c){

	tipoElementoCola datos;

	datos.anxiety_level = c.ini->elem.anxiety_level;
	datos.self_esteem = c.ini->elem.self_esteem;
	datos.mental_health_history = c.ini->elem.mental_health_history;
	datos.depression = c.ini->elem.depression;
	datos.headache = c.ini->elem.headache;
	datos.blood_pressure = c.ini->elem.blood_pressure;
	datos.sleep_quality = c.ini->elem.sleep_quality;
	datos.breathing_problem = c.ini->elem.breathing_problem;
	datos.noise_level = c.ini->elem.noise_level;
	datos.living_conditions = c.ini->elem.living_conditions;
	datos.safety = c.ini->elem.safety;
	datos.basic_needs = c.ini->elem.basic_needs;
	datos.academic_performance = c.ini->elem.academic_performance;
	datos.study_load = c.ini->elem.study_load;
	datos.teacher_student_relationship = c.ini->elem.teacher_student_relationship;
	datos.future_career_concerns = c.ini->elem.future_career_concerns;
	datos.social_support = c.ini->elem.social_support;
	datos.peer_pressure = c.ini->elem.peer_pressure;
	datos.extracurricular_activities = c.ini->elem.extracurricular_activities;
	datos.bullying = c.ini->elem.bullying;
	datos.stress_level = c.ini->elem.stress_level;
	
	return datos;
}
