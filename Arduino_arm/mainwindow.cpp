#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Arm control");
    this->setWindowIcon(QIcon(":/images/icon.png"));
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
       serialPort.setBaudRate(QSerialPort::Baud115200);
       serialPort.setDataBits(QSerialPort::Data8);
         serialPort.setParity(QSerialPort::NoParity);
         serialPort.setStopBits(QSerialPort::OneStop);
         serialPort.setFlowControl(QSerialPort::NoFlowControl);
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
       ui->positions->setText(QString::number(pos));
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
       serialPort.setBaudRate(QSerialPort::Baud115200);
       serialPort.setDataBits(QSerialPort::Data8);
         serialPort.setParity(QSerialPort::NoParity);
         serialPort.setStopBits(QSerialPort::OneStop);
         serialPort.setFlowControl(QSerialPort::NoFlowControl);

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
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
      serialPort.setParity(QSerialPort::NoParity);
      serialPort.setStopBits(QSerialPort::OneStop);
      serialPort.setFlowControl(QSerialPort::NoFlowControl);

    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
        serialPort.write("RESET");
        ui->run->setText("Начать");
        ui->run->setStyleSheet("* { background-color: rgb(38, 67, 255) }");
        ui->positions->setText("0");
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
    QString pname= this->ui->cmbPort->currentText();
    qDebug()<<pname;
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
      serialPort.setParity(QSerialPort::NoParity);
      serialPort.setStopBits(QSerialPort::OneStop);
      serialPort.setFlowControl(QSerialPort::NoFlowControl);
    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s6"+QString::number(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
    serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    QByteArray data;
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        data.append(serialPort.readAll());
    }
    qDebug()<<data;
    qDebug()<<value;
    qDebug()<<str1;
    qDebug()<<c_str2;

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_05_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    QString pname= this->ui->cmbPort->currentText();
    qDebug()<<pname;
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
      serialPort.setParity(QSerialPort::NoParity);
      serialPort.setStopBits(QSerialPort::OneStop);
      serialPort.setFlowControl(QSerialPort::NoFlowControl);
    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s5"+QString::number(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
    serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    QByteArray data;
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        data.append(serialPort.readAll());
    }
    qDebug()<<data;
    qDebug()<<value;
    qDebug()<<str1;
    qDebug()<<c_str2;

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_04_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    QString pname= this->ui->cmbPort->currentText();
    qDebug()<<pname;
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
      serialPort.setParity(QSerialPort::NoParity);
      serialPort.setStopBits(QSerialPort::OneStop);
      serialPort.setFlowControl(QSerialPort::NoFlowControl);
    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s4"+QString::number(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
    serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    QByteArray data;
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        data.append(serialPort.readAll());
    }
    qDebug()<<data;
    qDebug()<<value;
    qDebug()<<str1;
    qDebug()<<c_str2;

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_03_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    QString pname= this->ui->cmbPort->currentText();
    qDebug()<<pname;
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
      serialPort.setParity(QSerialPort::NoParity);
      serialPort.setStopBits(QSerialPort::OneStop);
      serialPort.setFlowControl(QSerialPort::NoFlowControl);
    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s3"+QString::number(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
    serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    QByteArray data;
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        data.append(serialPort.readAll());
    }
    qDebug()<<data;
    qDebug()<<value;
    qDebug()<<str1;
    qDebug()<<c_str2;

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_02_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    QString pname= this->ui->cmbPort->currentText();
    qDebug()<<pname;
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
      serialPort.setParity(QSerialPort::NoParity);
      serialPort.setStopBits(QSerialPort::OneStop);
      serialPort.setFlowControl(QSerialPort::NoFlowControl);
    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s2"+QString::number(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
    serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    QByteArray data;
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        data.append(serialPort.readAll());
    }
    qDebug()<<data;
    qDebug()<<value;
    qDebug()<<str1;
    qDebug()<<c_str2;

    // ну и закрываем порт
    serialPort.close();
}

void MainWindow::on_servo_01_valueChanged(int value)
{
    QSerialPort serialPort;

    // указали имя к какому порту будем подключаться
    serialPort.setPortName(this->ui->cmbPort->currentText());
    QString pname= this->ui->cmbPort->currentText();
    qDebug()<<pname;
    // указали скорость
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
      serialPort.setParity(QSerialPort::NoParity);
      serialPort.setStopBits(QSerialPort::OneStop);
      serialPort.setFlowControl(QSerialPort::NoFlowControl);
    // пробуем подключится
    if (!serialPort.open(QIODevice::ReadWrite)) {
        // если подключится не получится, то покажем сообщение с ошибкой
        QMessageBox::warning(this, "Ошибка", "Не удалось подключится к порту");
        return;
    }
    QString str1 = "s1"+QString::number(value);
      QByteArray ba = str1.toLocal8Bit();
      const char *c_str2 = ba.data();
    serialPort.write(c_str2);
    serialPort.waitForBytesWritten();
    QByteArray data;
    while (serialPort.waitForReadyRead(10)) {
        // и если появилось мы просто это читаем в пустоту
        data.append(serialPort.readAll());
    }
    qDebug()<<data;
    qDebug()<<value;
    qDebug()<<str1;
    qDebug()<<c_str2;

    // ну и закрываем порт
    serialPort.close();
}
