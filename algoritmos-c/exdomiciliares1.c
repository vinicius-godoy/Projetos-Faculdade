#define ex1
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*1. Receba notas de um conjunto de K alunos. A variável K representa a quantidade de alunos
determinada pelo usuário e as variáveis Nota1 e Nota2 representam respectivamente a primeira
e a segunda nota de cada aluno. Calcule:
a. A média aritmética das duas notas de cada aluno.
b. Exiba juntamente com a média uma mensagem correspondente a tabela abaixo:
|Média Aritmética | Mensagem   |
|Até 3.0	      | Reprovado  |
|Entre 3,0 e 7,0  | P3         |
|Acima de 7.0	  | Aprovado   |
c. O total de alunos aprovados, alunos de P3, alunos reprovados e a média da classe. */

#ifdef ex1
int main() {
    setlocale(LC_ALL, "portuguese");
    // variáveis de número de alunos, contador, alunos aprovados, reprovados e de p3
    int numal, i, aaprov = 0, areprov = 0, ap3 = 0;
    //vetores de nota 1 e 2 e média do aluno, variável da média da sala
    float nota1[100], nota2[100], media[100], mediasala;

    printf("DIGITE O NÚMERO DE ALUNOS QUE DESEJA CALCULCAR A MÉDIA: ");
    scanf("%i", &numal);
    printf("\n");
    //laço for pra armazenar as notas dos alunos, calcular as médias e contar os aprovados
    for(i = 0, mediasala = 0; i<numal; i++){
        printf("%iº ALUNO\n", i+1);
        do{
        printf("Digite a primeira nota do Aluno: ");
        scanf("%f", &nota1[i]);
        if(nota1[i]<0 || nota1[i]>10){
            printf("Digite uma nota válida!\n");
        }
        }while(nota1[i]<0 || nota1[i]>10);
        do{
        printf("Digite a segunda nota do Aluno: ");
        scanf("%f", &nota2[i]);
        if(nota2[i]<0 || nota2[i]>10){
            printf("Digite uma nota válida!\n");
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
    printf("MÉDIAS DOS ALUNOS\n------------------\n");
    //laço for pra printar as médias, números de aprovados, reprovados e p3
    for(i = 0; i<numal; i++){
        printf("Média do Aluno %i: %.2f | ", i+1, media[i]);
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
    printf("\nAlunos Aprovados: %i | Alunos Reprovados: %i | Alunos de P3: %i\nMédia da Sala: %.2f\n", aaprov, areprov, ap3, mediasala/numal);
}
#endif // ex1

/*2. O cardápio de uma lanchonete é o seguinte:
|Especificação   | Código | Preço |
|Cachorro quente |   100  | 1,20  |
|Bauru simples   |   101  | 1,30  |
|Bauru com ovo   |   102  | 1,50  |
|Hambúrguer      |   103  | 1,20  |
|Cheeseburguer   |   104  | 1,30  |
|Refrigerante    |   105  | 1,00  |
Leia o código do item pedido, a quantidade e calcule o valor a ser pago por
aquele lanche. Considere que a cada execução somente será calculado um item.
A quantidade de clientes é determinada pelo usuário. */

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    //variáveis de contador, número de clientes, quantidade e item
    int i, numcl, qntd, item;
    //vetores de valor e cardápio de códigos
    float vlr[100], cardapio[6] = {1.20, 1.30, 1.50, 1.20, 1.30, 1.00};

    do{
    printf("Digite quantos clientes você deseja calcular o valor do pedido: ");
    scanf("%i", &numcl);
    if(numcl<0){
        printf("Digite um número de clientes maior que zero!\n");
    }
    }while(numcl<0);
    printf("\n");
    //laço for para calcular o valor dos pedidos de todos os clientes
    for(i=0; i<numcl; i++){
        printf("%iº CLIENTE\n", i+1);
        printf("Digite o código do pedido: ");
        scanf("%i", &item);
        do{
        printf("Digite a quantidade de itens do pedido: ");
        scanf("%i", &qntd);
        if(numcl<0){
            printf("Digite um número de itens maior que zero!\n");
        }
        }while(qntd<0);
        vlr[i] = cardapio[item-100] * qntd;
        printf("-------------------------------------------------------\n");
    }
    system("cls"); //comando pra limpar a tela
    printf("Preço dos pedidos dos clientes\n");
    //laço for pra printar o valor dos pedidos
    for(i=0; i<numcl; i++){
        printf("O preço do pedido do %iº cliente é de: R$%.2f\n", i+1, vlr[i]);
    }
}
#endif // ex2
