#include "tvShow.h"
#include <iostream>
using namespace std;

TvShow() : Content()
{
    totalSeasons = 0;
    totalEpisodes = 0;
    episodesWatched = 0;
    showCreator = "";
}
TvShow::TvShow(int inputTotalSeasons, int inputTotalEpisodes, int inputEpisodesWatched, string inputShowCreator)
: Content(inputTitle, inputReleaseYear, inputGenre, inputWatched, inputUserRating)
{
    totalSeasons = inputTotalSeasons;
    totalEpisodes = inputTotalEpisodes;
    episodesWatched = inputEpisodesWatched;
    showCreator = inputShowCreator;
}
int TvShow::getTotalSeasons()
{
    return totalSeasons;
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
    return 1.0 * (episodesWatched / totalEpisodes);
}
void TvShow::printInfo()
{
    
}