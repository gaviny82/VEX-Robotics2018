#include "lib/event_handler.hpp"
#include "lib/button.hpp"

vector<Button*> EventHandler::Events;
Task *EventHandler::ButtonEventTask=nullptr;

void EventHandler::button_event_loop(void * param)
{
	for (vector<Button*>::iterator it = Events.begin(); it != Events.end(); it++) {
		// Check if the notify is defined
		if ((*it)->ClickedEvent == nullptr) continue;

		bool current = (*it)->IsKeyDown();
		// Try situations
		if (!current && (*it)->IsPreviewDown) {
			(*it)->IsPreviewDown = false;
			(*it)->ClickedEvent();
		}
		else if (current) {
			(*it)->IsPreviewDown = true;
		}
		else {
			(*it)->IsPreviewDown = false;
		}
	}
}

void EventHandler::EnableButtonEvents(){
	Task t = new Task(button_event_loop, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Button Event Handler");
	ButtonEventTask = &t;
}

void EventHandler::DisableButtonEvents(){
	ButtonEventTask->remove();
	delete ButtonEventTask;
}
