#include "lib/KeyNotify.hpp"
#include "pros/misc.hpp"

KeyNotify::KeyNotify(pros::Controller &Controller, const pros::controller_digital_e_t Button, const keynotify_callback_t Callback):controller(Controller){
  button=Button;
  callback=Callback;
  isPrevDown=false;
}
