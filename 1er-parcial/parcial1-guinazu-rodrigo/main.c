#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/// 1. Funciones de Carga de Datos (funciones auxiliares)
// I. Función “Cargar Arreglo”: Carga todas las notas de alumnos que cursan la materia por 1ra vez en el arreglo “ingresantes”
// II. Función “Cargar Pila”: Carga todas las notas de alumnos que recursan lamateria en la pila “recursantes”
// III. En ambos casos deberá validarse que el ingreso de datos sea del valorCORRECTO (es decir: que los valores de las notas se encuentren entre 1 y10). Esto se hará mediante una función auxiliar que se encargue de lavalidación y sea llamada desde las funciones de carga

/// 2. Función Controladora “CargarNotas” (función principal): Esta función deberá llamar a las 2 funciones del punto “1”.
// I. Tendrá como parámetros: Puntero a una Pila, Arreglo y Dimensión.
// II. La función tiene que solicitarle al usuario: 1ro qué tipo nota desea ingresar al sistema (si de un recursante o se un ingresante), y 2do que ingrese la nota.
// III. De acuerdo a si la nota es de un recursante o de un ingresante, la función controladora llamará a la función auxiliar de cargar pila o a la de cargar arreglo.
// IV. Esta función debe retornar la cantidad de validos del arreglo.
// V. Esta función controladora es la que vamos a invocar desde el main()

/// 3. Funciones de Gestión de datos
// I. Contar cuántos aprobados y cuántos desaprobados hay en el arreglo de ingresantes (se aprueba con 6). (10 puntos)
// II. Buscar si una nota específica ENVIADA POR PARÁMETRO está guardada o no en la pila de recursantes (por ej, el docente quiere saber si entre los recursantes hay alguno que se haya sacado un 10).(12 puntos)
// III. Crear un arreglo llamado “comision7” y pasar al mismo todas las notas del arreglo “ingresantes” y todas las notas de la pila “recursantes” (10 puntos)
// IV. Sumar todas las notas guardadas en el arreglo “comision7” y retornar dicho total (La función debe recorrer el arreglo al revés). (13 puntos)

/// 4. EN EL MAIN DEBO LLAMAR A TODAS LAS FUNCIONES (de forma directa o indirecta). Ponderar que el programa compile correctamente. (15 puntos, de los cuales 5 corresponden a la correcta compilación del programa)

///1
int cargarArray (int ingresantes[], int dimension);
void cargarPila(Pila * recursantes, int dimension);
int validarNota(int elemento);
void mostrarArray (int A[], int maximo);

///2
void cargarNotas (Pila * recursantes, int ingresantes[], int dimension);

///3
void aprobadosDesaprobados(Pila recursantes, int ingresantes[], int validos, int * aprobados, int * desaprobados);
int apruebaDesaprueba(int elemento);
int buscarNota(Pila recursantes, int elemento);
void pasarComision(int comision7[], int ingresantes[], Pila recursantes);
int sumaNotas(int comision7[]);

int main()
{

    Pila recursantes;
    inicpila(&recursantes);
    int ingresantes[5];
    int dimension = 5;
    int validos = 0;
    int aprobados = 0;
    int desaprobados = 0;
    int elementoABuscar = 7;
    int comision7[10];
    int suma = 0;

    /*
    printf("\nEjercicio 1 - I\n");
    validos = cargarArray(ingresantes, dimension);
    mostrarArray(ingresantes, validos);

    printf("\nEjercicio 1 - II\n");
    cargarPila(&recursantes, dimension);
    mostrar(&recursantes);

    printf("\nEjercicio 1 - III\n");
    */

    printf("\nEjercicio 2\n");
    cargarNotas(&recursantes, ingresantes, dimension);

    printf("\nEjercicio 3 - I\n");
    //aprobadosDesaprobados(recursantes, ingresantes, validos, aprobados, desaprobados);
    //printf("Hay %i Aprobados y %i Desaprobados", aprobados, desaprobados);
    printf("\nEjercicio 3 - III\n");
    pasarComision(comision7, ingresantes, recursantes);
    printf("\nEjercicio 3 - IV\n");
    suma = sumaNotas(comision7);
    printf("La suma de las notas es: %i", suma);
    printf("\nEjercicio 3 - II\n");
    int encontre = buscarNota(recursantes, elementoABuscar);
    if(encontre == 1){
        printf("\nEncontre el elemento\n");
    }else{
        printf("\nNO Encontre el elemento\n");
    }

    return 0;
}

/// EJERCICIO 3
int sumaNotas(int comision7[]){
    int suma = 0;
    for(int i=0; i<10; i++){
        suma = suma + comision7[i];
    }
    return suma;
}

void pasarComision(int comision7[], int ingresantes[], Pila recursantes){
    Pila aux;
    inicpila(&aux);
    int i = 0;

    while(!pilavacia(&recursantes)){
        comision7[i] = tope(&recursantes);
        apilar(&aux, desapilar(&recursantes));
        i++;
    }

    for(int j=0; j<5; j++){
        comision7[i] = ingresantes[j];
        i++;
    }
}

int buscarNota(Pila recursantes, int elemento){
    Pila aux;
    inicpila(&aux);
    int flag = 0;
    while(!pilavacia(&recursantes)){
        if(tope(&recursantes) == elemento){
            flag = 1;
        }else{
            flag = 0;
        }
    }
    return flag;
}

void aprobadosDesaprobados(Pila recursantes, int ingresantes[], int validos, int * aprobados, int * desaprobados){
    Pila aux;
    int flag = 0;
    inicpila(&aux);
    while(!pilavacia(&recursantes)){
        flag = apruebaDesaprueba(tope(&recursantes));
        if(flag == 0){
            *aprobados++;
            apilar(&aux, desapilar(&recursantes));
        }else{
            *desaprobados++;
            apilar(&aux, desapilar(&recursantes));
        }
    }
    for(int i =0; i<validos; i++){
        flag = apruebaDesaprueba(ingresantes[i]);
        if(flag == 0){
            *aprobados++;
            apilar(&aux, desapilar(&recursantes));
        }else{
            *desaprobados++;
            apilar(&aux, desapilar(&recursantes));
        }
    }
}

int apruebaDesaprueba(int elemento){
    int flag = 0;
    if(elemento >= 6){
        flag = 0;
    }else {
        flag = 1;
    }
    return flag;
}

/// FUNCIONES EJERCICIO 2

void cargarNotas (Pila * recursantes, int ingresantes[], int dimension){
    int opcion = 0;
    char control = 's';
    int validos = 0;

    while(control == 's'){
        printf("\nOprima 1 para cargar notas de Ingresantes o 2 para cargar Notas de recursantes\n");
        scanf("%i", &opcion);
        if(opcion == 1){
            printf("\nCARGANDO NOTAS DE INGRESANTES\n");
            validos = cargarArray(ingresantes, dimension);
            printf("\nCargaste %i Notas\n\n", validos);
            mostrarArray(ingresantes, validos);
        }else if(opcion == 2){
            printf("\nCARGANDO NOTAS DE RECURSANTES\n");
            cargarPila(&*recursantes, dimension);
            mostrar(&*recursantes);
        }else{
            printf("\nDebes presionar 1 para Ingresantes o 2 para Recursantes\n");
        }
        printf("\nDesea cargar mas notas?\n");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
}

/// FUNCIONES EJERCICIO 1

int cargarArray (int ingresantes[], int dimension){
    char control = 's';
    int contador=0;
    int flag = 0;

    while(control == 's' && contador < dimension){
        printf("Ingrese una nota: ");
        scanf("%i", &ingresantes[contador]);
        flag = validarNota(ingresantes[contador]);
        if(flag == 0){
            contador++;
        }else {
            printf("\nDebes ingresar una nota entre 1 y 10\n");
        }
        printf("Desea cargar otra nota en el Array?");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
    return contador;
}

void cargarPila(Pila * recursantes, int dimension){
    Pila aux;
    inicpila(&aux);
    char control = 's';
    int flag = 0;
    int contador = 0;

    while(control == 's' && contador < dimension){
        leer(&aux);
        flag = validarNota(tope(&aux));
        if(flag == 0){
            apilar(&*recursantes, desapilar(&aux));
            contador++;
        }else {
            printf("\nDebes ingresar una nota entre 1 y 10\n");
        }
        printf("Desea cargar otra nota en la Pila?");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
}

int validarNota(int elemento){
    int flag = 0;
    if(elemento > 0 && elemento < 11){
        flag = 0;
    }else{
        flag = 1;
    }
    return flag;
}

void mostrarArray (int A[], int maximo){
    int contador = 0;
    printf("[");
    for(contador=0; contador<maximo; contador++){
        printf("%i, ", A[contador]);
    }
    printf("]");
}
