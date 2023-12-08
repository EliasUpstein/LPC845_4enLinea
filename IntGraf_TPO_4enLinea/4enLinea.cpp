#include "4enLinea.h"
#include "ui_4enLinea.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = NULL;
    Colors_1 = (QStringList() << "Rojo" << "Azul" << "Verde" << "Amarillo" << "Rosa" << "Celeste" << "Violeta" << "Naranja");
    Colors_2 = (QStringList() << "Azul" << "Rojo" << "Verde" << "Amarillo" << "Rosa" << "Celeste" << "Violeta" << "Naranja");
    Aux = 0;
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
    Aux = ui->Colores_Jug_1->count();
    for(int i = 0; i < Aux; i++){
        ui->Colores_Jug_1->removeItem(0);
        ui->Colores_Jug_2->removeItem(0);
    }
    ui->Colores_Jug_1->addItems(Colors_1);
    ui->Colores_Jug_2->addItems(Colors_2);
    ui->Movimiento->hide();
    ui->Contador->hide();
    ui->Reiniciar_Juego->hide();
    ui->Error->hide();
    ui->Amarillo_1->hide();
    ui->Amarillo_2->hide();
    ui->Azul_1->hide();
    ui->Azul_2->hide();
    ui->Verde_1->hide();
    ui->Verde_2->hide();
    ui->Rojo_1->hide();
    ui->Rojo_2->hide();
    ui->Rosa_1->hide();
    ui->Rosa_2->hide();
    ui->Celeste_1->hide();
    ui->Celeste_2->hide();
    ui->Violeta_1->hide();
    ui->Violeta_2->hide();
    ui->Naranja_1->hide();
    ui->Naranja_2->hide();
    ui->Listo_1->hide();
    ui->Listo_2->hide();
    ui->Conf_Color_Jug_1->hide();
    ui->Conf_Color_Jug_2->hide();
    ui->Comienzo_Juego->hide();
    ui->Jug_1_Color->show();
    ui->Jug_2_Color->show();
    ui->Colores_Jug_1->show();
    ui->Colores_Jug_2->show();
    ui->groupBoxConex->show();
    ui->Color->show();
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
        ui->Error->hide();
        ui->groupBoxConex->hide();
        ui->Conf_Color_Jug_1->show();
        ui->Conf_Color_Jug_2->show();
    }else {
        // Si hubo un error en la apertura...
        ui->Error->show();
        delete serial;
        serial = NULL;
    }
}

void MainWindow::on_Colores_Jug_1_textActivated(const QString &arg1)
{
    if(arg1 == ui->Colores_Jug_2->currentText()){
        if(ui->Colores_Jug_2->currentIndex() == ui->Colores_Jug_2->count() - 1)
            ui->Colores_Jug_2->setCurrentIndex(ui->Colores_Jug_2->currentIndex() - (ui->Colores_Jug_2->count() - 1));
        else
            ui->Colores_Jug_2->setCurrentIndex(ui->Colores_Jug_2->currentIndex() + 1);
    }
}

void MainWindow::on_Colores_Jug_2_textActivated(const QString &arg2)
{
    if(arg2==ui->Colores_Jug_1->currentText()){
        if(ui->Colores_Jug_1->currentIndex() == (ui->Colores_Jug_1->count() - 1))
            ui->Colores_Jug_1->setCurrentIndex(ui->Colores_Jug_1->currentIndex() - (ui->Colores_Jug_2->count() - 1));
        else
            ui->Colores_Jug_1->setCurrentIndex(ui->Colores_Jug_1->currentIndex() + 1);
    }
}

void MainWindow::on_Conf_Color_Jug_1_clicked()
{
    if(serial->isWritable()){
        switch(ui->Colores_Jug_1->currentIndex()){
            case 0:
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
            case 1:
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
            case 2:
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
            case 3:
                if(ui->Conf_Color_Jug_2->isHidden() && ui->Colores_Jug_2->currentIndex() <= 3)
                {
                    serial->write("P"); //envio la P de PINK
                    ui->Rosa_1->show();
                }else{
                    serial->write("Y"); //envio la Y de YELLOW
                    ui->Amarillo_1->show();
                    ui->Colores_Jug_2->removeItem(3);//Cancelo la posibilidad del color Amarillo en el jugador 2
                }
                break;
            case 4:
                if(ui->Conf_Color_Jug_2->isHidden() && ui->Colores_Jug_2->currentIndex() <= 4)
                {
                    serial->write("L"); //envio la L de LIGHT BLUE
                    ui->Celeste_1->show();
                }else{
                    serial->write("P"); //envio la P de PINK
                    ui->Rosa_1->show();
                    ui->Colores_Jug_2->removeItem(4);//Cancelo la posibilidad del color rosa en el jugador 2
                }
                break;
            case 5:
                if(ui->Conf_Color_Jug_2->isHidden() && ui->Colores_Jug_2->currentIndex() <= 5)
                {
                    serial->write("V"); //envio la V de VIOLET
                    ui->Violeta_1->show();
                }else{
                    serial->write("L"); //envio la L de LIGHT BLUE
                    ui->Celeste_1->show();
                    ui->Colores_Jug_2->removeItem(5);//Cancelo la posibilidad del color Celeste en el jugador 2
                }
                break;
            case 6:
                if(ui->Conf_Color_Jug_2->isHidden() && ui->Colores_Jug_2->currentIndex() <= 6)
                {
                    serial->write("O"); //envio la O de ORANGE
                    ui->Naranja_1->show();
                }else{
                    serial->write("V"); //envio la V de VIOLET
                    ui->Violeta_1->show();
                    ui->Colores_Jug_2->removeItem(6);//Cancelo la posibilidad del color Violeta en el jugador 2
                }
                break;
            case 7:
                serial->write("O"); //envio la O de ORANGE
                ui->Naranja_1->show();
                ui->Colores_Jug_2->removeItem(7);//Cancelo la posibilidad del color Naranja en el jugador 2
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
            case 3:
                if(ui->Conf_Color_Jug_1->isHidden() && ui->Colores_Jug_1->currentIndex() <= 3)
                {
                    serial->write("p"); //envio la p de PINK
                    ui->Rosa_2->show();
                }else{
                    serial->write("y"); //envio la y de YELLOW
                    ui->Amarillo_2->show();
                    ui->Colores_Jug_1->removeItem(3);//Cancelo la posibilidad del color Amarillo en el jugador 2
                }
                break;
            case 4:
                if(ui->Conf_Color_Jug_1->isHidden() && ui->Colores_Jug_1->currentIndex() <= 4)
                {
                    serial->write("l"); //envio la l de LIGHT BLUE
                    ui->Celeste_2->show();
                }else{
                    serial->write("p"); //envio la p de PINK
                    ui->Rosa_2->show();
                    ui->Colores_Jug_1->removeItem(4);//Cancelo la posibilidad del color rosa en el jugador 2
                }
                break;
            case 5:
                if(ui->Conf_Color_Jug_1->isHidden() && ui->Colores_Jug_1->currentIndex() <= 5)
                {
                    serial->write("v"); //envio la v de VIOLET
                    ui->Violeta_2->show();
                }else{
                    serial->write("l"); //envio la l de LIGHT BLUE
                    ui->Celeste_2->show();
                    ui->Colores_Jug_1->removeItem(5);//Cancelo la posibilidad del color Celeste en el jugador 2
                }
                break;
            case 6:
                if(ui->Conf_Color_Jug_1->isHidden() && ui->Colores_Jug_1->currentIndex() <= 6)
                {
                    serial->write("o"); //envio la o de ORANGE
                    ui->Naranja_2->show();
                }else{
                    serial->write("v"); //envio la v de VIOLET
                    ui->Violeta_2->show();
                    ui->Colores_Jug_1->removeItem(6);//Cancelo la posibilidad del color Violeta en el jugador 2
                }
                break;
            case 7:
                serial->write("o"); //envio la o de ORANGE
                ui->Naranja_2->show();
                ui->Colores_Jug_1->removeItem(7);//Cancelo la posibilidad del color Naranja en el jugador 2
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
    ui->Reiniciar_Juego->show();

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
            ui->Reiniciar_Juego->show();
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
        serial->write("0"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }
}

void MainWindow::on_Mov_Izq_clicked()
{
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("2"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }
}

void MainWindow::on_Conf_Pos_clicked()
{
    if(serial->isWritable()){ //chequeao que la comunicación tenga habilitada la escritura
        serial->write("1"); //envio el valor equivalente a la switch en el teclado fisico del Kit
    }
}

void MainWindow::on_Reiniciar_Juego_clicked()
{
    begining();
    ui->groupBoxConex->hide();
    ui->Conf_Color_Jug_1->show();
    ui->Conf_Color_Jug_2->show();
}
