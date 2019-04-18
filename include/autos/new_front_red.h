pros::lcd::print(1, "Auto: new_front_red");

//shoot
_set_onetime_task(500, ShootSignal = SIG_SHOOT);
_set_onetime_task(0, arm.move(127));

//turning
_set_onetime_task(500, chassis.Drive(50,-50));//135 degree
_set_onetime_task(500, chassis.Drive(0,0));

//straight
_set_onetime_task(0, arm.move(0);//需要保证在到达球后面之前arm不要落地
_set_movement(127, 500, 500, 1000);
_set_onetime_task(500, arm.move(127))；
_set_onetime_task(0, arm.move(0));
_set_movement(127, -200, -200, 400);

//back
_set_onetime_task(0, collector.move(127));
_set_movement(127, 100, 100, 200);
_set_movement(127, -400, -400, 800);
_set_onetime_task(0, collector.move(0));

//turning
_set_onetime_task(500,chassis.Drive(-50,50));//135 degree
_set_onetime_task(0,chassis.Drive(0,0));

//straight
_set_movement(127, 500, 500, 1000);
_set_onetime_task(127,ShootSignal = SIG_SHOOT);

//Third flag
_set_movement(127, 500, 500, 1000);
_set_movement(127,-1000, -1000, 2000);

//turning
_set_onetime_task(1000, chassis.Drive(100, -100));
_set_onetime_task(0, chassis.Drive(0,0));

//straight
_set_onetime_task(0, collector.move(127));
_set_movement(127, 1000, 1000, 2000);
_set_movement(127, -100, -100, 200);

//turning
_set_onetime_task(500, chassis.Drive(50, -50))//45 degree
_set_onetime_task(0, chassis.Drive(0,0));
_set_onetime_task(0, collector.move(0));

//back
_set_movement(127, -700, -700, 1500);

//turning
_set_onetime_task(500, chassis.Drive(-50, 50));//90 degree


//changeable
