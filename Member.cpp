#include "Member.h"
#include "House.h"
#include "Review.h"
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
    this->numOfOccupyHouse = 0;
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
        std::cout << "You can only add one house per account!!!\n";
    }
    else {
        std::string location, description;
        int reqCreditPoints, reqRating;
        int availability = 1;
        std::cout << "Enter location (Saigon/Hanoi/Da Nang): ";
        std::getline(std::cin,location);
        std::cout << "Enter description: ";
        std::getline(std::cin,description);
        std::cout << "Minimum required credit points: ";
        getInput(reqCreditPoints);
        std::cout << "Minimum required rating points: ";
        getInput(reqRating);
        House *newhouse = new House(username, location, description, availability, reqCreditPoints, reqRating);
        houses.push_back(newhouse);
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
            this->rating >= houses[i]->requiredRating && houses[i]->getOwnerUsername() != this->username){
            std::cout << order + 1 << ". ";
            houses[i]->showInfo();
            availableHouses.push_back(houses[i]);
            order++;
        }
    }

    if(order == 0){return false;}else{return true;}
}

void Member::requestOccupy(std::vector<House*> availableHouses, int houseChoice, std::vector<Request*> &requests){
    for(int i = 0; i < availableHouses.size(); i++){
        if(houseChoice == i+1){
            Request *newRequest = new Request(availableHouses[i]->getOwnerUsername(),
            this->username, "Pending");
            requests.push_back(newRequest);
            std::cout << "\nYou've successfully requested to occupy the house of the owner with username is "
            << availableHouses[i]->getOwnerUsername() << ". Let's wait for the owner's response.\n";
        }
    }
};

bool Member::viewRequests() {
    system("cls");
    if(this->myHouse->getAvailability() == 1){
        std::cout << this->myHouse->getAvailability();
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
    }else{
        std::cout << "Sorry, your house has not been available yet, cannot see requests for now.\n";
        return false;
    }
}

std::string Member::acceptRequest(int requestChoice){
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
    return acceptedReq->getOccupierUsername();
}

void Member::showInfo() {
    std::cout << "--------------MEMBER INFORMATION--------------\n";
    std::cout << "\n_Full Name: " << this->fullname + "\n" 
            << "_Phone Number: " << this->phoneNo + "\n"
            << "_Credit Point: " << this->creditPoints << "\n"
            << "_Rating: " << this->rating << "\n"
            << "_Reviews about your house: \n";
    for (Review *eachReview : this->myReviews){
        if(eachReview->getType().compare("house") == 0){
            std::cout << "+Review from: " << eachReview->getWriterUsername();
            std::cout << ", content: " << eachReview->getContent() << "\n";
        }
    }
    std::cout << "_Reviews about you: \n";
    for (Review *eachReview : this->myReviews){
        if(eachReview->getType().compare("occupier") == 0){
            std::cout << "+Review from: " << eachReview->getWriterUsername();
            std::cout << ", content: " << eachReview->getContent() << "\n";
        }
    }
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
void Member::setRating(int rating) {
    this->rating = rating;
}
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
std::vector<Review*> &Member::getMyReview(){
    return this->myReviews;
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
House *Member::getOcuppyingHouse() {
    return this->occuppyingHouse;
}
int Member::getNumOfOccupyHouse() {
    return this->numOfOccupyHouse;
}