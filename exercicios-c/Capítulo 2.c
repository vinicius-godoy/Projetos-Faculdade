#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#ifdef ex1
/* 1. Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
comando if-else. */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int chute, max, min, i;

    do{
    chute = 50;max = 99;min = 0;
    printf("Pense em um n�mero e me ajude a descobrir.\n");
    printf("Utilize > para aumentar o n�mero.\nUtilize < para diminuir o n�mero.\nUtilize = quando o n�mero estiver certo.\n\n");

    for(i = 1; resp != '='; i++){
        printf("\nSeu n�mero � %-2d ?\n", chute);
        printf("Maior, menor ou igual: ");
        do{
        resp = getche();
        if(resp == '='){
            printf("\a\n\nObrigado por cooperar! O programa acertou o seu n�mero '%d' em %d tentativas!\n", chute, i);}
        else if(resp == '<'){
            max = chute-1;
            chute = min + ((max-min)/2);}
        else if(resp == '>'){
            min = chute+1;
            chute = min + ((max-min)/2);}
        else{
            printf("\a\nO operador '%c' n�o funciona! Utilize '<', '>' ou '='!\n", resp);}
        }while(resp != '<' && resp != '>' && resp != '=');
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex1

#ifdef ex2
/* 2. Resecreva o programa do execicio anterior agora utilizando o comando switch.
Conte o n. de tentativas e imprima o resultado no video. */
main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int chute, max, min, i;

    do{
    chute = 50;max = 99;min = 0;
    printf("Pense em um n�mero e me ajude a descobrir.\n");
    printf("Utilize > para aumentar o n�mero.\nUtilize < para diminuir o n�mero.\nUtilize = quando o n�mero estiver certo.\n\n");

    for(i = 1; resp != '='; i++){
        printf("\nSeu n�mero � %-2d ?\n", chute);
        printf("Maior, menor ou igual: ");
        do{
        resp = getche();
        switch(resp)
        {
        case '<':
            max = chute-1;
            chute = min + ((max-min)/2);
            break;
        case '>':
            min = chute+1;
            chute = min + ((max-min)/2);
            break;
        case '=':
            printf("\a\n\nObrigado por cooperar! O programa acertou o seu n�mero '%d' em %d tentativas!\n", chute, i);
            break;
        default:
            printf("\a\nO operador '%c' n�o funciona! Utilize '<', '>' ou '='!\n", resp);
        }
        }while(resp != '<' && resp != '>' && resp != '=');
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex2

#ifdef ex3
/*3. De um modo geral, as liga��es telef�nicas s�o cobradas pelas suas dura��es.
O sistema registra os instantes em que a liga��o foi iniciada e conclu�da.
Escreva um programa que recebe via teclado dois instantes dados em
horas, minutos e segundo e determina o intervalo de tempo
(em horas, minutos e segundos) decorrido entre eles. */

void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int h1, min1, seg1, h2, min2, seg2, segundos1, segundos2,inth, intm, ints;

    do{
    printf("Digite o hor�rio em que voc� come�ou a liga��o (HH:MM:SS):\n");
    scanf("%d:%d:%d", &h1, &min1, &seg1);
    printf("Agora digite o hor�rio em que voc� terminou a liga��o (HH:MM:SS):\n");
    scanf("%d:%d:%d", &h2, &min2, &seg2);

    //passa os hor�rios para segundos
    segundos2 = (h2*3600) + (min2*60) + seg2;
    segundos1 = (h1*3600) + (min1*60) + seg1;
    segundos2 -= segundos1;

    //converte o intervalo para horas, minutos, segundos
    inth = segundos2/3600;
    segundos2 -= (3600*inth);
    intm = segundos2/60;
    segundos2 -= (60*intm);
    ints = segundos2;

    printf("Voc� passou %d:%d:%d em liga��o\n", inth, intm, ints);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex3

#ifdef ex4
/* Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados. */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int soma=0,cont=0,i;
    float media;

    do{
    printf("Digite n�meros positivos para som�-los e um n�mero negativo para fazer sua m�dia!\n");
    while(i > 0){
        printf("Digite um n�mero: ");
        scanf("%i", &i);
        if (i > 0){
            soma += i;
            cont++;}
    }
    media = (float)soma / (float)cont;
    printf("A m�dia dos n�meros positivos que voc� escreveu �: %.2f.\n", media);
    soma = 0; cont = 0; i = 1;

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex4

#ifdef ex5
/* 5. Escreva um programa que realize arredondamentos de n�meros utilizando a
seguinte regra:
- se a parte fracionaria for menor ou igual a 0,24 o n. e' arredonda para 0
- se a parte fracionaria for maior ou igual a 0,25 e menor ou igual a 0,74
o numero e' arredondado para 0,5
- se a parte fracionaria for maior ou igual a 0,75 o numero e' arredondado
para o inteiro imediatamente superior */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    float num, decimal;
    int aux;

    do{
    printf("Digite um n�mero decimal(com v�rgula) para arredond�-lo: ");
    scanf("%f", &num);
    aux = num;
    decimal = num - aux;
    if(decimal <= 0.24){
        decimal = aux;
    }else if(decimal >= 0.25 && decimal <= 0.74){
        decimal = aux + 0.5;
    }else{
        decimal = aux + 1;
    }
    printf("O n�mero %g arredondado � igual a %g\n", num, decimal);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex5
