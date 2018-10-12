#include "GameManager.h"
#include "Body.h"

Body starship = Body(1e+6f, 2.67e+10f);

GameManager::GameManager() {
	totalTime = 0.0f;

	file.open("Resources/file.csv", fstream::trunc);
	file << "Time:,Angular Acceleration:,Angular Velocity:,Angle:,Force: x:,y:,Acceleration: x:,y:,Velocity: x:,y:,Position: x:,y:" << endl;

	printf("Time:\tAngular Accel:\tAngular Vel:\tAngle:\tForce:\t\tAcceleration:\tVelocity:\tPosition:\n");
}

void GameManager::Update(float timeStep) {
	//less than or equal to a minute
	while (totalTime <= 60) {

		//at time = 0, apply 5 * 10^7 N of force
		if (totalTime == 0) {
			//set starship pos to 0,0
			starship.position = Vec2();
			starship.relativeForce.x = 5e+7f;
		}

		//halve thrust and apply counterclockwise spin of 6.281 * 10 ^ 8 at 31 seconds
		if (totalTime > 30 && totalTime < 50) {
			starship.relativeForce.x = 5e+7f / 2;
			starship.Torque = 6.291e+8f;
		}

		//reset acceleration to 0
		if (totalTime > 50) {
			starship.relativeForce = Vec2();
		}
				
		//updates body(do not calculate beyond this point)
		starship.ApplyTorque(starship.Torque);;
		starship.Update(timeStep);

		file << totalTime << "," << starship.angularAcceleration << "," << starship.angularVelocity << "," << starship.angle << ","
			<< starship.relativeForce.x << "," << starship.relativeForce.y << ","
			<< starship.acceleration.x << "," << starship.acceleration.y << ","
			<< starship.velocity.x << "," << starship.velocity.y << ","
			<< starship.position.x << "," << starship.position.y << endl;

		cout << /*totalTime << "\t" << starship.angularAcceleration << "\t\t" <<*/ starship.angularVelocity << "\t\t" << starship.angle << "\t"
			//<< starship.relativeForce.x << "\t" << starship.relativeForce.y << "\t" 
			<< starship.acceleration.x << "\t" << starship.acceleration.y << "\t" 
			<< starship.velocity.x << "\t" << starship.velocity.y << "\t" 
			<< starship.position.x << "\t" << starship.position.y << endl;

		//update (do last)
		totalTime += timeStep;
	}
}