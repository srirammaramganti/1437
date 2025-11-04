








































/*#ifndef PARTY_H
#define PARTY_H

#include <string>

class Party
{
private:
    std::string location;
    std::string* attendees;
    int maxAttendees;
    int numAttendees;

public:
    Party();                                   // Default constructor (already implemented)
    Party(std::string l, int num);             // Constructor with parameters
    Party(const Party& other);                  // Copy constructor (deep copy)
    Party& operator=(const Party& other);       // Copy assignment (deep copy)
    ~Party();                                   // Destructor

    Party& operator+(const std::string& name);  // Add attendee
    bool operator>(const Party& rhs) const;     // Compare by number of attendees

    void changeAttendeeAt(std::string name, int pos);
    void print();
    std::string getAttendeeAt(int pos);
    int getMaxAttendees() const;
    int getNumAttendees() const;
    std::string getLocation() const;
    void setLocation(std::string);
};

#endif*/
