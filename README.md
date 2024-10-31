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

## Implementação

### Bibliotecas utilizadas:
- `<cctype>` : Inclui o cabeçalho da biblioteca de C <ctype.h> e adiciona os nomes associados ao namespace std;
- `<fstream>` : Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em arquivos externos.
- `<iostream>` : Declara objetos que controlam a leitura e a gravação nos fluxos padrão.
- `<list>` : Para a manipulação de dados utilizando a estrutura de lista bidirecionais;
- `<string>` : Para manipulação de strings;
- `<algorithm>` : Define as funções de modelo do contêiner da Biblioteca Padrão do C++ que executam algoritmos.
- `<cmath>` : Inclusão de funções matemáticas, tais como seno, cosseno, logarítmo; etc;
& - `<codevct>` :
- `<locale>` : Para indicar para a máquina que algumas bibliotecas devem funcionar pensando na lingua portuguesa.
- `<set>` : Para armazenar e recuperar dados de uma coleção;
- `<sstream>` : Para operar em strings como fluxo de dados;
- `<unordered_map>` : Para criar e manipular tabelas hash de modo eficiente;
- `<vector>` : Para armazenar sequências dinâmicas de elementos.

## Estruturas de Dados Utilizadas

### 1 | Leitura dos documentos:
***Principal Estrutura:*** Lista de objetos.

Para ler os documentos e separar suas palavras apropriadas das stopwords, utilizamos o paradigma de orientação de objetos para impementar um objeto chamado Palavra, que registra cada palavra válida do texto (chamada de *termo* na classe) e um valor inteiro que representa a quantidade de iterações da palavra por documento.

A partir disso, implementamos uma **lista** de objetos Palavra usando a biblioteca `<list>`. Essa foi uma decisão pensada não só na simplicidade de implementação com essa biblioteca, mas também pela falta de especificidade para inserir e remover elementos, coisa que, nesse trabalho, indica menos complicações para se lidar com os dados coletados do que se o mesmo fosse feito usando, por exemplo, uma pilha ou uma fila.

### 2 | Cálculo do TF-IDF:
***Principal Estrutura:*** Tabela Hash.

Após salvar os termos individualmente e suas iterações por documento, calcular o TF-IDF se torna prático e foi feito nesse trabalho através do uso de uma **tabela hash**, implementada usando a biblioteca `<unordored_map>`. Através dela, foi possível atribuir valores e chaves aos termos válidos extraídos e quantas vezes eles aparecem. O principal motivo para o uso dessa estrutura é a velocidade no armazenamento e acesso de informações, o que torna muito mais viável e eficiente o cálculo do TF-IDF. 

### 3 | Ranqueamento de documentos:
***Principal Estrutura:*** Lista 

Assim como na leitura dos documentos, uma **lista** foi implementada usando a biblioteca `<list>`. Isso foi feito dentro da função TF-IDF também por conta da praticidade de se usar a biblioteca e armazenar múltiplas informações de um mesmo elemento (no caso, um documento e sua relevância na lista de resultados), além de forncer ferramentas para tornar ainda mais simples as ordenações de documentos por ordem de relevância.

Por mais que filas e pilhas pudessem ser implementadas, o uso da lista como uma generalização pareceu mais apropriada para essa aplicação e para o acesso de dados que decidimos utilizar. Também não é um cenário em que a implementação de uma tabela hash pareceu fornecer ganhos tão significativos.

## Estruturação do Código

### assets:
- `logo.png`: A logo da instituição, usada nesse README.

### datasets:
#### Documentos:
- `A mão e a luva.txt`: dataset em texto do livro de mesmo nome, escrito por Machado de Assis.
- `biblia.txt`: dataset em texto da Bíblia Sagrada.
- `DomCasmurro.txt`: dataset em texto do livro de mesmo nome, escrito por Machado de Assis.
- `quincas borba`: dataset em texto do livro de mesmo nome, escrito por Machado de Assis.
- `Semana_Machado_Assis.txt`: dataset em texto do livro *A Semana*, escrito por Machado de Assis.
- `terremoto.txt`: dataset em texto do documento *Relação do formidavel, e lastimoso terremoto succedido no Reino de Valença*, disponível em domínio público.
#### Outros:
- `stopwords.txt`: arquivo de texto com todas as stopwords usadas para tratamento de texto.

### src
- `main.cpp`: arquivo com a principal rotina do código.
- `Codigo.cpp`: arquivo com as principais funções do código.
- `Codigo.hpp`: : arquivo de cabeçalho das principais funções do código.
- `Palavra.cpp`: arquivo com os métodos da classe Palavra.
- `Palavra.hpp`: arquivo de cabeçalho da classe Palavra.


## Compilação e Execução

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
