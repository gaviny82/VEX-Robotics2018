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
* @param proportion argument
*
* @param integral argument
*
* @param derivative argument
*
*/
extern void pid_init(PIDCtrl *pid, float Kp, float Ki, float Kd);

/*
* return the output of a pid
*
* @param a defined pid
*
* @param current value
*
* @param target value
*/
extern int pid_process(PIDCtrl *pid, int posInput, int posAct);

extern void go(int distance, unsigned char speed, signed int estimateTime);

extern void rotate(int degree, unsigned char speed, signed int estimateTime);


extern void leftPIDLoop(void *tgt);

extern void rightPIDLoop(void *tgt);

#endif
