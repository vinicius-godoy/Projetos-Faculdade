#include <iostream>
#include <cstdlib>
#include <clocale>
#include "contador.h"
#include "teatro.h"

//Namespaces
using namespace std;

//Protótipos de Função
void imprimir_teatro(int, int, char*);

int main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int fileira, cadeira, opc;

    cout << "===========|Teatro Municipal|===========" << endl;
    cout << "Digite o número de cadeiras por fileira" << endl;
    cin >> cadeira;
    cout << "Digite o número de fileiras" << endl;
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
        cout << endl << "Selecione sua opção -> ";
        cin >> opc;

        system("cls"); //Limpa a tela antes de trocar de menu
        switch(opc)
        {
            int lin, col, err; //Variáveis usadas no Switch-Case
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
                cout << endl << "Esse lugar já foi reservado! \a";
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
                cout << endl << "Esse lugar já foi reservado! \a";
                system("pause");
            }else{
                cout << endl << "O lugar que você está tentando trocar não foi reservado ainda! \a";
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
                cout << endl << "Esse lugar não foi reservado ainda, portanto não pode ser devolvido! \a";
                system("pause");
            }
            break;
        default:
            cout << "Digite uma opção válida!\a";
            system("pause");
        }
    }while(opc != 0);

    return 0;
}

//Definições de Função
void imprimir_teatro(int fileira, int cadeira, char* teatro)
{
    cout << "   "; //Espaço antes da numeração das fileiras
    for(int i = 1; i <= fileira; i++){ //Laço para numeração das fileiras
        if(i < 10){
            cout << " " << i << "  ";
        }else if(i < 100){
            cout << i << "  ";
        }else{
            cout << i << " ";
        }
    }
    cout << endl;
    for(int i = 0, j = 1, k = 1; i < fileira*cadeira; i++, j++){ //Laço pra impressão da matriz
        if(j == 1){ //Condicional para numeração das cadeiras
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
