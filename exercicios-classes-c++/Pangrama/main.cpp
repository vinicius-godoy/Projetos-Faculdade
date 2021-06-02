#include <iostream>
#include <vector>
#include <string>

using namespace std;
    
bool ePangrama(string& str); // Definição da função

int main()
{
    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);
    
    if(ePangrama(frase) == true){
        cout << "A frase digitada -> \"" << frase << "\" e um pangrama!" << endl;
    }else{
        cout << "A frase digitada -> \"" << frase << "\" NAO e um pangrama!" << endl;
    }

    return (0);
}

bool ePangrama(string& str){
    vector<bool> letras(26, false); // Vetor do tamanho do alfabeto composto de falses 
    int indice;

    for (int i = 0; i < str.length(); i++) { // Verifica se a iteração atual da string é uma letra e salva qual
        if('A' <= str[i] && str[i] <= 'Z'){
            indice = str[i] - 'A';
        }else if('a' <= str[i] && str[i] <= 'z'){
            indice = str[i] - 'a';
        }else{
            continue;
        }
    
        letras[indice] = true; // Se for uma letra marca ela como true no vetor
    }
    
    for (int i = 0; i <= 25; i++){
        if (letras[i] == false){ // Verifica o vetor inteiro, se um deles for false retorna false
            return (false);
        }
    } 

    return (true);
}