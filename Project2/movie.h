#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include "content.h"
using namespace std;

class Movie : public Content {
    public:
        Movie();
        Movie(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating, int inputMovieDuration, string inputDirector);
        int getMovieDuration();
        string getDirector();
        void setMovieDuration(int inputMovieDuration);
        void setDirector(string inputDirector);
        virtual void printInfo() const override;
    private:
        int movieDuration;
        string director;
};