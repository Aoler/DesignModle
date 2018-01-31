//
//  status.hpp
//  status
//
//  Created by Haitao on 11/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef status_hpp
#define status_hpp

/*
 模式定义
 状态模式允许对象在内部状态改变时改变它的行为，对象看起来好像修改了它的类。
 
 举例：
 一个工人一天的时间分为上班，睡觉，干其他事情三个时间段。我们可以用状态模式来表示一天中在干什么事情。
 
*/

#include <iostream>
using namespace std;


class Worker;   //类的前置声明

//状态类
class State
{
public:
    virtual void doing(Worker* w){}
};
//工作状态
class WorkingState: public State
{
public:
    void doing(Worker* worker);
};
//休息状态
class SleepingState: public State
{
public:
    void doing(Worker* worker);
};
//其他状态
class OtherState : public State
{
public:
    void doing(Worker* worker);
};

//工人类
class Worker
{
public:
    Worker()
    {
        state = new WorkingState();
    }
    void setState(State* stat)
    {
        state = stat;
    }
    double getHour()
    {
        return hour;
    }
    void setHour(double hou)
    {
        hour = hou;
    }
    
    void requestDoing()
    {
        state->doing(this);
    }
private:
    State* state;
    double hour;
};
//各个状态doing方法的实现
void WorkingState::doing(Worker* worker)
{
    if(worker->getHour() > 8 && worker->getHour()  < 16)
        cout << "WorkingState!" << endl;
    else
    {
        worker->setState(new OtherState());
        worker->requestDoing();
    }
}

void SleepingState::doing(Worker* worker)
{
    if(worker->getHour()  >= 21 || worker->getHour()  < 5)
        cout << "SleepingState!" << endl;
    else
    {
        worker->setState(new OtherState());
        worker->requestDoing();
        
    }
}

void OtherState::doing(Worker* worker)
{
    if((worker->getHour() >= 5 && worker->getHour() < 8)
       || (worker->getHour() >= 16 && worker->getHour() < 21))
        cout << "SleepingState!" << endl;
    else if(worker->getHour() >= 21 || worker->getHour() < 5)
    {
        worker->setState(new SleepingState());
        worker->requestDoing();
    }
    else
    {
        worker->setState(new WorkingState());
        worker->requestDoing();
    }
}

#endif /* status_hpp */
