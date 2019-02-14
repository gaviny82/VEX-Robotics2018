pros::lcd::print(1, "Auto: 1 min @ back_red");

//move forward to collect the ball	[2000ms]
_set_onetime_task(0, collector.move(127));
_set_movement(127, 2800, 2800, 3000);
//turn over the cap
_set_onetime_task(300, IsAutoShootEnabled = false);
_set_onetime_task(0, collector.move(-127));
_set_onetime_task(1600, chassis.Drive(50, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
//move backward and adjust the position
_set_movement(100, -4700, -4700, 4800);
_set_onetime_task(1200, chassis.Drive(-30, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_movement(50, 300, 300, 700);
_set_onetime_task(0, IsAutoShootEnabled = true);
_set_movement(60, 580, -580, 1500);

//move to shooting position, then shoot	[1000ms]
_set_movement(80, -1010, -1010, 1200);
_set_movement(127, 45, -45, 1000);
_set_onetime_task(0, collector.move(0));
_set_onetime_task(2000, ShootSignal = SIG_SHOOT);
_set_movement(127, -40, 40, 500);

//rotate and switch the lower flag	[3300ms]
_set_movement(127, -2310, -2310, 2400);

_set_onetime_task(0, collector.move(127));
//move backward and rotate	[3000ms]
_set_movement(100, 1600, 1600, 1900);
_set_movement(100, -550, 550, 1000);
//turn over the caps	[4000ms]
_set_onetime_task(0, collector.move(-127));
_set_movement(100, 500, 500, 800);
_set_onetime_task(0, collector.move(-127));
_set_onetime_task(800, chassis.Drive(60, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_onetime_task(500, collector.move(0));
_set_movement(100, -2100, -2100, 2500);
_set_onetime_task(1200, chassis.Drive(-30, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_movement(50, 300, 300, 700);
_set_movement(60, 580, -580, 1500);
_set_movement(100, 2300, 2300, 2600);

#if 0
_set_movement(60, -580, 580, 1500);
_set_movement(100, -1500, -1500, 1800);

_set_onetime_task(2000, chassis.Drive(-20, 0));
_set_onetime_task(0, chassis.Drive(0, 0));

_set_movement(60, 500, 500, 800);
_set_movement(60, 580, -580, 1500);

_set_movement(100, -3000, -3000, 2800);
#endif