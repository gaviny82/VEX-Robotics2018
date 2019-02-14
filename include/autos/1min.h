pros::lcd::print(1, "Auto: 1 min @ back_red");

//move forward to collect the ball	[2000ms]
_set_onetime_task(0, collector.move(127));
_set_movement(127, 2800, 2800, 3000);
//turn over the cap
_set_onetime_task(300, IsAutoShootEnabled = false);
_set_onetime_task(0, collector.move(-127));
_set_movement(60, 2000, 2000, 4000);
//move backward and adjust the position
_set_movement(127, -4900, -4900, 4800);
_set_movement(40, -300, -300, 2000);
