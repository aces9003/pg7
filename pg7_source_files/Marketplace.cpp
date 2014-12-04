//
//  Marketplace.cpp
//  pg7
//
//  Created by Emily Johnson on 12/3/14.
//  Copyright (c) 2014 Emily Johnson. All rights reserved.
//

#include "Marketplace.h"


Marketplace::Marketplace(Game a){
    for(int i=0; i<5; i++){
        int r= rand() % a.deck.size();
        Card adder=a.deck.at(r);
        market.push_back(a.deck.at(r));
        a.deck.erase(a.deck.begin()+r);
    }
}