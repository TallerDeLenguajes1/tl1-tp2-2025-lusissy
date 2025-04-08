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

// Declaración de funciones
int generar_aleatorio(int min, int max);
void llenarDatos(Computadora *compu);
void listarPCs(Computadora pcs[], int cantidad);
void mostrarMasVieja(Computadora pcs[], int cantidad);
void mostrarMasVeloz(Computadora pcs[], int cantidad);

int main() {
    int cantComputadoras = 5; 
    Computadora *compu = (Computadora *)malloc(cantComputadoras * sizeof(Computadora)); 
    srand(time(NULL));

    for (int i = 0; i < cantComputadoras; i++) {
        llenarDatos(&compu[i]); 
    }

    listarPCs(compu, cantComputadoras);
    printf("\n");
    mostrarMasVieja(compu, cantComputadoras);
    printf("\n");
    mostrarMasVeloz(compu, cantComputadoras);

    for (int i = 0; i < cantComputadoras; i++) {
        free(compu[i].tipo_cpu);
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
        printf("Error de asignacion de memoria para tipo_cpu.\n");
    }
}

// Función para listar todas las PCs
void listarPCs(Computadora pcs[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("PC %d:\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Anio de fabricacion: %d\n", pcs[i].anio);
        printf("  Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo de procesador: %s\n", pcs[i].tipo_cpu);
        printf("\n");
    }
}

// Función para mostrar la PC más vieja (con el menor Anio de fabricación)
void mostrarMasVieja(Computadora pcs[], int cantidad) {
    int index_mas_vieja = 0; 
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[index_mas_vieja].anio) {
            index_mas_vieja = i; 
        }
    }

    printf("La PC mas vieja es:\n");
    printf("  Velocidad: %d GHz\n", pcs[index_mas_vieja].velocidad);
    printf("  Anio de fabricacion: %d\n", pcs[index_mas_vieja].anio);
    printf("  Cantidad de nucleos: %d\n", pcs[index_mas_vieja].cantidad_nucleos);
    printf("  Tipo de procesador: %s\n", pcs[index_mas_vieja].tipo_cpu);
}

// Función para mostrar la PC más veloz (con la mayor velocidad de procesamiento)
void mostrarMasVeloz(Computadora pcs[], int cantidad) {
    int index_mas_veloz = 0; 
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > pcs[index_mas_veloz].velocidad) {
            index_mas_veloz = i; 
        }
    }

    printf("La PC mas veloz es:\n");
    printf("  Velocidad: %d GHz\n", pcs[index_mas_veloz].velocidad);
    printf("  Anio de fabricacion: %d\n", pcs[index_mas_veloz].anio);
    printf("  Cantidad de nucleos: %d\n", pcs[index_mas_veloz].cantidad_nucleos);
    printf("  Tipo de procesador: %s\n", pcs[index_mas_veloz].tipo_cpu);
}
