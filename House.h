#pragma once

#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "Member.h"

class Member; //Forward declaration

class House{
    private:
        int rating;
        std::string review;
        bool availability;
        Member* occupier;
        std::string occupierUsername;   //This is used when load data for Member::occupyingHouse attribute
        int numOfOccupier;
    public:
        std::string owner;
        std::string location;
        std::string description;
        int requiredRating;
        int requiredCreditPoints;
        House();
        //This constructor is called is Member::addHouse
        House(std::string owner, std::string location, std::string description, bool availability, int reqCrePoints, int reqRating);
        //This constructor is called in System::loadData
        House(std::string owner, std::string location, std::string description, bool availability, int creditPoints, int reqRating, int rating, std::string review, int numOfOccupier, std::string occupierUsername);

        void showInfo();
        void showAvailability();

        //Setters
        void setAvailability(bool availability);
        void setRequiredCreditPoints(int reqCreditPoints);
        void setRating(int rating);
        void setReview(std::string review);
        void setOccupier(Member *occupier);
        void setNumOfOccupier(int num);
        void setOccupierUsername(std::string occupierUsername);

        //Getters
        bool getAvailability();
        std::string getOwnerUsername();
        int getRating();
        std::string getReview();
        Member *getOccupier();
        int getNumOfOccupier();
        std::string getOccupierUsername();
};

#endif