#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

#include <iostream>
class Teatro{
private:
    char *lugares;
    int linhas;
    int colunas;
public:
    /* Construtores */
    Teatro(int lin, int col){
        lugares = new char[lin*col];
        linhas = lin; colunas = col;

        for(int i = 0; i < lin*col; i++){
            lugares[i] = ' ';
        }
    }

    /* Métodos comuns */
    int reservar(int lin, int col){
        int i;
        // \/ Fórmula pra converter os indíces da matriz bidimensional nos do vetor unidimensional
        i = ((lin - 1) * colunas) + (col - 1);
        if(lugares[i] == 'x')
            return 0;
        else
            lugares[i] = 'x';
        return 1;
    }
    int trocar(int lin, int col, int lin2, int col2){
        int i, j;
        i = ((lin - 1) * colunas) + (col - 1);
        j = ((lin2 - 1) * colunas) + (col2 - 1);

        if(lugares[i] == ' ')
            return 0;
        else if(lugares[j] == 'x')
            return -1;
        else{
            lugares[i] = ' ';
            lugares[j] = 'x';
            return 1;
        }
    }
    int devolver(int lin, int col){
        int i;
        i = ((lin - 1) * colunas) + (col - 1);
        if(lugares[i] == ' ')
            return 0;
        else
            lugares[i] = ' ';
        return 1;
    }

    /* Métodos Get */
    char* getLugares(){
        return lugares;
    }
    unsigned int getLin(){
        return linhas;
    }
    unsigned int getCol(){
        return colunas;
    }
};

#endif // TEATRO_H_INCLUDED
