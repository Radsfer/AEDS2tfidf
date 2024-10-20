#include "Codigo.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list> 
using namespace std;


int main(){

    string titulo1 = "datasets/A mão e a luva.txt";
    string titulo2 = "datasets/biblia.txt";
    string titulo3 = "datasets/DomCasmurro.txt";
    string titulo4 = "datasets/quincas borba.txt";
    string titulo5 = "datasets/Semana_Machado_Assis.txt";
    string titulo6 = "datasets/terremoto.txt";

    list<string> lista1;
    // list<string> lista2;
    // list<string> lista3;
    // list<string> lista4;
    // list<string> lista5;
    // list<string> lista6;

    abrirArq(titulo1, lista1);
    imprimirLista(lista1);

    // abirArq(titulo2); 
    // abirArq(titulo3); 
    // abirArq(titulo4); 
    // abirArq(titulo5); 
    // abirArq(titulo6);

    return 0;
}