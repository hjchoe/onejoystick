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
  vexcodeInit();

  while (true)
  {
    int updown = controller1.Axis3.position() ^ 3 / 20000;
    int leftright = controller1.Axis4.position() ^ 3 / 20000;

    int leftVelocity = 0;
    int rightVelocity = 0;

    leftVelocity = updown;
    rightVelocity = updown;

    if (updown == 0)
    {
      if (leftright > 0)
      {
        leftVelocity += abs(leftright);
        rightVelocity -= abs(leftright);
      }
      else if (leftright < 0)
      {
        rightVelocity += abs(leftright);
        leftVelocity -= abs(leftright);
      }
    }
    else if (updown > 0)
    {
      if (leftright > 0)
      {
        leftVelocity += abs(leftright);
      }
      else if (leftright < 0)
      {
        rightVelocity += abs(leftright);
      }
    }
    else if (updown < 0)
    {
      if (leftright > 0)
      {
        leftVelocity -= abs(leftright);
      }
      else if (leftright < 0)
      {
        rightVelocity -= abs(leftright);
      }
    }

    leftMotor.setVelocity(leftVelocity, percent);
    rightMotor.setVelocity(rightVelocity, percent);

    leftMotor.spin(forward);
    rightMotor.spin(forward);

    wait(25, msec);
  }
}
