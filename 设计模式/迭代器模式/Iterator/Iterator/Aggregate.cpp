//
//  Aggregate.cpp
//  Iterator
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#include "Aggregate.hpp"
#include "Iterator.hpp"

ConcreteAggregate::ConcreteAggregate()
{
    items=new std::vector<object>;
}
ConcreteAggregate::~ConcreteAggregate()
{
    delete items;
}
Iterator* ConcreteAggregate::CreateIterator()
{
    Iterator* it=new ConcreteIterator(this);
    return it;
}
Iterator* ConcreteAggregate::CreateIteratorDesc()
{
    Iterator* it=new ConcreteIteratorDesc(this);
    return it;
}
int ConcreteAggregate::Count()
{
    return items->size();
}
std::vector<object>* ConcreteAggregate::GetVector()
{
    return items;
}
object ConcreteAggregate::GetElement(int index)
{
    return items->at(index);
}
void ConcreteAggregate::SetElement(int index,object o)
{
    items->at(index)=o;
}
