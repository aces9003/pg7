//
//  Token.h
//  pg6
//
//  Created by Alex Sharata on 11/11/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#ifndef __pg6__Token__
#define __pg6__Token__

#include <string>
#include <iostream>
#include <stdio.h>


class Token {
    
    // Private by default
    int point;
    std::string type;
    
public:
    // Constructors
    // Default constructor - if called, creates 'empty' token
    Token();
    // Alternate constructor
    Token(int point, std::string type);
    /*
    // Copy constructor
    Token(const Token &);
     */
    
    // Destructor
    ~Token();
    
    // Accessors with inline definitions
    int getPoint() const { return this->point; };
    std::string getType() const { return this->type; };
    void printToken() const {
        std::cout << getPoint() << " of " << getType() << std::endl;
    };
    
    // Mutators
    bool setPoint(int n);
    bool setType(std::string s);
    
    // Overload operators
    /*
    bool operator< (const Token &) const;
    bool operator== (const Token &) const;
    // overload print operator if possible, or implement toString()-like method
    */
     
private:
    // Helper methods
    
    // isValid methods with inline definitions
    bool isValidPoint(int n) { return (n > 0 && n < 11); };
     bool isValidType(std::string s) { return (s == "Diamonds") || (s == "Gold") || (s == "Silver") || (s == "Cloth") || (s == "Spice") || (s == "Leather")|| (s == "Camels") || (s == "3cardBonus") || (s == "4cardBonus")|| (s == "5cardBonus"); };
};

#endif /* defined(__pg6__Token__) */
