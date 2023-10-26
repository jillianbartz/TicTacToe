
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void addPoints(string usernameIn, string pointsIn)
{
    string pointstr;
    string username;
    int pointsInInt = stoi(pointsIn);
    int pointsInt = 0;

    ofstream out;
    ifstream in;

    in.open("leaderboardList.txt");
    out.open("leaderboardTemp.txt");

    while(getline(in, username, ',') && getline(in, pointstr))
    {
        if(username == usernameIn)
        {
            pointsInt = stoi(pointstr);
            pointsInInt += pointsInt;
            pointstr = to_string(pointsInInt);
        }
            out << username;
            out << ",";
            out << pointstr << '\n';
    }
    rename("leaderboardTemp.txt","leaderboardList.txt");
    in.close();
    out.close();
    return;
}

void addLeader(string usernameIn, string pointsIn){
string pointstr;
string username;
   ofstream out;
   ifstream in;
   in.open("leaderboardList.txt");
   out.open("leaderboardList.txt", ios::app); //open files with appending it


   while(getline(in, username, ',') && getline(in, pointstr))
   {
    if (username == usernameIn)
    {
        in.close();
        out.close();
        addPoints(usernameIn, pointsIn);
        return;
    }
   }
    out << usernameIn;
    out << ',';
    out << pointsIn;
    in.close();
    out.close();
    return;
}

void showLeader(string usernameIn){
    ifstream in;

    in.open("leaderboardList.txt");

    string username;
    string usernameMax;
    string pointstr;
    string usernamePoints;
    int usernamePointsInt;
    int temp = 0;
    int max = 0;

    while(getline(in, username, ',') && getline(in, pointstr))
    {
        if (username == usernameIn)
        {
            usernamePoints = pointstr;
            usernamePointsInt = stoi(usernamePoints);
        }
        temp = stoi(pointstr);
        if (temp > max)
        {
            max = temp;
            usernameMax = username;
        }
    }
    if(usernameMax == usernameIn)
    {
        cout << "You are the leader " << usernameIn << " with " << max << " points! Keep it up!\n";
    }
    else{
    cout << usernameMax << " leads with " << to_string(max) << " points!\nYou are " << (max - usernamePointsInt) << " points from the leader. \n";
    }
    in.close();
    return;
}



int main()
{
    string input;
    int choice = 0;
    string key;
    string playerOne;
    string playerOneChoice;
    string playerTwo;
    string playerTwoChoice;
    string playerOneNum;
    string playerTwoNum;

    
    START:cout << "Welcome to Tic-Tac-Toe! Please select your choice from the menu below: \n \n";
    
    MENU:cout << "-----------MENU----------- \n 1. Rules \n 2. Play Game \n 3. Leaderboard \n 4. Exit";
    getline(cin, input);
    choice = stoi(input);
    switch(choice){
        case 1:
        RULES:cout << "Rules: Players take turns putting their marks in empty squares. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner. \n Press [1] to go back to menu.\n";
        getline(cin, key);
        if (key == "1")
        {
            goto MENU;
        }
        else{
            cout << "\nPlease press a valid key.\n";
            goto RULES;
        }
        case 2:
        cout << "Enter name of Player One: ";
        getline(cin, playerOne);
        cout << "Enter name of Player Two: ";
        getline(cin, playerTwo);

        PLAYERONECHOICE:cout<<"\n" << playerOne << " Please choose 'X' or 'O' for your mark: ";
        getline(cin, playerOneChoice);
        if(!(playerOneChoice == "X" || playerOneChoice == "x" || playerOneChoice == "O" || playerOneChoice == "o"))
        {
            cout << "\nPlease press a valid key.\n";
            goto PLAYERONECHOICE;
        }
        PLAYERTWOCHOICE:cout<<"\n" << playerTwo << " Please choose 'X' or 'O' for your mark: "; 
        getline(cin, playerTwoChoice);
        if(!(playerTwoChoice == "X" || playerTwoChoice == "x" || playerTwoChoice == "O" || playerTwoChoice == "o"))
        {
            cout << "\nPlease press a valid key.\n";
            goto PLAYERTWOCHOICE;
        }
            GRID:cout << "Numbered Grid:\n";
            cout << "     |     |     \n";
            cout << "  1  |  2  |  3  \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "  4  |  5  |  6  \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "  7  |  8  |  9  \n";
            cout << "     |     |     \n";
            cout << "\n\n";

            cout << "Decide who goes first...\n";
            cout << playerOne << "Choose a \n 1.Heads \n 2.Tails \n";
            getline(cin, playerOneNum);
            if (playerOneNum != "1" || playerOneNum != "2")
            {
                "Please choose either 1.Heads or 2.Tails\n";
            }
            cout << "     |     |     \n";
            cout << "     |     |     \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "     |     |     \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "     |     |     \n";
            cout << "     |     |     \n";

        
        // case 3:
        // case 4:
        default:
        return 0;
    }
    
   addLeader("hahahaha", "10");
   showLeader("hahahaha");
        return 0;
}