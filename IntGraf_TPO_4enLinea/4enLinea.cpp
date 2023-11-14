#include "4enLinea.h"
#include "ui_4enLinea.h"

#define CANTIDAD_COLORES 4  //la cantidad de colores real es 1 más, pero se empieza contando desde el 0

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort();
    foreach(const QSerialPortInfo &serial_Info, QSerialPortInfo::availablePorts()){
        qDebug()<<"Puerto: "<<serial_Info.portName(); //debugueo la cantidad de puertos que tengo disponible
        portname = serial_Info.portName();
    }
    LPC_Init(); //inicializo la comunicación serie con el LPC
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LPC_Init()
{
    serial->setPortName(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial, SIGNAL(readyRead()), this, SLOT(serial_read()));
}

void MainWindow::on_Comienzo_Juego_clicked()
{
    if(serial->isWritable()){
        switch(ui->Colores_Jug_1->currentIndex()){
            case '0': //Index del color Rojo en el jugador 1
                serial->write("r"); //envio la r de RED
                break;
            case '1': //Index del color Azul en el jugador 1
                serial->write("b"); //envio la b de BLUE
                break;
            case '2': //Index del color Verde en el jugador 1
                serial->write("g"); //envio la g de GREEN
                break;
            case '3': //Index del color Amarillo en el jugador 1
                serial->write("y"); //envio la y de YELLOW
                break;
            case '4': //Index del color Rosa en el jugador 1
                serial->write("p"); //envio la p de PINK
                break;
            default:
                serial->write("e"); //envia ERROR
                break;
        }
        switch(ui->Colores_Jug_2->currentIndex()){
            case '1': //Index del color Rojo en el jugador 2
                serial->write("r"); //envio la r de RED
                break;
            case '0': //Index del color Azul en el jugador 2
                serial->write("b"); //envio la b de BLUE
                break;
            case '2': //Index del color Verde en el jugador 2
                serial->write("g"); //envio la g de GREEN
                break;
            case '3': //Index del color Amarillo en el jugador 2
                serial->write("y"); //envio la y de YELLOW
                break;
            case '4': //Index del color Rosa en el jugador 2
                serial->write("p"); //envio la p de PINK
                break;
            default:
                serial->write("e"); //envia ERROR
                break;
        }
    }
    ui->Color->hide();
    ui->Movimiento->show();
    ui->Contador->show();
}

void MainWindow::begining()
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
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("5"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }

}

void MainWindow::on_Mov_Izq_clicked()
{
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("3"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }
}

void MainWindow::on_Conf_Pos_clicked()
{
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("1"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }
}

void MainWindow::serial_read()
{
    if(serial->isReadable()){
        QByteArray data = serial->readAll();
        if(data.toInt() == 1){
            ui->Cont_Jug_1->display(ui->Cont_Jug_1->digitCount()+1);
        }else if(data.toInt() == 2){
            ui->Cont_Jug_2->display(ui->Cont_Jug_2->digitCount()+1);
        }else{
            ui->Cont_Jug_1->display(0);
            ui->Cont_Jug_2->display(0);
        }
    }
}
