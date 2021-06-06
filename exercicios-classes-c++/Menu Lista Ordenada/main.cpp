#include <iostream>
#include <cstdlib>
#include <clocale>
#include "listaordenada.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese");
    Lista<int> lista;
    int opc, valor;
    bool verifica;
    Node<int> *aux;

    do{
        cout << "Lista Ordenada" << endl;
        cout << "1. Inserir um novo número" << endl;
        cout << "2. Realizar a busca de um elemento" << endl;
        cout << "3. Excluir um elemento" << endl;
        cout << "4. Exibir a lista" << endl;
        cout << "0. Sair" << endl;
        
        cout << "Selecione sua opção -> ";
        cin >> opc;
        
        switch(opc){
        case 0:
            exit(0);
            break;
        case 1:
            cout << "Digite o número que deseja inserir: ";
            cin >> valor;
            
            verifica = lista.insere(valor);
            if(!verifica){
                cout << "\aERRO ao inserir o número! ";
                system("pause");
            }
            break;
        case 2:
            cout << "Digite o número que deseja buscar: ";
            cin >> valor;

            aux = lista.h;
            while (aux->info != valor){
                    if(aux->prox == NULL){
                        aux = NULL;
                        break;
                    }else{
                        aux = aux->prox;
                    }
            }
            if(aux == NULL){
                cout << "O valor " << valor << " NÃO está na lista! ";
            }else{
                cout << "O valor " << valor << " ESTÁ na lista! ";
            }
            system("pause");
            break;
        case 3:
            cout << "Digite o número que deseja excluir: ";
            cin >> valor;
            
            verifica = lista.remove(valor);
            if(!verifica){
                cout << "\aERRO ao excluir o número! ";
                system("pause");
            }
            break;
        case 4:
            aux = lista.h;

            cout << "Elementos da lista: " << endl;
            while (aux != NULL){
                cout << aux->info << " ";
                aux = aux->prox;
            }
            cout << endl;
            system("pause");
            break;
        }

        cout << endl << endl;
    }while(opc != 0);
    return 0;
}