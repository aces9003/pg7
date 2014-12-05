//
//  Card.cpp
//  pg6
//
//  Created by Alex Sharata on 11/11/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#include <string>
#include <iostream>
#include "Card.h"

using std::string;
using std::cout;
using std::endl;

// Default constructor - creates empty, non-valid card
Card:: Card() : type("NoType")
{}

// Alternate constructor
Card::Card(std::string type)
{
    // Validate all input prior to constructing Card object
    if (isValidType(type) == false) {
        this->type = "NoType";
    } else {
        setType(type);
    }
}

/*
// Copy constructor
Card::Card(const Card & other) : type(other.type)
{}
*/

Card::~Card()
{
    // Instructions: uncomment line below to simulate destructor
    //cout << "Destroying "; printCard();
}

bool Card::setType(string s)
{
    if (isValidType(s)) {
        type = s;
        return true;
    } else {
        type = "NoType";
        return false;
    }
}

/*
bool Card:: operator< (const Card & other) const {
    return this->getRank() < other.getRank();
}

bool Card:: operator== (const Card & other) const {
    return this->getRank() == other.getRank();
}
*/
