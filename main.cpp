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
        cout << "Números de Pessoas: " << c1.getNum() << endl;
        cout << "1 - Mudar Capacidade Máxima" << endl;
        cout << "2 - Entrada" << endl;
        cout << "3 - Saída" << endl;
        cout << "4 - Entrada/Saída de Número específico" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione sua opção -> ";
        cin >> opc;

        switch(opc)
        {
        case 0:
            exit(0);
            break;
        case 1:
            system("cls");
            cout << "Capacidade Máxima Atual : " << c1.getNumMax() << endl;
            cout << "Defina a Capacidade Máxima -> ";
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
            cout << "Número de pessoas: " << c1.getNum() << endl;
            cout << "Entrada ou Saída? (1 ou 0) -> ";
            cin >> opc;

            if(opc == 1){
                cout << "Número de Entrada -> ";
                cin >> num_especifico;
            }else{
                cout << "Número de Saída -> ";
                cin >> num_especifico;
            }

            if(opc == 1){
                c1.aumentarNum(num_especifico);
            }else{
                c1.diminuirNum(num_especifico);
            }
            break;
        default:
            cout << "Escolha uma opção disponível!" << endl;
            system("pause");
        }
        system("cls");
    }while(opc != 0);
    return 0;
}
