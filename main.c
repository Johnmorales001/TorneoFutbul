#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ingreso.h"
#include "torneo.h"
#include "resultados.h"

//Realizado por: John Morales, Alejandro Acosta y Nathalia Maldonado

void mostrarMenu() {
    printf("------ Menu ------\n");
    printf("1. Ingresar equipos\n");
    printf("2. Mostrar equipos\n");
    printf("3. Generar resultados\n");
    printf("4. Ingresar resultados\n");
    printf("5. Mostrar tabla de posiciones\n");
    printf("6. Mostrar resultados de los partidos\n");
    printf("7. Salir\n");
    printf("------------------\n");
}

int main() {
    int opcion, numEquipos;

    do {
        numEquipos = obtenerNumeroEquipos();

        mostrarMenu();

        printf("Ingrese una opcion: ");
        opcion = ingresarNumero();

        switch(opcion) {
            case 1:
                system(LIMPIAR_CONSOLA);
                ingresarEquipos();
                break;
            case 2:
                system(LIMPIAR_CONSOLA);
                mostrarEquipos();
                pausarFlujoDelPrograma();
                break;
            case 3:
                system(LIMPIAR_CONSOLA);
                if(numEquipos == 0) {
                    printf("Debe ingresar los equipos primero.\n");
                    pausarFlujoDelPrograma();
                    break;
                }
                srand(time(NULL));
                generarResultadosAutomaticamente();
                pausarFlujoDelPrograma();
                break;
            case 4:
                system(LIMPIAR_CONSOLA);
                if(numEquipos == 0) {
                    printf("Debe ingresar los equipos primero.\n");
                    pausarFlujoDelPrograma();
                    break;
                }
                ingresarResultados();
                pausarFlujoDelPrograma();
                break;
            case 5:
                system(LIMPIAR_CONSOLA);
                if(numEquipos == 0) {
                    printf("Debe ingresar los equipos primero.\n");
                    pausarFlujoDelPrograma();
                    break;
                }
                mostrarTablaDePosiciones();
                pausarFlujoDelPrograma();
                break;
            case 6:
                system(LIMPIAR_CONSOLA);
                if(numEquipos == 0) {
                    printf("Debe ingresar los equipos primero.\n");
                    pausarFlujoDelPrograma();
                    break;
                }
                mostrarResultados();
                pausarFlujoDelPrograma();
                break;
            case 7:
                system(LIMPIAR_CONSOLA);
                printf("¡Hasta luego!\n");
                pausarFlujoDelPrograma();
                exit(0);
            default:
                system(LIMPIAR_CONSOLA);
                printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                pausarFlujoDelPrograma();
        }
    } while(opcion != 7);

    return 0;
}
