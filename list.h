#ifndef LIST_H
#define LIST_H

#define MAX_CHAR_LENGTH 100

// Definición de estructuras

// Estructura para un punto de interes turistico
typedef struct PuntoDeInteres {
    char nombre[100];
    char tipo[100];
    char direccion[100];
    char horario[100];
    char descripcion[100];
    struct PuntoDeInteres* siguiente;
} PuntoDeInteres;

// Estructura para un turista
typedef struct Turista {
    char pasaporte[100];
    char nombre[100];
    char paisOrigen[100];
    struct LugarFavorito* lugaresFavoritos;
    struct Turista* siguiente;
} Turista;

// Estructura para un lugar favorito (para la lista de lugares favoritos de un turista)
typedef struct LugarFavorito {
    PuntoDeInteres* puntoDeInteres;
    struct LugarFavorito* siguiente;
} LugarFavorito;

// Prototipos de funciones
void registrarPuntoDeInteres(char* nombre, char* tipo, char* direccion, char* horario, char* descripcion);
// Agrega un nuevo punto de interés a la aplicación 

void mostrarDatosPuntoDeInteres(char* nombre);
// Entrega la infromación de un punto de interés en particular

void eliminarPuntoDeInteres(char* nombre);
// Elimina un punto de interés de la aplicación

void registrarTurista(char* pasaporte, char* nombre, char* pais);
// Agrega los datos de un nuevo turista a la aplicación

void agregarLugarFavoritoATurista(char* pasaporte, char* nombre_lugar);
// Agrega un nuevo lugar a la lista de Lugares Favoritos de un turista

void mostrarTuristasPorPais(char* pais);
// Muestra por pantalla los datos de todos los turistas pertenecientes a un país

void mostrarPuntosDeInteresPorTipo(char* tipo);
// Se despliega por pantalla la información de todos los lugares de interés de cierto tipo

void importarDatosDesdeCSV(char* nombre_archivo_puntos, char* nombre_archivo_turistas);
// Importa los datos tanto de turistas como de puntos de interés desde un CSV.

void exportarDatosACSV(char* nombre_archivo_puntos, char* nombre_archivo_turistas);
// Exporta todos los puntos de interés y turistas, sus datos y las listas de lugares favoritos a un archivos CSV indicados por el usuario.

void liberarLugaresFavoritos(LugarFavorito* lista);
// Se libera la memoria utilizada por una lista de Lugares Favoritos

void liberarTodosLosTuristas();
// Se libera la memoria utilizada para almacenar los datos de los turistas

void liberarTodosLosPuntosDeInteres();
// Se libera la memoria utilizada para almacenar los datos de los puntos de interés

#endif //LIST_H
