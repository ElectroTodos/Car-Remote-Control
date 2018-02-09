#include <IRremote.h>
#include "LowPower.h"
IRsend irsend;

#define B1 4
#define B2 5
#define B3 6
#define B4 7
#define B5 8



/*#define BON 0xF738C7 //On
#define BUP 0xF77887 //Up
#define BDOWN 0xF7609F //Down
#define BLEFT 0xF7807F //Left
#define BRIGHT 0xF7C03F //Right*/
#define BPLAY 0xF740BF //PlayPause
//#define BMODE 0xF700FF //Mode
//#define BUSB 0xF720DF //USBSD
#define BVOLUP 0xF7D02F //VOL+
#define BVOLDOWN 0xF7906F //Vol-
//#define BSEL 0xF750AF //Sel
#define BNEXT 0xF7E01F //Next
#define BPREV 0xF7A05F //Prev
/*#define BBAND 0xF710EF //Band
#define BANS 0xF7F00F //Ans
#define BHUNGUP 0xF7C837 //Hung*/


int timer;

void wakeUp(){
 timer = 0;
}

void setup() {
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
  pinMode(B5, INPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  
  timer = 0;
}

void loop() {
  attachInterrupt(0,wakeUp, HIGH);
  while (timer < 2000){
          //digitalWrite(LED_BUILTIN,HIGH);
            if(digitalRead(B1)){
              timer = 0;  
              delay(50);
              irsend.sendNEC(BPLAY, 32);
            } //PlayPause
          
            if(digitalRead(B2)){
              timer = 0;
              delay(50);
              irsend.sendNEC(BVOLUP, 32);
             } //Vol+
          
            if(digitalRead(B3)){
              timer = 0;
              delay(50);
              irsend.sendNEC(BVOLDOWN, 32);
            } //Vol-
      
             if(digitalRead(B4)){
              timer = 0;
              delay(50);
              irsend.sendNEC(BNEXT, 32);
            } //Vol-
      
             if(digitalRead(B5)){
              timer = 0;
              delay(50);
              irsend.sendNEC(BPREV, 32);
            } //Vol-
            
             delay(1);
             timer = timer + 1;
      }
  //digitalWrite(LED_BUILTIN,LOW);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  
}
