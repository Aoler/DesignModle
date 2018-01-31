//
//  LeifengModel.hpp
//  FactoryMethod
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef LeifengModel_hpp
#define LeifengModel_hpp

#include <iostream>
#include <cstdlib>

using namespace std;

//抽象产品类：雷锋
class Leifeng
{
public:
    virtual void Sweep()
    {
        cout<<"扫地"<<endl;
    }
    virtual void Wash()
    {
        cout<<"洗衣"<<endl;
    }
    virtual void BuyRice()
    {
        cout<<"买米"<<endl;
    }
};

//下面是两个具体产品类
class Undergraduate:public Leifeng
{
public:
    void Sweep()
    {
        cout<<"学生-扫地"<<endl;
    }
    void Wash()
    {
        cout<<"学生-洗衣"<<endl;
    }
    void BuyRice()
    {
        cout<<"学生-买米"<<endl;
    }
};

class Volunteer:public Leifeng
{
public:
    void Sweep()
    {
        cout<<"志愿者-扫地"<<endl;
    }
    void Wash()
    {
        cout<<"志愿者-洗衣"<<endl;
    }
    void BuyRice()
    {
        cout<<"志愿者-买米"<<endl;
    }
};

//抽象工厂类
class AbstractFactory
{
public:
    virtual Leifeng* CreateLeifeng()
    {
        return new Leifeng;
    }
};

//下面是两个具体工厂类，分别于两个具体产品相对应
class UndergraduateFactory:public AbstractFactory
{
public:
    Undergraduate* CreateLeifeng()
    {
        return new Undergraduate;
    }
};

class VolunteerFactory:public AbstractFactory
{
public:
    Volunteer* CreateLeifeng()
    {
        return new Volunteer();
    }
};

#endif /* LeifengModel_hpp */
