#include "Member.h"
#include "House.h"
#include "Input.h"
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
Member::Member(std::string username, std::string password, std::string fullname, std::string phoneNumber, int creditPoints, int rating, int numOfOccupyHouse){    //This constructor is called in System::loadData
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->phoneNo = phoneNumber;
    this->creditPoints = creditPoints;
    this->rating = rating;
    this->numOfOccupyHouse = numOfOccupyHouse;
}

//Functions
void Member::addHouse(std::vector<House*> &houses, std::string username) {
    if(this->numOfHouse == 1) {
        std::cout << "You can only have one house!!!\n";
    }
    else {
        std::string location, description;
        int reqCreditPoints;
        std::cout << "Enter location: ";
        std::getline(std::cin,location);
        std::cout << "Enter description: ";
        std::getline(std::cin,description);
        std::cout << "Minimum required credit point: ";
        getInput(reqCreditPoints);
        House *newhouse = new House(username, location, description, 0);
        newhouse->setRequiredCreditPoints(reqCreditPoints);
        houses.push_back(newhouse);
        setMyHouse(newhouse);
        std::cout << "New House Added!!!\n";
        this->setNumOfHouse(1);
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
        if( city.compare(houses[i]->location) == 0 && 
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

bool Member::viewRequests() {
    system("cls");
    int numOfReq = 0;
    std::cout << "List of all requests to your listed house:\n\n";
    for(int i = 0; i < this->myRequests.size(); i++){
        numOfReq++;
        std::cout << i+1 << ". ";
        std::cout << "Requester's username: " << this->myRequests[i]->getOccupierUsername();
        std::cout << " ------------- Status: " << this->myRequests[i]->getStatus() << "\n";
    }
    if(numOfReq == 0){
        std::cout << "\nThere is no request to show for now.\n";
        return false;
    }else{return true;}
}

void Member::acceptRequest(int requestChoice){
    Request *acceptedReq;
    for(int i = 0; i < this->myRequests.size(); i++){
        if(requestChoice == i+1){
            this->myRequests[i]->setStatus("Accepted");
            acceptedReq = this->myRequests[i];
        }else{
            this->myRequests[i]->setStatus("Rejected");
        }
    }
    std::cout << "\nYou've successfully accepted the request of the member with username: ";
    std::cout << acceptedReq->getOccupierUsername() << ".\n";
}

void Member::showInfo() {
    std::cout << "--------------MEMBER INFORMATION--------------\n";
    std::cout << "Full Name: " << this->fullname + "\n" 
            << "Phone Number: " << this->phoneNo + "\n"
            << "Credit Point: " << this->creditPoints << "\n"
            << "Rating: " << this->rating << "\n";
}

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
void Member::setNumOfHouse(int numOfHouse) {
    this->numOfHouse = numOfHouse;
}
void Member::setOccupyingHouse(House *house) {
    this->occuppyingHouse = house;
}
void Member::setNumOfOccupyHouse(int num) {
    this->numOfHouse = num;
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
int Member::getNumOfHouse() {
    return this->numOfHouse;
}
std::vector<Request*> &Member::getMyRequest(){
    return this->myRequests;
}
House *Member::getocuppyingHouse() {
    return this->occuppyingHouse;
}
int Member::getNumOfOccupyHouse() {
    return this->numOfOccupyHouse;
}