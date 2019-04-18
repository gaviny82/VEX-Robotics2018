pros::lcd::print(1, "Auto: new_back_blue");

//shoot
_set_onetime_task(500, ShootSignal = SIG_SHOOT);

//turning
_set_onetime_task(500, chassis.Drive(-50, 50));
_set_onetime_task(0, chassis.Drive(0, 0));

//straight
_set_onetime_task(0, collector.move(127));
_set_movement(127, 1000, 1000, 2000);
_set_movement(127, -100, -100, 200);

//turning
_set_onetime_task(500, chassis.Drive(50, -50));
_set_onetime_task(0, collector.move(0));
_set_onetime_task(0, chassis.Drive(0,0));


//backward & forward
_set_movement(127, -600, -600, 1200);
_set_movement(127, 600, 600, 1200);
_set_onetime_task(0, collector.move(0));

//turning
_set_onetime_task(500, chassis.Drive(-50, 50));
_set_onetime_task(0, chassis.Drive(0, 0));

//go up
_set_movement(127, 500, 500, 2000);


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
