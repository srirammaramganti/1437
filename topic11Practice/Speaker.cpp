#include "Speaker.h"

Speaker::Speaker(){
   brand = "Unknown";
   maxVolume = 100;
   currentVolume = 0;
}

Speaker::Speaker(string _brand, int _maxVol, int _curVol){
   brand = _brand;
   maxVolume = _maxVol;
   currentVolume = _curVol;
}


string Speaker::getBrand(){
   return brand;
}


int Speaker::getMaxVolume(){
   return maxVolume;
}

int Speaker::getCurrentVolume(){
   return currentVolume;
}


void Speaker::printConf(){
   cout << "Speaker Brand: " << brand << ", Maximum Volume: " << maxVolume 
        << ", Current Volume: " << currentVolume << endl;
}

void Speaker::volumeUp(){
   if (currentVolume < maxVolume) currentVolume++;
}

void Speaker::volumeDown(){
   if (currentVolume > 0) currentVolume--;
}