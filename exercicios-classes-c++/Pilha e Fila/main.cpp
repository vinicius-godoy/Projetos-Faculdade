#include <iostream>
#include <cstdlib>
#include <ctime>
#include "filasequencial.h"
#include "pilhasequencial.h"

using namespace std;

int main(){
    Pilha<int> p(20);
    Fila<int> f(20);
    cout << "Uma fila e uma pilha de tamanho 20 criadas!" << endl;
    srand(time(NULL));

    while (!f.cheia()){
        int x = (rand() % 44) + 35; // Gera um número aleatório entre 35 e 78
        f.insere(x); // Insere na fila
    }
    cout << "Fila preenchida com numeros aleatorios de 35 a 78!" << endl;

    cout << "Exibicao da fila:" << endl;
    for(int i = f.getInicio(); i <= f.getFim(); i++){ // Exibe a fila 
        cout << "fila[" << i << "] = " << f.getPosicao(i) << endl;
    }

    while (!f.vazia() && !p.pilhaCheia()){
        int x = f.exclui();
        p.empilha(x); // Empilha na pila o que for removido da fila
    }
    cout << "Fila transferida para a pilha!" << endl;

    cout << "Exibicao da pilha:" << endl;
    for(int i = 0; i <= p.getTopo(); i++){
        cout << "pilha[" << i << "] = " << p.getValor(i) << endl;
    }

    return 0;
}