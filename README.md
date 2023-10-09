# Gestión de la Memoria Secundaria en C

# - Introducción

Proyecto realizado en la asignatura de Estructuras de Datos y Algortimos II del grado de Ingenieria Informática de la Universidad de Salamanca. El enunciado del proyecto se encuentra subido en el repositorio en un archivo pdf llamado *EntregaMemoriaSecundaria2021.pdf*.  
  
El principal objetivo de este proyecto es la implementación de funciones en el lenguaje C que trabajen con la ***organización indexada*** y la ***organización directa (dispersión)***. Para ello, se dispondran de varios archivos almacenados en memoria secuendaria los cuales serán utilizados para probar el correcto funcionamiento de las funciones implementadas.

# - Comentarios sobre el material adjuntado

Se adjuntan 2 carpetas llamadas ***Ejercicio1*** y ***Ejercicio2***. Cada una de estas subcarpetas contiene un fichero .c con la implementación de las funciones implementadas de *organización indexada* y la *organización directa* respectivamente y unos ficheros .h de cabecera que definen las funciones creadas en cada caso.

Por otra parte, existen 3 ficheros llamados ***alumnos.dat***, ***alumnos.hash*** y ***alumnos.idx***. El primer fichero se utilizará para las pruebas con las ***organización indexada*** mientras que el segundo fichero se utilizará para las pruebas con las ***organización directa (dispersión)***. El tercer fichero se obtendrá como resultado al probar las funciones del ejercicio 1.

Adicionalmente, se incluye un fichero llamado *prueba.c* que contiene un codigo para probar la correcta implementación de las funciones sobre memoria secuendaria.  

También se incluye un fichero *makefile* que contiene las directivas necesarias para compilar dicho fichero incluyendo las funciones implementadas en el Ejercicio 1 y en el Ejercicio 2.

# - Comentarios sobre la ejecución

Para probar la correcta implementación de las funciones, se requerirá de una distribución del Sistema Operativo **GNU/Linux**.    

Para compilar el fichero de pruebas, se utilizará el siguiente comando:

```make```

Este comando generará un ejecutable llamado *memsec* a partir del fichero *prueba.c* y las implementaciones de las funciones.

Para ejecutar el programa, bastará con introducir el siguiente comando por la terminal:

```./memsec```

# - Ejemplo de ejecución

En las siguientes imagenes, se muestra un ejemplo del uso y funcionamiento del programa:    
