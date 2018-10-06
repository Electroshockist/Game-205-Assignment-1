#include "Vec2.h"


Vec2::Vec2() {
	x = 0;
	y = 0;
}

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vec2::print() {
	printf("x: %f, y: %f\n", x, y);
}

