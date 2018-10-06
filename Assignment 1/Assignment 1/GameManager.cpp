#include "GameManager.h"
#include "Body.h"

Body starship = Body(pow(10, 6), 2.67 * pow(10, 10));

GameManager::GameManager() {
	totalTime = 0.0f;
}

void GameManager::Update(float timeStep) {
	//for accuracy (will be cast to int later)
	float timeStepMiliseconds = timeStep * 1000;

	//set starship pos to 0,0
	starship.position = Vec2();
	if (totalTime == 0) {
		float e = pow(10, 8);
		Vec2 accel = Vec2(6.291 * e, 0);
		starship.ApplyForce(accel);
	}

	//updates body(do not calculate beyond this point)
	starship.Update(timeStep);

	//sleeps thread till next update
	sleep_for(milliseconds((int)timeStepMiliseconds));

	//update (do last)
	totalTime += timeStep;
	Update(timeStep);
}