#include <stdio.h> //Fun��es padr�es de entrada e sa�da
#include <stdlib.h>//Fun��o system
#include <string.h> //Fun��o strlen
#include <conio.h> //Fun��es getch e getche
#include <locale.h> //Fun��o de configura��o de idioma da tabela ASCII

//Estrutura
struct estoque{
    unsigned char nome[31];
    int qtd_atual; //quantidade atual
    int qtd_min;   //quantidade de estoque m�nima
    int mes_validade;
    int ano_validade;
};

//Prot�tipo das Fun��es
void lbuffer(void); //Fun��o para limpar o buffer que funciona em todos os SOs
void escreverEstrutura(struct estoque *ps, char modo[], int linha); //Fun��o pra escrever uma estrutura no arquivo
void lerEstrutura(struct estoque *ps, int linha); //Fun��o pra ler uma estrutura no arquivo
void zerar_estrutura(struct estoque *ps); //Fun��o que zera todas as vari�veis da estrutura
int  fim_arquivo(); //Fun��o que retorna a quantidade de linhas at� o fim do arquivo
int compara_nome(struct estoque *ps, char nome[]); //Fun��o que compara nomes
int compara_letra(struct estoque *ps, char letra); //Fun��o que compara letras
void menu_cadastrar(struct estoque *ps); //Fun��o do menu de cadastramento de produtos
void menu_listar(struct estoque *ps); //Fun��o do menu de listar produtos
void menu_pesquisar_nome(struct estoque *ps); //Fun��o do menu de pesquisa de produto por nome
void menu_pesquisar_letra(struct estoque *ps); //Fun��o do menu de pesquisa de produto por primeira letra
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
    static int iteracao = 0; //Declara��o da vari�vel que define se o programa acabou de abrir
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
    linha = linha * _struct; //Define o tamanho da linha com todas as vari�veis no arquivo

    zerar_estrutura(ps); //Zera a estrutura antes de ler do arquivo para evitar lixo

    file = fopen("estoque.txt", "r");
    fseek(file, linha, SEEK_SET);
    fread(ps -> nome, sizeof(ps -> nome), 1, file);
    fread(&ps -> qtd_atual, sizeof(ps -> qtd_atual), 1, file);
    fread(&ps -> qtd_min, sizeof(ps -> qtd_min), 1, file);
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
    ps -> mes_validade = 0;
    ps -> ano_validade = 0;
}

int fim_arquivo()
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
        for(j = 0; j < strlen(nome); j++){ //j � o n�mero de caracteres do nome a ser comparado
            if(ps -> nome[j] == nome[j]){
                correto++; //Se a letra n da estrutura for igual a letra n do nome, correto incrementa
            }
        }
        if(correto == strlen(ps ->nome)){
            return i; //se o n�mero de letras iguais for igual ao n�mero de letras do nome da struct ent�o retorna o �ndice do nome igual
        }
        correto = 0;
    }

    return -1; //Se nenhum nome for igual retorna -1
}

int compara_letra(struct estoque *ps, char letra)
{
    int i, correto = 0;
    char letra2;

    for(i = 0; i < (fim_arquivo(ps)); i++){
        lerEstrutura(ps, i);
        if(letra >= 'a' && letra <= 'z'){letra2 = letra - 32;}
        else if(letra >= 'A' && letra <= 'Z'){letra2 = letra + 32;}
        if(ps -> nome[0] == letra || ps -> nome[0] == letra2){
            correto++; //Se a letra n da estrutura for igual a letra n do nome, correto incrementa
        }
        if(correto == 1){
            return i; //se o n�mero de letras iguais for igual ao n�mero de letras do nome da struct ent�o retorna o �ndice do nome igual
        }
        correto = 0;
    }

    return -1; //Se nenhum nome for igual retorna -1
}

void menu_cadastrar(struct estoque *ps)
{
    int i, iteracao;
    char menu;

    iteracao = fim_arquivo(ps); //Roda uma vez fora do la�o for para que o inicializador consigo pegar o valor

    for(i = iteracao; menu != 'B' || menu != 'b'; i++){
        iteracao = fim_arquivo(ps); //Roda a cada itera��o do la�o for para acompanhar o cadastro
        printf("Entre com os dados do produto que deseja cadastrar!\n\n");
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Nome do produto: ");
        gets(ps -> nome);
        printf("Quantidade Atual do produto: ");
        scanf("%d", &ps -> qtd_atual);
        printf("Quantidade M�nima do produto: ");
        scanf("%d", &ps -> qtd_min);
        printf("Data de validade do produto (MM/AA): ");
        scanf("%d/%d", &ps -> mes_validade, &ps -> ano_validade);
        printf("=================================================================================\n");

        //Se � a primeira itera��o chama a fun��o como escrita pra resetar arquivo, caso contr�rio anexa
        if(iteracao == 0){
            escreverEstrutura(ps, "w", 0);
        }else{
            escreverEstrutura(ps, "a", 0);
        }

        printf("\nPressione 'ESPA�O' para adicionar outro produto\n");
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
        printf("Quantidade M�nima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
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
        printf("Digite o nome do produto que deseja procurar: ");
        gets(pesquisa);
        iteracao = compara_nome(ps, pesquisa);

        system("cls");
        if(iteracao < 0){
            printf("Procura produto por nome\n\n");
            printf("Produto com o nome \"%s\"\n", pesquisa);
            printf("\aNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
        }else{
            lerEstrutura(ps, iteracao);
            printf("Procura produto por nome\n\n");
            printf("Produto com o nome \"%s\"\n", pesquisa);
            printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
            printf("Nome do produto: %s\n", ps->nome);
            printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
            printf("Quantidade M�nima do produto: %d\n", ps->qtd_min);
            printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
        }

        printf("\nPressione 'ESPA�O' para procurar outro produto\n");
        printf("Pressione 'B' para voltar ao menu\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
        if(menu == 'B' || menu == 'b'){system("cls");main();}

        system("cls");
    }
}

void menu_pesquisar_letra(struct estoque *ps)
{
    int i, iteracao;
    char menu;
    char pesquisa;

    for(i = 0; menu != 'B' && menu != 'b'; i++){
        printf("Procura produto por primeira letra\n\n");
        printf("Digite a primeira letra do produto que deseja procurar: ");
        pesquisa = getchar();
        iteracao = compara_letra(ps, pesquisa);

        system("cls");
        if(iteracao < 0){
            printf("Procura produto por primeira letra\n\n");
            printf("Produto com a primeira letra \'%c\'\n", pesquisa);
            printf("\aNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
        }else{
            lerEstrutura(ps, iteracao);
            printf("Procura produto por primeira letra\n\n");
            printf("Produto com a primeira letra \'%c\'\n", pesquisa);
            printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
            printf("Nome do produto: %s\n", ps->nome);
            printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
            printf("Quantidade M�nima do produto: %d\n", ps->qtd_min);
            printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
        }

        printf("\nPressione 'ESPA�O' para procurar outro produto\n");
        printf("Pressione 'B' para voltar ao menu\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
        if(menu == 'B' || menu == 'b'){system("cls");main();}

        lbuffer();
        system("cls");
    }
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
