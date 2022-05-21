#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include "Member.h"
#include "House.h"
#include "Request.h"
#include "Input.h"

//DEFINE
#define MAXPASSLENGTH 20

class System{
    public:
        //Attributes
        bool isLoggedInVar;
        Member *loggedInMember;
        std::vector<Member*> members;
        std::vector<House*> houses;
        std::vector<Request*> requests;

        //Constructor
        System();

        //Functions
        void loadData();
        void saveData();
        void mainMenu();
        void guestMenu();
        void memberMenu();
        void adminMenu();
        void loginInput(std::string *u, std::string *p);
        bool isLoggedIn(std::string username, std::string password);
        bool isLoggedInAdmin(std::string username, std::string password);
        std::string toLowercase(std::string str);
        void showHousesGuest();
        void showHousesMember();
        void showHousesInCity(std::string city);
        void showMembersAdmin();
        void showHousesAdmin();
        bool strto_bool(std::string str);
        std::string boolto_str(bool boolean);
        void toMemberMenu();
};