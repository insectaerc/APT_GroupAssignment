#include "Member.h"
#include <iostream>

Member::Member(){}
Member::Member(std::string userame, std::string pass) {
    this->username = username;
    this->password = pass;
}
Member::Member(std::string username, std::string password, std::string fullname, std::string phoneNumber){
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->phoneNo = phoneNumber;
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
void Member::setUserName(std::string username){
    this->username= username;
};
void Member::setPassword(std::string password){
    this->password= password;
};

//Getters

void getHouse() {}
void getReview() {}
void getRating() {}
void getCreditPts() {}
void getocuppyingHouse() {}

void Member::showInfo() {
    //return ("Full Name: " + this->fullname + ", Phone No: " + this->phoneNo);
    std::cout << "Full name:" + this->fullname + ", phone number: " + this->phoneNo + "\n";
}