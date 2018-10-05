#include "Body.h"

Body::Body() {
	mass = 0;
	rotationalInertia = 0;

	onCreate();
}

Body::Body(float mass, float rotationalInertia) {
	this->mass = mass;
	this->rotationalInertia = rotationalInertia;

	onCreate();
}

void Body::onCreate() {
	lastUpdateTime = system_clock::now();
}

void Body::ApplyTorque(float torque) {
	angularAcceleration = torque / rotationalInertia;
}

void Body::ApplyForce(Vec2 force) {
	acceleration.x = force.x / mass;
}

void Body::Update(int timeStepMiliseconds) {
	printf("butt\n");
	sleep_for(milliseconds(timeStepMiliseconds));
	Update(timeStepMiliseconds);
}

Body::~Body() {
}
