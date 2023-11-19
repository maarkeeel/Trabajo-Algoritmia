#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "colaDeDatos.h"

int main()
{
  int n1, n2, indice, distancia, distanciaMinima, nuevaDistancia, estresMinimo;
  FILE *fichero;

  tipoElementoCola datos;
  tipoElementoCola datoNuevo;
  tipoCola cola;
  int* tabla;


  datoNuevo.anxiety_level = 14;
  datoNuevo.self_esteem = 20;
  datoNuevo.mental_health_history = 0;
  datoNuevo.depression = 12;
  datoNuevo.headache = 2;
  datoNuevo.blood_pressure = 1;
  datoNuevo.sleep_quality = 2;
  datoNuevo.breathing_problem = 4;
  datoNuevo.noise_level = 2;
  datoNuevo.living_conditions = 3;
  datoNuevo.safety = 3;
  datoNuevo.basic_needs = 2;
  datoNuevo.academic_performance = 3;
  datoNuevo.study_load = 2;
  datoNuevo.teacher_student_relationship = 3;
  datoNuevo.future_career_concerns = 3;
  datoNuevo.social_support = 2;
  datoNuevo.peer_pressure = 3;
  datoNuevo.extracurricular_activities = 3;
  datoNuevo.bullying = 2;

  nuevaCola(&cola);
  
  fichero = fopen("StressLevelDataset.csv", "r");

  while(!feof(fichero))
  {
    tabla = (int*)malloc(sizeof(int) * 21);

    for (indice = 0; indice < 21; indice++)
    {
      fread(&n1, sizeof(int), 1, fichero);
      fread(&n2, sizeof(int), 1, fichero);

      if (n2 != ';')
      {
        n1 = n1*10;
        n1 += n2;

        tabla[indice] = n1;

        fread(&n2, sizeof(int), 1, fichero);
      }
      else
      {
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
  
  distancia += pow(datos.anxiety_level - datoNuevo.anxiety_level, 2);
  distancia += pow(datos.self_esteem - datoNuevo.self_esteem, 2);
  distancia += pow(datos.mental_health_history - datoNuevo.mental_health_history, 2);
  distancia += pow(datos.depression - datoNuevo.depression, 2);
  distancia += pow(datos.headache - datoNuevo.headache, 2);
  distancia += pow(datos.blood_pressure - datoNuevo.blood_pressure, 2);
  distancia += pow(datos.sleep_quality - datoNuevo.sleep_quality, 2);
  distancia += pow(datos.breathing_problem - datoNuevo.breathing_problem, 2);
  distancia += pow(datos.noise_level - datoNuevo.noise_level, 2);
  distancia += pow(datos.living_conditions - datoNuevo.living_conditions, 2);
  distancia += pow(datos.safety - datoNuevo.safety, 2);
  distancia += pow(datos.basic_needs - datoNuevo.basic_needs, 2);
  distancia += pow(datos.academic_performance - datoNuevo.academic_performance, 2);
  distancia += pow(datos.study_load - datoNuevo.study_load, 2);
  distancia += pow(datos.teacher_student_relationship - datoNuevo.teacher_student_relationship, 2);
  distancia += pow(datos.future_career_concerns - datoNuevo.future_career_concerns, 2);
  distancia += pow(datos.social_support - datoNuevo.social_support, 2);
  distancia += pow(datos.peer_pressure - datoNuevo.peer_pressure, 2);
  distancia += pow(datos.extracurricular_activities - datoNuevo.extracurricular_activities, 2);
  distancia += pow(datos.bullying - datoNuevo.bullying, 2);
  distancia = sqrt(distancia);


  datos = frente(cola);
  desencolar(&cola);
  distanciaMinima = distancia;
  estresMinimo = datos.stress_level;
  while(!esNulaCola(cola) && distanciaMinima != 0)
  {
    datos = frente(cola);
    desencolar(&cola);

    distancia = 0;
    distancia += pow(datos.anxiety_level - datoNuevo.anxiety_level, 2);
    distancia += pow(datos.self_esteem - datoNuevo.self_esteem, 2);
    distancia += pow(datos.mental_health_history - datoNuevo.mental_health_history, 2);
    distancia += pow(datos.depression - datoNuevo.depression, 2);
    distancia += pow(datos.headache - datoNuevo.headache, 2);
    distancia += pow(datos.blood_pressure - datoNuevo.blood_pressure, 2);
    distancia += pow(datos.sleep_quality - datoNuevo.sleep_quality, 2);
    distancia += pow(datos.breathing_problem - datoNuevo.breathing_problem, 2);
    distancia += pow(datos.noise_level - datoNuevo.noise_level, 2);
    distancia += pow(datos.living_conditions - datoNuevo.living_conditions, 2);
    distancia += pow(datos.safety - datoNuevo.safety, 2);
    distancia += pow(datos.basic_needs - datoNuevo.basic_needs, 2);
    distancia += pow(datos.academic_performance - datoNuevo.academic_performance, 2);
    distancia += pow(datos.study_load - datoNuevo.study_load, 2);
    distancia += pow(datos.teacher_student_relationship - datoNuevo.teacher_student_relationship, 2);
    distancia += pow(datos.future_career_concerns - datoNuevo.future_career_concerns, 2);
    distancia += pow(datos.social_support - datoNuevo.social_support, 2);
    distancia += pow(datos.peer_pressure - datoNuevo.peer_pressure, 2);
    distancia += pow(datos.extracurricular_activities - datoNuevo.extracurricular_activities, 2);
    distancia += pow(datos.bullying - datoNuevo.bullying, 2);
    distancia = sqrt(distancia);
    nuevaDistancia = distancia;
    if (nuevaDistancia < distanciaMinima)
    {          
      distanciaMinima = nuevaDistancia;
      estresMinimo = datos.stress_level;
    }
  }
  datoNuevo.stress_level = estresMinimo;
  printf("El estres correspondiente a los datos introducidos es : %d", estresMinimo);
  printf("El estres correspondiente a los datos introducidos es : %d", distancia);
}