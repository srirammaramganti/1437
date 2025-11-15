#ifndef HEADSET_H
#define HEADSET_H

//TODO: include the proper header
#include "Speaker.cpp"
//TODO: declare your HeadSet class here
class HeadSet : public Speaker {
   private:
      bool withMicrophone; //true if with microphone
      bool WiredOrWireless; //true if wired
      bool blueToothOn; // true if blue tooth is turned on
   public:
      HeadSet();
      HeadSet(string _brand; int _maxVol; int _curVol; bool _withMic; bool _wiredOrNot);
      bool hasMicrophone() ; //return the value of withMicrophone variable
      bool isWired(); //return the value of WiredOrWireless variable
      bool isBlueToothOn(); // return the value of blueToothOn variable
      void turnOnBlueTooth(); //set blueToothOn to be true if WiredOrWireless == false
      void turnOffBlueTooth(); // set blueToothOn to be false
};

#endif