#include <SoftwareSerial.h>
#include <Servo.h>
String val;
Servo servo;
SoftwareSerial Bluetooth(3, 4);

void setup()

{

Bluetooth.begin(9600);
servo.attach(6);
servo.write(180);
pinMode(13, OUTPUT); // 13 пин – светодиод, объявляется как выход

}

void loop()

{
if (Bluetooth.available()) // проверка поданных команд
{
delay(1000);
val = Bluetooth.readString();
Bluetooth.print(val);
if (val.startsWith("1")) {
  Bluetooth.print("Hello");
  servo.write(0);} // при 1 включается светодиод

if (val.startsWith("0")) {servo.write(180);} 
if (val.startsWith("2")) {servo.write(90);}
if (val.startsWith("3")) {servo.write(120);}
if (val.startsWith("5")) {servo.write(200);}
delay(2000);// при 0 выключается светодиод

}

}
