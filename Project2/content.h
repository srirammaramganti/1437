#ifndef CONTENT_H
#define CONTENT_H
#include <iostream>
using namespace std;

class Content
{
public:
  Content();
  Content(string inputTitle, int inputReleaseYear, string inputGenre, bool inputWatched, double inputUserRating);
  virtual void printInfo() const;
  void markWatched();
  void markUnWatched();
  void setRating(double inputUserRating);
  string getTitle();
  bool getIsWatched();
  double getUserRating();

protected:
  string title;
  int releaseYear;
  string genre;
  bool watched;
  double userRating;
};