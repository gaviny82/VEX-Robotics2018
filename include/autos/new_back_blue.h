pros::lcd::print(1, "Auto: new_back_blue");



//rise the arm
_set_movement_warm(127,-1600,-1600,2000);
_set_movement(100,-680,500,600);
_set_onetime_task(1000,chassis.Drive(-60,0));
_set_onetime_task(0, chassis.Drive(0,0));
_set_onetime_task(0,_arm_up);

//turn over the plate
_set_movement_warm(100, 2700, 2700, 3000);
_set_onetime_task(500,)
//_set_onetime_task(0,collector.move(110))
_set_movement_warm(100, -1400, -1400, 2000);
_set_onetime_task(1000, );
//_set_onetime_task(0,collector.move(0))
_set_movement(100,250,-250,400);
_set_onetime_task(0,_arm_down);
_set_onetime_task(0,collector.move(110));
_set_movement_warm(60,2200,2200,2500);
//_set_onetime_task(0,collector.move(0));
_set_movement_warm(60,-700,-700,900);
_set_onetime_task(0,_arm_back);
_set_movement(100,380,-380,500);
_set_onetime_task(500,chassis.Drive(80,0));
_set_onetime_task(0,chassis.Drive(0,0));
_set_movement(60,-300,0,800);
_set_onetime_task(300,ShootSignal = SIG_SHOOT);
_set_onetime_task(0, collector.move(110));
_set_movement_warm(100,-800,-800,1000);
_set_onetime_task(300, collector.move(0));
_set_onetime_task(200,ShootSignal = SIG_SHOOT);
_set_onetime_task(1300,chassis.Drive(127,0))
