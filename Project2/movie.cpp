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
  : Content(inputTitle, inputReleaseYear, inputGenre, inputWatched, inputUserRating)
{
  movieDuration = inputMovieDuration;
  director = inputDirector;
}
int Movie::getMovieDuration()
{
  return movieDuration;
}
string Movie::getDirector()
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