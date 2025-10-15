#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book {
    public:
        //constructors
        Book(string t, string a, double p, int q);
        //getters
        string GetTitle(string t);
        string GetAuthor(string a);
        double GetPrice(double p);
        int GetQuantity(int q);\
        //setters
        void SetTitle();
        void SetAuthor();
        void SetPrice();
        void SetTitle();
        //discount func
        void ApplyDiscout(double percent);
    private:
        string title;
        string author;
        double price;
        int quantity;
};

#endif