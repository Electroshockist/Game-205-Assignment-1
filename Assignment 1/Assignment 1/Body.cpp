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
			cosf(angle * PI / 180) * force.x - sinf(angle * PI / 180) * force.y,
			sinf(angle * PI / 180) * force.x + cosf(angle * PI / 180) * force.y);

	acceleration = acceleration + worldForce / mass;

}


void Body::Update(float timeStep) {
	//calculates angle using theta_f = theta_i + omega_i*delta(time) + alpha * (delta(time))^2
	//I update theta, x and y first, so that I don't have to keep seperate variables for initial values
	angle += angularVelocity * timeStep + (angularAcceleration*pow(timeStep, 2)) / 2;
	
	velocity = velocity * timeStep + (acceleration*pow(timeStep, 2)) / 2;

	//calculate angular velocity using omega_f = omega_i + alpha * delta(time)
	angularVelocity += angularAcceleration * timeStep;

	//calculate velocity using v_f = v_i + accel * delta(time)
	velocity = velocity + acceleration * timeStep;

	printf("%f\t%f\t%f\t%f, %f\t%f, %f\t %f, %f\n", angularAcceleration, angularVelocity, angle, acceleration.x, acceleration.y, velocity.x, velocity.y, position.x, position.y);
}

