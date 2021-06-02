#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clocale>
#include "pilhasequencial.h"
#include "container.h"

using namespace std;

//Declaração de Funções
void menu_empilhamento();
void menu_desempilhamento();
void menu_exibir();

//Variáveis Globais
int const tamanho_patio = 10, max_quadra = 5; //Tamanho do pátio e quantos containers cabem em cada quadra dele
Pilha<Container> *p[tamanho_patio]; //Array de ponteiros para pilhas de containers
Container container; //Variável de Container para entrada e saída

int main()
{
    setlocale(LC_ALL, "portuguese");
    for (int i = 0; i < tamanho_patio; i++){ //Inicialização das quadras do pátio
        p[i] = new Pilha<Container>(max_quadra); //Cria uma pilha de 5 containers pra cada ponteiro
    }
    int opc;

    do{
        cout << "=====|Pátio de Containers|=====" << endl;
        cout << "1 - Empilhar Container" << endl;
        cout << "2 - Desempilhar Container" << endl;
        cout << "3 - Exibir Pátio" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nSelecione sua Opção -> ";
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
            cout << "\aEscolha uma opção válida!";
            system("pause");
        }
        system("cls");

    }while(opc != 0);

    return 0;
}

void menu_empilhamento()
{
    int quadra;
    cout << "==============|Pátio de Containers|==============" << endl;
    cout << "Qual quadra você deseja empilhar esse container?" << endl;
    do{
    cin >> quadra;
    if(quadra > 10 || quadra < 1){cout << "\aEssa quadra não existe! Escolha uma entre 1 e 10 -> ";}
    }while(quadra > 10 || quadra < 1);

    if(p[quadra - 1]->pilhaCheia()){ //Quadra - 1 por que o array começa em 0 e o número das quadras em 1
        cout << "\aNão é possível empilhar em uma quadra cheia! ";
        system("pause");
    }else{
        cout << "=====|Informações do Container|=====" << endl;
        cout << "Código do Container: "; cin >> container.codigo;
        cout << "Dimensão: "; cin >> container.dimensao;
        cout << "Peso: "; cin >> container.peso;

        p[quadra - 1]->empilha(container);

        cout << "Container empilhado com sucesso na quadra " << quadra << "! ";
        system("pause");
    }
}

void menu_desempilhamento()
{
    int quadra;
    cout << "==============|Pátio de Containers|==============" << endl;
    cout << "Qual quadra você deseja desempilhar um container?" << endl;
    do{
    cin >> quadra;
    if(quadra > 10 || quadra < 1){cout << "\aEssa quadra não existe! Escolha uma entre 1 e 10 -> ";}
    }while(quadra > 10 || quadra < 1);

    if(p[quadra - 1]->pilhaVazia()){
        cout << "\aNão é possível desempilhar de uma quadra vazia! ";
        system("pause");
    }else{
        container = p[quadra - 1]->desempilha();
        cout << "Informações do Container Desempilhado:" << endl;
        cout << "Código do Container: " << container.codigo << endl;
        cout << "Dimensão do Container: " << container.dimensao << endl;
        cout << "Peso do Container: " << container.peso << endl;

        cout << endl << "Container desempilhado com sucesso da quadra " << quadra << "! ";
        system("pause");
    }
}

void menu_exibir()
{
    int quadras_vazias = 0;
    cout << "=====|Pátio de Containers|======" << endl;
    for(int i = 0; i < tamanho_patio; i++){
        if(p[i]->pilhaVazia()){
            quadras_vazias++;
        }else{
            cout << "==========|" << i + 1 << "º QUADRA|==========" << endl;
            for(int j = 0; j <= p[i]->getTopo(); j++){
                container = p[i]->getValor(j);
                cout << "+----------------------------+ " << endl;
                cout << "| Código do Container: " << setw(5) << container.codigo << setw(0) << " | " << endl;
                cout << "|     Dimensão: " << container.dimensao << " pés       |" << endl;
                cout << "|      Peso: " << setw(6) << fixed << setprecision(2) << container.peso << setw(0) << " ton      | " << endl;
                cout << "+----------------------------+ " << endl;
            }
        }
    }
    if(quadras_vazias == tamanho_patio){
        cout << endl << "Todas as quadras estão vazias! ";
    }else if(quadras_vazias > 1){
        cout << "========|OUTRAS QUADRAS|========" << endl;
        cout << "Todas as outras " << quadras_vazias << " quadras estão vazias! ";
    }else{
        cout << "=========|OUTRA QUADRA|=========" << endl;
        cout << "A outra quadra está vazia! ";
    }
    system("pause");
}
