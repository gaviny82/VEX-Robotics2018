pros::lcd::print(1, "Auto: front_blue");

//move forward to collect the ball	[2000ms]
_set_onetime_task(0, collector.move(127));
_set_movement(127, 3200, 3200, 2000);
//move backward	[1900ms]
_set_movement(127, -3100, -3100, 1900);
//rotate to aim at the flags	[950ms]
_set_movement(127, -580, 580, 950);
//move to shooting position, then shoot	[1000ms]
_set_movement(100, -920, -920, 1000);
_set_movement(127, -20, 20, 1000);
_set_onetime_task(0, collector.move(0));
_set_onetime_task(2000, ShootSignal = SIG_SHOOT);
_set_movement(127, 40, -40, 500);
//rotate and switch the lower flag	[3300ms]
_set_movement(127, -2400, -2400, 2400);

_set_onetime_task(0, collector.move(127));
//move backward and rotate	[3000ms]
_set_movement(127, 1700, 1700, 1700);
_set_movement(127, 500, -500, 1000);
//turn over the caps	[4000ms]
_set_onetime_task(0, collector.move(-127));
_set_movement(127, 2000, 2000, 1800);
_set_onetime_task(0, collector.move(0));
_set_movement(127, -500, -500, 1000);