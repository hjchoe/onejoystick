/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jameschoe                                                 */
/*    Created:      Tue Sep 14 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;


// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// controller1          controller
// leftMotor            motor         14               
// rightMotor           motor         11               
// ---- END VEXCODE CONFIGURED DEVICES ----

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  int deadband = 5;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = controller1.Axis3.position() ^ 3 / 10000;
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = controller1.Axis2.position() ^ 3 / 10000;

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      leftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      leftMotor.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      rightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      rightMotor.setVelocity(rightMotorSpeed, percent);
    }

    // Spin both motors in the forward direction.
    leftMotor.spin(forward);
    rightMotor.spin(forward);

    wait(25, msec);
  }
}
