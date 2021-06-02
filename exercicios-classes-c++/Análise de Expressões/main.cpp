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
        cout << "Análise de Expressões" << endl;
        cout << "1 - Nova Expressão" << endl;
        cout << "0 - Sair" << endl;
        cout << endl << "Selecione uma opção -> ";
        cin >> opc;

        system("cls");
        switch(opc){
        case 0:
            exit(0);
            break;
        case 1:
            cout << "Digite a expressão: ";
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
                cout << "A expressão \"" << expressao << "\" está correta!" << endl;
            }else{
                cout << "A expressão \"" << expressao << "\" NÃO está correta!" << endl;
            }
            system("pause");
            break;
        default:
            cout << "Opção Inválida, Selecione Outra!\a" << endl;
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
