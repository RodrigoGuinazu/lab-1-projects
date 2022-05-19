#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
     int id;
     char nombreCompleto[30];
     int legajo;
     int edad;
     int anio;
} setAlumno;

void agregarAlFinal(char archivo[]);
void mostrarArchivo(char archivo[]);
void mostrarAlumno(setAlumno alumno);
int ultimoId(char archivoAlumnos[]);
int cuentaRegistros(char archivoAlumnos[], int tamanio);

int main()
{
    agregarAlFinal("archivoAlumnos.dat");
    printf("\nAlumnos en el Archivo: %d\n", cuentaRegistros("archivoAlumnos.dat", sizeof(setAlumno)));
    printf("\nListado de alumnos:\n");
    mostrarArchivo("archivoAlumnos.dat");

    return 0;
}

void agregarAlFinal(char archivoAlumnos[]){
    char control = 's';
    int i = ultimoId(archivoAlumnos);
    setAlumno alumno;
    FILE *archivo = fopen(archivoAlumnos, "ab");

    if(archivo){ // SIEMPRE VERIFICAR SI EL ARCHIVO SE ABRIO ANTES DE TRABAJAR CON EL
        printf("\nQuiere cargar un alumno? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);

        while(control == 's'){
            printf("\n--------------------------------------------------\n");

            printf("\nNombre completo del alumno:\n");
            fflush(stdin);
            gets(alumno.nombreCompleto);

            printf("\nLegajo del alumno:\n");
            scanf("%i", &alumno.legajo);

            printf("\nEdad del alumno:\n");
            scanf("%i", &alumno.edad);

            printf("\nAnio en el que se encuentra el alumno:\n");
            scanf("%i", &alumno.anio);

            printf("\n--------------------------------------------------\n");

            i++; // El incremento va antes de setear el ID !!!
            alumno.id = i;

            fwrite(&alumno, sizeof(setAlumno), 1, archivo); // fread y fwrite llevan los mismos parametros

            printf("\nCargar otro alumno? (s/n)\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archivo);
    }else {
        printf("El archivo en NULL");
    }
}

void mostrarArchivo(char archivoAlumnos[]){ // Porque el parametro es un array de char?
    FILE *archivo = fopen(archivoAlumnos, "rb");
    setAlumno alumno;

    if(archivo){
        while(fread(&alumno, sizeof(setAlumno), 1, archivo) > 0){ // fread y fwrite llevan los mismos parametros
            mostrarAlumno(alumno);
        }

        fclose(archivo);
    }
}

void mostrarAlumno(setAlumno alumno){
    printf("\nID: %d\n", alumno.id);
    printf("Nombre Completo: %s\n", alumno.nombreCompleto);
    printf("Legajo: %d\n", alumno.legajo);
    printf("Edad: %d\n", alumno.edad);
    printf("Anio: %d\n", alumno.anio);
    printf("\n***************************************************\n");
}

int ultimoId(char archivoAlumnos[]){ // PARA AUTO-GENERAR EL ID CORRECTAMENTE
    FILE *archivo = fopen(archivoAlumnos, "r+b");
    setAlumno alumno;
    int id = 0;

    if(archivo){
        fseek(archivo, -1 * sizeof(setAlumno), SEEK_END); // Uso el fseek() para bucar desde el indice que le indique, SEEK_END(2) pondria el indice desde el final del archivo.
        if(fread(&alumno, sizeof(setAlumno), 1, archivo) > 0){ // En caso de que el archivo exista pero este vacio, para no retornar basura hago la condicion.
            id = alumno.id;
        }
        fclose(archivo);
    }
    return id;
}

int cuentaRegistros(char archivoAlumnos[], int tamanio){ // Para saber cuantos registros existen en en el archivo, le paso como segundo parametro el tamanio para poder reutilizar el codigo
    FILE *archivo = fopen(archivoAlumnos, "r+b");
    int cantidad = 0;
    if(archivo){
        fseek(archivo, 0, SEEK_END); // Se posiciona en el final del archivo y no se mueve de ahi
        cantidad = ftell(archivo)/tamanio; // El ftell(archivo) devuelve el peso en bytes del archivo, al dividirlo por sizeof(setAlumno) podemos saber cuantos registros hay
        fclose(archivo);
    }
    return cantidad;
}
