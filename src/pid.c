#include "pid.h"

void pid_init(pidctrl pid,float Kp,float Ki,float Kd)
{
	pid.Kp=Kp;
	pid.Ki=Ki;
	pid.Kd=Kd;
	pid.nSetPos=0;
	pid.nActPos=0;
	pid.nErr=0;
	pid.nErr_last=0;
	pid.nIntegral=0;
	pid.nDiffer=0;
	pid.nPowerOut=0.0;
}

int pid_process(pidctrl pid,int posInput,int posAct)
{
	pid.nSetPos=posInput;
	pid.nActPos=posAct;
	pid.nErr=pid.nSetPos-pid.nActPos;
	pid.nIntegral=pid.nErr_last+pid.nErr;
	pid.nDiffer=pid.nErr_last-pid.nErr;
	pid.nPowerOut=pid.Kp*pid.nErr+pid.Ki*pid.nIntegral+pid.Kd*pid.nDiffer;
	pid.nErr_last=pid.nErr;
	return (int)pid.nPowerOut;
}
