#include "main.h"
#include "lib/event_handler.hpp"

vector<Button *> EventHandler::Events;
Task *EventHandler::ButtonEventTask = nullptr;

Button::Button(Controller &ctrller, controller_digital_e_t btn)
{
	controller = &ctrller;
	button = btn;
	ClickedEvent = nullptr;
}

Button::Button(Controller &ctrller, controller_digital_e_t btn, event_callback_t clickedEvent)
{
	controller = &ctrller;
	button = btn;
	SetClickedEvent(clickedEvent);
}

void Button::SetClickedEvent(event_callback_t clickedEvent)
{
	for (Button *item : EventHandler::Events)
	{
		if (item == this)
		{
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

void EventHandler::button_event_loop(void *param)
{
	while (true)
	{
		for (vector<Button *>::iterator it = Events.begin(); it != Events.end(); it++)
		{
			// Check if the notify is defined
			if ((*it)->ClickedEvent == nullptr)
				continue;

			bool current = (*it)->IsKeyDown();
			// Try situations
			if (!current && (*it)->IsPreviewDown)
			{
				(*it)->IsPreviewDown = false;
				(*it)->ClickedEvent();
			}
			else if (current)
			{
				(*it)->IsPreviewDown = true;
			}
			else
			{
				(*it)->IsPreviewDown = false;
			}
		}
		delay(20);
	}
}

void EventHandler::EnableButtonEvents()
{
	Task t(button_event_loop, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Button Event Handler");
	ButtonEventTask = &t;
}

void EventHandler::DisableButtonEvents()
{
	if (ButtonEventTask)
	{
		ButtonEventTask->remove();
		ButtonEventTask = nullptr;
	}
}
