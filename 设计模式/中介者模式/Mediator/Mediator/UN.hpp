//
//  UN.hpp
//  Mediator
//
//  Created by Haitao on 13/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef UN_hpp
#define UN_hpp

#include <string>
class Country;
using namespace std;

//Mediator
class UnitedNations
{
public:
    virtual void setColleague1(Country* c)=0;
    virtual void setColleague2(Country* c)=0;
    virtual void Declare(string message, Country* colleague)=0;
};

//ConcreteMediator
class UnitedNationsSecurityCouncil:public UnitedNations
{
private:
    Country* colleague1;
    Country* colleague2;
    
public:
    void setColleague1(Country* c);
    void setColleague2(Country* c);
    void Declare(string message, Country* colleague);
};

#endif /* UN_hpp */
