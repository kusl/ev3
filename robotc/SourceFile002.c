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
	int GoBackLeftTire = 0;
	int GoBackRightTire = 0;
	while(true)
	{
		motor[LeftTire]=90;
		motor[RightTire]=90;
		while(SensorValue(ColorSensor) < 14){setMotorSyncEncoder(LeftTire, RightTire, 0, 1000, 90);}
		motor[LeftTire] = 0;
		motor[RightTire] = 0;
		moveMotorTarget(LeftTire, 80, 40);
		while (getMotorMoving(LeftTire))
		{
			if (SensorValue(ColorSensor) < 14)
			{
				GoBackLeftTire = 0;
				break;
			}
		}
		moveMotorTarget(LeftTire, 80, -40);
		GoBackLeftTire++;
		while (getMotorMoving(LeftTire))
		{
			if (SensorValue(ColorSensor) < 14)
			{
				break;
			}
		}
		moveMotorTarget(RightTire, 80, 40);
		while (getMotorMoving(RightTire))
		{
			if (SensorValue(ColorSensor) < 14)
			{
				break;
			}
		}
		moveMotorTarget(RightTire, 80, -40);
		GoBackRightTire++;
		while (getMotorMoving(RightTire))
		{
			if (SensorValue(ColorSensor) < 14)
			{
				GoBackLeftTire = 0;
				break;
			}
		}
	}
};
