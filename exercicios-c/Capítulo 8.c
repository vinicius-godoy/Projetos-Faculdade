#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#ifdef ex1
/*1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned,float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros e o operador de conteudo *
    no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char                            */
void main()
{
    setlocale(LC_ALL, "portuguese");
    short  a;
    long   b;
    int    c;
    float  d;
    double e;
    char   f, menu;
    unsigned long g;
    unsigned char h;
    short  *pa = &a;
    long   *pb = &b;
    int    *pc = &c;
    float  *pd = &d;
    double *pe = &e;
    char   *pf = &f, *pmenu = &menu;
    unsigned long *pg = &g;
    unsigned char *ph = &h;

    do{
    fflush(stdin);
    printf("Digite os valores requisitados\n");
    printf("Valor do tipo Short: ");
    scanf("%hd", pa);
    printf("Valor do tipo Long: ");
    scanf("%ld", pb);
    printf("Valor do tipo Int: ");
    scanf("%d", pc);
    printf("Valor do tipo float: ");
    scanf("%f", pd);
    printf("Valor do tipo Double: ");
    scanf("%lf", pe);
    getchar();
    printf("Valor do tipo Char: ");
    *pf = getchar();
    //getchar();
    printf("Valor do tipo Unsigned Long: ");
    scanf("%lu", pg);
    getchar();
    printf("Valor do tipo Unsigned Char: ");
    scanf("%c", ph);

    printf("\n\n");
    printf("        10        20        30        40        50        60     \n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("    %-5hd               %-6ld               %-3d                  \n", *pa, *pb, *pc);
    printf("              %-5.2f               %-6.5lf             %-4c       \n", *pd, *pe, *pf);
    printf("         %-5d               %c                                    \n", *pg, *ph);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{*pmenu = getch();}while(*pmenu != 'S' && *pmenu != 's' && *pmenu != 'N' && *pmenu != 'n');system("cls");
    }while(*pmenu == 'S' || *pmenu == 's');
}
#endif // ex1

#ifdef ex2
/*2 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados pelo teclado usando ponteiros e imprima-os no video
    também usando ponteiros. Utilize um comando de loop. (vetor de estruturas)
                  nome, end, cidade, estado, cep                              */

struct dados_pessoa{
    char nome[41];
    char end[51];
    char cidade[21];
    char estado[3];
    char cep[9];
}pessoas[4], *ps;

void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    int i;
    char *pmenu = &menu;
    int *pi = &i;

    ps = pessoas;

    printf("---------MENU---------\n");
    printf("1. Entrar com os dados\n");
    printf("2. Ver os dados\n");
    printf("3. Sair\n");
    do{*pmenu = getch();}while(*pmenu != '1' && *pmenu != '2' && *pmenu != '3');
    system("cls");

    switch(*pmenu)
    {
    case '1':
        for(*pi = 0; *pi < 4; (*pi)++){
            printf("Entre com os dados pedidos para 4 pessoas!\n");
            printf("Nome da %dº pessoa: ", *pi + 1);
            gets((ps + *pi)-> nome);
            printf("Endereço da %dº pessoa: ", *pi + 1);
            gets((ps + *pi) -> end);
            printf("Cidade da %dº pessoa: ", *pi + 1);
            gets((ps + *pi) -> cidade);
            printf("Estado da %dº pessoa(2 letras): ", *pi + 1);
            gets((ps + *pi) -> estado);
            printf("CEP da %dº pessoa(Sem traços ou pontos): ", *pi + 1);
            gets((ps + *pi) -> cep);
            system("cls");
        }
        system("cls");
        printf("\aTODOS OS DADOS FORAM INSERIDOS!\n");
        printf("\nPressione 'B' para voltar ao menu\n");
        do{*pmenu = getch();}while(*pmenu != 'B' && *pmenu != 'b');
        if(*pmenu == 'B' || *pmenu == 'b'){system("cls");main();}
        break;
    case '2':
            printf("-------------------------------------------DADOS------------------------------------------\n");
        for(*pi = 0; *pi < 4; (*pi)++){
            printf("Nome da %dº pessoa:                      %50s\n", (*pi) + 1, (ps + *pi) -> nome);
            printf("Endereço da %dº pessoa:                  %50s\n", (*pi) + 1, (ps + *pi) -> end);
            printf("Cidade da %dº pessoa:                    %50s\n", (*pi) + 1, (ps + *pi) -> cidade);
            printf("Estado da %dº pessoa:                    %50s\n", (*pi) + 1, (ps + *pi) -> estado);
            printf("CEP da %dº pessoa:                       %50s\n", (*pi) + 1, (ps + *pi) -> cep);
            printf("------------------------------------------------------------------------------------------\n");
        }
        printf("\nPressione 'B' para voltar ao menu\n");
        do{*pmenu = getch();}while(*pmenu != 'B' && *pmenu != 'b');
        if(*pmenu == 'B' || *pmenu == 'b'){system("cls");main();}
        break;
    case '3':
        exit(EXIT_SUCCESS);
        break;
    }
}
#endif // ex2

#ifdef ex3
/*3 - Receba um caracter via teclado usando ponteiros e compara com o vetor abaixo
    usando ponteiros. Mostre como resultado se são EXISTE ou NAO EXISTE.
    vetor -> b,d,f,h,j,l,m,o,q,s,u,w,y */

int acharLetra(char *vetor, char *letra, int *num)
{
    int i, certo = 0;

    for(i = 0;i <= 13; i++){
        if (*(vetor + i) == *letra){certo = 1;break;}
    }

    *num = i;
    return certo;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char vetor[14] = "bdfhjlmoqsuwy";
    char letra, menu;
    int boolean, num;
    char *pletra = &letra, *pmenu = &menu, *pvetor = vetor;
    int *pboolean = &boolean, *pnum = &num;

    do{
    fflush(stdin); //Limpa o buffer para os laços de repetição
    printf("Verifique se o caractere digitado está no vetor \"%s\"\n", vetor);
    printf("Digite a letra: ");
    scanf("%c", pletra);

    *pboolean = acharLetra(pvetor, pletra, pnum);

    if(*pboolean){
        printf("Sua letra '%c' ESTÁ contida no vetor %s na posição %d !\n", *pletra, pvetor, (*pnum) + 1);
    }else{
        printf("Sua letra '%c' NÃO ESTÁ contida no vetor %s !\n", *pletra, pvetor);
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{*pmenu = getch();}while(*pmenu != 'S' && *pmenu != 's' && *pmenu != 'N' && *pmenu != 'n');system("cls");
    }while(*pmenu == 'S' || *pmenu == 's');
}
#endif // ex3

#ifdef ex4
/*4 - Receba 2 string de ate 10 caracteres via teclado, compare-as usando ponteiros
    e mostre como resultado se são IGUAIS ou DIFERENTES.                  */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char string1[11], string2[11], menu;
    char *pstring1 = string1, *pstring2 = string2, *pmenu = &menu;
    int i, igual;
    int *pi = &i, *pigual = &igual;

    do{
    printf("Digite 2 strings de até 10 caracteres\n");
    printf("Primeira String: ");
    scanf("%s", pstring1);
    printf("Segunda String : ");
    scanf("%s", pstring2);

    //compara as strings
    for(*pi = 0, *pigual = 0; string1[*pi] != '\0' || string2[*pi] != '\0'; (*pi)++){
        if( pstring1[*pi] == pstring2[*pi]){
            (*pigual)++;
        }
    }
    if(*pigual == *pi){
        printf("\nSuas Strings são iguais!\n\n");
    }else{
        printf("\nSuas Strings são diferentes!\n\n");}

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{*pmenu = getch();}while(*pmenu != 'S' && *pmenu != 's' && *pmenu != 'N' && *pmenu != 'n');system("cls");
    }while(*pmenu == 'S' || *pmenu == 's');
}
#endif // ex4

#ifdef ex5
/*5 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.                                               */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    char *pmenu = &menu;
    int i, soma = 0,cont = 0;
    int *pi = &i, *psoma = &soma, *pcont = &cont;
    float media;
    float *pmedia = &media;

    do{
    printf("Digite números positivos para serem somados, caso queira saber sua média digite um número negativo\n");
    while(*pi >= 0){
        printf("Digite um número: ");
        scanf("%d", pi);

        if (*pi > 0){
            (*psoma) += *pi;
            (*pcont)++;}
    }
    *pmedia = (float)*psoma / (float)*pcont;
    printf("A média dos números positivos que você escreveu é: %.2f.\n", *pmedia);
    *psoma = 0; *pcont = 0; *pi = 1;

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{*pmenu = getch();}while(*pmenu != 'S' && *pmenu != 's' && *pmenu != 'N' && *pmenu != 'n');system("cls");
    }while(*pmenu == 'S' || *pmenu == 's');
}
#endif // ex5

#ifdef ex6
/*6 - Escreva um programa que contenha uma estrutura representando uma data
    valida. Essa estrutura deve conter os campos dia, mes e ano. Em seguida,
    leia duas datas e armazene nessa estrutura usando ponteiros. Calcule e exiba o
    numero de dias que decorreram entre as duas datas usando ponteiros.   */

//Estruturas
struct data_valida{
    int dia;
    int mes;
    int ano;
};

//Constantes
const int diasMeses[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };

//Funções
int validarData(struct data_valida data)
{
    int bissexto = 0;

    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0)){bissexto = 1;}

    if(data.ano < 1583){return 0;} //Verificar ano
    if(data.mes < 1 || data.mes > 12){return 0;} //Verificar mês
    //Verificar dia
    if(data.mes == 2 && bissexto == 1){if(data.dia < 1 || data.dia > 29){return 0;}}
    if(data.mes == 2 && !bissexto){if(data.dia < 1 || data.dia > 28){return 0;}}
    if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11){if(data.dia < 1 || data.dia > 30){return 0;}}
    else{if(data.dia < 1 || data.dia > 31){return 0;}}

    return 1;
}

int contarAnosBi(struct data_valida data)
{
    int anos = data.ano;

    //Verifica se o ano atual precisa ser considerado na contagem de bissextos
    if (data.mes <= 2)
        anos--;

    //Calcula quantidade de anos bissextos antes do ano
    return anos / 4 - anos / 100 + anos / 400;
}

int diferencaDatas(struct data_valida data1, struct data_valida data2)
{
    //Calcula quantos dias se passaram considerando anos e dias e sem considerar bissextos
    long int n1 = data1.ano * 365 + data1.dia;
    for (int i = 0; i < data1.mes - 1; i++){ //Adiciona dias pelo mês da data
        n1 += diasMeses[i];
    }
    n1 += contarAnosBi(data1); //Adiciona um dia do ano para cada ano bissexto

    //Repete o cálculo para a segunda data
    long int n2 = data2.ano * 365 + data2.dia;
    for (int i = 0; i < data2.mes - 1; i++){
        n2 += diasMeses[i];
    }
    n2 += contarAnosBi(data2);

    return (n2 - n1);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    //Variáveis Simples
    struct data_valida data1, data2;
    int numdias;
    char menu;
    //Ponteiros
    struct data_valida *pdata1 = &data1, *pdata2 = &data2;
    int *pnumdias = &numdias;
    char *pmenu = &menu;

    do{
    printf("Digite duas datas para saber a quantidade de dias entre elas\n");
    do{
    printf("Digite a primeira data (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &pdata1 -> dia, &pdata1 -> mes, &pdata1 -> ano);
    if(validarData(*pdata1) == 0){
        printf("\a[AVISO]Você digitou uma data inválida! Digite a data no modelo DD/MM/AAAA (D = dia|M = mês|A = ano)!\n");}
    }while(validarData(*pdata1) == 0);

    do{
    printf("Digite a segunda data (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &pdata2 -> dia, &pdata2 -> mes, &pdata2 -> ano);
    if(validarData(*pdata2) == 0){
        printf("\a[AVISO]Você digitou uma data inválida! Digite a data no modelo DD/MM/AAAA (D = dia|M = mês|A = ano)!\n");}
    }while(validarData(*pdata2) == 0);

    *pnumdias = diferencaDatas(*pdata1, *pdata2);
    if(*pnumdias < 0){(*pnumdias) *= -1 ;} //Deixa o número positivo caso seja negativo

    printf("\nSe passaram(ão) %d dias entre %d/%d/%d e %d/%d/%d\n", *pnumdias, pdata1 -> dia, pdata1 -> mes, pdata1 -> ano, pdata2 -> dia, pdata2 -> mes, pdata2 -> ano);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{*pmenu = getch();}while(*pmenu != 'S' && *pmenu != 's' && *pmenu != 'N' && *pmenu != 'n');system("cls");
    }while(*pmenu == 'S' || *pmenu == 's');
}
#endif // ex6
