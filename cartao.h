#ifndef CARTAO_H
#define CARTAO_H
#include <iostream>
using namespace std;

class Cartao
{
public:
    Cartao();
    ~Cartao();
    string getMacCartao();
    string getNome();
    string getMatricula();
    string getImagen();
    bool getPresente();
    void setMacCartao(string mac);
    void setNome(string name);
    void setMatricula(string alunomatricula);
    void setImagem(string imagemaluno);
    void setPresente(bool status);
private:
    string macCartao;
    string nome;
    string matricula;
    string imagem;
    bool presente;

};

#endif // CARTAO_H
