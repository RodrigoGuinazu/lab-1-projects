#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
 char nombreYApellido[30];
 int edad;
 char departamento[30]; /* Finanzas, RRHH, Ventas, etc */
 float sueldo;
} Empleado;


int validarEdad (int edad);
void cargaArchivoEmpleados(char archivo[]);
void mostrarUnEmpleado(Empleado aux);
///void mostrarArchivoEmpleados (char archivo[]);
void mostrarArchivo(char archivo[]);
int pasarToArray (char archivo[], Empleado array[], int dim, char departamento[]);
void ordenacionSeleccion(Empleado a[ ], int cantVal);
int posicionMenor(Empleado a[], int cantVal, int pos);
void mostrarArray (Empleado a[], int validos);
int cantRegistros (char archivo[]);

float porcentajeSueldo (char archivo[]);


int main()
{
    char archi_empleados[] = {"empleados.dat"};

    cargaArchivoEmpleados(archi_empleados);
    mostrarArchivo("empleados.dat");

    Empleado deFinanzas[10];



    int validos = pasarToArray(archi_empleados, deFinanzas,10,"Finanzas");
    ordenacionSeleccion(deFinanzas,validos);
    //mostrarArray(deFinanzas, validos);

    int cantidad = cantRegistros(archi_empleados);

    float porcentaje = porcentajeSueldo(archi_empleados);

    printf("\nLa cantidad de empleados es %i, \ny el porcentaje de los que cobran mas de 1500 es  : %f",cantidad,porcentaje);

    int registro;

    printf("\n Ingrese el registro que quiere ver : ");
    fflush(stdin);
    scanf("%d", &registro);
    if(registro<cantidad)
    {
        mostrarDeterminado(archi_empleados, registro);
    }









    return 0;
}

int validarEdad (int edad)
{
    int edadValida = 0;
    if (edad>=18)
    {
        edadValida= 1;
    }
  return edadValida;
}

void cargaArchivoEmpleados(char archivo[])
{
    FILE*pArchi=fopen(archivo, "ab");
    Empleado aux;
    char control='s';


    if(pArchi)
    {
        printf("\n Desea cargar algun empleado? s o n\n");
        fflush(stdin);
        scanf("%c",&control);
        while(control == 's')
        {
            printf("\nIngrese el nombre : ");
            fflush(stdin);
            gets(aux.nombreYApellido);
            fflush(stdin);
            do{
            printf("\nIngrese la edad : ");
            scanf("%d",&aux.edad);

            }while(validarEdad(aux.edad)== 0);

            printf("\nIngrese el departamento laboral : ");
            fflush(stdin);
            scanf("%s", aux.departamento);
            printf("\nIngrese el sueldo : ");
            scanf("%f",&aux.sueldo);

            fwrite(&aux, sizeof(Empleado),1,pArchi);

             printf("\nDesea continuar? s o n\n");
             fflush(stdin);
             scanf("%c",&control);
        }
        fclose(pArchi);
    }
}


/*void mostrarArchivoEmpleados (char archivo[])
{
    FILE*pArchi = fopen(archivo, "rb");
    Empleado aux;
    if(pArchi)
    {
      while(fread(&aux, sizeof(Empleado),1, pArchi)>0)
      {
        printf("\n--------------");
        printf("\nNombre : %s",aux.nombreYApellido);
        printf("\nEdad : %d",aux.edad);
        printf("\nDepartamento : %s",aux.departamento);
        printf("\nSueldo : %2f",aux.sueldo);
      }
     fclose(pArchi);
    }

}
*/
void mostrarArchivo(char archivo[])
{
    FILE*parchivo= fopen(archivo, "rb");
    Empleado a;

    if(parchivo)
    {
        fseek(parchivo,0,SEEK_SET);
        while(fread(&a,sizeof(Empleado),1,parchivo)>0)
        {
            mostrarUnEmpleado(a);
        }
        fclose(parchivo);
    }
}
void mostrarUnEmpleado(Empleado aux)
{
    printf("\n--------------");
    printf("\nNombre : %s",aux.nombreYApellido);
    printf("\nEdad : %d",aux.edad);
    printf("\nDepartamento : %s",aux.departamento);
    printf("\nSueldo : %.2f",aux.sueldo);

}

int pasarToArray (char archivo[], Empleado array[], int dim, char departamento[])
{
    FILE*pArchi = fopen(archivo, "rb");
    int i = 0;
    Empleado aux;
    if(pArchi)
    {
        while(fread(&aux, sizeof(Empleado),1,pArchi)>0 && i<dim)
        {
            if(strcmp(aux.departamento, departamento)== 0)
            {
                array[i]= aux;
                i++;
            }

        }
        fclose(pArchi);
    }
    return i;
}
int posicionMenor(Empleado a[], int cantVal, int pos){
    Empleado menor = a[pos];
    int posMenor = pos;
    int index = pos + 1;
    while (index < cantVal){
        if(strcmp(menor.nombreYApellido, a[index].nombreYApellido)>0){
            menor = a[index];
            posMenor = index;
        }
        index++;
    }
    return posMenor;
}
void ordenacionSeleccion(Empleado a[ ], int cantVal){
    int posMenor;
    int i = 0;
    Empleado aux;
    while(i< cantVal - 1){ /// llego hasta la anteúltima posición
        posMenor = posicionMenor(a, cantVal, i);
        aux = a[posMenor];
        a[posMenor] = a[i];
        a[i] = aux;
        i++;
    }
}

void mostrarArray (Empleado a[], int validos)
{
    int i=0;
    while(i < validos)
    {
        mostrarUnEmpleado(a[i]);
        i++;
    }
}

int cantRegistros (char archivo[])
{
    FILE*pArchi = fopen(archivo, "rb");
    int cantidadRegistros;
    Empleado aux;
    if(pArchi)
    {
        fseek(pArchi,0, SEEK_END);
        cantidadRegistros = ftell(pArchi)/ sizeof(aux);
        fclose(pArchi);
    }

    return cantidadRegistros;
}

float porcentajeSueldo (char archivo[])
{
    FILE*pArchi = fopen(archivo, "rb");
    int cobranpiola=0;
    int total = cantRegistros(archivo);
    float porcentaje;
    Empleado aux;


    if(pArchi)
    {
        while(fread(&aux, sizeof(Empleado),1,pArchi))
        {
            if(aux.sueldo>15000)
            {
                cobranpiola++;
            }
        }
        fclose(pArchi);
    }

    porcentaje= ((float)cobranpiola/(float)total)*100;


    return porcentaje;


}

void mostrarDeterminado (char archivo[], int registro)
{
    FILE*parchi=fopen(archivo,"rb");
    Empleado aux;

    if(parchi)
    {
        fseek(parchi,(registro-1)*sizeof(Empleado), SEEK_SET);
        fread(&aux,sizeof(Empleado),1,parchi);
        mostrarUnEmpleado(aux);
    }

}
