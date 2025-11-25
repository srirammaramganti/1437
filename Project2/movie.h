#ifndef MOVIE_H
#define MOVIE_H
#include "content.h"
#include <iostream>
using namespace std;

class Movie : public Content
{
public:
  Movie();
  Movie(int inputMovieDuration, string inputDirector);
  int getMovieDuration();
  string getDirector();
  void setMovieDuration(int inputMovieDuration);
  void setDirector(string inputDirector);
  void printInfo() const override;

private:
  int movieDuration;
  string director;
};