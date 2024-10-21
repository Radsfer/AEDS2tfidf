#ifndef CODIGO_HPP
#define CODIGO_HPP
#include "Palavra.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
#include <set>
using namespace std;

void tratarTexto(string& texto);
void removerStopWord(string& texto, const set<string>& stopwords);
void abrirArq(string titulo1, list<Palavra>& lista1, const set<string> stopwords);
void imprimirLista(list<Palavra>& lista1);
void SalvarStopWords(set<string>& stopwords);

#endif // CODIGO_HPP