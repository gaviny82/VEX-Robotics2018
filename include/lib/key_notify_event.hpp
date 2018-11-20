#pragma once
#include "lib/key_notify.hpp"
#include "pros/rtos.hpp"
#include <list>

class KeyNotifyEvent{
public:
  static pros::Task taskKeyNotify;
  static std::list<KeyNotify> clickedEvents;

  static void Register(const KeyNotify &notify);
private:
  static void keyNotifyLoop(void *param);
};
