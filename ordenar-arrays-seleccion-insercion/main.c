#include <stdio.h>
#include <stdlib.h>

int cargarArreglo (int a [],int dimension);
void mostrarArreglo (int a [], int validos);
void ordenarPorSeleccion (int a[], int validos);
int buscarPosicionMenor (int a[], int pos, int validos );
void ordenamientoPorInsercion (int a[], int validos);
void insertar (int a [], int ultimaPos , int dato );


int main()
{

    int arreglo [10];
    int validos=0;

    validos=cargarArreglo(arreglo, 10);
    printf("El arreglo desordenado es: \n");
    mostrarArreglo(arreglo, validos);
    printf("El arreglo ordenado es: \n");
    ordenamientoPorInsercion(arreglo,validos);
    ///ordenarPorSeleccion(arreglo, validos);
    mostrarArreglo(arreglo, validos);

    return 0;
}

void insertar (int a [], int ultimaPos , int dato ){

    int i=ultimaPos;
    while(i>=0 && dato<a[i]){

        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;
}

void ordenamientoPorInsercion (int a[], int validos){

    int i=0;
    while(i<validos){
        insertar(a,i,a[i+1]);
        i++;
    }
}

/// esta funcion solo busca el menor a partir de la posicion que le dicen
int buscarPosicionMenor (int a[], int pos, int validos ){

    int menor=a[pos];///guardamos la primera posicion del arreglo recortado
    int posmenor=pos;/// donde se guarda la posicion del menor
    int index=pos+1;
    while(index<validos){

        if(menor>a[index]){
            menor=a[index];
            posmenor=index;///guarda posicion del menor
        }
        index++;
    }
    return posmenor;///retorna la posicion donde estaba el menor
}

void ordenarPorSeleccion (int a[], int validos){

    int burbuja=0;
    int posmenor=0;
    int i=0;
    while(i<(validos)){
        posmenor=buscarPosicionMenor(a,i,validos);///guardar la posicion del menor
        mostrarArreglo(a, validos);
        system("pause");
        burbuja=a[posmenor];
        a[posmenor]=a[i];
        a[i]=burbuja;
        i++;
    }
}

int cargarArreglo (int a [],int dimension)
{
    int i=0;
    char letra='s';

    while (i<dimension && letra=='s')
    {

        printf("Ingrese un valor al arreglo: \n");
        fflush(stdin);
        scanf("%i", &a[i]);
        printf("desea seguir ingresando valores? \n");
        fflush(stdin);
        scanf("%c",&letra);
        i++;
    }

    return i;
}


void mostrarArreglo (int a [], int validos){
  int i=0;

  while(i<validos){
    printf("a[%i]: %i \n",i , a[i]);
    i++;
  }

}
