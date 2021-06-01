#define ex1
#include<stdio.h>
#include<locale.h>

/*Receba a temperatura média de cada mês do ano e armazene essas temperaturas em um vetor;
calcule  e  mostre  a  maior,  a  menor  temperatura  do  ano  e  a  média  das  temperaturas.
Mostre todas as temperaturas armazenadas*/
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    float tempmes[12], maiortemp, menortemp, tempano;
    int contador;
    const char* mes[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro","Outubro","Novembro","Dezembro"};

    printf("Digite a média de temperatura de cada mês do ano para saber a média anual\n\n");
    for(contador = 0, maiortemp = 0, menortemp = 100, tempano =0; contador<12; contador++){
        printf("Digite a temperatura média do mês de %-10s: ", mes[contador]);
        scanf("%f", &tempmes[contador]);
        tempano += tempmes[contador];
        if(tempmes[contador]>maiortemp){
            maiortemp = tempmes[contador];
        }
        if(tempmes[contador]<menortemp){
            menortemp = tempmes[contador];
        }
    }
    system("cls");
    printf("TEMPERATURAS MÉDIAS MENSAIS\n");
    printf("|--------------------\n");
    for(contador = 0; contador<12; contador++){
        printf("|%-10s:%6.2fºC\n", mes[contador], tempmes[contador]);
        printf("|--------------------\n");
    }
    printf("MÉDIA DO ANO E EXTREMOS\n");
    printf("Média anual: %.2fºC | Maior média: %.2fºC | Menor média: %.2fºC\n", tempano/12, maiortemp, menortemp);
}
#endif // ex1

/*Elabore um programa que efetue o cálculo de uma tabuada de um número qualquer e armazene
os  resultados  no  vetor  A  de  uma  dimensão  para  10  elementos.  O  usuário  deverá
digitar  o número e o programa deverá construir e exibir a tabuada correspondente.*/
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int tabuada[10], num, contador;

    printf("Digite um número para saber sua tabuada: ");
    scanf("%i", &num);
    system("cls");
    printf("  TABUADA DO %i\n\n", num);
    for(contador = 0; contador <10; contador++){
        tabuada[contador] = num * (contador + 1);
        printf("%i x %-3i = %5i\n", num, contador+1, tabuada[contador]);
    }
}
#endif // ex2
