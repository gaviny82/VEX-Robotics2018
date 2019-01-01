#include "lib/button.hpp"
#include "lib/event_handler.hpp"
#include <vector>
#include <list>
#include "pros/llemu.hpp"

using event_callback_t = void (*)(void);

Button::Button(Controller &ctrller, controller_digital_e_t btn)
{
	controller = &ctrller;
	button = btn;
	ClickedEvent = nullptr;
}

Button::Button(Controller &ctrller, controller_digital_e_t btn, event_callback_t clickedEvent){
	controller = &ctrller;
	button = btn;
	SetClickedEvent(clickedEvent);
}

void Button::SetClickedEvent(event_callback_t clickedEvent)
{
	for (Button *item : EventHandler::Events) {
		if (item == this) {
			pros::lcd::print(7, "ERROR: Button %s on %s has already been registered!");
			return;
		}
	}
	ClickedEvent = clickedEvent;
	EventHandler::Events.push_back(this);
}

void Button::RemoveClickedEvent()
{
	ClickedEvent = nullptr;
}
