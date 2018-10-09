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
	Vec2 worldForce = 
		Vec2(
		cos(angle)* (-sin(angle)) * force.x,
		sin(angle) * cos(angle) * force.y);

	acceleration = worldForce / mass;
}

void Body::Update(float timeStep) {

	//calculates angle using theta_f = theta_i + omega_i*delta(time) + alpha * (delta(time))^2
	//I update theta first, so that I don't have to keep a seperate variable for omega_i
	angle += angularVelocity * timeStep + (angularAcceleration*pow(timeStep, 2)) / 2;

	//calculate angular velocity using omega_f = omega_i + alpha * delta(time)
	angularVelocity += angularAcceleration * timeStep;

	printf("pos: %f, %f\tvel: %f, %f\tacc: %f, %f\n", position.x, position.y, velocity.x, velocity.y, acceleration.x, acceleration.y);
}

Body::~Body() {
}
