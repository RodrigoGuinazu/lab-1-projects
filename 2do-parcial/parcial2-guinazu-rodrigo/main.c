#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int id;
    char nombre[30];
    char autor[30];
    float precio;
}Cuadro;

void cargarCuadros(char archivoCuadros[]);
int validarPrecio(float precio);
void mostrarArchivo(char archivoCuadros[]);
void mostrarCuadro(Cuadro nuevoCuadro);
int pasarArray(char archivoCuadros[], char autor[], Cuadro arrayCuadros[]);
void mostrarArray(Cuadro arrayCuadros[], int validos);
void insertar(Cuadro arrayCuadros[], int ultimaPos, Cuadro dato);
void ordenamientoPorInsercion(Cuadro arrayCuadros[], int validos);
int cantidadDeCuadros(char archivoCuadros[]);
void cuadroPorPosicion(char archivoCuadros[], int posicion);
float porcentajeMenores(char archivoCuadros[]);

int main()
{
    menu();
    return 0;
}

/// -------------------------------------------------------- EJERCICIO 1 ----------------------------------------------------------------------------------------------------------------------------------------

void cargarCuadros(char archivoCuadros[]){
    char control = 's';
    Cuadro nuevoCuadro;
    FILE *archivo = fopen(archivoCuadros, "ab");

    if(archivo){
        printf("\nQuiere cargar un Cuadro? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);

        while(control == 's'){
            printf("\n-----------------------CARGANDO CUADROS---------------------------\n");

            printf("\nID:\n");
            fflush(stdin);
            scanf("%i", &nuevoCuadro.id);

            printf("\nNombre del Cuadro:\n");
            fflush(stdin);
            gets(nuevoCuadro.nombre);


            printf("\nAutor del Cuadro:\n");
            fflush(stdin);
            gets(nuevoCuadro.autor);


            fflush(stdin);
            int flagPrecio = 0;
            while(flagPrecio == 0){
                printf("\nPrecio en USD:\n");
                scanf("%f", &nuevoCuadro.precio);
                flagPrecio = validarPrecio(nuevoCuadro.precio);
            }


            printf("\n--------------------------------------------------------------------\n");

            fwrite(&nuevoCuadro, sizeof(Cuadro), 1, archivo);

            printf("\nCargar otro Cuadro? (s/n)\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archivo);
    }else {
        printf("El archivo en NULL");
    }
}

int validarPrecio(float precio){
    if(precio>1000.0 && precio<100000.0){
        return 1;
    }
    printf("\nEl precio debe ser entre 1.000 y 100.000\n");
    return 0;
}
/// -------------------------------------------------------- EJERCICIO 2 ----------------------------------------------------------------------------------------------------------------------------------------

void mostrarArchivo(char archivoCuadros[]){
    FILE *archivo = fopen(archivoCuadros, "rb");
    Cuadro nuevoCuadro;
    if(archivo){
        while(fread(&nuevoCuadro, sizeof(Cuadro), 1, archivo) > 0){
            mostrarCuadro(nuevoCuadro);
        }
        fclose(archivo);
    }
}

void mostrarCuadro(Cuadro nuevoCuadro){
    printf("ID: %i\n", nuevoCuadro.id);
    printf("\Nombre del Cuadro: %s\n", nuevoCuadro.nombre);
    printf("Autor del Cuadro: %s\n", nuevoCuadro.autor);
    printf("Precio: $%.2f\n", nuevoCuadro.precio);
    printf("\n***************************************************\n");
}

/// ----------------------------------------------------------- EJERCICIO 3 Y 4 -------------------------------------------------------------------------------------------------------------------------------------

int pasarArray(char archivoCuadros[], char autor[], Cuadro arrayCuadros[]){
    Cuadro nuevoCuadro;
    int i = 0;
    FILE *archivo = fopen(archivoCuadros, "rb");

    if(archivo){
        while(fread(&nuevoCuadro, sizeof(Cuadro), 1, archivo) > 0){
            if(strcmp(nuevoCuadro.autor, autor) == 0){
                arrayCuadros[i] = nuevoCuadro;
                i++;
            }
        }

        fclose(archivo);
    }
    return i;
}

void mostrarArray(Cuadro arrayCuadros[], int validos){
    int i = 0;
    while(i<validos){
        mostrarCuadro(arrayCuadros[i]);
        i++;
    }
}

/// ------------------------------------------------------  EJERCICIO 5 ------------------------------------------------------------------------------------------------------------------------------------------

void insertar(Cuadro arrayCuadros[], int ultimaPos, Cuadro dato){
    Cuadro aux;
    aux = dato;
    int i = ultimaPos;
    for(i; i>=0 && strcmpi(arrayCuadros[i].nombre, aux.nombre)>0; i--){
        arrayCuadros[i+1] = arrayCuadros[i];
    }
    arrayCuadros[i+1] = aux;
}

void ordenamientoPorInsercion(Cuadro arrayCuadros[], int validos){
    for(int i=0; i<validos-1; i++){
        insertar(arrayCuadros, i, arrayCuadros[i+1]);
    }
}

/// ---------------------------------------------------------   EJERCICIO 6 ---------------------------------------------------------------------------------------------------------------------------------------

int cantidadDeCuadros(char archivoCuadros[]){
    Cuadro nuevoCuadro;
    int totalDeCuadros = 0;
    FILE *archivo = fopen(archivoCuadros, "rb");

    if(archivo){
        fseek(archivo,0, SEEK_END);
        totalDeCuadros = ftell(archivo)/ sizeof(nuevoCuadro);

        fclose(archivo);
    }
    return totalDeCuadros;
}

/// --------------------------------------------------------------   EJERCICIO 7 ----------------------------------------------------------------------------------------------------------------------------------

void cuadroPorPosicion(char archivoCuadros[], int posicion){
    Cuadro nuevoCuadro;
    int totalDeCuadros = 0;
    FILE *archivo = fopen(archivoCuadros, "rb");

    if(archivo){
        fseek(archivo,(posicion-1)*sizeof(Cuadro), SEEK_SET);
        fread(&nuevoCuadro, sizeof(Cuadro), 1, archivo);
        mostrarCuadro(nuevoCuadro);

        fclose(archivo);
    }
}

/// --------------------------------------------------------------   EJERCICIO 8 ----------------------------------------------------------------------------------------------------------------------------------

float porcentajeMenores(char archivoCuadros[]){
    FILE *archivo = fopen(archivoCuadros, "rb");
    Cuadro nuevoCuadro;
    float porcentaje = 0.00;
    int cuadrosMenores = 0;
    int total = cantidadDeCuadros(archivoCuadros);

    if(archivo){
        while(fread(&nuevoCuadro, sizeof(Cuadro), 1, archivo) > 0){
            if(nuevoCuadro.precio < 20000.00){
                cuadrosMenores++;
            }
        }
        fclose(archivo);
    }

    porcentaje = ((float)cuadrosMenores/(float)total) * 100;
    return porcentaje;
}

/// ------------------------------------------------------------   EJERCICIO 9  ------------------------------------------------------------------------------------------------------------------------------------


void menu(){
    char control = 's';
    int option;
    Cuadro arrayCuadros[50];
    float porcentaje = 0;
    char autor[50];
    int validos = 0;

    while(control == 's'){
        printf("\nPARCIAL 2 GUINAZU RODRIGO\n");
        printf("-----------------------------------------\n\n");
        printf("Ingrese una opcion\n\n");
        printf("[1] - Ejercicio 1\n");
        printf("[2] - Ejercicio 2\n");
        printf("[3] - Ejercicio 3 y 4\n");
        printf("[4] - Ejercicio 5\n");
        printf("[5] - Ejercicio 6\n");
        printf("[6] - Ejercicio 7\n");
        printf("[7] - Ejercicio 8\n");

        fflush(stdin);
        scanf("%i", &option);
        system("cls;");

        switch(option){
            case 1: ;

            cargarCuadros("archivoCuadros.bin");

            system("Pause");
            system("cls");
            break;

            case 2: ;

            mostrarArchivo("archivoCuadros.bin");

            system("Pause");
            system("cls");
            break;

            case 3: ;

            fflush(stdin);
            printf("\nQue autor desea buscar? ");
            gets(autor);
            validos = pasarArray("archivoCuadros.bin", autor, arrayCuadros);
            if(validos == 0){
                printf("\nNo tenemos ningun cuadro de ese autor!\n");
            }else{
                mostrarArray(arrayCuadros, validos);
            }

            system("Pause");
            system("cls");
            break;

            case 4: ;

            fflush(stdin);
            printf("\nQue autor desea Ordenar? ");
            gets(autor);
            validos = pasarArray("archivoCuadros.bin", autor, arrayCuadros);
            if(validos == 0){
                printf("\nNo tenemos ningun cuadro de ese autor!\n");
            }else{
                void ordenamientoPorInsercion (arrayCuadros, validos);
                printf("\nArray Ordenado\n");
                mostrarArray(arrayCuadros, validos);
            }

            system("Pause");
            system("cls");
            break;

            case 5: ;

            int totalDeCuadros = cantidadDeCuadros("archivoCuadros.bin");
            printf("Hay %i Cuadros en el archivo", totalDeCuadros);

            system("Pause");
            system("cls");
            break;

            case 6: ;

            int posicionABuscar;
            int flagPosicion = 0;
            while(flagPosicion == 0){
                printf("\nQue Posicion quiere buscar?\n");
                scanf("%i", &posicionABuscar);
                if(posicionABuscar > totalDeCuadros){
                    printf("\nEsa posicion NO existe!\n");
                    flagPosicion = 0;
                }else{
                    cuadroPorPosicion("archivoCuadros.bin", posicionABuscar);
                    flagPosicion = 1;
                }
            }

            system("Pause");
            system("cls");
            break;

            case 7: ;

            porcentaje = porcentajeMenores("archivoCuadros.bin");
            printf("\nEl %%%.2f de los cuadros vale menos de $20.000 USD\n", porcentaje);

            system("Pause");
            system("cls");
            break;

            default: ;

            printf("\nElegiste una opcion incorrecta\n");
        }
        printf("\nVolver al menu principal? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
}
