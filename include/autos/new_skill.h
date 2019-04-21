pros::lcd::print(1, "Auto: new_skill")

//*************First group is copied from auto/new_back_red.h ****************//
//go to the end
_set_movement_warm(110, -1600, -1600, 2000);

//correct the turn and the direction
_set_movement(100, -680, 600, 700);
_set_onetime_task(500, chassis.Drive(70, 0));

//back to turn the plate
_set_onetime_task(0, _arm_pan);
_set_movement_warm(127, -2800, -2800, 3000);
_set_movement(127, 700, 700, 600);

//turn direction and place
_set_onetime_task(2000, chassis.Drive(70, 50));//change this number to match the position
_set_onetime_task(0 ,chassis.Drive(0, 0));

//fetch the ball
_set_onetime_task(0, collector.move(127));
_set_movement_warm(50, 500, 500, 600);
_set_delayed_task(500, );
_set_movement_warm(70, -500, -500, 600);

//turn and shoot the high flag
_set_onetime_task(0, collector.move(0));
_set_movement(_100, -300, 300, 400);
_set_movement(127, 200, 200, 300);
_set_onetime_task(400, ShootSignal = SIG_SHOOT);
_set_movement(12, -600, -600, 800);
_set_delayed_task(500, );
_set_onetime_task(0 ,ShootSignal = SIG_SHOOT);

//correct the place
_set_onetime_task(2000, chassis.Drive(-70, 0);
