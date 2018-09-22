#include "API.h"
#include "keynotify.h"

void set_keynotify(int num, unsigned char joystick, unsigned char buttonGroup, unsigned char button, keynotify_cb_t callback) {
    if (num < 0 || num > MAX_NOTIFY)
      return;
    keynotify[num].joystick = joystick;
    keynotify[num].buttonGroup = buttonGroup;
    keynotify[num].button = button;
    keynotify[num].callback = (*callback);
}

void keynotify_loop() {
  int i = 0;
  for(i = 0; i < MAX_NOTIFY ; i++) {

    bool current;

    /* Check if the notify is defined */
    if (!(*keynotify[i].callback))
      continue;

    /* Get the current key state */
    current = joystickGetDigital(keynotify[i].joystick,
                    keynotify[i].buttonGroup , keynotify[i].button);

    /* Try situations */
    if(current && keynotify[i].isPrevDown) {
      keynotify[i].isPrevDown = false;
      keynotify[i].callback();
    } else if (current) {
      keynotify[i].isPrevDown = true;
    } else {
      keynotify[i].isPrevDown = false;
    }
  } /* End array count loop */
}
