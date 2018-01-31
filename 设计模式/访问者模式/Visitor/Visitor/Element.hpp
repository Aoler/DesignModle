//
//  Element.hpp
//  Visitor
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Element_hpp
#define Element_hpp

class Action;

class Person
{
public:
    virtual void Accept(Action* visitor){};
};

class Man:public Person
{
    void Accept(Action* visitor);
};

class Woman:public Person
{
    void Accept(Action* visitor);
};

#endif /* Element_hpp */
