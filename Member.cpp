#include "Member.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>


Member::Member(std::string name, std::string pass, std::string fullname, std::string phoneNo) {
    this->username = name;
    this->password = pass;
    this->fullname = fullname;
    this->phoneNo = phoneNo;
}

std::string Member::getName() {
    return this->fullname;
}

std::string Member::getphoneNo() {
    return this->phoneNo;
}

//Functions

// void Member::addHouse() {
//     //user1, location1, descript1, rating1, review1, 0
//     string location, description, rating = "", review = "", availability = 0;
//     string str;
//     std::ofstream myFile;

//     std::cout << "Enter location: ";
//     std::getline(std::cin, location);

//     std::cout << "Enter description: ";
//     std::getline(std::cin, description);

//     str = this->username + ", " + location + ", " + description + ", " + rating + ", " + review + ", " + availability;

//     myFile.open("house.txt", std::ios::app);
//     if(myFile.is_open()) {
//         myFile << str << "\n";
//         myFile.close();
//     }
// }

void Member::addHouse() {}
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

//Getters

void getHouse() {}
void getReview() {}
void getRating() {}
void getCreditPts() {}
void getocuppyingHouse() {}

std::string Member::showInfo() {
    return ("Full Name: " + this->fullname + ", Phone No: " + this->phoneNo);
}