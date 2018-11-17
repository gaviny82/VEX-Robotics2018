#pragma once

using namespace pros;

class Joystick {
public:
	Joystick(const Controller &ctrller, const controller_analog_e_t &joystick);

	Controller controller;
	controller_analog_e_t joystick;
};