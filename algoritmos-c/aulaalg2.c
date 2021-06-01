#define ex1
#include<stdio.h>
#include<locale.h>

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int y, par;
    unsigned int num;
    printf("Digite a quantidade de termos que irão aparecer da tabuada do 2: ");
    scanf("%i", &num);
    for(y = 0, par = 2; num != y; y++, par += 2){
        if(num - 1 == y){
        printf("%i.", par);
        }else{
        printf("%i, ", par);
        }
    }
    return 0;
}
#endif // ex1

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    int lado1, lado2, lado3, soma1, soma2, soma3; //variáveis dos três lados e suas somas possíveis
    do{
    printf("Digite os três lados de um triângulo para saber se ele é isóscele, equilátero ou escaleno:\n");
    scanf("%i %i %i", &lado1, &lado2, &lado3);
    soma1=lado2 + lado3; //faz a conta dos lados do triângulo para garantir sua existência
    soma2=lado1 + lado3;
    soma3=lado1 + lado2;
    if(lado1>soma1 || lado2>soma2 || lado3>soma3){
        printf("Estas medidas indicam um triângulo inexistente, digite outros valores!\n\n");
    }
    }while(lado1>soma1 || lado2>soma2 || lado3>soma3); /*pede os lados de novo caso algum lado seja maior que
    a soma dos outros dois lados */
    if(lado1==lado2 && lado2==lado3){ //verifica se tem todos os lado iguais
        printf("O seu triângulo é equilátero!");
    }else{
        if(lado1!=lado2 && lado2!=lado3){ //verifica se tem todos os lado diferentes
        printf("O seu triângulo é escaleno!");
        }else{ //caso contrário ele será isóscele
        printf("O seu triângulo é isóscele!");
        }
    }
    return 0;
}
#endif // ex2
