#include "Arduino.h"
#include "ByteTransfer.h"

ByteTransfer::ByteTransfer(int SIGNALOUT,int DATAOUT,int SIGNALIN, int DATAIN){
  pinMode(SIGNALIN, INPUT);
  pinMode(DATAIN,INPUT);
  pinMode(SIGNALOUT,OUTPUT);
  pinMode(DATAOUT,OUTPUT);
  _SIGNALOUT = SIGNALOUT;
  _DATAOUT = DATAOUT;
  _SIGNALIN = SIGNALIN;
  _DATAIN = DATAIN;
}

void ByteTransfer::printBin(){
  if(digitalRead(_SIGNALIN)){
    Serial.println(digitalRead(_DATAIN));
    while(digitalRead(_SIGNALIN)){}
    return;
  }
}

void ByteTransfer::checkSerialMonitor(){
  if(Serial.available()){
    String message = Serial.readString();
    for(int i = 0; i < message.length(); i++){
      char myChar = message.charAt(i);
      for(int i = 7; i>= 0; i--){      
        if(bitRead(myChar,i)){
          sendSignal(1);
        } else{
          sendSignal(0);
        }
      } 
    }
  }
}

void ByteTransfer::sendSignal(int value){
  digitalWrite(_DATAOUT,value);
  digitalWrite(_SIGNALOUT,HIGH);
  delay(10);
  digitalWrite(_SIGNALOUT,LOW);
  delay(10); 
}