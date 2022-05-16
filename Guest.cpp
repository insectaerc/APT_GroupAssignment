#include <stdio.h>
#include <iostream>
#include <fstream>
#include "house.h"
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

class Guest: public House
    {
     int rating;
     public:

        vector<House> vectorOfHouses;
        void viewHouse(){
          for(House house: vectorOfHouses){
            cout<<"House owner: "<< house.owner;
            cout<<"Address is: "<< house.location;
            cout<<"Rating: " << house.rating;
            }  
        }   

    void createAccount() // Takes and stores users login information, username and password
    {
    string username, fullname;
    string password;
    int phoneNumber;

        cout << "Please create a username: ";
        cin >> username;
        cout << "Please create a password: ";
        cin >> password;
        cout << "Please enter your full name: ";
        cin >> fullname;
        cout << "Please enter your phone number: ";
        cin >> phoneNumber;
    
        ofstream createAccount;
    createAccount.open("accounts.txt");
    createAccount << username << " " << password;
    createAccount.close();
    cout << "Account successfully created" << endl;
    }
};