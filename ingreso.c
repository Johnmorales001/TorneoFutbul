#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ingreso.h"

int ingresarNumero() {
    char input[100];
    int num = -1;

    fgets(input, 100, stdin);
    if(sscanf(input, "%d\n", &num) != 1) {
        printf("Error: Ingresa un numero valido.\n");
        getchar();
        system(LIMPIAR_CONSOLA);
        return num;
    }

    return num;
}

void pausarFlujoDelPrograma() {
    printf("Pulsa ENTER para continuar...");
    getchar();
    system(LIMPIAR_CONSOLA);
}

void ingresarEquipos() {
    char equipos[MAX_EQUIPOS][MAX_NOMBRE_EQUIPO];
    char nombreEquipo[MAX_NOMBRE_EQUIPO];
    FILE *archivoEquipos;
    int numEquipos = obtenerNumeroEquipos();

    archivoEquipos = fopen(ARCHIVO_EQUIPOS, "a");

    if (archivoEquipos == NULL) {
        printf("Error al abrir el archivo de equipos.\n");
        pausarFlujoDelPrograma();
        return;
    }

    printf("Ingrese los nombres de los equipos (escriba 'terminar' para finalizar):\n");

    do {
        printf("Equipo %d: ", numEquipos + 1);
        scanf(" %[^\n]s", nombreEquipo);

        if (strcmp(nombreEquipo, "terminar") == 0) {
            break;
        }

        strcpy(equipos[numEquipos], nombreEquipo);
        fprintf(archivoEquipos, "%s\n", equipos[numEquipos]);
        numEquipos++;
    } while (strcmp(nombreEquipo, "terminar") != 0);

    fclose(archivoEquipos);

    printf("Se han ingresado %d equipos.\n", numEquipos);
    printf("Pulsa ENTER para continuar...");
    getchar(); getchar();
    system(LIMPIAR_CONSOLA);
}

void mostrarEquipos() {
    char equipos[MAX_EQUIPOS][MAX_NOMBRE_EQUIPO];
    int numEquipos = obtenerEquipos(equipos);

    if (numEquipos == 0) {
        printf("No se ha ingresado ningun equipo aun.\n");
    } else {
        printf("Equipos ingresados:\n");
        for (int i = 0; i < numEquipos; i++) {
            printf("%d. %s\n", i + 1, equipos[i]);
        }
    }
}

int obtenerEquipos(char equipos[][MAX_NOMBRE_EQUIPO]) {
    FILE *archivoEquipos;
    char nombreEquipo[MAX_NOMBRE_EQUIPO];
    int numEquipos = 0;

    archivoEquipos = fopen(ARCHIVO_EQUIPOS, "r");
    if(archivoEquipos == NULL) {
        printf("No se encontro el archivo de equipos.\n");
        pausarFlujoDelPrograma();
        return 0;
    }

    while(fgets(nombreEquipo, MAX_NOMBRE_EQUIPO, archivoEquipos) != NULL) {
        // Eliminar el salto de línea al final del nombre del equipo
        nombreEquipo[strcspn(nombreEquipo, "\n")] = '\0';
        strcpy(equipos[numEquipos], nombreEquipo);
        numEquipos++;
    }

    fclose(archivoEquipos);
    return numEquipos;
}

int obtenerNumeroEquipos() {
    FILE *archivoEquipos;
    char nombreEquipo[MAX_NOMBRE_EQUIPO];
    int numEquipos = 0;

    archivoEquipos = fopen(ARCHIVO_EQUIPOS, "r");
    if(archivoEquipos == NULL) {
        return 0;
    }

    while(fgets(nombreEquipo, MAX_NOMBRE_EQUIPO, archivoEquipos) != NULL) {
        numEquipos++;
    }

    fclose(archivoEquipos);
    return numEquipos;
}