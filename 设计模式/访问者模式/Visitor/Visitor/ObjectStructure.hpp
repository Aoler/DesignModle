//
//  ObjectStructure.hpp
//  Visitor
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef ObjectStructure_hpp
#define ObjectStructure_hpp

#include "Element.hpp"
#include "Visitor.hpp"
#include <vector>
#include <string>
#include <iostream>

class ObjectStructure
{
private:
    std::vector<Person*> elements;
public:
    ObjectStructure(){}
    ~ObjectStructure();
    
    void Attach(Person*);
    void Detach(Person*);
    void Display(Action*);
};

#endif /* ObjectStructure_hpp */
