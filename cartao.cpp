#include "cartao.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

Cartao::Cartao()
{

}

Cartao::~Cartao()
{

}

bool Cartao::getPresente()
{
    return presente;
}
char* Cartao::getMacCartao()
{
    return macCartao;
}
char* Cartao::getImagen()
{
    return imagem;
}

char* Cartao::getMatricula()
{
    return matricula;
}
char* Cartao::getNome()
{
    return nome;
}
void Cartao::setImagem(string  imagemaluno)
{
    strcpy(imagem, imagemaluno.c_str());
}
void Cartao::setMacCartao(string  mac)
{
    strcpy(macCartao,mac.c_str());

}
void Cartao::setMatricula(string  alunomatricula)
{
    strcpy(matricula, alunomatricula.c_str());
}
void Cartao::setNome(string  name)
{
    strcpy(nome,name.c_str());
}
void Cartao::setPresente(bool status)
{
    presente = status;
}
