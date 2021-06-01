#define ex1
#include<stdlib.h>
#include<locale.h>

/*1. Receba a quantidade de n�meros pares definida pelo usu�rio representada pela vari�vel J.
A vari�vel par representa cada n�mero par digitado pelo usu�rio. Exiba a m�dia dos n�meros
pares divis�veis por 3, o maior n�mero par encontrado e a quantidade de vezes que ele apareceu.*/
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int j, cont, par, maior, div, contm;
    float media;

    printf("Digite a quantidade de n�meros pares que ser�o digitados: ");
    scanf("%i", &j);
    for(cont=0, media=0, maior=0, div=0; cont<j; cont++)
    {
        do{
        printf("Digite um n�mero par: ");
        scanf("%i", &par);
        if(par%2!=0){
            printf("O n�mero digitado tem que ser par!\n");
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
    printf("\nM�dia dos pares m�ltiplos de 3: %g | Maior par: %i (Foi digitado %i vezes)\n", media/div, maior, contm);
}
#endif

/* 1)	Desafio: Solicite ao usu�rio dois n�meros positivos e diferentes. O primeiro deve ser
menor que o segundo e exiba todos os n�meros definidos nesse intervalo. Utilize o la�o for
para exibir esses n�meros. */
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num1, num2, cont;

    printf("Digite dois n�meros positivos e diferentes para ver os n�meros em seu intervalo\n");
    do{
    printf("Digite o primeiro n�mero: ");
    scanf("%i", &num1);
    if(num1<0){
        printf("O n�mero digitado tem que ser positivo!\n");
    }
    }while(num1<0);
    printf("---------------------------------------------------------\n");
    do{
    printf("Digite o segundo n�mero: ");
    scanf("%i", &num2);
    if(num2<0){
        printf("O n�mero digitado tem que ser positivo!\n");
    }else if(num2<num1){
        printf("O segundo n�mero precisa ser maior que o primeiro!\n");
    }else if(num2==num1){
        printf("O segundo n�mero n�o pode ser igual ao primeiro!\n");
    }
    }while(num2<0 || num2<num1 || num2==num1);
    printf("\nOs n�meros entre %i e %i s�o:\n", num1, num2);
    for(cont=num1+1; cont<num2; cont++)
    {
        printf("%i ", cont);
    }
    printf("\n");
}
#endif // ex2
