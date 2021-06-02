#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED

template<typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *prox;
};

template<typename Tipo>
struct Lista{
    Node<Tipo> *h;
    
    Lista(){
        h = NULL;
    }

    bool listaVazia(){
        return h == NULL;
    }
    bool insere(Tipo x){
        bool v = true;
        Node<Tipo> *aux2;
        Node<Tipo> *aux = new Node<Tipo>;
        if(aux == NULL){
            v = false;
        }else{
            aux->info = x;
            if(h == NULL || x < h->info){
                aux->prox = h;
                h = aux;
            }else{
                aux2 = h;
                while(aux2->prox != NULL && x > aux2->prox->info){
                    aux2 = aux2->prox;
                }
                aux->prox = aux2->prox;
                aux2->prox = aux;
            }
        }

        return v;
    }
    bool remove(Tipo x){
        bool v = true;
        Node<Tipo> *aux2;
        Node<Tipo> *aux = new Node<Tipo>;
        aux = h;

        if(aux == NULL){ // Caso-base, a lista ordenada está vazia
            v = false;
        }else{
            if(aux->info == x){ // Caso o primeiro item da lista seja o removido
                h = aux->prox;
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

#endif // LISTAORDENADA_H_INCLUDED