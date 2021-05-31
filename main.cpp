#include <iostream>
#include <cstdlib>
#include "arcondicionado.h"

using namespace std;

int main()
{
    system("cls");

    Arcondicionado a(25);
    int opc;

    do{
        cout << "===| Menu Ar Condicionado |===" << endl;
        cout << "Estado: ";
        if(a.getLigado() == 1){
            cout << "Ligado" << endl;
        }else{
            cout << "Desligado" << endl;
        }
        cout << "Temperatura: ";
        if(a.getLigado() == 1){
            cout << a.getTemperatura() << endl;
        }else{
            cout << "--" << endl;
        }
        cout << "1 - Liga/Desliga" << endl;
        cout << "2 - Aumentar Temperatura" << endl;
        cout << "3 - Diminuir Temperatura" << endl;
        cout << "0 - Sair" << endl;
        cout << "Selecione uma opcao: ";
        cin >> opc;
        switch (opc){
        case 1:
            a.onOff();
            break;
        case 2:
            if(a.getLigado() == 1){
                a.aumentar();
            }
            break;
        case 3:
            if(a.getLigado() == 1){
                a.diminuir();
            }
            break;
        case 0:
            break;
        default:
            cout << "Opcao Invalida! Escolha outra opcao" << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (opc != 0);
    return 0;
}
