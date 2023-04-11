// Set a Pass then get an input and say 8888 or 1 



#include "SevSeg.h"
SevSeg sevseg; 

int pass=0;
int input=0;


void setup() {
    byte numDigits = 4;  
    byte digitPins[] = {2, 3, 4, 5};
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
    bool resistorsOnSegments = 0;
    //sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    //sevseg.setBrightness(0);


    pinMode(A0, OUTPUT);           
    digitalWrite(A0, LOW);   
    pinMode(A1, OUTPUT);           
    digitalWrite(A1, LOW); 
    pinMode(A2, OUTPUT);           
    digitalWrite(A2, LOW); 
    pinMode(A3, OUTPUT);           
    digitalWrite(A3, LOW); 
    pinMode(A4, OUTPUT);           
    digitalWrite(A4, LOW); // set pin
    pinMode(A5, OUTPUT);           
    digitalWrite(A5, LOW); // debug pin
    



}
void loop() {

  while(1) {
    sevseg.setNumber(pass);
    sevseg.refreshDisplay(); 
    if (digitalRead(A0) == 1) {
      pass=pass+1000;
      delay(200);
    }
    if (digitalRead(A1) == 1) {
      pass=pass+100;
      delay(200);
    }
    if (digitalRead(A2) == 1) {
      pass=pass+10;
      delay(200);
    }
    if (digitalRead(A3) == 1) {
      pass=pass+1;
      delay(200);
    }
    if (pass > 9999) {
      pass=0;
    }
    if (digitalRead(A4) == 1) {
      delay(400);
      break;
    }
  }
  
  
  
  
  
  //input

  while(1) {
    sevseg.setNumber(input);
    sevseg.refreshDisplay(); 
    if (digitalRead(A0) == 1) {
      input=input+1000;
      delay(200);
    }
    if (digitalRead(A1) == 1) {
      input=input+100;
      delay(200);
    }
    if (digitalRead(A2) == 1) {
      input=input+10;
      delay(200);
    }
    if (digitalRead(A3) == 1) {
      input=input+1;
      delay(200);
    }
    if (input > 9999) {
      input=0;
    }
    if (digitalRead(A4) == 1) {
      break;
    }
  }


  //control
  digitalWrite(A5, HIGH);
  if (pass == input){
    digitalWrite(A5, LOW);
    while(1){
      sevseg.setNumber(1);
      sevseg.refreshDisplay(); 
    }
  } else{
    digitalWrite(A5, LOW);
    while(1){
      sevseg.setNumber(8888);
      sevseg.refreshDisplay(); 
      delay(20);
    }
  }

}