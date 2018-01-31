//
//  main.cpp
//  Adapter
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//


/*
 
 关键词：Client需要Request（）函数，Adaptee提供的是SpecificRequest（）函数，Adapter提供一个Request（）函数将Adaptee和SpecificeRequest（）函数封装起来。
 
 
 二、概念
 适配器模式：将一个类的接口转换成客户希望的另外一个接口。Adapter模式使得原来由于接口不兼容而不能一起工作的那些类可以一起工作。
 
 三、说明
 角色：
 （1）Target：这是客户所期待的接口，Target可以是具体的或抽象的类，也可以是接口。
 （2）Adaptee：需要适配的类。
 （3）Adapter：通过在内部包装一个Adaptee对象，把源接口转换成目标接口。
 什么时候用？
 （1）在想使用一个已存在的类，但是如果他的接口，也就是它的方法和你的要求不相同时，就应该考虑用适配器模式。
 （2）用了适配器模式，客户代码可以统一调用统一接口就行了，这样可以更简单，更直接，更紧凑。
 （3）要在双方都不太容易修改的时候再使用适配器模式适配，而不是一有不同是就使用它。
 
*/

#include "Adapter.hpp"
#include <string>
#include <iostream>

int main(int argc, const char * argv[]) {
    Player* b=new Forwards("巴蒂尔");
    b->Attack();
    
    Player* m=new Guards("麦克格雷迪");
    m->Attack();
    
    //翻译告诉姚明，教练让你既要进攻，又要防守
    Player* ym=new Translator("姚明");
    ym->Attack();
    ym->Defense();
    
    delete b;
    delete m;
    delete ym;
    return 0;
}
