//
//  Decorator.hpp
//  Decorator
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//


/*
 二、概念
 装饰模式：动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更为灵活。
 
 三、说明
 角色：
 （1）Component是定义一个对象，可以给这些对象动态地添加职责。
 （2）ConcreteComponent是定义了一个具体的对象，也可以给这个对象增加一些职责。
 （3）Decorator，装饰抽象类，继承了Component，从外类来扩展Component类的功能，但是对于Component来说，是无需知道Decorator的存在的。
 （4）至于ConcreteDecorator就是具体的装饰对象，起到给Component添加职责的作用。
 什么时候用：
 （1）需要在内部组装完成再显示出来的情况。
 （2）类似于建造者模式，但是建造者模式的要求见到的过程必须是稳定的，而装饰模式的建造过程是不稳定的。
 （3）我们需要把所需的功能按正确的顺序串联起来进行控制。
 优点：
 （1）把类的装饰功能从类中搬移去除，这样可以简化原有的类。
 （2）有效地把类的核心职责和装饰功能区分开来，而且可以去除相关类中重复的装饰逻辑。
 和建造者模式的区别？
 建造者模式要求建造的过程必须是稳定的，而装饰模式的建造过程是不稳定的，可以有各种各样的组合方式。
 
*/

#ifndef Decorator_hpp
#define Decorator_hpp

//2）Decorator及ConcreteDecorator：此处为Finery及其子类

#include <iostream>
#include "Conponent.hpp"

//Decorator类
class Finery:public Person
{
protected:
    Person* component;
public:
    void Decorator(Person* component)
    {
        this->component=component;
    }
    void Show()
    {
        if(component!=NULL)
            component->Show();
    }
};

//下面是一系列ConcreteDecorator类
class TShirts:public Finery
{
public:
    void Show()
    {
        std::cout<<"大T恤  ";
        Finery::Show();
    }
    
};

//ConcreteDecorator类
class BigTrouser:public Finery
{
public:
    void Show()
    {
        std::cout<<"垮裤  ";
        Finery::Show();
    }
    
};

//ConcreteDecorator类
class Sneakers:public Finery
{
public:
    void Show()
    {
        std::cout<<"破球鞋  ";
        Finery::Show();
    }
    
};

//ConcreteDecorator类
class Suit:public Finery
{
public:
    void Show()
    {
        std::cout<<"西装  ";
        Finery::Show();
    }
    
};

//ConcreteDecorator类
class Tie:public Finery
{
public:
    void Show()
    {
        std::cout<<"领带  ";
        Finery::Show();
    }
    
};

//ConcreteDecorator类
class LeatherShoes:public Finery
{
public:
    void Show()
    {
        std::cout<<"皮鞋  ";
        Finery::Show();
    }
    
};

#endif /* Decorator_hpp */
