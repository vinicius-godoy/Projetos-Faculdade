#define ex2
#include <stdio.h>
#include <locale.h>

/*Crie a função MédiaFibonacci que receba da função main um valor do tipo inteiro e maior que
zero que  represente a quantidade de termos da seqüência e calcule a média dos termos da
seqüência. Exiba na função main o resultado obtido na função MédiaFibonacci.
Seqüência de Fibonacci: 0  1  1  2   3   5   8  13  21....*/
#ifdef ex1
float MediaFibonacci(int numtermos)
{
    float media;
    int i, valor1 = 0, valor2 = 1, fibonacci;

    if(numtermos == 1){
        media = 0;
    }else{
    for(i = 0, media = 1; i < numtermos-2; i ++){
        fibonacci = valor1 + valor2;
        media += fibonacci;
        valor1 = valor2;
        valor2 = fibonacci;
    }
    media = media/numtermos;
    }

    return media;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    float media;
    int numtermos;

    printf("Digite a quantidade de termos da Sequência de Fibonacci que você quer que sejam calculados em uma média:\n");
    do{
    scanf("%i", &numtermos);
    if(numtermos <= 0){
        printf("O número de termos deve ser maior do que zero !\n");
    }
    }while(numtermos <= 0);
    if(numtermos == 1){
        printf("A média calculada com o termo foi %i", MediaFibonacci(numtermos));
    }else{
        printf("A média calculada com os %i termos foi %.2f", numtermos, MediaFibonacci(numtermos));
    }
}
#endif

/*Leia 12 elementos inteiros para o vetor A e construa o vetor B com a mesma dimensão,
observando a seguinte lei de formação: “Todo elemento do vetor A que for ímpar deve ser
multiplicado por 2; caso contrário, o elemento do vetor A deve permanecer constante”.
Exiba o conteúdo dos dois vetores.*/
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int A[12], B[12], contador;

    printf("Digite 12 números no vetor A para receber o vetor B\n");
    for(contador = 0; contador < 12; contador ++){
        printf("Digite o %iº termo: ", contador + 1);
        scanf("%i", &A[contador]);
        if(A[contador]%2 != 0){
            B[contador] = A[contador]*2;
        }else{
            B[contador] = A[contador];
        }
    }
    system("cls");
    for(contador = 0; contador < 12; contador ++){
        if(contador<10){
            printf("A[%i]  = %3i    B[%i]  = %3i\n", contador, A[contador], contador, B[contador]);
        }else{
            printf("A[%i] = %3i    B[%i] = %3i\n", contador, A[contador], contador, B[contador]);
        }
    }
}
#endif // ex2
