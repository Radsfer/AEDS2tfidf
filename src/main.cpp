#include "Codigo.hpp"
#include "Palavra.hpp"
using namespace std;

int main() {

  clock_t inicio = clock();

  set<string> stopwords;
  vector<string> titulos = {
      "datasets/A mão e a luva.txt",       "datasets/biblia.txt",
      "datasets/DomCasmurro.txt",          "datasets/quincas borba.txt",
      "datasets/Semana_Machado_Assis.txt", "datasets/terremoto.txt"};
  SalvarStopWords(stopwords);
  vector<list<Palavra>> listas(titulos.size(), list<Palavra>());

  int qtd_listas = titulos.size();
  for (int i = 0; i < qtd_listas; i++) {
    abrirArq(titulos[i], listas[i], stopwords);
  }

  clock_t fim = clock();

  cout << "Tempo de execução = " << (fim - inicio)/CLOCKS_PER_SEC << " segundos.\n" << endl;

  char CondicaodeParada;

  do {
    cout << "Digite a sentença buscada. " << endl;
    string entrada;
    cout << "Frase desejada: " << entrada << endl;
    getline(cin, entrada);
    cout << "-----------------" << endl;
    TF_IDF(listas, entrada, stopwords);
    cout << "-----------------" << endl;
    cout << "\n Deseja buscar outra sentença? (S/N)." << endl;
    cin >> CondicaodeParada;
    cin.ignore();
  } while (CondicaodeParada == 's' || CondicaodeParada == 'S');

  return 0;
}
