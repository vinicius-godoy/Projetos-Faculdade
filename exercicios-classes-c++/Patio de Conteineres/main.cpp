#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include "pilhasequencial.h"
#include "container.h"

using namespace std;

//Declara��o de Fun��es
void menu_empilhamento();
void menu_desempilhamento();
void menu_exibir();

//Vari�veis Globais
int const tamanho_patio = 10, max_quadra = 5; //Tamanho do p�tio e quantos containers cabem em cada quadra dele
Pilha<Container> *p[tamanho_patio]; //Array de ponteiros para pilhas de containers
Container container; //Vari�vel de Container para entrada e sa�da

int main()
{
    setlocale(LC_ALL, "portuguese");
    for (int i = 0; i < tamanho_patio; i++){ //Inicializa��o das quadras do p�tio
        p[i] = new Pilha<Container>(max_quadra); //Cria uma pilha de 5 containers pra cada ponteiro
    }
    int opc;

    do{
        cout << "=====|P�tio de Containers|=====" << endl;
        cout << "1 - Empilhar Container" << endl;
        cout << "2 - Desempilhar Container" << endl;
        cout << "3 - Exibir P�tio" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nSelecione sua Op��o -> ";
        cin >> opc;

        system("cls");
        switch(opc)
        {
        case 0:
            exit(0);
            break;
        case 1:
            menu_empilhamento();
            break;
        case 2:
            menu_desempilhamento();
            break;
        case 3:
            menu_exibir();
            break;
        default:
            cout << "\aEscolha uma op��o v�lida!";
            system("pause");
        }
        system("cls");

    }while(opc != 0);

    return 0;
}

void menu_empilhamento()
{
    int quadra;
    cout << "==============|P�tio de Containers|==============" << endl;
    cout << "Qual quadra voc� deseja empilhar esse container?" << endl;
    do{
    cin >> quadra;
    if(quadra > 10 || quadra < 1){cout << "\aEssa quadra n�o existe! Escolha uma entre 1 e 10 -> ";}
    }while(quadra > 10 || quadra < 1);

    if(p[quadra - 1]->pilhaCheia()){ //Quadra - 1 por que o array come�a em 0 e o n�mero das quadras em 1
        cout << "\aN�o � poss�vel empilhar em uma quadra cheia! ";
        system("pause");
    }else{
        cout << "=====|Informa��es do Container|=====" << endl;
        cout << "C�digo do Container: "; cin >> container.codigo;
        cout << "Dimens�o: "; cin >> container.dimensao;
        cout << "Peso: "; cin >> container.peso;

        p[quadra - 1]->empilha(container);

        cout << "Container empilhado com sucesso na quadra " << quadra << "! ";
        system("pause");
    }
}

void menu_desempilhamento()
{
    int quadra;
    cout << "==============|P�tio de Containers|==============" << endl;
    cout << "Qual quadra voc� deseja desempilhar um container?" << endl;
    do{
    cin >> quadra;
    if(quadra > 10 || quadra < 1){cout << "\aEssa quadra n�o existe! Escolha uma entre 1 e 10 -> ";}
    }while(quadra > 10 || quadra < 1);

    if(p[quadra - 1]->pilhaVazia()){
        cout << "\aN�o � poss�vel desempilhar de uma quadra vazia! ";
        system("pause");
    }else{
        container = p[quadra - 1]->desempilha();
        cout << "Informa��es do Container Desempilhado:" << endl;
        cout << "C�digo do Container: " << container.codigo << endl;
        cout << "Dimens�o do Container: " << container.dimensao << endl;
        cout << "Peso do Container: " << container.peso << endl;

        cout << endl << "Container desempilhado com sucesso da quadra " << quadra << "! ";
        system("pause");
    }
}

void menu_exibir()
{
    int quadras_vazias = 0;
    cout << "=====|P�tio de Containers|======" << endl;
    for(int i = 0; i < tamanho_patio; i++){
        if(p[i]->pilhaVazia()){
            quadras_vazias++;
        }else{
            cout << "==========|" << i + 1 << "� QUADRA|==========" << endl;
            for(int j = 0; j <= p[i]->getTopo(); j++){
                container = p[i]->getValor(j);
                cout << "+----------------------------+ " << endl;
                cout << "| C�digo do Container: " << setw(5) << container.codigo << setw(0) << " | " << endl;
                cout << "|     Dimens�o: " << container.dimensao << " p�s       |" << endl;
                cout << "|      Peso: " << setw(6) << fixed << setprecision(2) << container.peso << setw(0) << " ton      | " << endl;
                cout << "+----------------------------+ " << endl;
            }
        }
    }
    if(quadras_vazias == tamanho_patio){
        cout << endl << "Todas as quadras est�o vazias! ";
    }else if(quadras_vazias > 1){
        cout << "========|OUTRAS QUADRAS|========" << endl;
        cout << "Todas as outras " << quadras_vazias << " quadras est�o vazias! ";
    }else{
        cout << "=========|OUTRA QUADRA|=========" << endl;
        cout << "A outra quadra est� vazia! ";
    }
    system("pause");
}
