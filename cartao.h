#ifndef CARTAO_H
#define CARTAO_H
#include <iostream>
#include <string>
using namespace std;

class Cartao
{
public:
    Cartao();
    ~Cartao();
    char* getMacCartao();
    char* getNome();
    char* getMatricula();
    char* getImagen();
    bool getPresente();
    void setMacCartao(string mac);
    void setNome(string  name);
    void setMatricula(string alunomatricula);
    void setImagem(string imagemaluno);
    void setPresente(bool status);
private:
    char macCartao[100];
    char nome[100];
    char matricula[100];
    char imagem[100];
    bool presente;

};

#endif // CARTAO_H
