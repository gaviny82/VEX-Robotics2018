#include "lib/KeyNotifyEvent.hpp"
#include "pros/rtos.hpp"
#include <list>

void KeyNotifyEvent::Register(const KeyNotify &notify){
  if(!initialized){
    init(notify.controller);
  }
  clickedEvents.push_back(notify);
}

void KeyNotifyEvent::init(const pros::Controller &Controller){
  pros::Task task(keyNotifyLoop, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Key Notify");
  taskKeyNotify = task;
  controller = Controller;
  initialized = true;
}

void KeyNotifyEvent::keyNotifyLoop(void *param){
  for(std::list<KeyNotify>::iterator it= clickedEvents.begin(); it!=clickedEvents.end();it++){
    /* Check if the notify is defined */
    if (!it->callback) continue;

    bool current = controller.get_digital(it->button);//Get the current key state
    /* Try situations */
    if(!current && it->isPrevDown) {
      it->isPrevDown = false;
      it->callback();
    } else if (current) {
      it->isPrevDown = true;
    } else {
      it->isPrevDown = false;
    }
  }
}
