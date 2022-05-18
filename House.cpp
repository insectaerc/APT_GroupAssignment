#include "House.h"
#include <iostream>

House::House(){}
House::House(std::string owner, std::string location, std::string description){
    this->owner = owner;
    this->location = location;
    this->description = description;
}

void House::showInfo(){
    std::cout << "Owner: " << this->owner << ", location: " << this->location << ", description: " << this->description << "\n";
}

// Getters
double getRating() {
    return this->rating;
}

string getReview() {
    return this->review;
}
bool getAvailability() {
    return this->availability;
}
