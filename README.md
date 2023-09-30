# Tarea 2 Estructura De Datos

# Cristopher Dauros Deij

INTRODUCCIÓN
El algoritmo que se presenta a continuación corresponde a la implementación de una aplicación de gestión de información turística, la cuál poseee una serie de funcionalidades que permiten almacenar, revisar y eliminar información tanto sobre "turistas" como "lugares turísticos de interés". Lo anterior se puede realizar de manera sencilla accediendo a alguna de las 10 opciones desplegadas en el menú de la aplicación. Este menú posee las siguientes opciones:

1. **Registrar punto de interés** (char* nombre, char* tipo, char* dirección, char* horario, char* descripción): El usuario ingresa los datos del lugar y la aplicación los almacena. La validación de los datos debe asegurar que ningún campo char* tenga un largo mayor a 100 caracteres.
   
2. **Mostrar datos de punto de interés** (char* nombre): El usuario ingresa el nombre del lugar y la aplicación muestra sus datos. Si no existe, se muestra un aviso.
   
3. **Eliminar punto de interés** (char* nombre): El usuario ingresa el nombre del lugar y la aplicación lo elimina. Si no existe, se muestra un aviso.
   
4. **Registrar turista** (char* pasaporte, char* nombre, char* país): El usuario ingresa los datos del turista y la aplicación los almacena.
   
5. **Agregar lugar favorito a turista** (char* pasaporte, char* nombre_lugar): El usuario ingresa el pasaporte del turista y el nombre del lugar favorito, y la aplicación lo agrega a la lista de lugares favoritos del turista.
   
6. **Mostrar turistas por país** (char* país): La aplicación muestra todos los turistas de un país específico y sus listas de lugares favoritos.
    
7. **Mostrar todos los puntos de interés de un tipo** (char* tipo): La aplicación muestra todos los lugares de un tipo específico (por ejemplo, todos los museos).
    
8. **Importar puntos de interés y turistas desde archivos CSV** (char* nombre_archivo_puntos, char* nombre_archivo_turistas): El usuario ingresa los nombres de archivo y la aplicación carga todos los puntos de interés y turistas, incluyendo las listas de lugares favoritos.
    
9. **Exportar puntos de interés y turistas a archivos CSV** (char* nombre_archivo_puntos, char* nombre_archivo_turistas): La aplicación exporta todos los puntos de interés y turistas, sus datos y las listas de lugares favoritos a archivos CSV indicados por el usuario.

0. **Salir**: Permite cerrar la aplicación.


PROBLEMA CONOCIDO:
Si el formato en que se ingresa el horario de un lugar de interés posee la siguiente forma "hh:mm - hh:mm", la aplicación comienza a desplegar el menú en un bucle infinito hasta que uno detenga la ejecución del programa. Cualquier otro formato de horario ingresado (ej: "hh:mm-hh:mm") no causa ningún problema en la aplicación. 


CÓMO COMPILAR Y EJECUTAR EL PROGRAMA

Primero debemos clonar el repositorio en un compilador e intérprete de preferencia. Una vez clonado el repositorio completo se debe correr el programa principal para que se ejecute la aplicación, la cuál debiese desplegar inicialmente el siguiente menú:

Menu:
1. Registrar punto de interes
2. Mostrar datos de punto de interes
3. Eliminar punto de interes
4. Registrar turista
5. Agregar lugar favorito a turista
6. Mostrar turistas por pais
7. Mostrar todos los puntos de interes de un tipo
8. Importar puntos de interes y turistas desde archivos CSV
9. Exportar puntos de interes y turistas a archivos CSV
0. Salir
Ingrese la opcion:
 
Una vez se haya desplegado el menú de la aplicación, se debe ingresar el índice de la opción a la cuál se quiera acceder. Luego solo basta con ir completando los datos de cada uno de los campos que se irán solicitando y presionar enter al completar cada uno para acceder al siguiente. 

NOTA: Cada campo ingresado no puede poseer mas de 100 caractéres.

Una vez concluida la utilización de la aplicación se debe ingresar la opción “0” para cerrarla. Al hacer esto, dejará de existir el ejecutable creado al correr el programa por lo que toda la información almacenada en la aplicación será eliminada de la memoria.
