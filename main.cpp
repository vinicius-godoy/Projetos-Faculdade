#include <iostream>
#include <cstdlib>
#include <clocale>
#include "contador.h"
#include "teatro.h"

//Namespaces
using namespace std;

//Prot�tipos de Fun��o
void imprimir_teatro(int, int, char*);

int main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int fileira, cadeira, opc;

    cout << "===========|Teatro Municipal|===========" << endl;
    cout << "Digite o n�mero de cadeiras por fileira" << endl;
    cin >> cadeira;
    cout << "Digite o n�mero de fileiras" << endl;
    cin >> fileira;

    Teatro t1(cadeira, fileira);
    Contador c1(fileira*cadeira);

    /* Menu */
    do{
        system("cls");
        cout << "===========|Teatro Municipal|===========" << endl;
        imprimir_teatro(fileira, cadeira, t1.getLugares());

        cout << endl << "Lugares Comprados: " << c1.getNum() << endl;
        cout << "1 - Comprar Lugar" << endl;
        cout << "2 - Trocar Lugar" << endl;
        cout << "3 - Devolver Lugar" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione sua op��o -> ";
        cin >> opc;

        system("cls"); //Limpa a tela antes de trocar de menu
        switch(opc)
        {
            int lin, col, err; //Vari�veis usadas no Switch-Case
        case 0:
            exit(EXIT_SUCCESS);
            break;
        case 1:
            cout << "===========|Teatro Municipal|===========" << endl;
            imprimir_teatro(fileira, cadeira, t1.getLugares());
            cout << endl << "Digite a cadeira e a fileira do lugar que deseja comprar: ";
            cin >> lin >> col;
            err = t1.reservar(lin, col);
            if(err == 1){
                c1.aumentarNum();
                cout << endl << "Lugar Reservado! ";
                system("pause");
            }else{
                cout << endl << "Esse lugar j� foi reservado! \a";
                system("pause");
            }
            break;
        case 2:
            int lin2, col2;
            cout << "===========|Teatro Municipal|===========" << endl;
            imprimir_teatro(fileira, cadeira, t1.getLugares());
            cout << endl << "Digite a cadeira e a fileira do lugar que deseja trocar por outro: ";
            cin >> lin >> col;
            cout << "Agora digite a cadeira e a fileiraa do lugar que deseja pegar: ";
            cin >> lin2 >> col2;
            err = t1.trocar(lin, col, lin2, col2);
            if(err == 1){
                cout << endl << "Lugar Trocado! ";
                system("pause");
            }else if(err < 0){
                cout << endl << "Esse lugar j� foi reservado! \a";
                system("pause");
            }else{
                cout << endl << "O lugar que voc� est� tentando trocar n�o foi reservado ainda! \a";
                system("pause");
            }
            break;
        case 3:
            cout << "===========|Teatro Municipal|===========" << endl;
            imprimir_teatro(fileira, cadeira, t1.getLugares());
            cout << endl << "Digite a cadeira e a fileira do lugar que deseja devolver: ";
            cin >> lin >> col;
            err = t1.devolver(lin, col);
            if(err == 1){
                c1.diminuirNum();
                cout << endl << "Lugar Devolvido! ";
                system("pause");
            }else{
                cout << endl << "Esse lugar n�o foi reservado ainda, portanto n�o pode ser devolvido! \a";
                system("pause");
            }
            break;
        default:
            cout << "Digite uma op��o v�lida!\a";
            system("pause");
        }
    }while(opc != 0);

    return 0;
}

//Defini��es de Fun��o
void imprimir_teatro(int fileira, int cadeira, char* teatro)
{
    cout << "   "; //Espa�o antes da numera��o das fileiras
    for(int i = 1; i <= fileira; i++){ //La�o para numera��o das fileiras
        if(i < 10){
            cout << " " << i << "  ";
        }else if(i < 100){
            cout << i << "  ";
        }else{
            cout << i << " ";
        }
    }
    cout << endl;
    for(int i = 0, j = 1, k = 1; i < fileira*cadeira; i++, j++){ //La�o pra impress�o da matriz
        if(j == 1){ //Condicional para numera��o das cadeiras
            if(k < 10){
                cout << k << "  "; k++;
            }else if(k < 100){
                cout << k << " "; k++;
            }else{
                cout << k; k++;
            }
        }
        cout << "[" << teatro[i] << "] ";
        if(j == fileira){cout << endl;j = 0;}
    }
}
