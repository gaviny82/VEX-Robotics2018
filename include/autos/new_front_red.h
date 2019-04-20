pros::lcd::print(1, "Auto: new_front_red");

//straight
_set_onetime_task(0, arm_m = -115);//changeable
_set_onetime_task(0, collector.move(115));
_set_movement_warm(100, 1050, 1050, 1400);
_set_onetime_task(800, arm_m = 0);
//_set_movement(80, -200, -200, 400);

//back
//_set_movement_warm(100, 100, 100, 600);
_set_onetime_task(0, arm_m = 30);
_set_onetime_task(0, collector.move(0));
_set_movement_warm(100, -1350, -1350, 1400);
_set_onetime_task(0, arm_m = 0);

//turning
_set_movement(100,-840,840,1000);

//shoot
_set_onetime_task(0, ShootSignal = SIG_SHOOT);
_set_onetime_task(200, collector.move(127));

//straight
_set_movement_warm(127, 1800, 1800, 2000);

//shoot again
_set_onetime_task(0, ShootSignal = SIG_SHOOT);

//Third flag
//_set_movement(100,-50,50,100)
_set_movement_warm(127, 700, 700, 1500);

_set_movement(127, -2300, -2300, 3000);
/*
//turning to the Cap
_set_movement(100, 310, -310, 600);

//back
_set_movement(100, -2000, -2000, 2000);
_set_movement(100, 600, 600, 600);

//turn and face the flag
_set_movement(100,-400,400,600)

//shoot

_set_onetime_task(0, ShootSignal = SIG_SHOOT)

//forward
_set_movement(100,1000,1000,1500)
*/
