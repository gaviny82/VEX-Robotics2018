#pragma once
#include "pros/misc.hpp"
#include "lib/event.hpp"

using keynotify_callback_t = void (*)(void);
using namespace pros;

class Button {
public:
	Button(Controller &ctrller, controller_digital_e_t &btn);
	~Button();

	bool IsKeyDown() { return controller->get_digital(button); }

	void SetClickedEvent(keynotify_callback_t callback);
	void RemoveClickedEvent();
private:
	ButtonClickedEvent *clickedEvent;
	Controller *controller;
	controller_digital_e_t button;
};
