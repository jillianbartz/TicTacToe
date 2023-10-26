#ifndef READFILE_H__
#define READFILE_H__
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct leaderboard{
    string username;
    int score;
}


bool addUser(string usernameIn);
bool addPoints(string username, int points);
void printLeaderboard(string username);