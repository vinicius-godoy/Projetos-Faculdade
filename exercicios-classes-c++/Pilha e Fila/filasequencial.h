#ifndef FILASEQUENCIAL_H_INCLUDED
#define FILASEQUENCIAL_H_INCLUDED

template <typename Tipo>

class Fila{
private:
    Tipo *v; // Ponteiro para dado do template da classe
    int fim;
    int inicio;
    unsigned tamanho;
    unsigned qtd; // Quantidade
public:
    //Construtor
    Fila(unsigned tam){
        tamanho = tam; // Tamanho definido pelo usuário passado por parâmetro
        fim = -1; inicio = 0; // Fim começa como -1 e início como 0
        qtd = 0; // Quantidade começa com 0 
        v = new Tipo[tamanho]; // Ponteiro aponta para um array de tamanho definido pelo usuário
    }

    //Destrutor
    ~Fila(){
        delete[] v;
    }

    //Métodos
    void insere(Tipo x){
        fim++; qtd++; // Incrementa fim e quantidade
        if(fim == tamanho){fim = 0;} // Se o fim chegar ao fim do array, ele circula pro começo
        v[fim] = x; // Adiciona dado ao array
    }
    Tipo exclui(){
        Tipo temp = v[inicio]; // Variável temporária para guardar dado que será removido
        inicio++; qtd--; // Incrementa início e decrementa quantidade
        if(inicio == tamanho){inicio = 0;} // Se o início chegar ao fim do array, ele circula pro começo

        return temp; // Retorna dado removido
    }
    bool cheia(){
        return qtd == tamanho;
    }
    bool vazia(){
        return qtd == 0;
    }
    Tipo primeiro(){
        return v[inicio];
    }

    //Métodos Get
    unsigned getTamanho(){
        return tamanho;
    }
    int getQuantidade(){
        return qtd;
    }
    int getFim(){
        return fim;
    }
    unsigned getInicio(){
        return inicio;
    }
    Tipo getPosicao(unsigned posicao){
        return v[posicao];
    }
};


#endif // FILASEQUENCIAL_H_INCLUDED
