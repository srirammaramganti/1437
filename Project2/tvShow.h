#ifndef TVSHOW_H
#define TVSHOW_H
#include <iostream>
#include "content.h"
using namespace std;

class TvShow : public Content {
    public:
        TvShow();
        TvShow(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating, int inputTotalSeasons, int inputTotalEpisodes, int inputEpisodesWatched, string inputShowCreator);
        int getTotalSeasons();
        int getTotalEpisodes();
        int getEpisodesWatched();
        void markWatched() override;
        void markUnWatched() override;
        double getShowProgress();
        void printInfo() override;
        
    private:
        int totalSeasons;
        int totalEpisodes;
        int episodesWatched;
        string showCreator;
};
