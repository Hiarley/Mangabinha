#include "servidor.h"
#include "cartao.h"

Servidor::Servidor()
{

}

Servidor::~Servidor()
{

}

void Servidor::run()
{

    while (true)
    {

      //Verificando erros
      if ( conexaoClienteId == -1)
      {
        perror("Error accept");
        exit(1);
      }


      //Recebendo dados do cliente

      if ( bytesLidos = recv(conexaoClienteId, &rfid, sizeof(Cartao), 0) < 0 )
      {
        perror ("Error recv\n");
        exit(1);
      }


      emit updateInterface(rfid.getNome(),rfid.getMatricula(),rfid.getMacCartao(),rfid.getImagen());
      msleep(100);
    }
}

bool Servidor::criarSocket()
{

    //Criando o socket (internet, TCP, IP)
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    //Verificar erros
    if (socketId == -1)
    {
       perror("Error socket()\n");
       exit(1);
    }
     //tipo do protocolo
    endereco.sin_family = AF_INET;
    //porta
    endereco.sin_port = htons(4325);
    //o endereco será qualquer interface de rede do computador
    endereco.sin_addr.s_addr = inet_addr("127.0.0.1");
    //inserir zeros
    bzero( &( endereco.sin_zero ), 8);

    //Ligando o socket a uma porta do servidor
    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
    {
       perror("Error bind()\n");
       exit(1);
    }

    //Habilitando o servidor a receber conexoes do cliente
    if ( listen( socketId, 4 ) == -1)
    {
       perror("Error listen()\n");
       exit(1);
    }

}

void Servidor::esperarConexao()
{
    printf("Servidor: esperando conexões clientes\n");
    //Fica bloqueado esperando uma conexão do cliente
    conexaoClienteId = accept( socketId,
                               (struct sockaddr *) &enderecoCliente,
                               &enderecoClienteTam );
    printf("Servidor: recebeu conexão de %s, Descritor: %d\n",
                                                      inet_ntoa( enderecoCliente.sin_addr ),
                                                      conexaoClienteId);
}

