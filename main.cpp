#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <clocale>
#include "contador.h"
#include "teatro.h"

//Namespaces
using namespace std;

//Prot�tipos de Fun��o
void imprimir_teatro(int, int, Teatro&);
void menu_compra(Teatro&, Contador&);
void menu_troca(Teatro&);
void menu_devolucao(Teatro&, Contador&);
void titulo_teatro(Teatro&);
//Fun��es usam passagem por refer�ncia para que ela n�o chame o destrutor de Teatro ao final dela

//Vari�veis Globais
int colunas, linhas;

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opc;

    cout << "================|Teatro Tal|================" << endl;
    cout << "Digite o n�mero de fileiras: ";
    cin >> colunas;
    cout << "Digite o n�mero de cadeiras por fileira: ";
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
        cout << endl << "Selecione sua op��o -> "; cin >> opc;

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
            cout << "Digite uma op��o v�lida!\a";
            system("pause");
        }
    }while(opc != 0);

    return 0;
}

//Defini��es de Fun��o
void imprimir_teatro(int col, int lin, Teatro& t1)
{
    //Espa�o antes da numera��o das fileiras
    cout << "   ";

    //La�o para numera��o das fileiras
    for(int i = 1; i <= col; i++){
        if(i < 10){cout << " " << i << " ";
        }else if(i < 100){cout << " " << i;}
    }
    cout << endl;

    //La�o para impress�o da matriz e da numera��o das cadeiras
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
    lin = lin - 1; col = col - 1; //Remove um pra matriz poder come�ar com 1, 1 e n�o 0, 0
    err = t1.reservar(lin, col);
    if(err == 1){
        c1.aumentarNum();
        cout << endl << "Lugar Reservado! ";
        system("pause");
    }else{
        cout << endl << "Esse lugar j� foi reservado! \a";
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
        cout << endl << "O lugar que voc� est� tentando trocar n�o foi reservado ainda! \a";
        system("pause");
    }else if(err < 0){
        cout << endl << "Voc� n�o pode trocar o seu lugar por um que j� foi reservado! \a";
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
        cout << endl << "Esse lugar n�o foi reservado ainda, portanto n�o pode ser devolvido! \a";
        system("pause");
    }
}
void titulo_teatro(Teatro& t1)
{
    int tamanhoTitulo;
    int numCol = t1.getCol();

    if(numCol <= 3){tamanhoTitulo = 2;}
    else{tamanhoTitulo = ((numCol*3)- 11)/2;}
    //A f�rmula acima calcula quantos '=' tem que ter de cada lado do t�tulo pra cobrir toda a matriz

    //Printa um titulo de acordo com o tamanho da matriz apresentada na tela
    cout << "   " <<
    setw(tamanhoTitulo) << setfill('=') << "" <<
    setw(0) << "|Teatro Tal|" <<
    setw(tamanhoTitulo) << setfill('=') << "" <<
    setw(0) << setfill(' ') << endl;
}
