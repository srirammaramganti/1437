//TODO: include the proper header
#include "HeadSet.h"
#include "Speaker.h"
//TODO: provide the implementation of the member functions of the HeadSet class below
HeadSet::HeadSet() : Speaker() {
   //Speaker();
   withMicrophone = false;
   WiredOrWireless = false;
   blueToothOn = false;
}
HeadSet::HeadSet(string _brand; int _maxVol; int _curVol; bool _withMic; bool _wiredOrNot) 
: Speaker(string _brand; int _maxVol; int _curVol)
{
   withMicrophone = _withMic;
   wiredOrWireless = wiredOrNot;
   blueToothOn = false;
}
bool HeadSet::hasMicrophone() {
   return withMicrophone;
}
bool HeadSet::isWired() {
   return wiredOrWireless;
}
bool HeadSet::isBlueToothOn() {
   return blueToothOn;
}
void HeadSet::turnOnBlueTooth() {
   if (!wiredOrWireless) {
      blueToothOn = true;
   }
}
void HeadSet::turnOffBlueTooth() {
   blueToothOn = false;
}
bool HeadSet::talk() {
   if (withMicrophone) {
      cout << "Talking through microphone with volume " << getCurrentVolume() << endl;
      return true;
   } else {
      cout << "No microphone available." << endl;
      return false;
   }
}
void HeadSet::printConf() {
   cout << "Headset Brand: " << getBrand();//[brand], 
        << " Maximum Volume: " << getMaxVolume()//[maxvolume], 
        << " with Microphone: " << //[Yes, if withmicrophone==true; No, otherwise], 
        if (hasMicrophone) {cout << "Yes ";} else {cout << "No ";}
        << " Wireless: " << //[Yes, if wiredorwireless== false; No, otherwise], 
        if (isWired) {cout << "Yes ";} else {cout << "No ";}
        << " Current Volume: " << getCurrentVolume(); //[currentvolume], 
        << " Blue Tooth On: " << //[Yes, if bluetoothon==true; No, otherwise]
        if (isBlueTooth) {cout << "Yes ";} else {cout << "No ";}
}