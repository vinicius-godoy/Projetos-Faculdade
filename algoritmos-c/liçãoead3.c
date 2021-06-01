#define ex1
#include<stdio.h>
#include<locale.h>

/*Receba a temperatura m�dia de cada m�s do ano e armazene essas temperaturas em um vetor;
calcule  e  mostre  a  maior,  a  menor  temperatura  do  ano  e  a  m�dia  das  temperaturas.
Mostre todas as temperaturas armazenadas*/
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    float tempmes[12], maiortemp, menortemp, tempano;
    int contador;
    const char* mes[12] = {"Janeiro", "Fevereiro", "Mar�o", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro","Outubro","Novembro","Dezembro"};

    printf("Digite a m�dia de temperatura de cada m�s do ano para saber a m�dia anual\n\n");
    for(contador = 0, maiortemp = 0, menortemp = 100, tempano =0; contador<12; contador++){
        printf("Digite a temperatura m�dia do m�s de %-10s: ", mes[contador]);
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
    printf("TEMPERATURAS M�DIAS MENSAIS\n");
    printf("|--------------------\n");
    for(contador = 0; contador<12; contador++){
        printf("|%-10s:%6.2f�C\n", mes[contador], tempmes[contador]);
        printf("|--------------------\n");
    }
    printf("M�DIA DO ANO E EXTREMOS\n");
    printf("M�dia anual: %.2f�C | Maior m�dia: %.2f�C | Menor m�dia: %.2f�C\n", tempano/12, maiortemp, menortemp);
}
#endif // ex1

/*Elabore um programa que efetue o c�lculo de uma tabuada de um n�mero qualquer e armazene
os  resultados  no  vetor  A  de  uma  dimens�o  para  10  elementos.  O  usu�rio  dever�
digitar  o n�mero e o programa dever� construir e exibir a tabuada correspondente.*/
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int tabuada[10], num, contador;

    printf("Digite um n�mero para saber sua tabuada: ");
    scanf("%i", &num);
    system("cls");
    printf("  TABUADA DO %i\n\n", num);
    for(contador = 0; contador <10; contador++){
        tabuada[contador] = num * (contador + 1);
        printf("%i x %-3i = %5i\n", num, contador+1, tabuada[contador]);
    }
}
#endif // ex2
