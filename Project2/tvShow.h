#ifndef TVSHOW_H
#define TVSHOW_H
#include <iostream>
#include "content.h"
using namespace std;

class TvShow : public Content {
    public:
        TvShow();
        TvShow(int inputTotalSeasons, int inputTotalEpisodes, int inputEpisodesWatched, string inputShowCreator);
        int getTotalSeasons();
        int getTotalEpisodes();
        int getEpisodesWatched();
        double getShowProgress();
        void printInfo() override;
        
    private:
        int totalSeasons;
        int totalEpisodes;
        int episodesWatched;
        string showCreator;
};
