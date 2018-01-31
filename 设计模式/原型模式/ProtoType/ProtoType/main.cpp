//
//  main.cpp
//  ProtoType
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 二、概念
 原型模式（Prototype）：用原型示例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
 
 三、说明
 （1）原型模式实际上就是从一个对象再创建另外一个可定制的对象，而且不需要知道任何创建的细节。
 （2）一般在初始化的信息不发生变化的情况下，克隆是最好的办法。这既隐藏了对象创建的细节，有对性能是大大的提高。因为如果不用Clone，每次new，都需要执行一次构造函数，如果构造函数的执行时间很长，那么多次的执行这个初始化操作就实在是太低效了。
 （3）浅复制和深复制：
 浅复制：被复制的对象的所有变量都含有与原来的对象相同的值，而所有对其他对象的引用都仍然指向原来的对象。
 深复制：把引用对象的变量指向复制过的新对象，而不是原有的被引用的对象。
 Clone的时候使用深复制。
 
*/

#include "ProtoType.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, const char * argv[]) {
    Resume* a=new Resume("大鸟");
    a->SetPersonalInfo("男","29");
    a->SetWorkExperience("1998-2000","XX公司");
    
    Resume* b=a->Clone();
    b->SetWorkExperience("1998-2006","YY公司");
    
    Resume* c=b->Clone();
    c->SetPersonalInfo("男","24");
    c->SetWorkExperience("1998-2003","ZZ公司");
    
    a->Display();
    b->Display();
    c->Display();
    
    Resume d(*c);
    c->SetWorkExperience("2011-2017", "yuntaili");
    d.Display();
    c->Display(); //c的改变不影响d
    d.Display();
    
    delete a;
    delete b;
    delete c;
    a=b=c=NULL;
    return 0;
}
