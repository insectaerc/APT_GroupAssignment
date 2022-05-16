#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
using std::string;

typedef struct{
    double rating;
    string owner;
    string location;
    string description;
    string review;
    bool availability;
} House;

#endif