#include "vex.h"

using namespace vex;

void spinM(motor m, int velocity, float waitTime){         //function to set velocity and spin motors using the motor, wait time, and velocity pct as parameters
  m.setVelocity(velocity,pct);
  m.spin(forward);
  wait(waitTime, sec);
  m.stop();
}

void spinMotor(motor m, int velocity){         //function to set velocity and spin motors using the motor, wait time, and velocity pct as parameters
  m.setVelocity(velocity, pct);
  m.spin(forward);
}

void intakeSpin() {           //function that allows the intake motor to continously run when one button is clicked
  spinMotor(intake, 100);
}

void intakeStop() {           //function that allows the intake motor to stop spinning when one button is clicked
  intake.stop();
}

void flywheelSpin() {         //function that allows the flywheel motor to continously run when one button is clicked
  spinMotor(flywheel, 100);
}

void flywheelStop() {         //function that allows the flywheel motor to stop spinning when one button is clicked
  flywheel.stop();
}

void dr(int verticalVelocity, int horizontalVelocity, int turning) {      //allows the different motors to spin forward/back depending on the position of the axis <-- bad comment will fix
  spinMotor(leftF, (verticalVelocity + horizontalVelocity + turning)); 
  spinMotor(rightF, (verticalVelocity - horizontalVelocity - turning));
  spinMotor(leftB, (verticalVelocity - horizontalVelocity + turning));
  spinMotor(rightB, (verticalVelocity + horizontalVelocity - turning));
}

void userControl(void){

  Controller1.ButtonX.pressed(intakeSpin);
  Controller1.ButtonB.pressed(intakeStop);
  Controller1.ButtonR1.pressed(flywheelSpin);
  Controller1.ButtonR2.pressed(flywheelStop);

  while(1){
    
    dr(Controller1.Axis2.position(pct), Controller1.Axis1.position(pct), Controller1.Axis4.position(pct));
    
    if(Controller1.ButtonUp.pressing()){
      spinMotor(roller, -100);
    }
    if(Controller1.ButtonDown.pressing()) {
      roller.stop();
    }
    
    //when L1 is pressing, release the pneumatics
    if(Controller1.ButtonL1.pressing()) {
      piston.set(true);
    }else{
      piston.set(false);
    }


  }
}
  