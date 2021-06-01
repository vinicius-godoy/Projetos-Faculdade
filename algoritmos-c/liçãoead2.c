#define ex1
#include<stdlib.h>
#include<locale.h>

/*1. Receba a quantidade de números pares definida pelo usuário representada pela variável J.
A variável par representa cada número par digitado pelo usuário. Exiba a média dos números
pares divisíveis por 3, o maior número par encontrado e a quantidade de vezes que ele apareceu.*/
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int j, cont, par, maior, div, contm;
    float media;

    printf("Digite a quantidade de números pares que serão digitados: ");
    scanf("%i", &j);
    for(cont=0, media=0, maior=0, div=0; cont<j; cont++)
    {
        do{
        printf("Digite um número par: ");
        scanf("%i", &par);
        if(par%2!=0){
            printf("O número digitado tem que ser par!\n");
        }
        }while(par%2!=0);
        if(par%3==0){
            media += par;
            div += 1;
        }
        if(par>maior){
            maior = par;
            contm = 1;
        }else if(par==maior){
            contm +=1;
        }
    }
    printf("\nMédia dos pares múltiplos de 3: %g | Maior par: %i (Foi digitado %i vezes)\n", media/div, maior, contm);
}
#endif

/* 1)	Desafio: Solicite ao usuário dois números positivos e diferentes. O primeiro deve ser
menor que o segundo e exiba todos os números definidos nesse intervalo. Utilize o laço for
para exibir esses números. */
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num1, num2, cont;

    printf("Digite dois números positivos e diferentes para ver os números em seu intervalo\n");
    do{
    printf("Digite o primeiro número: ");
    scanf("%i", &num1);
    if(num1<0){
        printf("O número digitado tem que ser positivo!\n");
    }
    }while(num1<0);
    printf("---------------------------------------------------------\n");
    do{
    printf("Digite o segundo número: ");
    scanf("%i", &num2);
    if(num2<0){
        printf("O número digitado tem que ser positivo!\n");
    }else if(num2<num1){
        printf("O segundo número precisa ser maior que o primeiro!\n");
    }else if(num2==num1){
        printf("O segundo número não pode ser igual ao primeiro!\n");
    }
    }while(num2<0 || num2<num1 || num2==num1);
    printf("\nOs números entre %i e %i são:\n", num1, num2);
    for(cont=num1+1; cont<num2; cont++)
    {
        printf("%i ", cont);
    }
    printf("\n");
}
#endif // ex2
