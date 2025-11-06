#include <iostream>
#include <string>
using namespace std;

class Team {
private:
    string name;
    int numPlayers;
    int playersInRoster;
    string* roster;

public:
    Team(string teamName, int maxPlayers)
        : name(teamName), numPlayers(maxPlayers), playersInRoster(0) {
        roster = new string[numPlayers];
    }

    Team(const Team& other) {
        name = other.name;
        numPlayers = other.numPlayers;
        playersInRoster = other.playersInRoster;
        roster = new string[numPlayers];
        for (int i = 0; i < playersInRoster; i++)
            roster[i] = other.roster[i];
    }

    Team& operator=(const Team& other) {
        if (this != &other) {
            delete[] roster;
            name = other.name;
            numPlayers = other.numPlayers;
            playersInRoster = other.playersInRoster;
            roster = new string[numPlayers];
            for (int i = 0; i < playersInRoster; i++)
                roster[i] = other.roster[i];
        }
        return *this;
    }

    Team& operator+(const string& playerName) {
        if (playersInRoster < numPlayers)
            roster[playersInRoster++] = playerName;
        else
            cout << "The team is already full!" << endl;
        return *this;
    }

    ~Team() {
        delete[] roster;
    }
};
