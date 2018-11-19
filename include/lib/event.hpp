#pragma once

using keynotify_callback_t = void(*)(void);

class Button;

class Event{
public:
	keynotify_callback_t callback;
};

class ButtonClickedEvent : public Event {
public:
	ButtonClickedEvent(Button *btn, const keynotify_callback_t cb);
private:
	bool isPreviewDown;
	Button *button;
};
