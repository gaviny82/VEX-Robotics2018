#include "lib/button.hpp"
#include "lib/event.hpp"

using keynotify_callback_t = void (*)(void);

Button::Button(Controller &ctrller, controller_digital_e_t &btn)
{
	controller = &ctrller;
	button = btn;
	clickedEvent = new ButtonClickedEvent(this, nullptr);
}
Button::~Button(){
	delete clickedEvent;
}

void Button::SetClickedEvent(keynotify_callback_t callback)
{
	clickedEvent->callback = callback;
}

void Button::RemoveClickedEvent()
{
	clickedEvent->callback = nullptr;
}
