#pragma once
#include "Vec2.h"
class Body
{
public:
	float mass, rotationalInertia, angle, angularVelocity, angularAcceleration;
	Vec2 positon, veocity, acceleration;
	
	Body();

	Body(float mass, float rotationalInertia);

	void ApplyTorque(float torque);

	void ApplyForce(Vec2 force);

	void Update(float timeStep);

	~Body();
};

