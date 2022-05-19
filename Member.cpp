#include "Member.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

Member::Member() {}
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

//Functions

void Member::addHouse(std::vector<House> *houses, std::string username) {
    std::string location, description;
    std::cout << "Enter location: ";
    std::getline(std::cin,location);
    std::cout << "Enter description: ";
    std::getline(std::cin,description);
    House newhouse(username, location, description, 0);
    houses->push_back(newhouse);
    std::cout << "New House Added!!!\n";
    for(int i = 0; i < houses->size(); i++) {
        houses->at(i).showInfo();
    }
}

void Member::list(House myHouse) {}
void Member::unlist(House myHouse) {}
void Member::request() {}
void Member::viewRequests() {}

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

void Member::setMyHouse(House house) {
    this->myHouse = house;
}

//Getters
std::string Member::getUsername() {
    return this->username;
}
std::string Member::getPassword() {
    return this->password;
}
int Member::getRating() {
    return this->rating;
}
int Member::getCreditPts() {
    return this->creditPoints;
}

House Member::getMyHouse() {
    return this->myHouse;
}

void getHouse() {}
void getReview() {}
void getocuppyingHouse() {}

void Member::showInfo() {
    //return ("Full Name: " + this->fullname + ", Phone No: " + this->phoneNo);
    std::cout << "Full name: " + this->fullname + ", phone number: " + this->phoneNo + "\n";
}