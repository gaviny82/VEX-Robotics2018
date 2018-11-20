#pragma once
#include "pros/misc.hpp"

using event_callback_t = void (*)(void);
using namespace pros;

class Button {
public:
	Button(Controller &ctrller, controller_digital_e_t btn);
	Button(Controller &ctrller, controller_digital_e_t btn, event_callback_t clickedEvent);

	bool IsKeyDown() { return controller->get_digital(button); }
	bool IsPreviewDown = false;
	event_callback_t ClickedEvent;

	Controller GetController() { return *controller; }

	void SetClickedEvent(event_callback_t clickedEvent);
	void RemoveClickedEvent();
private:
	Controller *controller;
	controller_digital_e_t button;

};
