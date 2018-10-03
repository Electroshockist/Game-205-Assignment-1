#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include "Vec2.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class Body {
public:
	float mass, rotationalInertia, angle, angularVelocity, angularAcceleration;
	Vec2 positon, veocity, acceleration;

	system_clock::time_point currentTime;
	system_clock::time_point lastUpdateTime;
	
	Body();

	Body(float mass, float rotationalInertia);

	void onCreate();

	void ApplyTorque(float torque);

	void ApplyForce(Vec2 force);

	void Update(int timeStepMiliseconds);

	~Body();
};

