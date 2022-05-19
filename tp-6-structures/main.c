#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int matricula;
    char nombre[20];
    char genero;
} setAlumno;

int cargarAlumnos(setAlumno alumnos[10]);
void printObejeto(setAlumno alumnos[10], int i);
void mostrarAlumnos(setAlumno alumnos[10], int validos);
void mostrarAlumnoPorMatricula(setAlumno alumnos[10], int validos, int matricula);
int buscarMenor(setAlumno alumnos[10], int validos, int iterador);
void ordenarPorSeleccion(setAlumno alumnos[10], int validos);
int generoAlumnos(setAlumno alumnos[10], int validos, char genero);
int insertarNuevoElemento(setAlumno alumnos[10], int validos);
void insertar(setAlumno alumnos[10], int ultimaPos, setAlumno alumnoAInsertar);
void ordenarPorInsercion(setAlumno alumnos[10], int validos);

int main()
{
    setAlumno alumnos[10];
    char control = 's';
    int option;

    while(control == 's'){
        printf("TP-6 ESTRUCTURAS DE DATOS\n");
        printf("-----------------------------------------\n\n");
        printf("Oprima el numero del ejercicio que desea ver\n\n");
        printf("1 - Ejercicio 1\n");
        printf("2 - Ejercicio 2\n");
        printf("3 - Ejercicio 3\n");
        printf("4 - Ejercicio 4\n");
        printf("5 - Ejercicio 5\n");
        printf("6 - Ejercicio 6\n");
        printf("7 - Ejercicio 7\n");
        printf("8 - Ejercicio 8\n\n");

        fflush(stdin);
        scanf("%i", &option);
        system("cls;");

        switch(option){
        case 1: ;  // Para evitar problemas en la ejecucion agregar un ; despues de cada case!
            int validos = cargarAlumnos(alumnos);

            system("Pause");
            system("cls");
            break;

        case 2: ;
            mostrarAlumnos(alumnos, validos);

            system("Pause");
            system("cls");
            break;

        case 3: ;
            mostrarAlumnoPorMatricula(alumnos, validos, 420);

            system("Pause");
            system("cls");
            break;

        case 4: ;
            ordenarPorSeleccion(alumnos, validos);
            mostrarAlumnos(alumnos, validos);

            system("Pause");
            system("cls");
            break;

        case 5: ;
            int cantidadPorGenro = generoAlumnos(alumnos, validos, 'f');

            system("Pause");
            system("cls");
            break;

        case 6: ;
            validos = insertarNuevoElemento(alumnos, validos);
            mostrarAlumnos(alumnos, validos);

            system("Pause");
            system("cls");
            break;

        case 7: ;
            ordenarPorInsercion(alumnos, validos);
            mostrarAlumnos(alumnos, validos);

            system("Pause");
            system("cls");
            break;

        case 8: ;
            printf("\nHay %i mujeres\n", cantidadPorGenro);

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

    printf("Gracias por ver el tp-6 estructuras de Rodrigo Guinazu");

    return 0;
}

// 1

int cargarAlumnos(setAlumno alumnos[10]){
    char control = 's';
    int i = 0;

    while(i<10 && control == 's'){
        printf("\nIngresa la matricula:\n");
        fflush(stdin);
        scanf("%i", &alumnos[i].matricula);

        printf("\nIngrese el Nombre\n");
        fflush(stdin);
        gets(alumnos[i].nombre);

        printf("\nIngrese el genero\n");
        fflush(stdin);
        scanf("%c", &alumnos[i].genero);

        i++;
        printf("\nDesea cargar otro alumno?\n");
        fflush(stdin);
        scanf("%c", &control);
    }

    return i;
}

// 2

void printObejeto(setAlumno alumnos[10], int i){
    printf("{\n");
    printf("    matricula: %i\n", alumnos[i].matricula);
    printf("    nombre: %s\n", alumnos[i].nombre);
    printf("    genero: %c\n", alumnos[i].genero);
    printf("},\n");
}

void mostrarAlumnos(setAlumno alumnos[10], int validos){
    int i = 0;
    printf("\n[\n");
    while(i < validos){
        printObejeto(alumnos, i);
        i++;
    }
    printf("\n]\n");
}

// 3

void mostrarAlumnoPorMatricula(setAlumno alumnos[10], int validos, int matricula){
    int flag = 0;
    int i = 0;
    while( i < validos && flag == 0 ){
        if(alumnos[i].matricula == matricula){
            flag = 1;
        }else{
            i++;
        }
    }
    if(flag == 1){
        printObejeto(alumnos, i);
    }else{
        printf("\nLa matricula ingresada no coincide con ningun alumno\n");
    }
}

// 4

int buscarMenor(setAlumno alumnos[10], int validos, int iterador){
    int menor = alumnos[iterador].matricula;
    int pos = iterador;
    int i = pos + 1;

    while(i<validos){
        if(alumnos[i].matricula < menor){
            menor = alumnos[i].matricula;
            pos = i;
        }
        i++;
    }
    return pos;
}

void ordenarPorSeleccion(setAlumno alumnos[10], int validos){
    int i = 0;
    int pos = 0;
    setAlumno aux;

    while(i<validos-1){
        pos = buscarMenor(alumnos, validos, i);

        aux = alumnos[pos];
        alumnos[pos] = alumnos[i];
        alumnos[i] = aux;

        i++;
    }
}

// 5 y 8

int generoAlumnos(setAlumno alumnos[10], int validos, char genero){
    int contador = 0;
    for(int i=0; i<validos; i++){
        if(alumnos[i].genero == genero){
            printObejeto(alumnos, i);
            contador++;
        }
    }
    return contador;
}

// 6

int insertarNuevoElemento(setAlumno alumnos[10], int validos){
    alumnos[validos].matricula = 12345;
    strcpy(alumnos[validos].nombre, "Probando Insertar");
    alumnos[validos].genero = 'm';

    return validos+1;
}

// 7

void insertar(setAlumno alumnos[10], int ultimaPos, setAlumno alumnoAInsertar){
    int i = ultimaPos;
    while(i>=0 && strcmp(alumnoAInsertar.nombre, alumnos[i].nombre) == -1){
        alumnos[i+1] = alumnos[i];
        i--;
    }
    alumnos[i+1] = alumnoAInsertar;
}


void ordenarPorInsercion(setAlumno alumnos[10], int validos){
    int i = 0;
    while(i<validos){
        insertar(alumnos, i, alumnos[i+1]);
        i++;
    }
}
