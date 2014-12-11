//  COMPILE WITH: g++ -std=c++11 -pedantic -Wall -Wextra -O UITest.cpp
//  UITest.cpp
//  pg7
//
//  Created by Alex Sharata on 11/21/14.
//  Copyright (c) 2014 Alex Sharata. All rights reserved.
//

//#include "MarketViewController.cpp"
#include "DynamicViewController.cpp"
#include <iostream>

#include <vector>
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::vector;

int main() {
    // We'll create a Game object (g) succesfully, initialize it's members,
    // then we'll pass it's memory address to beginGame(&g) and let it take
    // care of the rest...
    
    // Game g
    // ...
    // beginGame(&g);
    
    beginGame();
    
    // HOW TO POPULATE trading and selling vectors
    /*
    // Needs non-numeric character to finish inputing ints to proper vector
    while(cin >> input){
        v.push_back(input);
    }
     */

}