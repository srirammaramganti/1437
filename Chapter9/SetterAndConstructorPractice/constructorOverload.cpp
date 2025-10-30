#include <iostream>
using namespace std;
#include <string>

class Pizza {
    public:
        string topping;
        string topping1;
        string topping2;
        
        void print() {
            cout << topping1 << " " << topping2 << " pizza" << endl;
        }
        // constructor definition
        Pizza() {
            // empty just for here not to show any errors or anything
        }
        Pizza(string topping) {
            this->topping1 = topping1;
        }
        Pizza(string topping1, string topping2) {
            this->topping1 = topping1;
            this->topping2 = topping2;
        }
    private:

};

int main() {
    //constructor implementation
    Pizza pizza1("pepperoni");
    Pizza pizza2("mushroom", "peppers");
    pizza1.print();
    pizza2.print();

    return 0;
}