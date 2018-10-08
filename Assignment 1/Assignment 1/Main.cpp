#include "GameManager.h"

using namespace std;

const float framerate = 1.0f;

GameManager gameManager;

int main() {	
	gameManager.Update(framerate);
	getchar();
}
