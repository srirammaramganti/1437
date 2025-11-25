#include "content.h"
#include <iostream>
using namespace std;

Content::Content()
{
  title = "";
  releaseYear = 0;
  genre = "";
  watched = false;
  userRating = 0.0;
}
Content::Content(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating)
{
  title = inputTitle;
  releaseYear = inputReleaseYear;
  genre = inputGenre;
  watched = inputWatched;
  userRating = inputUserRating;
}
void Content::printInfo()
{
}
void Content::markWatched()
{
  watched = true;
}
void Content::markUnWatched()
{
  watched = false;
}
void Content::setRating(double inputUserRating)
{
  userRating = inputUserRating;
}
string Content::getTitle()
{
  return title;
}
bool Content::getIsWatched()
{
  return watched;
}
double Content::getUserRating()
{
  return userRating;
}