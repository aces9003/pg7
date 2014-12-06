//
//  Card.h
//  pg6
//
//  Created by Alex Sharata on 11/11/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#ifndef __pg6__Card__
#define __pg6__Card__

#include <string>
#include <iostream>
#include <stdio.h>


class Card {
    
    // Private by default
    std::string type;
    
public:
    // Constructors
    // Default constructor - if called, creates 'empty' card
    Card();
    // Alternate constructor
    Card(std::string type);
    // Copy constructor
    //Card(const Card &);
    
    // Destructor
    ~Card();
    
    // Accessors with inline definitions
    std::string getType() const { return this->type; };
    void printCard() const {
        std::cout << getType() << " card" << std::endl;
    };
    
    // Mutators
    bool setType(std::string s);
    
    // Overload operators
    bool operator== (const Card &) const;
    
    
private:
    // Helper methods
    
    // isValid methods with inline definitions
    bool isValidType(std::string s) { return (s == "Diamonds") || (s == "Gold") || (s == "Silver") || (s == "Cloth") || (s == "Spice") || (s == "Leather")|| (s == "Camels"); };
};

#endif /* defined(__pg6__Card__) */
