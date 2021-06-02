#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#ifdef ex1
/*1 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
    no video na funcao main(). Passe como informacao para a funcao a letra
    digitada.(utilize o comando return). O vetor deve ser uma variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

char c[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

int letra(char a){
    int i,x;
    for (i = 0;i <= 13; i++){
        if (c[i] == a){
            x = 1;}}

    if (x == 1){
        return 1;
    }else{
        return 0;}}

int main()
{
    inicio:
    setlocale(LC_ALL, "portuguese");
    char a,resp;

    printf("Digite uma letra e veja se ela esta contida no nosso vetor:");
    a = getche();

    if(letra(a) == 1){
        printf("\n\nA letra que voc� digitou FOI encontrada no nosso vetor!\nLetra digitada: %c.\nVetor: b,d,f,h,j,k,m,o,q,s,u,w,y.\n", a);
    }else{
        printf("\n\nA letra que voc� digitou N�O foi encontrada no nosso vetor!\nLetra digitada: %c.\nVetor: b,d,f,h,j,k,m,o,q,s,u,w,y.\n", a);}

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();

    if(resp == 'S' || resp == 's'){
        system("cls");
        goto inicio;
    }
}
#endif // ex1

#ifdef ex2

/*2 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima-os no video na funcao main().*/

int soma(int x, int y)
{
    int r;

    r = x + y;
    return r;
}

int sub(int x, int y)
{
    int r;

    r = x - y;
    return r;
}

int mult(int x, int y)
{
    int r;

    r = x * y;
    return r;
}

float divi(int x, int y)
{
    float r;

    r = (float)x / (float)y;
    return r;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int x,y,som,su,mul;
    float div;

    do{
    printf("Digite dois n�meros para realizar as quatro opera��es com eles: ");
    scanf("%i %i", &x,&y);

    som = soma(x,y);
    su = sub(x,y);
    mul = mult(x,y);
    div = divi(x,y);

    printf("\n%i + %i = %i.\n", x, y, som);
    printf("\n%i - %i = %i.\n", x, y, su);
    printf("\n%i * %i = %i.\n", x, y, mul);
    printf("\n%i / %i = %f.\n", x, y, div);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex2

#ifdef ex3
/*3. Reescreva o programa do exercicio anterior para receber via teclado n
valores. Os n valores nao sao definidos previamente.*/
int soma(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int mult(int a, int b)
{
    return a*b;
}
float divi(float a, float b)
{
    return (float)a/(float)b;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int i, n, val1, val2;
    int aux, aux1, aux2;
    float aux3;

    do{
    printf("Digite quantos valores voc� deseja que sejam calculados: ");
    do{
    scanf("%d", &n);
    if(n <= 1){printf("\aO n�mero m�nimo de valores � 2! Digite novamente!\n");}
    }while(n <= 1);

    printf("Digite o 1� valor: ");
    scanf("%d", &val1);
    printf("Digite o 2� valor: ");
    scanf("%d", &val2);
    aux = soma(val1,val2);
    aux1 = sub(val1,val2);
    aux2 = mult(val1,val2);
    aux3 = divi(val1,val2);

    for(i = 2; i < n; i++){
        printf("Digite o %d� valor: ", i+1);
        scanf("%d", &val1);
        aux = soma(aux, val1);
        aux1 = sub(aux1,val1);
        aux2 = mult(aux2,val1);
        aux3 = divi(aux3,val1);
    }

    printf("\nSOMA = %d\n", aux);
    printf("SUBTRA��O = %d\n", aux1);
    printf("MULTIPLICA��O = %d\n", aux2);
    printf("DIVIS�O = %f\n", aux3);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    fflush(stdin);resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex3

#ifdef ex4
/*4. Aproveitando o programa anterior inclua a selecao das operacoes aritmeticas
para transforma-lo em uma calculadora. (utilize o comando switch).*/
int soma(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int mult(int a, int b)
{
    return a*b;
}
float divi(float a, float b)
{
    return (float)a/(float)b;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int i, n, val1, val2;
    int aux, aux1, aux2;
    float aux3;

    do{
    printf("Digite quantos valores voc� deseja que sejam calculados: ");
    do{
    scanf("%d", &n);
    if(n == 1){printf("\aO n�mero m�nimo de valores � 2! Digite novamente!\n");}
    }while(n == 1);

    printf("Digite o 1� valor: ");
    scanf("%d", &val1);
    printf("Digite o 2� valor: ");
    scanf("%d", &val2);
    aux = soma(val1,val2);
    aux1 = sub(val1,val2);
    aux2 = mult(val1,val2);
    aux3 = divi(val1,val2);

    for(i = 2; i < n; i++){
        printf("Digite o %d� valor: ", i+1);
        scanf("%d", &val1);
        aux = soma(aux, val1);
        aux1 = sub(aux1,val1);
        aux2 = mult(aux2,val1);
        aux3 = divi(aux3,val1);
    }

    printf("\nPressione 1 para ver a soma destes valores\n");
    printf("Pressione 2 para ver a subtra��o destes valores\n");
    printf("Pressione 3 para ver a multiplica��o destes valores\n");
    printf("Pressione 4 para ver a divis�o destes valores\n");
    val2 = getch();

    refazer:
    switch(val2)
    {
    case '1':
        printf("\nSOMA = %d\n", aux);
        break;
    case '2':
        printf("\nSUBTRA��O = %d\n", aux1);
        break;
    case '3':
        printf("\nMULTIPLICA��O = %d\n", aux2);
        break;
    case '4':
        printf("\nDIVIS�O = %g\n", aux3);
        break;
    default:
        printf("\aEsse n�mero n�o indica nenhuma opera��o, escolha outra!\n");
        val2 = getch();
        goto refazer;
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    fflush(stdin);resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex4

#ifdef ex5
/*5. Escreva um programa que receba na funcao main() 2 strings de ate' 10 caracteres.
Escreva as funcoes que compare estas 2 strings e retorne se sao IGUAIS 1 e
se DIFERENTES 0. Declare as strings como variavel global.*/
char str1[11], str2[11];

int cmpstr(char str1[], char str2[])
{
    int i, igual;

    for(i = 0, igual = 0; str1[i] != '\0' || str2[i] != '\0'; i++){
        if(str1[i] == str2[i]){
            igual++;
        }
    }
    if(igual == i){
        return 1;
    }else{
        return 0;}
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int comparacao;

    do{
    printf("Digite duas strings de at� 10 caracteres para compar�-las\n");
    printf("Primeira String: ");
    scanf("%s", &str1);
    printf("Segunda String: ");
    scanf("%s", &str2);

    comparacao = cmpstr(str1, str2);
    if(comparacao == 1){
        printf("\nAs strings s�o iguais!\n");
    }else{
        printf("\nAs strings s�o diferentes!\n");}

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex5
