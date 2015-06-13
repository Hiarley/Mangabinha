#include "cartao.h"

Cartao::Cartao()
{

}

Cartao::~Cartao()
{

}

string Cartao::getMacCartao()
{
    return macCartao;
}
string Cartao::getImagen()
{
    return imagem;
}

string Cartao::getMatricula()
{
    return matricula;
}
string Cartao::getNome()
{
    return nome;
}
void Cartao::setImagem(string imagemaluno)
{
    imagem = imagemaluno;
}
void Cartao::setMacCartao(string mac)
{
    macCartao = mac;
}
void Cartao::setMatricula(string alunomatricula)
{
    matricula = alunomatricula;
}
void Cartao::setNome(string name)
{
    nome = name;
}
