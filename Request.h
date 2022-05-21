#pragma once
#include <iostream>

class Request{
    private:
        std::string ownerUsername;
        std::string occupierUsername;
        std::string status;
    public:
        Request();
        Request(std::string ownerUsername, std::string occupierUsername, std::string status);

        //Getters
        std::string getOwnerUsername();
        std::string getOccupierUsername();
        std::string getStatus();

        //Setters
        void setOwnerUsername(std::string username);
        void setOccupierUsername(std::string username);
        void setStatus(std::string status);

        //Functions
        void showInfo();
};