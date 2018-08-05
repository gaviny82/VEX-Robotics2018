#ifndef PID_H_
#define PID_H_

/** Instance of a PID controller.
 *
 * @note This structure is only public to be able to do static allocation of it.
 * Do not access its fields directly.
 */
typedef struct {
    float kp;
    float ki;
    float kd;
    float integrator;
    float previous_error;
    float integrator_limit;
    float frequency;
} pid_ctrl_t;

/** Initializes a PID controller. */
void pid_init(pid_ctrl_t *pid);

/** Sets the gains of the given PID. */
void pid_set_gains(pid_ctrl_t *pid, float kp, float ki, float kd);

/** Process one step if the PID algorithm. */
float pid_process(pid_ctrl_t *pid, float error);

#endif
