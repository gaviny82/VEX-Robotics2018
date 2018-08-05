#include <stdlib.h>
#include <math.h>
#include "pid.h"


void pid_init(pid_ctrl_t *pid)
{
    pid_set_gains(pid, 1., 0., 0.);
    pid->integrator = 0.;
    pid->previous_error = 0.;
    pid->integrator_limit = 127;
    pid->frequency = 1.;
}

void pid_set_gains(pid_ctrl_t *pid, float kp, float ki, float kd)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
}

float pid_process(pid_ctrl_t *pid, float error)
{
    float output;
    pid->integrator += error;

    if (pid->integrator > pid->integrator_limit) {
        pid->integrator = pid->integrator_limit;
    } else if (pid->integrator < -pid->integrator_limit) {
        pid->integrator = -pid->integrator_limit;
    }

    output  = - pid->kp * error;
    output += - pid->ki * pid->integrator / pid->frequency;
    output += - pid->kd * (error - pid->previous_error) * pid->frequency;

    pid->previous_error = error;
    return output;
}
