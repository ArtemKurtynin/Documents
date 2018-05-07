#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, dgtl1,  encoder_left,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoder_right,  sensorQuadEncoder)
#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           drive_left,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           drive_right,   tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           mobile_goal_intake, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           lift_top_left, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift_bottom_left, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           lift_top_right, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           lift_bottom_right, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           left_chainbar, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          right_chainbar, tmotorVex393_HBridge, openLoop, reversed)


#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"


int myauto = 1;

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;


void autoselector(){
		clearLCDLine(0);
    clearLCDLine(1);
    bLCDBacklight = true;
		while(bIfiRobotDisabled){
			switch(myauto){
				case(1):
					displayLCDCenteredString(0, "Autonomous 1");
					displayLCDCenteredString(1, "1010X");
						if(nLCDButtons == leftButton){
							while(nLCDButtons != 0){}
							wait1Msec(5);
							myauto = 1;
							}
						else if(nLCDButtons == rightButton){
							while(nLCDButtons != 0){}
							wait1Msec(5);
							myauto = 2;
						}
						else{}
				break;
				case(2):
					displayLCDCenteredString(0, "Autonomous 2");
					displayLCDCenteredString(1, "1010X");

					if(nLCDButtons == leftButton){
						while(nLCDButtons != 0){}
						wait1Msec(5);
						myauto = 1;
						}
					else if(nLCDButtons == rightButton){
						while(nLCDButtons != 0){}
						wait1Msec(5);
						myauto = 3;
						}
					else{}
				break;
				case(3):
					displayLCDCenteredString(0, "Autonomous 3");
					displayLCDCenteredString(1, "1010X");

					if(nLCDButtons == leftButton){
						while(nLCDButtons != 0){}
						wait1Msec(5);
						myauto = 2;
						}
					else if(nLCDButtons == rightButton){
						while(nLCDButtons != 0){}
						wait1Msec(5);
						myauto = 4;
						}
					else{}
				break;
				case(4):
					displayLCDCenteredString(0, "Autonomous 4");
					displayLCDCenteredString(1, "1010X");

					if(nLCDButtons == leftButton){
						while(nLCDButtons != 0){}
						wait1Msec(5);
						myauto = 3;
						}
					else if(nLCDButtons == rightButton){
						while(nLCDButtons != 0){}
						wait1Msec(5);
						myauto = 4;
						}
					else{}
				break;

				break;

				default:
					myauto = 1;
				break;
				}
			}
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
bStopTasksBetweenModes = true;
bDisplayCompetitionStatusOnLcd = false;


	SensorType[in3] = sensorNone;
 	wait1Msec(1000);
 	SensorType[in3] = sensorGyro;
	wait1Msec(2000);//wait needed to calibrate

	autoselector();
}
/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void autorunrollers (int rollerpower){
	motor[RollL] = motor[RollR] = rollerpower;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void autostoprollers(){
	motor[RollL] = motor[RollR] = 0;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void autoopenrollers(){
		wait1Msec(10);
		motor[RollL] = motor[RollR] = -90;//backwards
		wait1Msec(350);
		motor[RollL] = motor[RollR] = 0;//stop for short period
		wait1Msec(80);
		motor[RollL] = motor[RollR] = 90;//forwards
		wait1Msec(500);
		motor[RollL] = motor[RollR] = 0;//stop for shortperiod
		wait1Msec(20);

}
///////////////////////////////////////////////
void autoarmliftsimpleup(int armpower1, int armheight1){


while (SensorValue[potarmR] <= armheight1){
	motor[ArmLB] =  motor[ArmLT] =	motor[ArmRB] =  motor[ArmRT] = armpower1;
}

motor[ArmLB] =  motor[ArmLT] = motor[ArmRB] =  motor[ArmRT] = 0;
	wait1Msec(10);
}

////////////////////////////////////////////////
void autoarmliftsimpledown(int armpower2, int armheight2){
	while (SensorValue[potarmR] >= armheight2){
	motor[ArmLB] =  motor[ArmLT] =	motor[ArmRB] =  motor[ArmRT] = armpower2;
}

motor[ArmLB] =  motor[ArmLT] = motor[ArmRB] =  motor[ArmRT] = 0;
	wait1Msec(10);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void autoarmlift(int armpower, int armheight){ //negitive value for lowwering arm
	SensorValue[potarmL] = 0;
	SensorValue[potarmR] = 0;
			while (SensorValue[potarmL] <= armheight  && SensorValue[potarmR] <= armheight){
					if(SensorValue[potarmL] <= armheight){		//left
						motor[ArmLB] =  motor[ArmLT] = armpower;
					}else{
						motor[ArmLB] =  motor[ArmLT] = 0;}
					if (SensorValue[potarmR] <= armheight){			//right
						motor[ArmRB] =  motor[ArmRT] = armpower;
					}else{
						motor[ArmRB] =  motor[ArmRT] = 0;}
			}
	motor[ArmLB] =  motor[ArmLT] = motor[ArmRB] =  motor[ArmRT] = 0;
	wait1Msec(10);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void autodrivestraight (float kp, int distics, int timestep = 20){

	int totaltics = 0;
	int error = 0;
	int Rpower = 100;
	int Lpower = 100;

	SensorValue[encoderL] = 0;
	SensorValue[encoderR] = 0;

	while (distics >= totaltics){
		motor[DriveBL] = motor[DriveFL] = Lpower;
		motor[DriveBR] = motor[DriveFR] = Rpower;

		error = -SensorValue[encoderL] - SensorValue[encoderR];

		Lpower += -error * kp;//neg error for decrease when left side is too far

		Lpower = floor(Lpower);

		totaltics = (-SensorValue[encoderL] + SensorValue[encoderR])/2;

		//SensorValue[encoderL] = 0;
		//SensorValue[encoderR] = 0;
/*datalogDataGroupStart();
datalogAddValueWithTimeStamp(1, error);
datalogAddValueWithTimeStamp(2, Lpower);
datalogDataGroupEnd();
*/
		wait1Msec(timestep);
		}
	motor[DriveBL] = motor[DriveFL] = 0;
	motor[DriveBR] = motor[DriveFR] = 0;
	wait1Msec(10);
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void autogyroturnL(int powerturnL, int powerturnR, int gyrovalue){

SensorValue[gyro] = 0;
	while (SensorValue[gyro] >= gyrovalue){
		motor[DriveBL] = motor[DriveFL] = powerturnL;
		motor[DriveBR] = motor[DriveFR] = powerturnR;
	}
	motor[DriveBL] = motor[DriveFL] = motor[DriveBR] = motor[DriveFR] = 0;
	wait1Msec(10);}


void autogyroturnR(int powerturnL1, int powerturnR1, int gyrovalue){
	SensorValue[gyro] = 0;
		while (SensorValue[gyro] <= gyrovalue){
			motor[DriveBL] = motor[DriveFL] = powerturnL1;
			motor[DriveBR] = motor[DriveFR] = powerturnR1;
		}
		motor[DriveBL] = motor[DriveFL] = motor[DriveBR] = motor[DriveFR] = 0;
		wait1Msec(10);

}
