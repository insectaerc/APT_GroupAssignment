#include "House.h"
#include <iostream>

House::House(){}
House::House(std::string owner, std::string location, std::string description, bool availability){
    this->owner = owner;
    this->location = location;
    this->description = description;
    this->availability = availability;
}

void House::showInfo() {
    std::cout << "Owner: " << this->owner << ", location: " << this->location << ", description: " << this->description << "\n";
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