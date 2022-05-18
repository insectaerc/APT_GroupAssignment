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
