//
//  Element.cpp
//  Visitor
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#include "Element.hpp"
#include "Visitor.hpp"

void Man::Accept(Action* visitor)
{
    visitor->GetManConclusion(this);
}

void Woman::Accept(Action* visitor)
{
    visitor->GetWomanConclusion(this);
}
