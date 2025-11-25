#include "movie.h"
#include <iostream>
using namespace std;

Movie::Movie()
  : Content()
{
  movieDuration = 0;
  director = "";
}
Movie::Movie(int inputMovieDuration, string inputDirector)
  : Content(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating)
{
  movieDuration = inputMovieDuration;
  director = inputDirector;
}
int Movie::getMovieDuration()
{
  return movieDuration;
}
Movie::getDirector()
{
  return director;
}
void Movie::setMovieDuration(int inputMovieDuration)
{
  movieDuration = inputMovieDuration;
}
void Movie::setDirector(string inputDirector)
{
  director = inputDirector;
}
void Movie::printInfo()
{
    
}