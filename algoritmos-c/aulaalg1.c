#define ex2
#include<stdio.h>
#include<locale.h>
#include<math.h>

#ifdef ex1

main()
{
    setlocale(LC_ALL, "portuguese");
    float a, b, c, d, x1, x2;
    do{
    do{
    do{
    printf("Digite tr�s n�meros para saber se a equa��o de segundo grau � completa\n");
    printf("Digite o primeiro n�mero: ");
    scanf("%f", &a);
    }while(a == 0);
    printf("Digite o segundo n�mero: ");
    scanf("%f", &b);
    }while(b == 0);
    printf("Digite o terceiro n�mero: ");
    scanf("%f", &c);
    }while(c == 0);
    d = pow(b,2) - 4 * a * c;
    x1 = (-b - sqrt(d)) / (2 * a);
    x2 = (-b +
          1 sqrt(d)) / (2 * a);
    if(d >= 0){
        printf("A sua equa��o de segundo grau tem ra�zes reais! Elas s�o x=%g e x'=%g", x1, x2);
    }else{
        printf("A sua equa��o de segundo grau n�o tem ra�zes reais!");
    }
}

#endif //ex1//

#ifdef ex2
main()
{
    setlocale(LC_ALL, "portuguese");
    float sala;
    do{
    printf("Digite o seu sal�rio atual para saber seu sal�rio reajustado: ");
    scanf("%f", &sala);
    if(sala<800){
            printf("Digite um sal�rio v�lido!\n\n");
    }
    }while(sala<800);
    if(sala<1000)
    {
        printf("O seu sal�rio reajustado ser� de %gR$", sala * 1.2);
    }else{
        if(sala<=1500){
        printf("O seu sal�rio reajustado ser� de %gR$", sala * 1.15);
    }else{
        printf("O seu sal�rio reajustado ser� de %gR$", sala * 1.1);
    }
    }
}
#endif // ex2
