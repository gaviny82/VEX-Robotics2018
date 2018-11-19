#include "lib/joystick.hpp"
#include "pros/misc.hpp"

Joystick::Joystick(const Controller &ctrller, const controller_analog_e_t &joystick) : controller(ctrller)
{
	this->joystick = joystick;
}
