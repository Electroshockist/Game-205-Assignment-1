#include "GameManager.h"
#include "Body.h"

Body starship = Body(pow(10, 6), 2.67 * pow(10, 10));

GameManager::GameManager() {
	totalTime = 0.0f;

	file.open("Resources/file.csv", fstream::trunc);
	file << "Time:,Angular Acceleration:,Angular Velocity:,Angle:,Acceleration: x:,y:,Velocity: x:,y:,Position: x:,y:" << endl;

	printf("Time:\tAngular Accel:\tAngular Vel:\tAngle:\t\tAcceleration:\t\tVelocity:\t\t\tPosition:\n");
}

void GameManager::Update(float timeStep) {
	//for accuracy (will be cast to int later)
	float timeStepMiliseconds = timeStep * 1000;

	//set starship pos to 0,0
	starship.position = Vec2();

	//less than or equal to a minute
	if (totalTime <= 60) {

		//cout << totalTime << "\t";

		//at time = 0, apply 5 * 10^7 N of force
		if (totalTime == 0) {
			starship.ApplyForce(Vec2(5 * pow(10, 7), 0));
		}

		//halve thrust and apply counterclockwise spin of 6.281 * 10 ^ 8 at 31 seconds
		if (totalTime == 31) {
			starship.ApplyForce(Vec2(5 * pow(10, 7) / 2, 0));
			starship.ApplyTorque(6.291 * pow(10, 8));
		}

		//reset acceleration to 0
		if (totalTime == 51) {
			starship.acceleration = Vec2(0, 0);
			starship.angularAcceleration = 0;
		}


		file << totalTime << "," << starship.angularAcceleration << "," << starship.angularVelocity << "," << starship.angle << "," 
			<< starship.acceleration.x << "," << starship.acceleration.y << "," 
			<< starship.velocity.x << "," << starship.velocity.y << "," 
			<< starship.position.x << "," << starship.position.y << endl;

		//updates body(do not calculate beyond this point)
		starship.Update(timeStep);

		//sleeps thread till next update (unnessecary for now)
		//sleep_for(milliseconds((int)timeStepMiliseconds));

		//update (do last)
		totalTime += timeStep;
		Update(timeStep);
	}
}