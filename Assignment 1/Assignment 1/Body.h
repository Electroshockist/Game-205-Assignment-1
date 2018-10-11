#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include "Vec2.h"

#define PI 3.14159265

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class Body {
public:
	float mass, rotationalInertia, angle, angularVelocity, angularAcceleration;
	Vec2 position, velocity, acceleration;
	
	Body();

	Body(float mass, float rotationalInertia);

	void ApplyTorque(float torque);

	void ApplyForce(Vec2 force);

	void Update(float timeStep);
};

