#ifndef PID_H_
#define PID_H_

typedef struct {
	int nSetPos;
	int nActPos;
	int nErr;
	int nErr_last;
	float Kp, Ki, Kd;
	int nIntegral;
	int nDiffer;
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
void pid_init(PIDCtrl pid, float Kp, float Ki, float Kd);

/*
* return the output of a pid
*
* @param a defined pid
*
* @param current value
*
* @param target value
*/
int pid_process(PIDCtrl pid, int posInput, int posAct);

void goForward(int distance, unsigned char speed, signed int estimateTime);

void rotate(int degree, unsigned char speed, signed int estimateTime);


extern void leftPIDLoop(void *tgt);

extern void rightPIDLoop(void *tgt);

#endif
