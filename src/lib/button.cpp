#include "lib/button.hpp"

Button::Button(Controller &ctrller, controller_digital_e_t &btn) : controller(ctrller)
{
	button = btn;
}
