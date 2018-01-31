//
//  main.cpp
//  Iterator
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 二、概念
 迭代器模式（Iterator）：提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示。
 
 三、说明
 什么时候用？
 （1）当你需要访问一个聚集对象，而且不管这些对象时什么都需要遍历的时候，你就应该考虑用迭代器模式。
 （2）你需要对聚集有多种遍历时，可以考虑用迭代器模式。
 （3）为遍历不同的聚集结构提供如开始、下一个、是否结束、当前哪一项等统一的接口。
 迭代器模式的好处？
 迭代器模式就是分离了集合对象的遍历行为，抽象出一个迭代器类来负责，这样既可以不暴露集合的内部结构，又可让外部代码透明地访问集合内部的数据。
 
 
*/

#include "Iterator.hpp"
#include "Aggregate.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    //公交车，即聚集对象
    ConcreteAggregate* a=new ConcreteAggregate();
    
    //新上来的乘客
    a->GetVector()->push_back("大鸟");
    a->GetVector()->push_back("小菜");
    a->GetVector()->push_back("行李");
    a->GetVector()->push_back("老外");
    a->GetVector()->push_back("公交内部人员");
    a->GetVector()->push_back("小偷");
    
    //售票员出场，先看好了上车的是哪些人，即声明了迭代器对象。
    //下面两种获取迭代器的方法都可以
    //Iterator* i=new ConcreteIterator(a);
    
    //产生从前往后的迭代器
    Iterator* it1=a->CreateIterator();
    
    //告知每一位乘客买票
    std::cout<<"从前往后的迭代器："<<std::endl<<std::endl;
    while(!it1->IsDone())
    {
        std::cout<<it1->CurrentItem()<<"  请买车票！"<<std::endl;
        it1->Next();
    }
    std::cout<<std::endl;
    
    //产生从后往前的迭代器
    Iterator* it2=a->CreateIteratorDesc();
    
    //告知每一位乘客买票
    std::cout<<"从后往前的迭代器："<<std::endl<<std::endl;
    while(!it2->IsDone())
    {
        std::cout<<it2->CurrentItem()<<"  请买车票！"<<std::endl;
        it2->Next();
    }
    std::cout<<std::endl<<std::endl;
    
    delete a,it1,it2;
    return 0;
}
