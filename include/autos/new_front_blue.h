pros::lcd::print(1, "Auto: new_front_blue");
pros::lcd::print(2, "交附2");

//standzrd: 670 units = 90 degree
//standzrd: 1600 units = 60cm
/* 拨台上球 */
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
_set_movement(100,85,-85,300);/*调整角度*/
_set_movement_warm(127, 800, 800, 1500);/*向前顶低旗*/
//_set_onetime_task(200,);/*停止*/

_set_movement_warm(127, -2300, -2300, 3000);//后退回到红区
_set_delayed_task(200,_arm_pan);

_set_movement(100,-780,780,800);//转向对墙
_set_onetime_task(0,collector.move(110));//开始吸球
_set_movement_warm(70,2600,2600,3000);//向前顶盘
_set_movement_warm(70,-200,-200,300);
_set_movement(100,750,-750,800);//转向对台
_set_movement(100,-600,-600,400);//后退顶台
_set_onetime_task(0,_arm_up);
_set_movement_warm(100,2700,2700,3000);//前进到达点位
_set_onetime_task(0,collector.move(0));
_set_movement(100,-300,300,400);//
_set_onetime_task(300,ShootSignal = SIG_SHOOT);//打中旗
//_set_movement_warm(100,200,200,300);

//_set_movement_warm(100,200,200,300);//
//后退翻前盘
_set_onetime_task(800, chassis.SetMotorsLeft(-110); chassis.SetMotorsRight(-60));
_set_onetime_task(0, chassis.SetMotorsLeft(0); chassis.SetMotorsRight(0));
_set_movement(100,200,200,200);
