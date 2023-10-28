
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/*
addPoints: adds points to existing username into leaderboardList.txt
addLeader: adds every user who plays game into leaderboardList.txt
findUser: check if user exists in leaderboardList.txt
showLeader: show your position in the leaderboardList.txt compared to the number #1 leader (King of the Hill style)
grid: board of game with array output for values
checkWinner: as game progresses, check to see if certain values on grid equal a win, if so. add points to winner
gamePlay: allows user to choose thier play positions each turn
main: menu, as well as initalizing the usernames for players. calls other functions

leaderboardList.txt: text file with all users who have played and their associated points


Code cleanup/efficiency could be improved, but was working on quick deadline due to weekened travel + midterms
*/

    string pointstr;
    string username;
    char game[9] = {'1','2','3','4','5','6','7','8','9'};
    string playerOne;
    string playerTwo;

void addPoints(string usernameIn, string pointsIn) 
{
    ofstream out;
    ifstream in;
    int pointsInInt = stoi(pointsIn);
    int pointsInt = 0;
    in.open("leaderboardList.txt");
    out.open("leaderboardTemp.txt");

    while(getline(in, username, ',') && getline(in, pointstr)) 
    //parsing each line of the file
    {
        if(username == usernameIn) //if the username we look for is the line we are at in the leaderboardList.txt, add points
        {
            pointsInt = stoi(pointstr);
            pointsInInt += pointsInt;
            pointstr = to_string(pointsInInt);
        }
        //add all lines to temporary file
            out << username;
            out << ",";
            out << pointstr << '\n';
    }
    rename("leaderboardTemp.txt","leaderboardList.txt"); //rewrite the file leaderboardList.txt with new information including adjusted points
    in.close();
    out.close();
    return;
}

void addLeader(string usernameIn, string pointsIn){
        ofstream out;
    ifstream in;
   in.open("leaderboardList.txt");
   out.open("leaderboardList.txt", ios::app); //open files with appending it


   while(getline(in, username, ',') && getline(in, pointstr)) //parsing file lines
   {
    if (username == usernameIn) //if the user exists, close out of this function
    {
        in.close();
        out.close();
        return;
    }
   } 
   //if the user does not exist, add into the leaderboardList.txt
    out << usernameIn;
    out << ',';
    out << pointsIn;
    out << '\n';
    in.close();
    out.close();
    return;
}

bool findUser(string usernameIn){
    ifstream in;
    in.open("leaderboardList.txt");

    while(getline(in, username, ',') && getline(in, pointstr)) //parsing file lines
    {
        //if the username exists in the file, exit
        if(username==usernameIn){
            in.close();
            return true;
        }
    }
    in.close();
    return false; //if the username does not exist, return false
}

void showLeader(string usernameIn){
    ifstream in;
    in.open("leaderboardList.txt");

    string usernameMax;
    string usernamePoints;
    int usernamePointsInt;
    int temp = 0;
    int max = 0;

    while(getline(in, username, ',') && getline(in, pointstr)) //parsing file lines
    {
        if (username == usernameIn) 
        {
            usernamePoints = pointstr;
            usernamePointsInt = stoi(usernamePoints);
        }
        temp = stoi(pointstr);
        if (temp > max) //if the line has greater than the max amount of points, then they are the new top leader
        {
            max = temp;
            usernameMax = username;
        }
    }
    if(findUser(usernameIn)){ //ensure the user exists
    if(usernameMax == usernameIn) //if user is leader
    {
        cout << "\nYou are the leader " << usernameIn << " with " << max << " points! Keep it up!\n\n";
    }
    else if (usernameMax != usernameIn){ //if user isn't leader
    cout << '\n' << usernameMax << " leads with " << to_string(max) << " points!\nYou are " << (max - usernamePointsInt) << " points from the leader. \n\n";
    }
    }
    else if(findUser(usernameIn) == false){ //if user does not exist
        cout << "\nThat user does not exist. \n\n";
    }
    in.close();
    return;
}

void grid(){ //board of game
            cout << "     |     |     \n";
            cout << "  "<< game[0] << "  |  "<< game[1] <<"  |  "<< game[2] <<"  \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "  "<< game[3] <<"  |  "<< game[4] <<"  |  "<< game[5] <<"  \n";
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
            cout << "  "<< game[6] <<"  |  "<< game[7] <<"  |  "<< game[8] <<"  \n";
            cout << "     |     |     \n";
            cout << "\n\n";
}

bool checkWinner(string winner){
    
    if (game[0] == game[1] && game[1] == game[2]){ //if horizontal top row win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10");
        return true;}
    else if (game[3] == game[4] && game[4] == game[5]){ //if horizontal middle row win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10"); 
        return true;} 
    else if (game[6] == game[7] && game[7] == game[8]){ //if horizontal bottome row win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10");
        return true;}
    else if (game[0] == game[3] && game[3] == game[6]){ //if vertical left row win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10");
        return true;} 
    else if (game[1] == game[4] && game[4] == game[7]){ //if vertical middle row win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10");
        return true;}
    else if (game[2] == game[5] && game[5] == game[8]){ //if vertical right row win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10");
        return true;}
    else if (game[0] == game[4] && game[4] == game[8]){ //if diagonal win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10");
        return true;}
    else if (game[2] == game[4] && game[4] == game[6]){ //if diagonal win
        cout << winner << " has won the game!\n";
        addPoints(winner,"10");
        return true;}
    else if(game[0] != '1' && game[1] != '2' && game[2] != '3' && game[3] != '4' && game[4] != '5' && game[5] != '6' && game[6] != '7' && game[7] != '8' && game[8] != '9'){ //if a tie
    cout << "The game is a tie!\n";
    return true;}
    
        return 0;
}

void gamePlay(string playerUp){
    //reset our game board
        game[0] = '1';
        game[1] = '2';
        game[2] = '3';
        game[3] = '4';
        game[4] = '5';
        game[5] = '6';
        game[6] = '7';
        game[7] = '8';
        game[8] = '9';
    
    string pos;
    bool posValid=true;
    char sym;
    do{ //loop for our gameplay, in case invalid input we can reloop back to this
    grid();
    CHOICE: cout << playerUp << " please choose a position\n";
    getline(cin, pos);
    if(pos != "1" && pos != "2" && pos != "3" && pos != "4" && pos != "5" && pos != "6" && pos != "7" && pos != "8" && pos != "9"){ //if invalid entry
        cout << "Please submit a valid entry.\n";
    }
    else{
        
         if(playerUp == playerOne){ //decide what symbol to insert
            sym = 'X';
        }
        else if(playerUp == playerTwo){
            sym = 'O';
        }

        if (pos == "1" && game[0] == '1'){ //position 1
            game[0] = sym;}
        else if (pos == "2" && game[1] == '2'){ //position 2
            game[1] = sym;}
        else if (pos == "3" && game[2] == '3'){ //position 3
            game[2] = sym;}
        else if (pos == "4" && game[3] == '4'){ //position 4
            game[3] = sym;}
        else if (pos == "5" && game[4] == '5'){ //position 5
            game[4] = sym;}
        else if (pos == "6" && game[5] == '6'){ //position 6
            game[5] = sym;}
        else if (pos == "7" && game[6] == '7'){ //position 7
            game[6] = sym;}
        else if (pos == "8" && game[7] == '8'){ //position 8
            game[7] = sym;}
        else if (pos == "9" && game[8] == '9'){ //position 9
            game[8] = sym;}
        else{
            cout << "Invalid Choice\n"; 
            goto CHOICE;
        }
        if(checkWinner(playerUp)){ //if the move just won the user the game, then submit to checkWinner
            return;
        }
    else if(playerUp == playerOne){ //if didnt win, change who is the next player to move
        playerUp = playerTwo;
    }
    else if(playerUp == playerTwo){ //if didnt win, change who is the next player to move
        playerUp = playerOne;
    }
    }
    }while(posValid);
}

int main()
{
    string input;
    int choice = 0;
    string key;
    
    string playerOneChoice;
    int playerOneChoiceNum;
    
    bool menu = true;
    bool rules = true;
    bool name = true;
    bool headsTails = true;
    string winner;
    
    cout << "\nWelcome to Tic-Tac-Toe! Please select your choice from the menu below: \n \n"; //welcome message
    
    do{cout << "-----------MENU----------- \n 1. Rules \n 2. Play Game \n 3. Leaderboard \n 4. Exit\n"; //menu loop, go back to menu untill user presses exit
    getline(cin, input);
    if(input != "1" && input != "2" && input != "3" && input != "4"){ //if not a valid key
        cout << "Please enter a valid key.\n";
    }
    else{
    choice = stoi(input);
    switch(choice){
        case 1:{ //rules
        do{cout << "Rules: Players take turns putting their marks in empty games. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner. \n Press [1] to go back to menu.\n";
        getline(cin, key);
        if (key == "1")
        {
            rules = false;
        }
        else{
            cout << "\nPlease press a valid key.\n";
            
        }}while(rules);
        break;}
        case 2:{ //play game
        do{ //loop in case invalid input
        cout << "Enter name of Player One: ";
        getline(cin, playerOne);
        cout << "Enter name of Player Two: ";
        getline(cin, playerTwo);
        if(playerOne == playerTwo){
            cout << "Please input unique names.\n";
        }
        else{
        addLeader(playerOne,"0");
        addLeader(playerTwo, "0");
        do{cout << '\n'<<playerOne << " please choose either \n 1.Head \n 2.Tails\n"; //loop incase invalid input
        getline(cin, playerOneChoice);
        if(playerOneChoice == "1" || playerOneChoice == "2"){
            if(stoi(playerOneChoice) == ((rand()%2)+1)){ //using rand() to randomly flip the coin to decide who goes first in game
                cout << playerOne << " has won! " << playerOne << " will go first.\n";
                cout << playerOne << " will be 'X'\n";
                cout << playerTwo << " will be 'O'\n";
                winner = playerOne;
            }
            else{
                cout << '\n' << playerTwo << " has won! " << playerTwo << " will go first.\n";
                cout << playerOne << " will be 'X'\n";
                cout << playerTwo << " will be 'O'\n";
                winner = playerTwo;
            }
            gamePlay(winner);
            name = false;
            headsTails = false;
        }
        else{
            cout << "Invalid input.\n";
        }}while(headsTails);
            
        }}while(name);
        break;}
        
        case 3:{ //check leader
        bool leaderTest = true;
        string userAsk;
            cout << "Please enter your username: ";
            getline(cin, userAsk);
            showLeader(userAsk);
        break;}
        case 4:{ //exit
            cout << "Thanks for playing!!\n";
            return 1;
        }
        default:
        return 0;
    }
    }
    }while(menu);
    return 1;
}