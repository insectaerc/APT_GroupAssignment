#include "System.h"
#include "Input.h"

//Constructor
System::System(){this->isLoggedInVar = false;}

//Functions
void System::loadData(){
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
        //Remove new line character \n from tempStr
        tempStr.erase(remove(tempStr.begin(), tempStr.end(), '\n'), tempStr.end());
        
        if(className == "Member"){
            numOfMemberValue++;
            if(numOfMemberValue == 1){username = tempStr; continue;};
            if(numOfMemberValue == 2){password = tempStr; continue;};
            if(numOfMemberValue == 3){fullname = tempStr; continue;};
            if(numOfMemberValue == 4){
                phoneNumber = tempStr;
                Member *member = new Member(username, password, fullname, phoneNumber);
                this->members.push_back(member);
                numOfMemberValue = 0;
                continue;
            };
        }else if (className == "House"){
            numOfHouseValue++;
            if(numOfHouseValue == 1){houseOwner = tempStr; continue;};
            if(numOfHouseValue == 2){
                //Save locations to system for later use of showing members houses based on locations
                location = tempStr;
                if(this->locations.size() == 0){
                    this->locations.push_back(location);
                }
                bool locationAlreadySaved = false;       //Save decision is based on this variable
                for(std::string eachLocation : this->locations){ //With each location, we'll loop through the locations list, and compare
                    if(location == eachLocation){   // If location is found, no save
                        locationAlreadySaved = true;
                        break;
                    }else{
                        continue;  //Else, go to the next location of the locations list to check
                    }
                }
                if(locationAlreadySaved == false){ //At the end of the loop, if no location is found being similar, save
                    this->locations.push_back(location);
                }
            };
            if(numOfHouseValue == 3){
                //std::cout << "fasdfasd";
                description = tempStr;
                House *house = new House(houseOwner, location, description);
                this->houses.push_back(house);
                numOfHouseValue = 0;
                continue;
            };
        }
    }
    myFile.close();
}

void System::saveData(){
    std::cout << "Saving Data...." << std::endl;

    //std::ifstream myFile;
    std::ofstream newFile;
    //myFile.open("data.txt", std::ios::in);
    newFile.open("data.txt", std::ios::out);

    std::vector<Member*> members;
    std::vector<House*> houses;

    members = this->members;
    houses = this->houses;
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

void System::mainMenu(){
    //Show Options
    std::cout << "\nUse the app as: 1. Guest, 2. Member, 3. Admin\n";
    std::cout << "0. EXIT\n";
    std::cout << "\nEnter your choice: ";
    bool loop = 1;
    int choice;
    getInput(choice);
    while(loop) {
        switch(choice){
        case 1:
            //Guest Options Menu
            this->guestMenu();
            loop = 0;
            break;
        case 2:
            //Member Options Menu
            this->isLoggedInVar = false;
            std::cin.ignore();
            this->memberMenu();
            loop = 0;
            break;
        case 3:
            //Admin Options Menu
            std::cout << "Admin option";
            loop = 0;
            break;
        case 0:
            //Close App
            std::cout << "THANK YOU FOR USING OUR PROGRAM";
            this->saveData();
            exit(0);
        default:
            std::cout << "Invalid Choice. Enter again: ";
            getInput(choice);
        }
    }
}

void System::guestMenu(){
    system("cls");
    std::cout << "***** GUEST MENU *****\n\n";
    std::cout << "1. Register\n";
    std::cout << "2. View Houses\n";
    std::cout << "0. Return to Main menu\n";
    std::cout << "\nEnter your choice: ";
    
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
            std::cin.ignore();

            //Get info from user
            std::cout << "Enter your full name: ";
            std::getline(std::cin, fullname);
            std::cout << "Enter your phone Number: ";
            std::getline(std::cin, phoneNo);
            loginInput(&username, &password);

            //Convert username to lowercase
            username = toLowercase(username);
            username = "\n" + username;

            //Save info to newMember instance
            newMember->setUserName(username);
            newMember->setPassword(password);
            newMember->setName(fullname);
            newMember->setphoneNo(phoneNo);

            this->members.push_back(newMember);
            //std::cout << appSystem.members.size();
            //newMember->showInfo();


            // //Save info to file
            // str = username + ", " + password + ", " + fullname + ", " + phoneNo;
            // myFile.open("member.txt", std::ios::app);
            // if(myFile.is_open()){
            //     myFile << "\n" << str;
            //     myFile.close();
            // }

            std::cout << "\nRegister Succesfully!!!\n";
            std::cout << "Press Enter to return to main menu....";
            this->isLoggedInVar = true;
            std::cin.ignore();
            system("cls");
            std::cin.ignore();
            this->memberMenu();
            loop = 0;
            break;
        case 2:
            //View House Menu
            this->showHousesGuest();
            loop = 0;
            break;
        case 0:
            //Return to Main menu
            system("cls");
            this->mainMenu();
            loop = 0;
            break;
        default:
            std::cout << "Invalid Choice. Enter again: ";
            getInput(choice);
        }
    }
}

void System::memberMenu(){
    //Declare pointer for username and password
    string username, password;
  
    system("cls");

    bool loop = 1;
    while(loop) {
        if(this->isLoggedInVar == true){
            loop = 0;
            break;
        }
        loginInput(&username, &password);
        if(this->isLoggedIn(username, password) == false) {
            std::cout << "Wrong password or username!!!\n";
            std::cout << "Return to main menu? (Y/N): ";
            char choice;
            switch(getInput(choice)){
                case 'Y': case 'y':
                    this->mainMenu();
                    loop = 0;
                    break;
                case 'N': case 'n':
                    std::cin.ignore();
                    break;
                default:
                    std::cout << "Invalid Choice. Enter again: ";
                    getInput(choice);
            }
        }
        else {
            this->isLoggedInVar = true;
            break;
        }
    }

    Member* member = this->members.back();
  
    //system("cls");
    std::cout << "\n***** MEMBER MENU *****\n\n";
    std::cout << "1. View Information\n";
    std::cout << "2. Add House\n";
    std::cout << "3. List/Unlist House\n";
    std::cout << "4. Search Houses\n";
    std::cout << "5. Request House\n";
    std::cout << "6. View Requests\n";
    std::cout << "7. Rating\n";
    std::cout << "0. Return to Main menu\n";
    std::cout << "\nEnter your choice: ";
    
    int choice;
    switch(getInput(choice)){
    case 1:
        member->showInfo();
        std::cout << "Press Enter to return to main menu....";
        std::cin.ignore();
        std::cin.ignore();
        system("cls");
        this->memberMenu();
        break;
    case 2: //Add Houses
        break;
    case 3: //List/Unlist Houses
        break;
    case 4:
        system("cls");
        this->showHousesMember();
        std::cout << "Press Enter to return to main menu....";
        std::cin.ignore();
        std::cin.ignore();
        system("cls");
        this->memberMenu();
        break;
    case 5: //Request
        break;
    case 6: //View requests
        break;
    case 7: //Rating
        break;
    case 0:
        system("cls");
        this->mainMenu();
        break;
    default:
        std::cout << "Wrong Input\n";
        std::cout << "Press ENTER to Continue....\n";
        std::cin.ignore();
        std::cin.ignore();
        this->mainMenu();
    }
}

void System::loginInput(std::string *u, std::string *p){
    while(1) {
        std::cout << "Enter username: ";
        std::getline(std::cin, *u);
        if(u->length() > 0) {
            break;
        }
        std::cout << "No Username entered!!!\n";
    }
    while(1) {
        std::cout << "Enter password: ";
        std::getline(std::cin, *p);
        if(p->length() > MAXPASSLENGTH) {
            std::cout << "Your password is too long\n";
        }
        else if(p->length() == 0) {
            std::cout << "\nNo Password entered!!!\n";
        }
        else {
            break;
        }
    }
}

bool System::isLoggedIn(std::string username, std::string password){
    std::string u, p; //Correct username and password

    //Convert username to lowercase
    username = toLowercase(username);

    //Validation
    for(int i = 0; i < this->members.size(); i++) {
        u = this->members[i]->getUsername();
        p = this->members[i]->getPassword();
        if(username.compare(u) == 0 && password.compare(p) == 0) {
            return true;
        } 
        else {
            return false;
        }
    }
}

std::string System::toLowercase(std::string str){
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

void System::showHousesGuest(){
    std::cout << "All houses information:\n";
    for(House *eachHouse : this->houses){
        std::cout << "-------------------------------------\n";
        std::cout << "Location: " << eachHouse->location << ", Owner:" << eachHouse->owner << "\n"
        << "Description: " << eachHouse->description << "\n";
    }
}

void System::showHousesMember(){
    //This assumes that our app only supports Hanoi, Dalat, and Danang cities
    std::cout << "Suitable houses for you: \n";
    int order = 1;
    for(std::string eachLocation : this->locations){
        std::cout << eachLocation << std::endl;
        for(int i = 0; i < this->houses.size(); i++){
            if(eachLocation == this->houses[i]->location){
                std::cout << order << ". ";
                this->houses[i]->showInfo();
                order++;
            }
        }
        std::cout << std::endl;
    };
}