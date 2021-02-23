#include <iostream>
#include <cstdlib>
#include <clocale>
#include "contador.h"

using namespace std;

int main()
{
    system("cls");
    setlocale(LC_ALL, "portuguese");
    Contador c1;
    int opc;
    int num_especifico;

    do{
        cout << "========|Menu Contador|========" << endl;
        cout << "N�meros de Pessoas: " << c1.getNum() << endl;
        cout << "1 - Mudar Capacidade M�xima" << endl;
        cout << "2 - Entrada" << endl;
        cout << "3 - Sa�da" << endl;
        cout << "4 - Entrada/Sa�da de N�mero espec�fico" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione sua op��o -> ";
        cin >> opc;

        switch(opc)
        {
        case 0:
            exit(0);
            break;
        case 1:
            system("cls");
            cout << "Capacidade M�xima Atual : " << c1.getNumMax() << endl;
            cout << "Defina a Capacidade M�xima -> ";
            cin >> opc;

            c1.setNumMax(opc);
            break;
        case 2:
            c1.aumentarNum();
            break;
        case 3:
            c1.diminuirNum();
            break;
        case 4:
            system("cls");
            cout << "N�mero de pessoas: " << c1.getNum() << endl;
            cout << "Entrada ou Sa�da? (1 ou 0) -> ";
            cin >> opc;

            if(opc == 1){
                cout << "N�mero de Entrada -> ";
                cin >> num_especifico;
            }else{
                cout << "N�mero de Sa�da -> ";
                cin >> num_especifico;
            }

            if(opc == 1){
                c1.aumentarNum(num_especifico);
            }else{
                c1.diminuirNum(num_especifico);
            }
            break;
        default:
            cout << "Escolha uma op��o dispon�vel!" << endl;
            system("pause");
        }
        system("cls");
    }while(opc != 0);
    return 0;
}
