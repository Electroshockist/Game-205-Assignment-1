#include "GameManager.h"

using namespace std;

//per second
const float framerate = 1.0f;

GameManager gameManager;

int main() {	
	gameManager.Update(framerate);
	getchar();
}
