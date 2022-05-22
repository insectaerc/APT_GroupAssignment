#include "House.h"
#include <iostream>

House::House(){}
House::House(std::string owner, std::string location, std::string description, bool availability, int reqCrePoints, int reqRating){
    this->owner = owner;
    this->location = location;
    this->description = description;
    this->availability = availability;
    this->requiredCreditPoints = reqCrePoints;
    this->requiredRating = reqRating;
    this->rating = 0;
    this->occupierUsername = "";
    this->numOfOccupier = 0;
}
//This constructor is called in System::loadData
House::House(std::string owner, std::string location, std::string description, bool availability, int reqCreditPoints, int reqRating, int rating, std::string review, int numOfOccupier, std::string occupierUsername){
    this->owner = owner;
    this->location = location;
    this->description = description;
    this->availability = availability;
    this->requiredCreditPoints = reqCreditPoints;
    this->requiredRating = reqRating;
    this->rating = rating;
    this->review = review;
    this->numOfOccupier = numOfOccupier;
    this->occupierUsername = occupierUsername;
}

void House::showInfo() {
    std::cout << "Owner: " << this->owner << "\nLocation: " << this->location << "\nDescription: "
    << this->description << "\nMinimum credit points: " << this->requiredCreditPoints << "\nMinimum rating: "
    << this->requiredRating << "\n";
    if(this->availability == 1){
        std::cout << "Status: Available\n";
    }
}

void House::showAvailability() {
    std::cout << "Availability: " << this->availability << "\n";
}

//Setters
void House::setAvailability(bool availability) {
    this->availability = availability;
}
void House::setRequiredCreditPoints(int reqCreditPoints) {
    this->requiredCreditPoints = reqCreditPoints;
}
void House::setRating(int rating) {
    this->rating = rating;
}
void House::setReview(std::string review) {
    this->review = review;
}
void House::setOccupier(Member *occupier) {
    this->occupier = occupier;
}
void House::setNumOfOccupier(int num) {
    this->numOfOccupier = num;
}
void House::setOccupierUsername(std::string occupierUsername){
    this->occupierUsername = occupierUsername;
}

//Getters
bool House::getAvailability() {
    return this->availability;
}
int House::getRating(){
    return this->rating;
}
std::string House::getReview() {
    return this->review;
}
std::string House::getOwnerUsername() {
    return this->owner;
}
int House::getNumOfOccupier() {
    return this->numOfOccupier;
}
Member* House::getOccupier() {
    return this->occupier;
}
std::string House::getOccupierUsername(){
    return this->occupierUsername;
}