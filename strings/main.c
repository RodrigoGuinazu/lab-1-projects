#include <stdio.h>
#include <stdlib.h>
/// Las 2 librerias con las funciones de string
#include <string.h>
#include <ctype.h>
/// Las 2 librerias con las funciones de string

int main()
{

    // formas de declarar y definir
    char string1[]= "Almost before we knew it, we had left the ground";
    char string2[]={'L','O','L',0};
    char string3[]="lol";
    char string4[]="we";

   //strlen( _ );     #include <string.h>
   //Conocer la longitud de una cadena, devuelve un valor entero que es la cantidad de caracteres.
    int length1=strlen(string1);
    printf("EL LARGO DE STRING1 ES: %i\n",length1);
    int length2=strlen(string2);
    printf("EL LARGO DE STRING2 ES: %i\n",length2);

    //strcmp( _ , _ );     #include <string.h>
    //Compara elementos de 2 cadenas con codigo ASCII
    //Diferencia mayusculas
    // si da negativo el menor es el de al izquierda
    //si da 0 son iguales
    //si da 1 el menor es el de la derecha
    int COMPARACION = strcmp(string2,string3);
    printf("LA COMPARACION CON STRCMP ES: %i\n",COMPARACION);


    //strcmpi( _ , _ );    #include <string.h>
    //Compara dos strings para ver si son iguales, pero sin diferenciar mayúsculas y minúsculas.
    //Igual que strcmp pero sin diferenciar mayusculas
    int comparacion = strcmpi(string2,string3);
    printf("LA COMPARACION CON STRCMPI ES: %i\n",comparacion);


    //strcpy( _ , _ );    #include <string.h>
    // Copiar una cadena a otra
    //La primera es la cadena de destino y la segunda la de origen
    // Para hacer printf de strings usar tipo de dato "%s"
    //No es sensible a la dimension de destino, la agrandara de ser necesario
    char destino[100];
    strcpy(destino,string1);
    printf("LA STRING LUEGO DE COPIAR: %s\n",destino);

    //strcat( _ , _ );     #include <string.h>
    //Unir o concatenar dos o más strings, copia el contenido de la segunda cadena al final de la primera.
    //Es sensible a la dimension de destino
    strcat(destino,string2);
    printf("LA STRING DESTINO LUEGO DE CONCATENAR: %s\n",destino);

    //strstr( ); #include <string.h>
    //Permite saber si una cadena está contenida dentro de otra.
    //Devuelve un puntero al comienzo de la cadena buscada, si es que la encuentra
    //Devuelve “NULL” si no lo encuentra
    //Se busca en la string de la izquierda lo de la derecha
    char *busqueda = strstr(string1,string4);
    printf("LA BUSQUEDA RESULTO: %s\n", busqueda);


    //tolower( _ ); toupper( _ );   #include <ctype.h>
    //Posibilitan transformar a minúsculas o mayúsculas cualquier string
    //Hace letra por letra, necesito loop para toda la palabra
    for(int i=0;i<length1;i++){
        string1[i]=toupper(string1[i]); //A LA MISMA STRING
        destino[i]=toupper(string1[i]); // A OTRA STRING
    }
    printf("SOY STRING1 EN MAYUSCULAS: %s\n", string1);
    printf("SOY DESTINO EN MAYUSCULAS: %s\n", destino);


    /// OTRAS FUNCIONES
    //strcoll(); #include <string.h>
    //Comparar dos strings,
    //devuelve un int, cero (0) si son iguales
    //menor que cero (0) si el primero es menor que el segundo
    //mayor que cero (0) si el primero es mayor que el segundo
    int comp=strcoll(string2,string3);
    printf("LA COMPARACION CON STRCOLL ES: %i\n",comp);


    //Otras funciones de string  #include <string.h>

    //strcspn ( );
    // compara y devuelve la primera posición coincidente entre dos strings
    // int *coincidencia=strcspn(string1,string4);
    // printf("LA COINCIDENCIA ES: %i\n",*coincidencia);

    // strchr ( );
    // busca en un string la primera ocurrencia de un carácter especificado, con punteros.
    // char *coincident=strchr(string1,'w');
    // printf("%s",coincident);

    return 0;
}


