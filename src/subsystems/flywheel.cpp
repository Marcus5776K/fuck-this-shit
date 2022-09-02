#include "main.h"

using namespace okapi;

bool released3 = true;
bool released4 = true;
bool toggle3 = false;
bool toggle4 = false;

Motor flywheel(flywheelPort,false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);


int prevError = 0;

int LOWSPEED = 425;
int HIGHSPEED = 475;


void updateFlywheel()
{


  if (!released1 || !released2) {
bool released3 = true;
bool released4 = true;
bool toggle3 = false;
bool toggle4 = false;
flywheel.moveVelocity(0);    
  }

    if (controller.getDigital(ControllerDigital::L1) == 0)
    {
      released3 = true;
    }


    if (controller.getDigital(ControllerDigital::L1) == 1 && released3)
    {
      released3 = false;

      toggle4 = false;
      released4 = true;

      if (!toggle3){
        flywheel.moveVelocity(600);
        toggle3 = true;
      } else if (toggle3){
        flywheel.moveVelocity(0);
        toggle3 = false;

      }
    
    }

    if (controller.getDigital(ControllerDigital::L2) == 0)
    {
      released4 = true;
    }

    if (controller.getDigital(ControllerDigital::L2) == 1 && released4){
      released4 = false;

      toggle3 = false;
      released3 = true;
    
      if (!toggle4){
        flywheel.moveVelocity(400);
        toggle4 = true;
      } else if (toggle4){
        flywheel.moveVelocity(0);
        toggle4 = false;

      }
    }
  
    if (toggle4) {
      double kP = 0.05;
      double ki = 0.0;
      double kd = 0.1;

      int error = HIGHSPEED-50-flywheel.getActualVelocity();
      int integral = integral + error;
      int derivative = error - prevError;
      int prevError = error;
      int p = error * kP;
      int i = integral * ki;
      int d = derivative * kd;
    
      flywheel.moveVelocity(HIGHSPEED+p+i+d);
    
    }
    else if (toggle3) {
      double kP = 0.05;
      double ki = 0.0;
      double kd = 0.1;

      int error = LOWSPEED-50-flywheel.getActualVelocity();
      int integral = integral + error;
      int derivative = error - prevError;
      int prevError = error;
      int p = error * kP;
      int i = integral * ki;
      int d = derivative * kd;
    
      flywheel.moveVelocity(LOWSPEED+p+i+d);
    
    }
}
  
