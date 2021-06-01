#define ex1
#include<stdio.h>
#include<locale.h>

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int y, par;
    unsigned int num;
    printf("Digite a quantidade de termos que ir�o aparecer da tabuada do 2: ");
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
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    int lado1, lado2, lado3, soma1, soma2, soma3; //vari�veis dos tr�s lados e suas somas poss�veis
    do{
    printf("Digite os tr�s lados de um tri�ngulo para saber se ele � is�scele, equil�tero ou escaleno:\n");
    scanf("%i %i %i", &lado1, &lado2, &lado3);
    soma1=lado2 + lado3; //faz a conta dos lados do tri�ngulo para garantir sua exist�ncia
    soma2=lado1 + lado3;
    soma3=lado1 + lado2;
    if(lado1>soma1 || lado2>soma2 || lado3>soma3){
        printf("Estas medidas indicam um tri�ngulo inexistente, digite outros valores!\n\n");
    }
    }while(lado1>soma1 || lado2>soma2 || lado3>soma3); /*pede os lados de novo caso algum lado seja maior que
    a soma dos outros dois lados */
    if(lado1==lado2 && lado2==lado3){ //verifica se tem todos os lado iguais
        printf("O seu tri�ngulo � equil�tero!");
    }else{
        if(lado1!=lado2 && lado2!=lado3){ //verifica se tem todos os lado diferentes
        printf("O seu tri�ngulo � escaleno!");
        }else{ //caso contr�rio ele ser� is�scele
        printf("O seu tri�ngulo � is�scele!");
        }
    }
    return 0;
}
#endif // ex2
