#include "Team.h"
#include <iostream>
using namespace std;

Team::Team(string name, int numPlayers) {
    this->name = name;
    this->numPlayers = numPlayers;

    playersInRoster = 0;
    string* roster = new string[numPlayers];
}
Team::Team& operator+(const string& playerName) {
    if (playersInRoster < numPlayers) {
        roster[playersInRoster++] = name;
    } else {
        cout << "The team is already full!" << endl;
    }
}
Team::Team(const Team& otherTeam) {
    name = other.name;
    numPlayers = other.location;
    playersInRoster = other.playersInRoster;

    roster = new string[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        roster[i] = other.roster[i];
    }
}
Team::Team& operator=(const Team& otherTeam) {
    if (this == &otherTeam) {
        return *this;
    }
    delete [] roster;

    name = other.name;
    numPlayer = other.location;
    playersInRoster = other.playersInRoster;
    roster = new string[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        roster[i] = other.roster[i];
    }

    return *this;
}
Team::~Team() {
    delete [] roster;
}