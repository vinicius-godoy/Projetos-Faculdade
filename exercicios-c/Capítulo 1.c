#define ex1
#include <stdio.h>
#include <locale.h>

#ifdef ex1
/*1. Escreva um programa que receba dados via teclado para variaveis do tipo short,
long, int, float, double e um char e imprima-os no video no seguinte formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char              */
void main()
{
    setlocale(LC_ALL, "portuguese");
    short a;
    long b;
    int c;
    float d;
    double e;
    char f;

    printf("Digite os valores requisitados\n");
    printf("Valor do tipo Short: ");
    scanf("%hd", &a);
    printf("Valor do tipo Long: ");
    scanf("%ld", &b);
    printf("Valor do tipo Int: ");
    scanf("%d", &c);
    printf("Valor do tipo float: ");
    scanf("%f", &d);
    printf("Valor do tipo Double: ");
    scanf("%lf", &e);
    getchar();
    printf("Valor do tipo Char: ");
    f = getchar();

    printf("\n\n");
    printf("        10        20        30        40        50        60     \n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("    %-5hd               %-4ld                %-3d                  \n", a, b, c);
    printf("              %-5.2f               %-6.2lf              %-4c       \n", d, e, f);

    system("pause");
}
#endif // ex1

#ifdef ex2
/*2. Escreva um programa que receba via teclado um tempo em segundos e converta um
para horas, minutos e segundos.
Ex.: recebe 3850 segundos que converte para 1h 4min 10s.          */
void main()
{
    setlocale(LC_ALL, "portuguese");
    int tempo, tempof, horas, minutos, segundos;

    printf("Digite um espa�o de tempo em segundos para convert�-lo: ");
    scanf("%d", &tempo);

    //converter segundos em horas, minutos e segundos
    tempof = tempo;
    horas = tempo/3600;
    tempo -= (3600*horas);
    minutos = tempo/60;
    tempo -= (60*minutos);
    segundos = tempo;
    //converter segundos em horas, minutos e segundos

    printf("%d segundos s�o equivalentes a %dh %dm e %ds.\n", tempof, horas, minutos, segundos);

    system("pause");
}
#endif // ex2

#ifdef ex3
/*3. Escreva um programa para ler um numero inteiro, positivo de tres digitos, e gere
outro n�mero formado pelos d�gitos invertidos do n�mero lido.
Ex:   N�meroLido = 123
      N�meroGerado = 321                              */
void main()
{
    setlocale(LC_ALL, "portuguese");
    unsigned int num, numf, numinvertido = 0;

    do{
    printf("Digite um n�mero inteiro, positivo e de tr�s dig�tos para receb�-lo invertido: ");
    scanf("%u", &num);
    if(num < 100 || num > 999){
        printf("\aO n�mero digitado deve ser inteiro, positivo e de tr�s d�gitos!!!\n");
    }
    }while(num < 100 || num > 999);

    numf = num;
    while (num != 0){
    numinvertido = numinvertido * 10;
    numinvertido = numinvertido + num%10;
    num = num/10;
    }

    printf("\n\nn�mero = %u | n�mero invertido = %u\n", numf, numinvertido);

    system("pause");
}
#endif // ex3

#ifdef ex4
/*4. Escreva um programa que permute o conte�do de duas vari�veis sem utilizar uma
vari�vel auxiliar.                      */
void main()
{
    setlocale(LC_ALL, "portuguese");
    int a, b;

    printf("Digite um n�mero para cada vari�vel\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    //permuta as vari�veis
    a = a + b;
    b = a - b;
    a = a - b;

    printf("Valores permutados:\na = %d\nb = %d\n", a, b);

    system("pause");
}
#endif // ex4

#ifdef ex5
/*5. Escreva um programa que l� um valor em reais e calcula qual o menor n�mero
poss�vel de notas de $100, $50, $10, $5, $2 e $1 em que o valor lido pode ser
decomposto. Escrever o valor lido e a rela��o de notas necess�rias.   */
void main()
{
    setlocale(LC_ALL, "portuguese");
    int valor, valorf, n100, n50, n10, n2, n1;

    printf("Digite um valor inteiro em Reais para saber qual o n�mero m�nimo de notas voc� poderia adquir�-lo\n");
    printf("R$ ");
    scanf("%d", &valor);

    //Armazena o valor em uma vari�vel pra ser printada depois
    valorf = valor;
    //Converter valor em notas menores
    n100 = valor/100;
    valor -= (100*n100);
    n50 = valor/50;
    valor -= (50*n50);
    n10 = valor/10;
    valor -= (10*n10);
    n2 = valor/2;
    valor -= (2*n2);
    n1 = valor/1;
    valor -= (1*n1);
    //Converter valor em notas menores

    printf("\nEste valor pode ser divididos em:\n");
    if(n100 > 0){if(n100 == 1){printf("%d nota  de R$100\n", n100);}else{printf("%d notas de R$100\n", n100);}}
    if(n50 > 0){if(n50 == 1){printf("%d nota  de R$50\n", n50);}else{printf("%d notas de R$50\n", n50);}}
    if(n10 > 0){if(n10 == 1){printf("%d nota  de R$10\n", n10);}else{printf("%d notas de R$10\n", n10);}}
    if(n2 > 0){if(n2 == 1){printf("%d nota  de R$2\n", n100);}else{printf("%d notas de R$2\n", n2);}}
    if(n1 > 0){if(n1 == 1){printf("%d nota  de R$1\n", n100);}else{printf("%d notas de R$1\n", n100);}}

    system("pause");
}
#endif // ex5
