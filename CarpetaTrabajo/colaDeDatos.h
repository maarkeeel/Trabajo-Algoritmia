#include <stdbool.h>
#include <math.h>

typedef struct tipoElementoC{
	double anxiety_level;
	double self_esteem;
	double mental_health_history;
	double depression;
	double headache;
	double blood_pressure;
	double sleep_quality;
	double breathing_problem;
	double noise_level;
	double living_conditions;
	double safety;
	double basic_needs;
	double academic_performance;
	double study_load;
	double teacher_student_relationship;
	double future_career_concerns;
	double social_support;
	double peer_pressure;
	double extracurricular_activities;
	double bullying;
	double stress_level;
}tipoElementoCola;

typedef struct celdaC{
	tipoElementoCola elem;
	struct celdaC* sig;
} celdaCola; 
typedef struct tipoC{
	celdaCola* ini;
	celdaCola* fin;
}tipoCola;

void nuevaCola(tipoCola*);

bool esNulaCola(tipoCola);

void encolar(tipoCola*, tipoElementoCola);

void desencolar(tipoCola*);

tipoElementoCola frente(tipoCola);

void Normalizar(tipoElementoCola*);

double CalcularDistancia (tipoElementoCola, tipoElementoCola);

tipoElementoCola copiarDatos (tipoCola);
