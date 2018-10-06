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
	acceleration = force / mass;
}

void Body::Update(float timeStep) {

	//s = vInitial*time + ((a*t)^2)/2
	//figure out why I need the if statements
	if (velocity.x < pow(timeStep, 2) / 2 || velocity.x > pow(timeStep, 2) / 2)
		position.x = velocity.x * timeStep + (acceleration.x * pow(timeStep, 2) / 2);

	if (velocity.y < pow(timeStep, 2) / 2 || velocity.x > pow(timeStep, 2) / 2)
		position.y = velocity.y * timeStep + (acceleration.y * pow(timeStep, 2) / 2);

	//calculates vfinal
	velocity += (acceleration * timeStep);
	

	printf("pos: %f, %f\tvel: %f, %f\tacc: %f, %f\n", position.x, position.y, velocity.x, velocity.y, acceleration.x, acceleration.y);
}

Body::~Body() {
}
