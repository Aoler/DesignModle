//
//  Conponent.hpp
//  Decorator
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Conponent_hpp
#define Conponent_hpp

#include <string>
#include <iostream>
//ConcreteComponent即Component
class Person
{
private:
    std::string name;
public:
    Person(){};
    Person(std::string name)
    {
        this->name=name;
    }
    virtual void Show()
    {
        std::cout<<"装饰的"<<name<<std::endl;
    }
};



#endif /* Conponent_hpp */
