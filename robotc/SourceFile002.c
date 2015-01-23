#pragma config(Sensor, S1,     ColorSensor,    sensorEV3_Color)
#pragma config(Sensor, S4,     UltrasonicSensor, sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          Arm,           tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	resetMotorEncoder(LeftTire);
	resetMotorEncoder(RightTire);

	motor[LeftTire]=20;
	motor[RightTire]=20;

	while (getMotorEncoder(LeftTire) < 1000)
	{
	}

	motor[LeftTire]=0;
	motor[RightTire]=0;
	displayBigTextLine(1,"left -> %d",getMotorEncoder(LeftTire));
	displayBigTextLine(4,"right -> %d",getMotorEncoder(RightTire));

	sleep(5000);

	resetMotorEncoder(LeftTire);
	resetMotorEncoder(RightTire);

	setMotorSyncEncoder(LeftTire,RightTire,0,1000,100);

	while (getMotorRunning(LeftTire))
	{
	}

	displayBigTextLine(1,"left -> %d",getMotorEncoder(LeftTire));
	displayBigTextLine(4,"right -> %d",getMotorEncoder(RightTire));

	sleep(5000);
};
