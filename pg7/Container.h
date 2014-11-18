/*
 ABSTRACT Container Class
 has Cards
  vector for cards
 */

#ifndef pg7_Container_h
#define pg7_Container_h

#include <Cards.h>

class Container{
protected:
    vector<Card> hand;
public:
    virtual ~Container();
    virtual print()=0;
};

#endif
