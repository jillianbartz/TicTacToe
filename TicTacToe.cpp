#include <iostream>
using namespace std;
int add()
    {
    string playerOne;
    string playerTwo;
    cout << "Enter name of Player One \n";
    getline(cin, playerOne);
    cout << "Enter name of Player Two \n";
    getline(cin, playerTwo);
    return 0;
    }

int main()
{   

    // add a menu, then lets try and make a leaderboard using classes if i have enough time
    int choice;
    
    cout  << "menu \n 1. play \n";
    cin >> choice;
    cin.ignore(256, '\n');
    if (choice == 1)
    {
        add();
    }


    

    

    cout << "     |     |     \n";
    cout << "  1  |  2  |  3  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  4  |  5  |  6  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  7  |  8  |  9  \n";
    cout << "     |     |     \n";
    
    return 0;
}