//
//  Command.hpp
//  Command
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

//Receiver：此处为烤羊肉串者
class Barbecuer
{
public:
    void BakeMutton()
    {
        std::cout<<"烤羊肉串！"<<std::endl;
    }
    void BakeChickenWing()
    {
        std::cout<<"烤鸡翅！"<<std::endl;
    }
};

//Command类，抽象命令
class Command
{
protected:
    Barbecuer* receiver;
public:
    Command(Barbecuer* receiver)
    {
        this->receiver=receiver;
    }
    virtual void ExcuteCommand()=0;
};

//ConcreteCommand类，具体命令
class BakeMuttonCommand:public Command
{
public:
    BakeMuttonCommand(Barbecuer* receiver):Command(receiver){}
    void ExcuteCommand()
    {
        receiver->BakeMutton();
    }
};

//ConcreteCommand类，具体命令
class BakeChickenWingCommand:public Command
{
public:
    BakeChickenWingCommand(Barbecuer* receiver):Command(receiver){}
    void ExcuteCommand()
    {
        receiver->BakeChickenWing();
    }
};

//Invoker：此处为Waiter服务员
class Waiter
{
private:
    std::vector<Command*> *orders;
public:
    Waiter()
    {
        orders=new std::vector<Command*>;
    }
    ~Waiter()
    {
        delete orders;
    }
    
    //设置订单
    void SetOrder(Command* command)
    {
        //判断命令的类型并分别做不同的处理
        if(typeid(*command)==typeid(BakeChickenWingCommand))
        {
            std::cout<<"日志：服务员：鸡翅没有了，请点别的烧烤！"<<std::endl;
        }
        else if(typeid(*command)==typeid(BakeMuttonCommand))
        {
            orders->push_back(command);
            
            time_t now=time(0);
            std::cout<<"日志：增加订单：命令模式.烤羊肉串  "<<"时间："<<asctime(gmtime(&now));
        }
        else
        {
            std::cout<<"日志：暂时没有该服务！"<<std::endl;
        }
    }
    
    //通知全部执行
    void Notify()
    {
        std::vector<Command*>::iterator it;
        for(it=orders->begin();it!=orders->end();it++)
        {
            (*it)->ExcuteCommand();
        }
    }
};

#endif /* Command_hpp */
