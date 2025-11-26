#include "tvShow.h"
#include <iostream>
using namespace std;

TvShow::TvShow() : Content()
{
    totalEpisodes = 0;
    episodesWatched = 0;
    showCreator = "";
}
TvShow::TvShow(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating, int inputTotalEpisodes, int inputEpisodesWatched, string inputShowCreator)
: Content(inputTitle, inputReleaseYear, inputGenre, inputWatched, inputUserRating)
{
    totalEpisodes = inputTotalEpisodes;
    episodesWatched = inputEpisodesWatched;
    showCreator = inputShowCreator;
    contentType = "TvShow";
}
void TvShow::markWatched() {
  Content::markWatched();
}

void TvShow::markUnWatched() {
  Content::markUnWatched();
} 
int TvShow::getTotalEpisodes()
{
    return totalEpisodes;
}
int TvShow::getEpisodesWatched() 
{
    return episodesWatched;
}
double TvShow::getShowProgress() 
{
    return (double)episodesWatched / totalEpisodes * 100.0;
}
void TvShow::printInfo()
{
    cout << "TV  SHOW" << endl;
    Content::printInfo();
    cout << "Creator: " << showCreator << "\n";
    cout << "Show Progress: " << getShowProgress() << "%\n";
}