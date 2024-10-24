#include "Codigo.hpp"
#include <cctype>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <list>
#include <locale>
#include <set>
#include <sstream>
#include <string>
using namespace std;

// não tem mais o problema de tratar maiúscula com acento.
void tratarTexto(string &texto) {
  wstring_convert<codecvt_utf8<wchar_t>> converter;
  wstring texto_w = converter.from_bytes(texto);
  locale loc("pt_BR.UTF-8");

  wstring resultado;

  for (wchar_t c : texto_w) {
    resultado += tolower(c, loc);
  }
  texto = converter.to_bytes(resultado);
  return;
}

void removerStopWord(string &texto,
                     const set<string> &stopwords) { // auto-explicativo
  if (stopwords.find(texto) != stopwords.end()) {
    texto = "";
  }
  return;
}

void abrirArq(string titulo1, list<Palavra> &lista1,
              const set<string> stopwords) {
  ifstream file(titulo1);
  if (!file.is_open()) {
    cout << "Erro na leitura do arquivo.";
    return;
  }

  string linha;
  bool encontrado;

  while (getline(file, linha)) { // Lê linha por linha
    istringstream iss(linha);
    string texto;

    while (iss >> texto) {               // Lê cada palavra da linha
      tratarTexto(texto);                // Trata o texto.
      removerStopWord(texto, stopwords); // Remove stopwords.

      if (texto != "") {
        encontrado = false;
        for (auto &Palavra : lista1) {
          if (Palavra.getTermo() ==
              texto) { // Confere se a palavra já existe na lista
            Palavra.setFrequencia(Palavra.getFrequencia() +
                                  1); // Atualiza a frequência.
            encontrado = true;
            break;
          }
        }
        if (!encontrado) { // Se a palavra não existe, adiciona uma nova entrada
          lista1.emplace_back(texto, 1);
        }
      }
    }
  }

  file.close();
}

void imprimirLista(list<Palavra> &lista1) {
  for (Palavra &aux : lista1) {
    cout << aux.getTermo() << " e " << aux.getFrequencia() << endl;
  }
}

void SalvarStopWords(
    set<string> &stopwords) { // como imaginei que tudo ia levar muito tempo,
                              // implementei o set. Basicamente uma árvore
                              // balanceada de uma biblioteca.

  ifstream file("datasets/stopwords.txt");
  if (!file.is_open()) {
    cout << "Erro na leitura do arquivo de stopwords." << endl;
    return;
  }

  string palavras_parada;
  while (getline(file, palavras_parada)) {
    stopwords.insert(palavras_parada);
  }
  file.close();
  return;
}

void TF_IDF(vector<list<Palavra>> &listas, string entrada,
            set<string> stopwords) {

  tratarTexto(entrada);
  removerStopWord(entrada, stopwords);
  cout << entrada << "Quantidade de documentos " << listas.size() << endl;
  return;
}
