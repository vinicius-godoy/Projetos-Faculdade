#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

//Macros
#define PRI_LTR 0 //Primeira Letra
#define STR_INT 1 //String Inteira
#define ALT_USR 0 //Alterar Usu�rio
#define DEL_USR 1 //Deletar Usu�rio

//Vari�veis Globais (G mai�sculo no come�o)
unsigned char Gnome1[40], Gnome2[40], Gnome3[40]; //Vari�veis Globais de nome
unsigned char Gemail1[40], Gemail2[40], Gemail3[40]; //Vari�veis Globais de email
const int GnumUsuarios = 3; //Constante que permite aumentar o n�mero de usu�rios, apenas criando novas vari�veis globais

//Declara��o das Fun��es
void pegarDados(void);
int pesquisarNome(char nome[], int tipo);
void manipularDados(char novoNome[], char novoEmail[], int usuario, int tipo);

//Programa
void main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese"); //Fun��o para exibir caracteres da l�ngua portuguesa
    int menu, i, num; // Vari�vel 'menu' para resposta nos menus, uma vari�vel para la�os for e uma vari�vel para as op��es 5 e 6
    char resposta[40], resposta2[40]; // Vari�veis para respostas em string
    FILE *farquivo; // Ponteiro de vari�vel tipo FILE

    printf("====================|MENU|====================\n");
    printf("Digite o n�mero da op��o que deseja selecionar\n");
    printf("1 � Entrar com dados.\n");
    printf("2 � Listar todos os dados.\n");
    printf("3 � Pesquisar um nome\n");
    printf("4 � Pesquisar nomes pela 1� letra.\n");
    printf("5 � Alterar  dados.\n");
    printf("6 � Excluir dados.\n");
    printf("7 - Sair\n");

    do{
    menu = getch();
    }while(menu != '1' && menu != '2' && menu != '3' && menu != '4' && menu != '5' && menu != '6' && menu != '7');
    system("cls");

    switch(menu)
    {
    case '1':
        remove("dados.txt");
        for(i = 0; i < GnumUsuarios; i++){
            system("cls");
            printf("ENTRADA\n\n");
            printf("Entre com os dados pedidos:");
            printf("\nNome Usu�rio %d: ", i+1);
            gets(Gnome1);
            printf("Email Usu�rio %d: ", i+1);
            gets(Gemail1);
            farquivo = fopen("dados.txt", "a");
            fwrite(Gnome1, sizeof(char), sizeof(Gnome1), farquivo);
            fwrite(Gemail1, sizeof(char), sizeof(Gemail1), farquivo);
            fclose(farquivo);
            //As duas fun��es abaixo limpam as vari�veis para a pr�xima itera��o do la�o for
            memset(Gnome1,0,sizeof(Gnome1));
            memset(Gemail1,0,sizeof(Gemail1));
            printf("\nContinuar entrando com Dados - Pressione \'ESPA�O\'");
            printf("\nVoltar ao menu - Pressione \'B\'\n");
            do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
            if(menu == 'B' || menu == 'b'){ //if para voltar ao menu
                int j;
                //La�o for que deixa espa�o vazio pros usu�rios n�o entrados
                for(j = i + 1; j < GnumUsuarios; j++){
                    farquivo = fopen("dados.txt", "a");
                    fwrite(Gnome1, sizeof(char), sizeof(Gnome1), farquivo);
                    fwrite(Gemail1, sizeof(char), sizeof(Gemail1), farquivo);
                    fclose(farquivo);
                }
                system("cls");
                main();
            }
            }
            system("cls");
            printf("\aVoc� entrou com dados para todos os usu�rios!\n");
            printf("\nVoltar ao menu - Pressione \'B\'\n");
            do{menu = getch();}while(menu != 'B' && menu != 'b');
            if(menu == 'B' || menu == 'b'){
                system("cls");
                main();
            }
        break;
    case '2':
        printf("DADOS\n");
        pegarDados();
        printf("USU�RIO 1\nNome: %-40s | Email: %-40s\n", Gnome1, Gemail1);
        printf("USU�RIO 2\nNome: %-40s | Email: %-40s\n", Gnome2, Gemail2);
        printf("USU�RIO 3\nNome: %-40s | Email: %-40s\n", Gnome3, Gemail3);
        printf("\nVoltar ao menu - Pressione \'B\'\n");
        do{menu = getch();}while(menu != 'B' && menu != 'b');
        if(menu == 'B' || menu == 'b'){system("cls");main();}
        break;
    case '3':
        pegarDados();
        do{
        system("cls");
        printf("PESQUISA\n\n");
        printf("Buscar usu�rios pelo nome completo");
        printf("\nNome a ser procurado: ");
        gets(resposta);
        system("cls");printf("PESQUISA\n\n"); //Fun��es para liberar um pouco de espa�o na tela e deixar mais bonito o programa
        printf("Usu�rios com o nome \"%s\"\n", resposta);
        pesquisarNome(resposta, STR_INT);
        printf("----------------------------------------------------------------------------------\n");
        printf("\nVoltar ao menu - Pressione \'B\'");
        printf("\nContinuar procurando por usu�rios pelo nome - Pressione \'ESPA�O\'\n");
        do{menu = getch();}while(menu != ' ' && menu != 'B' && menu != 'b');
        if(menu == 'b' || menu == 'B'){system("cls");main();}
        }while(menu == ' ');
        break;
    case '4':
        pegarDados();
        do{
        system("cls");
        printf("PESQUISA\n\n");
        printf("Buscar usu�rios pela primeira letra");
        printf("\nLetra a ser procurado: ");
        gets(resposta);
        printf("\nUsu�rios com a primeira letra \'%c\'\n", resposta[0]);
        pesquisarNome(resposta, PRI_LTR);
        printf("----------------------------------------------------------------------------------\n");
        printf("\nVoltar ao menu - Pressione \'B\'");
        printf("\nContinuar procurando por usu�rios pela primeira letra - Pressione \'ESPA�O\'\n");
        do{menu = getch();}while(menu != ' ' && menu != 'B' && menu != 'b');
        if(menu == 'b' || menu == 'B'){system("cls");main();}
        }while(menu == ' ');
        break;
    case '5':
        do{
        do{
        menu = '\0'; //Previne conflito entre os dois 'do{}while'
        pegarDados();
        printf("ALTERAR DADOS\n\n");
        printf("Alterar dados de usu�rios encontrados pelo nome completo");
        printf("\nNome do usu�rio a ser alterado: ");
        gets(resposta);
        printf("\nUsu�rio com o nome \"%s\":\n", resposta);
        num = pesquisarNome(resposta, STR_INT);
        printf("----------------------------------------------------------------------------------");
        if(num == 0){
            printf("\nNenhum usu�rio encontrado! Digite outro nome pressionando \'ESPA�O\' ou volte ao menu pressionando \'B\'\n");
            do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
            if(menu == 'B' || menu == 'b'){system("cls");main();}
            if(menu == ' '){system("cls");}
        }
        }while(menu == ' ');
        printf("\nNovo Nome: ");
        gets(resposta);
        printf("\nNovo email: ");
        gets(resposta2);
        manipularDados(resposta, resposta2, num, ALT_USR);
        system("cls");
        printf("\aUSU�RIO ALTERADO COM SUCESSO!\n");
        printf("\nVoltar ao menu - Pressione \'B\'");
        printf("\nContinuar alterando usu�rios - Pressione \'ESPA�O\'\n");
        do{menu = getch();}while(menu != ' ' && menu != 'B' && menu != 'b');
        if(menu == 'b' || menu == 'B'){system("cls");main();}
        system("cls");
        }while(menu == ' ');
        break;
    case '6':
        do{
        do{
        menu = '\0'; //Previne conflito entre os dois 'do{}while'
        pegarDados();
        printf("REMOVER DADOS\n\n");
        printf("Remover dados de usu�rios encontrados pelo nome completo");
        printf("\nNome do usu�rio a ser removido: ");
        gets(resposta);
        printf("\nUsu�rio com o nome \"%s\":\n", resposta);
        num = pesquisarNome(resposta, STR_INT);
        printf("----------------------------------------------------------------------------------");
        if(num == 0){
            printf("\nNenhum usu�rio encontrado! Digite outro nome pressionando \'ESPA�O\' ou volte ao menu pressionando \'B\'\n");
            do{menu = getch();}while(menu != 'B' && menu != 'b' && menu != ' ');
            if(menu == 'B' || menu == 'b'){system("cls");main();}
            if(menu == ' '){system("cls");}
        }
        }while(menu == ' ');
        printf("\a\nTEM CERTEZA QUE DESEJA REMOVER O USU�RIO COM O NOME ACIMA ? (S/N)      ");
        menu = getch();
        if(menu == 'N' || menu == 'n'){main();}
        manipularDados(0, 0, num, DEL_USR);
        system("cls");
        printf("\aUSU�RIO REMOVIDO COM SUCESSO!\n");
        printf("\nVoltar ao menu - Pressione \'B\'");
        printf("\nContinuar removendo usu�rios - Pressione \'ESPA�O\'\n");
        do{menu = getch();}while(menu != ' ' && menu != 'B' && menu != 'b');
        if(menu == 'b' || menu == 'B'){system("cls");main();}
        system("cls");
        }while(menu == ' ');
        break;
    case '7':
        exit(EXIT_SUCCESS);
        break;
    }
}

//Fun��es
void pegarDados(void)
{
    FILE *pArquivo;

    //Fun��es para limpar o conte�do de todas as vari�veis globais
    memset(Gnome1,0,sizeof(Gnome1));
    memset(Gemail1,0,sizeof(Gemail1));
    memset(Gnome2,0,sizeof(Gnome2));
    memset(Gemail2,0,sizeof(Gemail2));
    memset(Gnome3,0,sizeof(Gnome3));
    memset(Gemail3,0,sizeof(Gemail3));

    pArquivo = fopen("dados.txt", "r");
    fread(Gnome1, sizeof(char), sizeof(Gnome1), pArquivo);
    fread(Gemail1, sizeof(char), sizeof(Gemail1), pArquivo);
    fread(Gnome2, sizeof(char), sizeof(Gnome2), pArquivo);
    fread(Gemail2, sizeof(char), sizeof(Gemail2), pArquivo);
    fread(Gnome3, sizeof(char), sizeof(Gnome3), pArquivo);
    fread(Gemail3, sizeof(char), sizeof(Gemail3), pArquivo);
    fclose(pArquivo);
}

int pesquisarNome(char nome[], int tipo)
{
    int nenhum = 0, usuario = 0, certo, i;

    //Verifica o primeiro usu�rio
    if(tipo == STR_INT){ //Verifica a String Inteira
    for(i = strlen(Gnome1), certo = 0; i >= 0; i--){
        if(Gnome1[i] == nome[i]){certo++;}
    }
    if((certo - 1) == strlen(Gnome1)){printf("USU�RIO 1:\nNome: %-40s | Email: %-40s\n", Gnome1, Gemail1);nenhum++;usuario=1;} //certo - 1 para descontar o NULL no final da string
    }
    if(tipo == PRI_LTR){ //Verifica a primeira letra
        if(Gnome1[0] > 'a' && Gnome1[0] < 'z'){
            if(nome[0] == Gnome1[0] || nome[0] == Gnome1[0]-32){
                printf("USU�RIO 1:\nNome: %-40s | Email: %-40s\n", Gnome1, Gemail1);nenhum++;}
        }else{
            if(nome[0] == Gnome1[0] || nome[0] == Gnome1[0]+32){
                printf("USU�RIO 1:\nNome: %-40s | Email: %-40s\n", Gnome1, Gemail1);nenhum++;}}}

    //Verifica o segundo usu�rio
    if(tipo == STR_INT){ //Verifica a String Inteira
    for(i = strlen(Gnome2), certo = 0; i >= 0; i--){
        if(Gnome2[i] == nome[i]){certo++;}
    }
    if((certo - 1) == strlen(Gnome2)){printf("USU�RIO 2:\nNome: %-40s | Email: %-40s\n", Gnome2, Gemail2);nenhum++;usuario=2;} //certo - 1 para descontar o NULL no final da string
    }
    if(tipo == PRI_LTR){ //Verifica a primeira letra
        if(Gnome2[0] > 'a' && Gnome2[0] < 'z'){
            if(nome[0] == Gnome2[0] || nome[0] == Gnome2[0]-32){
                printf("USU�RIO 2:\nNome: %-40s | Email: %-40s\n", Gnome2, Gemail2);nenhum++;}
        }else{
            if(nome[0] == Gnome2[0] || nome[0] == Gnome2[0]+32){
                printf("USU�RIO 2:\nNome: %-40s | Email: %-40s\n", Gnome2, Gemail2);nenhum++;}}}

    //Verifica o terceiro usu�rio
    if(tipo == STR_INT){ //Verifica a String Inteira
    for(i = strlen(Gnome3), certo = 0; i >= 0; i--){
        if(Gnome3[i] == nome[i]){certo++;}
    }
    if((certo - 1) == strlen(Gnome3)){printf("USU�RIO 3:\nNome: %-40s | Email: %-40s\n", Gnome3, Gemail3);nenhum++;usuario=3;} //certo - 1 para descontar o NULL no final da string
    }
    if(tipo == PRI_LTR){ //Verifica a primeira letra
        if(Gnome3[0] > 'a' && Gnome3[0] < 'z'){
            if(nome[0] == Gnome3[0] || nome[0] == Gnome3[0]-32){
                printf("USU�RIO 3:\nNome: %-40s | Email: %-40s\n", Gnome3, Gemail3);nenhum++;}
        }else{
            if(nome[0] == Gnome3[0] || nome[0] == Gnome3[0]+32){
                printf("USU�RIO 3:\nNome: %-40s | Email: %-40s\n", Gnome3, Gemail3);nenhum++;}}}

    //Printa a mensagem padr�o se n�o encontrar nenhum
    if(nenhum == 0){printf("NENHUM US�ARIO COM OS CRIT�RIOS DEFINIDOS ENCONTRADOS NO BANCO DE DADOS!\n\a");}

    return usuario;
}

void manipularDados(char novoNome[], char novoEmail[], int usuario, int tipo)
{
    FILE *pArquivo;
    int i;

    if(tipo == ALT_USR){
        pegarDados();
        if(usuario == 1){memset(Gnome1, 0, sizeof(Gnome1));memset(Gemail1, 0, sizeof(Gemail1));strcpy(Gnome1, novoNome);strcpy(Gemail1, novoEmail);}
        if(usuario == 2){memset(Gnome2, 0, sizeof(Gnome2));memset(Gemail2, 0, sizeof(Gemail2));strcpy(Gnome2, novoNome);strcpy(Gemail2, novoEmail);}
        if(usuario == 3){memset(Gnome3, 0, sizeof(Gnome3));memset(Gemail3, 0, sizeof(Gemail3));strcpy(Gnome3, novoNome);strcpy(Gemail3, novoEmail);}
        remove("dados.txt");
        pArquivo = fopen("dados.txt", "a");
        fwrite(Gnome1, sizeof(char), sizeof(Gnome1), pArquivo);
        fwrite(Gemail1, sizeof(char), sizeof(Gemail1), pArquivo);
        fwrite(Gnome2, sizeof(char), sizeof(Gnome2), pArquivo);
        fwrite(Gemail2, sizeof(char), sizeof(Gemail2), pArquivo);
        fwrite(Gnome3, sizeof(char), sizeof(Gnome3), pArquivo);
        fwrite(Gemail3, sizeof(char), sizeof(Gemail3), pArquivo);
        fclose(pArquivo);
    }

    if(tipo == DEL_USR){
        pegarDados();
        if(usuario == 1){memset(Gnome1, 0, sizeof(Gnome1));memset(Gemail1, 0, sizeof(Gemail1));}
        if(usuario == 2){memset(Gnome2, 0, sizeof(Gnome2));memset(Gemail2, 0, sizeof(Gemail2));}
        if(usuario == 3){memset(Gnome3, 0, sizeof(Gnome3));memset(Gemail3, 0, sizeof(Gemail3));}
        remove("dados.txt");
        pArquivo = fopen("dados.txt", "a");
        fwrite(Gnome1, sizeof(char), sizeof(Gnome1), pArquivo);
        fwrite(Gemail1, sizeof(char), sizeof(Gemail1), pArquivo);
        fwrite(Gnome2, sizeof(char), sizeof(Gnome2), pArquivo);
        fwrite(Gemail2, sizeof(char), sizeof(Gemail2), pArquivo);
        fwrite(Gnome3, sizeof(char), sizeof(Gnome3), pArquivo);
        fwrite(Gemail3, sizeof(char), sizeof(Gemail3), pArquivo);
        fclose(pArquivo);
    }
}
