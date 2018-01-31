//
//  main.cpp
//  Mediator
//
//  Created by Haitao on 13/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 二、概念
 中介者模式（Mediator）：用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显示地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。
 
 三、说明
 角色：
 （1）Colleague：抽象同事类。
 （2）ConcreteClleague：具体同事类，每个具体同事只知道自己的行为，而不了解其他同事类的情况，但它们却都认识中介者对象。
 （3）Mediator：抽象中介者，定义了同事对象到中介者对象的接口。
 （4）ConcreteMediator：具体中介者对象，实现抽象类的方法，它需要知道所有具体同事类，并从具体同事接收消息，向具体同事对象发出命令。
 中介者模式的优点？
 （1）Mediator的出现减少了各个Colleague的耦合，使得可以独立地改变和复用各个Colleague，比如任何国家的改变不会影响到其他国家，而只是与安理会发生变化。
 （2）由于把对象如何协作进行了抽象，将中介作为一个独立的概念并将其封装起在一个对象中，这样关注的对象就从对象各自本身的行为转移到他们之间的交互上来，也就是站在一个更宏观的角度去看待系统。
 中介者模式的缺点？
 由于ConcreteMediator控制了集中化，于是就把交互复杂性变为了中介者的复杂性，这就使得中介者会变得比任何一个ConcreteColleague都复杂。
 中介者模式的用途？
 中介者模式一般应用于一组对象以定义良好但是复杂的方式进行通信的场合，以及想定制一个分布在多个类中的行为，而又不想生成太多的子类的场合。
 
*/

#include "Country.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    UnitedNationsSecurityCouncil *us=new UnitedNationsSecurityCouncil;
    USA *usa=new USA(us);
    Iraq *iraq=new Iraq(us);
    
    us->setColleague1(usa);
    us->setColleague2(iraq);
    
    usa->Declare("不准研制核武器，否则发动战争");
    iraq->Declare("我们没有核武器，也不怕侵略");
    
    
    
    return 0;
}
