#include <stdio.h> //Fun��es padr�es de entrada e sa�da
#include <stdlib.h>//Fun��o system
#include <conio.h> //Fun��es getch e getche
#include <locale.h> //Fun��o de configura��o de idioma da tabela ASCII

//Estrutura
struct estoque{
    unsigned char nome[31];
    int qtd_atual; //quantidade atual
    int qtd_min;   //quantidaded de estoque m�nima
    int dia_validade;
    int mes_validade;
    int ano_validade;
};

//Prot�tipo das Fun��es
void lbuffer(void); //Fun��o para limpar o buffer que funciona em todos os SOs
void menu_cadastrar();
void menu_listar();
void menu_pesquisar_nome();
void menu_pesquisar_letra();
void menu_pesquisar_validade();
void menu_listar_qtdmin();
void menu_movimentar();
void menu_alterar();
void menu_excluir();
void sair();

//Programa
void main(void)
{
    system("cls");
    setlocale(LC_ALL, "portuguese"); //Configura o idioma padr�o da ASCII pra portugu�s
    static struct estoque produto, *ps; //Declara��o da estrutura e seu ponteiro
    int menu; //Declara��o da vari�vel do menu principal

    printf("MENU\n");
    printf(" 1. Cadastrar produto\n");
    printf(" 2. Listar produtos cadastrados\n");
    printf(" 3. Pesquisar produto por nome\n");
    printf(" 4. Pesquisar produto pela 1� letra\n");
    printf(" 5. Pesquisar data de validade\n");
    printf(" 6. Listar produtos abaixo do estoque m�nimo\n");
    printf(" 7. Movimentar quantidade em estoque\n");
    printf(" 8. Alterar produto cadastrado\n");
    printf(" 9. Excluir produto cadastrado\n");
    printf("10. Sair\n");
    printf("\nResposta -> ");

    do{scanf("%d", &menu);}while(menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5 && menu != 6 && menu != 7 && menu != 8 && menu != 9 && menu != 10);
    system("cls"); //Sempre que sair do menu limpar a tela
    lbuffer(); //Sempre que sair do menu limpar o buffer

    switch(menu)
    {
    case 1:
        menu_cadastrar();
        break;
    case 2:
        menu_listar();
        break;
    case 3:
        menu_pesquisar_nome();
        break;
    case 4:
        menu_pesquisar_letra();
        break;
    case 5:
        menu_pesquisar_validade();
        break;
    case 6:
        menu_listar_qtdmin();
        break;
    case 7:
        menu_movimentar();
        break;
    case 8:
        menu_alterar();
        break;
    case 9:
        menu_excluir();
        break;
    case 10:
        sair();
        break;
    }

}

//Fun��es
void lbuffer(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void menu_cadastrar()
{
    printf("1"); //Teste do menu
}

void menu_listar()
{
    printf("2"); //Teste do menu
}

void menu_pesquisar_nome()
{
    printf("3"); //Teste do menu
}

void menu_pesquisar_letra()
{
    printf("4"); //Teste do menu
}

void menu_pesquisar_validade()
{
    printf("5"); //Teste do menu
}

void menu_listar_qtdmin()
{
    printf("6"); //Teste do menu
}

void menu_movimentar()
{
    printf("7"); //Teste do menu
}

void menu_alterar()
{
    printf("8"); //Teste do menu
}

void menu_excluir()
{
    printf("9"); //Teste do menu
}

void sair()
{
    printf("10"); //Teste do menu
}
