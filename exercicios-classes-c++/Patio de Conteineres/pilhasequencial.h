#ifndef FILASEQUENCIAL_H_INCLUDED
#define FILASEQUENCIAL_H_INCLUDED

template <typename Tipo>

class Pilha{
private:
    int topo;
    Tipo *v;
    int tamanho;
public:
    //Construtor
    Pilha(int tam){
        tamanho = tam;
        topo = -1;
        v = new Tipo[tamanho];
    }

    //Destrutor
    ~Pilha(){
        delete[] v;
    }

    //Métodos
    void empilha(Tipo x){
        v[++topo] = x;
    }

    Tipo desempilha(){
        Tipo temp = v[topo];
        topo--;
        return temp;
    }
    Tipo elemTopo(){
        return v[topo];
    }
    bool pilhaCheia(){
        return topo == tamanho - 1;
    }
    bool pilhaVazia(){
        return topo == -1;
    }

    //Métodos Get
    unsigned getTamanho(){
        return tamanho;
    }
    int getTopo(){
        return topo;
    }
    Tipo getValor(int posicao){
        return v[posicao];
    }
};

#endif // FILASEQUENCIAL_H_INCLUDED
