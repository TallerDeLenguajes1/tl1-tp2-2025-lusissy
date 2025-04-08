#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    int velocidad;            // Velocidad de procesamiento en GHz
    int anio;                 // Año de fabricación
    int cantidad_nucleos;     // Cantidad de núcleos
    char *tipo_cpu;           // Tipo de procesador (apuntador a cadena de caracteres)
} Computadora;


int generar_aleatorio(int min, int max);
void llenarDatos(Computadora *compu);

int main() {
    int cantComputadoras = 5; 
    Computadora *compu = (Computadora *)malloc(cantComputadoras * sizeof(Computadora)); 
    srand(time(NULL));

    for (int i = 0; i < cantComputadoras; i++) {
        llenarDatos(&compu[i]); 
    }

    for (int i = 0; i < cantComputadoras; i++) {
        printf("PC %d:\n", i + 1);
        printf("  Velocidad: %d GHz\n", compu[i].velocidad);
        printf("  Anio: %d\n", compu[i].anio);
        printf("  Cantidad de nucleos: %d\n", compu[i].cantidad_nucleos);
        printf("  Tipo de procesador: %s\n", compu[i].tipo_cpu);
        printf("\n");
    }

    
    free(compu);

    return 0;
}

int generar_aleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void llenarDatos(Computadora *compu) {
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    compu->velocidad = generar_aleatorio(1, 3);           
    compu->anio = generar_aleatorio(2015, 2024);          
    compu->cantidad_nucleos = generar_aleatorio(1, 8);   

    int tipo_index = generar_aleatorio(0, 5);             
    compu->tipo_cpu = (char *)malloc(strlen(tipos[tipo_index]) + 1);  // +1 para el '\0'
    if (compu->tipo_cpu != NULL) {
        strcpy(compu->tipo_cpu, tipos[tipo_index]);  
    } else {
        printf("Error de asignación de memoria para tipo_cpu.\n");
    }
}