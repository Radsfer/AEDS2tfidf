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

## Objetivos:

<p aligh='justify'>
Este trabalho inicial tem por objetivo reforçar os conhecimentos adquiridos na primeira parte desta disciplina que é dividida em duas. Desta forma, trabalharemos com conceitos como anaĺise assintótica, utilização de Tabelas Hash, Filas, Listas ou Pilhas e demais estruturas uteis que foram aprendidas anterioremente. 

Além disso, conforme desenvolve-se o código, podemos ter uma ideia inicial de estruturas mais complexas que trabalharemos daqui em diante, como árvores, por exemplo, e outros tipos de implementações mais elegantes que poderiam ajudar no desenvolvimento do problema. Sendo assim, o objetivo último deste trabalho é agir como um introdutório a essas estruturas e um reforço aos conhecimentos adquiridos até o momento.
</p>


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
- ```void ImprimirLista(list<Palavra> &lista1)```
- ```void SalvarStopWords(set<string> &stopwords)```
- ```void TF_IDF(vector<list<Palavra>> &listas, string entrada, const set<string> stopwords)```


## Resolução do Problema:

<p aligh='justify'>
Esse tipo de problema tem, na concepção do grupo, dois problemas principais, são eles: a grande massa de dados, uma vez que estamos lidando com documentos que, no total, possuem mais de 50 mil linhas, cada uma com uma média minima de 10 à 15 palavras, e o tratamento desse texto. Quando fala-se do tratamento do texto estamos nos referindo ao todo, neste caso o tratamento de stopwords, de acentos e a alocação de todo esse conteúdo no computador de modo que ele possa ser acessado posteriormente de forma rápida.

Sendo assim, ao desenvolver o programa um dos primeiros problemas que encontramos foi na organização do armazenamento das palavras. A ideia inicial era fazer uma Lista enorme que conteria todas as palavras dos textos, mas como é fácil imaginar, essa não é uma solução muito boa. Como na disciplina de AEDS é sempre levada com o pensamento de custo, velocidade e eficiência, é ineficiente fazer o armazenamento da forma como planejamos no início. Sendo assim, recorremos aos conhecimentos desenvolvidos na materia de POO, aproveitando que o C++ - linguagem utilizada no desenvolvimento deste código - é uma linguagem voltada a manipulação de objetos.

Dessa forma criou-se a classe "Palavra", esta classe contém uma string onde é armazenada a palavra propriamente dita e um inteiro chamado frequência. Como o nome diz, neste inteiro é armazenada a quantidade de vezes que uma palavra apareceu dentro de seu texto respectivo. Dessa forma passamos a utilizar a estrutura Lista de forma mais eficiente e melhor planejada, decisão que ajudaria futuramente a calcular o valor TF-IDF mais facilmente.

Além da implementação de uma classe, outra decisão tomada foi utilizar a biblioteca <set>, que é uma das bibliotecas Standard de C++. Basicamente essa biblioteca armazena dados utilizando o conceito de árvores, como a rubro negra e a AVL, por exemplo. Utilizamos isso para armazenar as strings de StopWords, que, como estavam alocadas em àrvores balanceadas, mantiveram um custo de pesquisa interno de (log n), ou seja, uma pesquisa rápida e eficiente. Essa decisão foi bem acertada e permitiu que o tratamento dos documentos de texto fosse feita de forma símples e didática para uma pessoa externa que olhe o código.

Outra decisão de implementação foi o uso da biblioteca <locale> em união da <codevct>, basicamente para o tratamento de todas as palavras para minúsculas. Isso é importante ressaltar pois há casos em que a a função "tolower()" é incapaz de lidar com acentos específicos de um idioma, tal como o o cedilha (ç), e isso pode levar a problemas futuros no cáluclo do TF-IDF, pois palavras como conheço e CONHEÇO, seriam armazenadas como palavras distintas porque a função tolower(), ao menos no Ubunto, converte "CONHEÇO" para "conheÇo", ou seja, um problema óbvio que pode desviar os dados do TF-IDF posteriormente.

Agora, antes de falar da implementação do TF-IDF, basta dizer que também foram criadas "codigo.hpp" e "codigo.cpp". São nessas pastas onde as funções mais importantes estão presentes, bem como a declaração de todas as bibliotecas. A maioria das funções estão comentadas e seus nomes são significativos, ou seja, a função "removerStopWord", por exemplo, faz exatamente o que seu nome diz. Isso foi feito apenas para fins de organização e boas práticas de programação.

Por fim, a implementação do TF-IDF. Neste código a função TF-IDF basicamente utiliza outras funções que fazem os devidos tratamentos e só no fim faz o cálculo de fato. A função recebe como entrada um Vector de Listas, essas listas são de objetos da classe Palavra. Além disso a função também recebe a string de entrada, ou seja, a string que o usuário fornece e, por fim, o set com as stopwords. 

Após isso a função chama o tratamento de frases, que é feito na frase de entrada fornecida pelo usuário. Após isso entra-se no cálculo do IDF que é feito com cada termo da entrada fornecida pelo usuário após o tratamento da mesma. O algorítmo também confere se cada termo aparece em cada documento. Por fim o logarítmo é aplicado para calcular o IDF de fato.

Depois de calcular o IDF é feito o TF-IDF, novamente para cada documento com base na entrada fornecida pelo usuário. É de se imaginar que esse foi o processo mais custoso de todo o programa, uma vez que é necessário calcular os valores para cada palavra de entrada em cada um dos documentos que estamos utilizando. Após cada cálculo de documento o valor é salvo em uma lista de relevância, que ao fim é ordenada de ordem decrescente e, por fim, impressa no terminal.
</p>

## Custos Computacionais:
  
<p aligh='justify'>
  
  A função ``tratarTexto`` possui custo computacional de O(n), onde n é a quantidade de caracteres na string texto que passara pela função tolower().
  
  A função``tratarFrase`` possui custo computacional de O(m * log x), onde m é o número de palvras na /frase e x é o custo associado ao uso da biblioteca <set>, que cria uma àrvore balanceada. Em àrvores deste modelo o custo de caminhamento é log k, onde k é a quantidade de elementos nessa àrvore.

  A função ``removerStopWords``, como citado anteriormente, possui custo de O(log k), onde k é o número de nós da àrvore.

  A função ``abrirArq`` abre o arquivo e lê as palavras no texto. Sendo assim seu custo é o produto da quantidade de linhas no texto pela quantidade de palavras. Além disso essa função também adiciona as palavras achadas à uma lista, sendo assim o custo também deve ser múltiplicado pela quantidade de termos desta lista, pois é necessário percorré-la todas as vezes para garantir que não há repetições. Dessa forma, o custo dessa função é O(l * p * n).

  A função ``ImprimirLista`` possui custo associado de O(n), uma vez que é apenas necessário percorrer os n elementos da lista e, então, printa-los no terminal.

  A função ``SalvarStopWords``possui custo associado de O(n), uma vez que é necessário percorrer todo o documento txt que possui as stopwords e, então armazená-las utilizando a biblioteca <set>, como dito anteriormente.
</p>


## Compilação e Execução:

 Especificações da máquina em que o código foi rodado:
  * Processador Intel Core i5, 10th Gen;
  * Sistema Operacional Windows 11 Home;
  * Terminal do WSL: Ubuntu 22.04.5;
  * 16GB de RAM.

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
