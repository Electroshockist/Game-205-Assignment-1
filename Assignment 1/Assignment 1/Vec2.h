#ifndef VEC2_H
#define VEC2_H

#include <iostream>
class Vec2
{
public:
	float x, y;
	Vec2();
	Vec2(float x, float y);
	void print();
	~Vec2();

	//Add vectors
	inline Vec2 operator += (const Vec2& v)const {
		Vec2 butt(x + v.x, y + v.y);
		//butt.print();
		return butt;
	}
	//Multiply vectors
	inline Vec2 operator *= (const Vec2& v)const {		
		Vec2 butt(x * v.x, y * v.y);
		//butt.print();
		return butt;
	}
	//Add vectors
	inline Vec2 operator + (const Vec2& v)const {
		return Vec2(x + v.x, y + v.y);
	}
	//Subtract vectors
	inline Vec2 operator - (const Vec2& v)const {
		return Vec2(x - v.x, y - v.y);
	}
	//Multiply vectors
	inline Vec2 operator * (const Vec2& v)const {
		return Vec2(x * v.x, y * v.y);
	}
	//Multiply vector by float
	inline Vec2 operator * (const float& f)const {
		return Vec2(x * f, y * f);
	}
	//Divide vectors
	inline Vec2 operator / (const Vec2& v)const {
		return Vec2(x / v.x, y / v.y);
	}
	//Divide vector by float
	inline Vec2 operator / (const float& f)const {
		return Vec2(x / f, y / f);
	}
};
#endif

