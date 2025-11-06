#ifndef TEAM_H
#define TEAM_H
#include <string>
using namespace std;

class Team {
    private:
        string name;
        int numPlayers;
        int playersInRoster;
        string* roster;
    
    public:
        Team(string name, int numPlayers);
        Team& operator+(const string& playerName);
        Team(const Team& otherTeam);
        Team& operator=(const Team& otherTeam);
        ~Team();
};

#endif