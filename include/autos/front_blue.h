pros::lcd::print(1, "Auto: front_blue");

//move forward to collect the ball	[2000ms]
_set_onetime_task(0, collector.move(127));
_set_movement(127, 3200, 3200, 2000);
//move backward	[2000ms]
_set_movement(100, -3100, -3100, 2000);
//rotate to aim at the flags	[950ms]
_set_movement(100, -620, 620, 950);
//move to shooting position, then shoot	[2700ms]
_set_movement(100, -1150, -1150, 1000);
_set_movement(127, -35, 35, 1200);
_set_onetime_task(0, collector.move(0));
_set_onetime_task(2000, ShootSignal = SIG_SHOOT);
_set_movement(95, 50, -50, 500);
//rotate and switch the lower flag	[2400ms]
_set_movement(127, -2170, -2170, 2400);

_set_onetime_task(0, collector.move(127));
//move backward and rotate	[2700ms]
_set_movement(127, 1700, 1700, 1700);
_set_movement(127, 500, -500, 1000);
//turn over the caps	[2800ms]
_set_onetime_task(0, collector.move(-127));
_set_movement(127, 2000, 2000, 1800);
_set_onetime_task(0, collector.move(0));
_set_movement(127, -500, -500, 1000);