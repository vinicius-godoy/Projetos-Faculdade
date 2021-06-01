#define ex3
#include <stdio.h>
#include <locale.h>

/* Crie a fun��o Divis�o que receba da fun��o main dois n�meros que possibilitem o c�lculo da
divis�o do primeiro pelo segundo. Exiba na fun��o main os n�meros e o resultado obtido na
fun��o Divis�o. */
#ifdef ex1
float numeros();
float divisao(float dividendo, float divisor);

int main()
{
    setlocale(LC_ALL, "portuguese");
    float dividendo, divisor, quociente;

    printf("Digite dois n�meros para divid�-los e obter o resultado\n");
    dividendo = numeros();
    divisor = numeros();
    quociente = divisao(dividendo, divisor);
    printf("O resultado da divis�o de %g por %g � %g", dividendo, divisor, quociente);
}

float numeros()
{
    float num;
    printf("Digite um n�mero: ");
    scanf("%f", &num);
    return num;
}
float divisao(float dividendo, float divisor)
{
    float quociente;
    quociente = dividendo/divisor;
    return quociente;
}
#endif

/* Crie a fun��o ParImpar que receba da fun��o main um valor do tipo inteiro e maior que zero
que verifique  se o n�mero � para ou �mpar. Exiba no interior da fun��o Parimpar. */
#ifdef ex2
int ParImpar();

int main()
{
    setlocale(LC_ALL, "portuguese");

    ParImpar();
}

int ParImpar()
{
    int num;
    do{
    printf("Digite um n�mero maior do que zero: ");
    scanf("%i", &num);
    if(num < 0){
        printf("O n�mero digitado deve ser maior do que zero!\n");
    }
    }while(num < 0);
    if(num % 2 == 0){
        printf("O n�mero %i � par!", num);
    }else{
        printf("O n�mero %i � �mpar!", num);
    }
}
#endif // ex2

/* Crie a fun��o ReajSalNovo que receba da fun��o main o valor do sal�rio e efetue o c�lculo
do reajuste de sal�rio cada funcion�rio. Considere que o funcion�rio deve receber um reajuste
de 15% caso seu sal�rio seja menor que 800 reais. Se o sal�rio for maior ou igual a 800 e
menor ou igual a 1000, seu reajuste ser� de 10 %; caso seja maior que 1000, o reajuste deve
ser de 5%. Exiba na fun��o main o sal�rio antigo e novo sal�rio obtido na fun��o.*/
#ifdef ex3
float ReajSalNovo(float salario);

int main()
{
    setlocale(LC_ALL, "portuguese");
    float sala, saln;

    printf("Digite o seu sal�rio atual para receber o seu sal�rio ap�s o reajuste: ");
    scanf("%f", &sala);
    saln = ReajSalNovo(sala);
    printf("O seu sal�rio atual � de %.2fR$ e ap�s o reajuste ser� de %.2fR$ !", sala, saln);
}

float ReajSalNovo(float salario)
{
    float reajuste;

    if(salario < 800){
        reajuste = salario + (salario * 0.15);
    }else if(salario <=1 1000){
        reajuste = salario + (salario * 0.10);
    }else {
        reajuste = salario + (salario * 0.05);
    }
    return reajuste;
}
#endif // ex3
