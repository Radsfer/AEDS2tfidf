#ifndef PALAVRA_HPP
#define PALAVRA_HPP

#include <string>
#include <iostream>
using namespace std;

class Palavra {
    private:
        string termo;
        int frequencia;

    public:
    Palavra(string Termo, int Frequencia);
    string getTermo();
    int getFrequencia();
    void setTermo(string termo);
    void setFrequencia(int frequencia);

};

#endif