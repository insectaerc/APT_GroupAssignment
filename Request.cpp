#include "Request.h"

#include <iostream>

//Constructors
Request::Request(){}
Request::Request(std::string ownerUsername, std::string occupierUsername, std::string status){
    this->ownerUsername = ownerUsername;
    this->occupierUsername = occupierUsername;
    this->status = status;
}

//Getters
std::string Request::getOwnerUsername() {
    return this->ownerUsername;
}
std::string Request::getOccupierUsername(){
    return this->occupierUsername;
}
std::string Request::getStatus(){
    return this->status;
}

//Setters
void Request::setOwnerUsername(std::string username){
    this->ownerUsername = username;
};
void Request::setOccupierUsername(std::string username){
    this->occupierUsername = username;
};
void Request::setStatus(std::string status){
    this->status = status;
};

//Functions
void Request::showInfo(){
    std::cout << "House's Owner Username: " << this->ownerUsername
    << "\nRequester's Username: " << this->occupierUsername
    << "\nStatus: " << this->status << "\n";
}