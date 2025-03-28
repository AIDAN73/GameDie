#include "GameDie.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//class constructor that seeds the random number generator
GameDie::GameDie()
{
    srand(time(NULL));
    roll_counter.resize(FACES);

    for(int i=0; i<FACES; i++)
      roll_counter[i] = 0;
}

//overloaded constructor
GameDie::GameDie(unsigned int num)
{
    if( num == 0 )
    {
        roll_counter.resize(FACES);
    }
    else{
        roll_counter.resize(num);
    }
    for(int i=0; i<FACES; i++)
    {
        roll_counter[i] = 0;
    }

}

//generate a random number between 1-n where n is the counter size
// (inclusive) and return it
int GameDie::roll()
{
    int roll = rand() % roll_counter.size();
    roll_counter[roll]++;
    return roll + 1;
}

// return the count of how many times each face has been rolled, as a vector
// where each face's count is at index face-1 (i.e. Face 1 is at index 0)
vector <int> GameDie::get_distribution(){
    return roll_counter;
}


//return the percentage distribution of rolls
vector <int> GameDie::get_distribution_percentage()
{
	vector <int> percentages;
	int numRolls = 0;
	for (int i=0; i<FACES; i++)					//tally up all the rolls counted
	{
		numRolls = numRolls + counter[i];
	}
	for (int i=0; i<FACES; i++)					//calculate the percentage of each role
	{
		percentages[i] = (counter[i]/numRolls) * 100;
	}
    return percentages;							//return the vector of percentages
}
