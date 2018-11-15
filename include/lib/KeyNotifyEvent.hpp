#pragma once
#include "lib/KeyNotify.hpp"
#include "pros/rtos.hpp"
#include <list>

class KeyNotifyEvent{
public:
  static pros::Controller controller;
  static pros::Task taskKeyNotify;
  static std::list<KeyNotify> clickedEvents;

  static void Register(const KeyNotify &notify);
private:
  static bool initialized;

  static void init(const pros::Controller &controller);
  static void keyNotifyLoop(void *param);
};
