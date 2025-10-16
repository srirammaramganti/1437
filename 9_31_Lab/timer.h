#ifndef TIMER_H
#define TIMER_H
#include <iostream>
using namespace std;
// provide the declaration of the Timer class below

class Timer {
    private:
        int hours;
        int minutes;
        int seconds;
        void reduceSeconds();
        void reduceMinutes();
        void reduceHours();
    public:
        Timer();
        Timer(int seconds, int minutes, int hours);
        void setHours(int hours); 
        void setMinutes(int minutes);
        void setSeconds(int seconds);
        void start();
        string toString();

}

#endif 