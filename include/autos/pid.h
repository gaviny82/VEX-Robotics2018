pros::lcd::print(1, "Auto: test_of_pid");

_arm_down;
_set_movement_warm(100, 1300, 1300, 1400);//前进
_set_onetime_task(5000, );//前进
_set_movement_warm(100, -1300, -1300, 1400);//前进
_set_onetime_task(500, );//前进
_set_movement_warm(100, 1300, 1300, 1400);//前进
_set_onetime_task(500, );//前进
_arm_up;
_set_movement_warm(100, -1300, -1300, 1400);//前进


//2000 = 54cm
