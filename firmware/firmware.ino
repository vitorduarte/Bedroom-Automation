#include <IRremote.h>

IRrecv irrecv(11); // Receive on pin 11
decode_results results;

//RGB Led
const int pinRed = 6;
const int pinGreen = 7;
const int pinBlue = 5;

//Room's Light
const int pinLight = 3;

void setPins(){
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinLight, OUTPUT);
  pinMode(52,OUTPUT);
}

void setup(){
  setPins();
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
   digitalWrite(52,HIGH);
   if(irrecv.decode(&results)){
    Serial.print(control(results.value));
    lightOn(control(results.value));
    irrecv.resume();
   }
}



  

