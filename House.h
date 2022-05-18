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
        House(std::string owner, std::string location, std::string description);

        // Getters
        double getRating();
        string getReview();
        bool getAvailability();

        void showInfo();
};

#endif