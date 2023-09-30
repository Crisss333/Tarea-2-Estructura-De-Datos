#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h" // Contiene las definiciones de estructuras y funciones utilizadas en este código.

// Variables globales para la lista de puntos de interes y turistas
PuntoDeInteres* listaPuntosDeInteres = NULL;
Turista* listaTuristas = NULL;

// Función para registrar un punto de interes
void registrarPuntoDeInteres(char* nombre, char* tipo, char* direccion, char* horario, char* descripcion) {
    if (strlen(nombre) > 100 || strlen(tipo) > 100 || strlen(direccion) > 100 ||
        strlen(horario) > 100 || strlen(descripcion) > 100) {
        printf("Error: Los campos no deben tener un largo mayor a 100 caracteres.\n");
        return;
    }

    // Crear un nuevo punto de interes
    PuntoDeInteres* nuevoPunto = (PuntoDeInteres*)malloc(sizeof(PuntoDeInteres));
    strcpy(nuevoPunto->nombre, nombre);
    strcpy(nuevoPunto->tipo, tipo);
    strcpy(nuevoPunto->direccion, direccion);
    strcpy(nuevoPunto->horario, horario);
    strcpy(nuevoPunto->descripcion, descripcion);
    nuevoPunto->siguiente = NULL;

    // Agregar el nuevo punto de interes a la lista
    if (listaPuntosDeInteres == NULL) {
        listaPuntosDeInteres = nuevoPunto;
    } else {
        PuntoDeInteres* actual = listaPuntosDeInteres;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoPunto;
    }

    printf("Punto de interes registrado con exito.\n");
}

// Función para mostrar datos de un punto de interes
void mostrarDatosPuntoDeInteres(char* nombre) {
    PuntoDeInteres* actual = listaPuntosDeInteres;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Nombre: %s\n", actual->nombre);
            printf("Tipo: %s\n", actual->tipo);
            printf("Direccion: %s\n", actual->direccion);
            printf("Horario: %s\n", actual->horario);
            printf("Descripcion: %s\n", actual->descripcion);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Punto de interes no encontrado.\n");
}

// Función para eliminar un punto de interes
void eliminarPuntoDeInteres(char* nombre) {
    if (listaPuntosDeInteres == NULL) {
        printf("Error: No hay puntos de interes registrados.\n");
        return;
    }

    if (strcmp(listaPuntosDeInteres->nombre, nombre) == 0) {
        PuntoDeInteres* temp = listaPuntosDeInteres;
        listaPuntosDeInteres = listaPuntosDeInteres->siguiente;
        free(temp);
        printf("Punto de interes eliminado con exito.\n");
        return;
    }

    PuntoDeInteres* anterior = listaPuntosDeInteres;
    PuntoDeInteres* actual = listaPuntosDeInteres->siguiente;

    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            anterior->siguiente = actual->siguiente;
            free(actual);
            printf("Punto de interes eliminado con exito.\n");
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    printf("Punto de interes no encontrado.\n");
}

// Función para registrar un turista
void registrarTurista(char* pasaporte, char* nombre, char* pais) {
    // Crear un nuevo turista
    Turista* nuevoTurista = (Turista*)malloc(sizeof(Turista));
    strcpy(nuevoTurista->pasaporte, pasaporte);
    strcpy(nuevoTurista->nombre, nombre);
    strcpy(nuevoTurista->paisOrigen, pais);
    nuevoTurista->lugaresFavoritos = NULL;
    nuevoTurista->siguiente = NULL;

    // Agregar el nuevo turista a la lista
    if (listaTuristas == NULL) {
        listaTuristas = nuevoTurista;
    } else {
        Turista* actual = listaTuristas;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoTurista;
    }

    printf("Turista registrado con exito.\n");
}

// Función para agregar un lugar favorito a un turista
void agregarLugarFavoritoATurista(char* pasaporte, char* nombre_lugar) {
    Turista* turista = listaTuristas;
    while (turista != NULL) {
        if (strcmp(turista->pasaporte, pasaporte) == 0) {
            // Buscar el punto de interes en la lista de puntos de interes
            PuntoDeInteres* puntoDeInteres = listaPuntosDeInteres;
            while (puntoDeInteres != NULL) {
                if (strcmp(puntoDeInteres->nombre, nombre_lugar) == 0) {
                    // Crear un nuevo lugar favorito
                    LugarFavorito* nuevoFavorito = (LugarFavorito*)malloc(sizeof(LugarFavorito));
                    nuevoFavorito->puntoDeInteres = puntoDeInteres;
                    nuevoFavorito->siguiente = NULL;

                    // Agregar el nuevo lugar favorito a la lista del turista
                    if (turista->lugaresFavoritos == NULL) {
                        turista->lugaresFavoritos = nuevoFavorito;
                    } else {
                        LugarFavorito* actual = turista->lugaresFavoritos;
                        while (actual->siguiente != NULL) {
                            actual = actual->siguiente;
                        }
                        actual->siguiente = nuevoFavorito;
                    }

                    printf("Lugar favorito agregado al turista con exito.\n");
                    return;
                }
                puntoDeInteres = puntoDeInteres->siguiente;
            }
            printf("El lugar no existe en la lista de puntos de interes.\n");
            return;
        }
        turista = turista->siguiente;
    }
    printf("Error: Turista no encontrado.\n");
}

// Función para mostrar turistas por pais
void mostrarTuristasPorPais(char* pais) {
    Turista* turista = listaTuristas;
    while (turista != NULL) {
        if (strcmp(turista->paisOrigen, pais) == 0) {
            printf("Pasaporte: %s\n", turista->pasaporte);
            printf("Nombre: %s\n", turista->nombre);
            printf("Pais de Origen: %s\n", turista->paisOrigen);

            // Mostrar la lista de lugares favoritos del turista
            printf("Lugares Favoritos:\n");
            LugarFavorito* favorito = turista->lugaresFavoritos;
            while (favorito != NULL) {
                printf("- %s\n", favorito->puntoDeInteres->nombre);
                favorito = favorito->siguiente;
            }

            printf("\n");
        }
        turista = turista->siguiente;
    }
}

// Función para mostrar todos los puntos de interes de un tipo
void mostrarPuntosDeInteresPorTipo(char* tipo) {
    PuntoDeInteres* puntoDeInteres = listaPuntosDeInteres;
    while (puntoDeInteres != NULL) {
        if (strcmp(puntoDeInteres->tipo, tipo) == 0) {
            printf("Nombre: %s\n", puntoDeInteres->nombre);
            printf("Tipo: %s\n", puntoDeInteres->tipo);
            printf("Direccion: %s\n", puntoDeInteres->direccion);
            printf("Horario: %s\n", puntoDeInteres->horario);
            printf("Descripcion: %s\n", puntoDeInteres->descripcion);
            printf("\n");
        }
        puntoDeInteres = puntoDeInteres->siguiente;
    }
}


// Función para importar datos desde archivos CSV
void importarDatosDesdeCSV(char* nombre_archivo_puntos, char* nombre_archivo_turistas) {
    FILE* archivo_puntos = fopen(nombre_archivo_puntos, "r");
    if (archivo_puntos == NULL) {
        printf("Error: No se pudo abrir el archivo de puntos de interés.\n");
        return;
    }

    FILE* archivo_turistas = fopen(nombre_archivo_turistas, "r");
    if (archivo_turistas == NULL) {
        printf("Error: No se pudo abrir el archivo de turistas.\n");
        fclose(archivo_puntos);
        return;
    }

    // Limpiar datos previos si los hay
    liberarTodosLosPuntosDeInteres();
    liberarTodosLosTuristas();

    char linea[256];

    // Leer datos de puntos de interés desde el archivo CSV
    fgets(linea, sizeof(linea), archivo_puntos); // Ignorar la primera línea con encabezados
    while (fgets(linea, sizeof(linea), archivo_puntos)) {
        char nombre[100], tipo[100], direccion[100], horario[100], descripcion[100];
        if (sscanf(linea, "%99[^,],%99[^,],%99[^,],%99[^,],%99[^\n]", nombre, tipo, direccion, horario, descripcion) == 5) {
            registrarPuntoDeInteres(nombre, tipo, direccion, horario, descripcion);
        } else {
            printf("Error: Formato de línea incorrecto en el archivo de puntos de interés.\n");
        }
    }

    // Leer datos de turistas desde el archivo CSV
    fgets(linea, sizeof(linea), archivo_turistas); // Ignorar la primera línea con encabezados
    while (fgets(linea, sizeof(linea), archivo_turistas)) {
        char pasaporte[100], nombre[100], pais[100], lugaresFavoritos[256];
        if (sscanf(linea, "%99[^,],%99[^,],%99[^,],%255[^\n]", pasaporte, nombre, pais, lugaresFavoritos) == 4) {
            registrarTurista(pasaporte, nombre, pais);

            // Dividir la lista de lugares favoritos y agregarlos al turista
            char* token = strtok(lugaresFavoritos, ";");
            while (token != NULL) {
                agregarLugarFavoritoATurista(pasaporte, token);
                token = strtok(NULL, ";");
            }
        } else {
            printf("Error: Formato de línea incorrecto en el archivo de turistas.\n");
        }
    }

    fclose(archivo_puntos);
    fclose(archivo_turistas);

    printf("Datos importados con éxito desde archivos CSV.\n");
}

// Función para exportar datos a archivos CSV
void exportarDatosACSV(char* nombre_archivo_puntos, char* nombre_archivo_turistas) {
    FILE* archivo_puntos = fopen(nombre_archivo_puntos, "w");
    if (archivo_puntos == NULL) {
        printf("Error: No se pudo crear el archivo de puntos de interés.\n");
        return;
    }

    FILE* archivo_turistas = fopen(nombre_archivo_turistas, "w");
    if (archivo_turistas == NULL) {
        printf("Error: No se pudo crear el archivo de turistas.\n");
        fclose(archivo_puntos);
        return;
    }

    // Escribir encabezados en el archivo de puntos de interés
    fprintf(archivo_puntos, "Nombre,Tipo,Dirección,Horario,Descripción\n");

    // Escribir datos de puntos de interés al archivo CSV
    PuntoDeInteres* punto = listaPuntosDeInteres;
    while (punto != NULL) {
        fprintf(archivo_puntos, "%s,%s,%s,%s,%s\n", punto->nombre, punto->tipo, punto->direccion, punto->horario, punto->descripcion);
        punto = punto->siguiente;
    }

    // Escribir encabezados en el archivo de turistas
    fprintf(archivo_turistas, "Pasaporte,Nombre,País,Lugares Favoritos\n");

    // Escribir datos de turistas al archivo CSV
    Turista* turista = listaTuristas;
    while (turista != NULL) {
        fprintf(archivo_turistas, "%s,%s,%s,", turista->pasaporte, turista->nombre, turista->paisOrigen);

        // Escribir la lista de lugares favoritos del turista
        LugarFavorito* favorito = turista->lugaresFavoritos;
        while (favorito != NULL) {
            fprintf(archivo_turistas, "%s", favorito->puntoDeInteres->nombre);
            if (favorito->siguiente != NULL) {
                fprintf(archivo_turistas, ";");
            }
            favorito = favorito->siguiente;
        }
        fprintf(archivo_turistas, "\n");

        turista = turista->siguiente;
    }

    fclose(archivo_puntos);
    fclose(archivo_turistas);

    printf("Datos exportados con éxito a archivos CSV.\n");
}



// Función para liberar la memoria de todos los lugares favoritos de un turista
void liberarLugaresFavoritos(LugarFavorito* lista) {
    while (lista != NULL) {
        LugarFavorito* temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}

// Función para liberar la memoria de todos los turistas y sus listas de lugares favoritos
void liberarTodosLosTuristas() {
    Turista* turista = listaTuristas;
    while (turista != NULL) {
        liberarLugaresFavoritos(turista->lugaresFavoritos);
        Turista* temp = turista;
        turista = turista->siguiente;
        free(temp);
    }
    listaTuristas = NULL;
}

// Función para liberar la memoria de todos los puntos de interes
void liberarTodosLosPuntosDeInteres() {
    while (listaPuntosDeInteres != NULL) {
        PuntoDeInteres* temp = listaPuntosDeInteres;
        listaPuntosDeInteres = listaPuntosDeInteres->siguiente;
        free(temp);
    }
}
