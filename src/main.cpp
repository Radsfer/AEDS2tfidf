#include "Codigo.hpp"
#include "Palavra.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list> 
using namespace std;


int main(){

    set<string> stopwords;

    string titulo1 = "datasets/A mão e a luva.txt";
    string titulo2 = "datasets/biblia.txt";
    string titulo3 = "datasets/DomCasmurro.txt";
    string titulo4 = "datasets/quincas borba.txt";
    string titulo5 = "datasets/Semana_Machado_Assis.txt";
    string titulo6 = "datasets/terremoto.txt";

    list<Palavra> lista1;
    // list<string> lista2;
    // list<string> lista3;
    // list<string> lista4;
    // list<string> lista5;
    // list<string> lista6;
    SalvarStopWords(stopwords);
    abrirArq("datasets/Teste.txt", lista1, stopwords);
    imprimirLista(lista1);

    // abirArq(titulo2); 
    // abirArq(titulo3); 
    // abirArq(titulo4); 
    // abirArq(titulo5); 
    // abirArq(titulo6);

    return 0;
}