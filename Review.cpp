#include <iostream>
#include "Review.h"


//Constructors

//This constructor is called in System::loadData()
Review::Review(std::string type, std::string receiverUsername, std::string writerUsername, std::string content){
    this->type = type;
    this->receiverUsername = receiverUsername;
    this->writerUsername = writerUsername;
    this->content = content;
}


//Getters
std::string Review::getType(){
    return this->type;
};
std::string Review::getReceiverUsername(){
    return this->receiverUsername;
};
std::string Review::getWriterUsername(){
    return this->writerUsername;
};
std::string Review::getContent(){
    return this->content;
};

//Setters
void Review::setType(std::string type){
    this->type = type;
};
void Review::setReceiverUsername(std::string receiverUsername){
    this->receiverUsername = receiverUsername;
};
void Review::setWriterUsername(std::string writerUsername){
    this->writerUsername = writerUsername;
};
void Review::setContent(std::string content){
    this->content = content;
};