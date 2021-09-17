#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller controller1 = controller(primary);

motor leftMotor = motor(PORT14, ratio18_1, false);
motor rightMotor = motor(PORT11, ratio18_1, true);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  leftMotor.setStopping(brakeType::brake);
  rightMotor.setStopping(brakeType::brake);
}