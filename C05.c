#include <stdio.h> //Funções padrões de entrada e saída
#include <stdlib.h>//Função system
#include <string.h> //Função strlen
#include <conio.h> //Funções getch e getche
#include <locale.h> //Função de configuração de idioma da tabela ASCII

//Estrutura
struct estoque{
    unsigned char nome[31];
    int qtd_atual; //quantidade atual
    int qtd_min;   //quantidade de estoque mínima
    int dia_validade;
    int mes_validade;
    int ano_validade;
};

//Protótipo das Funções
void lbuffer(void); //Função para limpar o buffer que funciona em todos os SOs
void escreverEstrutura(struct estoque *ps, char modo[], int linha); //Função pra escrever uma estrutura no arquivo
void lerEstrutura(struct estoque *ps, int linha); //Função pra ler uma estrutura no arquivo
void zerar_estrutura(struct estoque *ps); //Função que zera todas as variáveis da estrutura
int  fim_arquivo(struct estoque *ps); //Função que retorna a quantidade de linhas até o fim do arquivo
int compara_nome(struct estoque *ps, char nome[]); //Função que compara nomes
void menu_cadastrar(struct estoque *ps); //Função do menu de cadastramento de produtos
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
    setlocale(LC_ALL, "portuguese"); //Configura o idioma padrão da ASCII pra português
    static struct estoque produto, *ps; //Declaração da estrutura e seu ponteiro
    static int iteracao = 0; //Declaração da variável que define se o programa acabou de abrir
    int menu; //Declaração da variável do menu principal

    ps = &produto;

    printf("MENU\n");
    printf(" 1. Cadastrar produto\n");
    printf(" 2. Listar produtos cadastrados\n");
    printf(" 3. Pesquisar produto por nome\n");
    printf(" 4. Pesquisar produto pela 1ª letra\n");
    printf(" 5. Pesquisar data de validade\n");
    printf(" 6. Listar produtos abaixo do estoque mínimo\n");
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

//Funções
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
    linha = linha * _struct; //Define o tamanho da linha com todas as variáveis no arquivo

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
    int _struct = (sizeof(struct estoque) - 1);
    linha = linha * _struct; //Define o tamanho da linha com todas as variáveis no arquivo

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

int fim_arquivo(struct estoque *ps)
{
    FILE *file;
    int _struct = (sizeof(struct estoque) - 1);
    int posicao;

    file = fopen("estoque.txt", "r");
    fseek(file, 0, SEEK_END);
    posicao = ftell(file);
    fclose(file);

    return (posicao/_struct);
}

int compara_nome(struct estoque *ps, char nome[])
{
    int i, j, correto = 0;

    for(i = 0; i < (fim_arquivo(ps)); i++){
        lerEstrutura(ps, i);
        for(j = 0; j < strlen(nome); j++){ //j é o número de caracteres do nome a ser comparado
            if(ps -> nome[j] == nome[j]){
                correto++; //Se a letra n da estrutura for igual a letra n do nome, correto incrementa
            }
        }
        if(correto == strlen(ps ->nome)){
            return i; //se o número de letras iguais for igual ao número de letras do nome da struct então retorna o índice do nome igual
        }
        correto = 0;
    }

    return -1; //Se nenhum nome for igual retorna -1
}

void menu_cadastrar(struct estoque *ps)
{
    int i;
    char menu;

    for(i = 0; menu != 'B' || menu != 'b'; i++){
        printf("Entre com os dados do produto que deseja cadastrar!\n\n");
        printf("==================================|PRODUTO %3d|==================================\n", i + 1);
        printf("Nome do produto: ");
        gets(ps -> nome);
        printf("Quantidade Atual do produto: ");
        scanf("%d", &ps -> qtd_atual);
        printf("Quantidade Mínima do produto: ");
        scanf("%d", &ps -> qtd_min);
        printf("Data de validade do produto (DD/MM/AA): ");
        scanf("%d/%d/%d", &ps -> dia_validade, &ps -> mes_validade, &ps -> ano_validade);
        printf("=================================================================================\n");

        //Se é a primeira iteração chama a função como escrita pra resetar arquivo, caso contrário anexa
        if(i == 0){
            escreverEstrutura(ps, "w", 0);
        }else{
            escreverEstrutura(ps, "a", 0);
        }

        printf("\nPressione 'ESPAÇO' para adicionar outro produto\n");
        printf("Pressione 'B' para voltar ao menu\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
        if(menu == 'B' || menu == 'b'){system("cls");main();}

        lbuffer();
        system("cls");
    }
}

void menu_listar(struct estoque *ps)
{
    int i;
    char menu;

    printf("Lista de todos produtos cadastrados\n\n");
    for(i = 0; i < (fim_arquivo(ps)); i++){
        lerEstrutura(ps, i);
        printf("==================================|PRODUTO %3d|==================================\n", i + 1);
        printf("Nome do produto: %s\n", ps->nome);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (DD/MM/AA): %d/%d/%d\n", ps->dia_validade, ps->mes_validade, ps->ano_validade);
    }

    printf("\nPressione 'B' para voltar ao menu\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b');
    if(menu == 'B' || menu == 'b'){system("cls");main();}

    system("cls");
}

void menu_pesquisar_nome(struct estoque *ps)
{
    int i, iteracao;
    char menu;
    char pesquisa[31];

    for(i = 0; menu != 'B' && menu != 'b'; i++){
        printf("Procura produto por nome\n\n");
        printf("Digite o nome o do produto que deseja procurar: ");
        gets(pesquisa);
        iteracao = compara_nome(ps, pesquisa);

        system("cls");
        lerEstrutura(ps, iteracao);
        printf("Procura produto por nome\n\n");
        printf("Produto com o nome \"%s\"\n", pesquisa);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Nome do produto: %s\n", ps->nome);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (DD/MM/AA): %d/%d/%d\n", ps->dia_validade, ps->mes_validade, ps->ano_validade);

        printf("\nPressione 'ESPAÇO' para procurar outro produto\n");
        printf("Pressione 'B' para voltar ao menu\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
        if(menu == 'B' || menu == 'b'){system("cls");main();}

        system("cls");
    }
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
    exit(EXIT_SUCCESS);
}
