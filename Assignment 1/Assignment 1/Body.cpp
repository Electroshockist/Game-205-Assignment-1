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
	worldForce =
		Vec2(
		(cos(angle) * force.x) - (sin(angle) * force.y),
		(sin(angle) * force.x) + (cos(angle) * force.y));
	acceleration = worldForce / mass;
}

void Body::Update(float timeStep) {

	//step 1 and 2
	ApplyTorque(Torque);

	//calculates angle using theta_f = theta_i + omega_i*delta(time) + alpha * (delta(time))^2
	//I update theta first, so that I don't have to keep seperate variables for initial values
	angle += angularVelocity * timeStep + (angularAcceleration*pow(timeStep, 2)) / 2;//step 4

	//calculate angular velocity using omega_f = omega_i + alpha * delta(time)
	angularVelocity += angularAcceleration * timeStep;//step 3
	
	//step 5 and 6
	ApplyForce(relativeForce);
	
	//I update x and y first, so that I don't have to keep seperate variables for initial values
	position = position + (velocity * timeStep) + (acceleration * pow(timeStep, 2)) / 2;//step 8

	//calculate velocity using v_f = v_i + accel * delta(time)
	velocity = velocity + acceleration * timeStep;//step 7	
}

