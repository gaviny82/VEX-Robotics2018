#include "lib/joystick.hpp"

Joystick::Joystick(const Controller &ctrller, const controller_analog_e_t &joystick) : controller(ctrller)
{
	this->joystick = joystick;
}
