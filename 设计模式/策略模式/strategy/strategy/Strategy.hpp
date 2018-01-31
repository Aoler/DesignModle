//
//  strategy.hpp
//  strategy
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
二、概念
策略模式：他定义了算法家族，分别封装起来，让他们之间可以互相替换，此模式让算法的变化，不会影响到使用算法的客户。

三、优点
（1）策略模式是一种定义一系列算法的方法，从概念上来看，所有这些算法完成的都是相同的工作，只是实现不同，他可以以相同的方式调用所有的算法，减少了各种算法类与使用算法类之间的耦合。
（2）策略模式的Strategy类曾是为Context定义了一些列的可供重用的算法或行为。集成有助于析取出这些算法中的公共功能。
（3）策略模式简化了单元测试，因为每个算法都有自己的类，可以通过自己的接口单独测试。
（4）策略模式就是用来封装算法的。
（5）只要在分析过程中听到需要在不同时间应用不同的业务规则，就可以考虑使用策略模式处理这种变化的可能性。
（6）简单工厂模式需要让客户端认识两个类，而策略模式和简单工厂模式结合的用法，客户端只需要认识一个类Context即可。

*/
 
#ifndef strategy_hpp
#define strategy_hpp

#include <string>
#include <math.h>

//父类抽象类
class CashSuper
{
public:
    virtual double acceptCash(double money)=0;
};

//子类：正常付费类型
class CashNormal:public CashSuper
{
public:
    double acceptCash(double money)
    {
        return money;
    }
};

//子类：返现类型
class CashReturn:public CashSuper
{
private:
    double moneyCondition;
    double moneyReturn;
public:
    CashReturn(double moneyCondition,double moneyReturn)
    {
        this->moneyCondition=moneyCondition;
        this->moneyReturn=moneyReturn;
    }
    double acceptCash(double money)
    {
        double result=money;
        if(money>moneyCondition)
            result=money-floor(money/moneyCondition)*moneyReturn;
        return result;
    }
};

//子类：打折扣类型
class CashRebate:public CashSuper
{
private:
    double moneyRebate;
public:
    CashRebate(double moneyRebate)
    {
        this->moneyRebate=moneyRebate;
    }
    double acceptCash(double money)
    {
        return money*moneyRebate;
    }
};

#endif /* strategy_hpp */
