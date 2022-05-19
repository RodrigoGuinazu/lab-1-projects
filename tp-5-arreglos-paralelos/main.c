#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cargarAlumnos(char nombres[20][30], int legajos[20], int anios[20]);
void mostrarAlumnos(char nombres[20][30], int legajos[20], int anios[20], int validos);
int posicionDelBuscado(int legajos[20], int validos, int elemento);
void encontrarNombre(char nombres[20][30], int legajos[20], int validos, int legajoABuscar);
int buscarMenor (char nombres[20][30], int legajos[20], int anios[20], int validos, int iterador);
void ordenarPorSeleccion(char nombres[20][30], int legajos[20], int anios[20], int validos);

int main()
{
    char nombres[20][30];
    int legajos[20];
    int anios[20];

    // 1
    int validos = cargarAlumnos(nombres, legajos, anios);
    mostrarAlumnos(nombres, legajos, anios, validos);

    // 2
    int resultado = posicionDelBuscado(legajos, validos, 420);
    if(resultado != -1){
        printf("\nEl legajo se encuentra en la posicion: %i\n", resultado);
    }else{
        printf("\nEl legajo no coincide con ninguna posicion\n");
    }

    // 3
    encontrarNombre(nombres, legajos, validos, 19);

    // 4
    ordenarPorSeleccion(nombres, legajos, anios, validos);
    mostrarAlumnos(nombres, legajos, anios, validos);

    return 0;
}

// 1

int cargarAlumnos(char nombres[20][30], int legajos[20], int anios[20]){
    int i = 0;
    char control = 's';
    while(i<20 && control == 's'){
        printf("\nNombre completo del Alumno:\n");
        fflush(stdin);
        gets(nombres[i]);
        printf("\nNro de Legajo:\n");
        fflush(stdin);
        scanf("%i", &legajos[i]);
        printf("\nEdad del alumno:\n");
        fflush(stdin);
        scanf("%i", &anios[i]);
        i++;
        printf("\nDesea cargar a otro alumno?\n");
        fflush(stdin);
        scanf("%c", &control);
    }

    return i;
}

void mostrarAlumnos(char nombres[20][30], int legajos[20], int anios[20], int validos){
    for(int i = 0; i<validos; i++){
        printf("\n Nombre: %s\n Legajo: %i\n Edad: %i\n", nombres[i], legajos[i], anios[i]);
        //system("pause"); //Ejercicio 5
    }
}

// 2

int posicionDelBuscado(int legajos[20], int validos, int elemento){
    int i = 0;
    while(i<validos){
        if(legajos[i] == elemento){
            return i;
        }
        i++;
    }
    return -1;
}

// 3

void encontrarNombre(char nombres[20][30], int legajos[20], int validos, int legajoABuscar){
    int busqueda = posicionDelBuscado(legajos, validos, legajoABuscar);
    if(busqueda != -1){
        printf("\nEl legajo nro %i pertenece a %s\n", legajoABuscar, nombres[busqueda]);
    }else {
        printf("\nEl legajo buscado no pertenece a ningun alumno\n");
    }
}

// 4

int buscarMenor (char nombres[20][30], int legajos[20], int anios[20], int validos, int iterador){
    char menor[30];
    strcpy(menor, nombres[iterador]); /// Copiamos en menor lo que haya en nombres[iterador]
    int pos = iterador; /// Igualamos la variable pos al valor de iterador
    int i = pos + 1;

    while(i<validos){ /// Recorro todo el array hasta encontrar el menor
        if(strcmp(nombres[i], menor) == -1){ /// Si la palabra que se encuentra en nombres[i] es menor se ejecuta lo siguiente
            strcpy(menor, nombres[i]); /// Copiamos en menor lo que hay en nombres[i], de esta forma tenemos el nuevo menor almacenado
            pos = i; /// Tambien cambiamos el valor de pos para luego retornarlo y utilizarlo en la funcion ordenarPorSeleccion
        }
        i++;
    }
    return pos;
}

void ordenarPorSeleccion(char nombres[20][30], int legajos[20], int anios[20], int validos){
    int i = 0;
    int pos = 0;
    int num = 0;
    char aux[30];

    while(i<validos-1){ /// Validos - 1 ya que la ultima posicion se supone que ya queda ordenada despues de todo el procedimiento
        pos = buscarMenor(nombres, legajos, anios, validos, i); /// Ejecuto la funcion de buscarMenor para almacenar lo que retorne en la variable pos

        strcpy(aux, nombres[pos]); /// Copiamos en aux lo que hay en nombres[pos], de esta forma guardamos el menor valor del array
        strcpy(nombres[pos], nombres[i]); /// Modificamos nombres[pos] por lo que haya en nombres[i], ahora nombres[pos] tiene almacenado lo que habia en nombres[i]
        strcpy(nombres[i], aux); /// Modificamos nombres[i] por lo que haya en el string aux, finalmente guardamos en nombres[i] el valor que corresponde

        num = legajos[pos]; /// Guardamos el valor de legajo[pos] en la variable num, de esta forma guardamos el menor valor del array
        legajos[pos] = legajos[i]; /// Guardamos el valor de legajo[i] en legajos[pos], ahora nombres[pos] tiene almacenado lo que habia en nombres[i]
        legajos[i] = num; /// Guardamos en legajo[i] lo que previamente almacenamos en la variable num, finalmente guardamos en nombres[i] el valor que corresponde

        num = anios[pos]; /// Guardamos el valor de anios[pos] en la variable num, de esta forma guardamos el menor valor del array
        anios[pos] = anios[i]; /// Guardamos el valor de anios[i] en anios[pos], ahora nombres[pos] tiene almacenado lo que habia en nombres[i]
        anios[i] = num; /// Guardamos en anios[i] lo que previamente almacenamos en la variable num, finalmente guardamos en nombres[i] el valor que corresponde

        i++;
    }
}
