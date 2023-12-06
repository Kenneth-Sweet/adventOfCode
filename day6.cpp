#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int determineWaysToBeatOneRace(int time, int distance)
{
	int numberForSingleRace = 0;
	for(int i = 1; i < time; i++)
	{
		int speed = i;
		int timeForRacin = time - i;
		int distanceTraveled = speed * timeForRacin;
		if(distanceTraveled > distance)
		{
			numberForSingleRace++;
		}

	}
	return numberForSingleRace;
}

int main()
{
	
	std::vector<int> numberOfWaysVector{};
	std::vector<int> time{50,74,86,85};
	std::vector<int> distance{242,1017,1691,1252};

	for(int i = 0; i < time.size(); i++)
	{
		int numberOfWays = determineWaysToBeatOneRace(time[i], distance[i]);
		numberOfWaysVector.emplace_back(numberOfWays);
	}
	int answer = 1;
	for(int value : numberOfWaysVector)
	{
		answer *= value;
	}
	cout << answer;
	
}
