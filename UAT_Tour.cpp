/*Dmitrii Orlov
    2/6/22
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    //proffessors array
    string profs[10]={ "Maureen Beam", "Craig Belanger", "Dr. David Bolman", "Sharon Bolman", "Dr. David Brokaw", "Dr. Jill Coddington", "Dr. Steven Cofrancesco", "Nathan Glover", "Tony Hinton", "Matthew Prater"};

    //rooms arrays
    string rooms[21] = { "Theater", "135", "108", "107", "106", "252", "253", "245", "244", "235", "234", "232", "231", "207", "206", "203", "202", "208", "205", "204", "201" };

    //creates random number
    srand(static_cast<unsigned int>(time(0)));
    int user_guess;

    int random = rand() % 10 + 1;;

    //1st floor array/map
    int FloorOne[50][70];

    //2nd floor array/map
    int FloorTwo[50][70];

    //varubale for floor
    int floor = 0;

    //variable for room
    int room = 1;

    cout << "1st Floor" << endl;
    cout << endl;
    //vertical
    for (int i = 0; i < 50; i++) {
        //horizontal
        for (int j = 0; j < 70; j++) {

            if (i >= 0 && j >= 0) {
                FloorOne[i][j] = floor;
            }

            //student services
            if (i <= 20 && j <= 10) {
                FloorOne[i][j] = room;
            }

            //cindery
            if (i >= 30 && j <= 10) {
                FloorOne[i][j] = room;
            }

            //theatre
            if (i <= 10 && j >= 15 && j <= 35) {
                FloorOne[i][j] = room;
            }

            //bathrooms
            if (i >= 10 && i <= 20 && j >= 50 && j <= 60) {
                FloorOne[i][j] = room;
            }

            //108,107,106
            if (i >= 25 && i <= 40 && j >= 50 && j <= 70) {
                FloorOne[i][j] = room;
            }

            //commons
            if (i >= 20 && j >= 15 && j <= 35) {
                FloorOne[i][j] = room;
            }
        
            cout << FloorOne[i][j] << " ";
        }
        cout << endl;
    }
    cout << " " << endl;
    cout << "2nd Floor" << endl;
    cout << " " << endl;
    //vertical
    for (int k = 0; k < 50; k++) {
        //horizontal
        for (int l = 0; l < 70; l++) {

            if (k >= 0 && l >= 0) {
                FloorTwo[k][l] = floor;
            }

            //235, 234
            if (k <= 10 && l >= 20 && l <= 40) {
                FloorTwo[k][l] = room;
            }

            //232, 231
            if (k >= 15 && k <= 25  && l >= 20 && l <= 40) {
                FloorTwo[k][l] = room;
            }

            //corporate center, 252, 253
            if (k >=0 && k <=20 && l >= 0 && l < 19) {
                FloorTwo[k][l] = room;
            }

            //245, 244
            if (k >= 30 && k <= 50 && l >= 0 && l <= 20) {
                FloorTwo[k][l] = room;
            }

            //faculty area
            if (k >= 0 && k <= 25 && l >= 45 && l <= 70) {
                FloorTwo[k][l] = room;
            }

            //201-208
            if (k >= 30 && k <= 50 && l >= 35 && l <= 70) {
                FloorTwo[k][l] = room;
            }
            cout << FloorTwo[k][l] << " ";
        }
        cout << endl;
    }
   
    
    //randomizer
    cout << "Please, guess a number from 1 - 10: ";
    cin >> user_guess;

   
    //loop for guess game
    do {
        cout << "Wrong! Do it again" << endl;
        cin >> user_guess;
        if (user_guess == random) {
            cout << "Yay! Tour is over!" << endl;
            Beep(523, 500);

        }

    } while (random != user_guess);

    return 0;
}