#pragma once

using namespace pros;

class Button {
public:
	Button(Controller &ctrller, controller_digital_e_t &btn);

	Controller controller;
	controller_digital_e_t button;
};

