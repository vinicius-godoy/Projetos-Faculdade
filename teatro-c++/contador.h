#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED

class Contador{
private:
    unsigned int num_pessoas;
    unsigned int num_max;
public:
    /* Construtores */
    Contador(int c, int m){
        num_pessoas = c;
        num_max = m;
    }
    Contador(int m){
        num_pessoas = 0;
        num_max = m;
    }
    Contador(){
        num_pessoas = 0;
        num_max = 50;
    }

    /* Métodos */
    void aumentarNum(){
        if(num_pessoas < num_max){
            num_pessoas++;
        }
    }
    void aumentarNum(int n){
        if(num_pessoas < num_max && num_pessoas + n <= num_max){
            num_pessoas += n;
        }
    }
    void diminuirNum(){
        if(num_pessoas > 0){
            num_pessoas--;
        }
    }
    void diminuirNum(int n){
        if(num_pessoas > 0 && num_pessoas - n >= 0){
            num_pessoas -= n;
        }
    }

    /* Métodos Get */
    unsigned int getNum(){
        return num_pessoas;
    }
    unsigned int getNumMax(){
        return num_max;
    }

    /* Métodos Set */
    void setNumMax(int m){
        num_max = m;
    }
};

#endif // CONTADOR_H_INCLUDED
