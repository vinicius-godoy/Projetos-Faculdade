#define ex2
#include<stdio.h>
#include<locale.h>

/*1. Escrever um algoritmo que leia dois valores inteiros distintos e informe qual � o maior.*/

#ifdef ex1
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    int num1, num2; //vari�veis do primeiro e segundo n�mero
    do{
    printf("Digite dois n�meros distintos para saber qual � o maior:\n");
    scanf("%i %i", &num1, &num2);
    if(num1 == num2){
        printf("Os dois n�meros s�o iguais!\n");
    }
    }while(num1==num2); //pede os n�meros de novo caso sejam iguais
    if(num1>num2){
        printf("O primeiro n�mero digitado, %i, � maior que %i.", num1, num2);
    }else{
        printf("O segundo n�mero digitado, %i, � maior que %i", num2, num1);
        }
    return 0;
}
#endif // ex1

/*2. Escrever um algoritmo que leia tr�s n�meros quaisquer e informe qual � o maior e se eles
forem todos igual informe ao usu�rio e solicite novos dados.*/

#ifdef ex2
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    int num1, num2, num3; //vari�veis do primeiro, segundo e terceiro n�mero
    do{
    printf("Digite tr�s n�meros quaisquer para saber qual � o maior:\n");
    scanf("%i %i %i", &num1, &num2, &num3);
    if(num1==num2 && num2==num3){
        printf("Os n�meros que voc� digitou s�o iguais! Tente outros n�meros.\n\n");
    }
    }while(num1==num2 && num2==num3); //pede os n�meros de novo caso sejam iguais
    if(num1>num2 && num1>num3){ //if para saber se o primeiro n�mero � maior
        printf("O primeiro n�mero � o maior, pois %i � maior que %i e %i", num1, num2, num3);
    }else{ //else com ifelse dentro para saber se o segundo ou o terceiro � maior
        if(num2>num1 && num2>num3){
        printf("O segundo n�mero � o maior, pois %i � maior que %i e %i", num2, num1, num3);
        }else{
        printf("O terceiro n�mero � o maior, pois %i � maior que %i e %i", num3, num2, num1);
        }
    }
    return 0;
}
#endif // ex2

/*3. Fa�a um algoritmo para receber um n�mero qualquer e informar na tela se � par ou �mpar.*/

#ifdef ex3
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    int num, resto; //vari�veis do n�mero qualquer e o resto da divis�o
    printf("Digite um n�mero para saber se ele � par ou �mpar: ");
    scanf("%i", &num);
    resto=num%2; //conta pra saber se o n�mero � par ou �mpar
    if(resto==0){ //se o resto for 0 o n�mero � par
        printf("O n�mero %i � par.", num);
    }else{ //se n�o ele � �mpar
    printf("O n�mero %i � �mpar.", num);
    }
    return 0;
}
#endif // ex3

/*4. Receba tr�s n�meros que representam os lados de um tri�ngulo e garantam a exist�ncia de um tri�ngulo.
Informe ao usu�rio se o tri�ngulo � is�scele, equil�tero ou escaleno.
Observa��es:
a.	Garantir que cada lado � menor que a soma dos outros dois lados.
b.	O tri�ngulo � equil�tero quando todos os lados s�o iguais.
c.	O tri�ngulo � is�scele quando apenas dois lados s�o iguais.
d.	O tri�ngulo � escaleno quando todos os lados s�o diferentes.*/

#ifdef ex4
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    int lado1, lado2, lado3; //vari�veis dos tr�s lados e suas somas poss�veis
    do{
    printf("Digite os tr�s lados de um tri�ngulo para saber se ele � is�scele, equil�tero ou escaleno:\n");
    scanf("%i %i %i", &lado1, &lado2, &lado3);
    if(lado1>lado2 + lado3 || lado2>lado1 + lado3 || lado3>lado1 + lado2){
        printf("Estas medidas indicam um tri�ngulo inexistente, digite outros valores!\n\n");
    }
    }while(lado1>lado2 + lado3 || lado2>lado1 + lado3 || lado3>lado1 + lado2); /*pede os lados de novo caso algum lado seja maior que
    a soma dos outros dois lados */
    if(lado1==lado2 && lado2==lado3){ //verifica se tem todos os lado iguais
        printf("O seu tri�ngulo � equil�tero!");
    }else{
        if(lado1!=lado2 && lado2!=lado3 && lado1!=lado3){ //verifica se tem todos os lado diferentes
        printf("O seu tri�ngulo � escaleno!");
        }else{ //caso contr�rio ele ser� is�scele
        printf("O seu tri�ngulo � is�scele!");
        }
    }
    return 0;
}
#endif // ex4

/*5. Fa�a um programa que receba o n�mero de horas trabalhadas e o valor do sal�rio m�nimo. Calcule e
mostre o sal�rio a receber seguindo as regras abaixo:
a. A hora trabalhada vale a metade do sal�rio m�nimo.
b. O sal�rio bruto equivale ao n�mero de horas trabalhadas multiplicado pelo valor da hora trabalhada.
c. O imposto equivale a 3% do sal�rio bruto.
d. O sal�rio a receber equivale ao sal�rio bruto menos o imposto.*/

#ifdef ex5
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    float numht, vlrsm, vlrht, salbr; /* vari�veis de n�mero de horas trabalhadas, valor do sal�rio
    m�nimo, valor da hora trabalhada e sal�rio bruto */
    printf("Digite o seu n�mero de horas trabalhadas e o valor do sal�rio m�nimo para saber seu sal�rio l�quido:\n");
    scanf("%f %f", &numht, &vlrsm);
    vlrht = vlrsm / 2; //calcula o valor da hora trabalhada
    salbr = numht * vlrht; //calcula o sal�rio bruto
    printf("O seu sal�rio l�quido � de %gR$.", salbr - (0.03 * salbr) ); //calcula e mostra o sal�rio l�quido
    return 0;
}
#endif // ex5

/*6. Cada degrau de uma escada tem X de altura. Fa�a um programa que receba essa altura e a altura que o
usu�rio deseja subindo a escada. Calcule e mostre quantos degraus o usu�rio dever� subir para atingir seu
objetivo, sem se preocupar com a altura do usu�rio.*/

#ifdef ex6
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    float malt, cmdegr, mdegr, numd; //vari�veis de altura desejada em metro, cent�metros do degrau, degraus em metro e n�mero de degraus
    printf("Digite quantos metros de altura voc� deseja subir e quantos cent�metros t�m os degraus da escada para saber\nquantos degraus voc� precisar� subir:\n");
    scanf("%f %f", &malt, &cmdegr);
    mdegr = cmdegr / 100; //c�lculo que transforma os cent�metros do degrau em metros
    numd = malt / mdegr; //c�lculo para saber o n�mero de degraus
    if(numd == 1){ //if para caso seja um degrau
        printf("Para alcan�ar %gm de altura voc� precisar� subir %g degrau.", malt, numd);
    }else{ //else para caso sejam dois degraus ou mais
        printf("Para alcan�ar %gm de altura voc� precisar� subir %g degraus.", malt, numd);
    }
    return 0;
}
#endif // ex6

/*7. Fa�a um programa que receba a altura e o sexo de uma pessoa e que calcule e mostre o seu peso ideal,
utilizando as seguintes f�rmulas:
a.	Para homens (72 * h) � 58
b.	Para mulheres (62,1* h) � 44.7*/

#ifdef ex7
main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    float alt, pesid; //vari�veis de peso e altura
    char sexo; //vari�vel de sexo
    do{
    printf("Digite a sua altura (com v�rgula) e o seu sexo (h ou m) para saber seu peso ideal!\n");
    printf("Digite primeiro sua altura: ");
    scanf("%f", &alt);
    if(alt <=0){
        printf("Voc� digitou uma altura inv�lida!\n");
    }
    }while(alt <= 0); //pede a altura de novo caso seja menor que 0
    do{
    printf("Agora digite seu sexo: ");
    getchar();
    sexo = getchar();
    if(sexo != 'h' && sexo != 'H' && sexo != 'm' && sexo != 'M'){
        printf("\nVoc� digitou um sexo inv�lido! Escreva h ou m!\n");
    }
    }while(sexo != 'h' && sexo != 'H' && sexo != 'm' && sexo != 'M'); //pede o sexo de novo caso n�o seja v�lido
    if(sexo == 'h' || sexo == 'H'){
        pesid = (72 * alt) - 58;
        printf("O seu peso ideal � de %gkg.", pesid);
    }else{
        pesid = (62.1 * alt) - 44.7;
        printf("O seu peso ideal � de %gkg.", pesid);
    }
}
#endif // ex7

/*8. O IMC � �ndice de Massa Corporal � um crit�rio da Organiza��o Mundial de Sa�de para dar uma indica��o
sobre a condi��o de peso de uma pessoa adulta. A f�rmula � IMC = peso / (altura)2. Elabore um algoritmo que
leia o peso e a altura de um adulto e mostre sua condi��o de acordo com as condi��es abaixo:
a.	Condi��o Abaixo de 18,5
b.	Abaixo do peso Entre 18,5 e 25
c.	Peso normal Entre 25 e 30
d.	Acima do peso Acima de 30 obeso*/

#ifdef ex8
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    float imc, peso, alt; // vari�veis de imc, peso e altura
    do{
    printf("Digite o seu peso e sua altura para saber sua condi��o de acordo com o IMC\n");
    printf("Digite seu peso em kg: ");
    scanf("%f", &peso);
    }while(peso <= 0); //pede o peso de novo se for menor que 0
    do{
    printf("Agora digite sua altura em metros: ");
    scanf("%f", &alt);
    }while(alt <= 0); //pede a altura de novo se for menor que 0
    imc = peso / (alt * 2); //f�rmula do IMC
    if(imc < 18.5){
        printf("Voc� est� abaixo do peso segundo o IMC."); //mensagem para abaixo de 18,5
    }else{
        if(imc < 25){
            printf("Voc� est� no peso normal segundo o IMC"); //mensagem entre 18,5 e 25
        }else{
        if(imc < 30){
            printf("Voc� est� acima do peso segundo o IMC"); //mensagem entre 25 e 30
        }else{
            printf("Voc� est� obeso segundo o IMC"); //mensagem para acima de 30
        }
        }
}
}
#endif // ex8

/*9. Fa�a um programa que receba a altura e o peso de uma pessoa. De acordo com a tabela a seguir e mostre qual a
classifica��o dessa pessoa.
Altura                 |                         Peso                            |
                       |      At� 60    |   Entre 60 e 90    |   Acima de 90     |
Menores que 1,20       |        A       |         D          |         G         |
De 1,20 a 1,70         |        B       |         E          |         H         |
Maiores que 1,70       |        C       |         F          |         I         |              */

#ifdef ex9
main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    float alt, peso; //vari�veis de altura e peso
    printf("Digite sua altura e seu peso para saber sua classifica��o\n");
    do{
    printf("Digite sua altura em metros (com v�rgulas): ");
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
            printf("Voc� tem a classifica��o A! Menor que 1,20m de altura e at� 60kg.");
            }
        if(peso <= 90){
            printf("Voc� tem a classifica��o D! Menor que 1,20m de altura e de 60 a 90kg.");
        }else{
            printf("Voc� tem a classifica��o G! Menor que 1,20m de altura e mais de 90kg.");
        }
    }else{
        if(alt < 1.71){ //da a resposta pra quem tem entre 1,20 e 1,70
            if(peso < 60){
                printf("Voc� tem a classifica��o B! Entre 1,20 e 1,70m de altura e at� 60kg.");
                }
            if(peso <= 90){
                printf("Voc� tem a classifica��o E! Entre 1,20 e 1,70m de altura e de 60 a 90kg.");
            }else{
                printf("Voc� tem a classifica��o H! Entre 1,20 e 1,70m de altura e mais de 90kg.");
            }
        }else{ //da a resposta pra quem tem mais de 1,70
            if(peso < 60){
                printf("Voc� tem a classifica��o C! Maior que 1,70m de altura e at� 60kg.");
                }
            if(peso <= 90){
                printf("Voc� tem a classifica��o F! Maior que 1,70m de altura e de 60 a 90kg.");
            }else{
                printf("Voc� tem a classifica��o I! Maior que 1,70m de altura e mais de 90kg.");
            }
        }
    }
}
#endif // ex9

/*10. Fa�a um algoritmo que receba o a idade, o sexo (1 para masculino e 2 para feminino) e sal�rio fixo de um funcion�rio.
Mostre o sexo, a idade e o sal�rio obtido ap�s o acr�scimo do abono:
Sexo           | Idade     | Abono          |
1- Masculino   | >= 30     | 200,00         |
_______________| <  30     | 120,00         |
2- Feminino    | >= 30     | 220,00         |
_______________| <  30     | 130,00         |                                     */

#ifdef ex10
int main()
{
    setlocale(LC_ALL, "portuguese"); //fun��o que permite pontua��o
    int idade, sexo; //vari�veis de idade e sexo
    float salf; //vari�vel de s�lario fixo
    printf("Digite as informa��es pedidas para saber seu sal�rio ap�s o acr�scimo do abono\n");
    do{
    printf("Digite sua idade: ");
    scanf("%i", &idade);
    if(idade < 16){
        printf("Escreva uma idade v�lida! (maior que 16)\n");
    }
    }while(idade < 16); //pede a idade de novo caso seja menor que 16
    do{
    printf("Digite seu sexo (1 = homem ou 2 = mulher): ");
    scanf("%i", &sexo);
    if(sexo != 1 && sexo != 2){
        printf("Escreva um sexo v�lido! (1 = homem ou 2 = mulher)\n");
    }
    }while(sexo != 1 && sexo != 2); //pede o sexo de novo caso seja diferente de 1 ou 2
    do{
    printf("Digite seu sal�rio fixo: ");
    scanf("%f", &salf);
    if(salf < 988){
        printf("Escreva um sal�rio fixo v�lido! (acima de R$988)\n");
    }
    }while(salf < 988); //pede o s�lario fixo de novo caso seja menor que R$ 988
    if(idade >= 30){ //if para pessoas acima de 30 anos
        if(sexo = 1){
        printf("Voc� tem %i anos e � do sexo masculino. Seu sal�rio com abono ser� de %f", idade, salf + 200);
        }else{
        printf("Voc� tem %i anos e � do sexo feminino. Seu sal�rio com abono ser� de %f", idade, salf + 220);
        }
    }else{ //else para pessoas abaixo de 30 anos
        if(sexo = 1){
        printf("Voc� tem %i anos e � do sexo masculino. Seu sal�rio com abono ser� de %f", idade, salf + 120);
        }else{
        printf("Voc� tem %i anos e � do sexo feminino. Seu sal�rio com abono ser� de %f", idade, salf + 130);
        }
    }
    return 0;
}
#endif
