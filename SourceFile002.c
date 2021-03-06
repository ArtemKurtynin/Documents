#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true)
	{
		int hold;

		//Claw Hold
		if(vexRT[Btn6UXmtr2]==1) // button 6U, partner controller
		{
			motor[claw] = 127; // motor power
			hold = 0;
		}
		//Claw Let Go
		else if(vexRT[Btn6DXmtr2]==1) // button 6D, partner controller
		{
			motor[claw] = -127; // motor power
			hold = 1;
		}
		//Claw Hold On
		else if (hold == 0)
		{
			motor[claw] = 42;
		}
		else if (hold == 1)
		{
			motor[claw] = -127;
		}
		else {
			motor[claw] = 0;
		}

	}
}
