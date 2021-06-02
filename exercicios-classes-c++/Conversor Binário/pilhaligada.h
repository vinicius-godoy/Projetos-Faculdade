#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED

template <typename Tipo>
struct Node{ // Estrutura de Nó que vai conter o dado e o próximo Nó
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
class Pilha{
private:
    Node<Tipo> *topo;

public:
    // Construtor
    Pilha(){
        topo = NULL; 
    }

    // Métodos
    bool empilha(Tipo x){
        bool v = true; // Variável para checar se a alocação dinâmica funcionou
        Node<Tipo> *aux = new Node<Tipo>; // Variável auxiliar pro novo nó
        if(aux == NULL){ // Se a alocação dinâmica falhar o check é falso
            v = false; 
        }else{ // Senão o auxiliar pega a informação passada como paramêtro e aponta pro topo e o topo vira o auxiliar
            aux->info = x;
            aux->prox = topo;
            topo = aux;
        }

        return v; // Retorna o sucesso da alocação
    }
    Tipo desempilha(){
        Tipo temp = topo->info; // Variável temporária pra armazenar dado do nó que será desempilhado 
        Node<Tipo> *aux = topo; // Variável auxiliar de nó que é atribuída com o topo
        topo = topo->prox; // Transforma o topo no próximo da pilha
        delete aux; // Deleta o auxiliar contendo o top
        
        return temp; // Retorna o dado do nó desempilhado
    }
    Tipo elementoTopo(){
        return topo->info;
    }
    bool pilhaVazia(){
        return topo == NULL;
    }
    Node<Tipo> *getTopo(){
        return topo;
    }
};

#endif // PILHALIGADA_H_INCLUDED