#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// 1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).

int cargarElementos (int A[], int dimension);

int main()
{
    int Arreglo[20];
    int dimension=20;
    int cantElementos=0;

    cantElementos=cargarElementos(Arreglo, dimension);
    printf("Hay %i elementos en el array", cantElementos);

    return 0;
}

int cargarElementos (int A[], int dimension){

    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        scanf("%i", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}

// 2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.

int cargarElementos (int A[], int dimension);
void mostrarArreglo (int A[], int maximo);

int main()
{
    int Arreglo[20];
    int dimension=20;
    int cantElementos=0;

    cantElementos=cargarElementos(Arreglo, dimension);
    mostrarArreglo(Arreglo, cantElementos);

    return 0;
}

int cargarElementos (int A[], int dimension){

    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        scanf("%i", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}

void mostrarArreglo (int A[], int maximo){

    int contador=0;
    printf("[");
    for(contador=0;contador<maximo;contador++){
        printf("%i, ", A[contador]);
    }
    printf("]");
}

// 3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.

int cargarElementos (int A[], int dimension);
void mostrarArreglo (int A[], int maximo);
int sumarElementos (int A[], int maximo);

int main()
{
    int Arreglo[20];
    int dimension=20;
    int cantElementos=0;
    int suma = 0;

    cantElementos=cargarElementos(Arreglo, dimension);
    mostrarArreglo(Arreglo, cantElementos);
    suma = sumarElementos(Arreglo, cantElementos);
    printf("\nLa suma de los elementos es: %d\n", suma);


    return 0;
}

int cargarElementos (int A[], int dimension){

    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        scanf("%i", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}

void mostrarArreglo (int A[], int maximo){

    int contador=0;
    printf("[");
    for(contador=0;contador<maximo;contador++){
        printf("%i, ", A[contador]);
    }
    printf("]");
}

int sumarElementos (int A[], int maximo){
    int suma = 0;
    for(int i=0; i < maximo; i++){
        suma += A[i];
    }
    return suma;
}

// 4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.

int cargarElementos (int A[], int dimension);
Pila copiarPila(int Array[], int maximo, Pila *pila1);

int main(){
    Pila pila1;
    inicpila(&pila1);
    int Arreglo[20];
    int dimension=20;
    int cantElementos=0;

    cantElementos=cargarElementos(Arreglo, dimension);
    copiarPila(Arreglo, cantElementos, &pila1);
    printf("\nPILA 1\n");
    mostrar(&pila1);

    return 0;
}

int cargarElementos (int A[], int dimension){

    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        scanf("%i", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}

Pila copiarPila(int Array[], int maximo, Pila *pila1){
    for(int i=0; i < maximo; i++){
        apilar(&*pila1, Array[i]);
    }
}

// 5. Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)

int cargarElementos (int A[], int dimension);
float sumarElementos (int A[], int maximo);

int main()
{
    int Arreglo[100];
    int dimension=100;
    int cantElementos=0;
    float suma = 0;

    cantElementos=cargarElementos(Arreglo, dimension);
    suma = sumarElementos(Arreglo, cantElementos);
    printf("\nLa suma de los elementos es: %f\n", suma);


    return 0;
}

int cargarElementos (int A[], int dimension){
    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        scanf("%i", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}


float sumarElementos (int A[], int maximo){
    float suma = 0;
    for(int i=0; i < maximo; i++){
        suma += A[i];
    }
    return suma;
}

// 6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.

int cargarElementos (char A[], int dimension);
int buscarElemento(char A[], int maximo, char elemento);

int main(){
    char Arreglo[20];
    int dimension=20;
    int cantElementos=0;
    char elemento = 'z';
    int flag = 0;

    cantElementos=cargarElementos(Arreglo, dimension);
    flag = buscarElemento(Arreglo, cantElementos, elemento);
    if(flag != 0){
        printf("\nEncontre el Elemento en el Array en la Posicion %i\n", flag);
    }else {
        printf("\nEl Elemento NO se encuentra en el Array\n");
    }

    return 0;
}

int cargarElementos (char A[], int dimension){
    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        fflush(stdin);
        scanf("%c", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}

int buscarElemento(char A[], int maximo, char elemento){
    int flag = 0;
    int i =0;
    while(i<maximo && flag == 0){
        if(A[i] == elemento){
            flag = i;
        }
        i++;
    }
   return flag;
}

// 7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.

int posicionElemento(char Abc[], int dimension, int elemento);
void insertarElemento(char AbcIncompleto[], int posicion, char elemento, int dimension);

int main(){
    char Abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char AbcIncompleto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'w', 'x', 'y', 'z'};
    char elemento = 'v';
    int dimension = 26;
    int posicion = 0;

    posicion = posicionElemento(Abc, dimension, elemento);
    insertarElemento(AbcIncompleto, posicion, elemento, dimension);

    return 0;
}

int posicionElemento(char Abc[], int dimension, int elemento){
    int posicion = 0;
    for(int i=0; i < dimension; i++){
        if(Abc[i] == elemento){
            posicion = i;
        }
    }
    return posicion;
}

void insertarElemento(char AbcIncompleto[], int posicion, char elemento, int dimension){

    for(int i=dimension ; i >= posicion; i--){
        AbcIncompleto[i+1] = AbcIncompleto[i];
    }
    AbcIncompleto[posicion] = elemento;

    printf("[");
    for(int j = 0; j < dimension; j++){
        printf("%c, ", AbcIncompleto[j]);
    }
    printf("]");
}

// 8. Realizar una función que obtenga el máximo carácter de un arreglo dado.

char maximoCaracter(char letras[], int dimension);

int main(){
    char letras[26] = {'h', 'k', 'z', 'a', 'p', 'o'};
    int dimension = 26;
    char caracter;

    caracter = maximoCaracter(letras, dimension);
    printf("\nEl caracter maximo es: %c\n", caracter);

    return 0;
}

char maximoCaracter(char letras[], int dimension){
    char caracter;
    int maximo = letras[0];
    for(int i=0; i < dimension; i++){
        if(letras[i] > maximo){
            maximo = letras[i];
            caracter = letras[i];
        }
    }
    return caracter;
}

// 9. Realizar una función que determine si un arreglo es capicúa.

int cargarElementos (int A[], int dimension);
int capicua(int array[], int dimension);

int main(){
    int array[20];
    int dimension = 20;
    int contador = 0;
    int flag = 0;

    contador = cargarElementos(array, dimension);
    flag = capicua(array, contador);
    if(flag != 0){
        printf("\nEl Array NO es Capicua!\n");
    }else {
        printf("\nEl Array es Capicua!\n");
    }

    return 0;
}

int cargarElementos (int A[], int dimension){

    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        scanf("%i", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}

int capicua(int array[], int dimension){
    int flag = 0;
    int j = (dimension-1);
    int i = 0;

    while(i < (dimension/2) && flag == 0){
        if(array[i] != array[j]){
            flag = 1;
        }
        i++;
        j--;
    }
    return flag;
}

// 10. Realizar una función que invierta los elementos de un arreglo.

int cargarElementos (int A[], int dimension);
void invertirArray(int array[], int dimension);

int main(){
    int array[20];
    int dimension = 20;
    int contador = 0;

    contador = cargarElementos(array, dimension);
    invertirArray(array, contador);


    return 0;
}

int cargarElementos (int A[], int dimension){

    char control= 's';
    int contador=0;

    while(control=='s'  && (contador < dimension)){
        printf("Ingrese un valor: \n");
        scanf("%i", &A[contador]);
        contador++;
        printf("desea seguir agregando elementos \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return contador;
}

void invertirArray(int array[], int dimension){
    int i = 0;
    int j = (dimension - 1); // Arranca una posicion menos ya que el anterior es basura

    while(i < (dimension/2)){ // Dimension/2 para que recorra la mitad del array, ya que se esta recorriendo al mismo tiempo por i(izq a der) y j(der a izq)
        int burbuja = array[i]; // Se pasa el dato de la primera posicion (i) del array a la burbuja
        array[i] = array[j]; // Se pasa el dato de la ultima posicion (j) a la primera posicion (i)
        array[j] = burbuja; // Se pasa el dato que habia quedado en burbuja hacia la ultima posicion del array (j)
        i++;
        j--;
    }

    printf("[");
    for(int f = 0; f < dimension; f++){
        printf("%i, ", array[f]);
    }
    printf("]");
}
