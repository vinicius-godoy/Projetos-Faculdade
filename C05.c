#include <stdio.h> //Fun��es padr�es de entrada e sa�da
#include <stdlib.h>//Fun��o system
#include <conio.h> //Fun��es getch e getche
#include <locale.h> //Fun��o de configura��o de idioma da tabela ASCII

//Macros
#define NUM_PROD 5 //Macro com o n�mero de produtos, basta aumentar aqui para mudar o programa.

//Estrutura
struct estoque{
    unsigned char nome[31];
    int qtd_atual; //quantidade atual
    int qtd_min;   //quantidade de estoque m�nima
    int dia_validade;
    int mes_validade;
    int ano_validade;
};

//Prot�tipo das Fun��es
void lbuffer(void); //Fun��o para limpar o buffer que funciona em todos os SOs
void escreverEstrutura(struct estoque *ps, char modo[], int linha); //Fun��o pra escrever uma estrutura no arquivo
void lerEstrutura(struct estoque *ps, int linha); //Fun��o pra ler uma estrutura no arquivo
void zerar_estrutura(struct estoque *ps); //Fun��o que zera todas as vari�veis da estrutura
void menu_cadastrar(struct estoque *ps); //Fun��o do menu de cadastramento de produtos
void menu_listar(struct estoque *ps);
void menu_pesquisar_nome(struct estoque *ps);
void menu_pesquisar_letra(struct estoque *ps);
void menu_pesquisar_validade(struct estoque *ps);
void menu_listar_qtdmin(struct estoque *ps);
void menu_movimentar(struct estoque *ps);
void menu_alterar(struct estoque *ps);
void menu_excluir(struct estoque *ps);
void sair(struct estoque *ps);

//Programa
void main(void)
{
    system("cls");
    setlocale(LC_ALL, "portuguese"); //Configura o idioma padr�o da ASCII pra portugu�s
    static struct estoque produto, *ps; //Declara��o da estrutura e seu ponteiro
    int menu; //Declara��o da vari�vel do menu principal

    ps = &produto;

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

    switch(menu)
    {
    case 1:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_cadastrar(ps);
        break;
    case 2:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_listar(ps);
        break;
    case 3:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_pesquisar_nome(ps);
        break;
    case 4:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_pesquisar_letra(ps);
        break;
    case 5:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_pesquisar_validade(ps);
        break;
    case 6:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_listar_qtdmin(ps);
        break;
    case 7:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_movimentar(ps);
        break;
    case 8:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_alterar(ps);
        break;
    case 9:
        system("cls"); //Sempre que sair do menu limpar a tela
        lbuffer(); //Sempre que sair do menu limpar o buffer
        menu_excluir(ps);
        break;
    case 10:
        sair(ps);
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

void escreverEstrutura(struct estoque *ps, char modo[], int linha)
{
    FILE *file;
    int i;
    int _struct = sizeof(struct estoque);
    linha = linha * _struct; //Define o tamanho da linha com todas as vari�veis no arquivo

    file = fopen("estoque.txt", modo);
    if(linha != 0){fseek(file, linha, SEEK_SET);}
    fwrite(ps -> nome, sizeof(ps -> nome), 1, file);
    fwrite(&ps -> qtd_atual, sizeof(ps -> qtd_atual), 1, file);
    fwrite(&ps -> qtd_min, sizeof(ps -> qtd_min), 1, file);
    fwrite(&ps -> dia_validade, sizeof(ps -> dia_validade), 1, file);
    fwrite(&ps -> mes_validade, sizeof(ps -> mes_validade), 1, file);
    fwrite(&ps -> ano_validade, sizeof(ps -> ano_validade), 1, file);
    fclose(file);

    zerar_estrutura(ps); //Zera a estrutura depois de escrever no arquivo para evitar lixo
}

void lerEstrutura(struct estoque *ps, int linha)
{
    FILE *file;
    int i;
    int _struct = sizeof(struct estoque);
    linha = linha * _struct; //Define o tamanho da linha com todas as vari�veis no arquivo

    zerar_estrutura(ps); //Zera a estrutura antes de ler do arquivo para evitar lixo

    file = fopen("estoque.txt", "r");
    fseek(file, linha, SEEK_SET);
    fread(ps -> nome, sizeof(ps -> nome), 1, file);
    fread(&ps -> qtd_atual, sizeof(ps -> qtd_atual), 1, file);
    fread(&ps -> qtd_min, sizeof(ps -> qtd_min), 1, file);
    fread(&ps -> dia_validade, sizeof(ps -> dia_validade), 1, file);
    fread(&ps -> mes_validade, sizeof(ps -> mes_validade), 1, file);
    fread(&ps -> ano_validade, sizeof(ps -> ano_validade), 1, file);
    fclose(file);
}

void zerar_estrutura(struct estoque *ps)
{
    int i;

    for(i = 0; i < (sizeof(ps -> nome) - 1); i++){
        ps -> nome[i] = '\0';
    }
    ps -> qtd_atual = 0;
    ps -> qtd_min = 0;
    ps -> dia_validade = 0;
    ps -> mes_validade = 0;
    ps -> ano_validade = 0;
}

void menu_cadastrar(struct estoque *ps)
{
    int i;
    char menu;

    for(i = 0; i < NUM_PROD; i++){
        printf("Entre com os dados do produto que deseja cadastrar!\n\n");
        printf("Nome do produto %d: ", i + 1);
        gets(ps -> nome);
        printf("Quantidade Atual do produto %d: ", i + 1);
        scanf("%d", &ps -> qtd_atual);
        printf("Quantidade M�nima do produto %d: ", i + 1);
        scanf("%d", &ps -> qtd_min);
        printf("Data de validade do produto %d(DD/MM/AA): ", i + 1);
        scanf("%d/%d/%d", &ps -> dia_validade, &ps -> mes_validade, &ps -> ano_validade);

        if(i == 0){
            escreverEstrutura(ps, "w", 0);
        }else{
            escreverEstrutura(ps, "a", 0);
        }
        lbuffer();
        system("cls");
    }
    system("cls");
    printf("\aTODOS OS DADOS DE PRODUTO FORAM INSERIDOS!\n");
    printf("\nPressione 'B' para voltar ao menu\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b');
    if(menu == 'B' || menu == 'b'){system("cls");main();}
}

void menu_listar(struct estoque *ps)
{
    printf("Quantidade Atual do produto 1: ");
    scanf("%d", &ps->qtd_atual);
    printf("%d", ps->qtd_atual);
}

void menu_pesquisar_nome(struct estoque *ps)
{
    printf("%d", sizeof(struct estoque)); //Teste do menu
}

void menu_pesquisar_letra(struct estoque *ps)
{
    printf("4"); //Teste do menu
}

void menu_pesquisar_validade(struct estoque *ps)
{
    printf("5"); //Teste do menu
}

void menu_listar_qtdmin(struct estoque *ps)
{
    printf("6"); //Teste do menu
}

void menu_movimentar(struct estoque *ps)
{
    printf("7"); //Teste do menu
}

void menu_alterar(struct estoque *ps)
{
    printf("8"); //Teste do menu
}

void menu_excluir(struct estoque *ps)
{
    printf("9"); //Teste do menu
}

void sair(struct estoque *ps)
{
    printf("10"); //Teste do menu
}
