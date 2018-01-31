//
//  Visitor.hpp
//  Visitor
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Visitor_hpp
#define Visitor_hpp

#include "Element.hpp"

class Action
{
public:
    virtual void GetManConclusion(Person* concreteElementA){};
    virtual void GetWomanConclusion(Person* concreteElementB){};
};

class Success:public Action
{
public:
    void GetManConclusion(Person* concreteElementA);
    void GetWomanConclusion(Person* concreteElementB);
};

class Failing:public Action
{
public:
    void GetManConclusion(Person* concreteElementA);
    void GetWomanConclusion(Person* concreteElementB);
};

class Amativeness:public Action
{
public:
    void GetManConclusion(Person* concreteElementA);
    void GetWomanConclusion(Person* concreteElementB);
};

#endif /* Visitor_hpp */
