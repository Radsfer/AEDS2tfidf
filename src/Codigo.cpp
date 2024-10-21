#include "Codigo.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
#include <locale>
#include <set>
using namespace std;

// não tem mais o problema de tratar maiúscula com acento.
void tratarTexto(string& texto){
    locale loc("pt_BR.UTF-8");
    string resultado;

    for (char& c: texto){
        if(!ispunct(c, loc)){
            resultado += tolower(c, loc);
        }
    }

    texto = resultado;
    return;
}



void removerStopWord(string& texto, const set<string>& stopwords){       //auto-explicativo
    if(stopwords.find(texto) != stopwords.end()){
        texto = "";
    }
    return;
}



void abrirArq(string titulo1, list<Palavra>& lista1, const set<string> stopwords){    //...
    ifstream file(titulo1);
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo.";
        return;
    }

    string texto;
    bool encontrado = false;

    while (file >> texto){
        tratarTexto(texto); // Literalmente trata o texto.
        removerStopWord(texto, stopwords); // agora aqui olha se é uma stopwords, se for vira "".

        if(texto != ""){
            for(auto& Palavra : lista1){
                if(Palavra.getTermo() == texto){ //Confere se a Palavra já existe na lista
                    Palavra.setFrequencia(Palavra.getFrequencia() + 1); // Se já existe, soma +1 à frequência.
                    encontrado = true;
                    break;
                }
            }
            if(!encontrado){ //Se a palavra não existe, adiciona uma instância dela à lista.
                lista1.emplace_back(texto, 1);
            }
        }
    }

    file.close();
    return;
}



void imprimirLista(list<Palavra>& lista1){
    for (Palavra&aux : lista1){
        cout << aux.getTermo() << " e " << aux.getFrequencia() << endl;
    }
}



void SalvarStopWords(set<string> &stopwords)
{ // como imaginei que tudo ia levar muito tempo, implementei o set. Basicamente uma árvore balanceada de uma biblioteca.

    ifstream file("datasets/stopwords.txt");
    if(!file.is_open()){
        cout << "Erro na leitura do arquivo de stopwords." << endl;
        return;
    }

    string palavras_parada;
    while (getline(file, palavras_parada)){
        stopwords.insert(palavras_parada);
    }
    file.close();
    return;
}