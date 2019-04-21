pros::lcd::print(1, "Auto: new_back_red");

//standard: 120 degree = 850
//standard: 90 degree = 670
//stavdard: 1600 units = 1 square unit

//go to the end
_set_movement_warm(127, -1780, -1780, 2000);

//correct the turn and the direction
_set_movement(100, -680, 600, 700);
_set_onetime_task(800, chassis.Drive(50, 0));

//back to turn the plate
_set_onetime_task(0, _arm_down);
_set_movement_warm(127, -3000, -3000, 3500);
_set_movement_warm(100, -700, -700, 1000);
_set_movement_warm(127, 700, 700, 600);

//turn direction and place
_set_onetime_task(1620, chassis.Drive( 62, 55));//change this number to match the position still need change 1:48 22/4/2019
_set_onetime_task(10, chassis.Drive( -62, -55));//barke the motor
_set_onetime_task(0, chassis.Drive(0, 0));//180 degree

//fetch the ball
_set_onetime_task(0, collector.move(127));
_set_movement_warm(127, 800, 800, 1200);
_set_movement_warm(70, 800, 800, 900);
_set_movement_warm(70, -1000, -1000, 1600);

//turn and shoot the high flag
_set_onetime_task(0, collector.move(0));
_set_movement(100, -350, 350, 500);
_set_movement_warm(127, -1200, -1200, 1500);
_set_onetime_task(500, collector.move(-127));
_set_onetime_task(400, ShootSignal = SIG_SHOOT);
_set_onetime_task(0, collector.move(110));
_set_movement_warm(127, 1800, 1800, 2000);
_set_onetime_task(500, );
_set_onetime_task(200, ShootSignal = SIG_SHOOT);
_set_onetime_task(0 ,collector.move(0));

//correct the place
_set_onetime_task(800, chassis.Drive(80, 0));
_set_movement_warm(127, 1600, 1600, 2000);
