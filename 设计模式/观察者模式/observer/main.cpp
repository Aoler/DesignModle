//
//  main.cpp
//  observer
//
//  Created by Haitao on 11/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 一、UML图
 
 关键词：Subject维护一个Observer列表，Subject执行Notify（）时就执行列表中的每个Observer的Update（）。
 
 二、概念
 观察者模式：定义了一种一对多的依赖关系，让多个观察者对象同时监听某一主题对象。这个主题对象在状态发生变化时，会通知所有观察者对象，使他们能够自动更新自己。
 
 三、说明
 角色：
 （1）Subject类：可以翻译为主题或者抽象通知者，一般用一个抽象类或者一个接口实现。他把所有对观察者对象的引用保存在一个聚集里，每个主题都可以有任何数量的观察者。抽象主题提供一个接口，可以增加和删除观察者对象。
 （2）Observer类：抽象观察者，为所有的具体观察者定义一个接口，在得到主题的通知时更新自己。这个接口叫做更新接口。抽象观察者一般用一个抽象类或者一个接口实现。更新接口通常包含一个Update()方法，这个方法叫做更新方法。
 （3）ConcreteSubject类：叫做具体主题或者具体通知者，将有关状态存入具体观察者对象；在具体主题的内部状态改变时，给所有登记过的观察者发出通知。
 （4）ConcreteObserver类：具体观察者，实现抽象观察者角色所要求的更新接口，以便使本身的状态与主题的状态相协调。具体观察者角色可以保存一个指向具体主题对象的引用。
 什么时候用观察者模式？
 （1）当一个对象的改变需要同时改变其他对象的时候；
 （2）而且不知道具体有多少对象有待改变时，应该考虑使用观察者模式；
 （3）当一个抽象模型有两个方面，其中一方面依赖于另一方面，这时用观察者模式可以将这两者封装在独立的对象中使他们各自独立地改变和复用。
 本质：
 观察者模式所做的工作其实就是在解除耦合，让耦合的双方都依赖于抽象，而不是依赖于具体。从而使得各自的变化都不会影响另一边的变化。
 
 
*/


#include "Observer.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Subject* huhansan=new Boss();
    
    //4个观察者实例
    Observer* tongshi1=new StockObserver("魏关姹",huhansan);
    Observer* tongshi2=new StockObserver("易管察",huhansan);
    Observer* tongshi3=new NBAObserver("霍华德",huhansan);
    Observer* tongshi4=new NBAObserver("林书豪",huhansan);
    
    //将4个观察者都加入到通知者的通知队列中
    huhansan->Attach(tongshi1);
    huhansan->Attach(tongshi2);
    huhansan->Attach(tongshi3);
    huhansan->Attach(tongshi4);
    
    //魏关姹没有被老板通知到，减去。
    huhansan->Detach(tongshi1);
    
    huhansan->SetSubjectState("我胡汉三回来了！");
    
    //通知
    huhansan->Notify();
    
    delete huhansan;
    delete tongshi1;
    delete tongshi2;
    delete tongshi3;
    delete tongshi4;
    
    std::cout<<""<<std::endl;
    system("pause");

    return 0;
}
