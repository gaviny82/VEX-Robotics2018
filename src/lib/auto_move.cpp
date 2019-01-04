#include "api.h"
#include "robot.hpp"
#include "lib/auto_move.hpp"
#include "lib/pid_control.hpp"

PidControl pid_l;
PidControl pid_r;

void auto_move::reset(){
    state = TASK_RUNNING;
    firstrun = true;
}

void auto_move::run() {
    if (state == TASK_TLE)
        return;
    if(firstrun){
        start_time = millis();
        firstrun = false;
        pid_l.Pidinit(Kp, Ki, Kd);
        pid_r.Pidinit(Kp, Ki, Kd);
        chassis.ClearEncoderL();
        chassis.ClearEncoderR();
    }
    time = time - (millis() - start_time);
    double spd_l = pid_l.PidProcess(target_l, chassis.GetEncoderL());
    double spd_r = pid_r.PidProcess(target_r,chassis.GetEncoderR());
    chassis.SetMotorsLeft(spd_l);
    chassis.SetMotorsRight(spd_r);
    if (time <= 0)
        state == TASK_TLE;

}