#ifndef CODIGO_HPP
#define CODIGO_HPP
#include "Palavra.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <list>
#include <locale>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void tratarTexto(string &texto);
void removerStopWord(string &texto, const set<string> &stopwords);
void abrirArq(string titulo1, list<Palavra> &lista1,
              const set<string> stopwords);
void imprimirLista(list<Palavra> &lista1);
void SalvarStopWords(set<string> &stopwords);
set<string> tratarFrase(string &frase, const set<string> stopwords);
void TF_IDF(vector<list<Palavra>> &listas, string entrada,
            set<string> stopwords);

#endif // CODIGO_HPP
