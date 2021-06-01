#define ex1
#include<locale.h>
#include<stdio.h>

/*1. Ler um n�mero inteiro e imprimir seu sucessor e seu antecessor. */

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num,ant,suc;
    printf("Digite um n�mero inteiro para saber seu antecessor e sucessor: ");
    scanf("%i", &num);
    ant=num-1;
    suc=num+1;
    printf("O antecessor de %i � %i e o sucessor � %i\n", num, ant, suc);
    return 0;
}
#endif // 1

/*2. Receber um valor qualquer do teclado e imprimir esse valor com reajuste de 10%. */

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    float val, valreaj;
    do{
    printf("Digite o valor do produto para receber seu reajuste: ");
    scanf("%g", &val);
    valreaj=val*1.1;
    if(val<=0)
    {printf("Voc� digitou um valor de produto inv�lido!\n\n");}
    }while(val<=0);
    printf("O valor reajustado do produto � %g\n", valreaj);
    return 0;
}
#endif // ex2

/* 3.	Informar um pre�o de um produto e calcular novo pre�o com desconto de 9%. */

#ifdef ex3
int main()
{
    setlocale(LC_ALL, "portuguese");
    float prc, desc;
    do{
    printf("Digite o valor do produto para saber seu pre�o ap�s o desconto de 9%%: ");
    scanf("%g", &prc);
    desc=prc*0.91;
    if(prc<=0)
    {printf("Voc� digitou um pre�o de produto inv�lido!\n\n");}
    }while(prc<=0);
    printf("O valor do produto ap�s o desconto � de %gR$\n", desc);
    return 0;
}
#endif // ex3

/*4. C�lculo de um sal�rio l�quido de um professor. Ser�o fornecidos valor da hora aula, n�mero de aulas dadas e o % de desconto do INSS.*/

#ifdef ex4
int main()
{
    setlocale(LC_ALL, "portuguese");
    float valh, inss, sal, desc;
    int numh;
    printf("Digite os valores pedidos para saber seu sal�rio l�quido\n");
    printf("Digite o valor da sua hora/aula: ");
    scanf("%f", &valh);
    printf("Digite o n�mero de aulas dadas: ");
    scanf("%i", &numh);
    printf("Digite o desconto do INSS: ");
    scanf("%f", &inss);
    desc=(inss/100)*(valh*numh);
    sal=(valh*numh)-desc;
    printf("O seu sal�rio liqu�do � de %gR$", sal);
    return 0;
}
#endif // ex4

/*5. Ler uma temperatura em graus Celsius e transform�-la em graus Fahrenheit.*/

#ifdef ex5
int main()
{
    setlocale(LC_ALL, "portuguese");
    float tempc, tempf;
    printf("Digite uma temperatura em Celsius para receb�-la em Fahrenheit: ");
    scanf("%f", &tempc);
    tempf=(tempc*9/5)+32;
    printf("%g graus Celsius s�o %g graus Fahrenheit",tempc, tempf);
    return 0;
}
#endif // ex5

/* 6.	Fa�a um programa que receba o ano do nascimento de uma pessoa e o ano atual, calcule e mostre:
a.	A idade dessa pessoa
b.	Quantos anos essa pessoa ter� em 2034. */


#ifdef ex6
int main()
{
    setlocale(LC_ALL, "portuguese");
    int nasc, anoatual, idade, id2034;
    do{
    printf("Digite as informa��es pedidas para saber sua idade atualmente e em 2034.\n");
    printf("\tDigite seu ano de nascimento: ");
    scanf("%i", &nasc);
    printf("\tDigite o ano atual: ");
    scanf("%i", &anoatual);
    idade = anoatual - nasc;
    id2034 = 2034 - nasc;
    if(idade<=0)
    {printf("Coloque um ano de nascimento e ano atual v�lidos!\n\n");}
    }while(idade<=0);
    if(idade>0);
    {printf("Voc� tem %i anos de idade e em 2034 ter� %i anos de idade.\n", idade, id2034);}
    return 0;
}
#endif // ex6

/*7. O custo ao consumidor de um carro novo � a soma do pre�o da f�brica com o percentual de lucro do distribuidor e dos
impostos aplicados ao pre�o de f�brica. Fa�a um programa que receba o pre�o de f�brica de um ve�culo, o percentual de lucro
do distribuidor e o percentual de impostos. Calcule e mostre:
a.	O valor correspondente ao lucro do distribuidor
b.	O valor correspondente aos impostos
c.	O pre�o final do ve�culo */

#ifdef ex7
int main()
{
    setlocale(LC_ALL,"portuguese");
    float prci, pctl, pcti, vlrl, vlri, prcf;
    printf("Calcule o pre�o final do seu carro\n");
    printf("\tDigite o pre�o de f�brica do carro: ");
    scanf("%f", &prci);
    printf("\tAgora digite o percentual de lucro do distribuidor: ");
    scanf("%f", &pctl);
    printf("\tFinalmente, digite o percentual de impostos: ");
    scanf("%f", &pcti);
    vlrl = (pctl / 100) * prci;
    vlri = (pcti / 100) * prci;
    prcf = prci + vlrl + vlri;
    printf("O pre�o final do seu carro ser� de %gR$.", prcf);
    return 0;
}
#endif // ex7

/*8. Elabore um programa que efetue o c�lculo do reajuste de sal�rio de um funcion�rio. Considere que o funcion�rio deve
receber um reajuste de 15% caso seu sal�rio seja menor que 800 reais. Se o sal�rio for maior ou igual a 800 e menor ou igual
a 1000, seu reajuste ser� de 10 %; caso seja maior que 1000, o reajuste deve ser de 5%. Ao final do programa deve apresentar
o valor antigo e o novo sal�rio. */

#ifdef ex8
int main()
{
    setlocale(LC_ALL, "portuguese");
    float sala, saln;
    do{
    printf("Digite o seu sal�rio atual para saber seu sal�rio reajustado: ");
    scanf("%f", &sala);
    if(sala<=0){
            printf("Digite um sal�rio v�lido!\n\n");
    }
    }while(sala<=0);
    if(sala<800)
    {
        saln = sala * 1.15;
        printf("O seu sal�rio reajustado ser� de %gR$", saln);
    }else{
        if(sala>=800 && sala<=1000){
        saln = sala * 1.1;
        printf("O seu sal�rio reajustado ser� de %gR$", saln);
    }else{
        saln = sala * 1.05;
        printf("O seu sal�rio reajustado ser� de %gR$", saln);
    }
    }
    return 0;
}
#endif // ex8

/*9. Leia quatro valores referentes �s notas escolares de um aluno e exiba uma mensagem dizendo que ele foi aprovado se a
m�dia for maior ou igual a 5. Caso contr�rio informe que ele est� reprovado. Apresente junto � mensagem o valor da m�dia
obtida pelo aluno independente de ter sido aprovado ou n�o. As notas dever�o ser maiores ou iguais a zero e menores ou
iguais a dez. */

#ifdef ex9
int main()
{
    setlocale(LC_ALL, "portuguese");
    float nota1, nota2, nota3, nota4, media;
    do{
    printf("Digite suas quatro notas do bimestre para saber se voc� foi aprovado e sua m�dia: \n");
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
    if(nota1<0 || nota1>10 || nota2<0 || nota2>10 || nota3<0 || nota3>10 || nota4<0 || nota4>10){
        printf("Voc� digitou notas inv�lidas!\n\n");
    }
    }while(nota1<0 || nota1>10 || nota2<0 || nota2>10 || nota3<0 || nota3>10 || nota4<0 || nota4>10);
    media = (nota1 + nota2 + nota3 + nota4) / 4;
    if(media >= 5){
        printf("Par�bens ! Voc� foi aprovado com m�dia %g", media);
    }else{
        printf("Infelizmente voc� foi reprovado com m�dia %g", media);
    }
    return 0;
}
#endif // ex9

/*10. Receba dois n�meros, o primeiro deve ser maior que 10 e menor que 25, o segundo deve ser maior ou igual a zero, o
terceiro deve ser a soma dos dois primeiros e o quarto � o produto dos tr�s n�meros anteriores. Calcule e exiba a soma dos
quadrados de cada um dos quatro n�meros. Caso o resultado seja menor que 50000, solicite novos dados. */

#ifdef ex10
int main()
{
    setlocale(LC_ALL, "portuguese");
    float num1, num2, num3, num4, num5;
    do{
    printf("Digite dois n�meros com condi��es secretas\n");
    do{
        printf("Digite o primeiro n�mero: ");
        scanf("%f", &num1);
        if(num1<10 || num1>25){
            printf("Voc� errou o primeiro n�mero. Tente novamente\n");
        }
    }while(num1<10 || num1>25);
    do{
        printf("Digite o segundo n�mero: ");
        scanf("%f", &num2);
        if(num2<0){
            printf("Voc� errou o segundo n�mero. Tente novamente\n");
        }
    }while(num2<0);
    num3 = num1 + num2;
    num4 = num1 * num2 * num3;
    num5 = (num1*num1) + (num2*num2) + (num3*num3) + (num4*num4);
    if(num5>50000){
        printf("Par�bens, voc� conseguiu alcan�ar a condi��o do quinto n�mero ! Seu resultado foi de %f!", num5);
    }
    else{
        printf("Voc� falhou em alcan�ar a condi��o do quinto n�mero ! Tente novamente.\n\n");
    }
    }while(num5<50000);
    return  0;
}
#endif // ex10
