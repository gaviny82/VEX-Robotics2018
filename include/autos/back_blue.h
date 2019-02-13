pros::lcd::print(1, "Auto: back_blue");

//move forward to collect the ball	[2000ms]
_set_onetime_task(0, collector.move(127));
_set_movement(127, 3200, 3200, 2000);
//move backward	[2000ms]
_set_movement(127, -750, -750, 1800);
//rotate
_set_movement(127, -500, 500, 800);
_set_onetime_task(0, collector.move(0));
//adjust position
_set_onetime_task(1000, chassis.Drive(-30, 0));
//
_set_onetime_task(800, chassis.Drive(-105, 0));
_set_onetime_task(20, chassis.Drive(40, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_onetime_task(0, chassis.SetMotorsRelativeL(0, 127); chassis.SetMotorsRelativeR(0, 127));
