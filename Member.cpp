#include "Member.h"
#include <iostream>


Member::Member(std::string name, std::string pass) {
    this->username = name;
    this->password = pass;
}

std::string Member::getName() {
    return this->fullname;
}

std::string Member::getphoneNo() {
    return this->phoneNo;
}

void list(House myHouse) {}
void unlist(House myHouse) {}
void request() {}
void viewRequests() {}

//Setters
void Member::setName(std::string fullname) {
    this->fullname = fullname;
}

void Member::setphoneNo(std::string phoneNo) {
    this->phoneNo = phoneNo;
}

//Getters

void getHouse() {}
void getReview() {}
void getRating() {}
void getCreditPts() {}
void getocuppyingHouse() {}

std::string Member::showInfo() {
    return ("Full Name: " + this->fullname + ", Phone No: " + this->phoneNo);
}