#include "movie.h"
#include <iostream>
using namespace std;

Movie::Movie() : Content()
{
  movieDuration = 0;
  director = "";
  contentType = "Movie"
}
Movie::Movie(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating, int inputMovieDuration, string inputDirector, string inputContentType)
  : Content(inputTitle, inputReleaseYear, inputGenre, inputWatched, inputUserRating)
{
  movieDuration = inputMovieDuration;
  director = inputDirector;
}
void Movie::markWatched() {
  Content::markWatched();
}

void Movie::markUnWatched() {
  Content::markUnWatched();
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
  cout << "Movie" << endl;
  Content::printInfo();
  cout << "Director: " << director << "\n";
  int minutes = movieDuration % 60;
  int hours = movieDuration / 60;
  cout << "Movie duration: " << hours << "h" << minutes << "mins";
  cout << endl;
}