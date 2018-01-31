//
//  main.cpp
//  status
//
//  Created by Haitao on 11/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//
#include "status.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Worker* pWorker = new Worker();
    pWorker->setHour(24);
    cout << "time 24" << endl;
    pWorker->requestDoing();
    
    pWorker->setHour(11.5);
    cout << "time 11.5" << endl;
    pWorker->requestDoing();
    
    pWorker->setHour(19);
    cout << "time 19" << endl;
    pWorker->requestDoing();
    
    delete pWorker;
    return 0;
}
