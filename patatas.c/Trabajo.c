#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mathio.h>

#include "colaDeDatos.h"

int main()
{
  int n1, n2, indice;
  FILE *StressLevelDataset;

  tipoElementoCola datos;
  tipoElementoCola datoNuevo;
  tipoCola cola;
  int* TablaDato;


    datoNuevo.anxiety_level = 14;
    datoNuevo.self_esteem = 20;
    datoNuevo.mental_health_history = 0;
    datoNuevo.depression = 11;
    datoNuevo.headache = 2;
    datoNuevo.blood_pressure = 1;
    datoNuevo.sleep_quality = 2;
    datoNuevo.breathing_problem = 4;
    datoNuevo.noise_level = 2;
    datoNuevo.living_conditions = 3;
    datoNuevo.safety = 3;
    datoNuevo.basic_needs = 2;
    datoNuevo.academic_preformance = 3;
    datoNuevo.study_load = 2;
    datoNuevo.teacher_student_relationship = 3;
    datoNuevo.future_career_concerns = 3;
    datoNuevo.social_support = 2;
    datoNuevo.peer_pressure = 3;
    datoNuevo.extracurricular_activities = 3;
    datoNuevo.bullying = 2;

  nuevaCola(&cola);
  
  fichero = fopen(StressLevelDataset, "r");

  while(!feof(f))
  {
    TablaDato = (int*)malloc(sizeof(int * 21))

    for indice = 0; indice < 21; indice++)
    {
      fread(&n1, sizeof(int), 1, fichero);
      fread(&n2, sizeof(int), 1, fichero);

      if (n2 != ';')
      {
        n1 = n1*10;
        n1 += n2;

        tabla[indice] = n1;

        fread(&n2, sizeof(int),1,f);
      }
      else
      {
        tabla[indice] = n1;
      }
    }

    *datos.anxiety_level = tabla[0];
    *datos.self_esteem = tabla[1];
    *datos.mental_health_history = tabla[2];
    *datos.depression = tabla[3];
    *datos.headache = tabla[4];
    *datos.blood_pressure = tabla[5];
    *datos.sleep_quality = tabla[6];
    *datos.breathing_problem = tabla[7];
    *datos.noise_level = tabla[8];
    *datos.living_conditions = tabla[9];
    *datos.safety = tabla[10];
    *datos.basic_needs = tabla[11];
    *datos.academic_preformance = tabla[12];
    *datos.study_load = tabla[13];
    *datos.teacher_student_relationship = tabla[14];
    *datos.future_career_concerns = tabla[15];
    *datos.social_support = tabla[16];
    *datos.peer_pressure = tabla[17];
    *datos.extracurricular_activities = tabla[18];
    *datos.bullying = tabla[19];
    *datos.stress_level = tabla[20];

    encolar(&cola, datos);
  }
  
  

}