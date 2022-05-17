#pragma once

//https://www.youtube.com/watch?v=HzmXgSnCPo4

#include <iostream>
#include <string>
#include <limits>

template<typename T>
T getInput(T& input) {
    std::cin >> input;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Invalid Input. Enter again: ";
        std::cin >> input;
    }
    return input;
}