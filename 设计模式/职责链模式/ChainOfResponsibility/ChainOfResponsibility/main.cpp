//
//  main.cpp
//  ChainOfResponsibility
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 二、概念
 职责链模式（Chain Of Responsibility）：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合。将这个对象连成一条链，并沿着这条链传递该请求，知道有一个对象处理它为止。
 
 三、说明
 角色：
 （1）Handler类：定义一个处理请求的接口。
 （2）ConcreteHandler类：具体的处理请求的接口。
 职责链模式的好处：
 （1）最关键的是，当客户提交一个请求时，请求时沿链传递直至有一个ConcreteHandler对象负责处理它。
 （2）接收者和发送者都没有对方的明确信息，且链中的对象自己也并不知道链的结构。结果是职责链可简化对象的相互连接，他们仅需要保持一个指向其后继者的引用，而不需要保持它所有的候选接收者的引用。
 （3）由于是在客户端来定义链的结构，所以用户可以随时地增加或者修改处理一个请求的结构。增强了给对象指派职责的灵活性。
 注意：一个请求极有可能到了链的末端都得不到处理，或者因为没有正确配置而得不到处理。
 
 
*/

#include "ChainOfResponsibility.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Manager* jinli=new CommonManager("金利");
    Manager* zongjian=new Majordomo("宗剑");
    Manager* zhongjingli=new GeneralManager("钟精励");
    
    //设置上级，完全可以按照实际需求来进行更改
    jinli->SetSuperior(zongjian);
    zongjian->SetSuperior(zhongjingli);
    
    //下面是4个请求
    //请求1：请假1天
    Request request1;
    request1.SetType("请假");
    request1.SetContent("小菜请假");
    request1.SetNumber(1);
    //客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道
    jinli->RequestApplication(&request1);
    
    //请求2：请假4天
    Request request2;
    request2.SetType("请假");
    request2.SetContent("小菜请假");
    request2.SetNumber(4);
    //客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道
    jinli->RequestApplication(&request2);
    
    //请求3：加薪500元
    Request request3;
    request3.SetType("加薪");
    request3.SetContent("小菜请求加薪");
    request3.SetNumber(500);
    //客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道
    jinli->RequestApplication(&request3);
    
    //请求4：加薪1000元
    Request request4;
    request4.SetType("加薪");
    request4.SetContent("小菜请求加薪");
    request4.SetNumber(1000);
    //客户端的申请都是由“经理”发起，但实际谁来决策由具体管理类来处理，客户端不知道
    jinli->RequestApplication(&request4);
    
    
    delete jinli,zongjian,zhongjingli;
    return 0;
}
