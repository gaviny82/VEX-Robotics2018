pros::lcd::print(1, "Auto: new_back_blue");



//rise the arm
_set_onetime_task(800,collector.move(110));
_set_onetime_task(200,ShootSignal = SIG_SHOOT);
_set_onetime_task(100,collector.move(0));
_set_movement(100,220,-220,200);
_set_movement_warm(110,-1600,-1600,2000);
_set_movement(100,-680,500,600);
_set_onetime_task(1000,chassis.Drive(-60,0));
_set_onetime_task(0, chassis.Drive(0,0));
_set_onetime_task(0,_arm_up);

//turn over the plate
_set_delayed_task(1000,_arm_down);
_set_movement_warm(100, 2700, 2700, 3000);
_set_onetime_task(500,)
_set_onetime_task(0,collector.move(110))
_set_movement_warm(90, -1100, -1100, 2000);
_set_movement_warm(100,-300,-300,600);
_set_onetime_task(1000,);
//_set_onetime_task(0,collector.move(0))
_set_movement(100,250,-250,400);
_set_onetime_task(0,_arm_down);
_set_onetime_task(0,collector.move(110));
_set_movement_warm(50,2200,2200,2500);
//_set_onetime_task(0,collector.move(0));
_set_movement_warm(50,-700,-700,900);
_set_onetime_task(0,_arm_back);
_set_movement(100,380,-380,500);
_set_onetime_task(1250,chassis.Drive(127,0))
_set_onetime_task(0,chassis.Drive(0,0));
/*
_set_onetime_task(0,collector.move(0))
_set_onetime_task(400,ShootSignal = SIG_SHOOT);
_set_movement(100,100,-400,500);
_set_onetime_task(500,chassis.Drive(-60,0));
_set_onetime_task(0,chassis.Drive(0,0));
_set_movement_warm(100,1000,1000,1200);
_set_movement(50,-300,300,500);
_set_onetime_task(500,);
_set_movement(50,300,-300,500);
_set_onetime_task(0,collector.move(110));



//correct the position with the wall
_set_movement(100, -400, 400, 500);
_set_onetime_task(500, chassis.Drive(-70, 0));

//straight
_set_movement_warm(100, 1200, 1200, 1400);
_set_movement(50, -30, 30, 50);
_set_delayed_task(200, );

//shoot
_set_oneitme_task(400, ShootSignal = SIG_SHOOT);
_set_movement_warm(127, -1100, -1100, 1400);
_set_onetime_task(500, chassis.Drive(-50, 0));

//go to the middle place
_set_movement(70, 300, 300, 400);
_set_movement(100, 300,-300, 400);
_set_movement_warm(127, 2500, 2500, 2800);
_set_movement(100, -920, 920, 1000);

//怼 the wall
_set_onetime_task(800, chassis.Move(-100, 0));

//go up
_set_onetime_task(2500, chassis.Drive(127, 0));
_set_movement(50, -100, -100, 200);
*/
