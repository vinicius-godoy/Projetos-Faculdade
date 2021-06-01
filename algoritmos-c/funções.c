#define ex3
#include <stdio.h>
#include <locale.h>

/* Crie a função Divisão que receba da função main dois números que possibilitem o cálculo da
divisão do primeiro pelo segundo. Exiba na função main os números e o resultado obtido na
função Divisão. */
#ifdef ex1
float numeros();
float divisao(float dividendo, float divisor);

int main()
{
    setlocale(LC_ALL, "portuguese");
    float dividendo, divisor, quociente;

    printf("Digite dois números para dividí-los e obter o resultado\n");
    dividendo = numeros();
    divisor = numeros();
    quociente = divisao(dividendo, divisor);
    printf("O resultado da divisão de %g por %g é %g", dividendo, divisor, quociente);
}

float numeros()
{
    float num;
    printf("Digite um número: ");
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

/* Crie a função ParImpar que receba da função main um valor do tipo inteiro e maior que zero
que verifique  se o número é para ou ímpar. Exiba no interior da função Parimpar. */
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
    printf("Digite um número maior do que zero: ");
    scanf("%i", &num);
    if(num < 0){
        printf("O número digitado deve ser maior do que zero!\n");
    }
    }while(num < 0);
    if(num % 2 == 0){
        printf("O número %i é par!", num);
    }else{
        printf("O número %i é ímpar!", num);
    }
}
#endif // ex2

/* Crie a função ReajSalNovo que receba da função main o valor do salário e efetue o cálculo
do reajuste de salário cada funcionário. Considere que o funcionário deve receber um reajuste
de 15% caso seu salário seja menor que 800 reais. Se o salário for maior ou igual a 800 e
menor ou igual a 1000, seu reajuste será de 10 %; caso seja maior que 1000, o reajuste deve
ser de 5%. Exiba na função main o salário antigo e novo salário obtido na função.*/
#ifdef ex3
float ReajSalNovo(float salario);

int main()
{
    setlocale(LC_ALL, "portuguese");
    float sala, saln;

    printf("Digite o seu salário atual para receber o seu salário após o reajuste: ");
    scanf("%f", &sala);
    saln = ReajSalNovo(sala);
    printf("O seu salário atual é de %.2fR$ e após o reajuste será de %.2fR$ !", sala, saln);
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
