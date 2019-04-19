pros::lcd::print(1, "Auto: new_front_blue_fake");

//straight
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
_set_movement(100,970,-970,1000);

//shoot
_set_onetime_task(0, ShootSignal = SIG_SHOOT);
_set_onetime_task(200, collector.move(127));

//straight
_set_movement(127, 2400, 2400, 2000);

//shoot again
_set_onetime_task(0, ShootSignal = SIG_SHOOT);
_set_onetime_task(0, collector.move(127));

//Third flag
_set_movement(127, 2000, 2000, 2500);
_set_movement(127,-1000, 1000, 1000);

//turning to the Cap
_set_movement(100, 310, -310, 600);

//back
_set_movement(100, -2000, -2000, 2000);
_set_movement(100, 600, 600, 600);

//turn and face the flag
_set_movement(100,-400,400,600)

//shoot
_set_movement(0,0,0,0)
_set_onetime_task(0, ShootSignal = SIG_SHOOT)

//forward
_set_movement(100,1000,1000,1500)
