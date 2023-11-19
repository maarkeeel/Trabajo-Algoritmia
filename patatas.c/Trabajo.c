#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "colaDeDatos.h"

void Normalizar(*TipoElementoC)

int main()
{
  int n1, n2, indice;
  FILE *StressLevelDataset;

  tipoElementoCola elem;
  tipoCola cola;
  int* TablaDato;

  nuevaCola(&cola);
  
  fichero = fopen(StressLevelDataset, "r");

  while(!feof(f))
  {
    TablaDato = (int*)malloc(sizeof(int * 20))

    for indice = 0; indice < 20; indice++)
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
  }
}
  
}

void Normalizar(*datos)
{
    *datos.anxiety_level = *datos.anxiety_level / 21
    *datos.self_esteem = *datos.self_esteem / 30
    *datos.mental_health_history = *datos.mental_health_history / 1
    *datos.depression = *datos.depression / 27
    *datos.headache = *datos.headache - 1 / 5 - 1
    *datos.blood_pressure = *datos.blood_pressure - 1 / 2
    *datos.sleep_quality = *datos.sleep_quality / 5
    *datos.breathing_problem = *datos.breathing_problem / 5
    *datos.noise_level = *datos.noise_level / 5
    *datos.living_conditions = *datos.living_conditions / 5
    *datos.safety = *datos.safety / 5
    *datos.basic_needs = *datos.basic_needs / 5
    *datos.academic_preformance = *datos.academic_preformance / 5
    *datos.study_load = *datos.study_load / 5
    *datos.teacher_student_relationship = *datos.teacher_student_relationship / 5
    *datos.future_career_concerns = *datos.future_career_concerns / 5
    *datos.social_support = *datos.social_support / 3
    *datos.peer_pressure = *datos.peer_pressure / 5
    *datos.extracurricular_activities = *datos.extracurricular_activities / 5
    *datos.bullying = *datos.bullying / 5
}
