#include <iostream>
#include <ctime>
#include "recursivas.h"

using namespace std;

int main(){
    cout << "Fatorial de 5 = " << fatorial(5) << endl;
    cout << "Fatorial de 5 = " << fatr(5) << endl;
    cout << "Fibonnaci de 5 = " << fib(5) << endl;
    cout << "MDC de 64 e 14 = " << mdc(64, 14) << endl;
    cout << "Somatoria = " << soma1(2, 2) << endl;
    cout << "Digitos em 53223 = " << dig(53223) << endl;
    cout << "2^5 = " << pot(2, 5) << endl;

    return 0;
}