#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#ifdef ex1
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura é uma variavel local na função main().Receba via teclado o
    conteudo de cada um dos membros numa função e imprima-os no video no
    seguinte fomato(também numa função).

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/
struct tipos_dados{
    char a;
    int b;
    long c;
    float d;
    double e;
    unsigned char f;
    unsigned int g;
    unsigned long h;
};

void pegarDados(struct tipos_dados *pdados)
{
    printf("Entre com os dados abaixo:\n");
    fflush(stdin); //limpa o buffer para caso o usuário recomece o programa
    printf("Char          = ");
    scanf("%c", &pdados -> a);
    printf("Int           = ");
    scanf("%d", &pdados -> b);
    printf("Long          = ");
    scanf("%ld", &pdados -> c);
    printf("Float         = ");
    scanf("%f", &pdados -> d);
    printf("Double        = ");
    scanf("%lf", &pdados -> e);
    getchar(); //Pega o último caractere para o unsigned char não armazenar o ENTER do double acima
    printf("Unsigned char = ");
    scanf("%c", &pdados -> f);
    printf("Unsigned int  = ");
    scanf("%u", &pdados -> g);
    printf("Unsigned long = ");
    scanf("%lu", &pdados -> h);
}

void escreverDados(struct tipos_dados *pdados)
{
    printf("\n");
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %c         %-5d     %-7ld             %-5.2f               %-6.4lf\n", pdados -> a, pdados -> b, pdados -> c, pdados -> d, pdados -> e);
    printf("          %c                   %-5u               %-5lu               \n", pdados -> f, pdados -> g, pdados -> h);
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    struct tipos_dados dados, *pdados;
    char menu;
    char *pmenu = &menu;
    pdados = &dados;

    do{
    pegarDados(pdados);
    escreverDados(pdados);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{menu = getch();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');system("cls");
    }while(menu == 'S' || menu == 's');
}
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa que receba n valores via teclado, receba também a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funções que recebe os valores usando ponteiros.*/
float aritmetica(char operacao, float num1, float num2)
{
    switch(operacao)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    case '=':
        break;
    }
}

void entradaDados(float *presultado)
{
    int i = 0;
    float num, aux;
    char operacao;
    //Ponteiros
    int *pi = &i;
    float *pnum = &num, *paux = &aux;
    char *poperacao = &operacao;

    while(1){
        (*pi)++;
        printf("Digite o %dº número: ", (*pi));
        scanf("%f", pnum);
        if((*pi) != 1){*presultado = aritmetica(*poperacao, *paux, *pnum);*paux = *presultado;}
        else{*paux = *pnum;}
        do{
        printf("Operação         -> ");
        getchar(); //Getchar para a operação não pegar o último ENTER
        scanf("%c", poperacao);
        if(*poperacao != '+' && *poperacao != '-' && *poperacao != '*' && *poperacao != '/' && *poperacao != '='){
            printf("\aOperação Inválida (+ Adição, - Subtração, * Multiplicação, / Divisão, = Resultado)\n");}
        }while(*poperacao != '+' && *poperacao != '-' && *poperacao != '*' && *poperacao != '/' && *poperacao != '=');
        if(*poperacao == '='){break;}
    }
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    float resultado;
    //Ponteiros
    char *pmenu = &menu;
    float *presultado = &resultado;

    do{
    printf("Digite vários valores e suas operações e quando quiser seu resultado digite \'=\' na operação\n");
    entradaDados(presultado);
    printf("\n\aO resultado do seu cálculo é: %g\n", *presultado);

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{menu = getch();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');system("cls");
    }while(menu == 'S' || menu == 's');
}
#endif // ex2

#ifdef ex3
/*3 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa no
    video na funcao main(). O vetor é uma variavel local na função main().Passe
    como parametro para a funcao o vetor e a letra digitada usando ponteiros.
    Pesquise usando ponteiros. (utilize o comando return)
    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/
int pesquisarLetra(char *vetor, char *letra)
{
    int i, boolean = 0;

    for(i = 0; i < 13; i++){
        if((*letra) == (*(vetor + i))){
           boolean++;
        }
    }

    return boolean;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    static char vetor[14] = "bdfhjkmoqsuwy";
    char letra, menu;
    //Ponteiros
    char *pvetor = &vetor, *pletra = &letra, *pmenu = &menu;

    do{
    printf("Digite um caractere para verificar se ele está presente no vetor \"%s\"\n", pvetor);
    printf("Caractere: ");
    scanf("%c", pletra);
    getchar();
    if((pesquisarLetra(pvetor, pletra)) != 0){
        printf("A letra \'%c\' ESTÁ no vetor \"%s\".\n", *pletra, pvetor);
    }else{
        printf("A letra \'%c\' NÃO está no vetor \"%s\".\n", *pletra, pvetor);
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{menu = getch();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');system("cls");
    }while(menu == 'S' || menu == 's');
}
#endif // ex3

#ifdef ex4
/*4 - Escreva um programa que receba em 1 funcao 2 strings de ate' 10 caracteres.
    Os vetores sao declaradas como variavel local na função main().
    Escreva uma funcao que recebe as 2 strings como parametros usando ponteiros
    e compare estas 2 strings.
    Retorne como resultado da comparacao 0 se forem DIFERENTES, 1 se forem
    IGUAIS, 2 se a string 1 for maior que a string 2, 3 se a string 2 for maior
    que a string 1 e 4 se as string tem tamanhos iguais mas são diferentes.*/
int comparaString(char *vetor1, char *vetor2)
{
    int i, igual, fim, maior = 0;

    if(strlen(vetor1) > strlen(vetor2)){
        fim = strlen(vetor1);
        maior = 1;
    }else if(strlen(vetor2) > strlen(vetor1)){
        fim = strlen(vetor2);
        maior = 2;
    }else{fim = strlen(vetor1);}

    for(i = 0, igual = 0; i < fim; i++){
        if(*(vetor1 + i) == *(vetor2 + i)){
            igual++;
        }
    }

    if(igual == i){
        return 1;
    }else if(maior == 1){
        return 2;
    }else if(maior == 2){
        return 3;
    }else{
        return 4;
    }
}

int entradaDados(char *vetor1, char *vetor2)
{
    int resultado;

    printf("Digite duas strings de até 10 caracteres para saber se são iguais ou têm alguma diferença\n");
    printf("Digite a primeira String: ");
    gets(vetor1);
    printf("Digite a segunda  String: ");
    gets(vetor2);

    resultado = comparaString(vetor1, vetor2);

    return resultado;
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    static char vetor1[11], vetor2[11];
    char menu;
    int compara;
    //Ponteiros
    char *pvetor1 = vetor1, *pvetor2 = vetor2, *pmenu = &menu;
    int *pcompara = &compara;

    do{
    *pcompara = entradaDados(pvetor1, pvetor2);
    switch(*pcompara)
    {
    case 1:
        printf("\nAs strings são IGUAIS!\n");
        break;
    case 2:
        printf("\nAs strings são DIFERENTES, sendo a primeira a maior delas!\n");
        break;
    case 3:
        printf("\nAs strings são DIFERENTES, sendo a segunda a maior delas!\n");
        break;
    case 4:
        printf("\nAs strings são DIFERENTES, porém têm o mesmo tamanho!\n");
        break;
    }

    printf("\nDeseja rodar o programa de novo ? S/N      ");
    do{menu = getch();}while(menu != 'S' && menu != 's' && menu != 'N' && menu != 'n');system("cls");
    }while(menu == 'S' || menu == 's');
}
#endif // ex4

#ifdef ex5
/*5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel local na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
                nome, end, cidade, estado, cep*/
void main(); //Protótipo da função main para as funções abaixo que usam ela
//Estruturas
struct dados_pessoa{
    char nome[41];
    char end[51];
    char cidade[21];
    char estado[3];
    char cep[9];
};

//Funções
void entrarDados(struct dados_pessoa *ps)
{
    int i, *pi = &i;
    char menu, *pmenu = &menu;

    for(*pi = 0; *pi < 4; (*pi)++){
        printf("Entre com os dados pedidos para 4 pessoas!\n");
        printf("Nome da %dº pessoa: ", *pi + 1);
        gets((ps + *pi) -> nome);
        printf("Endereço da %dº pessoa: ", *pi + 1);
        gets((ps + *pi) -> end);
        printf("Cidade da %dº pessoa: ", *pi + 1);
        gets((ps + *pi) -> cidade);
        printf("Estado da %dº pessoa(2 letras): ", *pi + 1);
        gets((ps + *pi) -> estado);
        printf("CEP da %dº pessoa(Sem traços ou pontos): ", *pi + 1);
        gets((ps + *pi) -> cep);
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
        printf("Nome da %dº pessoa:                      %50s\n", (*pi) + 1, (ps + *pi) -> nome);
        printf("Endereço da %dº pessoa:                  %50s\n", (*pi) + 1, (ps + *pi) -> end);
        printf("Cidade da %dº pessoa:                    %50s\n", (*pi) + 1, (ps + *pi) -> cidade);
        printf("Estado da %dº pessoa:                    %50s\n", (*pi) + 1, (ps + *pi) -> estado);
        printf("CEP da %dº pessoa:                       %50s\n", (*pi) + 1, (ps + *pi) -> cep);
        printf("-----------------------------------------------------------------------------------\n");
    }
    printf("\nPressione 'B' para voltar ao menu\n");
    do{*pmenu = getch();}while(*pmenu != 'B' && *pmenu != 'b');
    if(*pmenu == 'B' || *pmenu == 'b'){system("cls");main();}
}

//Programa
void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    char *pmenu = &menu;
    static struct dados_pessoa pessoas[4], *ps;

    ps = pessoas;

    printf("MENU\n");
    printf("1. Entrar com os dados\n");
    printf("2. Ver os dados\n");
    printf("3. Sair\n");
    do{*pmenu = getch();}while(*pmenu != '1' && *pmenu != '2' && *pmenu != '3');
    system("cls");

    switch(*pmenu)
    {
    case '1':
        entrarDados(ps);
        break;
    case '2':
        escreverDados(ps);
        break;
    case '3':
        exit(EXIT_SUCCESS);
        break;
    }
}
#endif // ex5

#ifdef ex6
/*6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro.*/
void main(); //Protótipo da função main para as funções abaixo que usam ela
//Estruturas
struct dados_pessoa{
    char nome[41];
    char end[51];
    char cidade[21];
    char estado[3];
    char cep[9];
};

//Funções
void entrarDados(struct dados_pessoa *ps)
{
    int i, *pi = &i;
    char menu, *pmenu = &menu;

    for(*pi = 0; *pi < 4; (*pi)++){
        printf("Entre com os dados pedidos para 4 pessoas!\n");
        printf("Nome da %dº pessoa: ", *pi + 1);
        gets((ps + *pi)-> nome);
        printf("Endereço da %dº pessoa: ", *pi + 1);
        gets((ps + *pi) -> end);
        printf("Cidade da %dº pessoa: ", *pi + 1);
        gets((ps + *pi) -> cidade);
        printf("Estado da %dº pessoa(2 letras): ", *pi + 1);
        gets((ps + *pi) -> estado);
        printf("CEP da %dº pessoa(Sem traços ou pontos): ", *pi + 1);
        gets((ps + *pi) -> cep);
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
        printf("Nome da %dº pessoa:                      %50s\n", (*pi) + 1, (ps + *pi) -> nome);
        printf("Endereço da %dº pessoa:                  %50s\n", (*pi) + 1, (ps + *pi) -> end);
        printf("Cidade da %dº pessoa:                    %50s\n", (*pi) + 1, (ps + *pi) -> cidade);
        printf("Estado da %dº pessoa:                    %50s\n", (*pi) + 1, (ps + *pi) -> estado);
        printf("CEP da %dº pessoa:                       %50s\n", (*pi) + 1, (ps + *pi) -> cep);
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
        for(j = 0; j < strlen(nome); j++){
            if((ps + i)-> nome[j] == nome[j]){
                correto++;
            }
        }
        if(correto == strlen((ps + i)->nome)){
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
        printf("\nCLIENTE %d\n", iteracao + 1);
        printf("Nome:          %50s\n", (ps + iteracao) -> nome);
        printf("Endereço:      %50s\n", (ps + iteracao) -> end);
        printf("Cidade:        %50s\n", (ps + iteracao) -> cidade);
        printf("Estado:        %50s\n", (ps + iteracao) -> estado);
        printf("CEP:           %50s\n", (ps + iteracao) -> cep);
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
        printf("\nCLIENTE %d (Antes da Alteração)\n", iteracao + 1);
        printf("Nome:          %50s\n", (ps + iteracao) -> nome);
        printf("Endereço:      %50s\n", (ps + iteracao) -> end);
        printf("Cidade:        %50s\n", (ps + iteracao) -> cidade);
        printf("Estado:        %50s\n", (ps + iteracao) -> estado);
        printf("CEP:           %50s\n", (ps + iteracao) -> cep);

        printf("\n\nDeseja mesmo alterar esse cliente ? S/N       ");
        scanf("%c", &menu);
        if(menu == 'N' || menu == 'n'){system("cls");main();}
        getchar(); //Pega o enter do scanf acima para o gets abaixo não pegá-lo
        printf("\nDigite os novos dados\n");
        printf("Digite o novo nome: ");
        gets((ps + iteracao)-> nome);
        printf("Digite o novo endereço: ");
        gets((ps + iteracao)-> end);
        printf("Digite o novo cidade: ");
        gets((ps + iteracao)-> cidade);
        printf("Digite o novo estado: ");
        gets((ps + iteracao)-> estado);
        printf("Digite o novo CEP: ");
        gets((ps + iteracao)-> cep);

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
        printf("\nCLIENTE %d (Antes da Exclusão)\n", iteracao + 1);
        printf("Nome:          %50s\n", (ps + iteracao) -> nome);
        printf("Endereço:      %50s\n", (ps + iteracao) -> end);
        printf("Cidade:        %50s\n", (ps + iteracao) -> cidade);
        printf("Estado:        %50s\n", (ps + iteracao) -> estado);
        printf("CEP:           %50s\n", (ps + iteracao) -> cep);

        printf("\n\nDeseja mesmo excluir esse cliente ? S/N       ");
        scanf("%c", &menu);
        if(menu == 'N' || menu == 'n'){system("cls");main();}

        memcpy((ps + iteracao) -> nome, "\0", 40);
        memcpy((ps + iteracao) -> end, "\0", 50);
        memcpy((ps + iteracao) -> cidade, "\0", 20);
        memcpy((ps + iteracao) -> estado, "\0", 2);
        memcpy((ps + iteracao) -> cep, "\0", 8);

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

//Programa
void main()
{
    setlocale(LC_ALL, "portuguese");
    char menu;
    char *pmenu = &menu;
    static struct dados_pessoa pessoas[4], *ps;

    ps = pessoas;

    printf("MENU\n");
    printf("1. Entrar com os dados\n");
    printf("2. Ver os dados\n");
    printf("3. Procura um dado\n");
    printf("4. Altera um dado\n");
    printf("5. Exclui um dado\n");
    printf("6. Sair\n");
    do{*pmenu = getch();}while(*pmenu != '1' && *pmenu != '2' && *pmenu != '3' && *pmenu != '4' && *pmenu != '5' && *pmenu != '6');
    system("cls");

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
#endif // ex6
