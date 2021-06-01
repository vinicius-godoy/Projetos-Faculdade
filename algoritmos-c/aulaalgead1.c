#define ex1
#include <stdio.h>
#include <locale.h>

/*9. Leia o vetor A tipo vetor com 10 elementos positivos. Construa o vetor B de mesmo tipo,
e cada elemento de B deve ser a metade de cada elemento de A. Exiba em que Vetor e em que
posi��es apareceram valores superiores a 4. */
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int A[10], contador;
    float B[10];

    printf("Digite 10 n�meros positivos para serem armazenados no vetor A\n");
    for(contador = 0; contador < 10; contador ++)
    {
        do{
        printf("Digite o %i� n�mero do vetor: ", contador + 1);
        scanf("%i", &A[contador]);
        if(A[contador] <= 0){
            printf("O n�mero digitado deve ser positivo!\n");
        }
        }while(A[contador] <= 0);
        B[contador] = (float)A[contador] / 2;
    }
    system("cls");
    printf("Os valores superiores a 4 aparecem nos vetores e posi��es seguintes:\n");
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

/*7. O usu�rio poder� digitar a quantidade de n�meros que ele deseja armazenar no vetor A
desde que esse valor seja superior a 4 e inferior ou igual a 20. Construa o vetor B da mesma
dimens�o e com os mesmos elementos do vetor A. Observando que o primeiro elemento de A passa
a ser o �ltimo de B, o segundo elemento de A passa a ser o pen�ltimo de B e a assim por
diante. Exibir o conte�do dos dois vetores. */
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int A[20], B[20], contador, numtermos, contador2;

    do{
    printf("Quantos termos voc� deseja digitar no Vetor A ? (>4 e <20)\n");
    scanf("%i", &numtermos);
    if(numtermos < 4 || numtermos > 20){
        printf("Voc� digitou um n�mero de termos inv�lidos! (O valor deve ser maior do que 4 e menor do que 20!)\n");
    }
    }while(numtermos < 4 || numtermos > 20);
    system("cls");
    //la�o for para armazenar os valores no array A
    for(contador = 0; contador < numtermos; contador++)
    {
        printf("Digite o %i� termo: ", contador + 1);
        scanf("%i", &A[contador]);
    }
    //la�o for para inverter a ordem dos valores no array B
    for(contador = 0, contador2 = numtermos - 1; contador < numtermos; contador++, contador2--)
    {
        B[contador2] = A[contador];
    }
    system("cls");
    printf("Conte�do dos Vetores A e B: \n");
    //la�o for para printar o conte�do dos Vetores A e B
    for(contador = 0; contador < numtermos; contador++)
    {
        printf("A[%i] = %i\t\t\tB[%i] = %i\n", contador, A[contador], contador, B[contador]);
    }
}
#endif // ex2
