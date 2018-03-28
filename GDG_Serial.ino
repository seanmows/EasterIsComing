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
  while(digitalRead(buttonpin) != 1) {};
//  while(digitalRead(buttonpin) == 1) {};
}

void loop ()
{
  // digital interface will be assigned a value of 3 to read val
//  waitForButton();
  Serial.println("fuk");
//  reloadRight.write(120); // 
//  reloadLeft.write(150); // 0 is bottom 180
//  delay(3000);
  trigger.write(0); // 0 is loaded, 90 is fired


}
