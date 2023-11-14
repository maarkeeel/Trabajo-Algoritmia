#include <stdbool.h>

typedef struct tipoElementoC{
	int anxiety_level;
	int self_esteem;
	int mental_health_history;
	int depression;
	int headache;
	int blood_pressure;
	int sleep_quality;
	int breathing_problem;
	int noise_level;
	int living_conditions;
	int safety;
	int basic_needs;
	int academic_performance;
	int study_load;
	int teacher_student_relationship;
	int future_career_concerns;
	int social_support;
	int peer_pressure;
	int extracurricular_activities;
	int bullying;
	int stress_level;
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
