#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED

template <typename Tipo>
struct Node{ // Estrutura de N� que vai conter o dado e o pr�ximo N�
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
class Pilha{
private:
    Node<Tipo> *topo; // Ponteiro do �ltimo item da pilha

public:
    // Construtor
    Pilha(){
        topo = NULL; // Inicia sem topo
    }

    // M�todos
    bool empilha(Tipo x){
        bool v = true; // Vari�vel para checar se a aloca��o din�mica funcionou
        Node<Tipo> *aux = new Node<Tipo>; // Vari�vel auxiliar pro novo n�
        if(aux == NULL){ // Se a aloca��o din�mica falhar o check � falso
            v = false; 
        }else{ // Sen�o o auxiliar pega a informa��o passada como param�tro e aponta pro topo e o topo vira o auxiliar
            aux->info = x;
            aux->prox = topo;
            topo = aux;
        }

        return v; // Retorna o sucesso da aloca��o
    }
    Tipo desempilha(){
        Tipo temp = topo->info; // Vari�vel tempor�ria pra armazenar dado do n� que ser� desempilhado 
        Node<Tipo> *aux = topo; // Vari�vel auxiliar de n� que � atribu�da com o topo
        topo = topo->prox; // Transforma o topo no pr�ximo da pilha
        delete aux; // Deleta o auxiliar contendo o top
        
        return temp; // Retorna o dado do n� desempilhado
    }
    Tipo elementoTopo(){
        return topo->info;
    }
    bool pilhaVazia(){
        return topo == NULL;
    }

    // M�todos Get
    Node<Tipo> *getTopo(){
        return topo;
    }
};

#endif // PILHALIGADA_H_INCLUDED