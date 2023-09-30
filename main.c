#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h" // Contiene las definiciones de estructuras y funciones utilizadas en este código.

// Implementación de la aplicación

int main() {
    int opcion;
    char entrada[100];

    do {
        printf("\nMenu:\n");
        printf("1. Registrar punto de interes\n");
        printf("2. Mostrar datos de punto de interes\n");
        printf("3. Eliminar punto de interes\n");
        printf("4. Registrar turista\n");
        printf("5. Agregar lugar favorito a turista\n");
        printf("6. Mostrar turistas por pais\n");
        printf("7. Mostrar todos los puntos de interes de un tipo\n");
        printf("8. Importar puntos de interes y turistas desde archivos CSV\n");
        printf("9. Exportar puntos de interes y turistas a archivos CSV\n");
        printf("0. Salir\n");
        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del punto de interes: ");
                scanf("%s", entrada);
                char tipo[100], direccion[100], horario[100], descripcion[100];
                printf("Ingrese el tipo: ");
                scanf("%s", tipo);
                printf("Ingrese la direccion: ");
                scanf("%s", direccion);
                printf("Ingrese el horario: ");
                scanf("%s", horario);
                printf("Ingrese la descripcion: ");
                scanf("%s", descripcion);
                registrarPuntoDeInteres(entrada, tipo, direccion, horario, descripcion);
                break;
            case 2:
                printf("Ingrese el nombre del punto de interes a mostrar: ");
                scanf("%s", entrada);
                mostrarDatosPuntoDeInteres(entrada);
                break;
            case 3:
                printf("Ingrese el nombre del punto de interes a eliminar: ");
                scanf("%s", entrada);
                eliminarPuntoDeInteres(entrada);
                break;
            case 4:
                printf("Ingrese el pasaporte del turista: ");
                scanf("%s", entrada);
                char nombreTurista[100], paisTurista[100];
                printf("Ingrese el nombre del turista: ");
                scanf("%s", nombreTurista);
                printf("Ingrese el pais de origen: ");
                scanf("%s", paisTurista);
                registrarTurista(entrada, nombreTurista, paisTurista);
                break;
            case 5:
                printf("Ingrese el pasaporte del turista: ");
                scanf("%s", entrada);
                char nombreLugarFavorito[100];
                printf("Ingrese el nombre del lugar favorito: ");
                scanf("%s", nombreLugarFavorito);
                agregarLugarFavoritoATurista(entrada, nombreLugarFavorito);
                break;
            case 6:
                printf("Ingrese el pais para mostrar los turistas: ");
                scanf("%s", entrada);
                mostrarTuristasPorPais(entrada);
                break;
            case 7:
                printf("Ingrese el tipo para mostrar puntos de interes: ");
                scanf("%s", entrada);
                mostrarPuntosDeInteresPorTipo(entrada);
                break;
            case 8:
                printf("Ingrese el nombre del archivo CSV de puntos de interes: ");
                scanf("%s", entrada);
                char nombre_archivo_puntos[100];
                strcpy(nombre_archivo_puntos, entrada);
                printf("Ingrese el nombre del archivo CSV de turistas: ");
                scanf("%s", entrada);
                char nombre_archivo_turistas[100];
                strcpy(nombre_archivo_turistas, entrada);
                importarDatosDesdeCSV(nombre_archivo_puntos, nombre_archivo_turistas);
                break;
            case 9:
                printf("Ingrese el nombre del archivo CSV para exportar puntos de interes: ");
                scanf("%s", entrada);
                char nombre_archivo_puntos_exportar[100];
                strcpy(nombre_archivo_puntos_exportar, entrada);
                printf("Ingrese el nombre del archivo CSV para exportar turistas: ");
                scanf("%s", entrada);
                char nombre_archivo_turistas_exportar[100];
                strcpy(nombre_archivo_turistas_exportar, entrada);
                exportarDatosACSV(nombre_archivo_puntos_exportar, nombre_archivo_turistas_exportar);
                break;
            case 0:
                // Salir del programa
                liberarTodosLosTuristas();
                liberarTodosLosPuntosDeInteres();
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}
