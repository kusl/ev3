#pragma config(Sensor, S1,     UltrasonicSensor, sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          Arm,           tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          LeftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int MaxDistance = 30;

void ResetAllMotorEncoders()
{
	resetMotorEncoder(Arm);
	resetMotorEncoder(LeftMotor);
	resetMotorEncoder(RightMotor);
}

task main()
{
	while(true)
	{
		ResetAllMotorEncoders();
		setMotorTarget(Arm, -90, 15);
		if(getUSDistance(UltrasonicSensor) < MaxDistance)
		{
			setMotorSyncEncoder(LeftMotor, RightMotor, 0, 360, 60);
		}
	}
}
