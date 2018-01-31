//
//  Iterator.cpp
//  Iterator
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#include "Iterator.hpp"

ConcreteIterator::ConcreteIterator(Aggregate* aggregate)
{
    this->aggregate=(ConcreteAggregate*)aggregate;
    current=0;
}

object ConcreteIterator::First()
{
    return aggregate->GetVector()->at(0);
}

object ConcreteIterator::Next()
{
    current++;
    if(current<aggregate->GetVector()->size())
        return aggregate->GetVector()->at(current);
    return object();
}

bool ConcreteIterator::IsDone()
{
    return current>=aggregate->GetVector()->size()?true:false;
}
object ConcreteIterator::CurrentItem()
{
    return aggregate->GetVector()->at(current);
}


ConcreteIteratorDesc::ConcreteIteratorDesc(Aggregate* aggregate)
{
    this->aggregate=(ConcreteAggregate*)aggregate;
    current=(((ConcreteAggregate*)aggregate)->GetVector()->size())-1;
}
object ConcreteIteratorDesc::First()
{
    return *(aggregate->GetVector()->end());
}

object ConcreteIteratorDesc::Next()
{
    current--;
    if(current>=0)
        return aggregate->GetVector()->at(current);
    return object();
}

bool ConcreteIteratorDesc::IsDone()
{
    return current<0?true:false;
}

object ConcreteIteratorDesc::CurrentItem()
{
    return aggregate->GetVector()->at(current);
}
