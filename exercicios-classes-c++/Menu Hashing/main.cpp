#include <iostream>
#include <clocale>
#include <cstdlib>
#include "hash.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese");

    int opc, valor, particao;
    Hash hash;
    Node *aux;

    do{
        cout << "Hashing" << endl;
        cout << "1. Inserir um novo n�mero" << endl;
        cout << "2. Realizar a busca de um elemento" << endl;
        cout << "3. Excluir um elemento" << endl;
        cout << "4. Exibir a Tabela Hashing" << endl;
        cout << "0. Sair" << endl;

        cout << "Selecione sua op��o -> ";
        cin >> opc;

        switch(opc){
        case 0:
            exit(0);
            break;
        case 1:
            cout << "N�mero que deseja inserir: ";
            cin >> valor;
            hash.insere(valor);
            break;
        case 2:
            cout << "N�mero que deseja buscar: ";
            cin >> valor;
            particao = hash.fht(valor);
            aux = hash.h[particao];
            while(aux != NULL && aux->info != valor){
                aux = aux->prox;
            }
            if(aux == NULL){
                cout << "O n�mero " << valor << " N�O est� na tabela hashing! \a";
            }else{
                cout << "O n�mero " << valor << " EST� na tabela hashing! ";
            }
            system("pause");
            break;
        case 3:
            cout << "N�mero que deseja excluir: ";
            cin >> valor;
            if(!hash.remove(valor)){
                cout << "ERRO ao excluir o n�mero!\a ";
                system("pause");
            }
            break;
        case 4:
            cout << "Tabela Hashing" << endl;
            for (int i = 0; i < W; i++){
                aux = hash.h[i];
                cout << "h[" << i << "]->";
                while(aux != NULL){
                    cout << aux->info << "->";
                    aux = aux->prox;
                }
                cout << endl;
            }
            system("pause");
            break;
        default:
            cout << "Selecione uma op��o v�lida [0-4] ! \a";
            system("pause");
            break;
        }
        cout << endl << endl;
    }while(opc != 0);
    return 0;
}