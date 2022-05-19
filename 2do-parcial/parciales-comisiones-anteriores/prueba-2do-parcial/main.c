#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
char nombre[30];
char tipo[30]; //Portero - Defensa - Mediocampista - Delantero
int nro; // nro que lleva en la camiseta
}Jugador;

typedef struct
{
  char nombre[30];
  int pj; ///partidos jugados , 0 por defecto
  int goles; //0 por defecto
}Est_Jugador;


Jugador jugadorRandom(char archivoJugadores[], char tipo[]);
void cargarFormacion(Jugador formacion[5][5], int portero, int defensores, int medio1, int medio2, int delanteros);
void matrizMostrar(Jugador formacion[5][5]);
void mostrarJugador(Jugador jugador);
void actualizarEstadistica(Jugador formacion[5][5], char archivoEstadistica[]);

int main()
{
   //archivoMostrar("jugadores.bin");

   //1 meter jugadores a arreglo ordenados por tipo
   Jugador jugadores[40];
   //printf("\nArray\n");
   int validos = arregloPorTipo("jugadores.bin", jugadores);
   //ordenarPorSeleccion(jugadores, validos);
   //mostrarArray(jugadores, validos);

    //matriz
    //estadisticas("estadisticas.bin", jugadores, validos);

    Jugador formacion[5][5];
    srand(time(NULL));
    cargarFormacion(formacion, 1,4,3,3,0);
    //matrizMostrar(formacion);

    actualizarEstadistica(formacion, "estadisticas.bin");
    mostrarEstadistica("estadisticas.bin");

   return 0;
}

void actualizarEstadistica(Jugador formacion[5][5], char archivoEstadistica[]){
    FILE *archivo = fopen(archivoEstadistica, "r+b");
    Est_Jugador aux;
    int flag = 0;
    int i=0;
    int j=0;

    if(archivo){

       for(i; i<5; i++){
          for(j; j<5; j++){
            if(formacion[i][j].nro != -1){
                flag = 0;
                while(flag == 0 && fread(&aux, sizeof(Est_Jugador), 1, archivo) > 0){
                    if(strcmp(formacion[i][j].nombre, aux.nombre) == 0){
                        flag = 1;
                    }
                }
                fseek(archivo, (-1 * sizeof(Est_Jugador)), SEEK_CUR);
                aux.pj++;
                fwrite(&aux, sizeof(Est_Jugador), 1, archivo);
            }
          }
       }

       fclose(archivo);
    }else{
        printf("\nNo se abrio el archivo!\n");
    }
}
/*
int goles(){
    int goles;

    return goles;
}
*/
void estadisticas(char archivoEstadistica[], Jugador jugadores[], int validos){
    FILE *archivo = fopen(archivoEstadistica, "ab");
    Est_Jugador aux;

    if(archivo){
        for(int i=0; i<validos; i++){
            strcpy(aux.nombre, jugadores[i].nombre);
            aux.pj = 0;
            aux.goles = 0;
            fwrite(&aux, sizeof(Est_Jugador), 1, archivo);
        }

        fclose(archivo);
    }else{
        printf("\nNo se abrio el archivo!\n");
    }
}

void mostrarEstadistica(char archivoEstadistica[]){
    FILE *arch = fopen(archivoEstadistica, "rb");
    Est_Jugador aux;

    if(arch){
      while(fread(&aux, sizeof(Est_Jugador), 1, arch) > 0){
         printEstadistica(aux);
      }
      fclose(arch);
   }else{
      printf("ERROR al abrir el archivo\n");
   }
}

void printEstadistica(Est_Jugador jugador){
    printf("nombre: %s\n",jugador.nombre);
    printf("partidos jugados: %i\n",jugador.pj);
    printf("goles: %i\n",jugador.goles);
    printf("\n------------------------------------\n");
}

Jugador jugadorRandom(char archivoJugadores[], char tipo[]){
    FILE *archivo = fopen(archivoJugadores, "rb");
    Jugador arrayAux[30];
    Jugador aux;
    int i = 0;
    int azar;

    if(archivo){
        while(fread(&aux, sizeof(Jugador), 1, archivo) > 0){
            if(strcmp(aux.tipo, tipo) == 0){
                arrayAux[i] = aux;
                i++;
            }
        }
        fclose(archivo);
    }else{
        printf("\nERROR AL ABRIR EL ARCHIVO\n");
    }

    azar = rand()%i;

    return arrayAux[azar];
}

void cargarFormacion(Jugador formacion[5][5], int portero, int defensores, int medio1, int medio2, int delanteros){
    int j;
    for(int i=0; i<5; i++){
        if(i==0){
            for(j=0; j<portero; j++){
                formacion[i][j] = jugadorRandom("jugadores.bin", "Portero");
            }
            for(j=portero; j<5; j++){
                formacion[i][j].nro = -1;
            }
        }else if(i==1){
            for(j=0; j<defensores; j++){
                formacion[i][j] = jugadorRandom("jugadores.bin", "Defensa");
            }
            for(j=defensores; j<5; j++){
                formacion[i][j].nro = -1;
            }
        }else if(i==2){
            for(j=0; j<medio1; j++){
                formacion[i][j] = jugadorRandom("jugadores.bin", "Mediocampista");
            }
            for(j=medio1; j<5; j++){
                formacion[i][j].nro = -1;
            }
        }else if(i==3){
            for(j=0; j<medio2; j++){
                formacion[i][j] = jugadorRandom("jugadores.bin", "Mediocampista");
            }
            for(j=medio2; j<5; j++){
                formacion[i][j].nro = -1;
            }
        }else{
            for(j=0; j<delanteros; j++){
                formacion[i][j] = jugadorRandom("jugadores.bin", "Delantero");
            }
            for(j=delanteros; j<5; j++){
                formacion[i][j].nro = -1;
            }
        }
    }
}

//mostrar matriz struc
void matrizMostrar(Jugador formacion[5][5]){
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        if(formacion[i][j].nro != -1){
            mostrarJugador(formacion[i][j]);
        }
      }
   }
}


//1. meta al arreglo por tipo
int arregloPorTipo(char nombreArchivo[],Jugador jugadores[]){
   FILE *arch = fopen(nombreArchivo,"rb");
   int i=0;
   Jugador jugadorActual;

   if(arch){
      while(fread(&jugadorActual, sizeof(Jugador), 1, arch) > 0){
            jugadores[i] = jugadorActual;
            i++;
      }
      fclose(arch);
   }else{
      printf("ERROR al abrir el archivo\n");
   }
   return i;
}

int buscarPosicionMenor (Jugador jugadores[], int pos, int validos){
    Jugador menor = jugadores[pos];///guardamos la primera posicion del arreglo recortado
    int posmenor = pos;/// donde se guarda la posicion del menor
    int index = pos + 1;
    while(index < validos){
        if(strcmp(menor.tipo, jugadores[index].tipo) == 1){
            menor = jugadores[index];
            posmenor = index;///guarda posicion del menor
        }
        index++;
    }
    return posmenor;///retorna la posicion donde estaba el menor
}

void ordenarPorSeleccion(Jugador jugadores[], int validos){
    Jugador burbuja;
    int posmenor = 0;
    int i = 0;
    while(i<(validos)){
        posmenor = buscarPosicionMenor(jugadores, i, validos);///guardar la posicion del menor
        burbuja = jugadores[posmenor];
        jugadores[posmenor] = jugadores[i];
        jugadores[i] = burbuja;
        i++;
    }
}

void mostrarArray(Jugador jugadores[], int validos){
    for(int i=0; i<validos; i++){
        mostrarJugador(jugadores[i]);
    }
}

//mostrarArchivo
void archivoMostrar(char jugadores[]){
   FILE *arch = fopen(jugadores,"rb");
   Jugador jugador;

   if(arch){
      while(fread(&jugador,sizeof(jugador),1,arch)>0){
         mostrarJugador(jugador);
      }
      fclose(arch);
   }else{
      printf("ERROR al abrir el archivo\n");
   }
}

//mostrar 1 solo jugador
void mostrarJugador(Jugador jugador){
     printf("nombre: %s\n",jugador.nombre);
     printf("tipo: %s\n",jugador.tipo);
     printf("numero: %i\n",jugador.nro);
     printf("\n------------------------------------\n");
}
