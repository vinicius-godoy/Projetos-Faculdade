#define ex6
#include<locale.h>
#include<stdio.h>

/*1. Armazene oito números quaisquer no vetor A. Após a alimentação mostre todos os números
contidos no vetor A. */

#ifdef ex1
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayA[8], i;
    const int max = 8;

    printf("Armazene oito números quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %iº número: ", i+1);
        scanf("%i", &arrayA[i]);
    }
    printf("Os números digitados foram: ");
    for(i=0;i<max;i++)
    {
        printf("%i ", arrayA[i]);
    }
    return 0;
}
#endif // ex1

/*2. Armazene oito números quaisquer no vetor B. Após a alimentação mostre apenas os números
maiores que zero armazenados no vetor B. */

#ifdef ex2
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayB[8], i;
    const int max = 8;

    printf("Armazene oito números quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %iº número: ", i+1);
        scanf("%i", &arrayB[i]);
    }
    printf("Os números digitados foram: ");
    for(i=0;i<max;i++)
    {
        if(array[i] > 0){
        printf("%i ", arrayB[i]);}
    }
    return 0;
}
#endif // ex2

/*3. Armazene nove números quaisquer no vetor C. Após a alimentação mostre apenas os números
pares armazenados no vetor C. */

#ifdef ex3
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayC[9], i;
    const int max = 9;

    printf("Armazene nove números quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %iº número: ", i+1);
        scanf("%i", &arrayC[i]);
    }
    printf("Os números digitados foram: ");
    for(i=0;i<max;i++)
    {
        if(array[i]%2 == 0){
        printf("%i ", arrayC[i]);}
    }
    return 0;
}
#endif // ex3

/*4. Armazene dez números positivos no vetor D. Após a alimentação mostre  as posições e
os respectivos números  que são divisíveis por 7 armazenados no vetor D.*/

#ifdef ex4
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayD[10], i, check;
    const int max = 10;

    printf("Armazene dez números quaisquers\n");
    for(i=0;i<max;i++)
    {
        do{
        printf("Digite o %iº número: ", i+1);
        scanf("%i", &arrayD[i]);
        if(arrayD[i] < 0){
            printf("O número digitado deve ser positivo!\n");
        }
        }while(arrayD[i] < 0);
    }
    for(i=0, check = 0;i<max;i++)
    {
        if(arrayD[i]%7 == 0){
        printf("O %iº número digitado: %i, é divisível por 7\n", i+1, arrayD[i]);
        check++;
        }
    }
    if(check == 0){
        printf("Nenhum número digitado é divisível por 7.");
    }
    return 0;
}
#endif // ex4

/*5. Armazene sete números quaisquer no vetor E. Após a alimentação de todos os números no
vetor A exiba o seu conteúdo da última posição até a primeira.*/

#ifdef ex5
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayE[7], i;
    const int max = 7;

    printf("Armazene sete números quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %iº número: ", i+1);
        scanf("%i", &arrayE[i]);
    }
    printf("------------------------\n");
    for(i=6;i>=0;i--)
    {
        printf("O %iº número digitado foi %i\n", i+1, arrayE[i]);
    }
    return 0;
}
#endif // ex5

/*6. Armazene sete números quaisquer no vetor F. Verifique e exiba a somatória dos números
e a quantidade de números positivos contidos nesse vetor.*/

#ifdef ex6
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayF[7], i, check, soma;
    const int max = 7;

    printf("Armazene sete números quaisquers para saber sua somátoria\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %iº número: ", i+1);
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
    printf("A somatória dos números digitados é de %i e existem %i números positivos", soma, check);
    }else{
    printf("A somatória dos números digitados é de %i e existe %i número positivo", soma, check);
    }
    return 0;
}
#endif // ex6

/*7. Armazene dez números negativos no vetor X. Exiba o menor número encontrado no vetor X e
a média dos números ímpares contidos nesse vetor. */

#ifdef ex7
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayX[8], i;
    const int max = 8;

    printf("Armazene oito números quaisquers\n");
    for(i=0;i<max;i++)
    {
    printf("Digite o %iº número: ", i+1);
    scanf("%i", &arrayX[i]);
    }
    printf("Os números digitados foram: ");
    for(i=0;i<max;i++)
    {
    printf("%i ", arrayX[i]);
    }
    return 0;
}
#endif // ex7

/*8. Armazene dez números quaisquer no vetor Y. Exiba o maior número encontrado e a quantidade
de números que são múltiplos de 5. */

#ifdef ex8
int main() {

    setlocale(LC_ALL, "portuguese");
    int arrayA[8], i;
    const int max = 8;

    printf("Armazene oito números quaisquers\n");
    for(i=0;i<max;i++)
    {
        printf("Digite o %iº número: ", i+1);
        scanf("%i", &arrayA[i]);
    }
    printf("Os números digitados foram: ");
    for(i=0;i<max;i++)
    {
        printf("%i ", arrayA[i]);
    }
    return 0;
}
#endif // ex8
