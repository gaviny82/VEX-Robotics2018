pros::lcd::print(1, "Auto: new_front_red");

/* 拨台上球 */
_arm_down;
_set_movement_warm(80, 1100, 1100, 1400);//前进
_set_movement_warm(70, -300, -300, 400);//向后拨球
_set_onetime_task(700,collector.move(127)); //吸球启动
_set_onetime_task(0, collector.move(0));//吸球停止

/* 清第一列旗 */
_set_movement_warm(127, -850, -850, 1400);//后退到击球位置
_set_movement(100,-850,850,1000);//转向对旗
_arm_up;

_set_onetime_task(200, ShootSignal = SIG_SHOOT);/*高旗射球*/
_set_onetime_task(0, collector.move(110)); /*第二发球到位*/
_set_movement_warm(127,1700,1700,2000)//
_set_onetime_task(400, ShootSignal = SIG_SHOOT);/*中旗射球*/
#if 0
_set_movement(100,-90,90,500);/*调整角度*/
_set_movement_warm(127, 1400, 1400, 1500);/*向前顶低旗*/
_set_onetime_task(200,);/*停止*/
_set_movement_warm(127, -1500, -1500, 3000);//后退回到顶盘位置

//清盘
_set_movement(100, -700, 700, 600);
_set_onetime_task(1000,chassis.Drive(50,0));
_set_onetime_task(0,chassis.Drive(0,0));

//back
_set_movement(100, -2000, -2000, 2000);
_set_movement(100, 600, 600, 600);

//turn and face the flag
_set_movement(100,-400,400,600)

//shoot

_set_onetime_task(0, ShootSignal = SIG_SHOOT)

//forward
_set_movement(100,1000,1000,1500)

#endif
