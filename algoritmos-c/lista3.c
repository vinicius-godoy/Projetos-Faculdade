#define ex2
#include<stdio.h>
#include<locale.h>

/*1. Mostre todos os números ímpares de 1 até 100. Utilize o laço do while. */

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = -1;
    printf("Numéros ímpares de 1 a 100:\n");
    do{
        num += 2;
        printf("%i\n", num);
    }while(num<99);
}
#endif // ex1

/*2. Mostre todos os números ímpares de 50 até 300.Utilize o laço do while. */

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = 49;
    printf("Números ímpares de 50 a 300:\n");
    do{
        num += 2;
        printf("%i\n", num);
    }while(num<299);
}
#endif // ex2

/*3. Receba um número inteiro e mostre os números pares a partir de 2 até esse inteiro.
CASO O NUMERO DIGITADO SEJA MENOR QUE 2 SOLICITE UM NOVO NÚMERO. Utilize o laço do while. */

#ifdef ex3
int main()
{

}
#endif // ex3
