#define ex1
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*1. Receba notas de um conjunto de K alunos. A vari�vel K representa a quantidade de alunos
determinada pelo usu�rio e as vari�veis Nota1 e Nota2 representam respectivamente a primeira
e a segunda nota de cada aluno. Calcule:
a. A m�dia aritm�tica das duas notas de cada aluno.
b. Exiba juntamente com a m�dia uma mensagem correspondente a tabela abaixo:
|M�dia Aritm�tica | Mensagem   |
|At� 3.0	      | Reprovado  |
|Entre 3,0 e 7,0  | P3         |
|Acima de 7.0	  | Aprovado   |
c. O total de alunos aprovados, alunos de P3, alunos reprovados e a m�dia da classe. */

#ifdef ex1
int main() {
    setlocale(LC_ALL, "portuguese");
    // vari�veis de n�mero de alunos, contador, alunos aprovados, reprovados e de p3
    int numal, i, aaprov = 0, areprov = 0, ap3 = 0;
    //vetores de nota 1 e 2 e m�dia do aluno, vari�vel da m�dia da sala
    float nota1[100], nota2[100], media[100], mediasala;

    printf("DIGITE O N�MERO DE ALUNOS QUE DESEJA CALCULCAR A M�DIA: ");
    scanf("%i", &numal);
    printf("\n");
    //la�o for pra armazenar as notas dos alunos, calcular as m�dias e contar os aprovados
    for(i = 0, mediasala = 0; i<numal; i++){
        printf("%i� ALUNO\n", i+1);
        do{
        printf("Digite a primeira nota do Aluno: ");
        scanf("%f", &nota1[i]);
        if(nota1[i]<0 || nota1[i]>10){
            printf("Digite uma nota v�lida!\n");
        }
        }while(nota1[i]<0 || nota1[i]>10);
        do{
        printf("Digite a segunda nota do Aluno: ");
        scanf("%f", &nota2[i]);
        if(nota2[i]<0 || nota2[i]>10){
            printf("Digite uma nota v�lida!\n");
        }
        }while(nota2[i]<0 || nota2[i]>10);
        printf("---------------------------------------\n");
        media[i] = (nota1[i]+nota2[i])/2;
        mediasala = mediasala + media[i];
        if(media[i]>7){
            aaprov = aaprov + 1;
        }else{
            if(media[i]<3){
            areprov = areprov + 1;
            }else{
            ap3 = ap3 + 1;
            }
            }
    }
    system("cls"); //comando pra limpar a tela
    printf("M�DIAS DOS ALUNOS\n------------------\n");
    //la�o for pra printar as m�dias, n�meros de aprovados, reprovados e p3
    for(i = 0; i<numal; i++){
        printf("M�dia do Aluno %i: %.2f | ", i+1, media[i]);
        if(media[i]>7){
            printf("APROVADO\n");
        }else{
            if(media[i]<3){
            printf("REPROVADO\n");
        }else{
            printf("P3\n");
            }
        }
    }
    printf("\nAlunos Aprovados: %i | Alunos Reprovados: %i | Alunos de P3: %i\nM�dia da Sala: %.2f\n", aaprov, areprov, ap3, mediasala/numal);
}
#endif // ex1

/*2. O card�pio de uma lanchonete � o seguinte:
|Especifica��o   | C�digo | Pre�o |
|Cachorro quente |   100  | 1,20  |
|Bauru simples   |   101  | 1,30  |
|Bauru com ovo   |   102  | 1,50  |
|Hamb�rguer      |   103  | 1,20  |
|Cheeseburguer   |   104  | 1,30  |
|Refrigerante    |   105  | 1,00  |
Leia o c�digo do item pedido, a quantidade e calcule o valor a ser pago por
aquele lanche. Considere que a cada execu��o somente ser� calculado um item.
A quantidade de clientes � determinada pelo usu�rio. */

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    //vari�veis de contador, n�mero de clientes, quantidade e item
    int i, numcl, qntd, item;
    //vetores de valor e card�pio de c�digos
    float vlr[100], cardapio[6] = {1.20, 1.30, 1.50, 1.20, 1.30, 1.00};

    do{
    printf("Digite quantos clientes voc� deseja calcular o valor do pedido: ");
    scanf("%i", &numcl);
    if(numcl<0){
        printf("Digite um n�mero de clientes maior que zero!\n");
    }
    }while(numcl<0);
    printf("\n");
    //la�o for para calcular o valor dos pedidos de todos os clientes
    for(i=0; i<numcl; i++){
        printf("%i� CLIENTE\n", i+1);
        printf("Digite o c�digo do pedido: ");
        scanf("%i", &item);
        do{
        printf("Digite a quantidade de itens do pedido: ");
        scanf("%i", &qntd);
        if(numcl<0){
            printf("Digite um n�mero de itens maior que zero!\n");
        }
        }while(qntd<0);
        vlr[i] = cardapio[item-100] * qntd;
        printf("-------------------------------------------------------\n");
    }
    system("cls"); //comando pra limpar a tela
    printf("Pre�o dos pedidos dos clientes\n");
    //la�o for pra printar o valor dos pedidos
    for(i=0; i<numcl; i++){
        printf("O pre�o do pedido do %i� cliente � de: R$%.2f\n", i+1, vlr[i]);
    }
}
#endif // ex2
