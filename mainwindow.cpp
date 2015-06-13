#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractAnimation>
#include <QItemSelectionModel>
#include <QStandardItem>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    Interface = new Servidor();
//    connect(Interface,SIGNAL(updateInterface(Cartao)),SLOT(updateInterfaceProfessor(Cartao));

QStandardItemModel *model = new QStandardItemModel();
model->clear();
   QList<QLabel *> listaItem;

    QLabel *label;
     QPixmap pixmap("/home/anderson/Imagens/Seleção_014.png");
    label->setPixmap(pixmap);
    label->setVisible(true);
    listaItem<<label;

     // Previously declared as QStringListModel *strListM1
    //model->appendRow(listaItem);
    ui->listView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterfaceProfessor(Cartao)
{

}
