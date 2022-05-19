#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int maxC=3;
const int maxF=3;
const int maxCPalabras=30;
const int maxFPalabras=30;
void cargarMatrizNumeros(int M[][maxC]);
void mostrarMatrizNumeros (int M[][maxC]);
void cargarMatrizNumerosAleatorios(int M[][maxC]);
int sumarMatriz (int M[][maxC]);
float promedioMatriz (int suma);
int buscarEnMatriz (int M[][maxC], int dato);
int cargarMatrizPalabras (char M[][maxCPalabras]);
void mostarPalabras (char M[][maxCPalabras], int cantidadPalabras);
int buscarPalabra (char M[][maxCPalabras], int cantidadPalabras, char palabraABuscar[]);
char matrizCharPosicionMenor(char M[][maxCPalabras], int validos,int pos);
void matrizCharOrdenarSeleccion(char M[][maxCPalabras],int validos);
void matrizCharOrdenarInsercion(char M[][maxCPalabras], int validos);
void matrizCharInsertar(char M[][maxCPalabras], int validos, char insertar[]);

int main()
{
    int matrizA[maxF][maxC];
    char matrizPalabras[maxFPalabras][maxCPalabras];

    //cargarMatrizNumeros(matrizA);
    srand(time(NULL));
    cargarMatrizNumerosAleatorios(matrizA);
    printf("La matriz es: \n");
    mostrarMatrizNumeros(matrizA);

    int buscar = buscarEnMatriz(matrizA, 5);
    if(buscar == 1){
        printf("\nEl elemento se encuentra en la Matriz\n");
    }else{
        printf("\nEl elemento NO se encuentra en la Matriz\n");
    }

    int sumatoria = sumarMatriz(matrizA);
    printf("\nLa suma de la Matriz es: %i\n", sumatoria);

    float promedio = promedioMatriz(sumatoria);
    printf("\nEl promedio de la Matriz es: %.2f\n", promedio);

    int cantidadPalabras = cargarMatrizPalabras(matrizPalabras);
    printf("\nCargaste %i palabras\n", cantidadPalabras);

    mostarPalabras(matrizPalabras, cantidadPalabras);

    char palabraABuscar[10] = "hola";
    int comparar = buscarPalabra(matrizPalabras, cantidadPalabras, palabraABuscar);
    if(comparar == 0){
        printf("\nLa palabra buscada NO se encuentra en la Matriz\n");
    }else{
        printf("\nLa palabra buscada se encuentra en la Matriz!!!\n");
    }

    //10 seleccion
    matrizCharOrdenarSeleccion(matrizPalabras, cantidadPalabras);
    printf("SOY LA MATRIZ ORDENADA POR SELECCION\n");
    mostarPalabras(matrizPalabras, cantidadPalabras);

//   10 inserccion
    //matrizCharOrdenarInsercion(matrizPalabras, cantidadPalabras);
    //printf("SOY LA MATRIZ ORDENADA POR INSERCION\n");
    //mostarPalabras(matrizPalabras, cantidadPalabras);

    return 0;
}

// 1

void cargarMatrizNumeros(int M[][maxC]){

    int f=0;
    int c=0;
    for(f=0; f<maxF; f++){
        for(c=0;c<maxC; c++){
            printf("Ingrese el numero: \n");
            scanf("%d", &M[f][c]);
        }
    }
}

// 2

void mostrarMatrizNumeros (int M[][maxC]){

    int f=0;
    int c=0;
    for(f=0; f<maxF; f++){
        for(c=0;c<maxC; c++){
            printf("%d-", M[f][c]);
        }
        printf("\n");
    }
}

// 3

void cargarMatrizNumerosAleatorios(int M[][maxC]){
    int f=0;
    int c=0;
    for(f=0; f<maxF; f++)
    {
        for(c=0; c<maxC; c++)
        {
            M[f][c]=rand()%10;
        }
    }
}

/* De esta forma la funcion es mas flexible y puede ser reutilizada
void matrizIntCargarRand(int fil, int col, int M[fil][col]){
   for(int i=0;i<fil;i++){
      for(int j=0;j<col;j++){
        M[i][j]=rand()%11;
      }
   }
}
*/

// 4

int sumarMatriz (int M[][maxC]){
    int f=0;
    int c=0;
    int suma = 0;
    for(f=0; f<maxF; f++){
        for(c=0;c<maxC; c++){
            suma = suma + M[f][c];
        }
    }
    return suma;
}

// 5

float promedioMatriz (int suma){
    int elementos = maxC * maxF;
    float promedio = (float)suma / (float)elementos;
    return promedio;
}

// 6

int buscarEnMatriz (int M[][maxC], int dato){
    int f=0;
    int c=0;
    for(f=0; f<maxF ; f++){
        for(c=0;c<maxC; c++){
            if(M[f][c] == dato){
                return 1;
            }
        }
    }
    return 0;
}

// 7

int cargarMatrizPalabras (char M[][maxCPalabras]){
    int f = 0;
    char letra = 's';
    while(f<maxFPalabras && letra == 's'){
        printf("\nEscribe un palabra\n");
        fflush(stdin);
        gets(M[f]);
        printf("\nDesea cargar otra palabra?\n");
        fflush(stdin);
        scanf("%c", &letra);
        f++;
    }
   return f;
}

// 8

void mostarPalabras (char M[][maxCPalabras], int cantidadPalabras){
    int f = 0;
    while(f<cantidadPalabras){
        printf("%s \n", M[f]);
        f++;
    }
}

// 9

int buscarPalabra (char M[][maxCPalabras], int cantidadPalabras, char palabraABuscar[]){
    int f = 0;
    while(f<cantidadPalabras){
        int comparar = strcmpi(M[f], palabraABuscar);
        if(comparar == 0){
            return 1;
        }
        f++;
    }
    return 0;
}

// 10 Insercion

void matrizCharInsertar(char M[][maxCPalabras], int validos, char insertar[]){

   char datazo[30]; //si no hago esto se pisan los datos
   strcpy(datazo, insertar);

   int i = validos;
   while(i>=0 && strcmpi(M[i],datazo)>0){
      strcpy(M[i+1],M[i]);
      i--;
   }
   strcpy(M[i+1],datazo);
}


void matrizCharOrdenarInsercion(char M[][maxCPalabras], int validos){
   int i=1;
   while(i<validos-1){
       matrizCharInsertar(M, i, M[i+1]);
       i++;
   }
}

// 10 Seleccion

void matrizCharOrdenarSeleccion(char M[][maxCPalabras],int validos){
   int posMenor;
   char aux[30];
   for(int i=0;i<maxFPalabras && i<validos-1;i++){
      posMenor=matrizCharPosicionMenor(M, validos, i);
      strcpy(aux,M[i]);
      strcpy(M[i],M[posMenor]);
      strcpy(M[posMenor],aux);
   }
}

char matrizCharPosicionMenor(char M[][maxCPalabras], int validos,int pos){
   char menor[30]; //los arreglos de string se declaran mas grandes para que entre texto del usuario
   strcpy(menor,M[pos]);
   int posMenor=pos;
   int comp;
   for(int i=pos;i<validos && i<maxFPalabras;i++){
      comp=strcmp(M[i],menor);
      if(comp<0){
         posMenor=i;
         strcpy(menor,M[i]);
      }
   }
   return posMenor;
}
