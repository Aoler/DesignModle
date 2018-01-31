//
//  Singleton.hpp
//  Singleton
//
//  Created by Haitao on 13/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp
#include <iostream>
using namespace std;

class Sigleton
{
public:
    static Sigleton* getInstance()//必须是static，否则无法调用getInstance
    {
        if(uniqueInstance == nullptr)
        {
            uniqueInstance = new Sigleton();
        }
        return uniqueInstance;
    }
    virtual void show()
    {
        cout << "Singleton" << endl;
    }
private:
    Sigleton(){}
    static Sigleton* uniqueInstance;
};
#endif /* Singleton_hpp */
