#ifndef KEYNOTIFY_H_

#define MAX_NOTIFY 5

struct keynotify_s{
    unsigned char joystick;
    unsigned char buttonGroup;
    unsigned char button;
    void (*callback)(); /* Callback function, should not be blocked! */
    bool isPrevDown; /* Used internal */
  };

struct keynotify_s keynotify[MAX_NOTIFY];

#define KEYNOTIFY_H_

#endif
