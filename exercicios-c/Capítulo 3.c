#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef ex1
/* 1.Escreva um programa para receber via teclado em vetores 3 int, 3 long,
3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double                                    */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int veti[3], i;
    long vetl[3];
    unsigned vetu[3];
    float vetf[3];
    double vetd[3];

    do{
    printf("Digite 3 valores para cada tipo de dado requisitado\n");
    printf("Int:\n");
    for(i = 0; i < 3; i++){
        printf("int veti [%d] = ", i);
        scanf("%d", &veti[i]);
    }
    printf("Long:\n");
    for(i = 0; i < 3; i++){
        printf("int vetl [%d] = ", i);
        scanf("%ld", &vetl[i]);
    }
    printf("Unsigned:\n");
    for(i = 0; i < 3; i++){
        printf("int vetu [%d] = ", i);
        scanf("%u", &vetu[i]);
    }
    printf("Float:\n");
    for(i = 0; i < 3; i++){
        printf("int vetf [%d] = ", i);
        scanf("%f", &vetf[i]);
    }
    printf("Double:\n");
    for(i = 0; i < 3; i++){
        printf("int vetd [%d] = ", i);
        scanf("%lf", &vetd[i]);
    }
    system("cls");
    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-6d              %-11ld         %-6u   \n", veti[0], vetl [0], vetu[0]);
    printf("            %-8.1e            %-9.1e            \n", vetf[0], vetd[0]);
    printf("  %-6d              %-11ld         %-6u\n", veti[1], vetl [1], vetu[1]);
    printf("            %-8.1e            %-9.1e            \n", vetf[1], vetd[1]);
    printf("  %-6d              %-11ld         %-6u\n", veti[2], vetl [2], vetu[2]);
    printf("            %-8.1e            %-9.1e            \n", vetf[2], vetd[2]);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex1

#ifdef ex2
/*2.Receba via teclado dez valores inteiros e ordene por ordem crescente assim
que sao digitados. Guarde-os em um vetor. Mostre ao final os valores em ordem. */
void main()
{
    setlocale(LC_ALL,"Portuguese");
    char resp;
    int num[10], aux, i, j;

    do{
    printf("Digite 10 números para colocá-los em ordem crescente!\n");
    for(i=0;i<10;i++){
        printf("Digite o %dº número: ",i+1);
        scanf("%d",&num[i]);

        for(j=0;j<i;j++){
            if(num[i] <= num[j]){
                aux = num[i];
                num[i] = num[j];
                num[j] = aux;
            }
        }
    }
    printf("\nOs números em ordem crescente são:\n");
    for(i=0;i<10;i++){
        if(i < 9){
            printf("%d, ",num[i]);
        }else{
            printf("%d.", num[i]);}
    }
    printf("\n");

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex2

#ifdef ex3
/* 3.Um vetor é palíndromo se ele não se altera quando as posições dos componentes
são invertidos. Por exemplo, o vetor v = {1, 3, 5, 2, 2, 5, 3, 1} é palíndromo.
Escreva um programa que verifique se um vetor é palíndromo. Receba o vetor
via teclado (tamanho 10)                  */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int vetor[10], palin = 0, palinTamanho = 10, soma, i;

    do{
    printf("Digite 10 números em um vetor para saber se ele é um palíndromo\n\n");
    //laço for pra escanear os números do vetor
    for(i = 0; i < palinTamanho; i++)
    {
        printf("vetor[%d] = ", i);
        scanf("%d", &vetor[i]);
    }
    //laço for pra verificar o palíndromo
    for(i = 0, soma = palinTamanho-1; i < palinTamanho/2; i++, soma -= 2)
    {
        if(vetor[i] == vetor[i+soma]){
            palin++;
        }
    }
    if(palin == 5){printf("\a\nO seu número é um palíndromo!\n\n");}
    else{printf("\a\nO seu número não é um palíndromo!\n\n");}
    palin = 0;

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex3

#ifdef ex4
/* Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
que recebe os dados via teclado para esses 2 vetores. Usando o operador
subtracao "-", subtraia os elementos de mesmo indice dos 2 vetores
e guarde o resultado num 3. vetor. Imprima na tela o indice, os valores e
o resultado dos 6 elementos dos vetores. */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int vetbi[2][3], vetbi2[2][3], vetsub[2][3], i, j;

    do{
    printf("Digite os valores do primeiro vetor!\n");
    //Laço pra pegar os dados do primeiro vetor
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("Valor do vetor1[%d][%d] = ", i, j);
            scanf("%d", &vetbi[i][j]);
            vetsub[i][j] = vetbi[i][j];
        }
    }
    printf("Agora digite os valores do segundo vetor!\n");
    //Laço pra pegar os dados do segundo vetor
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("Valor do vetor2[%d][%d] = ", i, j);
            scanf("%d", &vetbi2[i][j]);
            vetsub[i][j] -= vetbi2[i][j];
        }
    }

    system("cls");

    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("vetor1[%d][%d] = %d | vetor2[%d][%d] = %d | sub[%d][%d] = %d\n", i, j, vetbi[i][j], i, j, vetbi2[i][j], i, j, vetsub[i][j]);
            printf("%d - %d = %d\n", vetbi[i][j], vetbi2[i][j], vetsub[i][j]);
            printf("-----------------------------------------------------\n");
        }
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex4

#ifdef ex5
/* Receba via teclado valores para uma matriz 5 x 5. Receba via teclado um valor X.
O programa dever fazer a busca desse valor x na matriz e, ao final escrever a
localizacao (linha e coluna) ou uma mensagem de ”nao encontrado”. */
void main()
{
    setlocale(LC_ALL, "portuguese");
    char resp;
    int matriz[5][5], x, i, j, achado = 0;

    do{
    printf("Preencha essa matriz de 5x5!\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("Digite o valor da matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("---------------------------------------------------\n");
    printf("Informe o valor que deseja achar na matriz: ");
    scanf("%d", &x);
    system("cls");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(matriz[i][j] == x){
                printf("O valor procurado \'%d\' está na linha %d, coluna %d (matriz[%d][%d])\n", x, i, j, i, j);
                achado++;
                break;
            }
        }
    }
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(matriz[i][j] == x){printf(">%-3d< ", matriz[i][j]);}
            else{printf(" %-3d  ", matriz[i][j]);}
        }
        printf("\n");
    }
    if(achado == 0){
        printf("Valor %d não encontrado na matriz!\n", x);
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    resp = getch();system("cls");
    }while(resp == 'S' || resp == 's');
}
#endif // ex5
