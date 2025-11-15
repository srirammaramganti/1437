#ifndef SPEAKER_H
#define SPEAKER_H

#include <iostream>
using namespace std;

class Speaker{
public:
    Speaker();
    Speaker(string, int, int);
    string getBrand();
    int getMaxVolume();
    int getCurrentVolume();
    
    void printConf(); 
    void volumeUp();
    void volumeDown();
private:
    string brand;
    int maxVolume;
    int currentVolume;
};

#endif