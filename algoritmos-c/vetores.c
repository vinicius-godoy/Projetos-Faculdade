#define ex6
#include<locale.h>
#include<stdio.h>

/*1. Armazene oito n�meros quaisquer no vetor A. Ap�s a alimenta��o mostre todos os n�meros
contidos no vetor A. */

#ifdef ex1
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayA[8], i;
    const int max = 8;

    printf("Armazene oito n�meros quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %i� n�mero: ", i+1);
        scanf("%i", &arrayA[i]);
    }
    printf("Os n�meros digitados foram: ");
    for(i=0;i<max;i++)
    {
        printf("%i ", arrayA[i]);
    }
    return 0;
}
#endif // ex1

/*2. Armazene oito n�meros quaisquer no vetor B. Ap�s a alimenta��o mostre apenas os n�meros
maiores que zero armazenados no vetor B. */

#ifdef ex2
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayB[8], i;
    const int max = 8;

    printf("Armazene oito n�meros quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %i� n�mero: ", i+1);
        scanf("%i", &arrayB[i]);
    }
    printf("Os n�meros digitados foram: ");
    for(i=0;i<max;i++)
    {
        if(array[i] > 0){
        printf("%i ", arrayB[i]);}
    }
    return 0;
}
#endif // ex2

/*3. Armazene nove n�meros quaisquer no vetor C. Ap�s a alimenta��o mostre apenas os n�meros
pares armazenados no vetor C. */

#ifdef ex3
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayC[9], i;
    const int max = 9;

    printf("Armazene nove n�meros quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %i� n�mero: ", i+1);
        scanf("%i", &arrayC[i]);
    }
    printf("Os n�meros digitados foram: ");
    for(i=0;i<max;i++)
    {
        if(array[i]%2 == 0){
        printf("%i ", arrayC[i]);}
    }
    return 0;
}
#endif // ex3

/*4. Armazene dez n�meros positivos no vetor D. Ap�s a alimenta��o mostre  as posi��es e
os respectivos n�meros  que s�o divis�veis por 7 armazenados no vetor D.*/

#ifdef ex4
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayD[10], i, check;
    const int max = 10;

    printf("Armazene dez n�meros quaisquers\n");
    for(i=0;i<max;i++)
    {
        do{
        printf("Digite o %i� n�mero: ", i+1);
        scanf("%i", &arrayD[i]);
        if(arrayD[i] < 0){
            printf("O n�mero digitado deve ser positivo!\n");
        }
        }while(arrayD[i] < 0);
    }
    for(i=0, check = 0;i<max;i++)
    {
        if(arrayD[i]%7 == 0){
        printf("O %i� n�mero digitado: %i, � divis�vel por 7\n", i+1, arrayD[i]);
        check++;
        }
    }
    if(check == 0){
        printf("Nenhum n�mero digitado � divis�vel por 7.");
    }
    return 0;
}
#endif // ex4

/*5. Armazene sete n�meros quaisquer no vetor E. Ap�s a alimenta��o de todos os n�meros no
vetor A exiba o seu conte�do da �ltima posi��o at� a primeira.*/

#ifdef ex5
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayE[7], i;
    const int max = 7;

    printf("Armazene sete n�meros quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %i� n�mero: ", i+1);
        scanf("%i", &arrayE[i]);
    }
    printf("------------------------\n");
    for(i=6;i>=0;i--)
    {
        printf("O %i� n�mero digitado foi %i\n", i+1, arrayE[i]);
    }
    return 0;
}
#endif // ex5

/*6. Armazene sete n�meros quaisquer no vetor F. Verifique e exiba a somat�ria dos n�meros
e a quantidade de n�meros positivos contidos nesse vetor.*/

#ifdef ex6
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayF[7], i, check, soma;
    const int max = 7;

    printf("Armazene sete n�meros quaisquers para saber sua som�toria\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %i� n�mero: ", i+1);
        scanf("%i", &arrayF[i]);
    }
    for(i=0,soma = 0, check = 0;i<max;i++)
    {
        soma = soma + arrayF[i];
        if(arrayF[i]>0){
        check++;
        }
    }
    if(check>1){
    printf("A somat�ria dos n�meros digitados � de %i e existem %i n�meros positivos", soma, check);
    }else{
    printf("A somat�ria dos n�meros digitados � de %i e existe %i n�mero positivo", soma, check);
    }
    return 0;
}
#endif // ex6

/*7. Armazene dez n�meros negativos no vetor X. Exiba o menor n�mero encontrado no vetor X e
a m�dia dos n�meros �mpares contidos nesse vetor. */

#ifdef ex7
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayX[8], i;
    const int max = 8;

    printf("Armazene oito n�meros quaisquers\n");
    for(i=0;i<max;i++)
    {
    printf("Digite o %i� n�mero: ", i+1);
    scanf("%i", &arrayX[i]);
    }
    printf("Os n�meros digitados foram: ");
    for(i=0;i<max;i++)
    {
    printf("%i ", arrayX[i]);
    }
    return 0;
}
#endif // ex7

/*8. Armazene dez n�meros quaisquer no vetor Y. Exiba o maior n�mero encontrado e a quantidade
de n�meros que s�o m�ltiplos de 5. */

#ifdef ex8
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayA[8], i;
    const int max = 8;

    printf("Armazene oito n�meros quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %i� n�mero: ", i+1);
        scanf("%i", &arrayA[i]);
    }
    printf("Os n�meros digitados foram: ");
    for(i=0;i<max;i++)
    {
        printf("%i ", arrayA[i]);
    }
    return 0;
}
#endif // ex8
