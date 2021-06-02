#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

#ifdef ex1
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado e imprima estes conteudos no video no seguinte
    formato.
             char, int, long, float, double
             unsigned char, unsigned int, unsigned long,

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long       */

struct tipos_dados{
    char a;
    int b;
    long c;
    float d;
    double e;
    unsigned char f;
    unsigned int g;
    unsigned long h;
};

void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    struct tipos_dados dados;

    do{
    printf("Entre com os dados abaixo:\n");
    fflush(stdin); //limpa o buffer para caso o usuário recomece o programa
    printf("Char          = ");
    scanf("%c", &dados.a);
    printf("Int           = ");
    scanf("%d", &dados.b);
    printf("Long          = ");
    scanf("%ld", &dados.c);
    printf("Float         = ");
    scanf("%f", &dados.d);
    printf("Double        = ");
    scanf("%lf", &dados.e);
    fflush(stdin); //limpa o buffer para o unsigned char não armazenar o ENTER do double acima
    printf("Unsigned char = ");
    scanf("%c", &dados.f);
    printf("Unsigned int  = ");
    scanf("%u", &dados.g);
    printf("Unsigned long = ");
    scanf("%lu", &dados.h);

    printf("\n");
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %c         %-5d     %-7ld             %-5.2f               %-6.4lf\n", dados.a, dados.b, dados.c, dados.d, dados.e);
    printf("          %c                   %-5u               %-5lu               \n", dados.f, dados.g, dados.h);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{menu = getch();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');system("cls");
    }while(menu == 'S' || menu == 's');
}
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos. Receba os dados pelo teclado e imprima-os no video. Faça um
    menu. (vetor de estruturas)
		nome, end, cidade, estado, cep*/

struct dados_pessoa{
    char nome[41];
    char end[51];
    char cidade[21];
    char estado[3];
    char cep[9];
};

void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    int i;
    static struct dados_pessoa pessoas[4];

    printf("MENU\n");
    printf("1. Entrar com os dados\n");
    printf("2. Ver os dados\n");
    printf("3. Sair\n");
    do{menu = getch();}while(menu != '1' && menu != '2' && menu != '3');
    system("cls");

    switch(menu)
    {
    case '1':
        for(i = 0; i < 4; i++){
            printf("Entre com os dados pedidos para 4 pessoas!\n");
            printf("Nome da %dº pessoa: ", i + 1);
            gets(pessoas[i].nome);
            printf("Endereço da %dº pessoa: ", i + 1);
            gets(pessoas[i].end);
            printf("Cidade da %dº pessoa: ", i + 1);
            gets(pessoas[i].cidade);
            printf("Estado da %dº pessoa(2 letras): ", i + 1);
            gets(pessoas[i].estado);
            printf("CEP da %dº pessoa(Sem traços ou pontos): ", i + 1);
            gets(pessoas[i].cep);
            system("cls");
        }
        system("cls");
        printf("\aTODOS OS DADOS FORAM INSERIDOS!\n");
        printf("\nPressione 'B' para voltar ao menu\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b');
        if(menu == 'B' || menu == 'b'){system("cls");main();}
        break;
    case '2':
        printf("Dados do sistema\n");
        for(i = 0; i < 4; i++){
            printf("Nome da %dº pessoa:                      %50s\n", i + 1, pessoas[i].nome);
            printf("Endereço da %dº pessoa:                  %50s\n", i + 1, pessoas[i].end);
            printf("Cidade da %dº pessoa:                    %50s\n", i + 1, pessoas[i].cidade);
            printf("Estado da %dº pessoa:                    %50s\n", i + 1, pessoas[i].estado);
            printf("CEP da %dº pessoa:                       %50s\n", i + 1, pessoas[i].cep);
            printf("-----------------------------------------------------------------------------------\n");
        }
        printf("\nPressione 'B' para voltar ao menu\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b');
        if(menu == 'B' || menu == 'b'){system("cls");main();}
        break;
    case '3':
        exit(EXIT_SUCCESS);
        break;
    }
}
#endif // ex2

#ifdef ex3
/*3 - Crie uma estrutura para representar as coordenadas de um ponto no plano
    (posicoes X e Y). Em seguida, declare e leia do teclado um ponto e exiba a
    distancia dele ate' a origem das coordenadas, isto é, posição (0, 0). Para
    realizar o cálculo, utilize a fórmula a seguir:
           d = raiz quadrada de  (XB - XA)ao 2 +(YB -YA)ao 2
    Em que:
    d = distância entre os pontos A e B
    X = coordenada X em um ponto
    Y = coordenada Y em um ponto*/

struct plano_cart{
    float x;
    float y;
}coords;

void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    float d;

    do{
    fflush(stdin); //limpa o buffer para eventuais repetições do programa
    printf("Digite uma coordenada no formato \"num;num\" para saber a distância dela da origem: ");
    scanf("%f;%f", &coords.x, &coords.y);
    d = sqrt(((0 - coords.x)*(0 - coords.x))+ ((0 - coords.y)*(0 - coords.y)));
    printf("\nA distância da coordenada (%g; %g) é igual a %g\n", coords.x, coords.y, d);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{menu = getch();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');system("cls");
    }while(menu == 'S' || menu == 's');
}
#endif // ex3
