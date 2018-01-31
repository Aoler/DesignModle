//
//  Subject.cpp
//  observer
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#include "Subject.hpp"
#include "Observer.hpp"

std::string Subject::GetSubjectState()
{
    return SubjectState;
}
void Subject::SetSubjectState(std::string state)
{
    this->SubjectState=state;
}

void Boss::Attach(Observer* observer)
{
    observers.push_back(observer);
}
void Boss::Detach(Observer* observer)
{
    std::list<Observer*>::iterator it;
    for(it=observers.begin();it!=observers.end();it++)
    {
        if(*it==observer)
        {
            observers.erase(it);
            break;
        }
    }
}
void Boss::Notify()
{
    std::list<Observer*>::iterator it;
    for(it=observers.begin();it!=observers.end();it++)
    {
        (**it).Update();
    }
}
