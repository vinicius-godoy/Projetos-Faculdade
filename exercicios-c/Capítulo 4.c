#define ex5
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef ex1
/*1 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3                                       */
void main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    char nome1[8], nome2[8], nome3[8], nome4[8], nome5[8], resp;

    do{
    printf("Digite 5 nomes de até 7 caracteres\n");
    printf("nome1[] = ");
    scanf("%s", &nome1);
    printf("nome2[] = ");
    scanf("%s", &nome2);
    printf("nome3[] = ");
    scanf("%s", &nome3);
    printf("nome4[] = ");
    scanf("%s", &nome4);
    printf("nome5[] = ");
    scanf("%s", &nome5);

    system("cls");

    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-7s                                 %-7s   \n", nome1, nome5);
    printf("            %-7s             %-7s             \n", nome2, nome4);
    printf("                      %-7s                      \n", nome3);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex1

#ifdef ex2
/* 2 - Escreva um programa para receber 3 strings de ate 10 caracteres cada via
    teclado e imprima-as no video no seguinte formato:
    (utilize vetores multidimensionais)

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        string1             string2             string3 */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char c[3][11], resp;

    do{
    printf("Digite um nome de até 10 caracteres:\n");
    scanf("%s", &c[0]);

    printf("Digite o segundo nome:\n");
    scanf("%s", &c[1]);

    printf("Digite o terceiro nome:\n");
    scanf("%s", &c[2]);

    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-10s          %-10s          %-10s\n", c[0], c[1], c[2]);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}

#endif // ex2

#ifdef ex3
/*3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
para letras maiusculas. */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char texto[11], resp;
    int i;

    do{
    printf("Digite uma cadeia de 10 caracteres: ");
    scanf("%s", &texto);
    for(i = 0; i < 10; i++){
        if(texto[i] > 96 && texto[i] < 123){
            texto[i] -= 32;
        }
    }
    printf("Sua cadeia de 10 caracteres em letra maiúscula é: %s\n", texto);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex3

#ifdef ex4
/* 4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char c[11], resp;
    int i;

    do{
    printf("Digite uma cadeia de 10 caracteres:\n");
    gets(c);

    for(i=0;i<10;i++){
        if(c[i] > 64 && c[i] < 91){
            c[i] += 32;
        }
    }

    printf("Sua cadeia de caracteres em minúsculo é: %s\n", c);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex4

#ifdef ex5
/*5 - Receba 2 string de ate 10 caracteres via teclado, compare-as mostrando como
resultado se são IGUAIS ou DIFERENTES. */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char texto[2][11], resp;
    int i, igual;

    do{
    printf("Digite 2 strings de até 10 caracteres\n");
    printf("Primeira String: ");
    scanf("%s", &texto[0]);
    printf("Segunda String : ");
    scanf("%s", &texto[1]);

    //compara as strings
    for(i = 0, igual = 0; texto[0][i] != '\0' || texto[1][i] != '\0'; i++){
        if(texto[0][i] == texto[1][i]){
            igual++;
        }
    }
    if(igual == i){
        printf("\nSuas Strings são iguais!\n\n");
    }else{
        printf("\nSuas Strings são diferentes!\n\n");}

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex5
