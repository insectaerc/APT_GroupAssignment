#include "Member.h"
#include <iostream>

using std::cout;
using std::string;

//Constructor
Member::Member(string username, string password): 
    username(username), password(password) {}

//Functions
void list(House myHouse);
void unlist(House myHouse);
void request();
void viewRequests();

//Getters
string Member::getName() {
    return this->fullname;
}
string Member::getphoneNo() {
    return this->phoneNo;
}
void getHouse();
void getReview();
void getRating();
void getCreditPts();
void getocuppyingHouse();

//showInfo
string Member::showInfo() {
    string str;
    str = "Full Name: " + getName() + ", Phone Number: " + getphoneNo();
    return str;
}