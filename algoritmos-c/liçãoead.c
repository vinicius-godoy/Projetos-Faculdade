#define ex9
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//1. Mostre todos os n�meros �mpares de 1 at� 100. Utilize os tr�s la�os de repeti��o.
//Exerc�cio com 1 la�o do-while
#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = -1;

    printf("N�meros �mpares de 1 a 100\n");
    do{
        num += 2;
        printf("%i\n", num);
    }while(num<99);
}
#endif // ex1
//Exerc�cio 1 com la�o while
#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = -1;

    printf("N�meros �mpares de 1 a 100\n");
    while(num<99){
        num += 2;
        printf("%i\n", num);
    }
}
#endif // ex2
//Exerc�cio 1 com la�o for
#ifdef ex3
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num, cont;

    printf("N�meros �mpares de 1 a 100\n");
    for(cont = 1, num = 1; num<=99; cont++, num +=2)
    {
        printf("%i\n", num);
    }
}
#endif // ex3

/*2. Mostre todos os n�meros pares maiores ou iguais a  50  e menores ou iguais 300.
Fa�a  este exerc�cio utilizando os tr�s la�os de repeti��o. */
//Exerc�cio 2 com la�o do-while
#ifdef ex4
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = 48;

    printf("N�meros Pares maiores que 50 e menores que 300\n");
    do{
        num+=2;
        printf("%i\n", num);
    }while(num<300);
}
#endif // ex4
//Exerc�cio 2 com la�o do
#ifdef ex5
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num = 48;

    printf("N�meros Pares maiores que 50 e menores que 300\n");
    while(num<300){
        num+=2;
        printf("%i\n", num);
    }
}
#endif // ex5
//Exerc�cio 2 com la�o for
#ifdef ex6
int main()
{
    setlocale(LC_ALL, "portuguese");
    int num, cont;

    printf("N�meros Pares maiores que 50 e menores que 300\n");
    for(num=50, cont=1;num<=300;cont++, num+=2){
        printf("%i\n", num);
    }
}
#endif // ex6

/*3. Mostre todos os n�meros m�ltiplos de 3 entre os n�meros 1 e 70. Utilize o la�o for.*/
#ifdef ex7
int main()
{
    setlocale(LC_ALL, "portuguese");
    int cont;

    printf("M�ltiplos de 3 entre 1 e 70\n");
    for(cont = 1; cont<70; cont++){
        if(cont%3==0){
            printf("%i\n", cont);
        }
    }
}
#endif // ex7

/*4. Imprime todos os n�meros entre 30 e 5 (nesta ordem) divis�veis por 3.Imprima tamb�m no
final a soma dos n�meros divis�veis por 3.Utilize o la�o for. */
#ifdef ex8
int main()
{
    setlocale(LC_ALL, "portuguese");
    int cont, soma;

    printf("M�ltiplos de 3 entre 30 e 5\n");
    for(cont = 30, soma = 0; cont>5; cont--){
        if(cont%3==0){
            printf("%i\n", cont);
            soma += cont;
        }
    }
    printf("A soma de todos os m�ltiplos � %i", soma);
}
#endif // ex8

/*5. Receba a quantidade de alturas de um grupo de N pessoas. N representa essa quantidade
e deve ser digitada pelo usu�rio. A vari�vel H representa cada altura digitada. Calcule e
mostre a maior altura encontrada e  m�dia das alturas digitadas. */
#ifdef ex9
int main()
{
    setlocale(LC_ALL, "portuguese");
    int n, cont;
    float h, mediah, maiorh;

    printf("Digite o n�mero de pessoas pra ter sua altura comparada: ");
    scanf("%i", &n);
    for(cont = 0,h = 0, mediah = 0, maiorh = 0; cont<n; cont++){
        printf("Digite a altura da %i� pessoa:     m\b\b\b\b\b", cont+1);
        scanf("%f", &h);
        printf("------------------------------------\n");
        mediah += h;
        if(h>maiorh){
            maiorh = h;
        }
    }
    printf("A maior altura das digitadas � %.2fm e a m�dia de todas as alturas � %.2f\n", maiorh, mediah/n);
}
#endif // ex9
