#ifndef RECURSIVAS_H_INCLUDED
#define RECURSIVAS_H_INCLUDED
#include <cmath>

double fatorial(int n){
    double f = 1;
    if(n != 0){
        for(int i = 1; i <= n; i++){
            f = f*i;
        }
    }

    return f;
}
double fatr(int n){
    if(n == 0){
        return 1;
    }else{
        return n * fatr(n - 1);
    }                           
}
int fib(int n){
    if(n <= 2){
        return 1;
    }else{
        return fib(n - 1) + fib(n - 2);
    }
}
int mdc(int x, int y){
    if(x == y){
        return x;
    }else if(x < y){
        return mdc(y, x);
    }else{
        return mdc(x-y, y);
    }
}
int soma1(int m, int n){
    if(n == m){
        return m;
    }else if(m < n){
        return soma1(m, n - 1) + n;
    }
}
int soma2(int m, int n){
    if(n == m){
        return m;
    }else if(m < n){
        return m + soma2(m + 1, n);
    }
}
int dig(int n){
    if(n <= 9){
        return 1;
    }else{
        return 1 + dig(n/10);
    }
}
double pot(int x, int n){
    if(n == 0){
        return 1;
    }else if(n < 0){
        return 1/pot(x, std::abs(n));
    }else{
        return x * pot(x, n - 1);
    }
}
int retornar2(){
    return 2;
}


#endif // RECURSIVAS_H_INCLUDED