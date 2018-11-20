#pragma once
#include "pros/misc.hpp"

using keynotify_callback_t = void (*)(void);

class KeyNotify{
public:
  pros::Controller controller;
  pros::controller_digital_e_t button;
  keynotify_callback_t callback;
  bool isPrevDown = false;

  KeyNotify(pros::Controller &Controller, const pros::controller_digital_e_t Button, const keynotify_callback_t Callback);
};
//TODO: Extend keynotify to keydown events
