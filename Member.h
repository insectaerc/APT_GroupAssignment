#pragma once

#ifndef MEMBER_H
#define MEMBER_H

#include "House.h"
#include <iostream>

class Member {
private:
    string username;
    string password;
    string fullname;
    string phoneNo;
    House myHouse;
    string review;
    int rating;
    int creditPoints;
    House ocuppyingHouse;
public:
    //Constructor
    Member();
    Member(string username, string password);

    //Functions
    void list(House myHouse);
    void unlist(House myHouse);
    void request();
    void viewRequests();

    //Getters
    string getName();
    string getphoneNo();
    void getHouse();
    void getReview();
    void getRating();
    void getCreditPts();
    void getocuppyingHouse();

    string showInfo();
};

#endif