#include "test.hpp"
void insertArray(string usernameIn, string pointsIn){
    int points = stoi(pointsIn);
   ofstream out;
   ifstream in;
   in.open("leaderboardList.txt");
   out.open("leaderboardList.txt", ios::app); //open files with appending it
   while(getline(in, username, ',') && getline(in, username,))
   {
    if (username == usernameIn)
    {
        cout << "Username already exists!\n";
        in.close();
        out.close();
        return 0;
    }
   }
    out << usernameIn;
    out << ',';
    out << pointIn;
    return 0;
}