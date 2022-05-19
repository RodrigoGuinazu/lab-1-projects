#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


// 1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.

// 2. Hacer una función que pase todos los elementos de una pila a otra.

// 3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.

// 4. Hacer una función que encuentre el menor elemento de una pila y lo retorne. La misma debe eliminar ese dato de la pila.

// 5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)

// 6. Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el orden de ésta.

// 7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)

// 8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar su contenido.

// 9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.

// 10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal.

Pila cargarPila(Pila pila1);
Pila pasarPila(Pila pila2, Pila pila3);
Pila pasarPilaOrdenada(Pila pila4, Pila pila5, Pila pila6);
Pila menorPila(Pila pila7, Pila menor, Pila pila8);
Pila ordenarPila(Pila pila9, Pila menor2, Pila pila10, Pila ordenada);
void insertarEnPila(Pila * pila11, int nuevoElemento);
void insertarEnOrdenada(Pila * pila12, Pila * ordenada2);
int sumarTopes(Pila pila13, Pila aux3);
float promedio(Pila pila14, Pila aux4);
float sumaElementos(Pila pila14, Pila aux4);
float cantidadDeElementos(Pila pila14, Pila aux4);
float dividirElementos(float total, float contador);
int construirNumero (Pila*dada);

int main(){

    char control = 's';
    int option;

    while(control == 's'){
        printf("TP-4 FUNCIONES CON PILAS\n");
        printf("-----------------------------------------\n\n");
        printf("Oprima el numero del ejercicio que desea ver\n\n");
        printf("1 - Ejercicio 1\n");
        printf("2 - Ejercicio 2\n");
        printf("3 - Ejercicio 3\n\n");
        printf("4 - Ejercicio 4\n");
        printf("5 - Ejercicio 5\n");
        printf("6 - Ejercicio 6\n");
        printf("7 - Ejercicio 7\n");
        printf("8 - Ejercicio 8\n\n");
        printf("9 - Ejercicio 9\n");
        printf("10 - Ejercicio 10\n\n");

        fflush(stdin);
        scanf("%i", &option);
        system("cls;");

        switch(option){
        case 1: ;  // Para evitar problemas en la ejecucion agregar un ; despues de cada case!
            Pila pila1;
            inicpila(&pila1);
            pila1 = cargarPila(pila1);
            printf("\nPILA 1\n");
            mostrar(&pila1);

            system("Pause");
            system("cls");
            break;

        case 2: ;
            Pila pila2, pila3;

            inicpila(&pila2);
            inicpila(&pila3);

            apilar(&pila2, 4);
            apilar(&pila2, 8);
            apilar(&pila2, 2);
            apilar(&pila2, 9);

            pila3 = pasarPila(pila2, pila3);
            printf("\nPILA 3\n");
            mostrar(&pila3);

            system("Pause");
            system("cls");
            break;

        case 3: ;
            Pila pila4, pila5, pila6;

            inicpila(&pila4);
            inicpila(&pila5);
            inicpila(&pila6);

            apilar(&pila4, 4);
            apilar(&pila4, 8);
            apilar(&pila4, 2);
            apilar(&pila4, 9);

            pila6 = pasarPilaOrdenada(pila4, pila5, pila6);
            printf("\nPILA 6\n");
            mostrar(&pila6);

            system("Pause");
            system("cls");
            break;

        case 4: ;
            Pila pila7, menor, pila8;

            inicpila(&pila7);
            inicpila(&menor);
            inicpila(&pila8);

            apilar(&pila7, 7);
            apilar(&pila7, 11);
            apilar(&pila7, 2);
            apilar(&pila7, 5);

            printf("PILA 7 CON EL MENOR");
            mostrar(&pila7);

            pila7 = menorPila(pila7, menor, pila8);
            printf("PILA 7 SIN EL MENOR");
            mostrar(&pila7);

            system("Pause");
            system("cls");
            break;

        case 5: ;
            Pila pila9, menor2, pila10, ordenada;
            inicpila(&pila9);
            inicpila(&menor2);
            inicpila(&pila10);
            inicpila(&ordenada);

            apilar(&pila9, 9);
            apilar(&pila9, 3);
            apilar(&pila9, 15);
            apilar(&pila9, 2);
            apilar(&pila9, 542);

            ordenada = ordenarPila(pila9, menor2, pila10, ordenada);
            printf("\nPILA ORDENADA\n");
            mostrar(&ordenada);

            system("Pause");
            system("cls");
            break;

        case 6: ;
            Pila pila11;
            inicpila(&pila11);
            apilar(&pila11, 3);
            apilar(&pila11, 7);
            apilar(&pila11, 8);
            apilar(&pila11, 14);
            apilar(&pila11, 24);

            int nuevoElemento = 4;

            insertarEnPila(&pila11, nuevoElemento);
            printf("\nPILA 11\n");
            mostrar(&pila11);

            system("Pause");
            system("cls");
            break;

        case 7: ;
            Pila pila12, ordenada2;
            inicpila(&pila12);
            inicpila(&ordenada2);

            apilar(&pila12, 8);
            apilar(&pila12, 3);
            apilar(&pila12, 6);
            apilar(&pila12, 1);
            apilar(&pila12, 15);

            insertarEnOrdenada(&pila12, &ordenada2);
            printf("\nPILA ORDENADA 2\n");
            mostrar(&ordenada2);

            system("Pause");
            system("cls");
            break;

        case 8: ;
            Pila pila13, aux3;
            inicpila(&pila13);
            inicpila(&aux3);

            apilar(&pila13, 6);
            apilar(&pila13, 1);
            apilar(&pila13, 29);

            int suma = sumarTopes(pila13, aux3);
            printf("\nLa suma da: %i\n", suma);

            system("Pause");
            system("cls");
            break;

        case 9: ;
            Pila pila14, aux4;
            inicpila(&pila14);
            inicpila(&aux4);

            apilar(&pila14, 14);
            apilar(&pila14, 27);
            apilar(&pila14, 8);

            float resultadoFinal = promedio(pila14, aux4);
            printf("\nEl promedio de los elementos de la PILA 14 es: %.2f\n", resultadoFinal);

            system("Pause");
            system("cls");
            break;

        case 10: ;
            Pila dada;
            inicpila(&dada);
            int resultado=0;

            leer(&dada);
            leer(&dada);
            leer(&dada);

            resultado= construirNumero(&dada);

            printf("El numero es %d \n", resultado);

            system("Pause");
            system("cls");
            break;

        default:
            printf("Elegiste una opcion incorrecta");
        }

        printf("Desea ver otro ejercicio? oprima s para continuar o cualquier otra tecla para terminar");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");

    }

    printf("Gracias por ver el tp-4 funciones con pilas de Rodrigo Guinazu");

    return 0;

}

Pila cargarPila(Pila pila1){
    inicpila(&pila1);
    char control = 's';

    while(control == 's'){
        leer(&pila1);

        printf("Desea cargar otro dato en la Pila?");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
    return pila1;
}

Pila pasarPila(Pila pila2, Pila pila3){

    while(!pilavacia(&pila2)){
        apilar(&pila3, desapilar(&pila2));
    }
    return pila3;
}

Pila pasarPilaOrdenada(Pila pila4, Pila pila5, Pila pila6){

    while(!pilavacia(&pila4)){
        apilar(&pila5, desapilar(&pila4));
    }
    while(!pilavacia(&pila5)){
        apilar(&pila6, desapilar(&pila5));
    }
    return pila6;
}

Pila menorPila(Pila pila7, Pila menor, Pila pila8){
    apilar(&menor, desapilar(&pila7));
    while(!pilavacia(&pila7)){
        if(tope(&pila7) > tope(&menor)){
            apilar(&pila8, desapilar(&pila7));
        }else {
            apilar(&pila8, desapilar(&menor));
            apilar(&menor, desapilar(&pila7));
        }
    }
    if(pilavacia(&pila7)){
        while(!pilavacia(&pila8)){
            apilar(&pila7, desapilar(&pila8));
        }
    }
    return pila7;
}

Pila ordenarPila(Pila pila9, Pila menor2, Pila pila10, Pila ordenada){
    while(!pilavacia(&pila9)){
        apilar(&menor2, desapilar(&pila9));
        while(!pilavacia(&pila9)){
            if(tope(&pila9) > tope(&menor2)){
                apilar(&pila10, desapilar(&pila9));
            }else {
                apilar(&pila10, desapilar(&menor2));
                apilar(&menor2, desapilar(&pila9));
            }
        }
        if(pilavacia(&pila9)){
            apilar(&ordenada, desapilar(&menor2));
            while(!pilavacia(&pila10)){
                apilar(&pila9, desapilar(&pila10));
            }
        }
    }
    return ordenada;
}

void insertarEnPila(Pila * pila11, int nuevoElemento){

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&*pila11) && tope(&*pila11) > nuevoElemento){
        apilar(&aux, desapilar(&*pila11));
    }

    apilar(&*pila11, nuevoElemento);

    while(!pilavacia(&aux)){
        apilar(&*pila11, desapilar(&aux));
    }

}

void insertarEnOrdenada(Pila * pila12, Pila * ordenada2){
    while(!pilavacia(&*pila12)){
        insertarEnPila(&*ordenada2, desapilar(&*pila12));
    }
}

int sumarTopes(Pila pila13, Pila aux3){
    int copia1 = tope(&pila13);
    apilar(&aux3, desapilar(&pila13));
    int copia2 = tope(&pila13);
    apilar(&pila13, desapilar(&aux3));

    int suma = copia1 + copia2;

    return suma;
}

float promedio(Pila pila14, Pila aux4){
    float total, contador, resultadoFinal = 0;
    total = sumaElementos(pila14, aux4);
    contador = cantidadDeElementos(pila14, aux4);
    resultadoFinal = dividirElementos(total, contador);

    return resultadoFinal;
}

float sumaElementos(Pila pila14, Pila aux4){
    float total = 0;
    while(!pilavacia(&pila14)){
        total = total + tope(&pila14);
        apilar(&aux4, desapilar(&pila14));
    }
    if(pilavacia(&pila14)){
        while(!pilavacia(&aux4)){
            apilar(&pila14, desapilar(&aux4));
        }
    }
    return total;
}

float cantidadDeElementos(Pila pila14, Pila aux4){
    float contador = 0;
    while(!pilavacia(&pila14)){
        apilar(&aux4, desapilar(&pila14));
        contador++;
    }
    if(pilavacia(&pila14)){
        while(!pilavacia(&aux4)){
            apilar(&pila14, desapilar(&aux4));
        }
    }
    return contador;
}

float dividirElementos(float total, float contador){
    float resultado = total / contador;
    return resultado;
}

int construirNumero (Pila*dada){
    Pila aux;
    inicpila(&aux);
    int potencia = 1;
    int contadorFinal = 0;

    while(!pilavacia(dada)){
        contadorFinal = contadorFinal + (tope(dada) * potencia);
        potencia = (potencia * 10); // Potencia => 1, 10, 100, 1000
        apilar(&aux, desapilar(dada));
    }

    return contadorFinal;
}
