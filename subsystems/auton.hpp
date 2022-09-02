#include "main.h"

using namespace okapi;

extern Encoder left;
extern Encoder right;
extern Encoder middle;

extern double rPrev;
extern double lPrev;

extern void autontest1();
extern void driveForward(double relativeDistance);
extern void odomRotate(double relativeAngle);
extern double convertAngleToRotation(double angle);
extern double convertLengthToRotation(double distance);