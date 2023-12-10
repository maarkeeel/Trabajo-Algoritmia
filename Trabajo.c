#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "colaDeDatos.h"
#include "maxMonticulo.h"

int main()
{
	int n1, n2, indice, estresMinimo, numElem, cont0, cont1, cont2, contDist0, contDist1, contDist2;
	double distancia, distanciaNueva;
	FILE *fichero;
	char c1, c2;

	tipoElementoCola datos;
	tipoElementoCola datoNuevo;
	tipoCola cola;

	int* tabla;

	tipoElementoMaxMonticulo elem;
	tipoElementoMaxMonticulo raiz;
	tipoMaxMonticulo maxMon;


	printf("Introduce el nivel de ansiedad: ");
	scanf("%lf", &datoNuevo.anxiety_level);
	printf("Introduce el nivel de autoestima: ");
	scanf("%lf", &datoNuevo.self_esteem);
	printf("Introduce el nivel de salud mental: ");
	scanf("%lf", &datoNuevo.mental_health_history);
	printf("Introduce el nivel de depresion: ");
	scanf("%lf", &datoNuevo.depression);
	printf("Introduce el nivel de dolor de cabeza: ");
	scanf("%lf",&datoNuevo.headache);
	printf("Introduce el nivel de presion arterial: ");
	scanf("%lf", &datoNuevo.blood_pressure);
	printf("Introduce el nivel de calidad de sueño: ");
	scanf("%lf", &datoNuevo.sleep_quality);
	printf("Introduce el nivel de problemas respiratorios: ");
	scanf("%lf", &datoNuevo.breathing_problem);
	printf("Introduce el nivel de ruido: ");
	scanf("%lf", &datoNuevo.noise_level);
	printf("Introduce el nivel de condiciones de vida: ");
	scanf("%lf", &datoNuevo.living_conditions);
	printf("Introduce el nivel de seguridad: ");
	scanf("%lf", &datoNuevo.safety);
	printf("Introduce el nivel de necesidades basicas: ");
	scanf("%lf", &datoNuevo.basic_needs);
	printf("Introduce el nivel de rendimiento academico: ");
	scanf("%lf", &datoNuevo.academic_performance);
	printf("Introduce el nivel de carga de estudio: ");
	scanf("%lf", &datoNuevo.study_load);
	printf("Introduce el nivel de relacion alumno-profesor: ");
	scanf("%lf", &datoNuevo.teacher_student_relationship);
	printf("Introduce el nivel de preocupacion por tu futuro: ");
	scanf("%lf", &datoNuevo.future_career_concerns);
	printf("Introduce el nivel de apoyo social: ");
	scanf("%lf", &datoNuevo.social_support);
	printf("Introduce el nivel de presion social: ");
	scanf("%lf", &datoNuevo.peer_pressure);
	printf("Introduce el nivel de actividades extrascolares: ");
	scanf("%lf", &datoNuevo.extracurricular_activities);
	printf("Introduce el nivel de bullyng sufrido: ");
	scanf("%lf", &datoNuevo.bullying);
	
	Normalizar(&datoNuevo);//Se nos habia olvidado normalizar el dato nuevo

	nuevaCola(&cola);

	printf("\nIntroduce el numero de elementos que quieres comprobar (N): ");
	scanf("%d", &numElem);

	nuevoMaxMonticulo(&maxMon, numElem);
  
	fichero = fopen("StressLevelDataset.csv", "r");

    if (fichero == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

	tabla = (int *)malloc(sizeof(int) * 21);//estaba dentro y habia que reservar memoria cada vez y no hace falta
	
    while (!feof(fichero)) {//La funcion de la distancia estaba bien planteada pero mal implementada

        for (indice = 0; indice < 21; indice++) {
            c1 = fgetc(fichero);
            c2 = fgetc(fichero);
            
            if (c2 != ',' && c2 != '\n') //Es un numero de dos cifras convierte c1 y c2 a un entero que lo introduce en la tabla
            {
                n1 = c1 - '0';
                n2 = c2 - '0';
                n1 = n1 * 10 + n2;

                tabla[indice] = n1;

                // Leer el siguiente carácter después del número leído (la ,)
                fgetc(fichero);
            } 
            else 
            {
                n1 = c1 - '0';
                tabla[indice] = n1;
            }
        }

        datos.anxiety_level = tabla[0];
		datos.self_esteem = tabla[1];
		datos.mental_health_history = tabla[2];
		datos.depression = tabla[3];
		datos.headache = tabla[4];
		datos.blood_pressure = tabla[5];
		datos.sleep_quality = tabla[6];
		datos.breathing_problem = tabla[7];
		datos.noise_level = tabla[8];
		datos.living_conditions = tabla[9];
		datos.safety = tabla[10];
		datos.basic_needs = tabla[11];
		datos.academic_performance = tabla[12];
		datos.study_load = tabla[13];
		datos.teacher_student_relationship = tabla[14];
		datos.future_career_concerns = tabla[15];
		datos.social_support = tabla[16];
		datos.peer_pressure = tabla[17];
		datos.extracurricular_activities = tabla[18];
		datos.bullying = tabla[19];
		datos.stress_level = tabla[20];

		Normalizar(&datos);
		encolar(&cola, datos);
    }
    //liberar memoria de la tabla y cerrar fichero.
    free(tabla);
    fclose(fichero);

	while(!(estaLleno(maxMon))){

		datos = copiarDatos(cola);
		desencolar(&cola);

		elem.distancia = CalcularDistancia(datos, datoNuevo);
		elem.stressLevel = datos.stress_level;

		insertarMaxMonticulo(&maxMon, elem);
	}

	while(!esNulaCola(cola)){

		datos = copiarDatos(cola);
		desencolar(&cola);

		raiz = devolverRaiz(maxMon);

		distanciaNueva = CalcularDistancia(datos, datoNuevo);


		
		cambiarRaiz(&maxMon, elem);
	}

	while(!(estaLleno(maxMon))){

		raiz = devolverRaiz(maxMon);
		cambiarRaiz(&maxMon, elem);

		if(raiz.stressLevel == 0){
			cont0 += 1;
			contDist0 += raiz.distancia;
		}
		else if(raiz.stressLevel == 1){
			cont1 += 1;
			contDist1 += raiz.distancia;
		}
		else if (raiz.stressLevel == 2){
			cont2 += 1;
			contDist2 += raiz.distancia;
		}
		else{
			printf("ERROR"); //NO deberia de darse, pero pasa si el stress level da un numero que no sea 0, 1 o 2
		}
	}

	if (cont0 >= cont1 && cont0 >= cont2){
		if (cont0 == cont1 && cont1 != cont2){
			if(contDist0 >= contDist1){
				datoNuevo.stress_level = 0;
			}
			else{
				datoNuevo.stress_level = 1;
			}
		}
		else if (cont0 != cont1 && cont1 == cont2){
			if(contDist1 >= contDist2){
				datoNuevo.stress_level = 1;
			}
			else{
				datoNuevo.stress_level = 2;
			}
		}
		else if (cont0 == cont1 && cont1 == cont2){
			if(contDist1 >= contDist2 && contDist1 >= contDist0){
				datoNuevo.stress_level = 1;
			}
			else if(contDist2 >= contDist1 && contDist2 >= contDist0){
				datoNuevo.stress_level = 2;
			}
			else if(contDist0 >= contDist2 && contDist0 >= contDist1){
				datoNuevo.stress_level = 0;
			}
		}
	}

	else if(cont1 >= cont0 && cont1 >= cont2){
		if (cont0 == cont1 && cont1 != cont2){
			if(contDist0 >= contDist1){
				datoNuevo.stress_level = 0;
			}
			else{
				datoNuevo.stress_level = 1;
			}
		}
		else if (cont0 != cont1 && cont1 == cont2){
			if(contDist1 >= contDist2){
				datoNuevo.stress_level = 1;
			}
			else{
				datoNuevo.stress_level = 2;
			}
		}
		else if (cont0 == cont1 && cont1 == cont2){
			if(contDist1 >= contDist2 && contDist1 >= contDist0){
				datoNuevo.stress_level = 1;
			}
			else if(contDist2 >= contDist1 && contDist2 >= contDist0){
				datoNuevo.stress_level = 2;
			}
			else if(contDist0 >= contDist2 && contDist0 >= contDist1){
				datoNuevo.stress_level = 0;
			}
		}
	}
	else if(cont2 >= cont0 && cont2 >= cont1){
		if (cont2 == cont1 && cont1 != cont2){
			if(contDist2 >= contDist1){
				datoNuevo.stress_level = 2;
			}
			else{
				datoNuevo.stress_level = 1;
			}
		}
		else if (cont2 != cont1 && cont0 == cont2){
			if(contDist2 >= contDist0){
				datoNuevo.stress_level = 2;
			}
			else{
				datoNuevo.stress_level = 0;
			}
		}
		else if (cont2 == cont1 && cont0 == cont2){
			if(contDist1 >= contDist2 && contDist1 >= contDist0){
				datoNuevo.stress_level = 1;
			}
			else if(contDist2 >= contDist1 && contDist2 >= contDist0){
				datoNuevo.stress_level = 2;
			}
			else if(contDist0 >= contDist2 && contDist0 >= contDist1){
				datoNuevo.stress_level = 0;
			}
		}

	}
	printf("\nEl estres correspondiente a los datos introducidos es : %lf ", datoNuevo.stress_level);
}
