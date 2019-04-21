pros::lcd::print(1, "Auto: new_back_blue");

//轮子第二格

_set_onetime_task(0,collector.move(110));//开始吸球
_set_movement_warm(75,1200,1200,3000);//到射球位
_set_movement(100,590,-590,900);//转向对旗
_set_onetime_task(500, ShootSignal = SIG_SHOOT);/*中间高旗射球*/
_set_movement_warm(100,-1850,-1850,3000);//后退
_set_movement(100,870,-870,800);//转向对盘
_set_onetime_task(0,_arm_pan);
_set_movement_warm(75,-2400,-2400,3000);//怼盘子
_set_movement_warm(110,2500,2500,3000); //怼完跑路
_set_movement(100,-630,630,800);//转向撞墙
_set_onetime_task(500, chassis.SetMotorsLeft(-80); chassis.SetMotorsRight(-80));
_set_onetime_task(0, chassis.SetMotorsLeft(0); chassis.SetMotorsRight(0));
_set_movement_warm(100,1500,1500,3000);//到盘子旁边
_set_movement(100,-720,720,800);//转向对盘
_set_movement_warm(75,2300,2300,3000);//向前顶盘
_set_delayed_task(800, _arm_up); /*收arm*/
_set_movement_warm(100,-600,-600,3000);//后退
_set_movement(100,630,-630,800);//转向对台
_set_onetime_task(1000, chassis.SetMotorsLeft(127); chassis.SetMotorsRight(127));
_set_onetime_task(100, chassis.SetMotorsLeft(-10); chassis.SetMotorsRight(-10));
_set_onetime_task(100, chassis.SetMotorsRelativeL(0, 30); chassis.SetMotorsRelativeR(0,30));
