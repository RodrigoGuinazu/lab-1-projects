#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(){
    int a = 25;
    int b=18 ;
    int *c;

    b=a;
    c=&b;
    a= *c;

    printf("%i", c);
    return 0;
}

/*
// 1. Sumar los elementos de una pila (usar variables)

int main()
{
    int suma = 0;
    Pila a, aux;
    inicpila(&a);
    inicpila(&aux);
    printf("\nPila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    while(!pilavacia(&a)){
        suma = suma + tope(&a);
        apilar(&aux, desapilar(&a));
    }
    printf("\nLa suma de los elementos de la pila es: %d", suma);
    return 0;
}

// 2. Contar los elementos de una pila (usar variables)

int main()
{
    int acumulador = 0;
    Pila a, aux;
    inicpila(&a);
    inicpila(&aux);
    printf("\nPila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    while(!pilavacia(&a)){
        apilar(&aux, desapilar(&a));
        acumulador++;
    }
    printf("\nHay %i elementos en la Pila A", acumulador);
    return 0;
}

// 3. Calcular el promedio de los valores de una pila (usar variables)

int main()
{
    float suma = 0;
    float acumulador = 0;
    float promedio = 0;
    Pila a, aux;
    inicpila(&a);
    inicpila(&aux);
    printf("\nPila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    while(!pilavacia(&a)){
        suma = suma + tope(&a);
        apilar(&aux, desapilar(&a));
        acumulador++;
    }
    promedio = suma/acumulador;
    printf("\nHay %.0f elementos en la Pila A. La suma de de sus elementos es %.0f, y el promedio es %.2f", acumulador, suma, promedio);
    return 0;
}

// 4. Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)

int main()
{
    Pila a, aux, menor;
    inicpila(&a);
    inicpila(&aux);
    inicpila(&menor);
    printf("\nPila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    apilar(&menor, desapilar(&a));
    while(!pilavacia(&a)){
        if(tope(&a)>tope(&menor)){
            apilar(&aux, desapilar(&a));
        }else {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&a));
        }
    }
    printf("El menor elemento de la Pila A es: %i", tope(&menor));
    return 0;
}

// 5. Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables, solo pilas)

int main()
{
    Pila a, aux, elemento;
    inicpila(&a);
    inicpila(&aux);
    inicpila(&elemento);
    apilar(&a, 6);
    apilar(&a, 5);
    apilar(&a, 4);
    apilar(&a, 3);
    apilar(&a, 1);
    apilar(&elemento, 2);
    printf("\nPila A: \n");
    mostrar(&a);
    printf("\nElemento: \n");
    mostrar(&elemento);
    while(!pilavacia(&elemento)){
        if(tope(&a)<tope(&elemento)){
            apilar(&aux, desapilar(&a));
        }else {
            apilar(&aux, desapilar(&elemento));
        }
    }
    while(!pilavacia(&aux)){
        apilar(&a, desapilar(&aux));
    }
    printf("\nPila A: \n");
    mostrar(&a);
    return 0;
}

// 6. Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.

int main()
{
    Pila a, aux, menor, ordenada;
    inicpila(&a);
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);
    printf("\nPila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    while(!pilavacia(&a)){
        apilar(&menor, desapilar(&a));
        while(!pilavacia(&a)){
            if(tope(&a)>tope(&menor)){
                apilar(&aux, desapilar(&a));
            }else {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&a));
            }
        }
        apilar(&ordenada, desapilar(&menor));
        while(!pilavacia(&aux)){
            apilar(&a, desapilar(&aux));
        }
    }
    printf("\nPila ORDENADA\n");
    mostrar(&ordenada);
    return 0;
}

// 7. Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.
int main()
{
    int flag = 0;
    Pila a, aux, igual;
    inicpila(&a);
    inicpila(&aux);
    inicpila(&igual);
    printf("\nPila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    printf("\nElemento: \n");
    leer(&igual);
    while(!pilavacia(&a) && flag == 0){
        if(tope(&a) != tope(&igual)){
            apilar(&aux, desapilar(&a));
        }else {
            flag = 1;
        }
    }
    while(!pilavacia(&aux)){
        apilar(&a, desapilar(&aux));
    }
    if(flag == 1){
        printf("\nEl elemento se encuentra en la Pila A\n");
    }else{
        printf("\nEl elemento NO se encuentra en la Pila A\n");
    }
    printf("\n\nPila A: \n");
    mostrar(&a);
    return 0;
}

// 8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.
int main()
{
    int flag = 0;
    Pila a, aux, igual;
    inicpila(&a);
    inicpila(&aux);
    inicpila(&igual);
    printf("\nPila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    printf("\nElemento: \n");
    leer(&igual);
    while(!pilavacia(&a) && !pilavacia(&igual)){
        if(tope(&a) != tope(&igual)){
            apilar(&aux, desapilar(&a));
        }else {
            apilar(&igual, desapilar(&a));
            flag = 1;
        }
    }
    while(!pilavacia(&aux)){
        apilar(&a, desapilar(&aux));
    }
    if(flag == 1){
        printf("El elemento se encuentra en la Pila A");
    }else{
        printf("El elemento NO se encuentra en la Pila A");
    }
    printf("\n\nPila A: \n");
    mostrar(&a);
    return 0;
}

// 9. Verificar si una pila DADA es capicúa.
int main()
{
    int control = 0;
    Pila dada, aux, copia;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&copia);
    printf("\nPila DADA\n");
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    while(!pilavacia(&dada)){
        control = tope(&dada);
        apilar(&copia, control);
        apilar(&aux, desapilar(&dada));
    }
    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }
    while(!pilavacia(&dada) && !pilavacia(&copia) && tope(&copia) == tope(&dada)){
        desapilar(&copia);
        desapilar(&dada);
    }
    if(pilavacia(&copia) && pilavacia(&dada)){
        printf("\n\nEs Capicua!\n\n");
    }else {
        printf("\n\nNO es Capicua\n\n");
    }
    return 0;
}


// 10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.

int main()
{
    Pila a, b, c;
    inicpila(&a);
    inicpila(&b);
    inicpila(&c);
    printf("\nCargar Pila A\n");
    leer(&a);
    leer(&a);
    leer(&a);
    leer(&a);
    printf("\nCARGAR Pila B\n");
    leer(&b);
    leer(&b);
    leer(&b);
    leer(&b);
    while(!pilavacia(&a) && !pilavacia(&b)){
        apilar(&c, desapilar(&a));
        apilar(&c, desapilar(&b));
    }
    printf("\nPila C\n");
    mostrar(&c);
    return 0;
}

// 11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).

int main()
{
    Pila ordenada1, ordenada2, ordenadaFinal;
    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&ordenadaFinal);
    apilar(&ordenada1, 9);
    apilar(&ordenada1, 21);
    apilar(&ordenada1, 35);
    apilar(&ordenada1, 67);
    apilar(&ordenada2, 1);
    apilar(&ordenada2, 18);
    apilar(&ordenada2, 83);
    apilar(&ordenada2, 99);
    printf("\nPila ORDENADA 1\n");
    mostrar(&ordenada1);
    printf("\nPila ORDENADA 2\n");
    mostrar(&ordenada2);
    while(!pilavacia(&ordenada1) && !pilavacia(&ordenada2)){
        if(tope(&ordenada1) > tope(&ordenada2)){
            apilar(&ordenadaFinal, desapilar(&ordenada1));
        }else {
            apilar(&ordenadaFinal, desapilar(&ordenada2));
        }
    }
    printf("\nPila ORDENADA FINAL\n");
    mostrar(&ordenadaFinal);
    return 0;
}

// 12. Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.

int main()
{
    Pila dada, menor, aux, ordenada;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);
    apilar(&dada, 3);
    apilar(&dada, 4);
    apilar(&dada, 7);
    apilar(&dada, 1);
    apilar(&dada, 9);
    printf("\nPila DADA\n");
    mostrar(&dada);
    while(!pilavacia(&dada)){
        apilar(&menor, desapilar(&dada));
        while(!pilavacia(&dada)){
            if(tope(&dada) > tope(&menor)){
                apilar(&aux, desapilar(&dada));
            }else {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
        }
        apilar(&ordenada, desapilar(&menor));
        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }
    }
    printf("\nPila ORDENADA\n");
    mostrar(&ordenada);
    return 0;
}


// 13. Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al hacerlo coloca todas las cartas (las de él y las de su rival) en su pila de puntos. En caso de empate (y para simplificar) siempre gana el jugador1. Simular la ejecución del juego de tal manera que dada una pila MAZO (con un número de elementos múltiplo de cuatro) distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado. Utilizar las pilas auxiliares que crea conveniente.

int main()
{
    int puntos1 = 0;
    int total1 = 0;
    int puntos2 = 0;
    int total2 = 0;
    Pila mazo, jugador1, jugador2, cartas1, cartas2;

    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&cartas1);
    inicpila(&cartas2);

    apilar(&mazo, 4);
    apilar(&mazo, 1);
    apilar(&mazo, 11);
    apilar(&mazo, 9);
    apilar(&mazo, 12);
    apilar(&mazo, 7);
    apilar(&mazo, 5);
    apilar(&mazo, 10);

    printf("\nMAZO\n");
    mostrar(&mazo);

    while(!pilavacia(&mazo)){

        apilar(&jugador1, desapilar(&mazo));
        puntos1 = puntos1 + tope(&jugador1);

        apilar(&jugador2, desapilar(&mazo));
        puntos2 = puntos2 + tope(&jugador2);

        apilar(&jugador1, desapilar(&mazo));
        puntos1 = puntos1 + tope(&jugador1);

        apilar(&jugador2, desapilar(&mazo));
        puntos2 = puntos2 + tope(&jugador2);


        if(puntos1 >= puntos2){
            printf("\nLos puntos del JUGADOR 1 son %i\n", puntos1);
            printf("\nLos puntos del JUGADOR 2 son %i\n", puntos2);
            printf("\n\nEl JUGADOR 1 Gano esta Ronda!\n\n\n");
            printf("---------------------------------------------------------------------\n");
            while(!pilavacia(&jugador1) && !pilavacia(&jugador2)){
                apilar(&cartas1, desapilar(&jugador1));
                total1++;
                apilar(&cartas1, desapilar(&jugador2));
                total1++;
            }
        }else {
            printf("\nLos puntos del JUGADOR 1 son %i\n", puntos1);
            printf("\nLos puntos del JUGADOR 2 son %i\n", puntos2);
            printf("\n\nEl JUGADOR 2 Gano esta Ronda!\n\n\n");
            printf("---------------------------------------------------------------------\n");
            while(!pilavacia(&jugador1) && !pilavacia(&jugador2)){
                apilar(&cartas2, desapilar(&jugador1));
                total2++;
                apilar(&cartas2, desapilar(&jugador2));
                total2++;
            }
        }

        puntos1 = 0;
        puntos2 = 0;
    }

    printf("\n\nEl JUGADOR 1 Termino con %i Cartas\n", total1);
    printf("\n\nEl JUGADOR 2 Termino con %i Cartas\n", total2);
    printf("---------------------------------------------------------------------\n");

    if(total1 >= total2){
        printf("\n\n\nEl JUGADOR 1 Gana la Partida!!!!!!!!!!!!\n");
    }else {
        printf("\n\n\nEl JUGADOR 2 Gana la Partida!!!!!!!!!!!!\n");
    }

    return 0;
}
*/
