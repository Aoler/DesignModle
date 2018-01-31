//
//  main.cpp
//  Flyweight
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//


/*
 二、概念
 享元模式（Flyweight）：运用共享技术有效地支持大量细粒度的对象。
 flyweight的意思：轻量级。
 
 三、说明
 
 角色：
 （1）Flyweight类：它是所有具体享元类的超类或接口，通过这个接口，Flyweight可以接受并作用于外部状态。
 （2）ConcreteFlyweight类：继承Flyweight超类或实现Flyweight接口，并为内部状态增加存储空间。
 （3）UnsharedConcreteFlyweight：是指那些不需要共享的Flyweight子类。因为Flyweight接口共享成为可能，但是它并不强制共享。
 （4）FlyweightFactory：是一个享元工厂，用来创建并管理Flyweight对象。它主要是用来确保合理地共享Flyweight，当用户请求一个Flyweight时，FlyweightFactory对象提供一个已创建的实例或者创建一个（如果不存在的话）。
 
 用享元模式的好处？
 享元模式可以避免大量非常相似类的开销。在程序设计中，有时需要生成大量细粒度的类实例来表示数据。如果能发现这些实例除了几个参数外基本上都是相同的，有时就能够大幅度的减少需要实例化的类的数量。如果能把那些参数移到类实例的外面，在方法调用时将它们传递进来，就可以通过共享大幅度地减少单个实例的数目。
 也就是说，享元模式Flyweight执行时所需的状态是有内部的也可能有外部的，内部状态存储于ConcreteFlyweight对象之中，而外部对象则应该考虑由客户端对象存储或计算，当调用Flyweight对象的操作时，将该状态传递给它。
 
 什么时候用享元模式？
 如果一个应用程序使用了大量的对象，而大量的这些对象造成了很大的存储开销时就应该考虑使用；还有就是对象的大多数状态可以外部状态，如果删除对象的外部状态，那么可以用相对较少的共享对象取代很多组对象，此时可以考虑使用享元模式。
 
*/


#include "Flyweight.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    WebSiteFactory f;
    
    WebSite* fx=f.GetWebSiteCategory("产品展示");
    fx->Use(User("小菜"));
    
    WebSite* fy=f.GetWebSiteCategory("产品展示");
    fy->Use(User("大鸟"));
    
    WebSite* fz=f.GetWebSiteCategory("产品展示");
    fz->Use(User("娇娇"));
    
    WebSite* fl=f.GetWebSiteCategory("博客");
    fl->Use(User("老顽童"));
    
    WebSite* fm=f.GetWebSiteCategory("博客");
    fm->Use(User("桃谷六仙"));
    
    WebSite* fn=f.GetWebSiteCategory("博客");
    fn->Use(User("南海鳄神"));
    
    std::cout<<"得到网站分类总数："<<f.GetWebSiteCount()<<std::endl;
    return 0;
}
