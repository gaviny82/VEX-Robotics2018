#ifndef PID_H_
#define PID_H_

typedef struct _pidctrl
{
	int nSetPos;
	int nActPos;
	int nErr;
	int nErr_last;
	float Kp, Ki, Kd;
	int nIntegral;
	int nDiffer;
	float nPowerOut;
} pidctrl;

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
void pid_init(pidctrl pid, float Kp, float Ki, float Kd);

/*
* return the output of a pid
*
* @param a defined pid
*
* @param current value
*
* @param target value
*/
int pid_process(pidctrl pid, int posInput, int posAct);


//TODO: use pid to control the distance moved
void goForward(int distance, unsigned char speed, signed int estimateTime);

//TODO: use pid to control the angle rotated
void rotate(int degree, unsigned char speed, signed int estimateTime);


extern void leftPIDLoop(void *tgt);

extern void rightPIDLoop(void *tgt);

#endif
