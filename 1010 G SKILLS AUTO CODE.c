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


void pre_auton()
{
	bStopTasksBetweenModes = true;
}


task autonomous()
{

	motor[claw] = 127;
	wait1Msec(100);
	motor[left_chainbar] = 127; // lifts the chainbar up
	motor[right_chainbar] = -127; // lifts the chainbar up
	motor[mobile_goal_intake] = -127;	// put mobile goal intake down
	wait1Msec(600); // lasting period
	motor[mobile_goal_intake] = 0; // stop
	motor[left_chainbar] = 0; // stop
	motor[right_chainbar] = 0; // stop
	motor[claw] = 0;


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 600 && abs(SensorValue[encoder_left]) < 600) // drive into the first mobile goal
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[left_chainbar] = -127; // puts the chainbar down
	motor[right_chainbar] = 127; // puts the chainbar down
	wait1Msec(400); // lasting period
	motor[left_chainbar] = 0; // stop
	motor[right_chainbar] = 0; // stop
	motor[claw] = 0;


	motor[claw] = -127; // claw release
	wait1Msec(40); // lasting period
	motor[claw] = 0; // stop


	motor[claw] = -127; // claw open
	motor[left_chainbar] = 127; // lifts the chainbar up
	motor[right_chainbar] = -127; // lifts the chainbar up
	wait1Msec(300); // lasting period
	motor[left_chainbar] = 0; // stop
	motor[right_chainbar] = 0; // stop
	motor[claw] = 0; // stop


	motor(mobile_goal_intake) = 127;	// pick up mobile goal
	wait1Msec(1350); // lasting period
	motor(mobile_goal_intake) = 0; //stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 30 && abs(SensorValue[encoder_left]) < 30) // drive back
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 1420)	// turn 180 degrees
	{
		motor[drive_right] = -127; // motor power
	}
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 700 && abs(SensorValue[encoder_left]) < 700) // drive into the 20-point zone pipe
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = -127; // put mobile goal down
	wait1Msec(1300); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 30 && abs(SensorValue[encoder_left]) < 30) // drive back a bit
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 50 && abs(SensorValue[encoder_left]) < 50) // drive back a bit
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 30 && abs(SensorValue[encoder_left]) < 30) // drive back a bit
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = 127; // lift mobile goal intake
	wait1Msec(900); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 500 && abs(SensorValue[encoder_left]) < 500) // drive out of the 10-point zone
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_left]) < 450)	// turn 140 degrees
	{
		motor[drive_left] = 127; // motor power
	}
	motor[drive_left] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 900 && abs(SensorValue[encoder_left]) < 900) // drive to the left side
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 200)	// face the wall
	{
		motor[drive_right] = 127; // motor power
	}
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 200 && abs(SensorValue[encoder_left]) < 200) // drive into the wall
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 200 && abs(SensorValue[encoder_left]) < 200) // drive back
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 400 && abs(SensorValue[encoder_left]) < 400) // turn right 90 degrees
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 650 && abs(SensorValue[encoder_left]) < 650) // drive into the second mobile goal
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = 127; // pickup second mobile goal
	wait1Msec(1300); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 850 && abs(SensorValue[encoder_left]) < 850) // drive back to the 10-point zone
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 300 && abs(SensorValue[encoder_left]) < 300) // drive forward
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 800 && abs(SensorValue[encoder_left]) < 800) // turn 180 degrees right
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 320 && abs(SensorValue[encoder_left]) < 320) // hit 10-point zone pipe
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = -127; // put second mobile goal down
	wait1Msec(1000); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 50 && abs(SensorValue[encoder_left]) < 50) // drive back a bit
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = 127; // lift mobile goal itake
	wait1Msec(300); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 300 && abs(SensorValue[encoder_left]) < 300) // drive away
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 1500)	// turn 180 degrees
	{
		motor[drive_right] = -127; // motor power
	}
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 300 && abs(SensorValue[encoder_left]) < 300) // hit the 10-point zone pipe
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 600 && abs(SensorValue[encoder_left]) < 600) // drive into the third mobile goal
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = 127; // pickup third mobile goal
	wait1Msec(1300); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 30 && abs(SensorValue[encoder_left]) < 30) // drive back
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_left]) < 1420)	// turn 180 degrees
	{
		motor[drive_left] = -127; // motor power
	}
	motor[drive_left] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 200 && abs(SensorValue[encoder_left]) < 200) // drive back
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = -127; // put third mobile goal down
	wait1Msec(900); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 50 && abs(SensorValue[encoder_left]) < 50) // drive back
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = 127; // pickup mobile goal
	wait1Msec(300); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 50 && abs(SensorValue[encoder_left]) < 50) // drive back
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 800)	// turn 180 degrees
	{
		motor[drive_right] = -127; // motor power
	}
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 500 && abs(SensorValue[encoder_left]) < 500) // drive back
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 800)	// turn 180 degrees
	{
		motor[drive_right] = -127; // motor power
	}
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 100 && abs(SensorValue[encoder_left]) < 100) // drive back
	{
		motor[drive_left] = -127; // motor power
		motor[drive_right] = -127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 1300 && abs(SensorValue[encoder_left]) < 1300) // drive to the fourth mobile goal
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = 127; // pickup mobile goal
	wait1Msec(1300); // lasting period
	motor[mobile_goal_intake] = 0; // stop


	SensorValue[encoder_left] = 0; // reset encoder
	SensorValue[encoder_right] = 0; // reset encoder

	while(abs(SensorValue[encoder_right]) < 1000 && abs(SensorValue[encoder_left]) < 1000) // drive to the fourth mobile goal
	{
		motor[drive_left] = 127; // motor power
		motor[drive_right] = 127; // motor power
	}
	motor[drive_left] = 0; // stop
	motor[drive_right] = 0; // stop


	motor[mobile_goal_intake] = 127; // put mobile goal down
	wait1Msec(900); // lasting period
	motor[mobile_goal_intake] = 0; // stop




}	// end autonomous



task usercontrol()	// controller setup

{

	while (true)

	{

		int X1 = vexRT[Ch3]; // forward & back drive, left joystick, main controller
		int Y1 = vexRT[Ch1]; // turn right and left, right joystick, main controller
		motor[drive_right] = X1 - Y1;
		motor[drive_left] = X1 + Y1;


		motor[lift_top_left] = vexRT[Ch3Xmtr2]; // lift, left joystick, partner controller
		motor[lift_bottom_left] = vexRT[Ch3Xmtr2]; // lift, left joystick, partner controller
		motor[lift_top_right] = vexRT[Ch3Xmtr2]; // lift, left joystick, partner controller
		motor[lift_bottom_right] = vexRT[Ch3Xmtr2]; // lift, left joystick, partner controller


		if(vexRT[Btn6UXmtr2]==1) // button 6U, partner controller
		{
			motor[claw] = 127; // motor power
		}
		else if(vexRT[Btn6DXmtr2]==1) // button 6D, partner controller
		{
			motor[claw] = -127; // motor power
		}
		else // if buttons are not pressed
		{
			motor[claw] = 0; // motor power
		}


		if(vexRT[Btn6U]==1) // button 6U, main controller
		{
			motor[mobile_goal_intake] = 127; // motor power
		}
		else if(vexRT[Btn6D]==1) // button 6D, main controller
		{
			motor[mobile_goal_intake] = -127; // motor power
		}
		else // if buttons are not pressed
		{
			motor[mobile_goal_intake] = 0; // motor power
		}


		if(vexRT[Btn5UXmtr2]==1) // button 5U, partner controller
		{
			motor[left_chainbar] = 127; // motor power
			motor[right_chainbar] = -127; // motor power
		}
		else if(vexRT[Btn5DXmtr2]==1) // button 5D, partner controller
		{
			motor[left_chainbar] = -127; // motor power
			motor[right_chainbar] = 127; // motor power
		}
		else // if buttons are not pressed
		{
			motor[left_chainbar] = 0; // motor power
			motor[right_chainbar] = 0; // motor power
		}

	} // end while(true)

}	// end usercontrol()
