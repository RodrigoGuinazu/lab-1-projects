#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// 1. Hacer una función que cargue automáticamente un arreglo de 50 enteros en forma descendente. a[0] = 50, a[1] = 49 … a[49] = 1
// 2. Copiar los elementos pares del arreglo de la función 1 a un pila.
// 3. Determinar el menor elemento de la pila de la función 2. La pila debe quedar en el mismo orden. La función debe retornar dicho elemento.
// 4. Calcular el promedio de los elementos que se encuentran en el arreglo pero únicamente los que sean mayores a 20. Pensar bien.
// 5. Generar un segundo arreglo a partir del que se encuentra con números cargados pero que contenga el carácter correspondiente al código ASCII
// 7. Hacer una función main() que invoque a las funciones anteriores y demuestre el funcionamiento del programa.
// Para hacer esto, cree las variables que considere necesarias, cárguelas con datos e invoque las funciones como corresponde en cada caso.

void mostrarArray (int A[], int maximo);
void mostrarArrayChar (char A[], int maximo);
void cargarArreglo(int array[]);
void pilaPares(int array[], Pila * pares);
int menorElemento(Pila pares);
float promedioArray(int array[]);
void arrayAscii (int array[], char arrayChar[]);
int buscarElemento(char arrayChar[], char elemento);

int main()
{
    int array[50];
    Pila pares;
    inicpila(&pares);
    int menor;
    float promedio;
    char arrayChar[50];
    char elemento = '&';

    cargarArreglo(array);
    printf("\nEjercicio 1\n\n");
    mostrarArray(array, 50);

    printf("\n\nEjercicio 2\n\n");
    pilaPares(array, &pares);
    mostrar(&pares);

    printf("\n\nEjercicio 3\n\n");
    menor = menorElemento(pares);
    printf("\nEl menor elemento es: %i\n", menor);
    mostrar(&pares);

    printf("\n\nEjercicio 4\n\n");
    promedio = promedioArray(array);
    printf("\nEl promedio es: %.2f\n", promedio);

    arrayAscii(array, arrayChar);
    printf("\n\nEjercicio 5\n\n");
    mostrarArrayChar(arrayChar, 50);

    printf("\n\nEjercicio 6\n\n");
    int resultado = buscarElemento(arrayChar, elemento);
    if(resultado == 0){
        printf("\nNO se encontro el elemento en el array\n");
    }else{
        printf("\nSe encontro el elemento en el array!!\n");
    }

    return 0;
}

void mostrarArray (int A[], int maximo){
    int contador=0;
    printf("[");
    for(contador=0;contador<maximo;contador++){
        printf("%i, ", A[contador]);
    }
    printf("]");
}

void cargarArreglo(int array[]){
    int i = 0;
    int numero = 50;
    for(i=0; i<50; i++){
        array[i] = numero;
        numero--;
    }
}

void pilaPares(int array[], Pila * pares){
    inicpila(&*pares);
    for(int i=0; i<50; i++){
        if(array[i]%2 == 0){
            apilar(&*pares, array[i]);
        }
    }
}

int menorElemento(Pila pares){
    Pila aux;
    inicpila(&aux);
    int menor = tope(&pares);
    while(!pilavacia(&pares)){
        if(tope(&pares) < menor){
            apilar(&aux, menor);
            menor = tope(&pares);
        }else{
            apilar(&aux, desapilar(&pares));
        }
    }
    return menor;
}

float promedioArray(int array[]){
    float suma = 0;
    float contador = 0;
    float promedio = 0;
    for(int i=0; i<50; i++){
        if(array[i] > 20){
            suma = suma + array[i];
            contador++;
        }
    }
    promedio = suma/contador;
    return promedio;
}

void arrayAscii (int array[], char arrayChar[]){
    for(int i=0; i<50; i++){
        arrayChar[i] = array[i];
    }
}

void mostrarArrayChar (char A[], int maximo){
    int contador=0;
    printf("[");
    for(contador=0;contador<maximo;contador++){
        printf("%c ", A[contador]);
    }
    printf("]");
}

int buscarElemento(char arrayChar[], char elemento){
    int flag = 0;
    for(int i=0; i<50; i++){
        if(elemento == arrayChar[i]){
            flag = 1;
        }
    }
    return flag;
}
