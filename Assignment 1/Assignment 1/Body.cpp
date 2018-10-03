#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include "Body.h"

Body::Body() {
	mass = 0;
	rotationalInertia = 0;
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Time to fill and iterate a vector of "<< size << " ints : " << diff.count() << " s\n";
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
}

Body::~Body() {
}
