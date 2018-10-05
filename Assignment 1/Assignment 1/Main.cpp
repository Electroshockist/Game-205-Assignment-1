#include "Body.h"

using namespace std;

const float framerate = 0.033f;

Body starship = Body(pow(10, 6), 2.67 * pow(10, 10));

void main() {
	//set starship pos to 0,0
	starship.position = Vec2();
	starship.acceleration = Vec2(3.0f,5.2f);

	//updates body (do last)
	starship.Update(framerate);
	getchar();
}