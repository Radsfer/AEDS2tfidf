#ifndef CODIGO_HPP
#define CODIGO_HPP
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

// Início de uma implementação de lista encadeada.

struct no{
    string palavra;
    no *prox;
};

typedef struct{
   no *head;
   no *tail; 
} Lista;

#endif // CODIGO_HPP