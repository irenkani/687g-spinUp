#include "vex.h"
//#include "driverControl.h"

using namespace vex;

void spinmotor(motor m, int velocity ) {
  m.setVelocity(velocity, pct);
  m.spin(forward);
}
void drF() {      //allows the different motors to spin forward/back depending on the position of the axis <-- bad comment will fix
  spinmotor(leftF, 100); 
  spinmotor(rightF, 100);
  spinmotor(leftB, 100);
  spinmotor(rightB, 100);
}

void drB() {      //allows the different motors to spin forward/back depending on the position of the axis <-- bad comment will fix
  spinmotor(leftF, -100); 
  spinmotor(rightF, -100);
  spinmotor(leftB, -100);
  spinmotor(rightB, -100);
}

void spinL() {
  spinmotor(leftF, -100); 
  spinmotor(rightF, 100);
  spinmotor(leftB, 100);
  spinmotor(rightB, 100);
}

void drR() {
  spinmotor(rightF, -100);
  spinmotor(rightB, 100);
  spinmotor(leftF, -100);
  spinmotor(leftB, 100);
}


void auton(void) {
  drR();
  wait(0.22, sec);
  leftF.stop();
  rightF.stop();
  leftB.stop();
  rightB.stop();
  spinmotor(roller, -100);
  drF();
  wait(0.1, sec);
  roller.stop();
  leftF.stop();
  rightF.stop();
  leftB.stop();
  rightB.stop();
}