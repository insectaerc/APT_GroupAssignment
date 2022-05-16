#include "admin.h"

// Constructor
Admin::Admin(string username, string password) {
    this->username = username;
    this->password = password;
}

// Destructor
Admin::~Admin(){}

// Functions
// void viewMemberInfo () {
//     for (Member *member : vectorOfMembers) {
//         cout << "Member username: " << member->username
//              << "\n Fullname: " << member->fullname
//              << "\n Phone number: " << member->phoneNo
//              << "\n Rating: " << member->rating
//              << "\n Credit point: " << member->creditPoints
//              << "\n House location: " << member->myHouse->location
//              << "\n House description: " << member->myHouse->description << "\n";
//     }
// }

// void viewHousesInfo() {
//     for (House *house : vectorOfHouses) {
//         cout << "House location: " << house->location
//              << "\n Description: " << house->description
//              << "\n Rating: " << house->rating
//              << "\n Owner: " << house->owner
//              << "\n Review: " << house->review
//              << "\n Availability: " << house->availability << "\n";
//     }
// }
