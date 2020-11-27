#include <stdio.h> //Funções padrões de entrada e saída
#include <stdlib.h>//Função system
#include <conio.h> //Funções getch e getche
#include <locale.h> //Função de configuração de idioma da tabela ASCII

//Estrutura
struct estoque{
    unsigned char nome[31];
    int qtd_atual; //quantidade atual
    int qtd_min;   //quantidade de estoque mínima
    int mes_validade; //mes da data de validade
    int ano_validade; //ano da data de validade
};

//Protótipo das Funções
void lbuffer(void); //Função para limpar o buffer que funciona em todos os SOs
void escreverEstrutura(struct estoque *ps, char *modo, int linha); //Função pra escrever uma estrutura no arquivo
int lerEstrutura(struct estoque *ps, int linha); //Função pra ler uma estrutura no arquivo
void zerar_estrutura(struct estoque *ps); //Função que zera todas as variáveis da estrutura
int compara_nome(struct estoque *ps, char *nome); //Função que compara nomes
int compara_letra(struct estoque *ps, char letra); //Função que compara letras
void compara_data(struct estoque *ps, int mes, int ano); //Função que compara data de validade
void movimenta_estoque(struct estoque *ps, int movimentacao);
void menu_cadastrar(struct estoque *ps); //Função do menu de cadastramento de produtos
void menu_listar(struct estoque *ps); //Função do menu de listar produtos
void menu_pesquisar_nome(struct estoque *ps); //Função do menu de pesquisa de produto por nome
void menu_pesquisar_letra(struct estoque *ps); //Função do menu de pesquisa de produto por primeira letra
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

void escreverEstrutura(struct estoque *ps, char *modo, int linha)
{
    FILE *file;
    int i;
    int _struct = sizeof(struct estoque); //Define o tamanho da estrutura de um produto
    linha = linha * _struct; //Define até onde o fseek vai pra escrever o dado

    file = fopen("estoque.txt", modo);
    if(linha != 0){fseek(file, linha, SEEK_SET);}
    fwrite(ps, sizeof(*ps), 1, file);
    fclose(file);

    zerar_estrutura(ps); //Zera a estrutura depois de escrever no arquivo para evitar lixo
}

int lerEstrutura(struct estoque *ps, int linha)
{
    FILE *file;
    int i;
    int _struct = sizeof(struct estoque); //Define o tamanho da estrutura de um produto
    linha = linha * _struct; //Define até onde o fseek vai pra buscar o dado

    zerar_estrutura(ps); //Zera a estrutura antes de ler do arquivo para evitar lixo

    file = fopen("estoque.txt", "r");
    fseek(file, linha, SEEK_SET);
    i = fread(ps, sizeof(*ps), 1, file);
    fclose(file);

    return i;
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

int compara_nome(struct estoque *ps, char *nome)
{
    int i, j, correto = 0, fread = 1;

    //Roda o for até o fim do arquivo, pegando o nome de cada produto e vendo se bate com o nome informado
    for(i = 0; fread != 0; i++){
        fread = lerEstrutura(ps, i);
        for(j = 0; nome[j] != '\0'; j++){
            if(ps -> nome[j] != nome[j]){
                break;
            }
        }
        if(nome[j] == '\0' && ps ->nome[j] == '\0'){ //Se o número de letras corretas for igual ao de letras no nome do produto retorna o índice
            return i;
        }
    }

    return -1;
}

int compara_letra(struct estoque *ps, char letra)
{
    int i, fread = 1, correto = 0;
    char letra2;

    //Roda o for até o fim do arquivo, pegando o nome de cada produto e vendo se a letra informada bate, sendo maiúscula ou minúscula
    for(i = 0; fread != 0; i++){
        fread = lerEstrutura(ps, i);
        if(letra >= 'a' && letra <= 'z'){letra2 = letra - 32;}
        else if(letra >= 'A' && letra <= 'Z'){letra2 = letra + 32;}
        if(ps -> nome[0] == letra || ps -> nome[0] == letra2){
            printf("==================================|PRODUTO %3d|==================================\n", i + 1);
            printf("Nome do produto: %s\n", ps->nome);
            printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
            printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
            printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
            correto++;
        }
    }
    if(correto == 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }
}

void compara_data(struct estoque *ps, int mes, int ano)
{
    int i, correto = 0, fread = 1;

    for(i = 0; fread != 0; i++){
        fread = lerEstrutura(ps, i);

        if(ps -> mes_validade == mes && ps -> ano_validade == ano){
            printf("==================================|PRODUTO %3d|==================================\n", i + 1);
            printf("Nome do produto: %s\n", ps->nome);
            printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
            printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
            printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
            correto++;
        }
    }
    if(correto == 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }
}

void compara_estoque(struct estoque *ps)
{
    int i, correto = 0, fread = 1;

    for(i = 0; fread != 0; i++){
        fread = lerEstrutura(ps, i);

        if(ps -> qtd_atual < ps -> qtd_min){
            printf("==================================|PRODUTO %3d|==================================\n", i + 1);
            printf("Nome do produto: %s\n", ps->nome);
            printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
            printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
            printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
            correto++;
        }
    }

    if(correto == 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }
}

void menu_cadastrar(struct estoque *ps)
{
    int iteracao, fread = 1;

    //Laço for para saber qual é o último produto cadastrado e continuar de lá
    for(iteracao = 0; fread != 0; iteracao++){
        fread = lerEstrutura(ps, iteracao);
    }
    iteracao --; //Decremento pelo fato da contagem do produto no programa começar do 1 e não do 0
    printf("Entre com os dados do produto que deseja cadastrar!\n\n");
    printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
    printf("Nome do produto: ");
    gets(ps -> nome);
    printf("Quantidade Atual do produto: ");
    scanf("%d", &ps -> qtd_atual);
    printf("Quantidade Mínima do produto: ");
    scanf("%d", &ps -> qtd_min);
    printf("Data de validade do produto (MM/AA): ");
    scanf("%d/%d", &ps -> mes_validade, &ps -> ano_validade);
    printf("=================================================================================\n");

    escreverEstrutura(ps, "ab", 0);

    lbuffer();
    system("cls");
    main();
}

void menu_listar(struct estoque *ps)
{
    int i, fread = 1;
    char menu;

    printf("Lista de todos produtos cadastrados\n\n");
    fread = lerEstrutura(ps, 0);
    for(i = 0; fread != 0; i++){
        if(ps -> nome[0] == '*'){fread = lerEstrutura(ps, i + 1);continue;}
        printf("==================================|PRODUTO %3d|==================================\n", i + 1);
        printf("Nome do produto: %s\n", ps->nome);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
        fread = lerEstrutura(ps, i + 1); //Pega o valor do fread da próxima iteração pra parar no tempo certo
    }

    printf("\n");
    system("pause");
    system("cls");
    main();
}

void menu_pesquisar_nome(struct estoque *ps)
{
    int iteracao;
    char pesquisa[31];

    printf("Procura produto por nome\n\n");
    printf("Digite o nome do produto que deseja procurar: ");
    gets(pesquisa);
    iteracao = compara_nome(ps, pesquisa);

    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Nome do produto: %s\n", ps->nome);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);
    }

    printf("\n");
    system("pause");
    system("cls");
    main();
}

void menu_pesquisar_letra(struct estoque *ps)
{
    char pesquisa;

    printf("Procura produto por primeira letra\n\n");
    printf("Digite a primeira letra do produto que deseja procurar: ");
    pesquisa = getchar();
    compara_letra(ps, pesquisa);

    printf("\n");
    system("pause");
    lbuffer();
    system("cls");
    main();
}

void menu_pesquisar_validade(struct estoque *ps)
{
    int mes, ano;

    printf("Produtos vencidos na data específica\n\n");
    printf("Data da validade (MM/AA): ");
    scanf("%d/%d", &mes, &ano);
    compara_data(ps, mes, ano);

    printf("\n");
    system("pause");
    lbuffer();
    system("cls");
    main();
}

void menu_listar_qtdmin(struct estoque *ps)
{
    printf("Produtos abaixo do estoque mínimo\n\n");
    compara_estoque(ps);

    printf("\n");
    system("pause");
    system("cls");
    main();
}

void menu_movimentar(struct estoque *ps)
{
    int iteracao, movimentacao;
    char pesquisa[31];

    printf("Movimentar Estoque dos Produtos\n\n");
    printf("Digite o nome do produto que deseja movimentar: ");
    gets(pesquisa);
    iteracao = compara_nome(ps, pesquisa);
    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
        system("pause");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Nome do produto: %s\n", ps->nome);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);

        printf("\nNúmero Positivo = Adiciona | Número Negativo = Subtrai\n");
        printf("Digite a movimentação: ");
        scanf("%d", &movimentacao);

        lerEstrutura(ps, iteracao);
        ps -> qtd_atual = ps -> qtd_atual + movimentacao;
        escreverEstrutura(ps, "rb+", iteracao);
    }

    system("cls");
    main();
}

void menu_alterar(struct estoque *ps)
{
    int iteracao;
    char pesquisa[31];

    printf("Alterar Produtos Cadastrados\n\n");
    printf("Digite o nome do produto que deseja alterar: ");
    gets(pesquisa);
    iteracao = compara_nome(ps, pesquisa);
    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Nome do produto: %s\n", ps->nome);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);

        printf("\nNovo nome do produto: ");
        gets(ps -> nome);
        printf("Nova Quantidade Atual do Produto: ");
        scanf("%d", &ps -> qtd_atual);
        printf("Nova Quantidade Mínima do Produto: ");
        scanf("%d", &ps -> qtd_min);
        printf("Nova Data de Validade: ");
        scanf("%d/%d", &ps -> mes_validade, &ps -> ano_validade);

        escreverEstrutura(ps, "rb+", iteracao);
        printf("\n\aPRODUTO ALTERADO COM SUCESSO!\n\n");
    }

    system("pause");
    system("cls");
    main();
}

void menu_excluir(struct estoque *ps)
{
    int iteracao;
    char pesquisa[31];

    printf("Alterar Produtos Cadastrados\n\n");
    printf("Digite o nome do produto que deseja alterar: ");
    gets(pesquisa);
    iteracao = compara_nome(ps, pesquisa);
    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Nome do produto: %s\n", ps->nome);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        printf("Quantidade Mínima do produto: %d\n", ps->qtd_min);
        printf("Data de validade do produto (MM/AA): %d/%d\n", ps->mes_validade, ps->ano_validade);

        ps -> nome[0] = '*';

        escreverEstrutura(ps, "rb+", iteracao);
        printf("\n\aPRODUTO EXCLUÍDO COM SUCESSO!\n\n");
    }

    system("pause");
    system("cls");
    main();
}

void sair(struct estoque *ps)
{
    exit(EXIT_SUCCESS);
}
