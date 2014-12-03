//
//  Hand.cpp
//  pg7
//
//  Created by Emily Johnson on 12/3/14.
//  Copyright (c) 2014 Emily Johnson. All rights reserved.
//

#include "Hand.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>


Hand::Hand(Game a){
    for(int i=0; i<5; i++){
        int r= rand() % 55;
        Card adder=a.deck.at(r);
        string b=adder.getType();
        string c= "Camel";
        if (b.compare(c)==0) {
            i--;
            camels++;
            break;
        }
        hand.push_back(a.deck.at(r));
        a.deck.erase(a.deck.begin()+r);
    }
}
