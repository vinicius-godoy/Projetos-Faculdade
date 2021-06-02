#define ex1
#include <stdio.h>  //Header pras funções padrões de E/S
#include <stdlib.h> //Header pra função system()
#include <conio.h>  //Header pra função getch() e getche
#include <string.h> //Header pras funções de manipulação de string
#include <locale.h> //Header pra função setlocale()

#ifdef ex1
/*1 - Faça um programa para:
    • criar/abrir um arquivo texto de nome ”arq.txt”,
    • receba via teclado diversos caracteres (um por vezes)e armazene-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados.
    • abra o arquivo. Leia e imprima na tela todos os caracteres armazenados.*/
void main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j;
    char c, menu;
    FILE *pfile;

    do{
    printf("Digite vários caracteres para armazená-los em um arquivo e rever eles!\n");
    pfile = fopen("arq.txt", "w");
    for(i = 0; c != '0'; i++){
        printf("Digite o %-2dº caractere: ", i + 1);
        scanf("%c", &c);
        getchar(); //Evita pegar o ENTER do scanf acima e passar para o de baixo
        putc(c, pfile);
    }
    fclose(pfile);
    system("cls");
    printf("Esses são os caracteres salvos no arquivo:\n");
    pfile = fopen("arq.txt", "r");
    for(j = 0; j < i - 1; j++){
        c = getc(pfile);
        printf("%-2dº caractere digitado: %c \n", j + 1, c);
    }
    fclose(pfile);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{menu = getch();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');system("cls");
    }while(menu == 'S' || menu == 's');
}
#endif // ex1

#ifdef ex2
/*2 - Faça um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversário (dia e mês) em uma estrutura de
    dados.
    O programa deve ter as opções:
    1 - inserir contato
    2 - altera contato
    3 - exclui contato
    4 - pesquisar um contato pelo nome
    5 - listar todos os contatos
    6 - listar os contatos cujo nome inicia com uma letra digitada
    7 - imprimir os aniversariantes do mês.
    Sempre que o programa for encerrado, os contatos devem ser escritos no arquivo.
    Quando o programa iniciar os contatos devem ser lidos do arquivo.
    O vetor de estrutura será de 4 elementos como variavel local na funcao main().
    Utilize ponteiros*/
//Estruturas
struct agenda{
    char nome[41];
    char tel[13];
    int diaAni;
    int mesAni;
};

//Declaração das funções
void lerArquivo(struct agenda *ps);
void escreverArquivo(struct agenda *ps);
int procuraNome(char nome[], struct agenda *ps);
void procuraLetra(char letra, struct agenda *ps);
void excluirContato(struct agenda *ps, int indice);
void menuInserir(struct agenda *ps);
void menuAlterar(struct agenda *ps);
void menuExcluir(struct agenda *ps);
void menuPesquisar(struct agenda *ps);
void menuListar(struct agenda *ps);
void menuListarLetra(struct agenda *ps);
void menuAniversario(struct agenda *ps);

//Programa
void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    static int i = 0;
    static struct agenda contatos[4], *ps;
    FILE *file;

    ps = contatos;

    //Programa lê o arquivo sempre que o programa abre e escreve sempre que volta ao menu
    if(i == 0){lerArquivo(&contatos[0]);i++;}
    else{escreverArquivo(ps);}

    printf("=============================MENU=============================\n");
    printf("1 - inserir contato\n");
    printf("2 - alterar contato\n");
    printf("3 - excluir contato\n");
    printf("4 - pesquisar um contato pelo nome\n");
    printf("5 - listar todos os contatos\n");
    printf("6 - listar os contatos cujo nome inicia com uma letra digitada\n");
    printf("7 - imprimir os aniversariantes do mês\n");
    do{menu = getch();}while(menu != '1' && menu != '2' && menu != '3' && menu != '4' && menu != '5' && menu != '6' && menu != '7');
    system("cls");
    fflush(stdin);

    switch(menu)
    {
    case '1':
        menuInserir(ps);
        break;
    case '2':
        menuAlterar(ps);
        break;
    case '3':
        menuExcluir(ps);
        break;
    case '4':
        menuPesquisar(ps);
        break;
    case '5':
        menuListar(ps);
        break;
    case '6':
        menuListarLetra(ps);
        break;
    case '7':
        menuAniversario(ps);
        break;
    }
}

//Funções
void lerArquivo(struct agenda *ps)
{
    FILE *file;
    int i;

    file = fopen("agenda.txt", "r");
    for(i = 0; i < 4; i++){
       fread(&(ps + i) -> nome, sizeof((ps + i) -> nome), 1, file);
       fread(&(ps + i) -> tel, sizeof((ps + i) -> tel), 1, file);
       fread(&(ps + i) -> diaAni, sizeof((ps + i) -> diaAni), 1, file);
       fread(&(ps + i) -> mesAni, sizeof((ps + i) -> mesAni), 1, file);
    }
    fclose(file);
}

void escreverArquivo(struct agenda *ps)
{
    FILE *file;
    int i;

    file = fopen("agenda.txt", "w");
    for(i = 0; i < 4; i++){
       fwrite(&(ps + i) -> nome, sizeof((ps + i) -> nome), 1, file);
       fwrite(&(ps + i) -> tel, sizeof((ps + i) -> tel), 1, file);
       fwrite(&(ps + i) -> diaAni, sizeof((ps + i) -> diaAni), 1, file);
       fwrite(&(ps + i) -> mesAni, sizeof((ps + i) -> mesAni), 1, file);
    }
    fclose(file);
}

int procuraNome(char nome[], struct agenda *ps)
{
    int i, j, correto = 0;

    for(i = 0; i < 4; i++){ //4 é o número de contatos na agenda
        for(j = 0; j < strlen(nome); j++){ //j é o número de caracteres do nome a ser comparado
            if((ps + i)-> nome[j] == nome[j]){
                correto++; //Se a letra n da estrutura for igual a letra n do nome, correto incrementa
            }
        }
        if(correto == strlen((ps + i)->nome)){
            return i; //se o número de letras iguais for igual ao número de letras do nome da struct então retorna o índice do nome igual
        }
        correto = 0;
    }

    return -1; //Se nenhum nome for igual retorna -1
}

void procuraLetra(char letra, struct agenda *ps)
{
    int i, correto = 0;
    char letra2;

    for(i = 0; i < 4; i++){ //4 é o número de contatos na agenda
        if(letra >= 'a' && letra <= 'z'){
            letra2 = letra - 32;
        }else if(letra >= 'A' && letra <= 'Z'){
            letra2 = letra + 32;
        }

        if((ps + i)-> nome[0] == letra || (ps + i)-> nome[0] == letra2){
            correto++;
            printf("\n~~~~~~~~~~~~~~~~~~~~CONTATO %d~~~~~~~~~~~~~~~~~~~~\n", i + 1);
            printf("Nome:    %40s\n", (ps + i) -> nome);
            printf("Telefone:%40s\n", (ps + i) -> tel);
            printf("Aniversário:                                %2d/%2d\n", (ps + i) -> diaAni, (ps + i) -> mesAni);
        }
    }

    if(correto == 0){printf("\a\nNENHUM CONTATO COM O MESMO NOME ENCONTRADO\n");}
}

void excluirContato(struct agenda *ps, int indice)
{
    int i;

    for(i = 0; i < sizeof(ps[indice].nome) - 1; i++){
        ps[indice].nome[i] = ' ';
    }

    for(i = 0; i < sizeof(ps[indice].tel) - 1; i++){
        ps[indice].tel[i] = ' ';
    }

    ps[indice].diaAni = '\0';
    ps[indice].mesAni = '\0';
}

void menuInserir(struct agenda *ps)
{
    int i;
    char menu;

    for(i = 0; i < 4; i++){
            printf("INSERIR CONTATOS\n");
            printf("Digite as informações pedidas para cada contato\n");
            printf("Nome do %dº contato: ", i + 1);
            gets(ps[i].nome);
            printf("Telefone do %dº contato: ", i + 1);
            gets(ps[i].tel);
            printf("Aniversário do %dº contato (DD/MM): ", i + 1);
            scanf("%d/%d", &ps[i].diaAni, &ps[i].mesAni);
            getchar(); //Pega o enter do aniversário acima
            system("cls");
        }

        printf("INSERIR CONTATOS\n");
        printf("\aAgenda Preenchida !\n");
        printf("\nVoltar ao Menu - Pressione 'B'\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b');
        if(menu == 'B' || menu == 'b'){system("cls");main();}
}

void menuAlterar(struct agenda *ps)
{
    char pesquisa[41], menu;
    int igual;

    do{
    printf("ALTERAR CONTATOS\n");
    printf("Digite o nome do contato que deseja alterar: ");
    gets(pesquisa);
    igual = procuraNome(pesquisa, ps);
    printf("Contato com o mesmo nome:\n");
    if(igual < 0){printf("\a\nNENHUM CONTATO COM O MESMO NOME ENCONTRADO\n");}
    else{
        printf("\n~~~~~~~~~~~~~~~~~~~~CONTATO %d~~~~~~~~~~~~~~~~~~~~\n", igual + 1);
        printf("Nome:    %40s\n", (ps + igual) -> nome);
        printf("Telefone:%40s\n", (ps + igual) -> tel);
        printf("Aniversário:                                %2d/%2d\n", (ps + igual) -> diaAni, (ps + igual) -> mesAni);

        printf("\nDeseja alterar esse contato ? (S/N)     ");
        do{menu = getche();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');
        if(menu == 'N' || menu == 'n'){main();}
        system("cls");
        printf("\n\nDigite o novo nome do contato: ");
        gets(ps[igual].nome);
        printf("Digite o novo telefone do contato: ");
        gets(ps[igual].tel);
        printf("Digite o novo aniversário do contato: ");
        scanf("%d/%d", &ps[igual].diaAni, &ps[igual].mesAni);
        printf("\a\nCONTATO ALTERADO COM SUCESSO!\n");
    }

    printf("\nVoltar ao Menu - Pressione 'B'\n");
    printf("Alterar outro contato - Pressione 'ESPAÇO'\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    if(menu == 'B' || menu == 'b'){system("cls");main();}
    system("cls");
    }while(menu == ' ');
}

void menuExcluir(struct agenda *ps)
{
    char pesquisa[41], menu;
    int igual;

    do{
    printf("EXCLUIR CONTATOS\n");
    printf("Digite o nome do contato que deseja excluir: ");
    gets(pesquisa);
    igual = procuraNome(pesquisa, ps);
    printf("Contato com o mesmo nome:\n");
    if(igual < 0){printf("\a\nNENHUM CONTATO COM O MESMO NOME ENCONTRADO\n");}
    else{
        printf("\n~~~~~~~~~~~~~~~~~~~~CONTATO %d~~~~~~~~~~~~~~~~~~~~\n", igual + 1);
        printf("Nome:    %40s\n", (ps + igual) -> nome);
        printf("Telefone:%40s\n", (ps + igual) -> tel);
        printf("Aniversário:                                %2d/%2d\n", (ps + igual) -> diaAni, (ps + igual) -> mesAni);

        printf("\nDeseja mesmo excluir esse contato ? (S/N)     ");
        do{menu = getche();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');
        if(menu == 'N' || menu == 'n'){main();}
        system("cls");
        excluirContato(ps, igual);
        printf("\a\nCONTATO EXCLUÍDO COM SUCESSO!\n");
    }

    printf("\nVoltar ao Menu - Pressione 'B'\n");
    printf("Alterar outro contato - Pressione 'ESPAÇO'\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    if(menu == 'B' || menu == 'b'){system("cls");main();}
    system("cls");
    }while(menu == ' ');
}

void menuPesquisar(struct agenda *ps)
{
    char pesquisa[41], menu;
    int igual;

    do{
    printf("PESQUISAR CONTATOS\n");
    printf("Digite o nome do contato que deseja pesquisar: ");
    gets(pesquisa);
    igual = procuraNome(pesquisa, ps);
    printf("Contato com o mesmo nome:\n");
    if(igual < 0){printf("\a\nNENHUM CONTATO COM O MESMO NOME ENCONTRADO\n");}
    else{
        printf("\n~~~~~~~~~~~~~~~~~~~~CONTATO %d~~~~~~~~~~~~~~~~~~~~\n", igual + 1);
        printf("Nome:    %40s\n", (ps + igual) -> nome);
        printf("Telefone:%40s\n", (ps + igual) -> tel);
        printf("Aniversário:                                %2d/%2d\n", (ps + igual) -> diaAni, (ps + igual) -> mesAni);
    }

    printf("\nVoltar ao Menu - Pressione 'B'\n");
    printf("Pesquisar outro contato - Pressione 'ESPAÇO'\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    if(menu == 'B' || menu == 'b'){system("cls");main();}
    system("cls");
    }while(menu == ' ');
}

void menuListar(struct agenda *ps)
{
    int i;
    char menu;

    printf("LISTA DA AGENDA\n\n");
    for(i = 0; i < 4; i++){
        printf("~~~~~~~~~~~~~~~~~~~~CONTATO %d~~~~~~~~~~~~~~~~~~~~\n", i + 1);
        printf("Nome:    %40s\n", (ps + i) -> nome);
        printf("Telefone:%40s\n", (ps + i) -> tel);
        printf("Aniversário:                                %2d/%2d\n", (ps + i) -> diaAni, (ps + i) -> mesAni);
    }

    printf("\nVoltar ao Menu - Pressione 'B'\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b');
    if(menu == 'B' || menu == 'b'){system("cls");main();}
}

void menuListarLetra(struct agenda *ps)
{
    char letra, menu;
    int igual;

    do{
    printf("PESQUISAR CONTATOS\n");
    fflush(stdin);
    printf("Digite a primeira letra do nome do contato que deseja pesquisar: ");
    scanf("%c", &letra);
    procuraLetra(letra, ps);
    printf("\nVoltar ao Menu - Pressione 'B'\n");
    printf("Pesquisar outro contato - Pressione 'ESPAÇO'\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    if(menu == 'B' || menu == 'b'){system("cls");main();}
    system("cls");
    }while(menu == ' ');
}

void menuAniversario(struct agenda *ps)
{
    int i, mes;
    char menu;

    do{
    printf("ANIVERSARIANTES DO MÊS\n");
    printf("Digite o mês que você deseja ver os aniversariantes (número): ");
    scanf("%d", &mes);

    for(i = 0; i < 4; i++){
        if((ps + i) -> mesAni == mes){
            printf("\n~~~~~~~~~~~~~~~~~~~~CONTATO %d~~~~~~~~~~~~~~~~~~~~\n", i + 1);
            printf("Nome:    %40s\n", (ps + i) -> nome);
            printf("Telefone:%40s\n", (ps + i) -> tel);
            printf("Aniversário:                                %2d/%2d\n", (ps + i) -> diaAni, (ps + i) -> mesAni);
        }
    }

    printf("\nVoltar ao Menu - Pressione 'B'\n");
    printf("Ver aniversariantes de outro mês - Pressione 'ESPAÇO'\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    if(menu == 'B' || menu == 'b'){system("cls");main();}
    system("cls");
    }while(menu == ' ');
}
#endif // ex2

#ifdef ex3
/*3 - Faça um programa para o controle de mercadorias em uma despensa doméstica.
    Cada produto será armazenado um código numérico, descrição e quantidade atual
    numa estrutura de dados. Utilize ponteiros. A estrutura deve ser declarada como
    variavel local na funcao main().
    O programa deve ter as opções:
    1 - inclui produtos
    2 - altera produtos
    3 - exclui produtos
    4 - pesquisar uma mercadoria pela descrição
    5 - listar todos os produtos
    6 - listar os produtos não disponíveis.
    7 - alterar a quantidade atual
    Escreva os itens das mercadorias direto no arquivo. (utilize a funcao fseek).*/
//Estrutura
struct despensa{
    char cod_num[7];
    char descricao[51];
    int qtd_atual;
};

//Protótipo das Funções
void lbuffer(void);
void escreverEstrutura(struct despensa *ps, char *modo, int linha);
int lerEstrutura(struct despensa *ps, int linha);
void zerar_estrutura(struct despensa *ps);
int fim_arquivo();
int compara_descricao(struct despensa *ps, char *descricao);
void compara_disponibilidade(struct despensa *ps);
void movimenta_despensa(struct despensa *ps, int movimentacao);
void menu_cadastrar(struct despensa *ps);
void menu_listar(struct despensa *ps);
void menu_pesquisar_descricao(struct despensa *ps);
void menu_listar_naoDisponivel(struct despensa *ps);
void menu_movimentar(struct despensa *ps);
void menu_alterar(struct despensa *ps);
void menu_excluir(struct despensa *ps);
void sair(struct despensa *ps);

//Programa
void main(void)
{
    system("cls");
    setlocale(LC_ALL, "portuguese");
    static struct despensa produto, *ps;
    int menu;

    ps = &produto;

    printf("MENU\n");
    printf(" 1. Cadastrar produto\n");
    printf(" 2. Altera produto cadastrado\n");
    printf(" 3. Exclui produto cadastrado\n");
    printf(" 4. Pesquisar produto pela descrição\n");
    printf(" 5. Listar todos os produtos\n");
    printf(" 6. Listar produtos não disponíveis\n");
    printf(" 7. Alterar quantidade atual\n");
    printf("\nResposta -> ");

    do{scanf("%d", &menu);}while(menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5 && menu != 6 && menu != 7 && menu != 8 && menu != 9 && menu != 10);

    switch(menu)
    {
    case 1:
        system("cls");
        lbuffer();
        menu_cadastrar(ps);
        break;
    case 2:
        system("cls");
        lbuffer();
        menu_alterar(ps);
        break;
    case 3:
        system("cls");
        lbuffer();
        menu_excluir(ps);
        break;
    case 4:
        system("cls");
        lbuffer();
        menu_pesquisar_descricao(ps);
        break;
    case 5:
        system("cls");
        lbuffer();
        menu_listar(ps);
        break;
    case 6:
        system("cls");
        lbuffer();
        menu_listar_naoDisponivel(ps);
        break;
    case 7:
        system("cls");
        lbuffer();
        menu_movimentar(ps);
        break;
    case 8:
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

void escreverEstrutura(struct despensa *ps, char *modo, int linha)
{
    FILE *file;
    int i;
    int _struct = sizeof(struct despensa);
    linha = linha * _struct;

    file = fopen("despensa.txt", modo);
    if(linha != 0){fseek(file, linha, SEEK_SET);}
    fwrite(ps, sizeof(*ps), 1, file);
    fclose(file);

    zerar_estrutura(ps);
}

int lerEstrutura(struct despensa *ps, int linha)
{
    FILE *file;
    int i;
    int _struct = sizeof(struct despensa);
    linha = linha * _struct;

    zerar_estrutura(ps);

    file = fopen("despensa.txt", "r");
    fseek(file, linha, SEEK_SET);
    i = fread(ps, sizeof(*ps), 1, file);
    fclose(file);

    return i;
}

void zerar_estrutura(struct despensa *ps)
{
    int i;

    for(i = 0; i < (sizeof(ps -> cod_num) - 1); i++){
        ps -> cod_num[i] = '\0';
    }
    for(i = 0; i < (sizeof(ps -> descricao) - 1); i++){
        ps -> descricao[i] = '\0';
    }
    ps -> qtd_atual = 0;
}

int compara_descricao(struct despensa *ps, char *descricao)
{
    int i, j, correto = 0, fread = 1;

    for(i = 0; fread != 0; i++){
        fread = lerEstrutura(ps, i);
        for(j = 0; descricao[j] != '\0'; j++){
            if(ps -> descricao[j] != descricao[j]){
                break;
            }
        }
        if(descricao[j] == '\0' && ps -> descricao[j] == '\0'){
            return i;
        }
    }

    return -1;
}

void compara_disponibilidade(struct despensa *ps)
{
    int i, correto = 0, fread = 1;

    for(i = 0; fread != 0; i++){
        fread = lerEstrutura(ps, i);

        if(ps -> qtd_atual < 1 && fread == 1){
            printf("==================================|PRODUTO %3d|==================================\n", i + 1);
            printf("Código do produto: %s\n", ps->cod_num);
            printf("Quantidade Mínima do produto: %s\n", ps->descricao);
            printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
            correto++;
        }
    }

    if(correto == 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }
}

void menu_cadastrar(struct despensa *ps)
{
    int iteracao, fread = 1;

    for(iteracao = 0; fread != 0; iteracao++){
        fread = lerEstrutura(ps, iteracao);
    }
    iteracao --;
    printf("Entre com os dados do produto que deseja cadastrar!\n\n");
    printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
    printf("Código do produto: ");
    gets(ps -> cod_num);
    printf("Descrição do produto: ");
    gets(ps -> descricao);
    printf("Quantidade Atual do produto: ");
    scanf("%d", &ps -> qtd_atual);
    printf("=================================================================================\n");

    escreverEstrutura(ps, "ab", 0);

    lbuffer();
    system("cls");
    main();
}

void menu_listar(struct despensa *ps)
{
    int i, fread = 1;
    char menu;

    printf("Lista de todos produtos cadastrados\n\n");
    fread = lerEstrutura(ps, 0);
    for(i = 0; fread != 0; i++){
        if(ps -> cod_num[0] == '*'){fread = lerEstrutura(ps, i + 1);continue;}
        printf("==================================|PRODUTO %3d|==================================\n", i + 1);
        printf("Código do produto: %s\n", ps->cod_num);
        printf("Quantidade Mínima do produto: %s\n", ps->descricao);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
        fread = lerEstrutura(ps, i + 1); //Pega o valor do fread da próxima iteração pra parar no tempo certo
    }

    printf("\n");
    system("pause");
    system("cls");
    main();
}

void menu_pesquisar_descricao(struct despensa *ps)
{
    int iteracao;
    char pesquisa[51];

    printf("Procura produto por descrição\n\n");
    printf("Digite a descrição do produto que deseja procurar: ");
    gets(pesquisa);
    iteracao = compara_descricao(ps, pesquisa);

    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Código do produto: %s\n", ps->cod_num);
        printf("Quantidade Mínima do produto: %s\n", ps->descricao);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);
    }

    printf("\n");
    system("pause");
    system("cls");
    main();
}

void menu_listar_naoDisponivel(struct despensa *ps)
{
    printf("Produtos não disponíveis\n\n");
    compara_disponibilidade(ps);

    printf("\n");
    system("pause");
    system("cls");
    main();
}

void menu_movimentar(struct despensa *ps)
{
    int iteracao, movimentacao;
    char pesquisa[51];

    printf("Movimentar despensa\n\n");
    printf("Digite a descrição do produto que deseja movimentar: ");
    gets(pesquisa);
    iteracao = compara_descricao(ps, pesquisa);
    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
        system("pause");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Código do produto: %s\n", ps->cod_num);
        printf("Quantidade Mínima do produto: %s\n", ps->descricao);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);

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

void menu_alterar(struct despensa *ps)
{
    int iteracao;
    char pesquisa[31];

    printf("Alterar Produtos na Despensa\n\n");
    printf("Digite a descrição do produto que deseja alterar: ");
    gets(pesquisa);
    iteracao = compara_descricao(ps, pesquisa);
    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Código do produto: %s\n", ps->cod_num);
        printf("Quantidade Mínima do produto: %s\n", ps->descricao);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);

        printf("\nNovo código do produto: ");
        gets(ps -> cod_num);
        printf("Nova descrição do Produto: ");
        gets(ps -> descricao);
        printf("Nova Quantidade Atual do Produto: ");
        scanf("%d", &ps -> qtd_atual);

        escreverEstrutura(ps, "rb+", iteracao);
        printf("\n\aPRODUTO ALTERADO COM SUCESSO!\n\n");
    }

    system("pause");
    system("cls");
    main();
}

void menu_excluir(struct despensa *ps)
{
    int iteracao;
    char pesquisa[51];

    printf("Alterar Produtos na Despensa\n\n");
    printf("Digite a descrição do produto que deseja alterar: ");
    gets(pesquisa);
    iteracao = compara_descricao(ps, pesquisa);
    if(iteracao < 0){
        printf("\a\nNENHUM PRODUTO COM OS REQUISITOS ENCONTRADOS\n\n");
    }else{
        lerEstrutura(ps, iteracao);
        printf("==================================|PRODUTO %3d|==================================\n", iteracao + 1);
        printf("Código do produto: %s\n", ps->cod_num);
        printf("Quantidade Mínima do produto: %s\n", ps->descricao);
        printf("Quantidade Atual do produto: %d\n", ps->qtd_atual);

        ps -> cod_num[0] = '*';

        escreverEstrutura(ps, "rb+", iteracao);
        printf("\n\aPRODUTO EXCLUÍDO COM SUCESSO!\n\n");
    }

    system("pause");
    system("cls");
    main();
}

void sair(struct despensa *ps)
{
    exit(EXIT_SUCCESS);
}

#endif // ex3

#ifdef ex4
/*4 - A partir do exercico 6 do capitulo de funcoes, retire o vetor de estrutura e
    escreva e leia os registros direto no arquivo. (utilize a funcao fseek).*/
//Estruturas
struct dados_pessoa{
    char nome[41];
    char end[51];
    char cidade[21];
    char estado[3];
    char cep[9];
};

//Protótipo das funções
void escreverVariavel(struct dados_pessoa *ps, char modo[], int linha);
void lerVariavel(struct dados_pessoa *ps, int contador);
void entrarDados(struct dados_pessoa *ps);
void escreverDados(struct dados_pessoa *ps);
int procuraNome(char nome[], struct dados_pessoa *ps);
void procuraDados(struct dados_pessoa *ps);
void alteraDados(struct dados_pessoa *ps);
void excluiDados(struct dados_pessoa *ps);

//Programa
void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    char *pmenu = &menu;
    static struct dados_pessoa pessoas, *ps;

    ps = &pessoas;

    printf("MENU\n");
    printf("1. Entrar com os dados\n");
    printf("2. Ver os dados\n");
    printf("3. Procura um dado\n");
    printf("4. Altera um dado\n");
    printf("5. Exclui um dado\n");
    printf("6. Sair\n");
    do{*pmenu = getch();}while(*pmenu != '1' && *pmenu != '2' && *pmenu != '3' && *pmenu != '4' && *pmenu != '5' && *pmenu != '6');
    system("cls");
    fflush(stdin);

    switch(*pmenu)
    {
    case '1':
        entrarDados(ps);
        break;
    case '2':
        escreverDados(ps);
        break;
    case '3':
        procuraDados(ps);
        break;
    case '4':
        alteraDados(ps);
        break;
    case '5':
        excluiDados(ps);
        break;
    case '6':
        exit(EXIT_SUCCESS);
        break;
    }
}

//Funções

void escreverVariavel(struct dados_pessoa *ps, char modo[], int linha)
{
    FILE *file;
    int i;
    linha = linha * 125;

    file = fopen("clientes.txt", modo);
    if(linha != 0){fseek(file, linha, SEEK_SET);}
    fwrite(ps -> nome, sizeof(ps -> nome), 1, file);
    fwrite(ps -> end, sizeof(ps -> end), 1, file);
    fwrite(ps -> cidade, sizeof(ps -> cidade), 1, file);
    fwrite(ps -> estado, sizeof(ps -> estado), 1, file);
    fwrite(ps -> cep, sizeof(ps -> cep), 1, file);
    fclose(file);

    memset(ps -> nome, '\0', 40);
    memset(ps -> end, '\0', 50);
    memset(ps -> cidade, '\0', 20);
    memset(ps -> estado, '\0', 2);
    memset(ps -> cep, '\0', 8);
}

void lerVariavel(struct dados_pessoa *ps, int linha)
{
    FILE *file;
    int i;
    linha = linha * 125;

    memset(ps -> nome, '\0', 40);
    memset(ps -> end, '\0', 50);
    memset(ps -> cidade, '\0', 20);
    memset(ps -> estado, '\0', 2);
    memset(ps -> cep, '\0', 8);

    file = fopen("clientes.txt", "r");
    fseek(file, linha, SEEK_SET);
    fread(ps -> nome, sizeof(ps -> nome), 1, file);
    fread(ps -> end, sizeof(ps -> end), 1, file);
    fread(ps -> cidade, sizeof(ps -> cidade), 1, file);
    fread(ps -> estado, sizeof(ps -> estado), 1, file);
    fread(ps -> cep, sizeof(ps -> cep), 1, file);
    fclose(file);
}

void entrarDados(struct dados_pessoa *ps)
{
    int i, *pi = &i;
    char menu, *pmenu = &menu;

    for(*pi = 0; *pi < 4; (*pi)++){
        printf("Entre com os dados pedidos para 4 pessoas!\n");
        printf("Nome da %dº pessoa: ", *pi + 1);
        gets(ps -> nome);
        printf("Endereço da %dº pessoa: ", *pi + 1);
        gets(ps -> end);
        printf("Cidade da %dº pessoa: ", *pi + 1);
        gets(ps -> cidade);
        printf("Estado da %dº pessoa(2 letras): ", *pi + 1);
        gets(ps -> estado);
        printf("CEP da %dº pessoa(Sem traços ou pontos): ", *pi + 1);
        gets(ps -> cep);
        if(*pi == 0){
            escreverVariavel(ps, "w", 0);
        }else{
            escreverVariavel(ps, "a", 0);
        }
        system("cls");
    }
    system("cls");
    printf("\aTODOS OS DADOS FORAM INSERIDOS!\n");
    printf("\nPressione 'B' para voltar ao menu\n");
    do{*pmenu = getch();}while(*pmenu != 'B' && *pmenu != 'b');
    if(*pmenu == 'B' || *pmenu == 'b'){system("cls");main();}
}

void escreverDados(struct dados_pessoa *ps)
{
    int i, *pi = &i;
    char menu, *pmenu = &menu;

    printf("Dados do sistema\n");
    for(*pi = 0; *pi < 4; (*pi)++){
        lerVariavel(ps, *pi);
        printf("Nome da %dº pessoa:                      %50s\n", (*pi) + 1, ps -> nome);
        printf("Endereço da %dº pessoa:                  %50s\n", (*pi) + 1, ps -> end);
        printf("Cidade da %dº pessoa:                    %50s\n", (*pi) + 1, ps -> cidade);
        printf("Estado da %dº pessoa:                    %50s\n", (*pi) + 1, ps -> estado);
        printf("CEP da %dº pessoa:                       %50s\n", (*pi) + 1, ps -> cep);
        printf("-----------------------------------------------------------------------------------\n");
    }
    printf("\nPressione 'B' para voltar ao menu\n");
    do{*pmenu = getch();}while(*pmenu != 'B' && *pmenu != 'b');
    if(*pmenu == 'B' || *pmenu == 'b'){system("cls");main();}
}

int procuraNome(char nome[], struct dados_pessoa *ps)
{
    int i, j, correto = 0;

    for(i = 0; i < 4; i++){
        lerVariavel(ps, i);
        for(j = 0; j < strlen(nome); j++){
            if(ps -> nome[j] == nome[j]){
                correto++;
            }
        }
        if(correto == strlen(ps -> nome)){
            return i;
        }
        correto = 0;
    }

    return -1;
}

void procuraDados(struct dados_pessoa *ps)
{
    int iteracao;
    char menu, nome[41];

    do{
    printf("Procura por nome\n");
    printf("Digite o nome que deseja procurar: ");
    gets(nome);
    iteracao = procuraNome(nome, ps);
    if(iteracao == -1){printf("\n\aNENHUM DADO ENCONTRADO COM O NOME DIGITADO!\n");}
    else{
        lerVariavel(ps, iteracao);
        printf("\nCLIENTE %d\n", iteracao + 1);
        printf("Nome:          %50s\n", ps -> nome);
        printf("Endereço:      %50s\n", ps -> end);
        printf("Cidade:        %50s\n", ps -> cidade);
        printf("Estado:        %50s\n", ps -> estado);
        printf("CEP:           %50s\n", ps -> cep);
    }

    printf("\nPressione 'B' para voltar ao menu\n");
    printf("Pressione 'ESPAÇO' para procurar outro nome\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    system("cls");
    if(menu == 'B' || menu == 'b'){main();}
    }while(menu == ' ');
}

void alteraDados(struct dados_pessoa *ps)
{
    int iteracao;
    char menu, nome[41], novoNome[41];

    do{
    printf("Alterar um dado\n");
    printf("Digite o nome que deseja alterar: ");
    gets(nome);
    iteracao = procuraNome(nome, ps);
    switch(iteracao)
    {
    case -1:
        printf("\n\aNENHUM DADO ENCONTRADO COM O NOME DIGITADO!\n");
        break;
    default:
        lerVariavel(ps, iteracao);
        printf("\nCLIENTE %d (Antes da Alteração)\n", iteracao + 1);
        printf("Nome:          %50s\n", ps -> nome);
        printf("Endereço:      %50s\n", ps -> end);
        printf("Cidade:        %50s\n", ps -> cidade);
        printf("Estado:        %50s\n", ps -> estado);
        printf("CEP:           %50s\n", ps -> cep);

        printf("\n\nDeseja mesmo alterar esse cliente ? S/N       ");
        scanf("%c", &menu);
        if(menu == 'N' || menu == 'n'){system("cls");main();}
        getchar(); //Pega o enter do scanf acima para o gets abaixo não pegá-lo
        printf("\nDigite os novos dados\n");
        printf("Digite o novo nome: ");
        gets(ps -> nome);
        printf("Digite o novo endereço: ");
        gets(ps -> end);
        printf("Digite o novo cidade: ");
        gets(ps -> cidade);
        printf("Digite o novo estado: ");
        gets(ps -> estado);
        printf("Digite o novo CEP: ");
        gets(ps -> cep);
        escreverVariavel(ps, "r+", iteracao);

        printf("\n\aCLIENTE ALTERADO COM SUCESSO!\n");
        break;
    }

    printf("\nPressione 'B' para voltar ao menu\n");
    printf("Pressione 'ESPAÇO' para alterar outro nome\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    system("cls");
    if(menu == 'B' || menu == 'b'){main();}
    }while(menu == ' ');
}

void excluiDados(struct dados_pessoa *ps)
{
    int iteracao;
    char menu, nome[41], novoNome[41];

    do{
    printf("Excluir um dado\n");
    printf("Digite o nome que deseja excluir: ");
    gets(nome);
    iteracao = procuraNome(nome, ps);
    switch(iteracao)
    {
    case -1:
        printf("\n\aNENHUM DADO ENCONTRADO COM O NOME DIGITADO!\n");
        break;
    default:
        lerVariavel(ps, iteracao);
        printf("\nCLIENTE %d (Antes da Exclusão)\n", iteracao + 1);
        printf("Nome:          %50s\n", ps -> nome);
        printf("Endereço:      %50s\n", ps -> end);
        printf("Cidade:        %50s\n", ps -> cidade);
        printf("Estado:        %50s\n", ps -> estado);
        printf("CEP:           %50s\n", ps -> cep);

        printf("\n\nDeseja mesmo excluir esse cliente ? S/N       ");
        scanf("%c", &menu);
        if(menu == 'N' || menu == 'n'){system("cls");main();}

        memset(ps -> nome, '\0', 40);
        memset(ps -> end, '\0', 50);
        memset(ps -> cidade, '\0', 20);
        memset(ps -> estado, '\0', 2);
        memset(ps -> cep, '\0', 8);

        escreverVariavel(ps, "r+", iteracao);

        printf("\n\aCLIENTE EXCLUÍDO COM SUCESSO!\n");
        break;
    }

    printf("\nPressione 'B' para voltar ao menu\n");
    printf("Pressione 'ESPAÇO' para excluir outro nome\n");
    do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
    system("cls");
    if(menu == 'B' || menu == 'b'){main();}
    }while(menu == ' ');
}
#endif // ex4
