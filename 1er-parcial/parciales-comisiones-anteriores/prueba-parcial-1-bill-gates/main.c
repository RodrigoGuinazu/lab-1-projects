#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include <ctype.h>

//1
void datos(int id, float version[], char ranking[], int cantBugs[]);
char scanChar();
float scanFloat();
int scanInt();
//2
void pasarArregloIntAPila(Pila *pila, int idWindows[], int validos);
//3
float versionWindows(int idWindows, float versions[]);
//4
int getId(int idWindows[], char ranking[], int cantBugs[]);
//5
void informarVersion(Pila ids, float version[],int validos);
//6
void masVersionesDe(char A[], int validos);

void arregloCharMostrar(char C[],int validos);

int main()
{
    int idWindows[] = {1,2,3,4,5,6,7,8,9,10};
    float version[] = {1.0, 2, 1.2, 2.0, 3, 1.5, 1.7, 2, 1.9, 4};
    char ranking[]={'a','b','e','a','e','c','d','d','c','e'};
    int cantBugs[]={200,100,240,150,40,80,220,110,95,70};

    printf("\nEjercicio 1\n");
    printf("\nIngrese el id para insertar los datos: ");
    int id1=0;
    scanf("%i",&id1);
    datos(id1,version,ranking,cantBugs);
    printf("\n%.2f\n",version[id1-1]);
    printf("\n%c\n",ranking[id1-1]);
    printf("\n%i\n",cantBugs[id1-1]);

    printf("\nEjercicio 2\n");
    int validosId = 10;
    Pila ids;
    inicpila(&ids);
    pasarArregloIntAPila(&ids, idWindows,validosId);
    mostrar(&ids);

    printf("\nEjercicio 3\n");
    printf("\nINGRESE ID PARA BUSCAR VERSION: ");
    int idABuscar=0;
    scanf("%i",&idABuscar);
    printf("\nLa version de windows %i es: %f",idABuscar, versionWindows(idABuscar, version));

    printf("\nEjercicio 4\n\n");
    int pos = getId(idWindows, ranking, cantBugs);
    printf("%i",pos);

    printf("\nEjercicio 5\n\n");
    int validosVersion = 10;
    informarVersion(ids,version,validosVersion);

    printf("\nEjercicio 6\n");
    masVersionesDe(ranking,validosVersion);

    return 0;
}

    // 1
    void datos(int id, float version[], char ranking[], int cantBugs[] ){
        printf("Ingrese version: ");
        version[id-1]=scanFloat();
        printf("Ingrese ranking: ");
        ranking[id-1]=scanChar();
        printf("Ingrese los bugs: ");
        cantBugs[id-1]=scanInt();
    }

    int scanInt(){
        int dato;
        fflush(stdin);
        scanf("%i",&dato);
        return dato;
    }

    float scanFloat(){
        float dato;
        fflush(stdin);
        scanf("%f",&dato);
        return dato;
    }

    char scanChar(){
        char dato;
        fflush(stdin);
        scanf("%c",&dato);
        return dato;
    }

    //2
    void pasarArregloIntAPila(Pila *pila, int idWindows[], int validos){
        for(int i=0; i<validos;i++)
        apilar(pila,idWindows[i]);
    }

    // 3
    float versionWindows(int idWindows, float versions[]){
        return versions[idWindows-1];
    }

    //4
    int getId(int idWindows[], char ranking[], int cantBugs[]){
        int i=0;
        int indice=-1;

        while(i<10 && indice==-1){
            if(ranking[i]=='e' && cantBugs>100){
                indice=i;
            }
            i++;
        }
        return indice+1;
    }

    //5
    void informarVersion(Pila ids, float version[],int validos){
        int i=validos-1;
        while(!pilavacia(&ids)){
            printf("LA ID ES: %i Y LA VERSION ES: %.2f\n",tope(&ids),version[i]);
            desapilar(&ids);
            i--;
        }
    }

    //6
    void masVersionesDe(char A[], int validos) {
        int counterA=0;
        int counterB=0;
        int counterC=0;
        int counterD=0;
        int counterE=0;

        for(int i=0;i<validos;i++){
            if(A[i]=='a'){
                counterA++;
            }else if(A[i]=='b'){
                counterB++;
            }else if(A[i]=='c'){
                counterC++;
            }else if(A[i]=='d'){
                counterD++;
            }else if(A[i]=='e'){
                counterE++;
            }
        }

        if(counterA>counterB && counterA>counterC && counterA>counterD &&counterA>counterE){
            printf("EL RANKING QUE MAS APARECE ES A");
        } else if(counterB>counterA && counterB>counterC && counterB>counterD &&counterB>counterE){
            printf("EL RANKING QUE MAS APARECE ES B");
        }else if(counterC>counterA && counterC>counterB && counterC>counterD &&counterC>counterE){
            printf("EL RANKING QUE MAS APARECE ES C");
        }else if(counterD>counterA && counterD>counterB && counterD>counterC &&counterD>counterE){
            printf("EL RANKING QUE MAS APARECE ES D");
        } else{
            printf("EL RANKING QUE MAS APARECE ES E");
        }
    }

    // MOSTRAR ARREGLO CHAR
    void arregloCharMostrar(char C[],int validos){
        for(int i=0;i<validos;i++){
            printf("%c , ",C[i]);
        }
        printf("\n");
    }
