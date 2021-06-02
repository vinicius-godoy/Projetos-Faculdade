#include <iostream>
#include <cstdlib>
#include <clocale>
#include "pilhaligada.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    string expressao;
    unsigned i, tam; 
    bool valido;
    char s; 
    int opc;

    Pilha<char> p;
    do {
        cout << "An�lise de Express�es" << endl;
        cout << "1 - Nova Express�o" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione uma op��o -> ";
        cin >> opc;

        system("cls");
        switch(opc){
        case 0:
            exit(0);
            break;
        case 1:
            cout << "Digite a express�o: ";
            cin.ignore();
            getline(cin, expressao);
            tam = expressao.size();
            
            i = 0; valido = true;
            while(i < tam){
                s = expressao.at(i);
                if(s == '{' || s == '[' || s == '('){
                    p.empilha(s);
                }else{
                    if(s == '}' || s == ']' || s == ')'){
                        if(p.pilhaVazia()){
                            valido = false;
                        }else{
                            if(s == '}' && p.elementoTopo() == '{'){
                                p.desempilha();
                            }else if(s == ')' && p.elementoTopo() == '('){
                                p.desempilha();
                            }else if(s == ']' && p.elementoTopo() == '['){
                                p.desempilha();
                            }else{
                                break;
                            }
                        }
                    }
                }
                
                i++;
            }
            if(p.pilhaVazia() && valido){
                cout << "A express�o \"" << expressao << "\" est� correta!" << endl;
            }else{
                cout << "A express�o \"" << expressao << "\" N�O est� correta!" << endl;
            }
            system("pause");
            break;
        default:
            cout << "Op��o Inv�lida, Selecione Outra!\a" << endl;
            system("pause");
            break;
        }

        while(p.pilhaVazia() != true){
            p.desempilha();
        }
        system("cls");
    }while(opc != 0);

    return 0;
}
