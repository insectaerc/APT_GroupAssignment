#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
using std::string;

class House{
    private:
        double rating;
        string review;
        bool availability;
    public:
        string owner;
        string location;
        string description;
        House();
        House(std::string owner, std::string location, std::string description, bool availability);

        void showInfo();
        void showAvailability();

        //Setters
        void setAvailability(bool availability);

        //Getters
        bool getAvailability();
};

#endif