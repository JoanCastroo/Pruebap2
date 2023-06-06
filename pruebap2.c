#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

// Estructura para almacenar las calificaciones de un alumno
typedef struct {
    float calificaciones[NUM_PROGRESOS];
    float promedio;
} Alumno;

// Función para calcular el promedio de calificaciones de un alumno
void calcularPromedioAlumno(Alumno* alumno) {
    float suma = 0;
    for (int i = 0; i < NUM_PROGRESOS; i++) {
        suma += alumno->calificaciones[i];
    }
    alumno->promedio = suma / NUM_PROGRESOS;
}

// Función para calcular la nota promedio del grupo para cada progreso
void calcularPromedioGrupo(float calificaciones[][NUM_PROGRESOS], float promediosProgresos[]) {
    for (int j = 0; j < NUM_PROGRESOS; j++) {
        float suma = 0;
        for (int i = 0; i < NUM_ALUMNOS; i++) {
            suma += calificaciones[i][j];
        }
        promediosProgresos[j] = suma / NUM_ALUMNOS;
    }
}

// Función para encontrar el índice del alumno con el mayor promedio
int encontrarMaximoPromedio(Alumno alumnos[]) {
    int indiceMaximo = 0;
    for (int i = 1; i < NUM_ALUMNOS; i++) {
        if (alumnos[i].promedio > alumnos[indiceMaximo].promedio) {
            indiceMaximo = i;
        }
    }
    return indiceMaximo;
}

// Función para generar calificaciones aleatorias en el rango de 0 a 10
void generarCalificacionesAleatorias(Alumno alumnos[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            alumnos[i].calificaciones[j] = (float)(rand() % 110) / 10;  // Generar números aleatorios de 0 a 10 con un decimal
        }
        calcularPromedioAlumno(&alumnos[i]);
    }
}

int main() {
    Alumno alumnos[NUM_ALUMNOS];
    float promediosProgresos[NUM_PROGRESOS];

    // Generar calificaciones aleatorias para cada alumno
    generarCalificacionesAleatorias(alumnos);

    // Calcular la nota promedio del grupo para cada progreso
    calcularPromedioGrupo(alumnos[0].calificaciones, promediosProgresos);

    // Encontrar el alumno con el mayor promedio
    int indiceMaximo = encontrarMaximoPromedio(alumnos);

    // Imprimir resultados
    printf("\nPromedio de calificaciones de cada alumno durante el semestre:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Alumno %d: %.2f\n", i + 1, alumnos[i].promedio);
    }

    printf("\nNota promedio del grupo para cada progreso:\n");
    for (int j = 0; j < NUM_PROGRESOS; j++) {
        printf("Progreso %d: %.2f\n", j + 1, promediosProgresos[j]);
    }

    printf("\nAlumno con el mayor promedio de calificación durante el semestre:\n");
    printf("Alumno %d\n", indiceMaximo + 1);

    return 0;
}
