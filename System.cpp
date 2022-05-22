#include "System.h"

//Constructor
System::System(){
    this->isLoggedInVar = false; //This is for checking if the user has been logged in successfulyy
}

//Functions
void System::loadData(){        //Called when program starts
    //Fstream object to read file
    std::fstream myFile;
    myFile.open("data.txt", std::ios::in);
    std::string tempStr;

    //Variables
    std::string className;  // -> To detemine which class that the data in the file belongs to

    //Variables for storing data belong to Members
    std::string username, password, fullname, phoneNumber, memReview;
    int creditPoints, memRating, numOfOccupyingHouse;
    //Variables for storing data belong to Houses
    std::string houseOwner, location, description, houseReview, houseOccupierUsername;
    int houseRating, reqCrePoints, reqRating, numOfOccupier;
    bool availability;
    //Variables for storing data belong to Requests
    std::string ownerUsername, occupierUsername, requestStatus;
    //Variables for storing data belong to Reviews
    std::string reviewType, reviewReceiverUsername, reviewWriterUsername, reviewContent;
    //Variables to manage the number of attributes of each object
    int numOfMemberValue = 0;
    int numOfHouseValue = 0;
    int numOfRequestValue = 0;
    int numOfReviewValue = 0;

    while(getline(myFile, tempStr, '|')){
        //Remove new line character \n from tempStr
        tempStr.erase(remove(tempStr.begin(), tempStr.end(), '\n'), tempStr.end());

        //className works as an indicator to inform the program which block of data belongs to which class
        if(tempStr == "Member"){
            className = "Member";
            continue;
        }else if (tempStr == "House"){
            className = "House";
            continue;
        }else if (tempStr == "Request"){
            className = "Request";
            continue;
        }else if (tempStr == "Review"){
            className = "Review";
            continue;
        }
        
        if(className == "Member"){
            numOfMemberValue++;
            if(numOfMemberValue == 1) {username = tempStr; continue;};
            if(numOfMemberValue == 2) {password = tempStr; continue;};
            if(numOfMemberValue == 3) {fullname = tempStr; continue;};
            if(numOfMemberValue == 4) {phoneNumber = tempStr; continue;};
            if(numOfMemberValue == 5) {creditPoints = std::stoi(tempStr); continue;};
            if(numOfMemberValue == 6) {memRating = std::stoi(tempStr); continue;};
            if(numOfMemberValue == 7) {
                numOfOccupyingHouse = std::stoi(tempStr);
                Member *member = new Member(username, password, fullname, phoneNumber, creditPoints, memRating, numOfOccupyingHouse);
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
            if(numOfHouseValue == 7) {houseRating = std::stoi(tempStr);  continue;};
            if(numOfHouseValue == 8) {houseReview = tempStr; continue;}
            if(numOfHouseValue == 9) {numOfOccupier = std::stoi(tempStr); continue;};
            if(numOfHouseValue == 10){
                houseOccupierUsername = tempStr;
                House *house = new House(houseOwner, location, description, availability, reqCrePoints, reqRating, houseRating, houseReview, numOfOccupier, houseOccupierUsername);
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
        }else if(className == "Review"){
            numOfReviewValue++;
            if(numOfReviewValue == 1){reviewType = tempStr; continue;}
            if(numOfReviewValue == 2){reviewReceiverUsername = tempStr; continue;}
            if(numOfReviewValue == 3){reviewWriterUsername = tempStr; continue;}
            if(numOfReviewValue == 4){
                reviewContent = tempStr;
                Review *review = new Review(reviewType, reviewReceiverUsername, reviewWriterUsername, reviewContent);
                this->reviews.push_back(review);
                numOfReviewValue = 0;
                continue;
            }
        }
    }
    std::cout << "\nData loaded Successfully.\n";
    myFile.close();
}

void System::saveData(){        //Called when program closes
    std::cout << "Saving Data...." << std::endl;

    //ofstream object to read file
    std::ofstream newFile;
    newFile.open("data.txt", std::ios::out);
    
    //Save data of Members
    newFile << "Member|";
    for(int i = 0; i < this->members.size(); i++) {
        newFile << "\n" + this->members[i]->getUsername() << "|" 
                << this->members[i]->getPassword() << "|"
                << this->members[i]->getName() << "|"
                << this->members[i]->getphoneNo() << "|"
                << this->members[i]->getCreditPts() << "|"
                << this->members[i]->getRating() << "|"
                << this->members[i]->getNumOfOccupyHouse() << "|";
    }

    //Save data of Houses
    newFile << "\nHouse|";
    for(int i = 0; i < this->houses.size(); i++) {
        newFile << "\n" + this->houses[i]->owner<< "|"
                << this->houses[i]->location << "|"
                << this->houses[i]->description << "|"
                << boolto_str(this->houses[i]->getAvailability()) << "|"
                << this->houses[i]->requiredCreditPoints << "|"
                << this->houses[i]->requiredRating << "|"
                << this->houses[i]->getRating() << "|"
                << this->houses[i]->getReview() << "|"
                << this->houses[i]->getNumOfOccupier() << "|"
                << this->houses[i]->getOccupierUsername() << "|";
    }

    //Save data of Requests
    newFile << "\nRequest|";
    for(int i = 0; i < this->requests.size(); i++) {
        newFile << "\n" + this->requests[i]->getOwnerUsername() << "|" 
                << this->requests[i]->getOccupierUsername() << "|"
                << this->requests[i]->getStatus() << "|";
    }
    
    //Save data of Reviews
    newFile << "\nReview|";
    for(int i = 0; i < this->reviews.size(); i++){
        newFile << "\n" + this->reviews[i]->getType() << "|"
                << this->reviews[i]->getReceiverUsername() << "|"
                << this->reviews[i]->getWriterUsername() << "|"
                << this->reviews[i]->getContent() << "|";
    }
    newFile.close();
    std::cout << "Data saved successfully.";
}

void System::mainMenu(){        //Display main menu's options for user to select
                                //Corresponding function will be called based on the input
    //Show Options
    std::cout << "\nUse the app as:\n1. Guest\n2. Member\n3. Admin\n0. EXIT";
    std::cout << "\nEnter your choice: ";
    bool loop = 1;
    int choice;
    while(1) {
        switch(getInput(choice)){
        case 1:
            //Guest Options Menu
            this->guestMenu();
            break;
        case 2:
            //Member Options Menu
            this->isLoggedInVar = false;
            std::cin.ignore();
            this->memberMenu();
            break;
        case 3:
            //Admin Options Menu
            std::cin.ignore();
            this->adminMenu();
            break;
        case 0:
            //Close App
            this->saveData();
            std::cout << "\nTHANK YOU FOR USING OUR PROGRAM.";
            exit(0);
        default:
            std::cout << "Invalid Choice. Enter again: ";
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
    
    //Create a Member instance and it will be used if the user registers
    Member *newMember = new Member();
    std::string username, password, fullname, phoneNo, tmp;

    int choice;
    bool loop;
    while(1) {
        switch(getInput(choice)){
        case 1:     //Display registration steps and registered data
            std::cin.ignore();
            system("cls");
            //Get info from user
            std::cout << "********** REGISTER **********\n";
            std::cout << "\nEnter your full name: ";
            std::getline(std::cin, fullname);
            std::cout << "Enter your phone Number: ";
            std::getline(std::cin, phoneNo);
            loop = 1;
            while(loop) {
                loginInput(&username, &password);
                for(int i = 0; i < members.size(); i++) {
                    if(username.compare(members[i]->getUsername()) == 0) {
                        std::cout << "Username already existed!!!\n";
                        loop = 1;
                        break;
                    }
                    else {
                        loop = 0;
                    }
                }
            }

            //Convert username to lowercase
            username = toLowercase(username);

            //Save info to newMember instance
            newMember->setUserName(username);
            newMember->setPassword(password);
            newMember->setName(fullname);
            newMember->setphoneNo(phoneNo);

            //Push the newMember instance to System::members vector
            this->members.push_back(newMember);
            this->isLoggedInVar = true;

            //Once the user register successfully
            //He/she will be directed to the member's menu without loggin step
            //So we need to update the System::loggedInMember object
            for(int i = 0; i < this->members.size(); i++) {
                tmp = this->members[i]->getUsername();
                if(tmp.compare(username) == 0) {
                    this->loggedInMember = members[i];
                    this->loggedInMember->setNumOfHouse(0);
                }
            }
            std::cout << "\nRegister Succesfully!!!\n";
            this->toMemberMenu();
            break;
        case 2:     //View House Menu
            system("cls");
            this->showHousesGuest();
            std::cin.ignore();
            this->toGuestMenu();
            break;
        case 0:     //Return to Main menu
            system("cls");
            this->mainMenu();
            break;
        default:
            std::cout << "Invalid Choice. Enter again: ";
        }
    }
}

void System::memberMenu(){
    //Theses 2 variables are used for loggin steps
    std::string username, password;
  
    system("cls");
    
    bool loop = 1;  //This loop helps to keep asking user for correct username&password if they are not correct
                    //and user does not want to go back to main menu
    bool loop2 = 1; //When user enters incorrect username/password, program will ask user if he/she want to go back to 
                    //main menu by entering Y/N/y/n. This loop prevents user from entering different inputs.
    while(loop) {
        //First check if the user has already logged in successfuly
        //If true, programs will not ask user to re-enter the username and password & display the menu for member instead
        if(this->isLoggedInVar == true){
            loop = 0;
            break;
        }
        //Else, ask user to log in
        std::cout << "********** LOGIN **********\n";
        loginInput(&username, &password);   //Prevent user enters nothing or too long password
        if(this->isLoggedIn(username, password) == false) {
            std::cout << "Wrong password or username!!!\n";
            std::cout << "Return to Main Menu? (Y/N): ";
            char choice;
            loop2 = 1;
            while(loop2) {
                switch(getInput(choice)){
                    case 'Y': case 'y':
                        this->mainMenu();
                        break;
                    case 'N': case 'n':
                        std::cin.ignore();
                        loop2 = 0;
                        break;
                    default:
                        std::cout << "\nInvalid Choice. Enter again: ";
                }
            }
        }else{
            //If validated, load data to neccessary attibutes that will be used later
            //Update System::isLoggedInVar varibale
            this->isLoggedInVar = true;
            //Load data into System::loggedInMember object
            std::string tempStr;
            for(int i = 0; i < this->members.size(); i++) {
                tempStr = this->members[i]->getUsername();
                if(tempStr.compare(username) == 0) {
                    this->loggedInMember = members[i];
                }
            }
            //Load data into System::loggedInMember->requests
            for(Request *eachReq : this->requests){
                if(eachReq->getOwnerUsername() == this->loggedInMember->getUsername()){
                    this->loggedInMember->getMyRequest().push_back(eachReq);
                }
            }
            //Load data of myHouse objects that belong to member objects
            for(int i = 0; i < this->members.size(); i++) {
                for(int j = 0; j < this->houses.size(); j++) {
                    if(this->members[i]->getUsername().compare(this->houses[j]->owner) == 0) {
                        this->members[i]->setMyHouse(this->houses[j]);
                        this->members[i]->setNumOfHouse(1);
                    }
                }
            }

            //Load data into System::loggedInMember->occupyingHouse object
            for(int i = 0; i < this->houses.size(); i++){
                if(this->houses[i]->getOccupierUsername().compare(this->loggedInMember->getUsername()) == 0){
                    this->loggedInMember->setOccupyingHouse(this->houses[i]);
                }
            }
            //Load reviews of user
            for(int i = 0; i < this->reviews.size(); i++){
                if(this->reviews[i]->getReceiverUsername().compare(this->loggedInMember->getUsername()) == 0){
                    this->loggedInMember->getMyReview().push_back(this->reviews[i]);
                }
            }
            system("cls");
            std::cout << "\nLogged In Successfully!\n";
        }
    }

    

    //Display Member Menu
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
    int rating_option;
    int rating;
    std::string review;
    while(1) {
        switch(getInput(choice)){
        case 1:
            system("cls");
            this->loggedInMember->showInfo();
            std::cout << std::endl << std::endl;
            std::cin.ignore();
            this->toMemberMenu();
            break;
        case 2: //Add Houses
            system("cls");
            std::cin.ignore();
            this->loggedInMember->addHouse(this->houses, this->loggedInMember->getUsername());
            this->loggedInMember->setMyHouse(houses.back());
            std::cin.ignore();
            this->toMemberMenu();
            break;
        case 3: //List/Unlist Houses

            if(this->loggedInMember->getNumOfHouse() == 0) {
                std::cout << "\nYou do not have a house to list/unlist. Please go back to main menu and select Add House!!!\n";
                std::cin.ignore();
                this->toMemberMenu();
            }
            else {
                this->loggedInMember->showInfo();
                this->loggedInMember->getMyHouse()->showInfo();
                std::cout << "1. List house" << std::endl;
                std::cout << "2. Unlist house" << std::endl;
                std::cout << "0. Return to Member menu" << std::endl;
                std::cout << "\nEnter your choice: ";
                getInput(list_option);
                while(1) {
                    switch(list_option) {
                    case 1: //List Function
                        this->loggedInMember->list(this->loggedInMember->getMyHouse());
                        std::cin.ignore();
                        this->toMemberMenu();
                        break;
                    case 2: //Unlist Function
                        this->loggedInMember->unlist(this->loggedInMember->getMyHouse());
                        std::cin.ignore();
                        this->toMemberMenu();
                        break;
                    case 0: //Return to member menu
                        system("cls");
                        this->memberMenu();
                        break;
                    default:
                        std::cout << "Invalid Choice. Enter again: ";
                        getInput(list_option);
                    }
                }
            }
        case 4: //Show houses to member based on cities
            system("cls");
            this->showHousesMember();
            std::cin.ignore();
            this->toMemberMenu();
            break;
        case 5: //View requests
            if(this->loggedInMember->viewRequests() == false){
                this->toMemberMenu();
            }else{
                int requestChoice;
                std::cout << "\nSelect the request that you wish to accept, if you want go back to main menu please enter 0: ";
                getInput(requestChoice);
                if(requestChoice == 0){
                    system("cls");
                    this->memberMenu();
                }else{
                    //Accept
                    //acceptRequest() updates the status of the request from "Pending" to "Accepted"
                    //and returns the name of the occupier
                    std::string occupierUsername;
                    occupierUsername = this->loggedInMember->acceptRequest(requestChoice);
                    
                    //Update infomation
                    for(int i = 0; i < this->members.size(); i++) {
                        if(occupierUsername.compare(this->members[i]->getUsername()) == 0) {
                            //Update requester's occupying house to the house of the owner (the current user)
                            this->members[i]->setOccupyingHouse(this->loggedInMember->getMyHouse());
                            //Update owner's information
                            this->loggedInMember->getMyHouse()->setOccupier(members[i]);
                            this->loggedInMember->getMyHouse()->setOccupierUsername(occupierUsername);
                        }
                    }
                    std::cin.ignore();
                    this->toMemberMenu();
                }
            }
            break;
        case 6: //Rating
            system("cls");
            std::cout << "\n***** RATING MENU *****\n";
            std::cout << "1. Rate your most recent occupied house\n";
            std::cout << "2. Rate your most recent occupier\n";
            std::cout << "0. Return to main menu\n";
            std::cout << "\nEnter your choice: ";
            Review *newReview;
            switch(getInput(rating_option)) {
                case 1: //House Rating
                if(this->loggedInMember->getNumOfOccupyHouse() == 0) {
                    std::cout << "You are not occupying any house to which you can give a review.\n";
                    std::cin.ignore();
                    this->toMemberMenu();
                }
                else {
                    std::cout << "\nEnter your rating (-10 to 10): ";
                    getInput(rating);
                    this->loggedInMember->getOcuppyingHouse()->setRating(rating);
                    std::cout << "Enter you review: ";
                    std::cin.ignore();
                    std::getline(std::cin, review);
                    this->loggedInMember->getOcuppyingHouse()->setReview(review);
                    std::cout << "\nSuccessfully rated!\n";
                    this->toMemberMenu();
                    break;
                }
                case 2: //Occupier Rating
                    std::cout << "\nEnter your rating (-10 to 10): ";
                    getInput(rating);
                    this->loggedInMember->getMyHouse()->getOccupier()->setRating(rating);
                    std::cout << "Enter you review: ";
                    std::cin.ignore();
                    std::getline(std::cin, review);
                    newReview=  new Review("occupier", this->loggedInMember->getMyHouse()->getOccupierUsername(), this->loggedInMember->getUsername(), review);
                    this->reviews.push_back(newReview);
                    std::cout << "\nSuccessfully rated!\n";
                    this->toMemberMenu();
                    break;
                case 0: //Return
                    system("cls");
                    std::cin.ignore();
                    break;
                default:
                    std::cout << "Invalid Choice. Enter again: ";
            }
            break;
        case 0:
            system("cls");
            this->isLoggedInVar = false;
            this->mainMenu();
            break;
        default:
            std::cout << "Invalid Choice. Enter again: ";
        }
    }
}

void System::adminMenu() {
    system("cls");

    std::string username, password;
    int choice;

    bool loop = 1;
    bool loop2 = 1;
    while(loop) {
        if(this->isLoggedInVar == true){
            loop = 0;
            break;
        }
        std::cout << "********** LOGIN **********\n\n";
        loginInput(&username, &password);
        if(this->isLoggedInAdmin(username, password) == false) {
            std::cout << "Wrong password or username!!!\n";
            std::cout << "Return to Main Menu? (Y/N): ";
            char choice;
            loop2 = 1;
            while(loop2) {
                switch(getInput(choice)){
                    case 'Y': case 'y':
                        this->mainMenu();
                        break;
                    case 'N': case 'n':
                        std::cin.ignore();
                        loop2 = 0;
                        break;
                    default:
                        std::cout << "\nInvalid Choice. Enter again: ";
                }
            }
        }
        else {
            this->isLoggedInVar = true;
            system("cls");
            std::cout << "Logged In Successfully!\n";
            break;
        }
    }

    std::cout << "\n***** ADMIN MENU *****\n\n";
    std::cout << "1. View Members\n";
    std::cout << "2. View Houses\n";
    std::cout << "0. Log Out\n";
    std::cout << "\nEnter your choice: ";

    while(1) {
        switch(getInput(choice)){
        case 1: //View Members information
            system("cls");
            this->showMembersAdmin();
            std::cout << "\nPress enter to return to main menu....\n";
            std::cin.ignore();
            std::cin.ignore();
            this->adminMenu();
            break;
        case 2: //View Houses information
            system("cls");
            this->showHousesAdmin();
            std::cout << "\nPress enter to return to main menu....\n";
            std::cin.ignore();
            std::cin.ignore();
            this->adminMenu();
            break;
        case 0:
            system("cls");
            this->isLoggedInVar = false;
            this->mainMenu();
            break;
        default:
            std::cout << "Invalid Choice. Enter again: ";
        }
    }
}

void System::loginInput(std::string *u, std::string *p){ //Being called in guestMenu(), memberMenu() and adminMenu()
    //Keep asking user to enter appropriate username
    while(1) {
        std::cout << "Enter username: ";
        std::getline(std::cin, *u);
        if(u->length() > 0) {
            break;
        }
        std::cout << "No Username entered!!!\n";
    }
    //Keep asking user to enter appropriate password
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

bool System::isLoggedIn(std::string username, std::string password){ //Being called in memberMenu()
    //Validate if the username and the password that user enter lie in database (text file)

    std::string fileUsername, filePassword; //Correct username and password which lie in the data

    //Convert username to lowercase
    username = toLowercase(username);

    //Validation
    for(int i = 0; i < this->members.size(); i++) {
        fileUsername = this->members[i]->getUsername();
        filePassword = this->members[i]->getPassword();
        if(username.compare(fileUsername) == 0 && password.compare(filePassword) == 0) {
            return true;
        } 
        else {
            continue;
        }
    }
    return false;
}

bool System::isLoggedInAdmin(std::string username, std::string password){ //Being called in adminMenu()
    std::string u, p; // Correct username and password for admin

    //Convert username to lowercase
    username = toLowercase(username);

    //Predefined admin username and password
    u = "admin";
    p = "admin123";

    //Validation
    if(username.compare(u) == 0 && password.compare(p) == 0) {
        return true;
    }
    else {
        return false;
  
    }
}

void System::showHousesGuest(){         //Being called in guestMenu() if user selects 2
    std::cout << "\nAll available houses:\n";
    //Loop through System::houses vectors
    int order = 0;
    for(House *eachHouse : this->houses){
        if(eachHouse->getAvailability() == 1){
            order++;
            std::cout << order << ". \n";
            std::cout   << "Location: " << eachHouse->location
                        << ", Owner:" << eachHouse->owner << "\n"
                        << "Description: " << eachHouse->description << "\n";
        }
    }
    std::cout << std::endl;
}

void System::showHousesMember() {
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
        }
    }
}

void System::showMembersAdmin(){
    std::cout << "\n\nMembers Information:\n";
    int order = 0;
    for (Member *eachMember : this->members) {
        order++;
        std::cout << order << ". "
                  << "\nUsername: " << eachMember->getUsername()
                  << "\nFullname: " << eachMember->getName()
                  << "\nPhone number: " << eachMember->getphoneNo()
                  << "\nRating: " << eachMember->getRating()
                  << "\nCredit point: " << eachMember->getCreditPts() << "\n";
    }
}

void System::showHousesAdmin(){
    std::cout << "\n\nHouses Information:\n";
    for (House *eachHouse : houses) {
        std::cout << "\nLocation: " << eachHouse->location
                  << "\nDescription: " << eachHouse->description
                  << "\nOwner: " << eachHouse->owner;
        if(eachHouse->getOccupierUsername().compare("") != 0){
            std::cout << ", being occupied by: " << eachHouse->getOccupierUsername() << "\n";
        }else{
            std::cout << "\n";
        }
    }
}



//Navigate function
void System::toMemberMenu() { 
    std::cout << "Press Enter to return to main menu....";
    std::cin.ignore();
    system("cls");
    this->memberMenu();
}
void System::toGuestMenu(){
    std::cout << "Press Enter to return to main menu....";
    std::cin.ignore();
    system("cls");
    this->guestMenu();
}

//Functions to convert strings
std::string System::toLowercase(std::string str){
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
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
