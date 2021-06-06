#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#define W 5

struct Node{
    int info;
    Node *prox;
};

struct Hash{
    Node *h[W];

    Hash(){
        for(int i = 0; i < W; i++){
            h[i] = NULL;
        }
    }

    bool listaVazia(unsigned lista){
        return h[lista] == NULL;
    }

    unsigned fht(int x){
        return x % W;
    }

    void insere(int x){
        Node *aux2;
        Node *aux = new Node;
        aux->info = x;
        unsigned p = fht(x);
        if(h[p] == NULL || x < h[p]->info){
            aux->prox = h[p];
            h[p] = aux;
        }else{
            aux2 = h[p];
            while(aux2->prox != NULL && x > aux2->prox->info){
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }
    
    bool remove(int x){
        unsigned p = fht(x); // Verifica em qual lista da tabela hash o valor estaria
        bool v = true;
        Node *aux2;
        Node *aux = new Node;
        aux = h[p]; // Coloca o auxiliar como a cabeça da lista p

        if(aux == NULL){ // Caso-base, a lista ordenada está vazia
            v = false;
        }else{
            if(aux->info == x){ // Caso o primeiro item da lista seja o removido
                h[p] = aux->prox;
                delete(aux);
            }else{
                while(aux->prox != NULL && aux->prox->info != x){ // Procura o item na lista
                    aux = aux->prox;
                }
                aux2 = aux->prox;
                if(aux2 == NULL){ // Se o aux2 (o suposto número) for NULL não está na lista
                    v = false;
                }else{ // Se estiver pula o removido e o exclui
                    aux->prox = aux->prox->prox; 
                    delete(aux2);
                }
            }
        }
        return v; // Retorna a situação da remoção
    }
};

#endif // HASH_H_INCLUDED