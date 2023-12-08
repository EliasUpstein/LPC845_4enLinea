#include "4enLinea.h"
#include "ui_4enLinea.h"

#define Index_Max 3  //el index del QComboBox comienza desde 0, por ende hay 4 colores

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = NULL;
    begining();
    enumerarPuertos();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (serial != NULL) {
        serial->close();
        delete serial;
    }
}

void MainWindow::begining()
{
    ui->Movimiento->hide();
    ui->Contador->hide();
    ui->Amarillo_1->hide();
    ui->Amarillo_2->hide();
    ui->Azul_1->hide();
    ui->Azul_2->hide();
    ui->Verde_1->hide();
    ui->Verde_2->hide();
    ui->Rojo_1->hide();
    ui->Rojo_2->hide();
    ui->Listo_1->hide();
    ui->Listo_2->hide();
    ui->Conf_Color_Jug_1->hide();
    ui->Conf_Color_Jug_2->hide();
    ui->Comienzo_Juego->hide();
}

void MainWindow::enumerarPuertos()
{
    ui->comboBoxPuertos->clear();

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for (int i = 0; i < ports.size(); i++){
        ui->comboBoxPuertos->addItem(ports.at(i).portName(), ports.at(i).portName());
    }
}

void MainWindow::on_ConectarBoton_clicked()
{
    //Obtenemos el nombre del puerto del comboBox
    int i = ui->comboBoxPuertos->currentIndex();
    portname = ui->comboBoxPuertos->itemData(i).toString();

    qDebug()<<"Puerto Serie Seleccionado: "<<portname;

    //Creamos y configuramos el puerto
    serial = new QSerialPort(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    //Abrimos el puerto en modo lectura-escritura
    if (serial->open(QIODevice::ReadWrite)) {
        //Conectamos las señales que nos interesen
        connect(serial, SIGNAL(readyRead()), this, SLOT(serial_read()));

        ui->groupBoxConex->hide();
        ui->Conf_Color_Jug_1->show();
        ui->Conf_Color_Jug_2->show();
    }else {
        // Si hubo un error en la apertura...
        qDebug()<<"no pude abrir correctamente la comunicación";
        delete serial;
        serial = NULL;
    }
}

void MainWindow::on_Colores_Jug_1_textActivated(const QString &arg1)
{
    if(arg1 == ui->Colores_Jug_2->currentText()){
        if(ui->Colores_Jug_2->currentIndex() == Index_Max)
            ui->Colores_Jug_2->setCurrentIndex(ui->Colores_Jug_1->currentIndex() - Index_Max);
        else
            ui->Colores_Jug_2->setCurrentIndex(ui->Colores_Jug_2->currentIndex() + 1);
    }
}

void MainWindow::on_Colores_Jug_2_textActivated(const QString &arg2)
{
    if(arg2==ui->Colores_Jug_1->currentText()){
        if(ui->Colores_Jug_1->currentIndex() == Index_Max)
            ui->Colores_Jug_1->setCurrentIndex(ui->Colores_Jug_1->currentIndex() - Index_Max);
        else
            ui->Colores_Jug_1->setCurrentIndex(ui->Colores_Jug_1->currentIndex() + 1);
    }
}

void MainWindow::on_Conf_Color_Jug_1_clicked()
{
    if(serial->isWritable()){
        switch(ui->Colores_Jug_1->currentIndex()){
            case 0: //Index del color Rojo en el jugador 1
                if(ui->Conf_Color_Jug_2->isHidden() && ui->Colores_Jug_2->currentIndex() == 1)
                {
                    serial->write("B"); //envio la B de BLUE
                    ui->Azul_1->show();
                }else{
                    serial->write("R"); //envio la R de RED
                    ui->Rojo_1->show();
                    ui->Colores_Jug_2->removeItem(1);//Cancelo la posibilidad del color Rojo en el jugador 2
                }
                break;
            case 1: //Index del color Azul en el jugador 1
                if(ui->Conf_Color_Jug_2->isHidden() && ui->Colores_Jug_2->currentIndex() <= 1)
                {
                    serial->write("G"); //envio la G de GREEN
                    ui->Verde_1->show();
                }else{
                    serial->write("B"); //envio la B de BLUE
                    ui->Azul_1->show();
                    ui->Colores_Jug_2->removeItem(0);//Cancelo la posibilidad del color Azul en el jugador 2
                }
                break;
            case 2: //Index del color Verde en el jugador 1
                if(ui->Conf_Color_Jug_2->isHidden() && ui->Colores_Jug_2->currentIndex() <= 2)
                {
                    serial->write("Y"); //envio la Y de YELLOW
                    ui->Amarillo_1->show();
                }else{
                    serial->write("G"); //envio la G de GREEN
                    ui->Verde_1->show();
                    ui->Colores_Jug_2->removeItem(2);//Cancelo la posibilidad del color Verde en el jugador 2
                }
                break;
            case 3: //Index del color Amarillo en el jugador 1
                serial->write("Y"); //envio la Y de YELLOW
                ui->Amarillo_1->show();
                ui->Colores_Jug_2->removeItem(3);//Cancelo la posibilidad del color Amarillo en el jugador 2
                break;
            default:
                serial->write("E"); //envia ERROR
                break;
        }
    }

    ui->Conf_Color_Jug_1->hide();
    ui->Colores_Jug_1->hide();

    if(ui->Conf_Color_Jug_2->isHidden())
    {
        ui->Listo_2->hide();
        ui->Comienzo_Juego->show();
    }
    else
        ui->Listo_1->show();
}

void MainWindow::on_Conf_Color_Jug_2_clicked()
{
    if(serial->isWritable()){
        switch(ui->Colores_Jug_2->currentIndex()){
            case 1: //Index del color Rojo en el jugador 2
                if(ui->Conf_Color_Jug_1->isHidden() && ui->Colores_Jug_1->currentIndex() <= 1)
                {
                    serial->write("g"); //envio la g de GREEN
                    ui->Verde_2->show();
                }else{
                    serial->write("r"); //envio la r de RED
                    ui->Rojo_2->show();
                    ui->Colores_Jug_1->removeItem(0);//Cancelo la posibilidad del color Rojo en el jugador 1
                }
                break;
            case 0: //Index del color Azul en el jugador 2
                if(ui->Conf_Color_Jug_1->isHidden() && ui->Colores_Jug_1->currentIndex() == 1)
                {
                    serial->write("r"); //envio la r de RED
                    ui->Rojo_2->show();
                }else{
                    serial->write("b"); //envio la b de BLUE
                    ui->Azul_2->show();
                    ui->Colores_Jug_1->removeItem(1);//Cancelo la posibilidad del color Azul en el jugador 1
                }
                break;
            case 2: //Index del color Verde en el jugador 2
                if(ui->Conf_Color_Jug_1->isHidden() && ui->Colores_Jug_1->currentIndex() <= 2)
                {
                    serial->write("y"); //envio la y de YELLOW
                    ui->Amarillo_2->show();
                }else{
                    serial->write("g"); //envio la g de GREEN
                    ui->Verde_2->show();
                    ui->Colores_Jug_1->removeItem(2);//Cancelo la posibilidad del color Verde en el jugador 1
                }
                break;
            case 3: //Index del color Amarillo en el jugador 2
                serial->write("y"); //envio la y de YELLOW
                ui->Amarillo_2->show();
                ui->Colores_Jug_1->removeItem(3);//Cancelo la posibilidad del color Amarillo en el jugador 1
                break;
            default:
                serial->write("e"); //envia ERROR
                break;
        }
    }

    ui->Conf_Color_Jug_2->hide();
    ui->Colores_Jug_2->hide();

    if(ui->Conf_Color_Jug_1->isHidden())
    {
        ui->Listo_1->hide();
        ui->Comienzo_Juego->show();
    }
    else
        ui->Listo_2->show();
}

void MainWindow::on_Comienzo_Juego_clicked()
{
    ui->Color->hide();
    ui->Movimiento->show();
    ui->Contador->show();

    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("S"); //envio comenzar juego
    }
}

void MainWindow::serial_read()
{
    if(serial->isReadable()){
        QByteArray data = serial->readAll();
        if(data.toStdString() == "0"){
            ui->Cont_Jug_1->display(ui->Cont_Jug_1->intValue()+1);
        }else if(data.toStdString() == "1"){
            ui->Cont_Jug_2->display(ui->Cont_Jug_2->intValue()+1);
        }else if(data.toStdString() == "S"){
            ui->Color->hide();
            ui->Movimiento->show();
            ui->Contador->show();
        }else{
            ui->Cont_Jug_1->display(0);
            ui->Cont_Jug_2->display(0);
        }
    }
}

void MainWindow::on_Rein_Cont_clicked()
{
    ui->Cont_Jug_1->display(0);
    ui->Cont_Jug_2->display(0);
}

void MainWindow::on_Mov_Der_clicked()
{
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("2"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }

}

void MainWindow::on_Mov_Izq_clicked()
{
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("0"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }
}

void MainWindow::on_Conf_Pos_clicked()
{
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("1"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }
}
