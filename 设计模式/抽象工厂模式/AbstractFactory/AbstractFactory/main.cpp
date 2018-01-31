//
//  main.cpp
//  AbstractFactory
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 二、概念
 抽象方法模式（Abstract Factory）：提供一个创建一系列相关或互相依赖对象的接口，而无需指定他们具体的类。
 
 三、包含的角色
 （1）抽象工厂
 （2）具体工厂：包括具体工厂1和具体工厂2。具体工厂1用于生产具体产品A1和具体产品B1，具体工厂2用于生产具体产品A2和具体产品B2；
 （3）抽象产品：包括抽象产品A和抽象产品B；
 （4）具体产品：包括抽象产品A所对应的具体产品A1和A2，以及抽象产品B所对应的具体产品B1和B2.
 说明：在《大话设计模式》中，上述的1和2分别代表Sqlserver数据库和Access数据库。上述的A和B分别代表数据库中的User表和Department表。
 
 四、优势
 （1）抽象工厂模式是对工厂方法模式的改进。用于处理产品不只有一类的情况（工厂方法模式下，产品只有User这一类，而抽象工厂模式下，产品包括User和Department两类）。
 （2）在以下情况下应当考虑使用抽象工厂模式：
 一个系统不应当依赖于产品类实例如何被创建、组合和表达的细节，这对于所有形态的工厂模式都是重要的。
 这个系统有多于一个的产品族，而系统只消费其中某一产品族。
 同属于同一个产品族的产品是在一起使用的，这一约束必须在系统的设计中体现出来。
 系统提供一个产品类的库，所有的产品以同样的接口出现，从而使客户端不依赖于实现。
 （3）解读：
 在上例中，产品族包括两个：1和2，也就是Sqlserver数据库和Access数据库。每个产品族里面又包含两类产品：A和B，也就是User表和Department表。而每个产品族中的产品要一起使用，就是说产品族1中的两类产品A和B要一起使用，也就是说在SqlServer数据库中SqlServerUser表和SqlServerDepartment表要一起使用，Access数据库同理。
 
 
*/

#include "Factory.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    User user;
    Department department;
    
    //ConcreteFactory1
    IFactory* factory=NULL;
    factory=new SqlserverFactory;
    
    //ProductA1
    IUser* iu=NULL;
    iu=factory->CreateUser();
    iu->Insert(user);
    iu->GetUser(1);
    
    //ProductB1
    IDepartment* id=NULL;
    id=factory->CreateDepartment();
    id->Insert(department);
    id->GetDepartment(1);
    
    if(factory!=NULL)
    {
        delete factory;
        factory=NULL;
    }
    if(iu!=NULL)
    {
        delete iu;
        iu=NULL;
    }
    if(id!=NULL)
    {
        delete id;
        id=NULL;
    }
    return 0;
}
