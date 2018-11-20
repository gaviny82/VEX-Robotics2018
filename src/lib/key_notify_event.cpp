#include "lib/key_notify_event.hpp"
#include "lib/key_notify.hpp"
#include "pros/rtos.hpp"
#include <list>

pros::Task KeyNotifyEvent::taskKeyNotify(keyNotifyLoop, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Key Notify");
std::list<KeyNotify> KeyNotifyEvent::clickedEvents;

void KeyNotifyEvent::Register(const KeyNotify &notify) {
	clickedEvents.push_back(notify);
}

void KeyNotifyEvent::keyNotifyLoop(void *param) {
	for (std::list<KeyNotify>::iterator it = clickedEvents.begin(); it != clickedEvents.end(); it++) {
		// Check if the notify is defined
		if (!it->callback) continue;

		bool current = it->controller.get_digital(it->button);//Get the current key state
		// Try situations
		if (!current && it->isPrevDown) {
			it->isPrevDown = false;
			it->callback();
		}
		else if (current) {
			it->isPrevDown = true;
		}
		else {
			it->isPrevDown = false;
		}
	}
}
