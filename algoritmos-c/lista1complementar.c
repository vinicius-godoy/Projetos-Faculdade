#define ex2
#include<stdio.h>
#include<locale.h>

/*1. Escrever um algoritmo que leia dois valores inteiros distintos e informe qual é o maior.*/

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    int num1, num2; //variáveis do primeiro e segundo número
    do{
    printf("Digite dois números distintos para saber qual é o maior:\n");
    scanf("%i %i", &num1, &num2);
    if(num1 == num2){
        printf("Os dois números são iguais!\n");
    }
    }while(num1==num2); //pede os números de novo caso sejam iguais
    if(num1>num2){
        printf("O primeiro número digitado, %i, é maior que %i.", num1, num2);
    }else{
        printf("O segundo número digitado, %i, é maior que %i", num2, num1);
        }
    return 0;
}
#endif // ex1

/*2. Escrever um algoritmo que leia três números quaisquer e informe qual é o maior e se eles
forem todos igual informe ao usuário e solicite novos dados.*/

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    int num1, num2, num3; //variáveis do primeiro, segundo e terceiro número
    do{
    printf("Digite três números quaisquer para saber qual é o maior:\n");
    scanf("%i %i %i", &num1, &num2, &num3);
    if(num1==num2 && num2==num3){
        printf("Os números que você digitou são iguais! Tente outros números.\n\n");
    }
    }while(num1==num2 && num2==num3); //pede os números de novo caso sejam iguais
    if(num1>num2 && num1>num3){ //if para saber se o primeiro número é maior
        printf("O primeiro número é o maior, pois %i é maior que %i e %i", num1, num2, num3);
    }else{ //else com ifelse dentro para saber se o segundo ou o terceiro é maior
        if(num2>num1 && num2>num3){
        printf("O segundo número é o maior, pois %i é maior que %i e %i", num2, num1, num3);
        }else{
        printf("O terceiro número é o maior, pois %i é maior que %i e %i", num3, num2, num1);
        }
    }
    return 0;
}
#endif // ex2

/*3. Faça um algoritmo para receber um número qualquer e informar na tela se é par ou ímpar.*/

#ifdef ex3
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    int num, resto; //variáveis do número qualquer e o resto da divisão
    printf("Digite um número para saber se ele é par ou ímpar: ");
    scanf("%i", &num);
    resto=num%2; //conta pra saber se o número é par ou ímpar
    if(resto==0){ //se o resto for 0 o número é par
        printf("O número %i é par.", num);
    }else{ //se não ele é ímpar
    printf("O número %i é ímpar.", num);
    }
    return 0;
}
#endif // ex3

/*4. Receba três números que representam os lados de um triângulo e garantam a existência de um triângulo.
Informe ao usuário se o triângulo é isóscele, equilátero ou escaleno.
Observações:
a.	Garantir que cada lado é menor que a soma dos outros dois lados.
b.	O triângulo é equilátero quando todos os lados são iguais.
c.	O triângulo é isóscele quando apenas dois lados são iguais.
d.	O triângulo é escaleno quando todos os lados são diferentes.*/

#ifdef ex4
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    int lado1, lado2, lado3; //variáveis dos três lados e suas somas possíveis
    do{
    printf("Digite os três lados de um triângulo para saber se ele é isóscele, equilátero ou escaleno:\n");
    scanf("%i %i %i", &lado1, &lado2, &lado3);
    if(lado1>lado2 + lado3 || lado2>lado1 + lado3 || lado3>lado1 + lado2){
        printf("Estas medidas indicam um triângulo inexistente, digite outros valores!\n\n");
    }
    }while(lado1>lado2 + lado3 || lado2>lado1 + lado3 || lado3>lado1 + lado2); /*pede os lados de novo caso algum lado seja maior que
    a soma dos outros dois lados */
    if(lado1==lado2 && lado2==lado3){ //verifica se tem todos os lado iguais
        printf("O seu triângulo é equilátero!");
    }else{
        if(lado1!=lado2 && lado2!=lado3 && lado1!=lado3){ //verifica se tem todos os lado diferentes
        printf("O seu triângulo é escaleno!");
        }else{ //caso contrário ele será isóscele
        printf("O seu triângulo é isóscele!");
        }
    }
    return 0;
}
#endif // ex4

/*5. Faça um programa que receba o número de horas trabalhadas e o valor do salário mínimo. Calcule e
mostre o salário a receber seguindo as regras abaixo:
a. A hora trabalhada vale a metade do salário mínimo.
b. O salário bruto equivale ao número de horas trabalhadas multiplicado pelo valor da hora trabalhada.
c. O imposto equivale a 3% do salário bruto.
d. O salário a receber equivale ao salário bruto menos o imposto.*/

#ifdef ex5
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    float numht, vlrsm, vlrht, salbr; /* variáveis de número de horas trabalhadas, valor do salário
    mínimo, valor da hora trabalhada e salário bruto */
    printf("Digite o seu número de horas trabalhadas e o valor do salário mínimo para saber seu salário líquido:\n");
    scanf("%f %f", &numht, &vlrsm);
    vlrht = vlrsm / 2; //calcula o valor da hora trabalhada
    salbr = numht * vlrht; //calcula o salário bruto
    printf("O seu salário líquido é de %gR$.", salbr - (0.03 * salbr) ); //calcula e mostra o salário líquido
    return 0;
}
#endif // ex5

/*6. Cada degrau de uma escada tem X de altura. Faça um programa que receba essa altura e a altura que o
usuário deseja subindo a escada. Calcule e mostre quantos degraus o usuário deverá subir para atingir seu
objetivo, sem se preocupar com a altura do usuário.*/

#ifdef ex6
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    float malt, cmdegr, mdegr, numd; //variáveis de altura desejada em metro, centímetros do degrau, degraus em metro e número de degraus
    printf("Digite quantos metros de altura você deseja subir e quantos centímetros têm os degraus da escada para saber\nquantos degraus você precisará subir:\n");
    scanf("%f %f", &malt, &cmdegr);
    mdegr = cmdegr / 100; //cálculo que transforma os centímetros do degrau em metros
    numd = malt / mdegr; //cálculo para saber o número de degraus
    if(numd == 1){ //if para caso seja um degrau
        printf("Para alcançar %gm de altura você precisará subir %g degrau.", malt, numd);
    }else{ //else para caso sejam dois degraus ou mais
        printf("Para alcançar %gm de altura você precisará subir %g degraus.", malt, numd);
    }
    return 0;
}
#endif // ex6

/*7. Faça um programa que receba a altura e o sexo de uma pessoa e que calcule e mostre o seu peso ideal,
utilizando as seguintes fórmulas:
a.	Para homens (72 * h) – 58
b.	Para mulheres (62,1* h) – 44.7*/

#ifdef ex7
main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    float alt, pesid; //variáveis de peso e altura
    char sexo; //variável de sexo
    do{
    printf("Digite a sua altura (com vírgula) e o seu sexo (h ou m) para saber seu peso ideal!\n");
    printf("Digite primeiro sua altura: ");
    scanf("%f", &alt);
    if(alt <=0){
        printf("Você digitou uma altura inválida!\n");
    }
    }while(alt <= 0); //pede a altura de novo caso seja menor que 0
    do{
    printf("Agora digite seu sexo: ");
    getchar();
    sexo = getchar();
    if(sexo != 'h' && sexo != 'H' && sexo != 'm' && sexo != 'M'){
        printf("\nVocê digitou um sexo inválido! Escreva h ou m!\n");
    }
    }while(sexo != 'h' && sexo != 'H' && sexo != 'm' && sexo != 'M'); //pede o sexo de novo caso não seja válido
    if(sexo == 'h' || sexo == 'H'){
        pesid = (72 * alt) - 58;
        printf("O seu peso ideal é de %gkg.", pesid);
    }else{
        pesid = (62.1 * alt) - 44.7;
        printf("O seu peso ideal é de %gkg.", pesid);
    }
}
#endif // ex7

/*8. O IMC – Índice de Massa Corporal é um critério da Organização Mundial de Saúde para dar uma indicação
sobre a condição de peso de uma pessoa adulta. A fórmula é IMC = peso / (altura)2. Elabore um algoritmo que
leia o peso e a altura de um adulto e mostre sua condição de acordo com as condições abaixo:
a.	Condição Abaixo de 18,5
b.	Abaixo do peso Entre 18,5 e 25
c.	Peso normal Entre 25 e 30
d.	Acima do peso Acima de 30 obeso*/

#ifdef ex8
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    float imc, peso, alt; // variáveis de imc, peso e altura
    do{
    printf("Digite o seu peso e sua altura para saber sua condição de acordo com o IMC\n");
    printf("Digite seu peso em kg: ");
    scanf("%f", &peso);
    }while(peso <= 0); //pede o peso de novo se for menor que 0
    do{
    printf("Agora digite sua altura em metros: ");
    scanf("%f", &alt);
    }while(alt <= 0); //pede a altura de novo se for menor que 0
    imc = peso / (alt * 2); //fórmula do IMC
    if(imc < 18.5){
        printf("Você está abaixo do peso segundo o IMC."); //mensagem para abaixo de 18,5
    }else{
        if(imc < 25){
            printf("Você está no peso normal segundo o IMC"); //mensagem entre 18,5 e 25
        }else{
        if(imc < 30){
            printf("Você está acima do peso segundo o IMC"); //mensagem entre 25 e 30
        }else{
            printf("Você está obeso segundo o IMC"); //mensagem para acima de 30
        }
        }
}
}
#endif // ex8

/*9. Faça um programa que receba a altura e o peso de uma pessoa. De acordo com a tabela a seguir e mostre qual a
classificação dessa pessoa.
Altura                 |                         Peso                            |
                       |      Até 60    |   Entre 60 e 90    |   Acima de 90     |
Menores que 1,20       |        A       |         D          |         G         |
De 1,20 a 1,70         |        B       |         E          |         H         |
Maiores que 1,70       |        C       |         F          |         I         |              */

#ifdef ex9
main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    float alt, peso; //variáveis de altura e peso
    printf("Digite sua altura e seu peso para saber sua classificação\n");
    do{
    printf("Digite sua altura em metros (com vírgulas): ");
    scanf("%f", &alt);
    if (alt < 0){
        printf("Digite uma altura maior que zero !");
    }
    }while (alt < 0); //pede a altura de novo caso seja menor que 0
    do{
    printf("Agora digite seu peso em kg: ");
    scanf("%f", &peso);
    if (peso < 0){
        printf("Digite um peso maior que zero !");
    }
    }while (peso < 0); //pede o peso de novo caso seja menor que 0
    if (alt < 1.20) { //da a resposta pra quem tem menos de 1,20
        if(peso < 60){
            printf("Você tem a classificação A! Menor que 1,20m de altura e até 60kg.");
            }
        if(peso <= 90){
            printf("Você tem a classificação D! Menor que 1,20m de altura e de 60 a 90kg.");
        }else{
            printf("Você tem a classificação G! Menor que 1,20m de altura e mais de 90kg.");
        }
    }else{
        if(alt < 1.71){ //da a resposta pra quem tem entre 1,20 e 1,70
            if(peso < 60){
                printf("Você tem a classificação B! Entre 1,20 e 1,70m de altura e até 60kg.");
                }
            if(peso <= 90){
                printf("Você tem a classificação E! Entre 1,20 e 1,70m de altura e de 60 a 90kg.");
            }else{
                printf("Você tem a classificação H! Entre 1,20 e 1,70m de altura e mais de 90kg.");
            }
        }else{ //da a resposta pra quem tem mais de 1,70
            if(peso < 60){
                printf("Você tem a classificação C! Maior que 1,70m de altura e até 60kg.");
                }
            if(peso <= 90){
                printf("Você tem a classificação F! Maior que 1,70m de altura e de 60 a 90kg.");
            }else{
                printf("Você tem a classificação I! Maior que 1,70m de altura e mais de 90kg.");
            }
        }
    }
}
#endif // ex9

/*10. Faça um algoritmo que receba o a idade, o sexo (1 para masculino e 2 para feminino) e salário fixo de um funcionário.
Mostre o sexo, a idade e o salário obtido após o acréscimo do abono:
Sexo           | Idade     | Abono          |
1- Masculino   | >= 30     | 200,00         |
_______________| <  30     | 120,00         |
2- Feminino    | >= 30     | 220,00         |
_______________| <  30     | 130,00         |                                     */

#ifdef ex10
int main()
{
    setlocale(LC_ALL, "portuguese"); //função que permite pontuação
    int idade, sexo; //variáveis de idade e sexo
    float salf; //variável de sálario fixo
    printf("Digite as informações pedidas para saber seu salário após o acréscimo do abono\n");
    do{
    printf("Digite sua idade: ");
    scanf("%i", &idade);
    if(idade < 16){
        printf("Escreva uma idade válida! (maior que 16)\n");
    }
    }while(idade < 16); //pede a idade de novo caso seja menor que 16
    do{
    printf("Digite seu sexo (1 = homem ou 2 = mulher): ");
    scanf("%i", &sexo);
    if(sexo != 1 && sexo != 2){
        printf("Escreva um sexo válido! (1 = homem ou 2 = mulher)\n");
    }
    }while(sexo != 1 && sexo != 2); //pede o sexo de novo caso seja diferente de 1 ou 2
    do{
    printf("Digite seu salário fixo: ");
    scanf("%f", &salf);
    if(salf < 988){
        printf("Escreva um salário fixo válido! (acima de R$988)\n");
    }
    }while(salf < 988); //pede o sálario fixo de novo caso seja menor que R$ 988
    if(idade >= 30){ //if para pessoas acima de 30 anos
        if(sexo = 1){
        printf("Você tem %i anos e é do sexo masculino. Seu salário com abono será de %f", idade, salf + 200);
        }else{
        printf("Você tem %i anos e é do sexo feminino. Seu salário com abono será de %f", idade, salf + 220);
        }
    }else{ //else para pessoas abaixo de 30 anos
        if(sexo = 1){
        printf("Você tem %i anos e é do sexo masculino. Seu salário com abono será de %f", idade, salf + 120);
        }else{
        printf("Você tem %i anos e é do sexo feminino. Seu salário com abono será de %f", idade, salf + 130);
        }
    }
    return 0;
}
#endif
