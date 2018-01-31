//
//  Operation.hpp
//  FactoryMethod
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Operation_hpp
#define Operation_hpp

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
//下面是四个具体产品类
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

//抽象工厂类
class AbstractFactory
{
public:
    virtual Operation* createOperation()
    {
        return new Operation;
    }
};
//下面是四个具体工厂类，分别用于产生四个具体产品
class AddFactory:public AbstractFactory
{
public:
    Operation* createOperation()
    {
        Operation* oper=new OperationAdd;
        return oper;
    }
};

class SubFactory:public AbstractFactory
{
public:
    Operation* createOperation()
    {
        Operation* oper=new OperationSub;
        return oper;
    }
};

class MulFactory:public AbstractFactory
{
public:
    Operation* createOperation()
    {
        Operation* oper=new OperationMul;
        return oper;
    }
};

class DivFactory:public AbstractFactory
{
public:
    Operation* createOperation()
    {
        Operation* oper=new OperationDiv;
        return oper;
    }
};
#endif /* Operation_hpp */
