#include "test.hpp"
#include "lib/chassis.hpp"
#include "pros/llemu.hpp"
#include "main.h"

void Test::ChassisTest(Chassis &chassis){
  pros::lcd::print(0, "Going forward");
  chassis.Drive(127, 0);
  delay(1000);
  chassis.Stop();
  delay(500);

  pros::lcd::print(0, "Going backward");
  chassis.Drive(-127, 0);
  delay(1000);
  chassis.Stop();
  delay(500);

  pros::lcd::print(0, "Rotating anti-clockwise");
  chassis.Drive(0, 127);
  delay(1000);
  chassis.Stop();
  delay(500);

  pros::lcd::print(0, "Rotating clockwise");
  chassis.Drive(0, -127);
  delay(1000);
  chassis.Stop();
}

void Test::ControllerEventTest(){
    
}
