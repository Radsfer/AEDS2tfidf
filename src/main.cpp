#include "Codigo.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list> // Implementei com list por teste.
using namespace std;



// Tem um problema pra tratar maiuscula com acento.
void tratarTexto(string& texto){
    string resultado;
    for (char& c: texto){
        if(!ispunct(c)){
            resultado += tolower(c);
        }
    }
    
    texto = resultado;
}

void removerStopWord(string& texto){
    ifstream file("datasets/stopwords.txt");
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    string stopword;

    while(getline(file, stopword)){
        if (texto == stopword){
            texto = "";
        }
    }

    file.close();
}

void abirArq(string titulo1, list<string>& lista1){
    ifstream file(titulo1);
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    string texto;

    while (file >> texto){
        tratarTexto(texto);
        removerStopWord(texto);

        if(texto != ""){
            lista1.push_back(texto); 
        }
    }

    

    file.close();
}

void imprimirLista(list<string> lista1){
    for (string palavra : lista1){
        cout << palavra << endl;
    }
}

int main(){

    string titulo1 = "datasets/A mão e a luva.txt";
    string titulo2 = "datasets/biblia.txt";
    string titulo3 = "datasets/DomCasmurro.txt";
    string titulo4 = "datasets/quincas borba.txt";
    string titulo5 = "datasets/Semana_Machado_Assis.txt";
    string titulo6 = "datasets/terremoto.txt";

    list<string> lista1;
    abirArq(titulo1, lista1);
    imprimirLista(lista1);

    // abirArq(titulo2); 
    // abirArq(titulo3); 
    // abirArq(titulo4); 
    // abirArq(titulo5); 
    // abirArq(titulo6);

    return 0;
}