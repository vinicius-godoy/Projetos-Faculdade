#ifndef ARCONDICIONADO_H_INCLUDED
#define ARCONDICIONADO_H_INCLUDED

class Arcondicionado{
    private:
    int temperatura;
    bool ligado;

    public:
    Arcondicionado(int t){
        temperatura = t;
        ligado = false;
    }

    void onOff(){
        if(ligado == false){
            ligado = true;
        }else{
            ligado = false;
        }
    }

    void aumentar(){
        if(temperatura < 30){
            temperatura++;
        }
    }

    void diminuir(){
        if(temperatura > 15){
            temperatura--;
        }
    }

    int getTemperatura(){
        return temperatura;
    }

    bool getLigado(){
        return ligado;
    }
};

#endif // ARCONDICIONADO_H_INCLUDED
