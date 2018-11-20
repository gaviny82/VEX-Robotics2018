#include "lib/key_notify.hpp"
#include "pros/misc.hpp"

using event_callback_t = void (*)(void);

KeyNotify::KeyNotify(pros::Controller &Controller, const pros::controller_digital_e_t Button, const event_callback_t Callback) : controller(Controller) {
	button = Button;
	callback = Callback;
	isPrevDown = false;
}
