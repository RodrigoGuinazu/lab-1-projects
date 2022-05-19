#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idTipoDonacion;
    char nombre[30];
    int categoria;
}stTipoDonacion;

typedef struct{
    int idDonante;
    char nombre[30];
    float montoDonado;
    int idTipoDonacion;
}stDonante;

const char tiposDonacion[]={"tipoDonacion.dat"};
const char donantesA[]={"donantesA.dat"};
const char donantesB[]={"donantesB.dat"};

int cargarNuevosDonantes(stDonante nuevosDonantes[], char tiposDonacion[], int dimension);
int verificarIdTipo(char tiposDonacion[], int tipoDeDonacion);
void mostrarArray(stDonante nuevosDonantes[], int validos);
void printArray(stDonante donante);

void pasajeAArchivo(stDonante nuevosDonantes[], char donantesA[], char donantesB[], int validos);
void mostrarArchivo(char nombreArchivo[]);

float promedio(char archivo[]);
void subPrograma(stDonante nuevosDonantes[], char donantesA[], char donantesB[], int validos);

void mostrarPorCategoria(char tiposDonacion[], char nombres[][30], int categoria);
void mostrarMatriz(char nombres[][30], int validos, int categoria);
void subPrograma2(char nombres[][30]);

/*
5.	Hacer una función main() que invoque a los modulos anteriores y demuestre el funcionamiento del programa.
a.	Para hacer esto, cree las variables que considere necesarias e invoque las funciones (de forma directa o indirecta) como corresponde en cada caso.
b.	Muestre los resultados cada vez que sea necesario.
c.	Si lo considera, cree un menú de opciones para ejecutar cada función o subprograma.
d.	A fin de identificar cada inciso, comente su código indicando a qué apartado corresponde, por ejemplo: // Apartado 3.b
*/

int main(){
    printf("\n**********************************************************************************\n");
    printf("\n                                          PARCIAL 2\n");
    printf("\n**********************************************************************************\n");

    /// EJERCICIO 1
    printf("\nEJERCICIO 1\n");
    int dimension;
    printf("\nDimension del Array: ");
    scanf("%i", &dimension);
    stDonante nuevosDonantes[dimension];
    int validos = cargarNuevosDonantes(nuevosDonantes, tiposDonacion, dimension);
    mostrarArray(nuevosDonantes, validos);

    /// EJERCICIO 2 Y 3
    printf("\nEJERCICIO 2\n");
    subPrograma(nuevosDonantes, donantesA, donantesB, validos);

    /// EJERCICIO 4
    printf("\nEJERCICIO 4\n");
    char nombres[10][30];
    mostrarPorCategoria(tiposDonacion, nombres, 1);
    printf("\n**********************************************************************************\n");
    return 0;
}

/// --------------------------------------------------------------------------------------------------------------------------

/*
1. Efectuar la carga nuevos donantes sobre un arreglo de una dimensión específica con intervención del usuario del sistema.
Esta función deberá validar que el idTipoDonacion ingresado exista en el archivo de tipos de donación que se le ha entregado. Dicha operación se debe realizar en una función aparte (Modularizar).
Una vez cargado el arreglo de donantes, deberá mostrarlos por pantalla a fin de corroborar que los datos han sido debidamente ingresados. Modularizar.
*/

int cargarNuevosDonantes(stDonante nuevosDonantes[], char tiposDonacion[], int dimension){
    char control = 's';
    int validos = 0;

    while(validos <= dimension && control == 's'){
        printf("\nCARGANDO UN NUEVO DONANTE\n");

        printf("\nID:\n");
        scanf("%i", &nuevosDonantes[validos].idDonante);

        printf("\nNombre:\n");
        fflush(stdin);
        gets(nuevosDonantes[validos].nombre);

        printf("\Monto:\n");
        scanf("%f", &nuevosDonantes[validos].montoDonado);

        int flagDonacion = 0;
        while(flagDonacion == 0){
            printf("\nTipo de donacion:\n");
            scanf("%i", &nuevosDonantes[validos].idTipoDonacion);
            flagDonacion = verificarIdTipo(tiposDonacion, nuevosDonantes[validos].idTipoDonacion);
            if(flagDonacion == 0){
                printf("\nEse ID No es correcto!\n");
                system("pause");
            }
        }
        validos++;

        printf("\nDesea continuar? (s/n)\n");
        fflush(stdin);
        control = getch();
    }
    return validos;
}

int verificarIdTipo(char tiposDonacion[], int tipoDeDonacion){
    FILE * archivo = fopen(tiposDonacion, "rb");
    stTipoDonacion nuevaDonacion;

    if(archivo){
        while(fread(&nuevaDonacion, sizeof(stTipoDonacion), 1, archivo) > 0){
            if(nuevaDonacion.idTipoDonacion == tipoDeDonacion){
                return 1;
            }
        }
        fclose(archivo);
    }
    return 0;
}


void mostrarArray(stDonante nuevosDonantes[], int validos){
    for(int i = 0; i < validos; i++ ){
        printArray(nuevosDonantes[i]);
    }
}

void printArray(stDonante donante){
    printf("\n---------------------------------------\n");
    printf("Id: %i\n", donante.idDonante);
    printf("Nombre: %s\n", donante.nombre);
    printf("Monto: %.2f\n", donante.montoDonado);
    printf("Tipo de donacion: %i\n", donante.idTipoDonacion);
}

/// --------------------------------------------------------------------------------------------------------------------------

/*
2.	A partir del arreglo cargado en el inciso anterior :
a.	Pasar a dos archivos de donantes (“donantesA.dat” y “donantesB.dat”) la información cargada en el arreglo, dependiendo del monto donado por cada uno.
Se considera un donante “A” si ha contribuido con un monto superior a $25.000,00.
Dentro de la función, deberá trabajar con dos variables de tipo FILE *, una para cada archivo.
b.	Realizar una función que muestre un archivo de donantes por pantalla. Modularizar.
*/

void pasajeAArchivo(stDonante nuevosDonantes[], char donantesA[], char donantesB[], int validos){
    FILE *archivoA = fopen(donantesA, "ab");
    FILE *archivoB = fopen(donantesB, "ab");
    int i = 0;
    stDonante aux;

    for(i=0; i<validos; i++){
        if(nuevosDonantes[i].montoDonado >= 25000){
            if(archivoA){
                aux = nuevosDonantes[i];
                fwrite(&aux, sizeof(stDonante), 1, archivoA);

                fclose(archivoA);
            }
        }else{
            if(archivoB){
                aux = nuevosDonantes[i];
                fwrite(&aux, sizeof(stDonante), 1, archivoB);

                fclose(archivoB);
            }
        }
    }
}

void mostrarArchivo(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "rb");
    stDonante aux;

    if(archivo){
        while(fread(&aux, sizeof(stDonante), 1, archivo) > 0){
            printArray(aux);
        }

        fclose(archivo);
    }else{
        printf("\nError en el archivo!\n");
    }

}

/// --------------------------------------------------------------------------------------------------------------------------

/*
3.	Averiguar el promedio del valor donado sobre el total de donantes almacenados en uno de los archivos. Para lo cual deberá realizar:
a.	Una función que calcule la cantidad total de registros que posee un archivo.
b.	Una función que calcule el promedio del valor donado sobre el total de donantes almacenados en el archivo.
c.	Un subprograma, que deberá invocar a las funciones anteriores (3.a y 3.b) e informar por pantalla los resultados obtenidos en cada caso.
Deberá trabajar en el archivo correspondiente de donantes (donantes A o donantes B), de acuerdo a la solicitado por el usuario del sistema.
*/

float promedio(char archivo[]){
    FILE *archi = fopen(archivo, "rb");
    float sumaMonto = 0;
    stDonante aux;
    float promedioFinal = 0;

    if(archi){
        while(fread(&aux, sizeof(stDonante), 1, archi) > 0){
            sumaMonto = sumaMonto + aux.montoDonado;
        }

        fseek(archi, 0, SEEK_END);
        int validos = ftell(archi)/sizeof(stDonante);

        promedioFinal = sumaMonto/(float)validos;
        fclose(archi);
    }

    return promedioFinal;
}

void subPrograma(stDonante nuevosDonantes[], char donantesA[], char donantesB[], int validos){
    pasajeAArchivo(nuevosDonantes, donantesA, donantesB, validos);
    printf("\n============================================================================================\n");
    printf("\n\nARCHIVO A\n\n");
    mostrarArchivo(donantesA);
    printf("\n============================================================================================\n");
    printf("\n\nARCHIVO B\n\n");
    mostrarArchivo(donantesB);
    printf("\n============================================================================================\n");

    printf("\nEJERCICIO 3\n");
    printf("\n--------------PROMEDIOS-----------------------\n");
    float promedioFinal1 = promedio(donantesA);
    printf("\nPromedio del Archivo A: %.2f\n", promedioFinal1);
    float promedioFinal2 = promedio(donantesB);
    printf("\nPromedio del Archivo B: %.2f\n", promedioFinal2);
}

/// --------------------------------------------------------------------------------------------------------------------------

/*
4.	Mostrar todos los nombres de los tipos de donación de una categoría determinada. Para lo cual deberá realizar:
a.	Hacer una función que pase los nombres de los tipos de donación almacenados en el archivo a un arreglo de strings,
correspondientes a una categoría específica. La función debe retornar la cantidad de nombres copiados.
b.	Hacer una función que muestre por pantalla un arreglo de strings cargado con la función anterior, indicando la categoría a la que corresponden.
c.	Un subprograma, que deberá invocar a las funciones anteriores (4.a y 4.b) e informar por pantalla los resultados obtenidos en cada caso.
*/

void mostrarPorCategoria(char tiposDonacion[], char nombres[][30], int categoria){
    FILE *archivo = fopen(tiposDonacion, "rb");
    stTipoDonacion aux;
    int i = 0;

    if(archivo){
        while(fread(&aux, sizeof(stTipoDonacion), 1, archivo) > 0){
            if(aux.categoria == categoria){
                strcpy(nombres[i], aux.nombre);
                i++;
            }
        }
        fclose(archivo);
    }
    mostrarMatriz(nombres, i, categoria);
}

void mostrarMatriz(char nombres[][30], int validos, int categoria){
    int i = 0;
    printf("\nCategoria %d\n", categoria);
    printf("\n[");
    while(i<validos){
        printf("\n%s", nombres[i]);
        i++;
    }
    printf("\n]\n");
}


/// --------------------------------------------------------------------------------------------------------------------------
