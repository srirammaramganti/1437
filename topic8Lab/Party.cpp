#include <iostream>
#include <string>

using namespace std;

#include "Party.h"

Party::Party()
{
   //Default: 10 attendees, location = home
   location = "Home";
   maxAttendees = 10;
   numAttendees = 0;
   attendees = new string[maxAttendees];
}

//Define constructor with two parameters
//If the input integer is not positive, set maxAttendees = 10
Party::Party(string location, int numAttendees) {
    if (numAttendees < 0) {
        maxAttendees = 10;
    }
}
   
//Define the copy constructor
Party::Party(const Party& otherP) {
    if (this == &otherP) {
        return this;
    }

}
//Define the overloaded copy assignment operator (=)
Party::Party& operator=(const Party& otherParty) {
    location = otherParty.location;
    maxAttendees = otherParty.maxAttendees;
    numAttendees = otherParty.numAttendees;
}

/*
 Add an overloaded operator + to add an attendee to the party. You should check whether you reach the maximum number of attendees or not. 
 If not, add this attendee to the list and increase the number of current attendees by 1. Otherwise, output a message "The party is already full!" 
 without adding the attendee.*/
//Define the overloaded operator (+) to add an attendee
Party::Party& operator+(string& name) {
    if (numAttendees < maxAttendees) {
        attendees[numAttendees+1] = name;
        maxAttendees += 1;
    } else {
        cout << "The party is already full" << endl;
    }
}
//Define the overloaded operator (>) to compare two parties
Party::Party& operator>(int numAttendees) {
    bool Boolean;
    if (numAttendees == Party.numAttendees) {
        Boolean = true;
    } else {
        Boolean = false;
    }
    return Boolean;
}
//Add destructor
Party::~Party() {
    delete [] attendees;
}
//The following functions are provided
//Do not change
void Party::changeAttendeeAt(string name, int pos)
{
   if(pos>=0 && pos<numAttendees)
      attendees[pos] = name;
   else
      cout << "Invalid index.";
}

void Party::print()
{
   if(numAttendees > 0)
   {
      cout << "Attendees list:\n";
      for(int i = 0; i<numAttendees; i++)
         cout << attendees[i] << endl;
   }
   else
      cout << "List is empty! Invite more people to your party.\n";
}

string Party::getAttendeeAt(int pos)
{
   if(pos>=0 && pos<numAttendees)
      return attendees[pos];
   else
      return "Invalid index.";
}

int Party::getNumAttendees() const
{  return numAttendees;  }

int Party::getMaxAttendees() const
{  return maxAttendees;  }

string Party::getLocation() const
{  return location;  }

void Party::setLocation(string new_loc)
{   location = new_loc;  }

/*#include <iostream>
#include <string>
#include "Party.h"

using namespace std;

Party::Party()
{
    // Default: 10 attendees, location = Home
    location = "Home";
    maxAttendees = 10;
    numAttendees = 0;
    attendees = new string[maxAttendees];
}

// Define constructor with two parameters
// If the input integer is not positive, set maxAttendees = 10
Party::Party(string l, int num)
{
    location = l;
    maxAttendees = (num > 0 ? num : 10);
    numAttendees = 0;
    attendees = new string[maxAttendees];
}

// Define the copy constructor (deep copy)
Party::Party(const Party& other)
{
    location = other.location;
    maxAttendees = other.maxAttendees;
    numAttendees = other.numAttendees;
    attendees = new string[maxAttendees];
    for (int i = 0; i < numAttendees; ++i) {
        attendees[i] = other.attendees[i];
    }
}

// Define the overloaded copy assignment operator (=) (deep copy)
Party& Party::operator=(const Party& other)
{
    if (this == &other) return *this;

    // Free existing resources
    delete[] attendees;

    // Copy fields
    location = other.location;
    maxAttendees = other.maxAttendees;
    numAttendees = other.numAttendees;

    // Allocate new array and copy elements
    attendees = new string[maxAttendees];
    for (int i = 0; i < numAttendees; ++i) {
        attendees[i] = other.attendees[i];
    }
    return *this;
}

// Define the overloaded operator (+) to add an attendee
Party& Party::operator+(const string& name)
{
    if (numAttendees < maxAttendees) {
        attendees[numAttendees++] = name;
    } else {
        cout << "The party is already full!" << endl;
    }
    return *this; // Allow chaining like: p + "Alice" + "Bob";
}

// Define the overloaded operator (>) to compare two parties
bool Party::operator>(const Party& rhs) const
{
    return numAttendees > rhs.numAttendees;
}

// Add destructor
Party::~Party()
{
    delete[] attendees;
}

// The following functions are provided
// Do not change

void Party::changeAttendeeAt(string name, int pos)
{
    if (pos >= 0 && pos < numAttendees)
        attendees[pos] = name;
    else
        cout << "Invalid index.";
}

void Party::print()
{
    if (numAttendees > 0)
    {
        cout << "Attendees list:\n";
        for (int i = 0; i < numAttendees; i++)
            cout << attendees[i] << endl;
    }
    else
        cout << "List is empty! Invite more people to your party.\n";
}

string Party::getAttendeeAt(int pos)
{
    if (pos >= 0 && pos < numAttendees)
        return attendees[pos];
    else
        return "Invalid index.";
}

int Party::getNumAttendees() const { return numAttendees; }
int Party::getMaxAttendees() const { return maxAttendees; }
string Party::getLocation() const { return location; }
void Party::setLocation(string new_loc) { location = new_loc; }
*/