#include <stdio.h>
#include <stdlib.h>

// 1. Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.

int random();

int main()
{
    int numRand = 0;

    numRand = random();
    printf("\nEl numero es: %i\n", numRand);

    return 0;
}

int random(){
    int numero;

    srand(time(NULL));
    numero=rand()%100;

    return numero;
}

int main()
{
    menorMayor(123,7, -1);
    return 0;
}

int menorMayor(int num1, int num2, int num3){

    int mayor = num1;
    int menor = num1;

    if(num2 > mayor){
        mayor = num2;
    }else if(num2 < menor){
        menor = num2;
    }

    if(num3 > mayor){
        mayor = num3;
    }else if(num3 < menor){
        menor = num3;
    }

    printf("\n\nEl numero mayor es %i y el menor es %i\n\n", mayor, menor);
}

// 3. Diseñe una función que reciba un número entero N y realice la suma de los números enteros positivos menores que N y lo retorne. N es un dato ingresado por el usuario en el main.

int sumasN(int n);

int main()
{
        int n = 0;
    printf("\nIngresa el numero\n");
    scanf("%i", &n);
    int suma = sumasN(n);
    printf("\nLa suma de los numeros enteros menores a tu numero es: %i\n", suma);

    return 0;
}

int sumasN(int n){
    int suma = 0;
    for(int i=0; i<(n); i++){
        suma = suma + i;
    }

    return suma;
}

// 4. Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por parámetro.

int multiplicacion(int num);

int main()
{
    multiplicacion(5);
    return 0;
}

int multiplicacion(int num){
    int cuenta = 0;
    for(int i = 1; i<11; i++){
        cuenta = num * i;
        printf("\n%i * %i = %i\n", num, i, cuenta);
    }
}

// 5. Realice una pequeña calculadora, utilizando funciones (una función de suma, una de multiplicación, una de resta, una de división…)

int sum(int num1, int num2);
int res(int num1, int num2);
int divi(int num1, int num2);
int mul(int num1, int num2);

int main()
{
    int num1, num2 = 0;
    int option = 0;
    int cuenta = 0;

    printf("\nIngrese el numero 1:\n");
    scanf("%i", &num1);
    printf("\nIngrese el numero 2:\n");
    scanf("%i", &num2);

    printf("\n1 Sumar, 2 Restar, 3 Dividir, 4 Multiplicar\n");
    printf("\nIngrese que operacion quiere hacer: \n");
    scanf("%i", &option);

    switch(option){
        case 1:
            cuenta = sum(num1, num2);
            printf("\nEl resultado de la suma es: %i\n", cuenta);
            break;
        case 2:
            cuenta = res(num1, num2);
            printf("\nEl resultado de la resta es: %i\n", cuenta);
            break;
        case 3:
            cuenta = divi(num1, num2);
            printf("\nEl resultado de la division es: %i\n", cuenta);
            break;
        case 4:
            cuenta = mul(num1, num2);
            printf("\nEl resultado de la multiplicacion es: %i\n", cuenta);
            break;
        default:
            printf("\nOpcion incorrecta\n");
    }
    return 0;
}

int sum(int num1, int num2){
    int sumar = num1 + num2;
    return sumar;
}

int res(int num1, int num2){
    int restar = num1 - num2;
    return restar;
}

int divi(int num1, int num2){
    int dividir = num1 / num2;
    return dividir;
}

int mul(int num1, int num2){
    int multiplicar = num1 * num2;
    return multiplicar;
}

// 6. Realizar una función que reciba un número positivo entero por parámetro por referencia, y cambie su signo a negativo

void negativo(int * numero);

int main()
{
    int n = 0;
    printf("\nIngresa el numero n:\n");
    scanf("%i", &n);
    negativo(&n);

    printf("\nEl numero negativo es: %i\n", n);

    return 0;
}

void negativo(int * numero){
   *numero = *numero * (-1);
}

// 7. Realizar una función que reciba dos números enteros por parámetro por referencia y cargue sus valores el usuario dentro de la función.

void numeros(int * num1, int * num2);

int main()
{
    int numero1, numero2;
    numeros(&numero1, &numero2);
    printf("\nNumero 1 es: %i\nNumero 2 es: %i\n", numero1, numero2);
    return 0;
}

void numeros(int * num1, int * num2){
    printf("\nIngresa el numero 1:\n");
    scanf("%i", &*num1);
    printf("\nIngresa el numero 2:\n");
    scanf("%i", &*num2);
}

/* EJEMPLO CON PUNTEROS

void random(int * damage);
int sumarDano(int damage);

int main()
{
    int damage = 100;
    random(&damage);

    printf("\nEl damage es de: %i\n", damage);

    damage = sumarDano(damage);
    printf("El dano es: %i\n", damage);


    return 0;
}

void random(int * damage){
    int numero = 0;

    srand(time(NULL));
    numero=rand()%100;

    printf("numero random: %i\n", numero);

    if(numero > 50){
        *damage = *damage + 10;
    }
}

int sumarDano(int damage){
    damage = damage + 5;

    return damage;
}

EJEMPLO CON PUNTEROS */

/*

int subirDanio (int variable);
int subirVida (int vida);
void subirNivel (int*hp, int*danio, int*energia, int*shield, int rm);

///cuando sube de nivel los personajes ganan +20hp, +2 daño,+2 energia y +1 de armadura +1rm
int main()
{

    int hp=200;
    int danio=10;
    int energia=20;
    int armadura=5;
    int rm=0;
    int exp=400;



    if(exp>200){
        subirNivel(&hp, &danio,&energia, &armadura, rm); // COMO ES UN PUNTERO SE PONE EL & AL NOMBRE DE LA VARIABLE
    }

    printf("La vida del personaje es: %d \n", hp);
    printf("El daño de mi personaje es: %d \n", danio);
    printf("La energia de mi personaje es: %d \n", energia);
    printf("La armadura de mi personaje es: %d \n", armadura);
    printf("La rm de mi personaje es: %d \n",rm);



    return 0;
}

void subirNivel (int*hp, int*danio, int*energia, int*shield, int rm){
    *hp=*hp+20;
    *danio=*danio+2;
    *energia=*energia+2;
    *shield=*shield+1;
    rm=rm+1;

}



int subirVida (int vida){
    vida=vida+20;
    return vida;
}

*/
