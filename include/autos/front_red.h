pros::lcd::print(1, "Auto: front_red");
_set_onetime_task(0, collector.move(127));
_set_movement(127,3200,3200,3000);
_set_movement(127,-3000,-3000,2500);
//		_set_onetime_task(2000, ShootSignal = SIG_SHOOT);

_set_movement(127,-500,500,3000);