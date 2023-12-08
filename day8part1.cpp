#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map> 

void loopString(std::string directions, std::unordered_map<std::string, std::string> Lmap, std::unordered_map<std::string, std::string> Rmap, int totalHits, std::string nextHit)
{
	bool done = false;

	for(std::string::size_type i = 0; i < directions.size(); ++i)
	{
		if(directions[i] == 'L')
		{
			nextHit = Lmap[nextHit];
			totalHits++;
		}
		else if(directions[i] == 'R')
		{
			nextHit = Rmap[nextHit];
			totalHits++;
		}
		if(nextHit == "ZZZ")
		{
			std::cout << "Total hits to get there equals " << totalHits;
			done = true;


		}
	}
	if(!done)
	{
		loopString(directions, Lmap, Rmap, totalHits, nextHit);
	}

}

int main()
{
	std::unordered_map<std::string, std::string> Lmap;
	std::unordered_map<std::string, std::string> Rmap;
	long long int totalHits = 0;
	std::string line;
	std::fstream file("input8.txt");
	std::string directions = "LRLRRRLRLLRRLRLRRRLRLRRLRRLLRLRRLRRLRRRLRRRLRLRRRLRLRRLRRLLRLRLLLLLRLRLRRLLRRRLLLRLLLRRLLLLLRLLLRLRRLRRLRRRLRRRLRRLRRLRRRLRLRLRRLRLRLRLRRLRRRLLRLLRRLRLRRRLRLRRRLRLRRRLRRRLRRLRLLLLRLRRRLRLRRLRLRRLRRLRRLLRRRLLLLLLRLRRRLRRLLRRRLRRLLLRLRLRLRRRLRRLRLRRRLRRLRRRLLRRLRRLLLRRRR";
	while(std::getline(file, line))
	{
		Lmap[line.substr(0, 3)] = line.substr(7, 3);
		Rmap[line.substr(0, 3)] = line.substr(12, 3);
	}
	std::string nextHit = "AAA";
	loopString(directions, Lmap, Rmap,totalHits,nextHit);

	return 0;
	
}
