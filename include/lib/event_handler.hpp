#pragma once

#include "main.h"
#include <vector>

using namespace std;
using namespace pros;

using event_callback_t = void (*)(void);

class Button
{
  public:
	Button(Controller &ctrller, controller_digital_e_t btn);
	Button(Controller &ctrller, controller_digital_e_t btn, event_callback_t clickedEvent);

	bool IsKeyDown() { return controller->get_digital(button); }
	bool IsPreviewDown = false;
	event_callback_t ClickedEvent;

	Controller GetController() { return *controller; }

	void SetClickedEvent(event_callback_t clickedEvent);
	void RemoveClickedEvent();

  private:
	Controller *controller;
	controller_digital_e_t button;
};

class EventHandler
{
  public:
	static Task *ButtonEventTask;
	static vector<Button *> Events;
	static void EnableButtonEvents();
	static void DisableButtonEvents();

  private:
	static void button_event_loop(void *param);
};
