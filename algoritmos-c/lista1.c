#define ex1
#include<locale.h>
#include<stdio.h>

/*1. Ler um número inteiro e imprimir seu sucessor e seu antecessor. */

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num,ant,suc;
    printf("Digite um número inteiro para saber seu antecessor e sucessor: ");
    scanf("%i", &num);
    ant=num-1;
    suc=num+1;
    printf("O antecessor de %i é %i e o sucessor é %i\n", num, ant, suc);
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
    {printf("Você digitou um valor de produto inválido!\n\n");}
    }while(val<=0);
    printf("O valor reajustado do produto é %g\n", valreaj);
    return 0;
}
#endif // ex2

/* 3.	Informar um preço de um produto e calcular novo preço com desconto de 9%. */

#ifdef ex3
int main()
{
    setlocale(LC_ALL, "portuguese");
    float prc, desc;
    do{
    printf("Digite o valor do produto para saber seu preço após o desconto de 9%%: ");
    scanf("%g", &prc);
    desc=prc*0.91;
    if(prc<=0)
    {printf("Você digitou um preço de produto inválido!\n\n");}
    }while(prc<=0);
    printf("O valor do produto após o desconto é de %gR$\n", desc);
    return 0;
}
#endif // ex3

/*4. Cálculo de um salário líquido de um professor. Serão fornecidos valor da hora aula, número de aulas dadas e o % de desconto do INSS.*/

#ifdef ex4
int main()
{
    setlocale(LC_ALL, "portuguese");
    float valh, inss, sal, desc;
    int numh;
    printf("Digite os valores pedidos para saber seu salário líquido\n");
    printf("Digite o valor da sua hora/aula: ");
    scanf("%f", &valh);
    printf("Digite o número de aulas dadas: ");
    scanf("%i", &numh);
    printf("Digite o desconto do INSS: ");
    scanf("%f", &inss);
    desc=(inss/100)*(valh*numh);
    sal=(valh*numh)-desc;
    printf("O seu salário liquído é de %gR$", sal);
    return 0;
}
#endif // ex4

/*5. Ler uma temperatura em graus Celsius e transformá-la em graus Fahrenheit.*/

#ifdef ex5
int main()
{
    setlocale(LC_ALL, "portuguese");
    float tempc, tempf;
    printf("Digite uma temperatura em Celsius para recebê-la em Fahrenheit: ");
    scanf("%f", &tempc);
    tempf=(tempc*9/5)+32;
    printf("%g graus Celsius são %g graus Fahrenheit",tempc, tempf);
    return 0;
}
#endif // ex5

/* 6.	Faça um programa que receba o ano do nascimento de uma pessoa e o ano atual, calcule e mostre:
a.	A idade dessa pessoa
b.	Quantos anos essa pessoa terá em 2034. */


#ifdef ex6
int main()
{
    setlocale(LC_ALL, "portuguese");
    int nasc, anoatual, idade, id2034;
    do{
    printf("Digite as informações pedidas para saber sua idade atualmente e em 2034.\n");
    printf("\tDigite seu ano de nascimento: ");
    scanf("%i", &nasc);
    printf("\tDigite o ano atual: ");
    scanf("%i", &anoatual);
    idade = anoatual - nasc;
    id2034 = 2034 - nasc;
    if(idade<=0)
    {printf("Coloque um ano de nascimento e ano atual válidos!\n\n");}
    }while(idade<=0);
    if(idade>0);
    {printf("Você tem %i anos de idade e em 2034 terá %i anos de idade.\n", idade, id2034);}
    return 0;
}
#endif // ex6

/*7. O custo ao consumidor de um carro novo é a soma do preço da fábrica com o percentual de lucro do distribuidor e dos
impostos aplicados ao preço de fábrica. Faça um programa que receba o preço de fábrica de um veículo, o percentual de lucro
do distribuidor e o percentual de impostos. Calcule e mostre:
a.	O valor correspondente ao lucro do distribuidor
b.	O valor correspondente aos impostos
c.	O preço final do veículo */

#ifdef ex7
int main()
{
    setlocale(LC_ALL,"portuguese");
    float prci, pctl, pcti, vlrl, vlri, prcf;
    printf("Calcule o preço final do seu carro\n");
    printf("\tDigite o preço de fábrica do carro: ");
    scanf("%f", &prci);
    printf("\tAgora digite o percentual de lucro do distribuidor: ");
    scanf("%f", &pctl);
    printf("\tFinalmente, digite o percentual de impostos: ");
    scanf("%f", &pcti);
    vlrl = (pctl / 100) * prci;
    vlri = (pcti / 100) * prci;
    prcf = prci + vlrl + vlri;
    printf("O preço final do seu carro será de %gR$.", prcf);
    return 0;
}
#endif // ex7

/*8. Elabore um programa que efetue o cálculo do reajuste de salário de um funcionário. Considere que o funcionário deve
receber um reajuste de 15% caso seu salário seja menor que 800 reais. Se o salário for maior ou igual a 800 e menor ou igual
a 1000, seu reajuste será de 10 %; caso seja maior que 1000, o reajuste deve ser de 5%. Ao final do programa deve apresentar
o valor antigo e o novo salário. */

#ifdef ex8
int main()
{
    setlocale(LC_ALL, "portuguese");
    float sala, saln;
    do{
    printf("Digite o seu salário atual para saber seu salário reajustado: ");
    scanf("%f", &sala);
    if(sala<=0){
            printf("Digite um salário válido!\n\n");
    }
    }while(sala<=0);
    if(sala<800)
    {
        saln = sala * 1.15;
        printf("O seu salário reajustado será de %gR$", saln);
    }else{
        if(sala>=800 && sala<=1000){
        saln = sala * 1.1;
        printf("O seu salário reajustado será de %gR$", saln);
    }else{
        saln = sala * 1.05;
        printf("O seu salário reajustado será de %gR$", saln);
    }
    }
    return 0;
}
#endif // ex8

/*9. Leia quatro valores referentes às notas escolares de um aluno e exiba uma mensagem dizendo que ele foi aprovado se a
média for maior ou igual a 5. Caso contrário informe que ele está reprovado. Apresente junto à mensagem o valor da média
obtida pelo aluno independente de ter sido aprovado ou não. As notas deverão ser maiores ou iguais a zero e menores ou
iguais a dez. */

#ifdef ex9
int main()
{
    setlocale(LC_ALL, "portuguese");
    float nota1, nota2, nota3, nota4, media;
    do{
    printf("Digite suas quatro notas do bimestre para saber se você foi aprovado e sua média: \n");
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
    if(nota1<0 || nota1>10 || nota2<0 || nota2>10 || nota3<0 || nota3>10 || nota4<0 || nota4>10){
        printf("Você digitou notas inválidas!\n\n");
    }
    }while(nota1<0 || nota1>10 || nota2<0 || nota2>10 || nota3<0 || nota3>10 || nota4<0 || nota4>10);
    media = (nota1 + nota2 + nota3 + nota4) / 4;
    if(media >= 5){
        printf("Parábens ! Você foi aprovado com média %g", media);
    }else{
        printf("Infelizmente você foi reprovado com média %g", media);
    }
    return 0;
}
#endif // ex9

/*10. Receba dois números, o primeiro deve ser maior que 10 e menor que 25, o segundo deve ser maior ou igual a zero, o
terceiro deve ser a soma dos dois primeiros e o quarto é o produto dos três números anteriores. Calcule e exiba a soma dos
quadrados de cada um dos quatro números. Caso o resultado seja menor que 50000, solicite novos dados. */

#ifdef ex10
int main()
{
    setlocale(LC_ALL, "portuguese");
    float num1, num2, num3, num4, num5;
    do{
    printf("Digite dois números com condições secretas\n");
    do{
        printf("Digite o primeiro número: ");
        scanf("%f", &num1);
        if(num1<10 || num1>25){
            printf("Você errou o primeiro número. Tente novamente\n");
        }
    }while(num1<10 || num1>25);
    do{
        printf("Digite o segundo número: ");
        scanf("%f", &num2);
        if(num2<0){
            printf("Você errou o segundo número. Tente novamente\n");
        }
    }while(num2<0);
    num3 = num1 + num2;
    num4 = num1 * num2 * num3;
    num5 = (num1*num1) + (num2*num2) + (num3*num3) + (num4*num4);
    if(num5>50000){
        printf("Parábens, você conseguiu alcançar a condição do quinto número ! Seu resultado foi de %f!", num5);
    }
    else{
        printf("Você falhou em alcançar a condição do quinto número ! Tente novamente.\n\n");
    }
    }while(num5<50000);
    return  0;
}
#endif // ex10
