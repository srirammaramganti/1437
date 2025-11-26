#ifndef MOVIE_H
#define MOVIE_H
#include "content.h"
#include <iostream>

class Movie : public Content
{
public:
  Movie();
  Movie(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating, int inputMovieDuration, string inputDirector);
  int getMovieDuration();
  string getDirector();
  void markWatched() override;
  void markUnWatched() override;
  void setMovieDuration(int inputMovieDuration);
  void setDirector(string inputDirector);
  void printInfo() override;

private:
  int movieDuration;
  string director;
};