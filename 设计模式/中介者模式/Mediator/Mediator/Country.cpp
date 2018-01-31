//
//  Country.cpp
//  Mediator
//
//  Created by Haitao on 13/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#include "Country.hpp"
#include <string>
#include <iostream>

using namespace std;

void USA::Declare(string message)
{
    mediator->Declare(message,this);
}

void USA::GetMessage(string message)
{
    cout<<"美国获得对方信息："<<message<<endl;
}

void Iraq::Declare(string message)
{
    mediator->Declare(message,this);
}

void Iraq::GetMessage(string message)
{
    cout<<"伊拉克获得对方信息："<<message<<endl;
}
