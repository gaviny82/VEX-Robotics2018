pros::lcd::print(1, "Auto: new_back_red");



//后退翻盘
_set_movement_warm(127,-1200,-1200,2000);
_set_movement(100,600,-680,600);
_set_onetime_task(0,_arm_down);
_set_onetime_task(600,chassis.Drive(-60,0));
_set_onetime_task(0, chassis.Drive(0,0));
_set_movement_warm(80, 2450, 2450, 3000);
_set_onetime_task(0,_arm_up);
_set_movement(127,200,200,300);
//_set_onetime_task(0,collector.move(110))
_set_movement_warm(100, -1300, -1300, 2000);
//_set_onetime_task(200, );
//_set_onetime_task(0,collector.move(0))

//推盘吸球
_set_movement(100,-250,250,400);
_set_onetime_task(0,_arm_pan);
_set_onetime_task(0,collector.move(110));
_set_movement_warm(70,2300,2300,2500);
_set_delayed_task(400,collector.move(0));
_set_movement_warm(60,-800,-800,900);
_set_onetime_task(0,_arm_back);

//撞台打旗
_set_movement(100,-400,400,500);
_set_onetime_task(800,chassis.Drive(80,0))
_set_onetime_task(0,chassis.Drive(0,0));
_set_movement(60,0,-640,900);//第一列旗角度
_set_onetime_task(200,collector.move(-80));
_set_onetime_task(300,ShootSignal = SIG_SHOOT);//高旗
_set_onetime_task(0,collector.move(110));
_set_movement_warm(100,-1230,-1230,1500);
//_set_onetime_task(100, );
_set_onetime_task(250,collector.move(0));
_set_onetime_task(100,ShootSignal = SIG_SHOOT);//低旗
_set_movement_warm(100,1100,1100,1500);
_set_movement(100,0,640,900);
_set_onetime_task(1200,chassis.Drive(127,0));
_set_movement(10,-10,-10,50);
