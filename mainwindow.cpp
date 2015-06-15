#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractAnimation>
#include <QItemSelectionModel>
#include <QStandardItem>
#include <QLabel>



QStandardItemModel *model2 = new QStandardItemModel();


void MainWindow::criarListaPresenca(){
    QStringList headers;
    headers << tr("Matricula") << tr("Nome") << tr("Presença") << tr("Data");
    model2->setHorizontalHeaderLabels(headers);
    QList<QStandardItem *> listaItem;
    // caminho e nome do arquivo
    QFile arquivo("/home/anderson/ProjetosQT/Mangabinha/listaAlunos");
    // variáveis que guardarão o conteúdo e a linha atual do arquivo
    QString conteudo, linha;
    // o arquivo foi aberto com sucesso?
    if(arquivo.open(QFile::ReadOnly)){
            // vamos criar uma nova instância da classe QTextStream
            QTextStream entrada(&arquivo);
            // vamos ler do arquivo uma linha de cada ver
            //Matricula do aluno
           QString matricula = entrada.readLine();
                               listaItem << new QStandardItem("matricula");
            // Nome do Aluno
            QString nome = entrada.readLine();
                    listaItem << new QStandardItem(nome);
            //Numero do Data -- Pegar do Sistema
            QString data = entrada.readLine();
                    listaItem << new QStandardItem(data);
            //Numero do Presença -- 1 falta/2 falta/Presente
            QString presenca = entrada.readLine();
                    listaItem << new QStandardItem(presenca);
                               model2->appendRow(listaItem);
    }else{

    }


           model2->appendRow(listaItem);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Interface = new Servidor();
    connect(Interface,SIGNAL(updateInterface(QString,QString,QString,QString)),SLOT(updateInterfaceProfessor(QString,QString,QString,QString)));

    Interface->criarSocket();
    Interface->esperarConexao();
    Interface->start();



    criarListaPresenca();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterfaceProfessor(QString nome, QString matricula, QString maccartao,QString imagem)
{
    cout<<nome.toStdString()<<"\n";
    cout<<matricula.toStdString()<<"\n";
    cout<<maccartao.toStdString()<<"\n";
    cout<<imagem.toStdString()<<"\n";

}
