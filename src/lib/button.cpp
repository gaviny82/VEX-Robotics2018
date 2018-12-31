#include "lib/button.hpp"
#include "lib/event_handler.hpp"
#include <vector>

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
	ClickedEvent = clickedEvent;
	EventHandler::Events.push_back(this);
}

void Button::RemoveClickedEvent()
{
	ClickedEvent = nullptr;
}
