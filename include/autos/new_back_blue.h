pros::lcd::print(1, "Auto: new_back_blue");

//后退翻盘
//go back and turn left
_set_movement_warm(127,-1200,-1200,2000);
_set_movement(100,-680,600,600);
_set_onetime_task(0,_arm_down);

//touch the wall to correct
_set_onetime_task(600,chassis.Drive(-60,0));
_set_onetime_task(0, chassis.Drive(0,0));

//striahgt and turn the plate
_set_movement_warm(80, 2450, 2450, 3000);
_set_onetime_task(0,_arm_up);
_set_movement(127,200,200,300);

//go back
_set_movement_warm(100, -1300, -1300, 2000);

//推盘吸球
//turn right
_set_movement(100,270,-270,400);
_set_onetime_task(0,_arm_down);
_set_onetime_task(0,collector.move(110));

//slowly straight and fetch the ball
_set_movement_warm(60,2500,2500,2500);
_set_delayed_task(400,collector.move(0));
_set_movement_warm(60,-800,-800,900);
_set_onetime_task(0,_arm_back);

//撞台打旗
//turn and correct the direction
_set_movement(100,400,-400,500);
_set_onetime_task(800,chassis.Drive(80,0))
_set_onetime_task(0,chassis.Drive(0,0));

//high flag position
_set_movement(60,-640,0,900);//第一列旗角度
_set_onetime_task(0,collector.move(-80));
_set_onetime_task(300,ShootSignal = SIG_SHOOT);//高旗
_set_onetime_task(0,collector.move(110));

//middle flag position
_set_movement_warm(100,-1230,-1230,1500);
_set_onetime_task(250,collector.move(0));
_set_onetime_task(100,ShootSignal = SIG_SHOOT);//低旗

//上台
//go striahgt and correct the position
_set_movement_warm(100,1100,1100,1500);
_set_movement(100,650,0,900);

//get on tne plate
_set_onetime_task(1200,chassis.Drive(127,0));
_set_movement(10,-10,-10,50);
