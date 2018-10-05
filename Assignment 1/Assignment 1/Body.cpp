#include "Body.h"

Body::Body() {
	mass = 0;
	rotationalInertia = 0;
}

Body::Body(float mass, float rotationalInertia) {
	this->mass = mass;
	this->rotationalInertia = rotationalInertia;
}

void Body::ApplyTorque(float torque) {
	angularAcceleration = torque / rotationalInertia;
}

void Body::ApplyForce(Vec2 force) {
	acceleration.x = force.x / mass;
}

void Body::Update(int timeStepMiliseconds) {
	sleep_for(milliseconds(timeStepMiliseconds));
	Update(timeStepMiliseconds);
}

Body::~Body() {
}
