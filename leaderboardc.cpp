#include "leaderboard.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

bool addUser(string usernameIn){
    ifstream file;
    file.open(leaderboardList.txt);
    while(getline(file, username)){
        if (usernameIn == username)
        {
            file.close();
            return false;
        }
        else
        {
            file << username;
            file.close();
            return true;
        }
    }
}

bool addPoints(string username, int pointsIn){
    int arrCapactiy = 100;
    leaderboard *leaderboardArray;
    leaderboardArray = new leaderboard[arrCapactiy];
    ifstream file;
    file.open(leaderboardList.txt);
    while(getline(file, username, '\t') && getline(file, points, '\t')){
        if (usernameIn == username)
        {
            
        }
        else
        {
            return true;
        }
    }
}

bool orderArray()

void printLeaderboard(string username){

}