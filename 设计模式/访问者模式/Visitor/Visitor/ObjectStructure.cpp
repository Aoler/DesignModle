//
//  ObjectStructure.cpp
//  Visitor
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#include "ObjectStructure.hpp"
#include <iterator>

ObjectStructure::~ObjectStructure()
{
    std::vector<Person* >::iterator it;
    for(it=elements.begin();it!=elements.end();it++)
        delete *it;
}

void ObjectStructure::Attach(Person* element)
{
    elements.push_back(element);
}

void ObjectStructure::Detach(Person* element)
{}

void ObjectStructure::Display(Action* visitor)
{
    std::vector<Person* >::iterator it;
    for(it=elements.begin();it!=elements.end();it++)
        (*it)->Accept(visitor);
}
