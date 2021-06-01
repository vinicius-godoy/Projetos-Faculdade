#define ex1
#include <stdio.h>
#include <locale.h>

/*9. Leia o vetor A tipo vetor com 10 elementos positivos. Construa o vetor B de mesmo tipo,
e cada elemento de B deve ser a metade de cada elemento de A. Exiba em que Vetor e em que
posições apareceram valores superiores a 4. */
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int A[10], contador;
    float B[10];

    printf("Digite 10 números positivos para serem armazenados no vetor A\n");
    for(contador = 0; contador < 10; contador ++)
    {
        do{
        printf("Digite o %iº número do vetor: ", contador + 1);
        scanf("%i", &A[contador]);
        if(A[contador] <= 0){
            printf("O número digitado deve ser positivo!\n");
        }
        }while(A[contador] <= 0);
        B[contador] = (float)A[contador] / 2;
    }
    system("cls");
    printf("Os valores superiores a 4 aparecem nos vetores e posições seguintes:\n");
    for(contador = 0; contador < 10; contador ++)
    {
        if(A[contador] > 4){
            printf("A[%i] = %i\n", contador, A[contador]);
        }
        if(B[contador] > 4){
            printf("B[%i] = %g\n", contador, B[contador]);
        }
    }

}
#endif // ex1

/*7. O usuário poderá digitar a quantidade de números que ele deseja armazenar no vetor A
desde que esse valor seja superior a 4 e inferior ou igual a 20. Construa o vetor B da mesma
dimensão e com os mesmos elementos do vetor A. Observando que o primeiro elemento de A passa
a ser o último de B, o segundo elemento de A passa a ser o penúltimo de B e a assim por
diante. Exibir o conteúdo dos dois vetores. */
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int A[20], B[20], contador, numtermos, contador2;

    do{
    printf("Quantos termos você deseja digitar no Vetor A ? (>4 e <20)\n");
    scanf("%i", &numtermos);
    if(numtermos < 4 || numtermos > 20){
        printf("Você digitou um número de termos inválidos! (O valor deve ser maior do que 4 e menor do que 20!)\n");
    }
    }while(numtermos < 4 || numtermos > 20);
    system("cls");
    //laço for para armazenar os valores no array A
    for(contador = 0; contador < numtermos; contador++)
    {
        printf("Digite o %iº termo: ", contador + 1);
        scanf("%i", &A[contador]);
    }
    //laço for para inverter a ordem dos valores no array B
    for(contador = 0, contador2 = numtermos - 1; contador < numtermos; contador++, contador2--)
    {
        B[contador2] = A[contador];
    }
    system("cls");
    printf("Conteúdo dos Vetores A e B: \n");
    //laço for para printar o conteúdo dos Vetores A e B
    for(contador = 0; contador < numtermos; contador++)
    {
        printf("A[%i] = %i\t\t\tB[%i] = %i\n", contador, A[contador], contador, B[contador]);
    }
}
#endif // ex2
