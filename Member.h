#pragma once

// #ifndef MEMBER_H
// #define MEMBER_H

#include "House.h"
#include <iostream>
#include <vector>

class Member {
private:
    std::string username;
    std::string password;
    std::string fullname;
    std::string phoneNo;
    House myHouse;
    std::string review;
    int rating;
    int creditPoints;
    House ocuppyingHouse;
public:
    //Constructor
    Member();
    Member(std::string username, std::string password);
    Member(std::string username, std::string password, std::string fullname, std::string phoneNumber);

    //Functions
    void addHouse(std::vector<House*> &houses, std::string username);
    void list(House myHouse);
    void unlist(House myHouse);
    void request();
    void viewRequests();

    //Setters

    void setName(std::string name);
    void setphoneNo(std::string phoneNo);
    void setUserName(std::string username);
    void setPassword(std::string password);

    //Getters
    std::string getName();
    std::string getphoneNo();
    std::string getUsername();
    std::string getPassword();
    void getHouse();
    void getReview();
    void getRating();
    void getCreditPts();
    void getocuppyingHouse();

    void showInfo();
};

//#endif