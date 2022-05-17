//Import libraries
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cctype>
#include <fstream>

//Import files
#include "Input.h"
#include "House.h"
#include "Member.h"
#include "Guest.h"

//DEFINE
#define MAXPASSLENGTH 20

using std::string;
using std::cout;
using std::cin;

void mainMenu();
void loginInput(string *username, string *password);
void guestOptions();
void memberOptions();
bool isLoggedIn(string username, string password);
void adminOptions();

void mainMenu() {
    system("cls");

    //Show Options
    cout << "\nUse the app as: 1. Guest, 2. Member, 3. Admin\n";
    cout << "0. EXIT\n";
    cout << "\nEnter your choice: ";
    bool loop = 1;
    int choice;
    getInput(choice);
    while(loop) {
        switch(choice){
        case 1:
            //Guest Options Menu
            guestOptions();
            loop = 0;
            break;
        case 2:
            //Member Options Menu
            memberOptions();
            loop = 0;
            break;
        case 3:
            //Admin Options Menu
            cout << "Admin option";
            loop = 0;
            break;
        case 0:
            //Close App
            cout << "THANK YOU FOR USING OUR PROGRAM";
            exit(0);
        default:
            cout << "Invalid Choice. Please Enter again: ";
            getInput(choice);
        }
    }
}

void guestOptions() {
    string username, password, fullname, phoneNo, str;
    std::ofstream myFile;
    
    system("cls");
    cout << "***** GUEST MENU *****\n\n";
    cout << "1. Register, 2. View Houses\n";
    cout << "0. Return to Main menu\n";
    cout << "\nEnter your choice: ";

    //Guest guest;
    int choice;
    getInput(choice);
    bool loop = 1;
    while(loop) {
        switch(choice){
        case 1:
            //Register Menu
            system("cls");
            cin.ignore();
            cout << "Enter your full name: ";
            std::getline(cin, fullname);
            cout << "Enter your phone Number: ";
            std::getline(cin, phoneNo);
            loginInput(&username, &password);

            str = username + ", " + password + ", " + fullname + ", " + phoneNo;

            //guest.createAcc();

            myFile.open("member.txt", std::ios::app);
            if(myFile.is_open()){
                myFile << "\n" << str;
                myFile.close();
            }

            cout << "\nRegister Succesfully!!!\n";
            cout << "Press Enter to return to main menu....";
            cin.ignore();
            mainMenu();
            loop = 0;
            break;
        case 2:
            //View House Menu
            //guest.viewHouses();
            loop = 0;
            break;
        case 0:
            //Return to Main menu
            mainMenu();
            loop = 0;
            break;
        default:
            cout << "Invalid Choice. Please Enter again: ";
            getInput(choice);
        }
    }
}

void memberOptions() {
    //Declare pointer for username and password
    string username, password;
  
    system("cls");
    cin.ignore();

    while(1) {
        loginInput(&username, &password);

        if(!isLoggedIn(username, password)) {
            cout << "Wrong password or username!!!\n\n"; 
        }
        else {
            break;
        }
    }

    Member* member = new Member(username, password);
    member->setName("Quan");
    member->setphoneNo("032164564654");
  
    //system("cls");
    cout << "\n***** MEMBER MENU *****\n\n";
    cout << "1. View Information\n";
    cout << "2. View Houses\n";
    cout << "3. Search Houses\n";
    cout << "4. Request House\n";
    cout << "5. View Requests\n";
    cout << "6. Rating\n";
    cout << "0. Return to Main menu\n";
    cout << "\nEnter your choice: ";
    int choice;
    switch(getInput(choice)){
    case 1:
        cout << member->showInfo();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 0:
        mainMenu();
        break;
    default:
        cout << "Wrong Input\n";
        cout << "Press ENTER to Continue....\n";
        cin.ignore();
        cin.ignore();
        mainMenu();
    }
}

void loginInput(string *u, string *p) {
    while(1) {
        cout << "Enter username: ";
        std::getline(cin, *u);
        if(u->length() > 0) {
            break;
        }
        cout << "No Username entered!!!\n";
    }
    while(1) {
        cout << "Enter password: ";
        std::getline(cin, *p);
        if(p->length() > MAXPASSLENGTH) {
            cout << "Your password is too long\n";
        }
        else if(p->length() == 0) {
            cout << "\nNo Password entered!!!\n";
        }
        else {
            break;
        }
    }
}

bool isLoggedIn(string username, string password) {
    string u, p; //Correct username and password

    //Convert username to lowercase
    for(int i = 0; i < username.length(); i++) {
        username[i] = tolower(username[i]);
    }

    //Read file function for below code
    u = "Username";
    p = "123456789";

    //Validation
    if(username == u && password == p) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cout << "\nEEET2482/COSC2082 ASSIGNMENT\n";
    cout << "VACATION HOUSE EXCHANGE APPLICATION\n";
    cout << "\nInstructor: Mr. Linh Tran\n";
    cout << "Group: Group 29\n";
    cout << "s3928992, Quan Tran\n";
    cout << "s3695412, Hoang Ninh\n";
    cout << "s3515639, Quyen Nguyen\n";
    cout << "s3927196, Duy Hoang\n";
    mainMenu();
    return 0;
}