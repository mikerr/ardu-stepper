#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
//const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
  Stepper myStepper(stepsPerRevolution,12,10,11,9);     // <<<<<<<<<<< Note 9 & 12 swapped
void setup() {
  // set the speed at 120 rpm:
  myStepper.setSpeed(120);                  //<<<<<<<<<<<<<<< 2BY-48 only gets around 11rpm with this
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
//**************************    
  for (int x=1;x<12;x++)                         //<<<<<<<<<<<<  we want to iterate to get a full revolution
  {
  myStepper.step(stepsPerRevolution);
  Serial.println(x);                                 //<<<<<<<<<<<< This is just for debugging
  }
//**************************    
  delay(500);
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
//**************************    
  for (int x =1;x<12;x++)
  {
  myStepper.step(-stepsPerRevolution);
  Serial.println(x);  
  }
//**************************  
  delay(500); 
}

