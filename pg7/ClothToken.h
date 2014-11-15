//
//  ClothToken.h
//  pg7
//
//  Created by Emily Johnson on 11/15/14.
//  Copyright (c) 2014 Emily Johnson. All rights reserved.
//

#include "GoodsTokenA.h"

#ifndef pg7_ClothToken_h
#define pg7_ClothToken_h

class ClothToken : public GoodsToken{
private:
    string type;
    int value;
    
public:
    ClothToken(){
        string="Cloth";
    }
    void setVal(int val){
        if(val==4 || val>5){
            cerr<<"ERROR CANT SET CLOTH TOKEN TO THIS VAL"<<endl;
        }
        else value=val;
    }
    
};



class LeatherToken : public GoodsToken{
private:
    string type;
    int value;
    
public:
    LeatherToken(){
        string="Leather";
    }
    void setVal(int val){
        if(val>4){
            cerr<<"ERROR CANT SET CLOTH TOKEN TO THIS VAL"<<endl;
        }
        else value=val;
    }
};


class SpiceToken : public GoodsToken{
private:
    string type;
    int value;
    
public:
    SpiceToken(){
        string="Spice";
    }
    void setVal(int val){
        if(val==4 || val>5){
            cerr<<"ERROR CANT SET CLOTH TOKEN TO THIS VAL"<<endl;
        }
        else value=val;
    }
};

class SilverToken : public GoodsToken{
private:
    string type;
    int value;
    
public:
    SilverToken(){
        string="Silver";
    }
    void setVal(int val){
        if(val!=4){
            cerr<<"ERROR CANT SET CLOTH TOKEN TO THIS VAL"<<endl;
        }
        else value=val;
    }
};

class GoldToken : public GoodsToken{
private:
    string type;
    int value;
    
public:
    GoldToken(){
        string="Gold";
    }
    void setVal(int val){
        if(val!=5 || val!=6){
            cerr<<"ERROR CANT SET CLOTH TOKEN TO THIS VAL"<<endl;
            }
        else value=val;
    }
};

class DiamondToken : public GoodsToken{
private:
    string type;
    int value;
    
public:
    DiamondToken(){
        string="Diamond";
    }
    void setVal(int val){
        if(val!=5 || val!=7){
            cerr<<"ERROR CANT SET CLOTH TOKEN TO THIS VAL"<<endl;
        }
        else value=val;
    }
};



#endif
