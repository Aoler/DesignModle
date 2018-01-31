//
//  factory.hpp
//  simpleFactory
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 
 二、包含的角色
 简单工厂模式包含三个角色：
 （1）工厂类Factory：工厂类是用来制造产品的。因此，在Factory中有一个用于制造产品的Create函数或者Generate函数之类的函数。这个函数能够根据“标识符”的不同生成不同的ConcreteProduct，当然这些ConcreteProduct都是继承自AbstractProduct的。
 （2）抽象产品类AbstractProduct：抽象产品是从其他具体产品抽象出来的。抽象产品类只有一个。
 （3）具体产品类ConcreteProduct：具体产品类继承自抽象产品类，可以有多个。当需要增加新的产品的时候就增加一个继承自抽象产品类的具体产品类即可。
 三、优势：
 实现了松耦合，当需要增加一种新产品（在大话设计模式中，例子是 运算Operation），只需要做两点改动：
 （1）增加一个继承自抽象产品（抽象的运算）的具体产品（一种具体的运算）；
 （2）在工厂类中，switch中，增加一种根据标识符产生新运算的case即可。
 

*/


#ifndef factory_hpp
#define factory_hpp

#include <iostream>
#include <cstdlib>

using namespace std;

//抽象产品类
class Operation
{
protected:
    double numberA;
    double numberB;
    
public:
    double getA()
    {
        return numberA;
    }
    double getB()
    {
        return numberB;
    }
    void setA(double number)
    {
        numberA=number;
    }
    void setB(double number)
    {
        numberB=number;
    }
    
    virtual double GetResult()
    {
        double result=0;
        return result;
    }
};

//下面是四种具体产品类
class OperationAdd:public Operation
{
public:
    double GetResult()
    {
        double result=0;
        result=numberA+numberB;
        return result;
    }
};

class OperationSub:public Operation
{
public:
    double GetResult()
    {
        double result=0;
        result=numberA-numberB;
        return result;
    }
};

class OperationMul:public Operation
{
public:
    double GetResult()
    {
        double result=0;
        result=numberA*numberB;
        return result;
    }
};

class OperationDiv:public Operation
{
public:
    double GetResult()
    {
        double result=0;
        if(numberB!=0)
            result=numberA/numberB;
        return result;
    }
};

//工厂类
class OperationFactory
{
public:
    Operation* createOperation(char type)
    {
        Operation* oper;
        switch(type)
        {
            case '+':
                oper=new OperationAdd;
                break;
            case '-':
                oper=new OperationSub;
                break;
            case '*':
                oper=new OperationMul;
                break;
            case '/':
                oper=new OperationDiv;
                break;
        }
        return oper;  
    }  
};

#endif /* factory_hpp */
