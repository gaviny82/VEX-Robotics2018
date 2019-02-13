pros::lcd::print(1, "Auto: front_red");

//move forward to collect the ball
_set_onetime_task(0, collector.move(127));
_set_movement(127,3200,3200,2000);
//move backward
_set_movement(127,-3000,-3000,1900);		
//rotate to aim at the flags
_set_movement(127,-550,550,1000);
_set_onetime_task(0, collector.move(0));
//move to shooting position, then shoot
_set_movement(100,-1000,-1000,1000);
_set_onetime_task(2000, ShootSignal = SIG_SHOOT);

_set_movement(127,+50,-50,300);
_set_movement(127,-2500,-2500,3000);

_set_onetime_task(0, collector.move(127));
_set_movement(127,1700,1700,2000);
_set_movement(127,500,-500,1000);
_set_onetime_task(0, collector.move(-127));
_set_movement(127,2000,2000,2000);
_set_onetime_task(0, collector.move(0));
_set_movement(127,-500,-500,2000);