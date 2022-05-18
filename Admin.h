#pragma once

// #ifndef ADMIN_H
// #define ADMIN_H

#include "Member.h"
#include "House.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;

class Admin
{
    private:
        string username;
        string password;
    public:
        // Constructors
        Admin(); // Default
        Admin(string username, string password);
        // Functions
        // void viewMemberInfo();
        // void viewHousesInfo();
        // Getters
        // void getUsername();
        // void getPassword();
};

// #endif