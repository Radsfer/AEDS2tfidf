#include "Codigo.hpp"
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

set<string> tratarFrase(string &frase, const set<string> stopwords) {
  stringstream ss(frase);
  set<string> entrada_tratada;
  string palavra;
  string frase_tratada;

  while (ss >> palavra) {
    tratarTexto(palavra); // Trata cada palavra individualmente
    removerStopWord(palavra, stopwords);
    if (palavra != "") {
      entrada_tratada.insert(palavra);
    }
  }
  return entrada_tratada;
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

// Função para calcular o TF-IDF
void TF_IDF(vector<list<Palavra>> &listas, string entrada,
            const set<string> stopwords) {
  // 1. Trata a entrada para obter as palavras relevantes
  set<string> entrada_tratada = tratarFrase(entrada, stopwords);

  // 2. Calcula o IDF para cada termo da entrada_tratada em todos os documentos
  unordered_map<string, double> idf;
  int total_docs = listas.size();

  for (const string &termo : entrada_tratada) {
    int doc_count = 0;

    // Conta em quantos documentos o termo aparece
    for (auto &lista : listas) {
      for (Palavra &palavra : lista) {

        if (palavra.getTermo() == termo) {
          doc_count++;
          break;
        }
      }
    }

    // Calcula o IDF usando logaritmo para o termo
    idf[termo] = log(static_cast<double>(total_docs) / (1 + doc_count));
  }

  // 3. Calcula o TF-IDF para cada documento com base nas palavras da entrada
  vector<pair<int, double>> relevancia_docs;
  int qtd_listas = listas.size();
  for (int i = 0; i < qtd_listas; ++i) {
    double relevancia_total = 0.0;

    // Calcula o TF-IDF de cada palavra da entrada no documento atual
    for (const string &termo : entrada_tratada) {
      for (Palavra &palavra : listas[i]) {
        if (palavra.getTermo() == termo) {
          double tf = palavra.getFrequencia();
          relevancia_total += tf * idf[termo];
          break;
        }
      }
    }

    // Adiciona o documento e sua relevância na lista de resultados
    relevancia_docs.emplace_back(i, relevancia_total);
  }

  // 4. Ordena os documentos por relevância em ordem decrescente
  sort(relevancia_docs.begin(), relevancia_docs.end(),
       [](const pair<int, double> &a, const pair<int, double> &b) {
         return a.second > b.second;
       });

  // 5. Imprime os documentos em ordem de relevância
  for (const auto &doc : relevancia_docs) {
    cout << "Documento " << doc.first << " - Relevância: " << doc.second
         << endl;
  }
}
