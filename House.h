#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
using std::string;

class House{
    private:
        int rating;
        string review;
        bool availability;
    public:
        string owner;
        string location;
        string description;
        int requiredRating;
        int requiredCreditPoints;
        House();
        //This constructor is called is Member::addHouse
        House(std::string owner, std::string location, std::string description, bool availability);
        //This constructor is called in System::loadData
        House(std::string owner, std::string location, std::string description, bool availability, int creditPoints, int reqRating, int rating);

        void showInfo();
        void showAvailability();

        //Setters
        void setAvailability(bool availability);

        //Getters
        bool getAvailability();
        int getRating();
};

#endif