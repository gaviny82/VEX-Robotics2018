pros::lcd::print(1, "Auto: new_back_red");

//shoot
_set_onetime_task(500, ShootSignal = SIG_SHOOT);

//turning
_set_onetime_task(500, chassis.Drive(50, -50));
_set_onetime_task(0, chassis.Drive(0, 0));

//straight
_set_onetime_task(0, collector.move(127));
_set_movement(127, 1000, 1000, 2000);
_set_movement(127, -100, -100, 200);

//turning
_set_onetime_task(500, chassis.Drive(-50, 50));
_set_onetime_task(0, collector.move(0));
_set_onetime_task(0, chassis.Drive(0,0));


//backward & forward
_set_movement(127, -600, -600, 1200);
_set_movement(127, 600, 600, 1200);
_set_onetime_task(0, collector.move(0));

//turning
_set_onetime_task(500, chassis.Drive(50, -50));
_set_onetime_task(0, chassis.Drive(0, 0));

//go up
_set_movement(127, 500, 500, 2000);
