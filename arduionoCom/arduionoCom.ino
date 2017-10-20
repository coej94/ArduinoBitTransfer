#include <ByteTransfer.h>

ByteTransfer byteTransfer(12,13,11,10);

void setup(){
  Serial.begin(9600);
}

void loop(){
  byteTransfer.checkSerialMonitor();
  byteTransfer.printBin();
}

//int SIGNALOUT = 12;
//int DATAOUT = 13;
//int SIGNALIN = 11;
//int DATAIN  = 10;
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(SIGNALIN, INPUT);
//  pinMode(DATAIN,INPUT);
//  pinMode(SIGNALOUT,OUTPUT);
//  pinMode(DATAOUT,OUTPUT);
//}
//
//
//void loop() {
//  checkSerialMonitor();
//  printBin();
//}
//
//
//void printBin(){
//  if(digitalRead(SIGNALIN)){
//    Serial.println(digitalRead(DATAIN));
//    while(digitalRead(SIGNALIN)){}
//    return;
//  }
//}
//
//void checkSerialMonitor(){
//  if(Serial.available()){
//    String message = Serial.readString();
//    for(int i = 0; i < message.length(); i++){
//      char myChar = message.charAt(i);
//      for(int i = 7; i>= 0; i--){      
//        if(bitRead(myChar,i)){
//          sendSignal(1);
//        } else{
//          sendSignal(0);
//        }
//      } 
//    }
//  }
//}
//
//void sendSignal(int value){
//  digitalWrite(DATAOUT,value);
//  digitalWrite(SIGNALOUT,HIGH);
//  delay(10);
//  digitalWrite(SIGNALOUT,LOW);
//  delay(10); 
//}
