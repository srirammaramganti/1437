#include <iostream>
#include "content.h"
#include "movie.h"
#include "tvShow.h"
using namespace std;

void printMenu() {
    cout << "+====================================================+" << endl;
    cout << "|                CONTENT TRACKER MENU                |" << endl;
    cout << "+====================================================+" << endl;
    cout << "|  1) Add Movie                                      |" << endl;
    cout << "|  2) Add TV Show                                    |" << endl;
    cout << "|  3) Mark Watched                                   |" << endl;
    cout << "|  4) Change Rating                                  |" << endl;
    cout << "|  5) Update TV Show Progress                        |" << endl;
    cout << "|  6) View Watchlist                                 |" << endl;
    cout << "|  7) Exit                                           |" << endl;
    cout << "+====================================================+" << endl;
    cout << "|  Enter your choice (1-7):                          |" << endl;
    cout << "+====================================================+" << endl;
    cout << ">> ";
}

int main() 
{
    int capacity = 5;
    int size = 0;
    Content** watchlist = new Content*[capacity];
    int option = 0;

    while(true) {
        printMenu();
        if (!(cin >> option)) {
            return 0;
        } 
        switch (option) {
            case 1:
                string title, genre, director;
                int year, duration;
                cout << "Title of the movie: " << endl;
                getline(cin, title);
                cout << "Enter the release year: " << endl;
                cin >> year;
                cout << "Enter genre: " << endl;
                getline(cin, genre);
                cout << "Enter director: " << endl;
                getline(cin, director);
                cout << "Enter duration: " << endl;
                cin >> duration;

                if (size == capacity) {
                    capacity += 1;
                    Content** newWatchlist = new Content*[capacity];
                    for (int i = 0; i < size; i++) {
                        newWatchlist[i] = watchlist[i];
                    }

                    delete [] watchlist;
                    watchlist = newWatchlist;
                }
                watchlist[size] = new Movie(title, year, genre, duration, director);
                size += 1;
                
                cout << "Movie successfully added!" << endl;
                break;
            case 2:

                break;
            case 3:
                
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                return;
            default:
                cout << "Invalid menu option" << endl;
                break;
        }
    }
    return 0;
}