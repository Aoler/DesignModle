//
//  main.cpp
//  Bridge
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//


/*
 二、概念
 桥接模式（Bridge）：将抽象部分与它的实现部分分离，使他们都可以独立地变化。
 
 三、说明
 为什么叫“桥接模式”？
 如上所示的UML图中，有一个聚合线，像一座桥，所以叫“桥接模式”。
 
 概念解释：
 什么叫抽象与它的实现分离，这并不是说，让抽象类与其派生类分离，因为这没有任何意义。实现指的是抽象类与它的派生类用来实现自己的对象。
 
 为什么要优先使用合成/聚合原则？
 （1）对象的继承关系是在编译时就定义好了的，所以无法再运行时改变从父类继承的实现。子类的实现与它的父类有非常紧密的依赖关系，以至于父类实现的任何变化必然会导致子类发生变化。当你需要复用子类时，如果继承下来的实现不适合解决新的问题，则父类必须重写或被其他更适合的类替换。这种依赖关系限制了灵活性并最终限制了复用性。
 （2）优先使用合成/聚合原则有助于你保持每个类被封装，并被集中在单个任务上。这样类和类继承层次会保持较小规模，并且不太可能增长为不可控制的庞然大物。
 
 盲目使用继承会造成麻烦，本质原因是什么？
 继承是一种强耦合的结构。父类变，子类就必须要变。所以，我们在用继承时，一定要在是“is-a”的关系时再考虑使用，而不是任何时候都去使用。
 
*/

#include "Bridge.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout<<"手机品牌N："<<std::endl;
    HandsetBrand* ab=new HandsetBrandN();
    
    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();
    
    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();
    
    delete ab;
    
    //手机品牌M
    std::cout<<std::endl<<"手机品牌M："<<std::endl;
    ab=new HandsetBrandM();
    
    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();
    
    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();
    
    delete ab;
    ab=NULL;
    
    std::cout<<std::endl;     return 0;
}
