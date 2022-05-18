#pragma once

//#ifndef ADMIN_H
//#define ADMIN_H

#include "Member.h"
#include "House.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;

class Admin : public Member, public House
{
    private:
        string username;
        string password;
        vector<Member*> vectorOfMembers;
        vector<House*> vectorOfHouses;
    public:
        // Constructors
        Admin(); // Default
        Admin(string username, string password);
        // Destructor
        ~Admin();
        // Functions
        void viewMemberInfo();
        void viewHousesInfo();
        // Getters
        void getUsername();
        void getPassword();
};

//#endif