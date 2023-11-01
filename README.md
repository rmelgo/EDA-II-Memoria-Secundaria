# Gestión de la Memoria Secundaria en C

# - Introducción

Proyecto realizado en la asignatura de ***Estructuras de Datos y Algortimos II*** del grado de Ingenieria Informática de la Universidad de Salamanca. El enunciado del proyecto se encuentra subido en el repositorio en un archivo PDF llamado <a href="https://github.com/rmelgo/EDA-II-Memoria-Secundaria/blob/main/EntregaMemoriaSecundaria2021.pdf" target="_blank">*EntregaMemoriaSecundaria2021.pdf*</a>.  
  
El principal objetivo de este proyecto es la implementación de funciones en el lenguaje C que trabajen con la ***organización indexada*** y la ***organización directa (dispersión)***. Para ello, se dispondran de varios archivos almacenados en memoria secuendaria los cuales serán utilizados para probar el correcto funcionamiento de las funciones implementadas.

# - Comentarios sobre el material adjuntado

Se adjuntan 2 carpetas llamadas ***Ejercicio1*** y ***Ejercicio2***. Cada una de estas subcarpetas contiene un fichero .c con la implementación de las funciones implementadas de *organización indexada* y la *organización directa* respectivamente y unos ficheros .h de cabecera que definen las funciones creadas en cada caso.

Por otra parte, existen 3 ficheros llamados ***alumnos.dat***, ***alumnos.hash*** y ***alumnos.idx***. El primer fichero se utilizará para las pruebas con las ***organización indexada*** mientras que el segundo fichero se utilizará para las pruebas con las ***organización directa (dispersión)***. El tercer fichero se obtendrá como resultado al probar las funciones del ejercicio 1.

Adicionalmente, se incluye un fichero llamado *prueba.c* que contiene un código para probar la correcta implementación de las funciones sobre memoria secuendaria.  

También se incluye un fichero *makefile* que contiene las directivas necesarias para compilar dicho fichero incluyendo las funciones implementadas en el ***Ejercicio 1*** y en el ***Ejercicio 2***.

# - Comentarios sobre la ejecución

Para probar la correcta implementación de las funciones, se requerirá de una distribución del Sistema Operativo **GNU/Linux**.    

Para compilar el fichero de pruebas, se utilizará el siguiente comando:

```make```

Este comando generará un ejecutable llamado *memsec* a partir del fichero *prueba.c* y las implementaciones de las funciones.

Para ejecutar el programa, bastará con introducir el siguiente comando por la terminal:

```./memsec```

# - Ejemplo de ejecución

En las siguientes imagenes, se muestra un ejemplo del uso y funcionamiento del programa:    

![Ejemplo ejecucion 1](https://github.com/rmelgo/EDA-II_Memoria-Secundaria/assets/145989723/12fce24d-9231-4b6e-87e2-764628f42809)
![Ejemplo ejecucion 2](https://github.com/rmelgo/EDA-II_Memoria-Secundaria/assets/145989723/a7c1f3a8-ec8c-456c-ab3d-42aec174e776)
![Ejemplo ejecucion 3](https://github.com/rmelgo/EDA-II_Memoria-Secundaria/assets/145989723/b8cfa6c4-6b86-4d6d-a91e-0d552587b318)
![Ejemplo ejecucion 4](https://github.com/rmelgo/EDA-II_Memoria-Secundaria/assets/145989723/e9628b1b-94b9-49cc-a3be-e18a84a5484a)
![Ejemplo ejecucion 5](https://github.com/rmelgo/EDA-II_Memoria-Secundaria/assets/145989723/be215e2e-f1c2-4adf-9811-165508f96374)
![Ejemplo ejecucion 6](https://github.com/rmelgo/EDA-II_Memoria-Secundaria/assets/145989723/6aa79f0b-4d13-49b1-a8da-437a391581e8)
![Ejemplo ejecucion 7](https://github.com/rmelgo/EDA-II_Memoria-Secundaria/assets/145989723/9ac05a67-76a2-4074-b4ff-2099c6f61015)

# - Participantes

<table>
  <td align="center"><a href="https://github.com/rmelgo"><img src="https://avatars.githubusercontent.com/u/145989723?s=400&u=e5c06adba3f3c418207178abc845d398b3d5f77f&v=4" width="100px;" alt=""/><br /><sub><b>Raúl Melgosa</b></sub></a><br/> 
</table>
