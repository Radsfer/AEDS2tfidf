#include "Codigo.hpp"
#include "Palavra.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main() {

  set<string> stopwords;
  vector<string> titulos = {
      "datasets/A mão e a luva.txt",       "datasets/biblia.txt",
      "datasets/DomCasmurro.txt",          "datasets/quincas borba.txt",
      "datasets/Semana_Machado_Assis.txt", "datasets/terremoto.txt"};
  SalvarStopWords(stopwords);
  vector<list<Palavra>> listas(titulos.size(), list<Palavra>());
  string entrada = "o pavão voa para longe";
  // abrirArq("datasets/Teste.txt", listas.front(), stopwords);
  int qtd_listas = titulos.size();
  for (int i = 0; i < qtd_listas; i++) {
    abrirArq(titulos[i], listas[i], stopwords);
  }
  TF_IDF(listas, entrada, stopwords);
  return 0;
}
