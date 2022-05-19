#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// 1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos que se encuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas.

int main()
{
    Pila dada;
    Pila aux1;
    Pila aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    printf("Ingrese 5 elementos a la pila Dada \n\n");
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    printf("\nPila Dada\n\n");
    mostrar(&dada);
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));
    printf("\nPila Aux 1\n\n");
    mostrar(&aux1);
    printf("\nPila Aux 2\n\n");
    mostrar(&aux2);
    return 0;
}

// 2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.

int main()
{
    Pila destino, origen;
    inicpila(&destino);
    inicpila(&origen);
    printf("Carga la pila ORIGEN\n\n");
    leer(&origen);
    leer(&origen);
    leer(&origen);
    printf("\nPILA ORIGEN\n");
    mostrar(&origen);
    printf("------------------------------------------------------------------\n\n");
    while(!pilavacia(&origen)){
        apilar(&destino, desapilar(&origen));
    }
    printf("\nPILA ORIGEN\n");
    mostrar(&origen);
    printf("\n\nPILA DESTINO\n");
    mostrar(&destino);
    printf("------------------------------------------------------------------\n\n");
    return 0;
}

// 3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.

int main()
{
     Pila dada, distintos, aux;
     inicpila(&dada);
     inicpila(&distintos);
     inicpila(&aux);
     printf("Carga la pila DADA\n\n");
     leer(&dada);
     leer(&dada);
     leer(&dada);
     while(!pilavacia(&dada)){
        if(tope(&dada) != 8){
            apilar(&distintos, desapilar(&dada));
        }else {
            apilar(&aux, desapilar(&dada));
        }
     }
     printf("\n\nPILA DADA\n");
     mostrar(&dada);
     printf("------------------------------------------------------------------\n\n");
     printf("\n\nPILA DISTINTOS\n");
     mostrar(&distintos);
     printf("------------------------------------------------------------------\n\n");
     printf("\n\nPILA AUX\n");
     mostrar(&aux);
     printf("------------------------------------------------------------------\n\n");
     return 0;
}

// 4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.

int main()
{
     Pila origen, destino, aux;
     inicpila(&destino);
     inicpila(&origen);
     inicpila(&aux);
     printf("Carga la pila ORIGEN\n\n");
     leer(&origen);
     leer(&origen);
     leer(&origen);
     printf("\nPILA ORIGEN\n");
     mostrar(&origen);
     printf("------------------------------------------------------------------\n\n");
     apilar(&aux, desapilar(&origen));
     apilar(&aux, desapilar(&origen));
     apilar(&destino, desapilar(&origen));
     apilar(&destino, desapilar(&aux));
     apilar(&destino, desapilar(&aux));
     printf("\nPILA ORIGEN\n");
     mostrar(&origen);
     printf("------------------------------------------------------------------\n\n");
     printf("\n\nPILA DESTINO\n");
     mostrar(&destino);
     printf("------------------------------------------------------------------\n\n");
     return 0;
}

// 5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.

int main()
{
     Pila dada, aux1, aux2;
     inicpila(&dada);
     inicpila(&aux1);
     inicpila(&aux2);
     printf("Carga la pila DADA\n\n");
     leer(&dada);
     leer(&dada);
     leer(&dada);
     printf("\n\nPILA DADA\n");
     mostrar(&dada);
     printf("------------------------------------------------------------------\n\n");
     apilar(&aux1, desapilar(&dada));
     apilar(&aux1, desapilar(&dada));
     apilar(&aux1, desapilar(&dada));
     apilar(&aux2, desapilar(&aux1));
     apilar(&aux2, desapilar(&aux1));
     apilar(&aux2, desapilar(&aux1));
     apilar(&dada, desapilar(&aux2));
     apilar(&dada, desapilar(&aux2));
     apilar(&dada, desapilar(&aux2));
     printf("\n\nPILA DADA\n");
     mostrar(&dada);
     printf("------------------------------------------------------------------\n\n");
     return 0;
}

// 6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden.

int main()
{
     Pila dada, aux1, aux2;
     inicpila(&dada);
     inicpila(&aux1);
     inicpila(&aux2);
     printf("Carga la pila DADA\n\n");
     leer(&dada);
     leer(&dada);
     leer(&dada);
     leer(&dada);
     printf("\n\nPILA DADA\n");
     mostrar(&dada);
     printf("------------------------------------------------------------------\n\n");
     apilar(&aux1, desapilar(&dada));
     apilar(&aux2, desapilar(&dada));
     apilar(&aux2, desapilar(&dada));
     apilar(&aux2, desapilar(&dada));
     apilar(&dada, desapilar(&aux1));
     apilar(&dada, desapilar(&aux2));
     apilar(&dada, desapilar(&aux2));
     apilar(&dada, desapilar(&aux2));
     printf("\n\nPILA DADA\n");
     mostrar(&dada);
     printf("------------------------------------------------------------------\n\n");
     return 0;
}

// 7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes elementos en el mismo orden.

int main()
{
     Pila dada, aux1, aux2;
     inicpila(&dada);
     inicpila(&aux1);
     inicpila(&aux2);
     printf("Carga la pila DADA\n\n");
     leer(&dada);
     leer(&dada);
     leer(&dada);
     leer(&dada);
     printf("\n\nPILA DADA\n");
     mostrar(&dada);
     printf("------------------------------------------------------------------\n\n");
     apilar(&aux2, desapilar(&dada));
     apilar(&aux2, desapilar(&dada));
     apilar(&aux2, desapilar(&dada));
     apilar(&aux1, desapilar(&dada));
     apilar(&dada, desapilar(&aux2));
     apilar(&dada, desapilar(&aux2));
     apilar(&dada, desapilar(&aux2));
     apilar(&dada, desapilar(&aux1));
     printf("\n\nPILA DADA\n");
     mostrar(&dada);
     printf("------------------------------------------------------------------\n\n");
     return 0;
}

// 8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.

int main()
{
     Pila mazo, jugador1, jugador2;
     inicpila(&mazo);
     inicpila(&jugador1);
     inicpila(&jugador2);
     printf("Carga la pila MAZO\n\n");
     leer(&mazo);
     leer(&mazo);
     leer(&mazo);
     leer(&mazo);
     leer(&mazo);
     leer(&mazo);
     printf("\n\nPILA MAZO\n");
     mostrar(&mazo);
     printf("------------------------------------------------------------------\n\n");
     apilar(&jugador1, desapilar(&mazo));
     apilar(&jugador2, desapilar(&mazo));
     apilar(&jugador1, desapilar(&mazo));
     apilar(&jugador2, desapilar(&mazo));
     apilar(&jugador1, desapilar(&mazo));
     apilar(&jugador2, desapilar(&mazo));
     printf("\n\nPILA JUGADOR 1\n");
     mostrar(&jugador1);
     printf("------------------------------------------------------------------\n\n");
     printf("\n\nPILA JUGADOR 2\n");
     mostrar(&jugador2);
     printf("------------------------------------------------------------------\n\n");
     return 0;
}

// 9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.

int main()
{
     int contadorA = 0;
     int contadorB = 0;
     Pila a, b, aux1, aux2;
     inicpila(&a);
     inicpila(&b);
     inicpila(&aux1);
     inicpila(&aux2);
     printf("Carga la pila A\n\n");
     leer(&a);
     leer(&a);
     leer(&a);
     leer(&a);
     printf("Carga la pila B\n\n");
     leer(&b);
     leer(&b);
     leer(&b);
     leer(&b);
     leer(&b);
     while(!pilavacia(&a)){
        apilar(&aux1, desapilar(&a));
        contadorA = contadorA + 1;
     }
     while(!pilavacia(&b)){
        apilar(&aux2, desapilar(&b));
        contadorB = contadorB + 1;
     }
     printf("\nCantidad de elementos en la Pila A: %i\n", contadorA);
     printf("\nCantidad de elementos en la Pila B: %i\n", contadorB);
     return 0;
}

// 10. Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.

int main()
{
    Pila a, b, aux, aux2;
    inicpila(&a);
    inicpila(&b);
    inicpila(&aux);
    inicpila(&aux2);
    printf("\nIngrese 3 datos para la pila A: \n\n");
    leer(&a);
    leer(&a);
    leer(&a);
    printf("\nIngrese 3 datos para la pila B: \n\n");
    leer(&b);
    leer(&b);
    leer(&b);
    leer(&b);
    while(!pilavacia(&a) && !pilavacia(&b)){
        if(tope(&a) == tope(&b)){
            apilar(&aux, desapilar(&a));
            apilar(&aux, desapilar(&b));
        }else {
            apilar(&aux2, desapilar(&a));
            apilar(&aux2, desapilar(&b));
        }
    }
    if(pilavacia(&a) && pilavacia(&b)){
        if(pilavacia(&aux2)){
            printf("\nLas pilas A y B son iguales\n");
        }else {
            printf("\nLas pilas tienen la misma cantidad de datos, pero los numeros son distintos\n");
        }
    }else {
        printf("\nLas pilas no tienen la misma cantidad de datos\n");
    }
    return 0;
}

// 11. Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.

int main()
{
     Pila modelo, dada, aux1, aux2;
     inicpila(&modelo);
     inicpila(&dada);
     inicpila(&aux1);
     inicpila(&aux2);
     apilar(&modelo, 5);
     apilar(&modelo, 9);
     apilar(&modelo, 4);
     printf("Carga la pila DADA\n\n");
     leer(&dada);
     leer(&dada);
     leer(&dada);
     leer(&dada);
     while(!pilavacia(&dada)){
        if(tope(&dada) != tope(&modelo)){
            apilar(&aux2, desapilar(&dada));
        }else{
            apilar(&aux1, desapilar(&dada));
        }
     }
     if(!pilavacia(&aux1)){
        while(!pilavacia(&aux1)){
            apilar(&dada, desapilar(&aux1));
        }
        printf("\n\nPILA DADA\n");
        mostrar(&dada);
        printf("------------------------------------------------------------------\n\n");
     }else {
        printf("\n\nNingun elemento de la Pila DADA coincidio con el tope de la Pila MODELO\n");
     }
     return 0;
}

// 12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.

int main()
{
    Pila modelo, dada, distintos, iguales;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&iguales);
    apilar(&modelo, 5);
    apilar(&modelo, 9);
    apilar(&modelo, 4);
    printf("\n\nPILA MODELO\n");
    mostrar(&modelo);
    printf("------------------------------------------------------------------\n\n");
    printf("Carga la pila DADA\n\n");
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    while(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&modelo != tope(&dada))){
                apilar(&distintos, desapilar(&dada));
            }else {
                apilar(&iguales, desapilar(&dada));
            }
        }
        apilar(&iguales, desapilar(&modelo));
        while(!pilavacia(&distintos)){
            apilar(&dada, desapilar(&distintos));
        }
    }
    printf("\n\nPILA DADA\n");
    mostrar(&dada);
    printf("------------------------------------------------------------------\n\n");
    return 0;
}

// 12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.

int main()
{
    Pila modelo, dada, distintos, iguales;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&iguales);
    apilar(&modelo, 5);
    apilar(&modelo, 9);
    apilar(&modelo, 4);
    printf("\n\nPILA MODELO\n");
    mostrar(&modelo);
    printf("------------------------------------------------------------------\n\n");
    printf("Carga la pila DADA\n\n");
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    while(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&modelo) != tope(&dada)){
                apilar(&distintos, desapilar(&dada));
            }else {
                apilar(&iguales, desapilar(&dada));
            }
        }
        if(!pilavacia(&distintos)){
            apilar(&iguales, desapilar(&modelo));
            while(!pilavacia(&distintos)){
                apilar(&dada, desapilar(&distintos));
            }
        }
    }
    printf("\n\nPILA DADA\n");
    mostrar(&dada);
    printf("------------------------------------------------------------------\n\n");
    return 0;
}

// 13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.

int main()
{
    Pila limite, dada, mayores, menores;
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);
    apilar(&limite, 5);
    apilar(&limite, 9);
    apilar(&limite, 4);
    printf("\n\nPILA LIMITE\n");
    mostrar(&limite);
    printf("------------------------------------------------------------------\n\n");
    printf("Carga la pila DADA\n\n");
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    while(!pilavacia(&dada)){
        if(tope(&dada) >= tope(&limite)){
            apilar(&mayores, desapilar(&dada));
        }else {
            apilar(&menores, desapilar(&dada));
        }
    }
    printf("\n\nPILA MAYORES\n");
    mostrar(&mayores);
    printf("------------------------------------------------------------------\n\n");
    printf("\n\nPILA MENORES\n");
    mostrar(&menores);
    printf("------------------------------------------------------------------\n\n");
    return 0;
}

// 14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR.

int main()
{
    Pila dada, par, impar, aux;
    inicpila(&par);
    inicpila(&dada);
    inicpila(&impar);
    inicpila(&aux);
    printf("Carga la pila DADA\n\n");
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    printf("\n\nPILA DADA\n");
    mostrar(&dada);
    printf("------------------------------------------------------------------\n\n");
    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
        if(pilavacia(&dada)){
            apilar(&impar, desapilar(&aux));
            printf("\nLa cantidad de elementos es IMPAR\n");
            printf("\n\nPILA IMPAR\n");
            mostrar(&impar);
            printf("------------------------------------------------------------------\n\n");
        }else {
            apilar(&aux, desapilar(&dada));
            if(pilavacia(&dada)){
                apilar(&par, desapilar(&aux));
                printf("\nLa cantidad de elementos es PAR\n");
                printf("\n\nPILA PAR\n");
                mostrar(&par);
                printf("------------------------------------------------------------------\n\n");
            }
        }
    }
    return 0;
}

// 15. ¿Cuál es la condición del siguiente ciclo? ¿Cuándo finaliza el ciclo? (Pila1, Pila2, y Descarte son pilas):
/*
    while (!pilavacia(&Pila1)) {
        apilar (&Pila2, desapilar(&Descarte))
    }
*/

int main()
{
    // La condicion es que mientras la PILA1 NO este vacia, se saque un elemento de la Pila DESCARTE y se pase a la PILA2
}

// 16. ¿Que realiza el siguiente código escrito en lenguaje C (Pila1, Aux y Result son pilas):
/*
   while (!pilavacia(&Pila1)) {
       if (tope(&Pila1) == 5) {
          apilar (&Aux, desapilar(&Pila1));
          apilar (&Result, desapilar(&Aux));
       }
    }
*/

int main()
{
    // El codigo tiene la condicion de que mientras que la PILA1 no este vacia, corrobora que el tope de la PILA1 sea igual a 5. Si esa condicion se cumple se desapila PILA1 y se guarda el resultado en la pila AUX, despues de eso desapila la pila AUX y lo apila en la pila RESULT.
}

// 17. Para el ejercicio “Cargar por teclado una pila ORIGEN y pasar a la pila DISTINTO todos aquellos elementos que preceden al valor 5 (elementos entre el tope y el valor 5). No se asegura que exista algún valor 5”, se realizó el siguiente programa:
// este programa carga por teclado una pila Origen y pasa a la pila Destino todos aquellos elementos que preceden el valor 5

/*
   int main() {
       Pila Origen, Distinto;
       inicpila(&Origen);
       inicpila(&Distinto);
       leer(&Origen);
       if (!pilaVacia(&Origen)){
          while (tope(&Origen) != 5) {
             apilar (&Distinto, desapilar(&Origen));
          }
       }
       return 0;
    }
*/

/*
    a. ¿Resuelve el problema planteado?
    b. ¿Cuáles son los errores que encuentra?
    c. Reescribir el código para que resuelva adecuadamente el problema planteado.
    d. Indicar los componentes del programa.
*/

int main()
{
    /*
        a) Lo que hace esta resolucion es que solo en el caso de que el tope de origen no sea 5, desapile ORIGEN y apile DISTINTO
        b) Que la condicion esta mal declarada
        c)
           Pila Origen, Distinto;
           inicpila(&Origen);
           inicpila(&Distinto);
           leer(&Origen);
           if (!pilaVacia(&Origen)){
              while (tope(&Origen) < 5) {
                 apilar (&Distinto, desapilar(&Origen));
              }
           }
           return 0;
        d)
    */

}

// 18. Dado el siguiente ciclo (Pila1, Pila2 y Descarte son pilas):

/*
   while ( (!pilaVacia(&Pila1)) && (!pilaVacia(&Pila2)) ) {
      apilar (&Descarte, desapilar(&Pila1));
      apilar (&Descarte, desapilar(&Pila2))  FALTA UN PUNTO Y COMA
   }
*/

/*
    a. ¿Cuál es la condición del ciclo? Explique con sus palabras
    b. ¿Cuales son los posibles estados de ambas pilas al finalizar el ciclo?
*/

int main()
{
    /*
        a) La condicion del ciclo es que mientras se cumplan ambos casos (1er caso que la PILA1 NO este vacia) y (2do caso que la PILA2 NO este vacia) se desapile ambas pilas y se apilen sus valores en la pila DESCARTE
        b) Hay 3 casos. 1ero que la PILA1 se vacie, 2do caso que la PILA2 se vacie y el 3er caso seria que ambas pilas queden vacias al mismo tiempo
    */
}
