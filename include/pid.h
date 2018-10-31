#ifndef PID_H_
#define PID_H_

typedef struct {
	int nSetPos;
	int nActPos;
	int nErr;
	int nErr_last;
	float Kp, Ki, Kd;
	float nIntegral;
	float nDiffer;
	float nPowerOut;
	int max;
	int target;
} PIDCtrl;

/*
* initialize a new pid control
*
* @param Kp: proportion argument
*
* @param Ki: integral argument
*
* @param Kd: derivative argument
*
*/
extern void pid_init(PIDCtrl *pid, float Kp, float Ki, float Kd);

/*
* return the output of a pid
*
* @param pid: a defined pid
*
* @param posInput: target value
*
* @param posAct: current value
*/
extern int pid_process(PIDCtrl *pid, int posInput, int posAct);

/*
* go straight forward, it goes backward if distance is negative
*
* @param distance: distance moved
*
* @param speed: set maximum speed to complete the action
*
* @param estimateTime: time delay to stop the task
*/
extern void go(int distance, unsigned char speed, signed int estimateTime);

/*
* rotate about the center
*
* @param degree: angle rotated clockwise
*
* @param speed: set maximum speed to complete the action
*
* @param estimateTime: time delay to stop the task
*/
extern void rotate(int degree, unsigned char speed, signed int estimateTime);


extern void leftPIDLoop(void *tgt);

extern void rightPIDLoop(void *tgt);

#endif
