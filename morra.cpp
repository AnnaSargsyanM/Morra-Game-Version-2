//****************************************************************************************************
//     File:               morra.cpp
// 
//     Student:            Anna Sargsyan
// 
//     Assignment:         Program #9
// 
//     Course Name:        Programming I
// 
//     Course Number:      COSC 1550-01
// 
//     Due:                March 31, 2023
//
//     This program selectes numbers for players  randomly, 
//     then selectes the right answers randomly.
//     After it output who wins in the game "Morra".
//  
//     
//
//****************************************************************************************************

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

const int MIN_FINGERS = 0;
const int MAX_FINGERS = 5; 

void printTitle();
void printFingerSummary(int, int, int, int);
string findDecision(int, int, int, int);
void printDecision(string );

int main()
{

    int player1Num,
        player2Num,
        player1Guess,
        player2Guess;

    short seed = time(0);

    srand(seed);

    player1Num = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
    player2Num = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;

    player1Guess = rand() % (MAX_FINGERS - MIN_FINGERS)
        + MIN_FINGERS + player1Num;
    player2Guess = rand() % (MAX_FINGERS - MIN_FINGERS)
        + MIN_FINGERS + player2Num;

    printTitle();
    printFingerSummary(player1Num, player2Num, player1Guess, player2Guess);
    string decision = findDecision(player1Num, player2Num,
        player1Guess, player2Guess);
    printDecision(decision);

    return 0;
}

void printTitle()
{
    cout << "Morra Simulation" << endl;
    cout << endl;
}

void printFingerSummary(int player1Num, int player2Num, int player1Guess, 
                        int player2Guess)
{
    cout << "\t\tPlayer 1\t" << "Player 2" << endl;
    cout << "Fingers\t\t" << player1Num << "\t\t" << player2Num << endl;
    cout << "Guesses\t\t" << player1Guess << "\t\t" << player2Guess << endl;
    cout << endl;
}

string findDecision(int player1Num, int player2Num, int player1Guess,
                    int player2Guess)
{
    int sum = player1Num + player2Num;
    string decision;

        if (player1Guess == sum && player2Guess == sum)
        {
            decision = "It's a Tie!";     
        }
        else if (player1Guess == sum)
        {
            decision = "Player 1 is the Winner!";  
        }
        else if (player2Guess == sum)
        {
            decision = "Player 2 is the Winner!";
        }
        else
        {
            decision = "No one won. Try again!";
        }

    return decision;
}

void printDecision(string decision)
{
    cout << decision << endl;
}



/*
Morra Simulation

                Player 1        Player 2
Fingers         3               0
Guesses         6               1

Player 1 is the Winner!

*/

/*

Morra Simulation

                Player 1        Player 2
Fingers         0               2
Guesses         0               4

Player 2 is the Winner!

*/

/*
* 
Morra Simulation

                Player 1        Player 2
Fingers         3               1
Guesses         6               5

No one won. Try again!

*/