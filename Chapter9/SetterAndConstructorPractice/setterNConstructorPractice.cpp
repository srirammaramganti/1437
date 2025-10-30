#include <iostream>
#include <string>
using namespace std;

class Restaurants {
    public:
        Restaurants(string name, int rating);
        void SetName(string name);
        void SetRating(int rating);
        void Print();
    private:
        string name = "NoName";
        int rating = -1;
};
Restaurants::Restaurants(string name, int rating) {
    this->name = name;
    this->rating = rating;
}
void Restaurants::SetName(string name) {
    this->name = name;
}
void Restaurants::SetRating(int rating) {
    this->rating = rating;
}
void Restaurants::Print() {
    cout << name << " has a recieved a rating of " << rating << " stars." << endl;
}
int main() {
    Restaurants r1("Bistro Huddy", 5);
    r1.Print();

    return 0;
}