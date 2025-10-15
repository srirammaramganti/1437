#include "book.h"
#include <iostream>
using namespace std;

//constructors
Book::Book(string t = "Unititled", string a = "Unknown", double p = 0.0, int q = 0) {
    title = t;
    author = a;
    price = p;
    quantity = q;
}
//getters
string Book::GetTitle(string t) {
    return title;
}
string Book::GetAuthor(string a) {
    return author;
}
double Book::GetPrice(double p) {
    return price;
}
int Book::GetQuantity(int q) {
    return quantity;
}
//setters
void Book::SetTitle() {
    title = t;
}
void Book::SetAuthout() {
    author = a;
}
void Book::SetPrice() {
    price = p;
}
void Book::SetTitle() {
    quantity = q;
}
//discount func
void Book::ApplyDiscout(double percent) {
    p = (100 - percent) * p;
}

