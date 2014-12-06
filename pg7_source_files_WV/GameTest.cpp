// GameTest.cpp
// compile with g++ -std=c++11 -pedantic -Wall -Wextra -O GameTest.cpp Card.cpp Token.cpp
// Append *.cpp files as you see necessary for testing purposes

#include "Game.h"
#include "Game.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

int main() {
    Game gameTest("p1", "p2");
    //Game gameTest;
    //assert(gameTest.createDeck());
    //assert(gameTest.setupTokens());
    
    cout << "Size of initialized deck: ";
    cout << gameTest.deck.size() << endl;
    
    // Print all 55 cards (should be shuffled)
    for (int i = 0; i < (int) gameTest.deck.size(); i++) {
        cout << "Card " << i+1 << ": " << gameTest.deck.at(i).getType() << endl;
    }
    
    // Print all 56 tokens (bonus tokens should be shuffled)
    // Print Diamonds tokens
    for (int i = 0; i < 5; i++) {
        cout << "Diamond token " << i+1 << ": " << gameTest.diamondT.at(i).getType() << " " << gameTest.diamondT.at(i).getPoint() << endl;
    }
    
    // Print Gold tokens
    for (int i = 0; i < 5; i++) {
        cout << "Gold token " << i+1 << ": " << gameTest.goldT.at(i).getType() << " " << gameTest.goldT.at(i).getPoint() << endl;
    }
    
    // Print Silver tokens
    for (int i = 0; i < 5; i++) {
        cout << "Silver token " << i+1 << ": " << gameTest.silverT.at(i).getType() << " " << gameTest.silverT.at(i).getPoint() << endl;
    }
    
    // Print Cloth tokens
    for (int i = 0; i < 7; i++) {
        cout << "Cloth token " << i+1 << ": " << gameTest.clothT.at(i).getType() << " " << gameTest.clothT.at(i).getPoint() << endl;
    }
    
    // Print Spice tokens
    for (int i = 0; i < 7; i++) {
        cout << "Spice token " << i+1 << ": " << gameTest.spiceT.at(i).getType() << " " << gameTest.spiceT.at(i).getPoint() << endl;
    }
    
    // Print Leather tokens
    for (int i = 0; i < 9; i++) {
        cout << "Leather token " << i+1 << ": " << gameTest.leatherT.at(i).getType() << " " << gameTest.leatherT.at(i).getPoint() << endl;
    }
    
    // Print bonus3 tokens
    for (int i = 0; i < 6; i++) {
        cout << "Bonus 3 token " << i+1 << ": " << gameTest.bonus3.at(i).getType() << " " << gameTest.bonus3.at(i).getPoint() << endl;
    }
    
    // Print bonus4 tokens
    for (int i = 0; i < 6; i++) {
        cout << "Bonus 4 token " << i+1 << ": " << gameTest.bonus4.at(i).getType() << " " << gameTest.bonus4.at(i).getPoint() << endl;
    }
    
    // Print bonus3 tokens
    for (int i = 0; i < 6; i++) {
        cout << "Bonus 5 token " << i+1 << ": " << gameTest.bonus5.at(i).getType() << " " << gameTest.bonus5.at(i).getPoint() << endl;
    }
    
    return 0;
    
    cout<<"Testing Cards"<<endl;
    Card card("Camels");
    Card card2("NotCamels");
    Card card1("Camels");
    assert(card == card1);
    assert(!card == card2);
    cout<<"Done testing Card operator overloaders!"<<endl<<"Testing "
    Token token1(1,"A");
    Token token2(2,"B");
    Token token3(1,"A");
    assert(token1==token3);
    assert(!token1==token2);
    cout<<"Done testing Token operator overloaders!"<<endl;
    
    
}

