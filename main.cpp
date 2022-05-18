//Import libraries
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

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

class System{
    public:
        bool isLoggedIn;
        std::vector<Member*> members;
        std::vector<House*> houses;
        System(){};
};

void saveData(System appSystem);
void loadData(System &appSystem);
void mainMenu(System appSystem);
void guestOptions(System appSystem);
void memberOptions(System appSystem);
void adminOptions();
void loginInput(string *username, string *password);

bool isLoggedIn(string username, string password);
bool strto_bool(string str);

string toLowercase(string str);

void mainMenu(System appSystem) {
    //Load Data
    loadData(appSystem);

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
            guestOptions(appSystem);
            loop = 0;
            break;
        case 2:
            //Member Options Menu
            memberOptions(appSystem);
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
            cout << "Invalid Choice. Enter again: ";
            getInput(choice);
        }
    }
}

void guestOptions(System appSystem) {
    system("cls");
    cout << "***** GUEST MENU *****\n\n";
    cout << "1. Register\n";
    cout << "2. View Houses\n";
    cout << "0. Return to Main menu\n";
    cout << "\nEnter your choice: ";
    
    //Create a Member instance
    Member *newMember = new Member();
    string username, password, fullname, phoneNo, str;

    int choice;
    getInput(choice);
    bool loop = 1;
    while(loop) {
        switch(choice){
        case 1: //Register Menu
            system("cls");
            cin.ignore();

            //Get info from user
            cout << "Enter your full name: ";
            std::getline(cin, fullname);
            cout << "Enter your phone Number: ";
            std::getline(cin, phoneNo);
            loginInput(&username, &password);

            //Convert username to lowercase
            username = toLowercase(username);

            //Save info to newMember instance
            newMember->setUserName(username);
            newMember->setPassword(password);
            newMember->setName(fullname);
            newMember->setphoneNo(phoneNo);

            appSystem.members.push_back(newMember);
            //std::cout << appSystem.members.size();
            //newMember->showInfo();


            // //Save info to file
            // str = username + ", " + password + ", " + fullname + ", " + phoneNo;
            // myFile.open("member.txt", std::ios::app);
            // if(myFile.is_open()){
            //     myFile << "\n" << str;
            //     myFile.close();
            // }

            cout << "\nRegister Succesfully!!!\n";
            cout << "Press Enter to return to main menu....";
            appSystem.isLoggedIn = true;
            cin.ignore();
            system("cls");
            memberOptions(appSystem);
            loop = 0;
            break;
        case 2:
            //View House Menu
            //guest.viewHouses();
            loop = 0;
            break;
        case 0:
            //Return to Main menu
            system("cls");
            mainMenu(appSystem);
            loop = 0;
            break;
        default:
            cout << "Invalid Choice. Enter again: ";
            getInput(choice);
        }
    }
}

void memberOptions(System appSystem) {
    //Declare pointer for username and password
    string username, password;
  
    system("cls");
    cin.ignore();

    bool loop = 1;
    while(loop) {
        // if(appSystem.isLoggedIn=true){
        //     loop = 0;
        //     break;
        // }
        loginInput(&username, &password);
        if(!isLoggedIn(username, password)) {
            cout << "Wrong password or username!!!\n";
            cout << "Return to main menu? (Y/N): ";
            char choice;
            switch(getInput(choice)){
                case 'Y': case 'y':
                    mainMenu(appSystem);
                    loop = 0;
                    break;
                case 'N': case 'n':
                    cin.ignore();
                    break;
                default:
                    cout << "Invalid Choice. Enter again: ";
                    getInput(choice);
            }
        }
        else {
            break;
        }
    }

    Member* member = appSystem.members.back();
    member->showInfo();
  
    //system("cls");
    cout << "\n***** MEMBER MENU *****\n\n";
    cout << "1. View Information\n";
    cout << "2. Add House\n";
    cout << "3. List/Unlist House\n";
    cout << "4. Search Houses\n";
    cout << "5. Request House\n";
    cout << "6. View Requests\n";
    cout << "7. Rating\n";
    cout << "0. Return to Main menu\n";
    cout << "\nEnter your choice: ";
    
    int choice;
    switch(getInput(choice)){
    case 1:
        member->showInfo();
        break;
    case 2: //Add Houses
        break;
    case 3: //List/Unlist Houses
        break;
    case 4: //Search Houses
        break;
    case 5: //Request
        break;
    case 6: //View requests
        break;
    case 7: //Rating
        break;
    case 0:
        system("cls");
        mainMenu(appSystem);
        break;
    default:
        cout << "Wrong Input\n";
        cout << "Press ENTER to Continue....\n";
        cin.ignore();
        cin.ignore();
        mainMenu(appSystem);
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
    username = toLowercase(username);

    //Read file function for below code
    u = "username";
    p = "123456789";

    //Validation
    if(username == u && password == p) {
        return true;
    }
    else {
        return false;
    }
}

string toLowercase(string str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

void readFile() {

    std::ifstream myFile("house.txt");

    string owner, location, description, rating, review, status;
    bool availability;

    string line;

    while(std::getline(myFile, line)) {
        std::stringstream ss(line);
        std::getline(ss, owner, ',');
        std::getline(ss, location, ',');
        std::getline(ss, description, ',');
        std::getline(ss, rating, ',');
        std::getline(ss, review, ',');
        ss >> availability;
        //availability = strto_bool(status);
        cout << owner << " " << location << " " << description << " ";
        cout << rating << " " << review << " " << availability << std::endl;
        if(availability) {
            cout << "True" << std::endl;
        }
        else {
            cout << "False" << std::endl;
        }
    }
    myFile.close();
}

bool strto_bool(string str) {
    if(str.compare("1")) {
        return 1;
    }
    return 0;
}

void saveData(System appSystem) {
    //std::ifstream myFile;
    std::ofstream newFile;
    //myFile.open("data.txt", std::ios::in);
    newFile.open("data.txt", std::ios::out);

    std::vector<Member*> members;
    std::vector<House*> houses;

    members = appSystem.members;
    houses = appSystem.houses;
    newFile << "Member|";
    
    for(int i = 0; i < members.size(); i++) {
        newFile << members[i]->getUsername() << "|" << members[i]->getPassword() << "|";
        newFile << members[i]->getName() << "|" << members[i]->getphoneNo() << "|";
    }

    newFile << "\nHouse|";

    for(int i = 0; i < houses.size(); i++) {
        newFile << houses[i]->owner << "|" << houses[i]->location << "|" << houses[i]->description << "|";
    }
    newFile.close();
}

void loadData(System &appSystem){
    std::fstream myFile;
    myFile.open("data.txt", std::ios::in);
    std::string tempStr;
    std::string className;
    std::string username, password, fullname, phoneNumber;
    std::string houseOwner, location, description;
    int numOfMemberValue = 0;
    int numOfHouseValue = 0;
    while(getline(myFile, tempStr, '|')){
        if(tempStr == "Member"){
            className = "Member";
            continue;
        }else if (tempStr == "\nHouse"){
            className = "House";
            continue;
        }
        
        if(className == "Member"){
            numOfMemberValue++;
            if(numOfMemberValue == 1){username = tempStr; continue;};
            if(numOfMemberValue == 2){password = tempStr; continue;};
            if(numOfMemberValue == 3){fullname = tempStr; continue;};
            if(numOfMemberValue == 4){
                phoneNumber = tempStr;
                Member *member = new Member(username, password, fullname, phoneNumber);
                appSystem.members.push_back(member);
                numOfMemberValue = 0;
                continue;
            };
        }else if (className == "House"){
            numOfHouseValue++;
            //std::cout << "Num of house value: " << numOfHouseValue << std::endl;
            if(numOfHouseValue == 1){houseOwner = tempStr; continue;};
            if(numOfHouseValue == 2){location = tempStr; continue;};
            if(numOfHouseValue == 3){
                //std::cout << "fasdfasd";
                description = tempStr;
                House *house = new House(houseOwner, location, description);
                appSystem.houses.push_back(house);
                //std::cout << "House size: " << appSystem.houses.size() << std::endl;
                numOfHouseValue = 0;
                continue;
            };
        }
    }
    myFile.close();
}

int main() {
    system("cls");
    // cout << "\nEEET2482/COSC2082 ASSIGNMENT\n";
    // cout << "VACATION HOUSE EXCHANGE APPLICATION\n";
    // cout << "\nInstructor: Mr. Linh Tran\n";
    // cout << "Group: Group 29\n";
    // cout << "s3928992, Quan Tran\n";
    // cout << "s3695412, Hoang Ninh\n";
    // cout << "s3515639, Quyen Nguyen\n";
    // cout << "s3927196, Duy Hoang\n";

    System appSystem; //Initialize an instance to manage the whole system later

    //mainMenu(appSystem);
    loadData(appSystem);
    saveData(appSystem);
    //readFile();

    // loadData(appSystem);
    // for(Member *each : appSystem.members){
    //     each->showInfo();
    // }
    // for(House *each : appSystem.houses){
    //     each->showInfo();
    // }

    //mainMenu(appSystem);
    return 0;
}