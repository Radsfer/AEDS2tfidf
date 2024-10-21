#include "Palavra.hpp"

using namespace std;

Palavra::Palavra(string Termo, int Frequencia){
    termo = Termo;
    frequencia = Frequencia;
}

string Palavra::getTermo(){
    return termo;
}

int Palavra::getFrequencia(){
    return frequencia;
}

void Palavra::setTermo(string Termo){
    termo = Termo;
}

void Palavra::setFrequencia(int Frequencia){
    frequencia = Frequencia;
}