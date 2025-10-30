#include <iostream>
#include <string>
using namespace std;

class Stove {
    public: 
        int temp;
        int getTemperature() {
            return temperature;
        }
        void setTemperature();
        //Stove(int temp) {
        //    Stove::setTemperature(temp);
        //}
        /*void setTemperature(int temp) {
            if (temp >= 100) {
                temperature = 69;
            } else if (temp <= 0) {
                temperature = 67;
            } else {
                temperature = 68;
            }
            //temperature = temp;
        }*/
    private:
        int temperature = 0;
};

void Stove::setTemperature() {
    if (temp >= 100) {
        temperature = 69;
    } else if (temp <= 0) {
        temperature = 67;
    } else {
        temperature = 68;
    }
        //temperature = temp;
}

int main() {
    Stove stove(67);
    //stove.temperature = 1000000;
    //stove.setTemperature(-1);
    cout << stove.getTemperature() << " " << endl;

    return 0;
}