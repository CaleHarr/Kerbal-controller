
#include "Keyboard.h"
//Need to use raspberry pi instead of Elegoo uno R3
//Using older button sketch that doesn't quite work right (potentially, issue might be break at end of countdown function)

//Source for countdown timer section:https://circuitdigest.com/microcontroller-projects/7-segment-display-interfacing-with-arduino
// Source for button wiring: https://docs.arduino.cc/tutorials/micro/keyboard-press
//Button code from Arduino Make book, sat on drive

//Pin 9 being used for button, think about wiring up in parallel as running out of grounds
#define segA 2//connecting segment A to PIN2
#define segB 3// connecting segment B to PIN3
#define segC 4// connecting segment C to PIN4
#define segD 5// connecting segment D to PIN5
#define segE 6// connecting segment E to PIN6
#define segF 7// connecting segment F to PIN7
#define segG 8// connecting segment G to PIN8 
                int COUNT=9;//count integer for 0-9 increment
                //int COUNT=0;//count integer for 0-9 increment
const int BUTTON=9; //input pin where button connected
int val=0; //val stores state of input pin
int val_store=0;;
void setup()
{
                  pinMode(BUTTON,INPUT);//and BUTTON is an input

                  for (int i=2;i<9;i++)

                  {

                                    pinMode(i, OUTPUT);// taking all pins from 2-8 as output

                  }

}

 

void loop()

{
  val=digitalRead(BUTTON);//read imput value and store it
if (val==HIGH&&val_store==LOW){
  val_store=HIGH;
  countdown(COUNT);
  delay(10);
 }
else if (val==LOW&&val_store==HIGH){
  countdown(COUNT);
  delay(10);

 }
else if (val==HIGH&&val_store==HIGH){
 val_store=LOW;
 countdown(COUNT);
 delay(10);
 }
 else if (val==LOW&&val_store==LOW){
  delay(10);
 }
//countdown(COUNT);
}


int countdown(int x){
                switch ( x)

                {
                case 0://when count value is zero show”0” on disp
                digitalWrite(segA, HIGH);
                digitalWrite(segB, HIGH);
                digitalWrite(segC, HIGH);
                digitalWrite(segD, HIGH);
                digitalWrite(segE, HIGH);
                digitalWrite(segF, HIGH);
                digitalWrite(segG, LOW);
                Keyboard.release(97);
                break;

 

                case 1:// when count value is 1 show”1” on disp
                digitalWrite(segA, LOW);
                digitalWrite(segB, HIGH);

                digitalWrite(segC, HIGH);
                digitalWrite(segD, LOW);
                digitalWrite(segE, LOW);

                digitalWrite(segF, LOW);

                digitalWrite(segG, LOW);

                break;

 

                case 2:// when count value is 2 show”2” on disp

                digitalWrite(segA, HIGH);

                digitalWrite(segB, HIGH);

                digitalWrite(segC, LOW);

                digitalWrite(segD, HIGH);

                digitalWrite(segE, HIGH);

                digitalWrite(segF, LOW);

                digitalWrite(segG, HIGH);

                break;

 

                case 3:// when count value is 3 show”3” on disp

                digitalWrite(segA, HIGH);

                digitalWrite(segB, HIGH);

                digitalWrite(segC, HIGH);

                digitalWrite(segD, HIGH);

                digitalWrite(segE, LOW);

                digitalWrite(segF, LOW);

                digitalWrite(segG, HIGH);

                break;

 

                case 4:// when count value is 4 show”4” on disp

                digitalWrite(segA, LOW);

                digitalWrite(segB, HIGH);

                digitalWrite(segC, HIGH);

                digitalWrite(segD, LOW);

                digitalWrite(segE, LOW);

                digitalWrite(segF, HIGH);

                digitalWrite(segG, HIGH);

                break;

 

                case 5:// when count value is 5 show”5” on disp

                digitalWrite(segA, HIGH);

                digitalWrite(segB, LOW);

                digitalWrite(segC, HIGH);

                digitalWrite(segD, HIGH);

                digitalWrite(segE, LOW);

                digitalWrite(segF, HIGH);

                digitalWrite(segG, HIGH);

                break;

 

                case 6:// when count value is 6 show”6” on disp

                digitalWrite(segA, HIGH);

                digitalWrite(segB, LOW);

                digitalWrite(segC, HIGH);

                digitalWrite(segD, HIGH);

                digitalWrite(segE, HIGH);

                digitalWrite(segF, HIGH);

                digitalWrite(segG, HIGH);

                break;

 

                case 7:// when count value is 7 show”7” on disp

                digitalWrite(segA, HIGH);

                digitalWrite(segB, HIGH);

                digitalWrite(segC, HIGH);

                digitalWrite(segD, LOW);

                digitalWrite(segE, LOW);

                digitalWrite(segF, LOW);

                digitalWrite(segG, LOW);

                break;

 

                case 8:// when count value is 8 show”8” on disp

                digitalWrite(segA, HIGH);

                digitalWrite(segB, HIGH);

                digitalWrite(segC, HIGH);

                digitalWrite(segD, HIGH);

                digitalWrite(segE, HIGH);

                digitalWrite(segF, HIGH);

                digitalWrite(segG, HIGH);

                break;

 

                case 9:// when count value is 9 show”9” on disp

                digitalWrite(segA, HIGH);

                digitalWrite(segB, HIGH);

                digitalWrite(segC, HIGH);

                digitalWrite(segD, HIGH);

                digitalWrite(segE, LOW);

                digitalWrite(segF, HIGH);

                digitalWrite(segG, HIGH);

                break;

 

                break;

                }

                if (COUNT<10)

                {
                                //COUNT++;

                                COUNT--;

                                delay(1000);///increment count integer for every second

                }

                if (COUNT==10)

                {

                               
                                //COUNT=0;// if count integer value is equal to 10, reset it to zero.
                                //break;
                                //delay(1000);

                }
                
}
