pros::lcd::print(1, "Auto: new_back_red");

//standard: 120 degree = 850
//standard: 90 degree = 670
//stavdard: 1600 units = 1 square unit
/****************second plan **************************************************/
/**********currently used************************************************false*/
/*
//shoot
_set_onetime_task(400, Shootsignal = SIG_SHOOT);

//turn to the direction of blue plate for 90 degree
_set_movement(127, 600, -600, 700);

//go sraight and then turn around
_set_movement_warm(127, 2000, 2000, 2200);
_set_movement(127, 1300, -1300, 1500);

//go backward to turn over the blue plate
_set_movement_warm(127, -1600, -1600, 1500);

//找一下后场射球的位子

*/



/*******This part is for the previous plan that has been replaced.*************/
/***********************currently used************************************true*/
//shoot
_set_onetime_task(400, Shootsignal = SIG_SHOOT);

//turn right for 60 degree
_set_movement(127, 400, -400, 500);

//fetch the ball
_set_onetime_task(200,chassis.Drive(50,0));
_set_delayed_task(800,arm_down);
_set_movement_warm(127,2300,2300,3000);
_set_onetime_task(0,collector.move(110));
_set_movement(50,800,800,1000);
_set_movement(50,-800,-800,1000);
_set_onetime_task(0,collector.move(0));

//turn left for 120 degree
_set_movement(127, -1200, 1200, 1400);

//backward to turn over the plate
_set_movement_warm(127, -2000, -2000, 2200);

//touch the wall to correct
_set_movement_warm(127, 300, 300, 400);
_set_movement(127, 200, -200, 300);
_set_movement_warm(50, -800, -800, 900);

//Shoot
/*this part should be replaced
*According to the place to Shoot
*
*/
// get on the plate
_set_movement_warm(127, 2000, 2000, 2200);
