#ifndef TVSHOW_H
#define TVSHOW_H
#include <iostream>
#include "content.h"
using namespace std;

class TvShow : public Content {
    public:
        TvShow();
        TvShow(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating, string inputContentType, int inputTotalEpisodes, int inputEpisodesWatched, string inputShowCreator);
        int getTotalEpisodes();
        int getEpisodesWatched();
        void markWatched() override;
        void markUnWatched() override;
        double getShowProgress();
        void printInfo() override;
        void setEpisodesWatched(int inputEpisodesWatched);
        
    private:
        int totalEpisodes;
        int episodesWatched;
        string showCreator;
};

#endif