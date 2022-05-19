#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// 1. Hacer una funci�n que recorra una pila y determine si un elemento est� dentro de ella. La funci�n recibe retornar un 1 o un 0 seg�n sea el resultado. La pila debe quedar igual al finalizar la funci�n.
// 2. Hacer una funci�n que agregue un nuevo elemento a una pila pero por la base, no arriba del tope. La funci�n recibe como par�metro la pila y el valor.
// 3. Hacer una funci�n que cargue una pila con muchos elementos (por la base, usando la funci�n 2), pero la cantidad cargada no debe superar los 40 n�meros. Adem�s, esta funci�n debe impedir cargar elementos repetidos, para esto debe usar la funci�n del ejercicio 1. La funci�n recibe como par�metro una pila vac�a y debe pedir al usuario los valores.
// 4. Dado un arreglo (vac�o) y dos pilas (ya cargadas), hacer una funci�n que vaya sumando los topes de ambas pilas y ubique los resultados en las celdas del arreglo, comenzando por la posici�n cero en adelante. Tener en cuenta que las pilas pueden tener distinta cantidad de elementos y que el arreglo podr�a no tener la suficiente cantidad de celdas. Si una de las pilas se vac�a antes que la otra, se debe continuar copiando en el arreglo el contenido de la que qued� con elementos. La funci�n recibe como par�metros: el arreglo (aclarando su tama�o) y las dos pilas; y retorna la cantidad de elementos cargados en el arreglo.
// 5. Hacer una funci�n que recorra el arreglo y lo muestre por pantalla todos los elementos distintos a un valor ingresado por el usuario (que se recibe por par�metro).
// 6. Hacer una funci�n que cargue autom�ticamente un arreglo, con el siguiente criterio: en la posici�n cero se pone un cero, en la posici�n 1 se pone un uno y en las siguientes posiciones se pone la suma de las dos anteriores. El tama�o del arreglo es 15 y se debe cargar completo. Sugerencia: cargar primero el arreglo en papel y l�piz.

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
