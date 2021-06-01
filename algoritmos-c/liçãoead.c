#define ex9
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//1. Mostre todos os números ímpares de 1 até 100. Utilize os três laços de repetição.
//Exercício com 1 laço do-while
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = -1;

    printf("Números Ímpares de 1 a 100\n");
    do{
        num += 2;
        printf("%i\n", num);
    }while(num<99);
}
#endif // ex1
//Exercício 1 com laço while
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = -1;

    printf("Números Ímpares de 1 a 100\n");
    while(num<99){
        num += 2;
        printf("%i\n", num);
    }
}
#endif // ex2
//Exercício 1 com laço for
#ifdef ex3
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num, cont;

    printf("Números Ímpares de 1 a 100\n");
    for(cont = 1, num = 1; num<=99; cont++, num +=2)
    {
        printf("%i\n", num);
    }
}
#endif // ex3

/*2. Mostre todos os números pares maiores ou iguais a  50  e menores ou iguais 300.
Faça  este exercício utilizando os três laços de repetição. */
//Exercício 2 com laço do-while
#ifdef ex4
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = 48;

    printf("Números Pares maiores que 50 e menores que 300\n");
    do{
        num+=2;
        printf("%i\n", num);
    }while(num<300);
}
#endif // ex4
//Exercício 2 com laço do
#ifdef ex5
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = 48;

    printf("Números Pares maiores que 50 e menores que 300\n");
    while(num<300){
        num+=2;
        printf("%i\n", num);
    }
}
#endif // ex5
//Exercício 2 com laço for
#ifdef ex6
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num, cont;

    printf("Números Pares maiores que 50 e menores que 300\n");
    for(num=50, cont=1;num<=300;cont++, num+=2){
        printf("%i\n", num);
    }
}
#endif // ex6

/*3. Mostre todos os números múltiplos de 3 entre os números 1 e 70. Utilize o laço for.*/
#ifdef ex7
int main()
{
    setlocale(LC_ALL, "portuguese");
    int cont;

    printf("Múltiplos de 3 entre 1 e 70\n");
    for(cont = 1; cont<70; cont++){
        if(cont%3==0){
            printf("%i\n", cont);
        }
    }
}
#endif // ex7

/*4. Imprime todos os números entre 30 e 5 (nesta ordem) divisíveis por 3.Imprima também no
final a soma dos números divisíveis por 3.Utilize o laço for. */
#ifdef ex8
int main()
{
    setlocale(LC_ALL, "portuguese");
    int cont, soma;

    printf("Múltiplos de 3 entre 30 e 5\n");
    for(cont = 30, soma = 0; cont>5; cont--){
        if(cont%3==0){
            printf("%i\n", cont);
            soma += cont;
        }
    }
    printf("A soma de todos os múltiplos é %i", soma);
}
#endif // ex8

/*5. Receba a quantidade de alturas de um grupo de N pessoas. N representa essa quantidade
e deve ser digitada pelo usuário. A variável H representa cada altura digitada. Calcule e
mostre a maior altura encontrada e  média das alturas digitadas. */
#ifdef ex9
int main()
{
    setlocale(LC_ALL, "portuguese");
    int n, cont;
    float h, mediah, maiorh;

    printf("Digite o número de pessoas pra ter sua altura comparada: ");
    scanf("%i", &n);
    for(cont = 0,h = 0, mediah = 0, maiorh = 0; cont<n; cont++){
        printf("Digite a altura da %iº pessoa:     m\b\b\b\b\b", cont+1);
        scanf("%f", &h);
        printf("------------------------------------\n");
        mediah += h;
        if(h>maiorh){
            maiorh = h;
        }
    }
    printf("A maior altura das digitadas é %.2fm e a média de todas as alturas é %.2f\n", maiorh, mediah/n);
}
#endif // ex9
