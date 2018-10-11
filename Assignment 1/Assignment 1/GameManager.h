#include <iostream>
//#include <chrono>
//#include <thread>
#include <fstream>      // std::ofstream

using namespace std;
//using namespace std::this_thread; // sleep_for, sleep_until
//using namespace std::chrono; // nanoseconds, system_clock, seconds

class GameManager
{
public:
	GameManager();

	float totalTime;	

	void Update(float timeStep);

	ofstream file;
};
