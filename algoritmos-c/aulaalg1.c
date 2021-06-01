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
    printf("Digite três números para saber se a equação de segundo grau é completa\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &a);
    }while(a == 0);
    printf("Digite o segundo número: ");
    scanf("%f", &b);
    }while(b == 0);
    printf("Digite o terceiro número: ");
    scanf("%f", &c);
    }while(c == 0);
    d = pow(b,2) - 4 * a * c;
    x1 = (-b - sqrt(d)) / (2 * a);
    x2 = (-b +
          1 sqrt(d)) / (2 * a);
    if(d >= 0){
        printf("A sua equação de segundo grau tem raízes reais! Elas são x=%g e x'=%g", x1, x2);
    }else{
        printf("A sua equação de segundo grau não tem raízes reais!");
    }
}

#endif //ex1//

#ifdef ex2
main()
{
    setlocale(LC_ALL, "portuguese");
    float sala;
    do{
    printf("Digite o seu salário atual para saber seu salário reajustado: ");
    scanf("%f", &sala);
    if(sala<800){
            printf("Digite um salário válido!\n\n");
    }
    }while(sala<800);
    if(sala<1000)
    {
        printf("O seu salário reajustado será de %gR$", sala * 1.2);
    }else{
        if(sala<=1500){
        printf("O seu salário reajustado será de %gR$", sala * 1.15);
    }else{
        printf("O seu salário reajustado será de %gR$", sala * 1.1);
    }
    }
}
#endif // ex2
