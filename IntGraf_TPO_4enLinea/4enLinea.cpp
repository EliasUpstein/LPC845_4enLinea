#include "4enLinea.h"
#include "ui_4enLinea.h"

#define CANTIDAD_COLORES 4  //la cantidad de colores real es 1 más, pero se empieza contando desde el 0

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Comienzo_Juego_clicked()
{
    ui->Color->hide();
    ui->Movimiento->show();
    ui->Contador->show();
}


void MainWindow::begin()
{
    ui->Movimiento->hide();
    ui->Contador->hide();
}

void MainWindow::on_Rein_Cont_clicked()
{
    ui->Cont_Jug_1->display(0);
    ui->Cont_Jug_2->display(0);
}

void MainWindow::on_Colores_Jug_1_textActivated(const QString &arg1)
{
    if(arg1==ui->Colores_Jug_2->currentText()){
        if(ui->Colores_Jug_2->currentIndex() == CANTIDAD_COLORES)
            ui->Colores_Jug_2->setCurrentIndex(ui->Colores_Jug_1->currentIndex() - CANTIDAD_COLORES);
        else
            ui->Colores_Jug_2->setCurrentIndex(ui->Colores_Jug_2->currentIndex() + 1);
    }
}

void MainWindow::on_Colores_Jug_2_textActivated(const QString &arg2)
{
    if(arg2==ui->Colores_Jug_1->currentText()){
        if(ui->Colores_Jug_1->currentIndex() == CANTIDAD_COLORES)
            ui->Colores_Jug_1->setCurrentIndex(ui->Colores_Jug_1->currentIndex() - CANTIDAD_COLORES);
        else
            ui->Colores_Jug_1->setCurrentIndex(ui->Colores_Jug_1->currentIndex() + 1);
    }
}


void MainWindow::on_Mov_Der_clicked()
{

}

void MainWindow::on_Mov_Izq_clicked()   //agregar la comunicacion serie con el LPC para poder jugar
{

}

void MainWindow::on_Conf_Pos_clicked()
{

}

