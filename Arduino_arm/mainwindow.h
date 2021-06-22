#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool IsPaused = false;

private slots:
    void on_save_clicked();

    void on_run_clicked();

    void on_reset_clicked();

    void on_servo_06_valueChanged(int value);

    void on_servo_05_valueChanged(int value);

    void on_servo_04_valueChanged(int value);

    void on_servo_03_valueChanged(int value);

    void on_servo_02_valueChanged(int value);

    void on_servo_01_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
