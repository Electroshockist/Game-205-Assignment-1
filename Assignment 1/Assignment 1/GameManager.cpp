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

	//at time = 0, apply 5 * 10^7 N of force
	if (totalTime == 0) starship.ApplyForce(Vec2(5 * pow(10,7), 0));

	//apply counterclockwise spin of  at 31 seconds
	if (totalTime == 31) starship.ApplyTorque(-6.291 * pow(10, 8));

	if (totalTime == 51) starship.acceleration = Vec2();

	//updates body(do not calculate beyond this point)
	starship.Update(timeStep);

	//sleeps thread till next update
	sleep_for(milliseconds((int)timeStepMiliseconds));

	//update (do last)
	totalTime += timeStep;
	Update(timeStep);
}