#define ex2
#include<stdio.h>
#include<locale.h>

/*1. Mostre todos os n�meros �mpares de 1 at� 100. Utilize o la�o do while. */

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = -1;
    printf("Num�ros �mpares de 1 a 100:\n");
    do{
        num += 2;
        printf("%i\n", num);
    }while(num<99);
}
#endif // ex1

/*2. Mostre todos os n�meros �mpares de 50 at� 300.Utilize o la�o do while. */

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = 49;
    printf("N�meros �mpares de 50 a 300:\n");
    do{
        num += 2;
        printf("%i\n", num);
    }while(num<299);
}
#endif // ex2

/*3. Receba um n�mero inteiro e mostre os n�meros pares a partir de 2 at� esse inteiro.
CASO O NUMERO DIGITADO SEJA MENOR QUE 2 SOLICITE UM NOVO N�MERO. Utilize o la�o do while. */

#ifdef ex3
int main()
{

}
#endif // ex3
