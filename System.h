#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "Member.h"
#include "House.h"
#include "Request.h"
#include "Input.h"
#include "Review.h"

//DEFINE
#define MAXPASSLENGTH 20

class System{
    public:
        //Attributes
        bool isLoggedInVar;                 //This is for checking if the user has been logged in successfulyy
        Member *loggedInMember;
        //Vectors of objects to store related data
        std::vector<Member*> members;       
        std::vector<House*> houses;
        std::vector<Request*> requests;
        std::vector<Review*> reviews;

        //Constructor
        System();

        //Functions
        void loadData();    //Called when program starts
        void saveData();    //Called when program closes
        void mainMenu();
        void guestMenu();
        void memberMenu();
        void adminMenu();
        void loginInput(std::string *u, std::string *p);
        bool isLoggedIn(std::string username, std::string password);
        bool isLoggedInAdmin(std::string username, std::string password);
        void showHousesGuest();
        void showHousesMember();
        void showHousesInCity(std::string city);
        void showMembersAdmin();
        void showHousesAdmin();

        //Navigate function
        void toGuestMenu();
        void toMemberMenu();
        
        //Functions to convert strings
        std::string toLowercase(std::string str);
        bool strto_bool(std::string str);
        std::string boolto_str(bool boolean);
};