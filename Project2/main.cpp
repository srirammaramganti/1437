#include <iostream>
#include <string>
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
            {
                string title, genre, director, watched;
                int year, duration;
                bool isWatched;
                double rating;

                cout << "Title of the movie: " << endl;
                getline(cin, title);
                cout << "Enter the release year: " << endl;
                cin >> year;
                cin.ignore();  
                cout << "Enter genre: " << endl;
                getline(cin, genre);
                cout << "Enter director: " << endl;
                getline(cin, director);
                cout << "Enter duration: " << endl;
                cin >> duration;
                cin.ignore();
                cout << "Did you watch the movie? (Yes/No)" << endl;
                getline(cin, watched);
                cout << "If so, what is your rating? If no then put 0.0" << endl;
                cin >> rating;
                cin.ignore();  

                if (size == capacity) {
                    capacity += 1;
                    Content** newWatchlist = new Content*[capacity];
                    for (int i = 0; i < size; i++) {
                        newWatchlist[i] = watchlist[i];
                    }
                    delete [] watchlist;
                    watchlist = newWatchlist;
                }
                if (watched == "Yes") {
                    isWatched = true;
                } else if (watched == "No") {
                    isWatched = false;
                } else {
                    isWatched = false;
                }
                watchlist[size] = new Movie(title, year, genre, isWatched, rating, duration, director, "Movie");
                size += 1;
                
                cout << "Movie successfully added!" << endl;
                break;
            }
            case 2: 
            {
                string title, genre, creator, watched;
                int episodesWatched, totalEpisodes, year, size, capacity;
                bool isWatched;
                double rating;
                cout << "Title of the show: " << endl;
                cin >> title;
                cout << "Enter the release year: " << endl;
                cin >> year;
                cout << "Enter show creator: " << endl;
                cin >> creator;
                cout << "Enter genre: " << endl;
                cin >> genre;
                cout << "Enter total no. of episodes: " << endl;
                cin >> totalEpisodes;
                cout << "Enter no. of episodes watched: " << endl;
                cin >> episodesWatched;
                cout << "Did you watch the movie? (Yes/No)" << endl;
                cin.ignore();
                getline(cin, watched);
                cout << "If so, what is your rating? If no then put 0.0" << endl;
                cin.ignore();
                cin >> rating;


                if (size == capacity) {
                    capacity += 1;
                    Content** newWatchlist = new Content*[capacity];
                    for (int i = 0; i < size; i++) {
                        newWatchlist[i] = watchlist[i];
                    }
                    delete [] watchlist;
                    watchlist = newWatchlist;
                }
                if (watched == "Yes") {
                    isWatched = true;
                } else if (watched == "No") {
                    isWatched = false;
                } else {
                    isWatched = false;
                }
                watchlist[size] = new TvShow(title, year, genre, isWatched, rating, totalSeasons, totalEpisodes, episodesWatched, creator, "TvShow");
                size += 1;
                break;
            }
            case 3: {
                if (size == 0) {
                    cout << "Watchlist is empty" << endl;
                    break;
                }
                cout << "Select what item you want to mark as watched" << endl;
                for (int i = 0; i < size; i++) {
                    cout << i << ")" << watchlist[i]->getTitle() << "->" << watchlist[i]->getIsWatched() << endl;
                }
                int index;
                if(!(cin >> index) || index < 0 || index >= size) {
                    cout << "Invalid selection" << endl;
                    break;
                }
                cout << "Mark Watched -> 1\n";
                cout << "Mark UnWatched -> 2\n";
                int choice;
                if (!(cin >> choice)) {
                    cout << "Invalid choice" << endl;
                    break;
                }
                if (choice == 1) watchlist[index]->markWatched();
                else if (choice == 2) watchlist[index]->markUnWatched(); 
                else cout << "Invalid choice.\n";
                break;
            }
            case 4: {
                if (size == 0) { cout << "Watchlist is empty.\n"; break; }
                cout << "Select an item:\n";
                for (int i = 0; i < size; i++) {
                    cout << i << ") " << watchlist[i]->getTitle() << '\n';
                }
                int index;
                if (!(cin >> index) || index < 0 || index >= size) { 
                    cout << "Invalid selection.\n"; 
                    break; 
                }
                cout << "Enter new rating (0-10): ";
                double rating; if (!(cin >> rating)) { break; }
                watchlist[index]->setRating(rating);
                break;
            }
            case 5: {
                if (size == 0) { cout << "Watchlist is empty.\n"; break; }
                cout << "Select a TV show:\n";
                for (int i = 0; i < size; ++i) {
                    if (watchlist[i]->getContentType() == "TvShow") {
                        cout << i << ") " << watchlist[i]->getTitle() << '\n';
                    }
                }
                int index; 
                if (!(cin >> index) || index < 0 || index >= size) {
                    cout << "Invalid selection.\n"; break;
                }
                if (watchlist[index]->getContentType() != "TvShow") {
                    cout << "Selected item is not a TV show.\n";
                    break;
                }
                cout << "Enter episodes watched: ";
                int watchedEpisodes; 
                if (!(cin >> watchedEpisodes)) { break; }
                TvShow* show = (TvShow*)watchlist[index];
                show->setEpisodesWatched(watchedEpisodes);
                cout << "Progress updated" << endl;
                break;
            }
            case 6: {
                if (size == 0) { cout << "Watchlist is empty.\n"; break; }
                for (int i = 0; i < size; ++i) {
                    cout << i << ") ";
                    watchlist[i]->printInfo();
                    cout << '\n';
                }
                break;
            }
            case 7:
                for (int i = 0; i < size; ++i) delete watchlist[i];
                delete [] watchlist;
                return 0;
            default:
                cout << "Invalid menu option" << endl;
                break;
        }
    }
    return 0;
}