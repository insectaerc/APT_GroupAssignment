#include "System.h"

//Constructor
System::System(){this->isLoggedInVar = false;}

//Functions
void System::loadData(){
    //Fstream object to read file
    std::fstream myFile;
    myFile.open("data.txt", std::ios::in);
    std::string tempStr;

    //Variables
    std::string className;  // -> To detemine which class that the data in the file belongs to

    //Variables for storing data belong to Members
    std::string username, password, fullname, phoneNumber;
    int creditPoints, memRating;
    //Variables for storing data belong to Houses
    std::string houseOwner, location, description;
    int houseRating, reqCrePoints, reqRating;
    bool availability;
    //Variables for storing data belong to Requests
    std::string ownerUsername, occupierUsername, requestStatus;
    //Variables to manage the number of attributes of each object
    int numOfMemberValue = 0;
    int numOfHouseValue = 0;
    int numOfRequestValue = 0;

    while(getline(myFile, tempStr, '|')){
        //Remove new line character \n from tempStr
        tempStr.erase(remove(tempStr.begin(), tempStr.end(), '\n'), tempStr.end());

        if(tempStr == "Member"){
            className = "Member";
            continue;
        }else if (tempStr == "House"){
            className = "House";
            continue;
        }else if (tempStr == "Request"){
            className = "Request";
            continue;
        }
        
        if(className == "Member"){
            numOfMemberValue++;
            if(numOfMemberValue == 1){username = tempStr; continue;};
            if(numOfMemberValue == 2){password = tempStr; continue;};
            if(numOfMemberValue == 3){fullname = tempStr; continue;};
            if(numOfMemberValue == 4){phoneNumber = tempStr; continue;};
            if(numOfMemberValue == 5){creditPoints = std::stoi(tempStr); continue;};
            if(numOfMemberValue == 6){
                memRating = std::stoi(tempStr);
                Member *member = new Member(username, password, fullname, phoneNumber, creditPoints, memRating);
                this->members.push_back(member);
                numOfMemberValue = 0;
                continue;
            };
            
        }else if (className == "House"){
            numOfHouseValue++;
            if(numOfHouseValue == 1) {houseOwner = tempStr; continue;};
            if(numOfHouseValue == 2) {location = tempStr; continue;};
            if(numOfHouseValue == 3) {description = tempStr; continue;};
            if(numOfHouseValue == 4) {availability = strto_bool(tempStr); continue;};
            if(numOfHouseValue == 5) {reqCrePoints = std::stoi(tempStr); continue;};
            if(numOfHouseValue == 6) {reqRating = std::stoi(tempStr); continue;};
            if(numOfHouseValue == 7){
                houseRating = std::stoi(tempStr); 
                House *house = new House(houseOwner, location, description, availability, reqCrePoints, reqRating, houseRating);
                this->houses.push_back(house);
                numOfHouseValue = 0;
                continue;
            };

        }else if(className == "Request"){
            numOfRequestValue++;
            if(numOfRequestValue == 1) {ownerUsername = tempStr; continue;};
            if(numOfRequestValue == 2) {occupierUsername = tempStr; continue;};
            if(numOfRequestValue == 3) {
                requestStatus = tempStr;
                Request *request = new Request(ownerUsername, occupierUsername, requestStatus);
                this->requests.push_back(request);
                numOfRequestValue = 0;
                continue;
            };
        }
    }

    //Load houses to myHouse
    for(int i = 0; i < this->members.size(); i++) {
        for(int j = 0; j < this->houses.size(); j++) {
            if(this->members[i]->getUsername().compare(this->houses[j]->owner) == 0) {
                this->members[i]->setMyHouse(this->houses[j]);
            }
        }
    }
    myFile.close();
}

void System::saveData(){
    std::cout << "Saving Data...." << std::endl;

    //ofstream object to read file
    std::ofstream newFile;
    newFile.open("data.txt", std::ios::out);

    std::vector<Member*> members;
    std::vector<House*> houses;
    members = this->members;
    houses = this->houses;
    std::string tmp;
    
    //Save data of Members
    newFile << "Member|";
    for(int i = 0; i < members.size(); i++) {
        tmp = "\n" + members[i]->getUsername();
        newFile << tmp << "|" << members[i]->getPassword() << "|";
        newFile << members[i]->getName() << "|" << members[i]->getphoneNo() << "|";
        newFile << members[i]->getCreditPts() << "|" << members[i]->getRating() << "|";
    }
    //Save data of Houses
    newFile << "\nHouse|";
    for(int i = 0; i < houses.size(); i++) {
        tmp = "\n" + houses[i]->owner;
        newFile << tmp << "|" << houses[i]->location << "|";
        newFile << houses[i]->description << "|" << boolto_str(houses[i]->getAvailability()) << "|";
        newFile << houses[i]->requiredCreditPoints << "|" << houses[i]->requiredRating << "|";
        newFile << houses[i]->getRating() << "|";
    }
    //Save data of Requests
    newFile << "\nRequest|";
    for(int i = 0; i < this->requests.size(); i++) {
        newFile <<  "\n" + this->requests[i]->getOwnerUsername() << "|" 
                << this->requests[i]->getOccupierUsername() << "|"
                << this->requests[i]->getStatus() << "|";
    }
    
    newFile.close();
}

void System::mainMenu(){

    this->houses[0]->setAvailability(1);

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
            std::cin.ignore();
            this->adminMenu();
            loop = 0;
            break;
        case 0:
            //Close App
            this->saveData();
            std::cout << "THANK YOU FOR USING OUR PROGRAM";
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
    string username, password, fullname, phoneNo, tmp;

    int choice;
    getInput(choice);
    bool loop = 1;
    while(loop) {
        switch(choice){
        case 1: //Register Menu
            std::cin.ignore();
            system("cls");
            //Get info from user
            std::cout << "Enter your full name: ";
            std::getline(std::cin, fullname);
            std::cout << "Enter your phone Number: ";
            std::getline(std::cin, phoneNo);
            loginInput(&username, &password);

            //Convert username to lowercase
            username = toLowercase(username);

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
            std::cout << "Press Enter to go to member menu....";
            this->isLoggedInVar = true;
            for(int i = 0; i < this->members.size(); i++) {
                tmp = this->members[i]->getUsername();
                if(tmp.compare(username) == 0) {
                    this->loggedInMember = members[i];
                }
            }
            std::cin.ignore();
            system("cls");
            this->memberMenu();
            loop = 0;
            break;
        case 2:
            //View House Menu
            system("cls");
            this->showHousesGuest();
            std::cout << "Press Enter to return to main menu....";
            std::cin.ignore();
            this->mainMenu();
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
    std::string username, password;
  
    system("cls");

    bool loop = 1;
    bool loop2 = 1;
    while(loop) {
        if(this->isLoggedInVar == true){
            loop = 0;
            break;
        }
        loginInput(&username, &password);
        if(this->isLoggedIn(username, password) == false) {
            std::cout << "Wrong password or username!!!\n";
            std::cout << "Return to Main Menu? (Y/N): ";
            char choice;
            loop2 = 1;
            getInput(choice);
            while(loop2) {
                switch(choice){
                    case 'Y': case 'y':
                        this->mainMenu();
                        break;
                    case 'N': case 'n':
                        std::cin.ignore();
                        loop2 = 0;
                        break;
                    default:
                        std::cout << "\nInvalid Choice. Enter again: ";
                        getInput(choice);
                }
            }
        }
        else {
            this->isLoggedInVar = true;
            std::string tmp;
            for(int i = 0; i < this->members.size(); i++) {
                tmp = this->members[i]->getUsername();
                if(tmp.compare(username) == 0) {
                    this->loggedInMember = members[i];
                }
            }
            //Load requests to logged-in Member object
            for(Request *eachReq : this->requests){
                if(eachReq->getOwnerUsername() == this->loggedInMember->getUsername()){
                    this->loggedInMember->getMyRequest().push_back(eachReq);
                }
            }
            break;
        }
    }

    //Member* member = this->members.back();
  
    //system("cls");
    std::cout << "\n***** MEMBER MENU *****\n\n";
    std::cout << "1. View Information\n";
    std::cout << "2. Add House\n";
    std::cout << "3. List/Unlist House\n";
    std::cout << "4. Search Houses\n";
    std::cout << "5. View Requests\n";
    std::cout << "6. Rating\n";
    std::cout << "0. Log Out\n";
    std::cout << "\nEnter your choice: ";
    
    int choice;
    int list_option;
    while(1) {
        switch(getInput(choice)){
        case 1:
            system("cls");
            this->loggedInMember->showInfo();
            std::cout << std::endl << std::endl;
            this->toMemberMenu();
            break;
        case 2: //Add Houses
            std::cin.ignore();
            this->loggedInMember->addHouse(this->houses, this->loggedInMember->getUsername());
            this->toMemberMenu();
            break;
        case 3: //List/Unlist Houses
            std::cout << "1. List house" << std::endl;
            std::cout << "2. Unlist house" << std::endl;
            std::cout << "0. Return to Member menu" << std::endl;
            std::cout << "\nEnter your choice: ";

            switch(getInput(list_option)) {
            case 1: //List Function
                loggedInMember->list(loggedInMember->getMyHouse());
                this->toMemberMenu();
                break;
            case 2: //Unlist Function
                loggedInMember->unlist(loggedInMember->getMyHouse());
                this->toMemberMenu();
                break;
            case 0: //Return to member menu
                system("cls");
                this->memberMenu();
                break;
            default:
                std::cout << "Invalid Choice. Enter again: ";
                getInput(choice);
            }
        case 4: //Show houses to member based on cities
            system("cls");
            this->showHousesMember();
            break;
        case 5: //View requests
            if(this->loggedInMember->viewRequests() == false){
                std::cout << "\n\nPress Enter to return to main menu.";
                std::cin.ignore();
                std::cin.ignore();
                system("cls");
                this->memberMenu();
            }else{
                int requestChoice;
                std::cout << "\nSelect the request that you wish to accept, if you want go back to main menu please enter 0: ";
                getInput(requestChoice);
                if(requestChoice == 0){
                    this->memberMenu();
                }else{
                    //this->loggedInMember->requestOccupy(availableHouses, occupyChoice, this->requests);
                    this->loggedInMember->acceptRequest(requestChoice);
                    std::cout << "Press Enter to return to main menu.";
                    std::cin.ignore();
                    std::cin.ignore();
                    this->memberMenu();
                }
            }
            break;
        case 6: //Rating
            break;
        case 0:
            system("cls");
            this->mainMenu();
            break;
        default:
            std::cout << "Invalid Choice. Enter again: ";
            getInput(choice);
        }
    }
}

void System::adminMenu() {
    system("cls");

    string username, password;
    int choice;

    bool loop = 1;
    while(loop) {
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
        } else {
            break;
        }
    }

    std::cout << "***** ADMIN MENU *****\n\n";
    std::cout << "1. View Members\n";
    std::cout << "2. View Houses\n";
    std::cout << "0. Return to Main menu\n";
    std::cout << "\nEnter your choice: ";

    getInput(choice);
    while(1) {
        switch(choice){
        case 1: //View Members information
            this->showMembersAdmin();
            break;
        case 2: //View Houses information
            this->showHousesAdmin();
            break;
        case 0:
            system("cls");
            this->mainMenu();
            break;
        default:
            std::cout << "Invalid Choice. Enter again: ";
            getInput(choice);
        }
    }
}

void System::loginInput(std::string *u, std::string *p){
    std::cout << "--------------LOGIN--------------\n";
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
            std::cout << "Logged In Successfully!\n";
            return true;
        } 
        else {
            continue;
        }
    }
    return false;
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
    int city_option;
    int choice;
    bool loop = true;
    std::cout << "The application only supports the below cities for now:\n";
    std::cout << "1. Hanoi" << std::endl;
    std::cout << "2. Saigon" << std::endl;
    std::cout << "3. Da Nang" << std::endl;
    std::cout << "0. Return to main menu" << std::endl << std::endl;
    std::cout << "\nYour option: ";
    while(loop){
        switch (getInput(city_option)){
            case 1:{
                std::vector<House*> availableHouses;
                if(this->loggedInMember->searchHouses("Hanoi", this->houses, availableHouses) == false){
                    std::cout << "\n";
                    std::cout << "So sorry, there is no house that is suitable for you right now.\n";
                    std::cout << "Press Enter to return and select another city.";
                    std::cin.ignore();
                    std::cin.ignore();
                    system("cls");
                    this->showHousesMember();
                }else{
                    int occupyChoice;
                    std::cout << "\nSelect the house that you wish to occupy, if you want go back to main menu please enter 0: ";
                    getInput(occupyChoice);
                    if(occupyChoice == 0){
                        this->memberMenu();
                    }else{
                        this->loggedInMember->requestOccupy(availableHouses, occupyChoice, this->requests);
                        std::cout << "Press Enter to return to main menu.";
                        std::cin.ignore();
                        std::cin.ignore();
                        this->memberMenu();
                    }
                }}
                break;
            case 2:
                {
                std::vector<House*> availableHouses;
                if(this->loggedInMember->searchHouses("Saigon", this->houses, availableHouses) == false){
                    std::cout << "\n";
                    std::cout << "So sorry, there is no house that is suitable for you right now.\n";
                    std::cout << "Press Enter to return and select another city.";
                    std::cin.ignore();
                    std::cin.ignore();
                    system("cls");
                    this->showHousesMember();
                }else{
                    int occupyChoice;
                    std::cout << "\nSelect the house that you wish to occupy, if you want go back to main menu please enter 0: ";
                    getInput(occupyChoice);
                    if(occupyChoice == 0){
                        this->memberMenu();
                    }else{
                        this->loggedInMember->requestOccupy(availableHouses, occupyChoice, this->requests);
                        std::cout << "Press Enter to return to main menu.";
                        std::cin.ignore();
                        std::cin.ignore();
                        this->memberMenu();
                    }
                }}
                break;
            case 3:
                {
                std::vector<House*> availableHouses;
                if(this->loggedInMember->searchHouses("Da Nang", this->houses, availableHouses) == false){
                    std::cout << "\n";
                    std::cout << "So sorry, there is no house that is suitable for you right now.\n";
                    std::cout << "Press Enter to return and select another city.";
                    std::cin.ignore();
                    std::cin.ignore();
                    system("cls");
                    this->showHousesMember();
                }else{
                    int occupyChoice;
                    std::cout << "\nSelect the house that you wish to occupy, if you want go back to main menu please enter 0: ";
                    getInput(occupyChoice);
                    if(occupyChoice == 0){
                        this->memberMenu();
                    }else{
                        this->loggedInMember->requestOccupy(availableHouses, occupyChoice, this->requests);
                        std::cout << "Press Enter to return to main menu.";
                        std::cin.ignore();
                        std::cin.ignore();
                        this->memberMenu();
                    }
                }}
                break;
            case 0:
                system("cls");
                this->memberMenu();
                break;
            default:
                std::cout << "Invalid Choice. Enter again: ";
                getInput(city_option);
                break;
        }
    }
}

void System::showMembersAdmin(){
    std::cout << "\n\nMembers Information:\n";
    for (Member *eachMember : this->members) {
        std::cout << "\nUsername: " << eachMember->getUsername()
                  << "\nFullname: " << eachMember->getName()
                  << "\nPhone number: " << eachMember->getphoneNo()
                  << "\nRating: " << eachMember->getRating()
                  << "\nCredit point: " << eachMember->getCreditPts() << "\n";
                  //<< "\n House location: " << eachMember->myHouse->location
                  //<< "\n House description: " << eachMember->myHouse->description << "\n";
    }
}

void System::showHousesAdmin(){
    std::cout << "\n\nHouses Information:\n";
    for (House *eachHouse : houses) {
        std::cout << "\nLocation: " << eachHouse->location
                  << "\nDescription: " << eachHouse->description
                  //<< "\n Rating: " << house->rating
                  << "\nOwner: " << eachHouse->owner << "\n";
                  //<< "\n Review: " << house->review
                  //<< "\n Availability: " << house->availability << "\n";
    }
}

bool System::strto_bool(std::string str){
    if(str.compare("0") == 0) {
        return false;
    }
    return true;
}

std::string System::boolto_str(bool boolean){
    if(boolean == 0) {
        return "0";
    }
    return "1";
}

void System::toMemberMenu() {
    std::cout << "Press Enter to return to member menu....";
    std::cin.ignore();
    std::cin.ignore();
    system("cls");
    this->memberMenu();
}