//
//  main.cpp
//  Proxy
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//
#include "Proxy.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    SchoolGirl* jiaojiao=new SchoolGirl();
    jiaojiao->setName("李娇娇");
    
    Proxy* daili=new Proxy(jiaojiao);
    
    daili->GiveDolls();
    daili->GiveFlowers();
    daili->GiveChocolate();
    
    delete jiaojiao;
    jiaojiao=NULL;
    delete daili;
    daili=NULL;
    return 0;
}
