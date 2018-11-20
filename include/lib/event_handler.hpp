#pragma once

#include <vector>
#include "lib/button.hpp"
#include "pros/rtos.hpp"

using namespace std;

class EventHandler {
public:
	static Task *ButtonEventTask;
	static vector<Button*> Events;
	static void EnableButtonEvents();
	static void DisableButtonEvents();

private:
	static void button_event_loop(void *param);
};
