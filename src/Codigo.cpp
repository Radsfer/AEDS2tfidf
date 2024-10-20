#include "Codigo.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
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

void abrirArq(string titulo1, list<string>& lista1){
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