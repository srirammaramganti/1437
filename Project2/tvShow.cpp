#include "tvShow.h"
#include <iostream>
using namespace std;

TvShow::TvShow() : Content()
{
    totalEpisodes = 0;
    episodesWatched = 0;
    showCreator = "";
    contentType = "TvShow";
}
TvShow::TvShow(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating, int inputTotalEpisodes, int inputEpisodesWatched, string inputShowCreator, string inputContentType)
: Content(inputTitle, inputReleaseYear, inputGenre, inputWatched, inputUserRating)
{
    totalEpisodes = inputTotalEpisodes;
    episodesWatched = inputEpisodesWatched;
    showCreator = inputShowCreator;
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
    if (totalEpisodes == 0) {
        return 0.0;
    }
    return (double)episodesWatched / totalEpisodes * 100.0;
}
void TvShow::printInfo()
{
    cout << "TV SHOW" << endl;
    Content::printInfo();
    cout << "Creator: " << showCreator << "\n";
    cout << "Show Progress: " << getShowProgress() << "%\n";
}
void TvShow::setEpisodesWatched(int inputEpisodesWatched)
{
    if (inputEpisodesWatched < 0) {
        episodesWatched = 0;
    } else if (inputEpisodesWatched > totalEpisodes) {
        episodesWatched = inputEpisodesWatched;
    } else {
        episodesWatched =  inputEpisodesWatched;
    }
    if (episodesWatched == totalEpisodes && totalEpisodes > 0) {
        markWatched();
    }
}