#pragma once

// #ifndef MEMBER_H
// #define MEMBER_H

#include "House.h"
#include "Request.h"
#include <iostream>
#include <vector>

class Member {
private:
    std::string username;
    std::string password;
    std::string fullname;
    std::string phoneNo;
    House *myHouse;
    std::vector<Request*> myRequests;
    int numOfHouse;
    std::string review;
    int rating;
    int creditPoints;
    House ocuppyingHouse;
public:
    //Constructor
    Member();
    Member(std::string username, std::string password, std::string fullname, std::string phoneNumber);
    Member(std::string username, std::string password, std::string fullname, std::string phoneNumber,
            int creditPoints, int rating); //This constructor is called in System::loadData

    //Functions
    void addHouse(std::vector<House*> &houses, std::string username);
    void list(House *myHouse);
    void unlist(House *myHouse);
    bool searchHouses(std::string cityName, std::vector<House*> houses, std::vector<House*> &availableHouses);
    void requestOccupy(std::vector<House*> availableHouses, int houseChoice, std::vector<Request*> requests);
    bool viewRequests();
    void acceptRequest(int requestChoice);
    void showInfo();

    //Setters
    void setName(std::string name);
    void setphoneNo(std::string phoneNo);
    void setUserName(std::string username);
    void setPassword(std::string password);
    void setMyHouse(House *house);
    void setNumOfHouse(int numOfHouse);

    //Getters
    std::string getName();
    std::string getphoneNo();
    std::string getUsername();
    std::string getPassword();
    House *getMyHouse();
    std::vector<Request*> &getMyRequest();
    int getNumOfHouse();
    void getHouse();
    void getReview();
    int getRating();
    int getCreditPts();
    void getocuppyingHouse();

};

//#endif