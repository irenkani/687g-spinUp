/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       irenka                                                    */
/*    Created:      Thu Sep 22 2022                                           */
/*    Description:  V5 project  spin up                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// flywheel             motor         8               
// roller               motor         10              
// leftF                motor         3               
// rightF               motor         4               
// leftB                motor         2               
// rightB               motor         1               
// intake               motor         9               
// piston               digital_out   H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
//including other files
#include "driverControl.h"    

void drB() {      //allows the different motors to spin forward/back depending on the position of the axis <-- bad comment will fix
  spinMotor(leftF, -100); 
  spinMotor(rightF, -100);
  spinMotor(leftB, -100);
  spinMotor(rightB, -100);
}

void drF() {      //allows the different motors to spin forward/back depending on the position of the axis <-- bad comment will fix
  spinMotor(leftF, 100); 
  spinMotor(rightF, 100);
  spinMotor(leftB, 100);
  spinMotor(rightB, 100);
}

void drR() {
  spinMotor(rightF, -100);
  spinMotor(rightB, 100);
  spinMotor(leftF, -100);
  spinMotor(leftB, 100);
}

void autonomous() {
  drR();
  wait(0.3, sec);
  leftF.stop();
  rightF.stop();
  leftB.stop();
  rightB.stop();

  wait(0.3, sec);

  spinMotor(roller, -100);
  drF();
  wait(0.7, sec);
  roller.stop();
  leftF.stop();
  rightF.stop();
  leftB.stop();
  rightB.stop();
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  autonomous();
  wait(3, msec);
  userControl();
}
