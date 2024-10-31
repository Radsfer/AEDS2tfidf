<p align="center"> 
  <img src="assets/image.png" alt="CEFET-MG" width="100px" height="100px">
</p>


<h1 align="center" font-size="200em"><b>Ranqueamento de Documentos | TF-IDF</b></h1>


<div align="center">

![Ubuntu](https://img.shields.io/badge/ubuntu-orange?style=for-the-badge&logo=ubuntu&logoColor=white)
![Static Badge](https://img.shields.io/badge/makefile-orangered?style=for-the-badge&logoColor=white)
![VS Code](https://img.shields.io/badge/vs%20code-royalblue?style=for-the-badge&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white)


</div>

<br>

## Introdução

### Sobre o trabalho:
<p align="justify">
O TF-IDF (<i>Term Frequency-Inverse Document Frequency</i>) é uma medida estatística e um algoritmo dentro da ciência de dados, usado para determinar a importância da palavra de um documento em relação a um banco de documentos. Isso, então, pode ser usado para ranquear os documentos com base no grau de relevância deles em relação à palavra/frase selecionada.
</p>

<p align="justify">
Portanto, implementamos um algoritmo de ranqueamento de documentos em C++ usando o TF-IDF como o primeiro trabalho da disciplina de AEDS II, ministrada no Campus Divinópolis do CEFET-MG pelo professor Michel Pires Da Silva.
</p>

<br>

## Implementação:

### Bibliotecas utilizadas:
- `<cctype>` : Inclui o cabeçalho da biblioteca de C <ctype.h> e adiciona os nomes associados ao namespace std;
- `<fstream>` : Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em arquivos externos.
- `<iostream>` : Declara objetos que controlam a leitura e a gravação nos fluxos padrão.
- `<list>` : Para a manipulação de dados utilizando a estrutura de lista bidirecionais;
- `<string>` : Para manipulação de strings;
- `<algorithm>` : Define as funções de modelo do contêiner da Biblioteca Padrão do C++ que executam algoritmos.
- `<cmath>` : Inclusão de funções matemáticas, tais como seno, cosseno, logarítmo; etc;
- `<codevct>` : Biblioteca utilizada para conversão dos dados de caracteres para UTF.
- `<locale>` : Para indicar para a máquina que algumas bibliotecas devem funcionar pensando na lingua portuguesa.
- `<set>` : Para armazenar e recuperar dados de uma coleção;
- `<sstream>` : Para operar em strings como fluxo de dados;
- `<unordered_map>` : Para criar e manipular tabelas hash de modo eficiente;
- `<vector>` : Para armazenar sequências dinâmicas de elementos.

### Funções:

- ```void tratarTexto(string &texto)```
- ```set<string> tratarFrase(string &frase, const set<string> stopwords) ```
- ```void RemoverStopWord(string &texto, const set<string> &stopwords)```
- ```void abrirArq(string titulo1, list<Palavra> &lista1, const set<string> stopwords)```
- ```void ImprimirLIsta(list<Palavra> &lista1)```
- ```void SalvarStopWords(set<string> &stopwords)```
- ```void TF_IDF(vextor<list<Palavra>> &listas, string entrada, const set<string> stopwords)```
  
## Compilação e Execução:

| Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build.                                       |
  |  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.          |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação.                                |


<br>

## Integrantes:

**Jader Oliveira Silva**  
[![Static Badge](https://img.shields.io/badge/%7C%200livas-black?style=flat-square&logo=github)](https://github.com/0livas)
[![Static Badge](https://img.shields.io/badge/%7C%20jaderoliveira28%40gmail.com%20%20-black?style=flat-square&logo=gmail)](mailto:jaderoliveira28@gmail.com)

**Rafael Adolfo Silva Ferreira**  
[![Static Badge](https://img.shields.io/badge/%7C%20Radsfer-black?style=flat-square&logo=github)](https://github.com/Radsfer)
[![Static Badge](https://img.shields.io/badge/%7C%20rafael.ferreira11.98%40gmail.com%20-black?style=flat-square&logo=gmail)](mailto:rafael.ferreira11.98@gmail.com )

**Samuel Silva Gomes**  
[![Static Badge](https://img.shields.io/badge/%7C%20samuelsilvg-black?style=flat-square&logo=github)](https://github.com/samuelsilvg)
[![Static Badge](https://img.shields.io/badge/%7C%20silvagomes881%40gmail.com%20-black?style=flat-square&logo=gmail)](mailto:silvagomes881@gmail.com)
