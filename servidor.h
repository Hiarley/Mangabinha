#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "dtrem.h"
#include <QThread>
#include <QtCore>

#include <QtCore>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> //bzero
//Bibliotecas socket
#include <sys/types.h>  //AF_INET
#include <sys/socket.h> //socket
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_ntoa
#include <unistd.h>  //close

#include <iostream>
using namespace std;


class Servidor: public QThread
{
    Q_OBJECT
public:

    Servidor();
    bool Enviar();
    void esperarConexao();
    bool criarSocket();//primeira função a ser chamada
    void run();
    ~Servidor();

signals:
    void updatetrem(int,int);
    void updatecontrole(int);
private:

    //Identificador do socket
    int socketId;

    //Struct de endereco
    struct sockaddr_in endereco;

    //Variaveis auxiliares para obter informações das conexões

    //Identificador de uma conexao cliente
    int conexaoClienteId;

    //Bytes lidos do cliente
    int bytesLidos;

    //Endereço de uma conexão cliente
    struct sockaddr_in enderecoCliente;

    //Tamanho do endereço do cliente
    socklen_t enderecoClienteTam;

};

#endif // SERVIDOR_H
