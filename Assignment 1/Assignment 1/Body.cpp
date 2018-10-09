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
	initialVelocity = velocity;

	//figure out why this doesn't work
	//velocity += (acceleration * timeStep);

	//calculates vfinal
	velocity = initialVelocity + (acceleration * timeStep);

	//s = vInitial * time + ((a*t)^2)/2
	position = position + ((initialVelocity + velocity) / 2) * timeStep;

	printf("pos: %f, %f\tvel: %f, %f\tacc: %f, %f\n", position.x, position.y, velocity.x, velocity.y, acceleration.x, acceleration.y);
}

Body::~Body() {
}
