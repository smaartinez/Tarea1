# Sistema de Gestión de tickets

# Descripción del Programa
Este sistema permite ingresar, gestionar y atender tickets. Los usuarios pueden crear su propio ticket, identificarlo con una ID Númerica, escribir la descripción de este. El programa le asignará automáticamente prioridad baja, además 
el ticket se guarda con la hora actual del dispositivo. Dentro de este podrás ingresar múltiples tickets, actualizarles su prioridad utilizando su ID, mostrar la lista de tickets pendientes ordenados por prioridad de atención, buscar un
ticket por ID para ver su descripción, prioridad y la hora que fue ingresado, además de atender atender los tickets por prioridad. 

# Como ejecutar para utilizar el programa
Este programa ha sido desarrollado en el lenguaje C y puede ejecutarse utilizando *Visual Studio Code* junto con una extensión para C/C++, como la *Extension pack de Microsoft* que se descarga del mismo Visual Studio Code
Para poder ejecutarlo siga los siguientes pasos.

# Requisitos Previos
1. Tener instalado Visual Studio Code
2. Tener la extención C/C++
3. Tener instalado un compilador de C, como por ejemplo *MinGW*


# Pasos para ejecutar

1. Descarga el archivo .zip y descomprime este en un directorio a elección
2. Abre el código en Visual Studio Code
Para esto:
- Abre la aplicacion
- Archivo -> Abrir Carpeta
- Y seleccionamos la carpeta donde descomprimimos el programa

3. Para compilar el codigo
- Crea una nueva terminal, en Terminal -> Nueva Terminal
- En la terminal coloca este comando: gcc Tarea1.c arraylist.c (Esto lo que hará será crear un Archivo.Exe para ejecutar el programa)
- Luego ingresa a la carpeta donde hayas descomprimido el programa y ejecuta el .Exe


# Funcionalidades
- Registrar tickets
- Asignar Prioridad de atención a este
- Poder buscar el ticket por ID
- Mostrar lista de tickets pendientes ordenados por orden de prioridad
- Atender tickets en orden de prioridad.

# Problemas Frecuentes
- Si al programa se le ingresan letras cuando se requiere utilizar Números es decir (Id u prioridad) este falla

# Posibles Mejoras
- Actualizar este para que no falle el programa cuando se le ingresen cáracteres donde no se deba
- Al cerrar el programa, los tickets que no hayan sido atendidos queden guardados en este.


# Ejemplo de Uso

![image](https://github.com/user-attachments/assets/4c3443c3-a7f0-46d0-bb83-e119e0a0ffed)

Opción 1. Crear Ticket

![image](https://github.com/user-attachments/assets/1801b79c-f021-4ef6-8e60-f80c4678b108)

Este será el menú en el cual deberemos ingresar el ID y la descripción de este.
Luego de ingresarlo mostrará un mensaje como este: 
"Ticket ingresado con exito! Ingresado en la lista de Prioridad Baja"

Opción 2. Asignar tipo de prioridad al ticket

![image](https://github.com/user-attachments/assets/d114238c-2153-4315-92ea-4ef5fe4b6551)

Tendremos que ingresar el ID del ticket que querramos actualizarle su ID.
Luego nos dará las opciones de prioridad e ingresaremos el número correspondieste 
a este (OJO SOLO NÚMEROS)

luego nos mostrára un mensaje como este: "Ticket con ID 255034 asignado a la lista de prioridad alta."

Opción 3. Mostrar Lista de tickets pendientes por atender 

![image](https://github.com/user-attachments/assets/4c5ef97f-28ce-4a17-a4e9-a07fc9d98c3e)

Veremos que el sistema nos mostrará los tickets sin atender ordenados por prioridad, mostrandonos su ID, descripción, prioridad y hora de ingreso.


Opción 4. Procesar siguiente ticket

![image](https://github.com/user-attachments/assets/a214a25d-dbd9-4bda-81c4-2c2663211e0b)

Se nos mostrará un mensaje así indicandonos los datos del ticket que fue atendido. Si no hay mas tickets que procesar este nos indicará con un mensaje.


Opción 5. Buscar ticket por ID y mostrar sus detalles.

![image](https://github.com/user-attachments/assets/72c2342f-974a-4df5-b002-2cab738375e5)

El programa nos solicitará ingresar el ID (SOLO DATOS NÚMERICOS) del ticket que querramos buscar y mostrar sus detalles. El programa nos avisará si el ID no existe.

Opción 6. Salir del Programa

Al seleccionar esta opción se cerrará el programa y los tickets que esten aún sin atender se perderán.





