#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// 1. Hacer una función que recorra una pila y determine si un elemento está dentro de ella. La función recibe retornar un 1 o un 0 según sea el resultado. La pila debe quedar igual al finalizar la función.
// 2. Hacer una función que agregue un nuevo elemento a una pila pero por la base, no arriba del tope. La función recibe como parámetro la pila y el valor.
// 3. Hacer una función que cargue una pila con muchos elementos (por la base, usando la función 2), pero la cantidad cargada no debe superar los 40 números. Además, esta función debe impedir cargar elementos repetidos, para esto debe usar la función del ejercicio 1. La función recibe como parámetro una pila vacía y debe pedir al usuario los valores.
// 4. Dado un arreglo (vacío) y dos pilas (ya cargadas), hacer una función que vaya sumando los topes de ambas pilas y ubique los resultados en las celdas del arreglo, comenzando por la posición cero en adelante. Tener en cuenta que las pilas pueden tener distinta cantidad de elementos y que el arreglo podría no tener la suficiente cantidad de celdas. Si una de las pilas se vacía antes que la otra, se debe continuar copiando en el arreglo el contenido de la que quedó con elementos. La función recibe como parámetros: el arreglo (aclarando su tamaño) y las dos pilas; y retorna la cantidad de elementos cargados en el arreglo.
// 5. Hacer una función que recorra el arreglo y lo muestre por pantalla todos los elementos distintos a un valor ingresado por el usuario (que se recibe por parámetro).
// 6. Hacer una función que cargue automáticamente un arreglo, con el siguiente criterio: en la posición cero se pone un cero, en la posición 1 se pone un uno y en las siguientes posiciones se pone la suma de las dos anteriores. El tamaño del arreglo es 15 y se debe cargar completo. Sugerencia: cargar primero el arreglo en papel y lápiz.

int buscarEnPila(Pila pila, int elemento);
Pila agregarABase(Pila pila, int elemento);
void cargarElementos(Pila * pila);
void agregarEnArreglo(Pila pila, Pila Pila1, int array[]);
void mostrarArray (int A[], int maximo);
void cargarArray(int array[]);

int main()
{
    Pila pila, pila1, pila2;
    inicpila(&pila);
    inicpila(&pila1);
    inicpila(&pila2);
    apilar(&pila, 4);
    apilar(&pila, 9);
    apilar(&pila, 1);
    apilar(&pila, 6);
    apilar(&pila1, 2);
    apilar(&pila1, 6);
    apilar(&pila1, 4);
    int elemento = 9;
    int array [4];
    int arrayCargado[15];

    printf("\nEjercicio 1\n");
    printf("\nEl elemento a buscar es: %i\n", elemento);
    mostrar(&pila);
    int resultado = buscarEnPila(pila, elemento);
    if(resultado == 1){
        printf("\nEl elemento se encuentra en la Pila\n");
    }else{
        printf("\nEl elemento NO se encuentra en la Pila\n");
    }

    printf("\nEjercicio 2\n");
    printf("\nEl elemento a agregar: %i\n", elemento);
    pila1 = agregarABase(pila1, elemento);
    mostrar(&pila1);

    printf("\nEjercicio 3\n");
    cargarElementos(&pila2);
    mostrar(&pila2);

    printf("\nEjercicio 4 y 5\n");
    agregarEnArreglo(pila, pila1, array);
    mostrar(&pila);
    mostrar(&pila1);
    mostrarArray(array, 4);

    printf("\nEjercicio 6\n");
    cargarArray(arrayCargado);
    mostrarArray(arrayCargado, 15);

    return 0;
}

int buscarEnPila(Pila pila, int elemento){
    Pila aux;
    inicpila(&aux);
    int flag = 0;
    while(!pilavacia(&pila) && flag == 0){
        if(tope(&pila)== elemento){
            flag = 1;
        }
        apilar(&aux, desapilar(&pila));
    }
    return flag;
}

Pila agregarABase(Pila pila, int elemento){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&pila)){
        apilar(&aux, desapilar(&pila));
    }
    if(pilavacia(&pila)){
        apilar(&pila, elemento);
        while(!pilavacia(&aux)){
            apilar(&pila, desapilar(&aux));
        }
    }
    return pila;
}

void cargarElementos(Pila * pila){
    int elemento = 0;
    int flag = 0;
    int i = 0;
    while(i<4){
        printf("\nCargar un Elemento a la Pila\n");
        scanf("%i", &elemento);
        flag = buscarEnPila(*pila, elemento);
        if(flag == 0){
            *pila = agregarABase(*pila, elemento);
            i++;
        }else{
            printf("\nUps! ese numero ya se encuentra en la Pila\n");
        }

    }
}

void agregarEnArreglo(Pila pila, Pila pila1, int array[]){
    Pila aux;
    inicpila(&aux);
    int sumaTopes = 0;
    int i = 0;
    while(!pilavacia(&pila) && !pilavacia(&pila1)){
        sumaTopes = tope(&pila) + tope(&pila1);
        apilar(&aux, desapilar(&pila));
        apilar(&aux, desapilar(&pila1));
        array[i] = sumaTopes;
        i++;
    }
}

void mostrarArray(int A[], int maximo){
    int i = 0;
    printf("[");
    for(i = 0; i<maximo; i++){
        printf("%i, ", A[i]);
    }
    printf("]");
}

void cargarArray(int array[]){
    int i = 0;
    for(i=0; i<15; i++){
        if(i == 0){
            array[i] = 0;
        }else if( i == 1){
            array[i] = 1;
        }else {
            array[i] = array[i-1] + array[i-2];
        }
    }
}
