/********************************************************************************
** Form generated from reading UI file '4enLinea.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_4ENLINEA_H
#define UI_4ENLINEA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *TiTulo_Juego;
    QGroupBox *Contador;
    QPushButton *Rein_Cont;
    QLabel *Jug_1;
    QLabel *Con_Vic;
    QLCDNumber *Cont_Jug_1;
    QLCDNumber *Cont_Jug_2;
    QLabel *Jug_2;
    QGroupBox *Movimiento;
    QLabel *Mov_Fichas;
    QPushButton *Mov_Der;
    QPushButton *Mov_Izq;
    QPushButton *Conf_Pos;
    QGroupBox *Color;
    QComboBox *Colores_Jug_1;
    QComboBox *Colores_Jug_2;
    QLabel *Jug_1_Color;
    QLabel *Jug_2_Color;
    QPushButton *Conf_Color_Jug_1;
    QPushButton *Conf_Color_Jug_2;
    QLabel *Rojo_1;
    QLabel *Rojo_2;
    QLabel *Amarillo_1;
    QLabel *Azul_1;
    QLabel *Verde_1;
    QLabel *Azul_2;
    QLabel *Verde_2;
    QLabel *Amarillo_2;
    QLabel *Listo_1;
    QLabel *Listo_2;
    QGroupBox *groupBoxConex;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPort;
    QComboBox *comboBoxPuertos;
    QPushButton *ConectarBoton;
    QPushButton *Comienzo_Juego;
    QLabel *Error;
    QLabel *Rosa_1;
    QLabel *Celeste_1;
    QLabel *Violeta_1;
    QLabel *Naranja_1;
    QLabel *Rosa_2;
    QLabel *Celeste_2;
    QLabel *Violeta_2;
    QLabel *Naranja_2;
    QLabel *Fondo_Juego;
    QPushButton *Reiniciar_Juego;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 640);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TiTulo_Juego = new QLabel(centralwidget);
        TiTulo_Juego->setObjectName(QString::fromUtf8("TiTulo_Juego"));
        TiTulo_Juego->setGeometry(QRect(290, 0, 461, 171));
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans MT"));
        font.setPointSize(48);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        TiTulo_Juego->setFont(font);
        TiTulo_Juego->setStyleSheet(QString::fromUtf8("font: 700 48pt \"Gill Sans MT\" rgb(255,255,255);\n"
"\n"
"\n"
""));
        Contador = new QGroupBox(centralwidget);
        Contador->setObjectName(QString::fromUtf8("Contador"));
        Contador->setGeometry(QRect(10, 170, 461, 431));
        Contador->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 189, 189);"));
        Rein_Cont = new QPushButton(Contador);
        Rein_Cont->setObjectName(QString::fromUtf8("Rein_Cont"));
        Rein_Cont->setGeometry(QRect(100, 290, 231, 71));
        QFont font1;
        font1.setPointSize(14);
        Rein_Cont->setFont(font1);
        Jug_1 = new QLabel(Contador);
        Jug_1->setObjectName(QString::fromUtf8("Jug_1"));
        Jug_1->setGeometry(QRect(50, 140, 151, 51));
        QFont font2;
        font2.setPointSize(12);
        Jug_1->setFont(font2);
        Con_Vic = new QLabel(Contador);
        Con_Vic->setObjectName(QString::fromUtf8("Con_Vic"));
        Con_Vic->setGeometry(QRect(90, 20, 281, 111));
        QFont font3;
        font3.setPointSize(16);
        Con_Vic->setFont(font3);
        Cont_Jug_1 = new QLCDNumber(Contador);
        Cont_Jug_1->setObjectName(QString::fromUtf8("Cont_Jug_1"));
        Cont_Jug_1->setGeometry(QRect(50, 200, 111, 41));
        Cont_Jug_1->setFont(font2);
        Cont_Jug_2 = new QLCDNumber(Contador);
        Cont_Jug_2->setObjectName(QString::fromUtf8("Cont_Jug_2"));
        Cont_Jug_2->setGeometry(QRect(260, 200, 121, 41));
        Cont_Jug_2->setFont(font2);
        Jug_2 = new QLabel(Contador);
        Jug_2->setObjectName(QString::fromUtf8("Jug_2"));
        Jug_2->setGeometry(QRect(260, 140, 161, 51));
        Jug_2->setFont(font2);
        Movimiento = new QGroupBox(centralwidget);
        Movimiento->setObjectName(QString::fromUtf8("Movimiento"));
        Movimiento->setGeometry(QRect(480, 170, 531, 311));
        Movimiento->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 189, 189);"));
        Mov_Fichas = new QLabel(Movimiento);
        Mov_Fichas->setObjectName(QString::fromUtf8("Mov_Fichas"));
        Mov_Fichas->setGeometry(QRect(80, 10, 391, 81));
        Mov_Fichas->setFont(font3);
        Mov_Der = new QPushButton(Movimiento);
        Mov_Der->setObjectName(QString::fromUtf8("Mov_Der"));
        Mov_Der->setGeometry(QRect(280, 100, 231, 81));
        Mov_Der->setFont(font1);
        Mov_Izq = new QPushButton(Movimiento);
        Mov_Izq->setObjectName(QString::fromUtf8("Mov_Izq"));
        Mov_Izq->setGeometry(QRect(20, 100, 231, 81));
        Mov_Izq->setFont(font1);
        Conf_Pos = new QPushButton(Movimiento);
        Conf_Pos->setObjectName(QString::fromUtf8("Conf_Pos"));
        Conf_Pos->setGeometry(QRect(150, 200, 231, 81));
        Conf_Pos->setFont(font1);
        Color = new QGroupBox(centralwidget);
        Color->setObjectName(QString::fromUtf8("Color"));
        Color->setGeometry(QRect(30, 190, 971, 341));
        Color->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 189, 189);"));
        Colores_Jug_1 = new QComboBox(Color);
        Colores_Jug_1->setObjectName(QString::fromUtf8("Colores_Jug_1"));
        Colores_Jug_1->setGeometry(QRect(340, 100, 141, 51));
        Colores_Jug_1->setFont(font2);
        Colores_Jug_1->setStyleSheet(QString::fromUtf8(""));
        Colores_Jug_2 = new QComboBox(Color);
        Colores_Jug_2->setObjectName(QString::fromUtf8("Colores_Jug_2"));
        Colores_Jug_2->setGeometry(QRect(340, 190, 141, 51));
        Colores_Jug_2->setFont(font2);
        Jug_1_Color = new QLabel(Color);
        Jug_1_Color->setObjectName(QString::fromUtf8("Jug_1_Color"));
        Jug_1_Color->setGeometry(QRect(60, 80, 281, 101));
        Jug_1_Color->setFont(font2);
        Jug_2_Color = new QLabel(Color);
        Jug_2_Color->setObjectName(QString::fromUtf8("Jug_2_Color"));
        Jug_2_Color->setGeometry(QRect(60, 170, 271, 91));
        Jug_2_Color->setFont(font2);
        Conf_Color_Jug_1 = new QPushButton(Color);
        Conf_Color_Jug_1->setObjectName(QString::fromUtf8("Conf_Color_Jug_1"));
        Conf_Color_Jug_1->setGeometry(QRect(550, 90, 331, 61));
        Conf_Color_Jug_1->setFont(font2);
        Conf_Color_Jug_2 = new QPushButton(Color);
        Conf_Color_Jug_2->setObjectName(QString::fromUtf8("Conf_Color_Jug_2"));
        Conf_Color_Jug_2->setGeometry(QRect(550, 190, 331, 61));
        Conf_Color_Jug_2->setFont(font2);
        Rojo_1 = new QLabel(Color);
        Rojo_1->setObjectName(QString::fromUtf8("Rojo_1"));
        Rojo_1->setGeometry(QRect(350, 80, 101, 101));
        Rojo_1->setFont(font2);
        Rojo_2 = new QLabel(Color);
        Rojo_2->setObjectName(QString::fromUtf8("Rojo_2"));
        Rojo_2->setGeometry(QRect(350, 170, 101, 91));
        Rojo_2->setFont(font2);
        Amarillo_1 = new QLabel(Color);
        Amarillo_1->setObjectName(QString::fromUtf8("Amarillo_1"));
        Amarillo_1->setGeometry(QRect(350, 80, 101, 101));
        Amarillo_1->setFont(font2);
        Azul_1 = new QLabel(Color);
        Azul_1->setObjectName(QString::fromUtf8("Azul_1"));
        Azul_1->setGeometry(QRect(350, 80, 101, 101));
        Azul_1->setFont(font2);
        Azul_1->setStyleSheet(QString::fromUtf8(""));
        Verde_1 = new QLabel(Color);
        Verde_1->setObjectName(QString::fromUtf8("Verde_1"));
        Verde_1->setGeometry(QRect(350, 80, 101, 101));
        Verde_1->setFont(font2);
        Azul_2 = new QLabel(Color);
        Azul_2->setObjectName(QString::fromUtf8("Azul_2"));
        Azul_2->setGeometry(QRect(350, 170, 101, 91));
        Azul_2->setFont(font2);
        Verde_2 = new QLabel(Color);
        Verde_2->setObjectName(QString::fromUtf8("Verde_2"));
        Verde_2->setGeometry(QRect(350, 170, 101, 91));
        Verde_2->setFont(font2);
        Amarillo_2 = new QLabel(Color);
        Amarillo_2->setObjectName(QString::fromUtf8("Amarillo_2"));
        Amarillo_2->setGeometry(QRect(350, 170, 101, 91));
        Amarillo_2->setFont(font2);
        Listo_1 = new QLabel(Color);
        Listo_1->setObjectName(QString::fromUtf8("Listo_1"));
        Listo_1->setGeometry(QRect(620, 90, 201, 71));
        QFont font4;
        font4.setPointSize(18);
        Listo_1->setFont(font4);
        Listo_2 = new QLabel(Color);
        Listo_2->setObjectName(QString::fromUtf8("Listo_2"));
        Listo_2->setGeometry(QRect(620, 180, 201, 71));
        Listo_2->setFont(font4);
        groupBoxConex = new QGroupBox(Color);
        groupBoxConex->setObjectName(QString::fromUtf8("groupBoxConex"));
        groupBoxConex->setGeometry(QRect(520, 80, 421, 171));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBoxConex->sizePolicy().hasHeightForWidth());
        groupBoxConex->setSizePolicy(sizePolicy);
        groupBoxConex->setMinimumSize(QSize(300, 0));
        groupBoxConex->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 189, 189);"));
        formLayout = new QFormLayout(groupBoxConex);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 20, -1, -1);
        labelPort = new QLabel(groupBoxConex);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        QFont font5;
        font5.setPointSize(10);
        labelPort->setFont(font5);

        horizontalLayout->addWidget(labelPort);

        comboBoxPuertos = new QComboBox(groupBoxConex);
        comboBoxPuertos->setObjectName(QString::fromUtf8("comboBoxPuertos"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxPuertos->sizePolicy().hasHeightForWidth());
        comboBoxPuertos->setSizePolicy(sizePolicy1);
        QFont font6;
        font6.setPointSize(11);
        comboBoxPuertos->setFont(font6);
        comboBoxPuertos->setEditable(false);

        horizontalLayout->addWidget(comboBoxPuertos);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        ConectarBoton = new QPushButton(groupBoxConex);
        ConectarBoton->setObjectName(QString::fromUtf8("ConectarBoton"));
        ConectarBoton->setEnabled(true);
        ConectarBoton->setFont(font5);

        formLayout->setWidget(1, QFormLayout::SpanningRole, ConectarBoton);

        Comienzo_Juego = new QPushButton(Color);
        Comienzo_Juego->setObjectName(QString::fromUtf8("Comienzo_Juego"));
        Comienzo_Juego->setGeometry(QRect(510, 80, 421, 191));
        QFont font7;
        font7.setPointSize(20);
        Comienzo_Juego->setFont(font7);
        Error = new QLabel(Color);
        Error->setObjectName(QString::fromUtf8("Error"));
        Error->setGeometry(QRect(580, 270, 301, 20));
        Error->setFont(font5);
        Error->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        Rosa_1 = new QLabel(Color);
        Rosa_1->setObjectName(QString::fromUtf8("Rosa_1"));
        Rosa_1->setGeometry(QRect(350, 80, 101, 101));
        Rosa_1->setFont(font2);
        Celeste_1 = new QLabel(Color);
        Celeste_1->setObjectName(QString::fromUtf8("Celeste_1"));
        Celeste_1->setGeometry(QRect(350, 80, 101, 101));
        Celeste_1->setFont(font2);
        Violeta_1 = new QLabel(Color);
        Violeta_1->setObjectName(QString::fromUtf8("Violeta_1"));
        Violeta_1->setGeometry(QRect(350, 80, 101, 101));
        Violeta_1->setFont(font2);
        Naranja_1 = new QLabel(Color);
        Naranja_1->setObjectName(QString::fromUtf8("Naranja_1"));
        Naranja_1->setGeometry(QRect(350, 80, 101, 101));
        Naranja_1->setFont(font2);
        Rosa_2 = new QLabel(Color);
        Rosa_2->setObjectName(QString::fromUtf8("Rosa_2"));
        Rosa_2->setGeometry(QRect(350, 170, 101, 91));
        Rosa_2->setFont(font2);
        Celeste_2 = new QLabel(Color);
        Celeste_2->setObjectName(QString::fromUtf8("Celeste_2"));
        Celeste_2->setGeometry(QRect(350, 170, 101, 91));
        Celeste_2->setFont(font2);
        Violeta_2 = new QLabel(Color);
        Violeta_2->setObjectName(QString::fromUtf8("Violeta_2"));
        Violeta_2->setGeometry(QRect(350, 170, 101, 91));
        Violeta_2->setFont(font2);
        Naranja_2 = new QLabel(Color);
        Naranja_2->setObjectName(QString::fromUtf8("Naranja_2"));
        Naranja_2->setGeometry(QRect(350, 170, 101, 91));
        Naranja_2->setFont(font2);
        Celeste_2->raise();
        Violeta_2->raise();
        Naranja_2->raise();
        Celeste_1->raise();
        Colores_Jug_1->raise();
        Colores_Jug_2->raise();
        Error->raise();
        Listo_2->raise();
        Listo_1->raise();
        Comienzo_Juego->raise();
        Jug_1_Color->raise();
        Jug_2_Color->raise();
        Conf_Color_Jug_1->raise();
        Conf_Color_Jug_2->raise();
        Amarillo_1->raise();
        Amarillo_2->raise();
        Azul_1->raise();
        Azul_2->raise();
        Rojo_2->raise();
        Verde_1->raise();
        Verde_2->raise();
        groupBoxConex->raise();
        Rosa_2->raise();
        Rojo_1->raise();
        Rosa_1->raise();
        Naranja_1->raise();
        Violeta_1->raise();
        Fondo_Juego = new QLabel(centralwidget);
        Fondo_Juego->setObjectName(QString::fromUtf8("Fondo_Juego"));
        Fondo_Juego->setGeometry(QRect(0, -10, 1061, 631));
        Fondo_Juego->setStyleSheet(QString::fromUtf8("background-image: url(:/Fondo/Fondos-web.jpg);"));
        Reiniciar_Juego = new QPushButton(centralwidget);
        Reiniciar_Juego->setObjectName(QString::fromUtf8("Reiniciar_Juego"));
        Reiniciar_Juego->setGeometry(QRect(480, 490, 531, 111));
        Reiniciar_Juego->setFont(font7);
        Reiniciar_Juego->setStyleSheet(QString::fromUtf8("background-color: rgb(189, 189, 189);"));
        MainWindow->setCentralWidget(centralwidget);
        Fondo_Juego->raise();
        Reiniciar_Juego->raise();
        Movimiento->raise();
        Contador->raise();
        Color->raise();
        TiTulo_Juego->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TiTulo_Juego->setText(QCoreApplication::translate("MainWindow", "4 en Linea", nullptr));
        Contador->setTitle(QString());
        Rein_Cont->setText(QCoreApplication::translate("MainWindow", "Reiniciar Contador", nullptr));
        Jug_1->setText(QCoreApplication::translate("MainWindow", "Jugador N\302\272 1:", nullptr));
        Con_Vic->setText(QCoreApplication::translate("MainWindow", "Contador Victorias:", nullptr));
        Jug_2->setText(QCoreApplication::translate("MainWindow", "Jugador N\302\272 2:", nullptr));
        Movimiento->setTitle(QString());
        Mov_Fichas->setText(QCoreApplication::translate("MainWindow", "Moviemiento de las Fichas:", nullptr));
        Mov_Der->setText(QCoreApplication::translate("MainWindow", "Derecha", nullptr));
        Mov_Izq->setText(QCoreApplication::translate("MainWindow", "Izquierda", nullptr));
        Conf_Pos->setText(QCoreApplication::translate("MainWindow", "Confirmar", nullptr));
        Color->setTitle(QString());
#if QT_CONFIG(whatsthis)
        Colores_Jug_1->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        Colores_Jug_2->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Jug_1_Color->setText(QCoreApplication::translate("MainWindow", "Color del Jugador N\302\272 1:", nullptr));
        Jug_2_Color->setText(QCoreApplication::translate("MainWindow", "Color del Jugador N\302\272 2:", nullptr));
        Conf_Color_Jug_1->setText(QCoreApplication::translate("MainWindow", "Confirma Color Jugador N\302\272 1", nullptr));
        Conf_Color_Jug_2->setText(QCoreApplication::translate("MainWindow", "Confirma Color Jugador N\302\272 2", nullptr));
        Rojo_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">Rojo</span></p></body></html>", nullptr));
        Rojo_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">Rojo</span></p></body></html>", nullptr));
        Amarillo_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffff00;\">Amarillo</span></p></body></html>", nullptr));
        Azul_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#0000ff;\">Azul</span></p></body></html>", nullptr));
        Verde_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#00ff00;\">Verde</span></p></body></html>", nullptr));
        Azul_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#0000ff;\">Azul</span></p></body></html>", nullptr));
        Verde_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#00ff00;\">Verde</span></p></body></html>", nullptr));
        Amarillo_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffff00;\">Amarillo</span></p></body></html>", nullptr));
        Listo_1->setText(QCoreApplication::translate("MainWindow", "\302\241LISTO!", nullptr));
        Listo_2->setText(QCoreApplication::translate("MainWindow", "\302\241LISTO!", nullptr));
        groupBoxConex->setTitle(QCoreApplication::translate("MainWindow", "Conexi\303\263n", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "Puerto", nullptr));
        ConectarBoton->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        Comienzo_Juego->setText(QCoreApplication::translate("MainWindow", "Comenzar Juego", nullptr));
        Error->setText(QCoreApplication::translate("MainWindow", "*Error abriendo la comunicaci\303\263n*", nullptr));
        Rosa_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff00ae;\">Rosa</span></p></body></html>", nullptr));
        Celeste_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#00ffff;\">Celeste</span></p></body></html>", nullptr));
        Violeta_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#aa00ff;\">Violeta</span></p></body></html>", nullptr));
        Naranja_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffaa00;\">Naranja</span></p></body></html>", nullptr));
        Rosa_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff00ae;\">Rosa</span></p></body></html>", nullptr));
        Celeste_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#00ffff;\">Celeste</span></p></body></html>", nullptr));
        Violeta_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#aa00ff;\">Violeta</span></p></body></html>", nullptr));
        Naranja_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffaa00;\">Naranja</span></p></body></html>", nullptr));
        Fondo_Juego->setText(QString());
        Reiniciar_Juego->setText(QCoreApplication::translate("MainWindow", "Reiniciar Juego", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_4ENLINEA_H
