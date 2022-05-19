#include "Member.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

//Constructors
Member::Member() {
    this->creditPoints = 500;
    this->rating = 0;
}
Member::Member(std::string username, std::string password, std::string fullname, std::string phoneNumber){
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->phoneNo = phoneNumber;
    this->creditPoints = 500;
    this->rating = 0;
}
Member::Member(std::string username, std::string password, std::string fullname, std::string phoneNumber, int creditPoints, int rating){    //This constructor is called in System::loadData
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->phoneNo = phoneNumber;
    this->creditPoints = creditPoints;
    this->rating = rating;
}


//Functions
void Member::addHouse(std::vector<House*> &houses, std::string username) {
    std::string location, description;
    std::cout << "Enter location: ";
    std::getline(std::cin,location);
    std::cout << "Enter description: ";
    std::getline(std::cin,description);
    House *newhouse = new House(username, location, description, 0);
    houses.push_back(newhouse);
    std::cout << "New House Added!!!\n";
    for(int i = 0; i < houses.size(); i++) {
        houses[i]->showInfo();
    }
}

void Member::list(House *myHouse) {
    if(myHouse->getAvailability() == 0) {
        myHouse->setAvailability(1);
        std::cout << "House listed successfully!!\n";
    }
    else {
        std::cout << "House is already listed!!\n";
    }
}

void Member::unlist(House *myHouse) {
    if(myHouse->getAvailability() == 1) {
        myHouse->setAvailability(0);
        std::cout << "House unlisted successfully!!\n";
    }
    else {
        std::cout << "House is already unlisted!!\n";
    }
}

bool Member::searchHouses(std::string city, std::vector<House*> houses, std::vector<House*> &availableHouses){
    system("cls");
    std::cout << "You selected " << city << " city. Available houses in " << city << " city:\n\n";
    int order = 0;
    for(int i = 0; i < houses.size(); i++){
        if( city == houses[i]->location && 
            this->creditPoints >= houses[i]->requiredCreditPoints &&
            this->rating >= houses[i]->requiredRating){
            std::cout << order + 1 << ". ";
            houses[i]->showInfo();
            availableHouses.push_back(houses[i]);
            order++;
        }
    }

    if(order == 0){return false;}else{return true;}
}

void Member::requestOccupy(std::vector<House*> availableHouses, int houseChoice, std::vector<Request*> requests){
    for(int i = 0; i < availableHouses.size(); i++){
        if(houseChoice == i+1){
            Request *newRequest = new Request(this->username,
            availableHouses[i]->getOwnerUsername(), "Pending");
            requests.push_back(newRequest);
            std::cout << "\nYou've successfully requested to occupy the house of the owner with username is "
            << availableHouses[i]->getOwnerUsername() << ". Let's wait for the owner's response.\n";
        }
    }
};

void Member::viewRequests(std::vector<Request*> requests) {
    system("cls");
    std::cout << "List of all requests to your listed house:\n\n";
    for(int i = 0; i < requests.size(); i++){
        if(requests[i]->getOwnerUsername() == this->username){
            std::cout << i+1 << ". ";
            std::cout << "Requester's username: " << requests[i]->getOccupierUsername();
            std::cout << " ------------- Status: " << requests[i]->getStatus() << "\n";
        }
    }
}

void Member::showInfo() {
    std::cout << "--------------MEMBER INFORMATION--------------\n";
    std::cout << "Full Name: " << this->fullname + "\n" 
            << "Phone Number: " << this->phoneNo + "\n"
            << "Credit Point: " << this->creditPoints << "\n"
            << "Rating: " << this->rating << "\n";
}

//Getters
std::string Member::getName() {
    return this->fullname;
}
std::string Member::getphoneNo() {
    return this->phoneNo;
}
std::string Member::getUsername() {
    return this->username;
}
std::string Member::getPassword() {
    return this->password;
}
int Member::getCreditPts() {
    return this->creditPoints;
}
int Member::getRating() {
    return this->rating;
}
House *Member::getMyHouse() {
    return this->myHouse;
}

void getHouse() {}
void getReview() {}
void getocuppyingHouse() {}

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
void Member::setMyHouse(House *house) {
    this->myHouse = house;
}
