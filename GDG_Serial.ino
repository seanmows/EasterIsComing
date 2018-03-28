#include <Servo.h>


Servo trigger;
Servo reloadRight;
Servo reloadLeft;

int val ; // define numeric variables val
int buttonpin = 3; // define Metal Touch Sensor Interface

void setup ()
{
  pinMode (buttonpin, INPUT) ; // define metal touch sensor output interface
  Serial.begin(9600);

  trigger.attach(10);
  reloadRight.attach(8);
  reloadLeft.attach(9);
  
}

void waitForButton() {
  //Waits For Button Push
  while(digitalRead(buttonpin) != 1) {};
  Serial.println("Button Pushed");
}
void restArms() {
  //Returns arms to Resting Position
  reloadRight.write(170);  
  reloadLeft.write(0);
  Serial.println("Arms Rested");
}
void reloadArms() {
  //Push arms back with rubberband to reload loaded position
  reloadRight.write(0); 
  reloadLeft.write(200); 
}
void loadTrigger() {
  //Puts trigger in veticle position to take load of Rubber band off reload arms
  trigger.write(0);
  Serial.println("Trigger Loaded");
}
void fireTrigger() {
  //Return Trigger to rest Position to let Rubber Band Go
  trigger.write(90`);
  Serial.println("Trigger Rest Position");
}

void loop ()
{   
    //Returns Arms to resting Position
    restArms();
    //Waits for Touch Sensor
    waitForButton();
    fireTrigger();
    reloadArms();
    //wait 3 seconds for Arms to go back with Rubber Band
    delay(3000);
    loadTrigger();
    //Wait One Second for Trigger to Take load
    delay(1000);
    restArms();
    //Wait 3 seconds for arms to clear firing range and go to rest
    delay(3000);
    //FIRE EASTER EGG
    fireTrigger();
    Serial.println("Fire!");
    delay(3000);



}
