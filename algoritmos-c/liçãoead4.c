#define ex2
#include <stdio.h>
#include <locale.h>

/*Crie a fun��o M�diaFibonacci que receba da fun��o main um valor do tipo inteiro e maior que
zero que  represente a quantidade de termos da seq��ncia e calcule a m�dia dos termos da
seq��ncia. Exiba na fun��o main o resultado obtido na fun��o M�diaFibonacci.
Seq��ncia de Fibonacci: 0  1  1  2   3   5   8  13  21....*/
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

    printf("Digite a quantidade de termos da Sequ�ncia de Fibonacci que voc� quer que sejam calculados em uma m�dia:\n");
    do{
    scanf("%i", &numtermos);
    if(numtermos <= 0){
        printf("O n�mero de termos deve ser maior do que zero !\n");
    }
    }while(numtermos <= 0);
    if(numtermos == 1){
        printf("A m�dia calculada com o termo foi %i", MediaFibonacci(numtermos));
    }else{
        printf("A m�dia calculada com os %i termos foi %.2f", numtermos, MediaFibonacci(numtermos));
    }
}
#endif

/*Leia 12 elementos inteiros para o vetor A e construa o vetor B com a mesma dimens�o,
observando a seguinte lei de forma��o: �Todo elemento do vetor A que for �mpar deve ser
multiplicado por 2; caso contr�rio, o elemento do vetor A deve permanecer constante�.
Exiba o conte�do dos dois vetores.*/
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int A[12], B[12], contador;

    printf("Digite 12 n�meros no vetor A para receber o vetor B\n");
    for(contador = 0; contador < 12; contador ++){
        printf("Digite o %i� termo: ", contador + 1);
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
