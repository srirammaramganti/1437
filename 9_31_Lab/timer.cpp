    #include <iostream>
    #include <string>
    #include <thread>         // std::this_thread::sleep_for
    #include <chrono>         // std::chrono::seconds
    using namespace std;
    #include "Timer.h"

    // Please provide the implementation of other member functions here
    Timer::Timer() : hours(0), minutes(1), seconds(0) { }

    Timer::Timer(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) { }

    void Timer::setHours(int hours) {
        this->hours = hours;
    } 
    void Timer::setMinutes(int minutes) {
        this->minutes = minutes;
    }
    void Timer::setSeconds(int seconds) {
        this->seconds = seconds;
    }
    void Timer::reduceSeconds() {
        if(seconds > 0) {
            seconds -= 1;
            return;
        } 
        if (minutes > 0 || hours > 0) {
            seconds = 59;
            reduceMinutes();
        }
    }
    void Timer::reduceMinutes() {
        if(minutes > 0) {
            minutes -= 1;
        } 
        if (hours > 0) {
            minutes = 59;
            reduceHours();
        }
    }
    void Timer::reduceHours() {
        hours -= 1;
    }
    void Timer::start()
    {
        cout << "Timer started" << endl;
        while(hours > 0 || minutes > 0 || seconds > 0)
        {
            cout << toString() << endl;
            this_thread::sleep_for (std::chrono::seconds(1));
            reduceSeconds();
        }
        cout << "Time!" << endl;
    }

    string Timer::toString()
    {
        string out;
        if(hours < 10)
            out = "0";
        
        out = out + to_string(hours) + ":";
        
        if(minutes < 10)
            out = out + "0";
        
        out = out + to_string(minutes) + ":";
        
        if(seconds < 10)
            out = out + "0";
        
        out = out + to_string(seconds);
        
        return out;
    }