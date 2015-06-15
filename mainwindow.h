#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cartao.h"
#include "servidor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
         void criarListaPresenca();
    ~MainWindow();

public slots:
    void updateInterfaceProfessor(Cartao);
private:
    Ui::MainWindow *ui;

    //servidor, interface do programa
    Servidor *Interface;
};

#endif // MAINWINDOW_H
