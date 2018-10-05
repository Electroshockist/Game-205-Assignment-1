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

void Body::Update(float timeStep) {
	//for accuracy
	float timeStepMiliseconds = timeStep * 1000;

	//position += velocity;
	velocity.x += acceleration.x * timeStep;
	velocity.y += acceleration.y * timeStep;

	velocity.print();

	//printf("pos: %f, %f\tvel: %f, %f\tacc: %f, %f\n", position.x, position.y, velocity.x, velocity.y, acceleration.x, acceleration.y);

	sleep_for(milliseconds((int)timeStepMiliseconds));
	Update(timeStep);
}

Body::~Body() {
}
