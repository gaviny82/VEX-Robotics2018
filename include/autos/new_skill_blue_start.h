pros::lcd::print(1, "Auto: skills");



//后退翻盘
_set_movement_warm(127,-1800,-1800,2000);
_set_movement(100,-680,600,600);
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
_set_movement(100,250,-250,400);
_set_onetime_task(0,_arm_down);
_set_onetime_task(0,collector.move(110));
_set_movement_warm(60,2500,2500,2500);
_set_delayed_task(400,collector.move(0));
_set_movement_warm(60,-800,-800,900);
_set_onetime_task(0,_arm_back);

//撞台打旗
_set_movement(100,400,-400,500);
_set_onetime_task(800,chassis.Drive(80,0))
_set_onetime_task(0,chassis.Drive(0,0));
_set_movement(60,-650,0,900);//第一列旗角度
//_set_onetime_task(200,collector.move(-110));
_set_onetime_task(300,ShootSignal = SIG_SHOOT);//高旗
_set_onetime_task(0,collector.move(110));
_set_movement_warm(100,-1230,-1230,1500);
//_set_onetime_task(100, );
_set_onetime_task(250,collector.move(0));
_set_onetime_task(100,ShootSignal = SIG_SHOOT);//低旗
_set_movement_warm(100,1100,1100,1500);
_set_movement(100,650,0,900);
_set_onetime_task(600,chassis.Drive(80,0));//撞台校准
_set_movement_warm(100,-500,-500,700);
_set_movement(100,670,-670,700);//time can be reduced
_set_onetime_task(500,);
_set_onetime_task(0,_arm_back);
_set_movement_warm(100,3500,3500,4000);
_set_onetime_task_(500,chassis.Drive(80,0));//撞墙校准

//吸台上球
_set_movement_warm(100,500,500,800);
_set_movement(100,300,-300,500);//Time cna be reduced
_set_onetime_task(0,_arm_down);
_set_onetime_task(0,collector.move(110)); //吸球启动
_set_movement_warm(80, 1100, 1100, 1400);//前进
_set_movement_warm(90, -600, -600, 600);//向后拨球
_set_onetime_task(200,);

//转向向前衔接蓝色前场自动
_set_movement_warm(100,-500,-500,600)
_set_movement(100,-300,300,500);//time can be reduced
_set_movement_warm(100,2000,2000,3000);
_set_movement(100,-670,670,1000);
_set_onetime_task(500,chassis.Drive(80));//撞墙校准
_set_movement_warm(100,500,500,600);
_set_movement(100,-200,200,300);

//蓝色前场自动
_set_onetime_task(0,_arm_down);
_set_onetime_task(0,collector.move(110)); //吸球启动
_set_movement_warm(80, 1100, 1100, 1400);//前进
_set_movement_warm(90, -650, -650, 500);//向后拨球
_set_onetime_task(200,);
/* 清第一列旗 */
_set_movement_warm(100, -650, -650, 1500);//后退到击球位置
_set_onetime_task(0, collector.move(0));//吸球停止
_set_movement(100,840,-840,900);//转向对旗
_set_onetime_task(0,_arm_up);

_set_onetime_task(400, ShootSignal = SIG_SHOOT);/*高旗射球*/
_set_onetime_task(0,collector.move(110));//启动吸球
_set_movement_warm(127,1750,1750,2000);//前进到中旗点位
_set_delayed_task(0, collector.move(0)); /*第二发球到位*/
_set_onetime_task(400, ShootSignal = SIG_SHOOT);/*中旗射球*/
_set_movement(100,95,-95,300);/*调整角度*/
_set_movement_warm(127, 800, 800, 1500);/*向前顶低旗*/
//_set_onetime_task(200,);/*停止*/
_set_movement_warm(127, -2450, -2450, 3000);//后退回到红区


_set_movement(100,-760,760,800);//转向对墙
_set_onetime_task(0,collector.move(110));//开始吸球
_set_onetime_task(0,_arm_pan);
_set_movement_warm(75,2600,2600,3000);//向前顶盘
_set_movement(100,710,-710,800);//转向对台
_set_movement(100,-600,-600,400);//后退顶台
_set_onetime_task(0,_arm_up);
_set_movement_warm(100,2700,2700,3000);//前进到达点位
_set_onetime_task(0,collector.move(0));
_set_movement(100,-300,300,400);//
_set_onetime_task(300,ShootSignal = SIG_SHOOT);//打中旗

//
_set_movement(100,300,-300,400);
_set_movement_warm(127,2000,2000,3000);
_set_onetime_task(500,chassis.Drive(80,0));
_set_onetime_task(0,Chassis.Drive(0,0));//撞台校准
_set_movement_warm(127,2000,2000,2500);
_set_movement(100,-670,670,700);//对准红侧前盘
_set_movement_warm(127,2500,2500,3000);
_set_onetime_task(0,_arm_up);
_set_movement(127,200,200,300);//翻盘
_set_movement_warm(127,-800,-800,900);
_set_onetime_task(0,_arm_pan);
_set_movement(100,-670,670,700);
_set_movement_warm(100,-2000,-2000,3000);
_set_onetime_task(500,chassis.Drive(80,0));
_set_onetime_task(0,chassis.Drive(0,0));//撞台校准
_set_movement_warm(100,800,800,1000);
_set_movement(100,-670,670,700);
_set_movement_warm(70,4000,4000,3000);//推盘
_set_movement_warm(100,-500,-500,1200);
_set_movement(100,670,-670,700);
_set_onetime_task(300,chassis.Drive(80));
_set_onetime_task(0,chassis.Drive(0));
_set_movement(100,650,50,600);//转向对旗
_set_onetime_task(200,);
_set_onetime_task(300,ShootSignal = SIG_SHOOT);
_set_movement(100,-650,-50);
_set_onetime_task(1250,chassis.Drive(127,0));
_set_movement(10,-10,-10,100);
