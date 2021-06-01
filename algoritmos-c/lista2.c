#define ex2
#include<stdio.h>
#include<locale.h>
#include<math.h>

/*1. Gere e exiba cada uma das seqüências abaixo com uma quantidade k de termos determinados
pelo usuário.
a. 3, 6, 9, 12, 15,...
b. 1/4, 1/8, 1/12, 1/16, 1/20,...                */

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    //variáveis do número de termos, contador, tabuada do 3 e fração de múltiplos de 4
    int numt, cont, tab3, frc4;
    printf("Digite a quantidade de termos que irão aparecer das sequências: ");
    scanf("%i", &numt);
    for(cont = 0, tab3 = 3; numt != cont; cont++, tab3 += 3){
        if(numt - 1 == cont){
        printf("%i.", tab3);
        }else{
        printf("%i, ", tab3);
        }
    }
        printf("\n\n");
    for(cont = 0, frc4 = 4; numt != cont; cont++, frc4 += 4){
        if(numt - 1 == cont){
        printf("1/%i.", frc4);
        }else{
        printf("1/%i, ", frc4);
        }
    }
    printf("\n");
    return 0;
}
#endif // ex1

/*2. Gere e exiba cada uma das seqüências abaixo com uma quantidade k de termos determinados
pelo usuário.
a)	2/5, 4/10, 6/15, 8/20, 10/25, 12/30,...
b)	4/8, 1, 36/24, 2, 100/40, 144/48,...                                        */

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int numt, cont, tab2, tab5, tab8;
    printf("Digite a quantidade de termos que irão aparecer das sequências: ");
    scanf("%i", &numt);
    for(cont = 0, tab2 = 2, tab5 = 5; numt != cont; cont++, tab2 += 2, tab5 += 5){
        if(numt - 1 == cont){
        printf("%i/%i.", tab2, tab5);
        }else{
        printf("%i/%i, ", tab2, tab5);
        }
    }
        printf("\n\n");
    for(cont= 0, tab2 = 2, tab8 = 8; numt != cont; cont++, tab2 += 2, tab8 += 8){
        if((tab2*tab2)%tab8 == 0) {
            if(numt - 1 == cont){
                printf("%i.", (tab2*tab2)/tab8);
            }else{
            printf("%i, ", (tab2*tab2)/tab8);
            }
        }else{
            if(numt - 1 == cont){
            printf("%i/%i.", tab2*tab2, tab8);
            }else{
            printf("%i/%i, ", tab2*tab2, tab8);
            }
        }
    }
    return 0;
}
#endif // ex2

/*3. Receba a quantidade de idades de K indivíduos. K representa essa quantidade e deve ser
digitada pelo usuário. A variável Idade armazena cada uma das K idades digitadas. Calcule e
mostre a somatória dessas idades.    */

#ifdef ex3
int main()
{
    setlocale(LC_ALL,"portuguese");
    int numt, cont, idade, somaid;
    printf("Digite a quantidade de idade de pessoas que gostaria de somar: ");
    scanf("%i", &numt);
    printf("Agora digite as idades destas pessoas\n");
    for (cont = 0, idade = 0, somaid = 0; cont != numt; cont++){
        if(cont == 0){
        printf("Digite uma idade: ");
        scanf("%i", &idade);
        somaid += idade;
        }else{
        printf("Digite outra idade: ");
        scanf("%i", &idade);
        somaid += idade;
        }
        if(cont == numt - 1){
        printf("A soma das idades que você digitou é: %i", somaid);
        }
    }
    return 0;
}
#endif // ex3

/*4. Calcule e mostre a média dos K primeiros pares e múltiplos de cinco.
OBS: K representa a quantidade de números pares solicitados via teclado pelo usuário.
Os números pares deverão ser gerados pelo programador.2, 4, 6, 8, 10,...*/

#ifdef ex4
int main()
{
    setlocale(LC_ALL, "portuguese");
    int k, soma, i;
    printf("Digite a quantidade de números pares e múltiplos de 5 que deverão ter sua média calculada: ");
    scanf("%i", &k);
    for (i = 1, soma = 0; i != 2*k+1; i++){
        if(cont%2 == 0){
            printf("%i ", i);
            if(cont%5 == 0){
                soma = soma + i;}
        }
    }
    printf("A média dos números pares e múltiplos de 5 é de: %f", soma/)
}
#endif // ex4

/*5. Receba K números. Exiba a quantidade de números pares negativos e quantas vezes o número
zero foi digitado.
OBS1: K representa a quantidade de números digitados pelo usuário.
OBS2: A variável Num representa cada número digitado pelo usuário. */

#ifdef ex5
int main()
{
    setlocale(LC_ALL, "portuguese");
    int k,
}
#endif // ex5
