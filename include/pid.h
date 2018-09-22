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

void pid_init(pidctrl pid, float Kp, float Ki, float Kd);

int pid_process(pidctrl pid, int posInput, int posAct);



#endif
