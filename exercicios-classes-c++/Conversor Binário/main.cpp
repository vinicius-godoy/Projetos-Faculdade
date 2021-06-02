#include <iostream>
#include "pilhaligada.h"

using namespace std;

int main()
{
    Pilha<int> p;
    int numInteiro;

    cout << "Digite um numero inteiro: ";
    cin >> numInteiro;

    cout << numInteiro << " em binario e ";
    while(numInteiro > 0){
        p.empilha(numInteiro % 2);
        numInteiro /= 2; 
    }
    // Printa o número binário
    Node<int> *aux = p.getTopo();
    while (aux != NULL){
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;

    return 0;
}