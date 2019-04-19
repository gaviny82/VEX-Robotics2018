pros::lcd::print(1, "Auto: new_back_blue");

//shoot
_set_onetime_task(500, ShootSignal = SIG_SHOOT);

//fetch a ball
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
_set_onetime_task(150, chassis.Drive(0, -127));
_set_onetime_task(0, chassis.Drive(0, 0));

//straight
_set_onetime_task(0, collector.move(127));
_set_movement(127, 3500, 3500, 3500);
_set_movement(127, -400, -400, 400);

//turning
_set_onetime_task(450, chassis.Drive(0, 127));
_set_onetime_task(0, collector.move(0));
_set_onetime_task(0, chassis.Drive(0,0));


//backward & forward
_set_movement(127, -2200, -2200, 2200);
_set_movement(127, 2200, 2200, 2200);
_set_onetime_task(0, collector.move(0));

//turning
_set_onetime_task(100, chassis.Drive(0, 127));
_set_onetime_task(0, chassis.Drive(0, 0));

//go up
_set_movement(127, 2000, 2000, 2000);


//fact
/*
_set_movement(127, 1000, 1000, 2000);//(motor, left, right, time)
_set_onetime_task(1000, collector.move(127));//timedelay, move collector
_set_onetiem_task(0, chassis.Drive(-127,127));//timedelay, left motor,right motor
_set_onetime_task(1000, collector.move(0));//stop collector
_set_onetime_task(0, chassis.Drive(0, 0));//stop left and right motor
_set_onetime_task(1000, ShootSignal = SIG_SHOOT);//shoot
_set_onetime_task(1000, arm_m = -127);
*/
