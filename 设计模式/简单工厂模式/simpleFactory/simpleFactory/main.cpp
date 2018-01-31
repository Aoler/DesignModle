//
//  main.cpp
//  simpleFactory
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#include "factory.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Operation* oper=NULL;
    
    OperationFactory of;
    oper=of.createOperation('/');
    oper->setA(1);
    oper->setB(2);
    cout<<oper->GetResult()<<endl;
    if(oper!=NULL)
    {
        delete oper;
        oper=NULL;
    }
    return 0;
}
