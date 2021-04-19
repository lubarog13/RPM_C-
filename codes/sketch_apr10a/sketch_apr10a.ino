#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
SoftwareSerial Bluetooth(3, 4);
int servo01Posit, servo02Posit, servo03Posit, servo04Posit, servo05Posit, servo06Posit;
int servo01PrevPosit, servo02PrevPosit, servo03PrevPosit, servo04PrevPosit, servo05PrevPosit, servo06PrevPosit;
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50];
int speedDelay=20;
int index=0;
StringdataIn="";
void setup() {
  servo01.attach(5);
  servo01.attach(6);
  servo01.attach(7);
  servo01.attach(8);
  servo01.attach(9);
  servo01.attach(10);
  Bluetooth.begin(38400);
  Bluetooth.setTimeout(1);
  delay(20);
  servo01PrevPosit=90;
  servo01.write(servo01PrevPosit);
  servo02PrevPosit=150;
  servo02.write(servo02PrevPosit);
  servo03PrevPosit=35;
  servo03.write(servo03PrevPosit);
  servo04PrevPosit=140;
  servo04.write(servo04PrevPosit);
  servo05PrevPosit=85;
  servo05.write(servo05PrevPosit);
  servo06PrevPosit=80;
  servo06.write(servo06PrevPosit);
}

void loop() {
 if(Bluetooth.available()>0){
    dataIn=Bluetooth.readString();
    if(dataIn.startsWith("s1"){
      String dataInS = dataIn.substring(2, dataIn.length());
      servo01Posit = dataInS.toInt();
      if(servo01PrevPosit>servo01Posit){
        for(int j=servo01PrevPosit; j>=servo01Posit;j--){
          servo01.write(j);
          delay(20);
        }
      }
      if(servo01PrevPosit<servo01Posit){
        for(int j=servo01PrevPosit; j<=servo01Posit;j++){
          servo01.write(j);
          delay(20);
        }
      }
      servo01PrevPosit=servo01Posit;
    }
    if(dataIn.startsWith("s2"){
      String dataInS = dataIn.substring(2, dataIn.length());
      servo02Posit = dataInS.toInt();
      if(servo02PrevPosit>servo02Posit){
        for(int j=servo02PrevPosit; j>=servo02Posit;j--){
          servo02.write(j);
          delay(50);
        }
      }
      if(servo02PrevPosit<servo02Posit){
        for(int j=servo02PrevPosit; j<=servo02Posit;j++){
          servo02.write(j);
          delay(50);
        }
      }
      servo02PrevPosit=servo02Posit;
    }
    if(dataIn.startsWith("s3"){
      String dataInS = dataIn.substring(2, dataIn.length());
      servo03Posit = dataInS.toInt();
      if(servo03PrevPosit>servo03Posit){
        for(int j=servo03PrevPosit; j>=servo03Posit;j--){
          servo03.write(j);
          delay(30);
        }
      }
      if(servo03PrevPosit<servo03Posit){
        for(int j=servo03PrevPosit; j<=servo03Posit;j++){
          servo03.write(j);
          delay(30);
        }
      }
      servo03PrevPosit=servo03Posit;
    }
    if(dataIn.startsWith("s4"){
      String dataInS = dataIn.substring(2, dataIn.length());
      servo04Posit = dataInS.toInt();
      if(servo04PrevPosit>servo04Posit){
        for(int j=servo04PrevPosit; j>=servo04Posit;j--){
          servo04.write(j);
          delay(30);
        }
      }
      if(servo04PrevPosit<servo04Posit){
        for(int j=servo04PrevPosit; j<=servo04Posit;j++){
          servo04.write(j);
          delay(30);
        }
      }
      servo04PrevPosit=servo04Posit;
    }
    if(dataIn.startsWith("s5"){
      String dataInS = dataIn.substring(2, dataIn.length());
      servo05Posit = dataInS.toInt();
      if(servo05PrevPosit>servo05Posit){
        for(int j=servo05PrevPosit; j>=servo05Posit;j--){
          servo05.write(j);
          delay(30);
        }
      }
      if(servo05PrevPosit<servo05Posit){
        for(int j=servo05PrevPosit; j<=servo05Posit;j++){
          servo05.write(j);
          delay(30);
        }
      }
      servo05PrevPosit=servo05Posit;
    }
    if(dataIn.startsWith("s6"){
      String dataInS = dataIn.substring(2, dataIn.length());
      servo06Posit = dataInS.toInt();
      if(servo06PrevPosit>servo06Posit){
        for(int j=servo06PrevPosit; j>=servo06Posit;j--){
          servo06.write(j);
          delay(30);
        }
      }
      if(servo06PrevPosit<servo06Posit){
        for(int j=servo06PrevPosit; j<=servo06Posit;j++){
          servo06.write(j);
          delay(30);
        }
      }
      servo06PrevPosit=servo06Posit;
    }
    if(dataIn.startsWith("SAVE"){
      servo01SP[index]=servo01PrevPosit;
      servo02SP[index]=servo02PrevPosit;
      servo03SP[index]=servo03PrevPosit;
      servo04SP[index]=servo04PrevPosit;
      servo05SP[index]=servo05PrevPosit;
      servo06SP[index]=servo06PrevPosit;
      index++;}
    if(dataIn.startsWith("RUN"){
      runservo();
    }
    if(dataIn=="RESET"){
      memset(servo01SP, 0, sizeof(servo01SP));
      memset(servo02SP, 0, sizeof(servo02SP));
      memset(servo03SP, 0, sizeof(servo03SP));
      memset(servo04SP, 0, sizeof(servo04SP));
      memset(servo05SP, 0, sizeof(servo05SP));
      memset(servo06SP, 0, sizeof(servo06SP));
      index=0;
    }
 }
}
void runservo(){
  while (dataIn!="RESET"){
    for(int i=0; i<index-1; i++){
      if(Bluetooth.available>0){
        dataIn=Bluetooth.readString();
        if(dataIn=="PAUSE"){
          while (datain!="RUN"){
            if(Bluetooth.available()>0){
              dataIn=Bluetooth.readString();
              if(dataIn=="RESET") break;
            }          
          }
        }
        if(dataIn.startsWith("ss")){
          String dataInS = dataIn.substring(2, dataIn.length);
          speedDelay = dataInS.toInt();
        }
      }
      if (servo01SP[i]==servo01SP[i+1]){}
      if(servo01SP[i]>servo01SP[i+1]){
        for ( int j = servo01SP[i]; j >= servo01SP[i + 1]; j--) {
            servo01.write(j);
            delay(speedDelay);
         }
      }
      if(servo01SP[i]<servo01SP[i+1]){
        for ( int j = servo01SP[i]; j <= servo01SP[i + 1]; j++) {
            servo01.write(j);
            delay(speedDelay);
          }
      }
      if (servo02SP[i]==servo02SP[i+1]){}
      if(servo02SP[i]>servo02SP[i+1]){
        for ( int j = servo02SP[i]; j >= servo02SP[i + 1]; j--) {
            servo02.write(j);
            delay(speedDelay);
         }
      }
      if(servo02SP[i]<servo02SP[i+1]){
        for ( int j = servo02SP[i]; j <= servo02SP[i + 1]; j++) {
            servo02.write(j);
            delay(speedDelay);
          }
      }
      if (servo03SP[i]==servo03SP[i+1]){}
      if(servo03SP[i]>servo03SP[i+1]){
        for ( int j = servo03SP[i]; j >= servo03SP[i + 1]; j--) {
            servo03.write(j);
            delay(speedDelay);
         }
      }
      if(servo03SP[i]<servo03SP[i+1]){
        for ( int j = servo03SP[i]; j <= servo03SP[i + 1]; j++) {
            servo03.write(j);
            delay(speedDelay);
          }
      }
      if (servo04SP[i]==servo04SP[i+1]){}
      if(servo04SP[i]>servo04SP[i+1]){
        for ( int j = servo04SP[i]; j >= servo04SP[i + 1]; j--) {
            servo04.write(j);
            delay(speedDelay);
         }
      }
      if(servo04SP[i]<servo04SP[i+1]){
        for ( int j = servo04SP[i]; j <= servo04SP[i + 1]; j++) {
            servo04.write(j);
            delay(speedDelay);
          }
      }
      if (servo05SP[i]==servo05SP[i+1]){}
      if(servo05SP[i]>servo05SP[i+1]){
        for ( int j = servo05SP[i]; j >= servo05SP[i + 1]; j--) {
            servo05.write(j);
            delay(speedDelay);
         }
      }
      if(servo05SP[i]<servo05SP[i+1]){
        for ( int j = servo05SP[i]; j <= servo05SP[i + 1]; j++) {
            servo05.write(j);
            delay(speedDelay);
          }
      }
      if (servo06SP[i]==servo06SP[i+1]){}
      if(servo06SP[i]>servo06SP[i+1]){
        for ( int j = servo06SP[i]; j >= servo06SP[i + 1]; j--) {
            servo06.write(j);
            delay(speedDelay);
         }
      }
      if(servo06SP[i]<servo06SP[i+1]){
        for ( int j = servo06SP[i]; j <= servo06SP[i + 1]; j++) {
            servo06.write(j);
            delay(speedDelay);
          }
      }
    }
  }
}
