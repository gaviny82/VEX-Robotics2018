pros::lcd::print(1, "Auto: new_front_red");

//standzrd: 670 units = 90 degree
//standzrd: 1600 units = 60cm
/* 拨台上球 */
_set_onetime_task(0,_arm_down);
_set_movement_warm(80, 1100, 1100, 1400);//前进
_set_movement_warm(90, -450, -450, 400);//向后拨球
_set_onetime_task(400,collector.move(110)); //吸球启动
_set_delayed_task(350, collector.move(0));//吸球停止

/* 清第一列旗 */
_set_movement_warm(100, -850, -850, 1400);//后退到击球位置
_set_movement(100,-810,810,1000);//转向对旗
_set_onetime_task(0,_arm_up);

_set_onetime_task(400, ShootSignal = SIG_SHOOT);/*高旗射球*/
_set_onetime_task(0,collector.move(110));//启动吸球
_set_delayed_task(200, collector.move(0)); /*第二发球到位*/
_set_movement_warm(127,1750,1750,2000);//前进到中旗点位
_set_onetime_task(400, ShootSignal = SIG_SHOOT);/*中旗射球*/
_set_movement(100,-95,125,500);/*调整角度*/
_set_movement_warm(127, 600, 600, 1500);/*向前顶低旗*/
_set_onetime_task(200,);/*停止*/
_set_movement_warm(127, -2200, -2200, 3000);//后退回到红区

//后盘
_set_movement(100,770,-770,800);//转向对墙
//_set_onetime_task(200,chassis.Drive(-50,0));//撞墙校准

//_set_delayed_task(800,arm_down);//延迟arm动作
_set_movement_warm(127,2300,2300,3000);//向前顶盘并夹盘
_set_onetime_task(0,collector.move(110));//开始吸球
//_set_movement(50,800,800,1000);//向前推盘吸球
//_set_movement(50,-800,-800,1000);//向后拉盘
//_set_onetime_task(0,collector.move(0));//吸球停止
_set_movement(100,-710,710,800);
_set_movement(100,-500,-500,400);
_set_movement_warm(100,2300,2300,3000);
_set_movement_warm(100,300,300,300);
_set_movement(100,300,-300,400);
_set_onetime_task(200,ShootSignal = SIG_SHOOT);
//_set_onetime_task(0,_arm_down);

_set_onetime_task(800, chassis.SetMotorsLeft(-40); chassis.SetMotorsRight(-127));
_set_onetime_task(0, chassis.SetMotorsLeft(0); chassis.SetMotorsRight(0));
_set_movement(100,200,200,200);
