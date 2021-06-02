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
        tamanho = tam; // Tamanho definido pelo usu�rio passado por par�metro
        fim = -1; inicio = 0; // Fim come�a como -1 e in�cio como 0
        qtd = 0; // Quantidade come�a com 0 
        v = new Tipo[tamanho]; // Ponteiro aponta para um array de tamanho definido pelo usu�rio
    }

    //Destrutor
    ~Fila(){
        delete[] v;
    }

    //M�todos
    void insere(Tipo x){
        fim++; qtd++; // Incrementa fim e quantidade
        if(fim == tamanho){fim = 0;} // Se o fim chegar ao fim do array, ele circula pro come�o
        v[fim] = x; // Adiciona dado ao array
    }
    Tipo exclui(){
        Tipo temp = v[inicio]; // Vari�vel tempor�ria para guardar dado que ser� removido
        inicio++; qtd--; // Incrementa in�cio e decrementa quantidade
        if(inicio == tamanho){inicio = 0;} // Se o in�cio chegar ao fim do array, ele circula pro come�o

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

    //M�todos Get
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
