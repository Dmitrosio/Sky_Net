/*Dmitrii Orlov
  2/6/22
*/
#include <iostream>
#include <ctime>

using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));

	//created random number/position of the enemy on the grid from 1 to 64
	int enemy_location = rand() % 64 + 1;
		
	//highest number in the grid
	int searchGridHighNumber = 64;

	//lowest number in the grid.
	int searchGridLowNumber = 1;

	//variable for prediction enemy location
	int targetLocationPrediction;

	//variable for attempt counter
	int iterator = 0;

	cout << "Initilizing SkyNet ground search..." << endl;

	do {
		//binary search algorythm
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		//condition for checking enemy location and location prediction
		if (targetLocationPrediction == enemy_location) {
			//attempt increment
			iterator++;
			cout << "Yo we found him at location " << enemy_location << ". It took us " << iterator << "# times.";
		}
		//checks if location prediction is greater than enemy location
		else if (targetLocationPrediction > enemy_location) {
			// outputs the enemy not found at current location, updates the high end of the search pattern
			cout << "Enemy not found at location " << targetLocationPrediction
				<< ". Guess was too high. Attempt # " << (iterator + 1) << endl;
			searchGridHighNumber = targetLocationPrediction - 1;
		}
		else{
			// outputs the enemy not found at current location, updates the low end of the search pattern.
			cout << "Enemy not found at location " << targetLocationPrediction
				<< ". Guess was too low. Attempt # " << (iterator + 1) << endl;
			searchGridLowNumber = targetLocationPrediction + 1;
		}
		iterator++;

		//the algorthm repeats itself till the enemy found
	} while (targetLocationPrediction != enemy_location);
}