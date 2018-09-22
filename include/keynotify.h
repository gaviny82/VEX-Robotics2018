#ifndef KEYNOTIFY_H_
#define KEYNOTIFY_H_

#define MAX_NOTIFY 5

typedef void (*keynotify_cb_t)();


struct keynotify_s{
    unsigned char joystick;
    unsigned char buttonGroup;
    unsigned char button;
    keynotify_cb_t callback; /* Callback function, should not be blocked! */
    bool isPrevDown; /* Used internal */
  };

struct keynotify_s keynotify[MAX_NOTIFY];

void set_keynotify(int num, unsigned char joystick, unsigned char buttonGroup,
                    unsigned char button, keynotify_cb_t callback);

void keynotify_loop();

#define NOTIFY_REVERSE_DIRECTION 0

#endif
