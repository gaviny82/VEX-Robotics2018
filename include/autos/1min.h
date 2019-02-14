pros::lcd::print(1, "Auto: 1 min @ front_red");

//move forward to collect the ball	[2000ms]
_set_onetime_task(0, collector.move(127));
_set_movement(127, 2800, 2800, 3000);
//turn over the cap
//_set_onetime_task(300, IsAutoShootEnabled = false);
_set_onetime_task(0, collector.move(-127));
_set_onetime_task(1600, chassis.Drive(50, 0));
_set_onetime_task(500, chassis.Drive(0, 0));
_set_movement(100, -500, -500, 700);
_set_movement(60, -580, 580, 1500);
_set_onetime_task(2000, chassis.Drive(-30, 0));
_set_onetime_task(200, chassis.Drive(0, 0));
_set_movement(60, 300, 300, 700);
_set_movement(40, 580, -580, 2000);

//move backward and adjust the position
_set_movement(70, -4200, -4200, 6000);
_set_onetime_task(1200, chassis.Drive(-30, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_movement(50, 300, 300, 700);
_set_onetime_task(0, IsAutoShootEnabled = true);
_set_movement(60, 580, -580, 1500);

//move to shooting position, then shoot	[1000ms]
_set_movement(80, -950, -950, 1200);
_set_movement(127, 45, -45, 1000);
_set_onetime_task(0, collector.move(0));
_set_onetime_task(2000, ShootSignal = SIG_SHOOT);
_set_movement(127, -55, 55, 500);

//rotate and switch the lower flag	[3300ms]
_set_movement(127, -2200, -2200, 2400);

_set_onetime_task(0, collector.move(127));
//move backward and rotate	[3000ms]
_set_movement(100, 1570, 1570, 1900);
_set_movement(100, -550, 550, 1000);
//turn over the caps	[4000ms]
_set_onetime_task(0, collector.move(-127));
_set_movement(100, 500, 500, 800);
_set_onetime_task(800, chassis.Drive(60, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_onetime_task(500, collector.move(0));

_set_movement(100, -2100, -2100, 2500);
_set_onetime_task(1200, chassis.Drive(-30, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_movement(50, 300, 300, 700);
_set_movement(60, 580, -580, 1500);

_set_movement(100, 3200, 3200, 3500);
_set_movement(60, 580, -580, 2000);
_set_onetime_task(2000, chassis.Drive(-30, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
//
_set_onetime_task(1000, chassis.Drive(-105, 0));
_set_onetime_task(20, chassis.Drive(40, 0));
_set_onetime_task(1000, chassis.Drive(0, 0));

_set_onetime_task(1500, chassis.Drive(-30, 0));
//2nd platform
_set_onetime_task(900, chassis.Drive(-105, 0));
_set_onetime_task(20, chassis.Drive(40, 0));
_set_onetime_task(0, chassis.Drive(0, 0));
_set_onetime_task(0, chassis.SetMotorsRelativeL(0, 127); chassis.SetMotorsRelativeR(0, 127));
