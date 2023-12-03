#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "colaDeDatos.h"

int main()
{
	int n1, n2, indice, estresMinimo;
	double distancia, distanciaMinima, nuevaDistancia;
	FILE *fichero;
	char c1, c2;

	tipoElementoCola datos;
	tipoElementoCola datoNuevo;
	tipoCola cola;
	int* tabla;


	datoNuevo.anxiety_level = 16;
	datoNuevo.self_esteem = 12;
	datoNuevo.mental_health_history = 1;
	datoNuevo.depression = 15;
	datoNuevo.headache = 4;
	datoNuevo.blood_pressure = 3;
	datoNuevo.sleep_quality = 1;
	datoNuevo.breathing_problem = 3;
	datoNuevo.noise_level = 4;
	datoNuevo.living_conditions = 2;
	datoNuevo.safety = 2;
	datoNuevo.basic_needs = 2;
	datoNuevo.academic_performance = 2;
	datoNuevo.study_load = 4;
	datoNuevo.teacher_student_relationship = 1;
	datoNuevo.future_career_concerns = 4;
	datoNuevo.social_support = 1;
	datoNuevo.peer_pressure = 4;
	datoNuevo.extracurricular_activities = 4;
	datoNuevo.bullying = 5;
	
	Normalizar(&datoNuevo);//Se nos habia olvidado normalizar el dato nuevo


	nuevaCola(&cola);
  
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

	datos = copiarDatos(cola);//aqui como bien dice la funcion se inicializa la variable datos con el frente de la cola que es el primer dato introducido
	desencolar(&cola);
	
	distanciaMinima = CalcularDistancia(datos, datoNuevo); //Funcion de calcular la distancia hecha 
	
	estresMinimo = datos.stress_level;
	
	while(!esNulaCola(cola) && distanciaMinima != 0)
	{
		datos = copiarDatos(cola);
		desencolar(&cola);

		
		nuevaDistancia = CalcularDistancia(datos, datoNuevo);
		
		if (nuevaDistancia < distanciaMinima)
		{          
		  distanciaMinima = nuevaDistancia;
		  estresMinimo = datos.stress_level;
		}
	  }
	datoNuevo.stress_level = estresMinimo;
	printf("El estres correspondiente a los datos introducidos es : %d \n", estresMinimo);
	printf("La distancia es : %lf \n", distancia);
}


