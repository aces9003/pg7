/*
 
 Token Class
 each token has a string declaring type
 and a point value
 
 */

#ifndef pg7_Token_h
#define pg7_Token_h

#include <string>

 using std::string;

class Token{
private:
    string type;
    int point;
    
public:
    Token(int points, string s) {setType(s); setPt(points);}
    
    string getType(){return this->type;};
    int getPt(){return this->point;};
    
    void setType(string s){type=s;}
    void setPt(int x){point=x;}
    
    void print();
    
    ~Token() {std::cout<<"Deleting Token "<<this.getType()<<std::endl; delete this;}
};

#endif
