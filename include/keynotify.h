#ifndef KEYNOTIFY_H_
#define KEYNOTIFY_H_

#define MAX_NOTIFY 12

typedef void (*keynotify_cb_t)();

struct keynotify_s{
    unsigned char joystick;
    unsigned char buttonGroup;
    unsigned char button;
    keynotify_cb_t callback; /* Callback function, should not be blocked! */
    bool isPrevDown; /* Used internal */
  };

struct keynotify_s keynotify[MAX_NOTIFY];

/*
* Set the clicked event for a particular button
*
* @param index of the event
*
* @param joystick number
*
* @param button group number
*
* @param button number
*
* @param the void function called when the button is pressed
*/
void set_keynotify(int num, unsigned char joystick, unsigned char buttonGroup,
                    unsigned char button, keynotify_cb_t callback);

/*
* loop to deteck keynotify events
* internal use only
*/
void keynotify_loop();

#define NOTIFY_REVERSE_DIRECTION 0

#endif
