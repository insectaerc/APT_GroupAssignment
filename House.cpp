#include "House.h"
#include <iostream>

House::House(){}
House::House(std::string owner, std::string location, std::string description, bool availability){
    this->owner = owner;
    this->location = location;
    this->description = description;
    this->availability = availability;
    this->rating = 0;
}
//This constructor is called in System::loadData
House::House(std::string owner, std::string location, std::string description, bool availability, int reqCreditPoints, int reqRating, int rating){
    this->owner = owner;
    this->location = location;
    this->description = description;
    this->availability = availability;
    this->requiredCreditPoints = reqCreditPoints;
    this->requiredRating = reqRating;
    this->rating = rating;
}

void House::showInfo() {
    std::cout << "Owner: " << this->owner << ", location: " << this->location << ", description: " << this->description << ", minimum credit points: " << this->requiredCreditPoints << ", minimum rating: " << this->rating <<"\n";
}

void House::showAvailability() {
    std::cout << "Availability: " << this->availability << "\n";
}

//Setters
void House::setAvailability(bool availability) {
    this->availability = availability;
}

//Getters
bool House::getAvailability() {
    return this->availability;
}
int House::getRating(){
    return this->rating;
}