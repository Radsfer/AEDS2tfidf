#ifndef CODIGO_HPP
#define CODIGO_HPP
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
using namespace std;

void tratarTexto(string& texto);
void removerStopWord(string& texto);
void abrirArq(string titulo1, list<string>& lista1);
void imprimirLista(list<string> lista1);

#endif // CODIGO_HPP