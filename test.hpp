#ifndef READFILE_H__
#define READFILE_H__
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct leader{
    string usernameIn;
    string pointsIn;
};

void insertArray(string usernameIn, string pointsIn);

#endif