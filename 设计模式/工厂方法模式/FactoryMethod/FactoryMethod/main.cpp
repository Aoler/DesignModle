//
//  main.cpp
//  FactoryMethod
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//


/*
 二、概念
 工厂方法模式（Factory Method）：定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法是一个类的实例化延迟到其子类。
 
 三、包含的角色
 （1）抽象工厂
 （2）具体工厂
 （3）抽象产品
 （4）具体产品
 
 四、优势
 （1）工厂方法模式是对简单工厂模式的稍微的改进。工厂方法模式的用意是定义一个创建产品对象的工厂接口，将实际工作推迟到子类中。
 （2）与简单工厂模式相比，制造产品的工厂类不再 只有一个，而是每种具体产品类都对应一个生产它的具体工厂类。而这些具体工厂类的共同特征再被提取出来形成一个抽象产品类，这些具体产品类都继承自这个抽象产品类。
 （3）当需要增加一种产品的时候，需要做的是：增加一种继承自抽象产品的具体产品类，增加一种继承在抽象工厂的具体工厂类，更改客户端。而不需要在简单工厂模式中那样更改工厂内的switch。
 
*/

#include "LeifengModel.hpp"
//#include "Operation.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
//    AbstractFactory* af=NULL;
//    af=new AddFactory();
//    
//    Operation* oper=NULL;
//    oper=af->createOperation();
//    
//    oper->setA(1);
//    oper->setB(2);
//    cout<<oper->GetResult()<<endl;
//    
//    if(af!=NULL)
//    {
//        delete af;
//        af=NULL;
//    }
//    if(oper!=NULL)
//    {
//        delete oper;
//        oper=NULL;
//    }
    
    //想要生产Volunteer产品的话，只需要将此处的UndergraduateFactory更改为VolunteerFactory即可。
    AbstractFactory* af=NULL;
    af=new UndergraduateFactory;
    
    Leifeng* lf=NULL;
    lf=af->CreateLeifeng();
    
    lf->BuyRice();
    lf->Sweep();
    lf->Wash();
    
    if(af!=NULL)
    {
        delete af;
        af=NULL;
    }
    if(lf!=NULL)
    {
        delete lf;
        lf=NULL;
    }
    return 0;
}
