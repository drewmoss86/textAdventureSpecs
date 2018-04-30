/**********************************************************
*AUTHOR         : Andrew Moss
*Assignment #7  : Text Adventure Specification
*CLASS          : CS 002
*SECTION        : MTWR: 7:30a – 12:30p
*Due Date       : 1/25/17
**********************************************************/
/************************************************************
* TEXT ADVENTURE SPECIFICATION
* _________________________________________________________
* This program is a game based on user input
*
* _________________________________________________________
* INPUT:
*    char door;                      //character representing door selection
*    string userName;                //name of user
*    string monsterName;             //name of monster
*
*
* OUTPUT:
*    char door;                      //character representing door selection
*    string userName;                //name of user
*    string monsterName;             //name of monster
*
************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
/************************************************************
* FUNCTION PrintHeader
*_________________________________________________________
* These functions receive integers and strings and
*   then outputs the the respective conditions depending on
*   the selected room - all functions return nothing.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* 	void monsterRoom : room with monster selection, requires monster name,
*                       user name, orange and banana values
*   void genieRoom   : room with a genie, requires, user name
*                       orange and banana values
*   void drawPicture : picture to display, requires user name
*   void getOptions  : takes several input and calculated values to output
*                       corresponding values based on updated banana and orange
*                       values, user name, monster name, door selection, and
*                       alignment number.
*
* POST-CONDITIONS
*   void monsterRoom : changes banana and orange values to 0
*   void genieRoom   : adds 2 to banana value and 1 to orange value
* 	void pictureRoom : will output a pre-drawn picture function
* 	void drawPicture : displays a picture
*   void exit        : exits the game
*   void getOptions  : outputs results based on chosen door options
*
*

***********************************************************/
//Function prototype
void monsterRoom (int& , string monsterName, string userName);
void genieRoom (int&, int&, string userName);
void pictureRoom();
void drawPicture(string userName);
void exit(int &bananas, int &oranges);
void getOptions(int alignNum, char door, int &bananas, int &oranges,
                int stolenFruit, string monsterName, string userName);

int main(int argc, char *argv[])
{
    char door;                      //character representing door selection
    string userName;                //name of user
    string monsterName;             //name of monster
    int bananas = 5;                //starting number of bananas
    int oranges = 3;                //starting number of oranges
    int stolenFruit = 0;            //stolen oranges and bananas
    srand(500);                     //seeding random number generator
    int alignNum;                   //random number for alignment

    //INPUT: User name
    cout << "Please enter your name: ";
    cin >> userName;
    cout << endl;

    //INPUT: Monster name
    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;

    //OUTPUT: User name entered and starting values for bananas and oranges
    cout << userName << ", you are in a room with 4 doors." << endl;
    cout << "\nYou are carrying " << bananas << " bananas and "
         << oranges << " oranges." << endl;

    do {
    //INPUT: doors, with 1 or 4 options - N, E, S, W
    cout << "Pick a door to enter by typing the direction it is in (N/E/S/W): ";
    cin >> door;
    cout << endl;
        if (door == 'N' || door == 'E' || door == 'S' || door == 'W') {
            alignNum = rand() % 2;
            //PROCESSING: Function to process the randomly chosen alignment #,
            //user input door option, updated banana and orange values, result
            //fruit value zero, monster name and user name.
            getOptions(alignNum, door, bananas, oranges, stolenFruit,
                       monsterName, userName);
        }
    } while (door != 'N' || door != 'E' || door != 'S' || door != 'W');

}

//Function definition
//door = monster, bananas and oranges are reduced to 0
void monsterRoom (int&, string monsterName, string userName) {

    int bananas = 0;
    int oranges = 0;
    int stolenFruit = bananas + oranges;
    cout << "\nWATCH OUT!!!\n" << monsterName
         << " attacks you and steals all of your bananas and oranges." << endl;
    cout << userName << ", you are in a room with 4 doors." << endl;


}

//door = genie, add 2 to bananas and add 1 to orange
void genieRoom (int &bananas, int &oranges, string userName) {

    bananas = bananas + 2;
    oranges = oranges + 1;
    cout << "\n!!Poof!!"
         << " A Genie pops out and grants you 2 bananas and 1 orange." << endl;
    cout << userName << ", you are in a room with 4 doors." << endl;

}

//door = picture, output picture adds nothing to bananas and oranges
void pictureRoom() {

    cout << "\nYou found a picture!";

}
//picture to output for picture door
void drawPicture(string userName) {

        cout << endl;
        cout << "        _--~~--_" << endl;
        cout << "      /~/_|  |_\\~\\" << endl;
        cout << "     |____________|" << endl;
        cout << "     |[][][][][][]|" << endl;
        cout << "   __| __         |__" << endl;
        cout << "  |  ||. |   ==   |  |" << endl;
        cout << " (|  ||__|   ==   |  |)" << endl;
        cout << "  |  |[] []  ==   |  |" << endl;
        cout << "  |  |____________|  |" << endl;
        cout << "  /__\\            /__\\" << endl;
        cout << "   ~~              ~~ " << endl;
        cout << endl;
        cout << userName << ", you are in a room with 4 doors." << endl;

}
//door = exit, ends game and sums the total number of bananas and oranges earned
void exitRoom(int &bananas, int &oranges) {

    cout << "\nYou found the exit!" << endl;
    cout << "Your score is " << bananas + oranges
         << "(" << bananas << " bananas and "
         << oranges << " oranges)." << endl;
    cout << "Bye bye!!!" << endl;
    exit(0);
}
//mechanism for which selected door by user will output
void getOptions(int alignNum, char door, int &bananas, int &oranges,
                int stolenFruit, string monsterName, string userName) {

    if (alignNum == 0 && door == 'W') {

            exitRoom(bananas, oranges);
    }

    if (alignNum == 1 && door == 'N') {

            exitRoom(bananas, oranges);
    }

    if (alignNum == 0 && door == 'N') {

            monsterRoom(stolenFruit, monsterName, userName);
            bananas = oranges = stolenFruit;
            cout << "\nYou are carrying " << bananas << " bananas and " << oranges << " oranges." << endl;
    }


    if (alignNum == 0 && door == 'E') {

        pictureRoom();
            cout << "\nYou found a picture!";
            drawPicture(userName);
            cout << "You are carrying " << bananas << " bananas and " << oranges << " oranges." << endl;
    }


    if (alignNum == 0 && door == 'S') {

            genieRoom(bananas, oranges, userName);
            cout << "\nYou are carrying " << bananas << " bananas and " << oranges << " oranges." << endl;
    }


    if (alignNum == 1 && door == 'E') {

        genieRoom(bananas, oranges, userName);
            cout << "\nYou are carrying " << bananas << " bananas and " << oranges << " oranges." << endl;
    }


    if (alignNum == 1 && door == 'S') {

        monsterRoom(stolenFruit, monsterName, userName);
        bananas = oranges = stolenFruit;
            cout << "\nYou are carrying " << bananas << " bananas and " << oranges << " oranges." << endl;
    }


    if (alignNum == 1 && door == 'W') {

        pictureRoom();
            drawPicture(userName);
            cout << "\nYou are carrying " << bananas << " bananas and " << oranges << " oranges." << endl;
    }
}

