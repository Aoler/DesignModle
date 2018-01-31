//
//  main.cpp
//  Singleton
//
//  Created by Haitao on 13/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 
 二、概念
 单例模式：保证一个类仅有一个实例，并提供一个访问他的全局访问点。[DP]
 通常我们可以让一个全局变量使得一个对象被访问，但它不能防止你实例化多个对象。一个最好的办法就是，让类自身负责保护它的唯一实例。这个类可以保证没有其他实例可以被创建，并且他可以提供一个访问该实例的方法。
 
 三、注意：
 使用单例模式，只能保证一个线程内对象不会被多次创建，而不不能保证多线程的情况。因此，需要考虑多线程的话，就要用锁。
 
*/

#include "Singleton.hpp"
#include <iostream>
using namespace std;

//静态成员在类体外定义
Sigleton* Sigleton::uniqueInstance=nullptr;


int main(int argc, const char * argv[]) {
    Sigleton* pSigleton1 = Sigleton::getInstance();
    Sigleton* pSigleton2 = Sigleton::getInstance();
    
    if(pSigleton1 == pSigleton2)
        cout << "Sigleton  Successful" << endl;
    else
        cout << "Sigleton failue" << endl;
    return 0;
}
