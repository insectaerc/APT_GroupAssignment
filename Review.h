#pragma once

#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>

class Review{
    private:
        std::string type;
        std::string receiverUsername;
        std::string writerUsername;
        std::string content;
    public:
        Review(std::string type, std::string receiverUsername, std::string writerUsername, std::string review);

        //Getters
        std::string getType();
        std::string getReceiverUsername();
        std::string getWriterUsername();
        std::string getContent();

        
        //Setters
        void setType(std::string type);
        void setReceiverUsername(std::string username);
        void setWriterUsername(std::string username);
        void setContent(std::string content);
};

#endif