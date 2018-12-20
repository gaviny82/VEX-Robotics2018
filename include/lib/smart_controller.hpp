#pragma once

#include "lib/button.hpp"

class SmartController{
public:
  SmartController();

private:
  Button btnLeft, btnRight, btnUp, btnDown;
  Button btnX, btnY, btnA, btnB;
  Button btnL1, btnL2, btnR1, btnR2;
};
