#include "main.h"

pros::ADIEncoder leftEncoder ('A', 'B', false);
pros::ADIEncoder rightEncoder ('C', 'D', false);
pros::ADIEncoder middleEncoder ('E', 'F', false);

int prevErrorLeftDrive = 0;

namespace auton {

double convertLengthToRotation(double distance) {
    return distance/8/3.14159*360;
}

double convertAngleToRotation(double angle) {
    return convertLengthToRotation(6.5*2*3.14159*angle/360);
}


void driveForward(double relativeDistance) {
    int l = 0;
    int r = 0;
    int m = 0;

    int targetL = l+convertLengthToRotation(relativeDistance);
    int targetR = r+convertLengthToRotation(relativeDistance);

    while (true) {
      double kP = 0.03;
      double ki = 0.0;
      double kd = 0.1;

      int error = targetL-l;
      int integral = integral + error;
      int derivative = error - prevErrorLeftDrive;
      int prevErrorLeftDrive = error;
      int p = error * kP;
      int i = integral * ki;
      int d = derivative * kd;
    
    
    }

}
void odomRotate(double relativeAngle) {

}


void autontest1() {

}


}