#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <clocale>
#include "contador.h"
#include "teatro.h"

//Namespaces
using namespace std;

//Protótipos de Função
void imprimir_teatro(int, int, Teatro&);
void menu_compra(Teatro&, Contador&);
void menu_troca(Teatro&);
void menu_devolucao(Teatro&, Contador&);
void titulo_teatro(Teatro&);
//Funções usam passagem por referência para que ela não chame o destrutor de Teatro ao final dela

//Variáveis Globais
int colunas, linhas;

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opc;

    cout << "================|Teatro Tal|================" << endl;
    cout << "Digite o número de fileiras: ";
    cin >> colunas;
    cout << "Digite o número de cadeiras por fileira: ";
    cin >> linhas;

    Teatro t1(linhas, colunas);
    Contador c1(colunas*linhas);

    /* Menu */
    do{
        system("cls");
        titulo_teatro(t1);
        imprimir_teatro(colunas, linhas, t1);

        cout << endl << "Lugares Comprados: " << c1.getNum() << endl;
        cout << "1 - Comprar Lugar" << endl;
        cout << "2 - Trocar Lugar" << endl;
        cout << "3 - Devolver Lugar" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione sua opção -> "; cin >> opc;

        system("cls"); //Limpa a tela antes de trocar de menu
        switch(opc)
        {
        case 0:
            exit(EXIT_SUCCESS);
            break;
        case 1:
            menu_compra(t1, c1);
            break;
        case 2:
            menu_troca(t1);
            break;
        case 3:
            menu_devolucao(t1, c1);
            break;
        default:
            cout << "Digite uma opção válida!\a";
            system("pause");
        }
    }while(opc != 0);

    return 0;
}

//Definições de Função
void imprimir_teatro(int col, int lin, Teatro& t1)
{
    //Espaço antes da numeração das fileiras
    cout << "   ";

    //Laço para numeração das fileiras
    for(int i = 1; i <= col; i++){
        if(i < 10){cout << " " << i << " ";
        }else if(i < 100){cout << " " << i;}
    }
    cout << endl;

    //Laço para impressão da matriz e da numeração das cadeiras
    for(int i = 0; i < lin; i++){
        cout << setw(3) << i + 1;
        for(int j = 0; j < col; j++){
            cout << "[" << t1.getLugar(i, j) << "]";
        }
        cout << endl;
    }
}
void menu_compra(Teatro& t1, Contador& c1)
{
    int col, lin, err;

    titulo_teatro(t1);
    imprimir_teatro(colunas, linhas, t1);
    cout << endl << "Digite a cadeira e a fileira do lugar que deseja comprar: ";
    cin >> lin >> col;
    lin = lin - 1; col = col - 1; //Remove um pra matriz poder começar com 1, 1 e não 0, 0
    err = t1.reservar(lin, col);
    if(err == 1){
        c1.aumentarNum();
        cout << endl << "Lugar Reservado! ";
        system("pause");
    }else{
        cout << endl << "Esse lugar já foi reservado! \a";
        system("pause");
    }
}
void menu_troca(Teatro& t1)
{
    int col, lin, col2, lin2, err;

    titulo_teatro(t1);
    imprimir_teatro(colunas, linhas, t1);
    cout << endl << "Digite a cadeira e a fileira do lugar que deseja trocar: ";
    cin >> lin >> col;
    cout << "Digite a cadeira e a fileira do lugar que deseja pegar: ";
    cin >> lin2 >> col2;
    lin = lin - 1; col = col - 1; lin2 = lin2 - 1; col2 = col2 - 1;
    err = t1.trocar(lin, col, lin2, col2);
    if(err == 0){
        cout << endl << "O lugar que você está tentando trocar não foi reservado ainda! \a";
        system("pause");
    }else if(err < 0){
        cout << endl << "Você não pode trocar o seu lugar por um que já foi reservado! \a";
        system("pause");
    }else{
        cout << endl << "Lugar Trocado! ";
        system("pause");
    }
}
void menu_devolucao(Teatro& t1, Contador& c1)
{
    int col, lin, err;

    titulo_teatro(t1);
    imprimir_teatro(colunas, linhas, t1);
    cout << endl << "Digite a cadeira e a fileira do lugar que deseja devolver: ";
    cin >> lin >> col;
    lin = lin - 1; col = col - 1;
    err = t1.devolver(lin, col);
    if(err == 1){
        c1.diminuirNum();
        cout << endl << "Lugar Devolvido! ";
        system("pause");
    }else{
        cout << endl << "Esse lugar não foi reservado ainda, portanto não pode ser devolvido! \a";
        system("pause");
    }
}
void titulo_teatro(Teatro& t1)
{
    int tamanhoTitulo;
    int numCol = t1.getCol();

    if(numCol <= 3){tamanhoTitulo = 2;}
    else{tamanhoTitulo = ((numCol*3)- 11)/2;}
    //A fórmula acima calcula quantos '=' tem que ter de cada lado do título pra cobrir toda a matriz

    //Printa um titulo de acordo com o tamanho da matriz apresentada na tela
    cout << "   " <<
    setw(tamanhoTitulo) << setfill('=') << "" <<
    setw(0) << "|Teatro Tal|" <<
    setw(tamanhoTitulo) << setfill('=') << "" <<
    setw(0) << setfill(' ') << endl;
}
