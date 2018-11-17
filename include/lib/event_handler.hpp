#pragma once

#include <vector>
#include "lib/button_event.hpp"

using namespace std;

class EventHandler {
public:
	static Register();
private:
	static vector<Event> _events;
};