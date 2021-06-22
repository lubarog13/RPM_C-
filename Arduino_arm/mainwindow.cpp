#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
            ui->cmbPort->addItem(serialPortInfo.portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_save_clicked()
{
    // создали экземпляр для общения по последовательному порту
       QSerialPort serialPort;

       // указали имя к какому порту будем подключаться
       serialPort.setPortName(this->ui->cmbPort->currentText());
       // указали скорость
       serialPort.setBaudRate(QSerialPort::Baud9600);

       // пробуем подключится
       if (!serialPort.open(QIODevice::ReadWrite)) {
           // если подключится не получится, то покажем сообщение с ошибкой
           QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
           return;
       }

       // отправляем строку с b нашей арудинкой
       serialPort.write("SAVE"); // очень важно, что именно двойные кавычки
       int pos = ui->positions->text().toInt();
       pos++;
       ui->positions->setText(QString(pos));
       serialPort.waitForBytesWritten(); // ждем пока дойдет
       while (serialPort.waitForReadyRead(10)) {
           // и если появилось мы просто это читаем в пустоту
           serialPort.readAll();
       }

       // ну и закрываем порт
       serialPort.close();
}

void MainWindow::on_run_clicked()
{
    // создали экземпляр для общения по последовательному порту
       QSerialPort serialPort;

       // указали имя к какому порту будем подключаться
       serialPort.setPortName(this->ui->cmbPort->currentText());
       // указали скорость
       serialPort.setBaudRate(QSerialPort::Baud9600);

       // пробуем подключится
       if (!serialPort.open(QIODevice::ReadWrite)) {
           // если подключится не получится, то покажем сообщение с ошибкой
           QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
           return;
       }

       if(!IsPaused){
           serialPort.write("RUN");
           ui->run->setText("Пауза");
           ui->run->setStyleSheet("* { background-color: red }");
           IsPaused = true;
       }
       else {
           serialPort.write("PAUSE");
           ui->run->setText("Продолжить");
           ui->run->setStyleSheet("* { background-color: green }");
           IsPaused = false;
       }
       serialPort.waitForBytesWritten(); // ждем пока дойдет

       // и не знаю с чем тут связано, но, чтобы сообщение дошло
       // надо обязательно прочитать не пришло ли нам чего в ответ
       //
       // функция waitForReadyRead(10) проверят не появилось
       // в ближайшие 10 миллисекунд чего-нибудь в ответ
       while (serialPort.waitForReadyRead(10)) {
           // и если появилось мы просто это читаем в пустоту
           serialPort.readAll();

           // сам while необходим для того что ответ приходит порциями
           // и мы хотим считать все что отправилось
       }

       // ну и закрываем порт
       serialPort.close();
}

void MainWindow::on_reset_clicked()
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud9600);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
        serialPort.write("RESET");
        ui->run->setText("Начать");
        ui->run->setStyleSheet("* { background-color: rgb(38, 67, 255) }");
        IsPaused = false;
    serialPort.waitForBytesWritten();
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        serialPort.readAll();
    }

    // ну и закрываем порт
    serialPort.close();
}


void MainWindow::on_servo_06_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud9600);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s6"+QString(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
        serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        serialPort.readAll();
    }

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_05_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud9600);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s5"+QString(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
        serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        serialPort.readAll();
    }

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_04_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud9600);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s4"+QString(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
        serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        serialPort.readAll();
    }

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_03_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud9600);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s3"+QString(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
        serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        serialPort.readAll();
    }

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_02_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud9600);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s2"+QString(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
        serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        serialPort.readAll();
    }

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_01_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud9600);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s1"+QString(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
        serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        serialPort.readAll();
    }

    // ну и закрываем порт
    serialPort.close();
}
