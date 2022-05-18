#include <iostream>
#include "System.h"

int main() {
    system("cls");
    std::cout << "\nEEET2482/COSC2082 ASSIGNMENT\n";
    std::cout << "VACATION HOUSE EXCHANGE APPLICATION\n";
    std::cout << "\nInstructor: Mr. Linh Tran\n";
    std::cout << "Group: Group 29\n";
    std::cout << "s3928992, Quan Tran\n";
    std::cout << "s3695412, Hoang Ninh\n";
    std::cout << "s3515639, Quyen Nguyen\n";
    std::cout << "s3927196, Duy Hoang\n";

    System appSystem; //Initialize an instance to manage the whole system later
    appSystem.loadData();
    appSystem.mainMenu();

    return 0;
}



// bool strto_bool(string str);
// void readFile() {

//     std::ifstream myFile("house.txt");

//     string owner, location, description, rating, review, status;
//     bool availability;

//     string line;

//     while(std::getline(myFile, line)) {
//         std::stringstream ss(line);
//         std::getline(ss, owner, ',');
//         std::getline(ss, location, ',');
//         std::getline(ss, description, ',');
//         std::getline(ss, rating, ',');
//         std::getline(ss, review, ',');
//         ss >> availability;
//         //availability = strto_bool(status);
//         cout << owner << " " << location << " " << description << " ";
//         cout << rating << " " << review << " " << availability << std::endl;
//         if(availability) {
//             cout << "True" << std::endl;
//         }
//         else {
//             cout << "False" << std::endl;
//         }
//     }
//     myFile.close();
// }

// bool strto_bool(string str) {
//     if(str.compare("1")) {
//         return 1;
//     }
//     return 0;
// }
