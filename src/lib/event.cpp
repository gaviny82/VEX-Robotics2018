#include "event.hpp"

ButtonClickedEvent::ButtonClickedEvent(Button *btn, const keynotify_callback_t cb)
{
	button = btn;
	callback = cb;
}
