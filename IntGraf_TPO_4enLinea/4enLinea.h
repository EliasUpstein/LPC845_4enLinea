#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void begin();

private slots:
    void on_Comienzo_Juego_clicked();

    void on_Rein_Cont_clicked();

    void on_Mov_Izq_clicked();

    void on_Colores_Jug_1_textActivated(const QString &arg1);

    void on_Colores_Jug_2_textActivated(const QString &arg1);

    void on_Mov_Der_clicked();

    void on_Conf_Pos_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
