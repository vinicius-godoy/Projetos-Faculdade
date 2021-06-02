#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef ex1
/*1. Escreva um programa que receba via teclado 2 numeros inteiros e
imprima-os no video com o resultado das 4 operacoes aritmeticas.*/
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int num1, num2;

    do{
    printf("Realize as quatro operações\n");
    printf("Digite um número: ");
    scanf("%d", &num1);
    printf("Digite um segundo número: ");
    scanf("%d", &num2);

    printf("\nOperações\n");
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
    printf("%d / %d = %g\n", num1, num2, (float)num1 / (float)num2);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex1

#ifdef ex2
/*2. Reescreva o exercicio anterior utilizando operadores de atribuicao
composta.*/
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int num1, num2;
    int soma, sub, mult;
    float divi;

    do{
    printf("Realize as quatro operações\n");
    printf("Digite um número: ");
    scanf("%d", &num1);
    soma = num1;
    sub = num1;
    mult = num1;
    divi = num1;
    printf("Digite um segundo número: ");
    scanf("%d", &num2);
    soma += num2;
    sub -= num2;
    mult *= num2;
    divi /= (float)num2;

    printf("\nOperações\n");
    printf("%d + %d = %d\n", num1, num2, soma);
    printf("%d - %d = %d\n", num1, num2, sub);
    printf("%d * %d = %d\n", num1, num2, mult);
    printf("%d / %d = %g\n", num1, num2, divi);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex2

#ifdef ex3
/*3. Escreva um programa que receba via teclado 2 numeros inteiros e execute
as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
video no formato decimal e hexadecimal.*/
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int num1, num2;

    do{
    printf("Realize as operações lógicas AND, OR e XOR\n");
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número : ");
    scanf("%d", &num2);

    printf("\nOperações Lógicas\n");
    printf("AND %-2d & %2d = %-3d x0%-4x\n", num1, num2, num1 & num2, num1 & num2);
    printf("OR  %-2d | %2d = %-3d x0%-4x\n", num1, num2, num1 | num2, num1 | num2);
    printf("XOR %-2d ^ %2d = %-3d x0%-4x\n", num1, num2, num1 ^ num2, num1 ^ num2);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex3

#ifdef ex4
/*Escreva um programa que receba um numero inteiro via teclado, divida-o
por 8 e multiplique-o por 8 utilizando os operadores de deslocamento.
Imprima no video o numero recebido e os resultados obtidos.*/
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int num, div8, mult8, i;

    do{
    printf("Digite um número para divídi-lo e multiplicá-lo por 8: ");
    scanf("%d", &num);

    div8 = num;
    div8 >>= 3;
    mult8 = num;
    mult8 <<= 3;

    printf("\n");
    printf("%-3d >> 3 = %-4d x0%-4x \n", num, div8, div8);
    printf("%-3d << 3 = %-4d x0%-4x \n", num, mult8, mult8);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex4

#ifdef ex5
/*Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
data (dia, mes e ano) atual.*/
int validarData(int dia, int mes, int ano)
{
    int bissexto = 0;

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){bissexto = 1;}

    if(ano < 1583){return 0;} //Verificar ano
    if(mes < 1 || mes > 12){return 0;} //Verificar mês
    //Verificar dia
    if(mes == 2 && bissexto == 1){if(dia < 1 || dia > 29){return 0;}}
    if(mes == 2){if(dia < 1 || dia > 28){return 0;}}
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){if(dia < 1 || dia > 30){return 0;}}
    else{if(dia < 1 || dia > 31){return 0;}}

    return 1;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int dia1, mes1, ano1,
        dia2, mes2, ano2;
    int dia, mes, ano;

    do{
    printf("Determine sua idade exata!\n");
    printf("Digite sua data de nascimento(DD/MM/AAAA): ");
    do{
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    if(validarData(dia1, mes1, ano1) == 0){
        printf("\aVocê colocou uma data inválida! Escreve novamente!\n");}
    }while(validarData(dia1, mes1, ano1) == 0);
    printf("Digite a data atual(DD/MM/AAAA): ");
    do{
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    if(validarData(dia2, mes2, ano2) == 0){
        printf("\aVocê colocou uma data inválida! Escreve novamente!\n");}
    }while(validarData(dia1, mes1, ano1) == 0);

    if(dia2 < dia1){
        if (mes2 == 3){
            //Verifica se o ano é bissexto
            if ((ano2 % 4 == 0 && ano2 % 100 != 0) || (ano2 % 400 == 0)){dia2 += 29;}
            else{dia2 += 28;}
        }
        //Pegar dias de Abril, Junho, Setembro ou Novembro
        else if (mes2 == 5 || mes2 == 7 || mes2 == 10 || mes2 == 12){dia2 += 30;}
        //Pegar dias de Janeiro, Março, Maio, Julho, Agosto, Outubro ou Dezembro
        else{dia2 += 31;}
        mes2 -= 1;
    }
    if(mes2 < mes1){
        mes2 += 12;
        ano2 -= 1;
    }

    //Calcula quanto tempo se passou
    dia = dia2 - dia1;
    mes = mes2 - mes1;
    ano = ano2 - ano1;

    printf("\nA sua idade exata é de %d anos, %d meses e % d dias!\n", ano, mes, dia);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex5

#ifdef ex6
/*6 - Escreva um programa para determinar o dia da semana de uma determinada
data (dia, mes e ano).*/
int diasemana(int d, int m, int a)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    a -= m < 3;
    return ( a + a/4 - a/100 + a/400 + t[m - 1] + d) % 7;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int dia, mes, ano, diaDaSem;

    do{
    printf("Digite a data para saber seu dia da semana (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    diaDaSem = diasemana(dia, mes, ano);

    switch(diaDaSem)
    {
    case 0:
        printf("\nEssa data foi ou será um Domingo!\n");
        break;
    case 1:
        printf("\nEssa data foi ou será uma Segunda-Feira!\n");
        break;
    case 2:
        printf("\nEssa data foi ou será uma Terça-Feira!\n");
        break;
    case 3:
        printf("\nEssa data foi ou será uma Quarta-Feira!\n");
        break;
    case 4:
        printf("\nEssa data foi ou será uma Quinta-Feira!\n");
        break;
    case 5:
        printf("\nEssa data foi ou será uma Sexta-Feira!\n");
        break;
    case 6:
        printf("\nEssa data foi ou será um Sábado!\n");
        break;
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex6
