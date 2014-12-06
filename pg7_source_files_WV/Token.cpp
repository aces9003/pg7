//
//  Token.cpp
//  pg6
//
//  Created by Alex Sharata on 11/11/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

#include <string>
#include <iostream>
#include "Token.h"

using std::string;
using std::cout;
using std::endl;

// Default constructor - creates empty, non-valid Token
Token:: Token() : point(0), type("NoType")
{}

// Alternate constructor
Token::Token(int point, std::string type)
{
    // Validate all input prior to constructing Token object
    if (isValidPoint(point) == false || isValidType(type) == false) {
        this->type = "NoType";
        this->point = 0;
    } else {
        setPoint(point);
        setType(type);
    }
}

/*
// Copy constructor
Token::Token(const Token & other) : point(other.point), type(other.type)
{}
 */

Token::~Token()
{
    // Instructions: uncomment line below to simulate destructor
    //cout << "Destroying "; printToken();
}

bool Token::setPoint(int n)
{
    if (isValidPoint(n)) {
        point = n;
        return true;
    } else {
        type = "NoType";
        point = 0;
        return false;
    }
}

bool Token::setType(string s)
{
    if (isValidType(s)) {
        type = s;
        return true;
    } else {
        type = "NoType";
        return false;
    }
}

bool Token:: operator== (const Token & other) const {
	if (this->getType() == other.getType() && this->getPoint() == other.getPoint)
		return true;
	return false;
}

