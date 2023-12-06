#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int64_t determineWaysToBeatOneRace(int64_t time, int64_t distance)
{
	int64_t numberForSingleRace = 0;
	for(int i = 1; i < time; i++)
	{
		int64_t speed = i;
		int64_t timeForRacin = time - i;
		int64_t distanceTraveled = speed * timeForRacin;
		if(distanceTraveled > distance)
		{
			numberForSingleRace++;
		}

	}
	return numberForSingleRace;
}

int main()
{
	
	int64_t time{50748685};
	int64_t distance{242101716911252};

	std::cout << determineWaysToBeatOneRace(time, distance);
	
}
