//
//  main.cpp
//  Command
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 二、概念
 命令模式（Command）：将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化，对请求进行排队或记录请求日志，以及支持可撤销的操作。
 
 三、说明
 角色：
 （1）Command类：用来声明执行操作的接口。
 （2）ConcreteCommand类：将一个接收者对象绑定与一个动作，调用接收者相应的操作，以实现Excute。
 （3）Invoker类：要求该命令执行这个请求。
 （4）Receiver类：知道如何实施与执行一个与请求相关的操作，任何类都可能作为一个接收者。
 命令模式的作用？
 （1）命令模式能够较容易地设计一个命令队列。
 （2）在需要的情况下，可以较容易地将命令记入日志。
 （3）允许接收请求的一方决定是否要否决请求。
 （4）可以容易地实现对请求的撤销和重做。
 （5）由于加进新的具体命令类不影响其他的类，因此增加新的具体命令类很容易。
 （6）命令模式把请求一个操作的对象与知道怎么执行一个操作的对象分隔开。
 
*/

#include "Command.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Barbecuer* boy=new Barbecuer();
    
    Command* bakeMuttonCommand1=new BakeMuttonCommand(boy);
    Command* bakeMuttonCommand2=new BakeMuttonCommand(boy);
    Command* bakeChickenWingCommand1=new BakeChickenWingCommand(boy);
    
    Waiter* girl=new Waiter();
    
    //开门营业，顾客点菜
    girl->SetOrder(bakeMuttonCommand1);
    girl->SetOrder(bakeMuttonCommand2);
    girl->SetOrder(bakeChickenWingCommand1);
    
    //点菜完毕，通知厨房
    girl->Notify();
    
    delete boy,bakeMuttonCommand1,bakeMuttonCommand2,bakeChickenWingCommand1;
    return 0;
}
