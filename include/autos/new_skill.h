pros::lcd::print(1, "Auto: new_skill")

//*************First group is copied from auto/new_back_red.h ****************//
//shoot
_set_onetime_task(400, Shootsignal = SIG_SHOOT);

//turn right for 60 degree
_set_movement(127, 300, -300, 500);

//straight to fetch the ball
_set_movement_warm(127, 2800, 2800, 2800);
_set_onetime_task(0,collector.move(127));

//fetch the ball
_set_movement_warm(50, 200, 200, 300);
_set_delayed_task(200, );

//back a little
_set_onetime_task(70, -300, -300, 400);
_set_onetime_task(0, collector.move(0));

//make the plate svevral distance away
_set_movement_warm(70, 500, 500, 600);
_set_movement_warm(70, -500, -500, 600);

//turn left for 120 degree
_set_movement(127, -600, 600, 1000);

//go to overtake the plate
_set_movement_warm(127, -2000, -2000, 2100);
_set_delayed_task(500, );

//go back to the position
_set_movement_warm(127, 2000, 2000, 2100);

//*******************go back to the another red place ************************//
//turn right and fetch the ball
arm_down;//change the arm to the lowest position
_se_onetime_task(0, collecotrmove(127));
_set_movement(127, 150, 150, 200);
