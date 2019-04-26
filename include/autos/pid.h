pros::lcd::print(1, "Auto: test");
//_set_onetime_task(0, arm_m = 10);
_set_onetime_task(0,_arm_up);
//_set_onetime_task(0, arm_m = 5);
/*
_arm_down;

_set_movement_warm(100, 1300, 1300, 1400);//前进
_set_onetime_task(5000, );//前进
_set_movement_warm(100, -1300, -1300, 1400);//前进
_set_onetime_task(500, );//前进
_set_movement_warm(100, 1300, 1300, 1400);//前进
_set_onetime_task(500, );//前进
_arm_up;
_set_movement_warm(100, -1300, -1300, 1400);//前进
*/
//_set_movement(100,670,-670,1000);
//_set_movement_warm(100,1600,1600,3000);

/*new added task
_set_onetime_task(5000,_arm_down);
_set_onetime_task(5000,_arm_up);
_set_onetime_task(0,_arm_pan);
_set_onetime_task(0,collector.move(100));
_set_movement_warm(100,3000,3000,1500);
*/
//1600 = 60cm  37.037 = 1cm


//test of turning with the center out of the robot
//(1800, chassis.Drive( 65, 55));//change this number to match the position
//_set_onetime_task(10, chassis.Drive( -65, -55));//barke the motor
//_set_onetime_task(0, chassis.Drive(0, 0));//180 degree
//completed
