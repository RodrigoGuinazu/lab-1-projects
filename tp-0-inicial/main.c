#include <stdio.h>
#include <stdlib.h>

const float interes = 0.2;
const float descuento = 0.15;
const float descuentoRopa = 0.2;
const int horaComun = 300;
const int horaExtra = 400;
const float descuento1 = 0.2;
const float descuento2 = 0.1;

int main(){

    char control = 's';
    int option;

    while(control == 's'){
        printf("TP-0 INICIAL DE RODRIGO GUINAZU\n");
        printf("-----------------------------------------\n\n");
        printf("Oprima el numero del ejercicio que desea ver\n\n");
        printf("Problemas Secuenciales\n\n");
        printf("1 - Ejercicio 1\n");
        printf("2 - Ejercicio 2\n");
        printf("3 - Ejercicio 3\n\n");
        printf("Problemas Condicionales Selectivos Simples\n\n");
        printf("4 - Ejercicio 1\n");
        printf("5 - Ejercicio 2\n");
        printf("6 - Ejercicio 3\n");
        printf("7 - Ejercicio 4\n");
        printf("8 - Ejercicio 5\n\n");
        printf("Problemas Condicionales Selectivos Compuestos (si anidados o en cascada)\n\n");
        printf("9 - Ejercicio 1\n");
        printf("10 - Ejercicio 2\n\n");
        printf("Problemas con repeticiones\n\n");
        printf("11 - Ejercicio 1\n");
        printf("12 - Ejercicio 2\n");
        printf("13 - Ejercicio 3\n");
        printf("14 - Ejercicio 4\n");
        printf("15 - Ejercicio 5\n");
        printf("16 - Ejercicio 6\n\n");

        fflush(stdin);
        scanf("%i", &option);
        system("cls;");

        switch(option){
        case 1:
            printf("1. Suponga que un individuo desea invertir su capital en un banco y desea saber cuánto dinero ganará después de un mes si el banco paga a razón de 2% mensual.\n\n");

            float total;
            printf("Cuanto dinero desea invertir?\n\n"); // \n para hacer un salto de linea en la consola
            scanf("%f", &total); // Aclarar con %f que tipo de dato se va ingresar
            printf("Su ganancia es de: $%.2f\n\n", (total*interes)); // %.2f para aclarar que el va tener 2 decimales
            printf("Total: $%.2f\n\n", (total*interes)+total); // %.2f para aclarar que el va tener 2 decimales

            system("Pause");
            system("cls");
            break;

        case 2:
            printf("2. Una tienda ofrece un descuento del 15% sobre el total de la compra y un cliente desea saber cuánto deberá pagar finalmente por su compra.\n\n");

            float total2;
            printf("total2 de sus productos:\n\n");
            scanf("%f", &total2);
            printf("Ahorraste: $%.2f\n\n ", (total2*descuento));
            printf("Total a pagar: $%.2f\n\n  ", total2-(total2*descuento));
            return 0;

            system("Pause");
            system("cls");
            break;

        case 3:
            printf("3. Un maestro desea saber qué porcentaje de hombres y que porcentaje de mujeres hay en un grupo de estudiantes.\n\n");

            int hombres, mujeres, total3;
            float div1, div2;
            printf("Cuantos hombres hay en tu grupo?\n\n");
            scanf("%i", &hombres);
            printf("Cuantas mujeres hay en tu grupo?\n\n");
            scanf("%i", &mujeres);
            total3 = hombres + mujeres;
            div1 = (float)hombres/(float)total3; // Tener en cuenta que la division da con decimal, asique hay que hacer la division sobre un float
            div2 = (float)mujeres/(float)total3; // Tener en cuenta que la division da con decimal, asique hay que hacer la division sobre un float
            printf("En tu grupo el %.2f son hombres, y el %.2f son mujeres", (div1*100),(div2*100)); // Tener en cuenta que la division da con decimal, asique hay que poner "%f"

            system("Pause");
            system("cls");
            break;

        case 4:
            printf("1. Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si su promedio de tres calificaciones es mayor o igual a 7; reprueba en caso contrario.\n\n");

            float nota1, nota2, nota3, promedio;
            printf("Ingresa tu Nota 1\n\n");
            scanf("%f", &nota1);
            printf("Ingresa tu Nota 2\n\n");
            scanf("%f", &nota2);
            printf("Ingresa tu Nota 3\n\n");
            scanf("%f", &nota3);
            promedio = (nota1 + nota2 + nota3)/3;
            if(promedio >= 7){
                printf("Aprobaste!");
            }else{
                printf("Desaprobaste :( ");
            }

            system("Pause");
            system("cls");
            break;

        case 5:
            printf("2. En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5000 ¿Cuál será la cantidad que pagara una persona por su compra?\n\n");

            float subtotal, total5, descontado;
            printf("Ingresa tu total a pagar:\n\n");
            scanf("%f", &subtotal);
            if(subtotal > 5000){
                descontado = subtotal*descuentoRopa;
                total5 = subtotal - descontado;
                printf("Como gastaste mas de $5000 te descontamos $%.2f de tu compra! Tu total a pagar es de $%.2f", descontado, total5);
            }else{
                printf("Tu compra no entra en la promocion. Tu total a pagar es de $%.2f", subtotal);
            }

            system("Pause");
            system("cls");
            break;

        case 6:
            printf("3. Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig. manera: Si trabaja 40 horas o menos se le paga $300 por hora Si trabaja más de 40 se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora extra.\n\n");

            float horas, cobro;
            printf("Cuantas horas trabajaste esta semana? \n\n");
            scanf("%f", &horas);
            if(horas > 40){
                float cantidadHorasExtra = horas - 40;
                cobro = (40*horaComun) + (cantidadHorasExtra*horaExtra);
                printf("Trabajaste %.2f horas Extra. Vas a cobrar: $%.2f", cantidadHorasExtra, cobro);
            }else{
                cobro = horas*horaComun;
                printf("No trabajaste horas Extra. Vas a cobrar: $%.2f", cobro);
            }

            system("Pause");
            system("cls");
            break;

        case 7:
            printf("4. Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente\n\n");

            float num1, num2;
            printf("Ingresa el numero 1: \n\n");
            scanf("%f", &num1);
            printf("Ingresa el numero 2: \n\n");
            scanf("%f", &num2);
            if(num1 > num2){
                printf("El numero 1 es mas grande que el 2 %.2f, %.2f", num1, num2);
            }else{
                printf("El numero 2 es mas grande que el 1 %.2f, %.2f", num2, num1);
            }

            system("Pause");
            system("cls");
            break;

        case 8:
            printf("5. Hacer un algoritmo que calcule el total a pagar por la compra de camisas. Si se compran 3 camisas o más se aplica un descuento del 20% sobre el total de la compra y si son menos de 3 camisas un descuento del 10%\n\n");

            int camisas;
            float subtotal8, total8;
            printf("Cuantas camisas vas a comprar?\n\n");
            scanf("%i", &camisas);
            printf("Total a pagar\n\n");
            scanf("%f", &subtotal8);
            if(camisas >= 3){
                total8 = subtotal8-(subtotal8*descuento1);
                printf("Tenes un descuento del 20 porciento, tu total a pagar es de $%.2f", total8);
            }else{
                total8 = subtotal8-(subtotal8*descuento2);
                printf("Tenes un descuento del 10 porciento, tu total a pagar es de $%.2f", total8);
            }

            system("Pause");
            system("cls");
            break;

        case 9:
            printf("1. Leer 2 números; si son iguales que los multiplique, si el primero es mayor que el segundo que los reste y si no que los sume.\n\n");

            float num19, num29, operacion;
            printf("Ingresa el numero 1: \n\n");
            scanf("%f", &num19);
            printf("Ingresa el numero 2: \n\n");
            scanf("%f", &num29);
            if(num19 == num29){
                operacion = num19*num29;
                printf("Tus numeros son iguales. La multiplicacion de ambos es: %.2f", operacion);
            }else if(num19 > num29){
                operacion = num19-num29;
                printf("El numero 1 es mayor que el 2. La resta de ambos numeros es: %.2f", operacion);
            }else{
                operacion = num19+num29;
                printf("El numero 2 es mayor que el 1. La suma de ambos numeros es: %.2f", operacion);
            }

            system("Pause");
            system("cls");
            break;

        case 10:
            printf("2. Leer tres números diferentes e imprimir el número mayor de los tres.\n\n");

            float num10, num20, num30;
            printf("Ingresa el numero 1: \n\n");
            scanf("%f", &num10);
            printf("Ingresa el numero 2: \n\n");
            scanf("%f", &num20);
            printf("Ingresa el numero 3: \n\n");
            scanf("%f", &num30);
            if(num10 > num20 && num10 > num30){
                printf("El numero 1 es el mas grande. Numero 1: %.2f", num10);
            }else if(num20 > num10 && num20 > num30){
                printf("El numero 2 es el mas grande. Numero 1: %.2f", num20);
            }else if(num30 > num20 && num30 > num10){
                printf("El numero 3 es el mas grande. Numero 1: %.2f", num30);
            }else {
                printf("Los valores que ingresaste no son unicos");
            }

            system("Pause");
            system("cls");
            break;

        case 11:
            printf("1. Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Programación 1\n\n");

            int i = 0;
            float total11 = 0;
            for(i=0;i<7;i++){
                float nota[i];
                printf("Ingresa la nota: %i\n\n", i); // No olvidarse el %i para imprimir la posicion de i
                scanf("%f", &nota[i]);
                total11 = total11 + nota[i]; // Suma total11 de todas las notas
                i = i++; // Acumulador para saber la cantidad de notas que se ingresaron
            }
            printf("Tu promedio es de: %f", (total11/i)); // Dividimos la suma de las notas con la cantidad de examenes ingresados

            system("Pause");
            system("cls");
            break;

        case 12:
            printf("2. Leer 10 números y obtener su cubo y su cuarta.\n\n");

            int i12 = 0;
            for(i12=0; i12<10; i12++){
                float num[i12];
                printf("Ingresa el numero: %i\n\n", i12);
                scanf("%f", &num[i12]);
                printf("El cubo del numero %.2f es: %f\n\n", num[i12], (num[i12]*num[i12]*num[i12]));
                printf("La cuarta del numero %.2f es: %f\n\n", num[i12], (num[i12]*num[i12]*num[i12]*num[i12]));
            }

            system("Pause");
            system("cls");
            break;

        case 13:
            printf("3. Leer 10 números e imprimir solamente los números positivos\n\n");

            int i13 = 0;
            for(i13=0; i13<10; i13++){
                float num[i13];
                printf("Ingresa el numero: %i\n\n", i13);
                scanf("%f", &num[i13]);
                if(num[i13]>0){
                    printf("%.2f\n\n", num[i13]);
                }else if(num[i13]<0){
                    printf("Ese numero no es positivo\n\n");
                }else {
                    printf("Ingresaste el 0\n\n");
                }
            }

            system("Pause");
            system("cls");
            break;

        case 14:
            printf("4. Leer 15 números negativos y convertirlos en positivos e imprimir dichos números.\n\n");

            int i14 = 0;
            printf("Debes ingresar 15 numeros negativos y la computadora se encargara de convertirlo en positivo\n\n");
            for(i14=0; i14<15; i14++){
                float num[i14];
                printf("Ingresa el numero: %i\n\n", i14);
                scanf("%f", &num[i14]);
                printf("El numero en positivo es: %.2f\n\n", (num[i14]*(-1)));
            }

            system("Pause");
            system("cls");
            break;

        case 15:
            printf("5. Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos. Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.\n\n");

            float total15;
            float notaBaja = 10;
            int i15 = 0;
            for(i15=0; i15<40; i15++){
                float nota[i15];
                printf("Ingresa la nota: %i\n\n", i15);
                scanf("%f", &nota[i15]);
                total15 = total15 + nota[i15]; // Suma total de todas las notas
                i = i++; // Acumulador para saber la cantidad de notas que se ingresaron
                if(notaBaja>nota[i15]){ // Comparamos si la notaBaja es mayor que la nota que acabamos de poner
                    notaBaja = nota[i15]; // Si es menor notaBaja ahora vale la nota que ingresamos previamente
                }
            }
            printf("El promedio del grupo es de: %.2f\n\n", (total15/i15));
            printf("La nota mas baja fue: %.2f\n\n", notaBaja);

            system("Pause");
            system("cls");
            break;

        case 16:
            printf("6. Calcular e imprimir la tabla de multiplicar de un número cualquiera. Imprimir el multiplicando, el multiplicador y el producto.\n\n");

            int i16 = 1;
            float num;
            printf("Ingresa el numero y la computadora devolvera la tabla de multiplicar del mismo\n\n");
            scanf("%f", &num);
            for(i16=1; i16<11; i16++){
                int multiplicador = i16;
                float multiplicacion = num*multiplicador;
                printf("\n\n %.2f * %i = %f \n\n", num, multiplicador, multiplicacion);
            }

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

    } // Aca cierra el while que empieza en la linea 17

    printf("Gracias por ver el tp-o inicial de Rodrigo Guinazu");

    return 0;

}
