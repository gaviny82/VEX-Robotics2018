pros::lcd::print(1, "Auto: new_front_red");

_set_onetime_task(0, arm_m = -90);//changeable
_set_onetime_task(0, collector.move(127));
_set_movement(90, 1400, 1400, 1400);
_set_onetime_task(0, arm_m = 0);
_set_movement(90, -200, -200, 400);

//back
_set_movement(90, 200, 200, 600);
_set_onetime_task(0, arm_m = 90);
_set_onetime_task(0, collector.move(0));
_set_movement(90, -1300, -1300, 1400);
_set_onetime_task(0, arm_m = 0);

//turning
_set_movement(100,9)
_set_onetime_task(200,chassis.Drive(0,0));

//shoot
_set_onetime_task(0, ShootSignal = SIG_SHOOT);
_set_onetime_task(200, collector.move(127));

//straight
_set_movement(127, 2400, 2400, 2000);

//shoot again
_set_onetime_task(200, ShootSignal = SIG_SHOOT);
_set_onetime_task(0, collector.move(127));
/*

//Third flag
_set_movement(127, 2000, 2000, 2500);
_set_movement(127,-3500, -3500, 3500);

//turning
_set_onetime_task(310, chassis.Drive(0, 127));
_set_onetime_task(0, chassis.Drive(0,0));
_set_onetime_task(500,chassis.Drive(-127, 0));
_set_onetime_task(0, chassis.Drive(0, 0));

//straight
_set_movement(127, 3500, 3500, 3500);
_set_movement(127, -400, -400, 400);

//turning
_set_onetime_task(200, chassis.Drive(0, -127))//45 degree
_set_onetime_task(0, chassis.Drive(0,0));
_set_onetime_task(0, collector.move(0));

//back
_set_movement(127, -1400, -1400, 1500);

//turning
_set_onetime_task(310, chassis.Drive(0, 127));//90 degree
_set_onetime_task(0, chassis.Drive(0, 0));
*/

//changeable
