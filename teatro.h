#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

#include <iostream>
#include <cstdlib>

class Teatro{
private:
    int linhas;
    int colunas;
    char *lugares;
public:
    /* Construtor */
    Teatro(int lin, int col){
        linhas = lin; colunas = col;
        lugares = new char[linhas * colunas];

        for (int i=0;i<linhas*colunas;i++){
            lugares[i] = ' ';
        }
    }
    /* Destructor */
    ~Teatro(){
        delete[] lugares;
    }

    /* M�todos comuns */
    int reservar(int lin, int col){
        if(lugares[lin*colunas+col] == 'x'){
            return 0; //Retorna 0 se o lugar que quer reservar j� tiver sido reservado
        }else{
            lugares[lin*colunas+col] = 'x';
            return 1; //Reserva o lugar e retorna 1 se houver sucesso
        }
    }
    int trocar(int lin, int col, int lin2, int col2){
        int v, v2;
        v = lin*colunas+col; //F�rmula do vetor do lugar que vai ser trocado
        v2 = lin2*colunas+col2; //F�rmula do vetor do lugar que vai ser pego

        if(lugares[v] == ' '){
            return 0; //Retorna 0 se o lugar que deseja trocar n�o tiver sido reservado ainda
        }else if(lugares[v2] == 'x'){
            return -1; //Retorna -1 se o lugar que deseja pegar na troca j� tiver sido reservado
        }else{
            lugares[v] = ' ';
            lugares[v2] = 'x';
            return 1; //Troca os lugares e retorna 1 se houver sucesso
        }
    }
    int devolver(int lin, int col){
        if(lugares[lin*colunas+col] == ' '){
            return 0; //Retorna 0 se o lugar que quer devolvido n�o tiver sido reservado ainda
        }else{
            lugares[lin*colunas+col] = ' ';
            return 1; //Devolve o lugar e retorna 1 se houver sucesso
        }
    }

    /* M�todos Get */
    char getLugar(int lin, int col){
        return lugares[lin*colunas+col];
    }
    int getLin(){
        return linhas;
    }
    int getCol(){
        return colunas;
    }
};

#endif // TEATRO_H_INCLUDED
