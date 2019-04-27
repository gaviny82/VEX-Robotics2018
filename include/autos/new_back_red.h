pros::lcd::print(1, "Auto: new_back_red");


_set_onetime_task(0,_arm_down);
_set_movement_warm(80, 2200, 2200, 3000);
_set_onetime_task(0,collector.move(110));
_set_onetime_task(300,);
_set_movement_warm(80,1000,1000,800);
_set_movement_warm(80,-800,-800,800);


_set_movement(60,-670,670,800);
_set_onetime_task(0,collector.move(0));
_set_onetime_task(800,chassis.Drive(60,0));
_set_movement(60,0,-690,900);//第一列旗角度
_set_onetime_task(200,);
_set_onetime_task(300,collector.move(-80));
_set_onetime_task(300,ShootSignal = SIG_SHOOT);//高旗
_set_onetime_task(0,collector.move(110));


_set_movement_warm(80,-1800,-1800,1500);
_set_onetime_task(0,_arm_back);
_set_onetime_task(250,collector.move(0));

_set_movement_warm(80,1800,1800,1500);
_set_movement(60,0,650,800);
_set_onetime_task(300,chassis.Drive(60,0));
_set_onetime_task(666,chassis.Drive(127,0));
_set_movement_warm(10,-10,-10,-20);
_set_movement_warm(5,5,5,10);
_set_onetime_task(0,chassis.SetBrakeMode(E_MOTOR_BRAKE_HOLD));
