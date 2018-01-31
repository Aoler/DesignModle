//
//  main.cpp
//  Memento
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 一、UML图
 
 关键词：备份内容到Memento，用的时候再从Memento中取出来，Caretaker负责管理这些操作。
 
 二、概念
 备忘录（Memento）：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可将对象恢复到原先保存的状态。
 
 三、说明
 角色：
 （1）Originator（发起人）：负责创建一个Memento，用以记录当前时刻它的内部状态，并可以使用备忘录恢复内部状态。Originator可以根据需要决定Memento存储Originator的哪些内部状态。
 （2）Memento（备忘录）：负责存储Originator对象的内部状态，并可以防止Originator以外的其他对象访问备忘录Memento。备忘录有两个接口，Caretaker只能看到备忘录的窄接口，他只能将备忘录传递给其他对象。Originator能够看到一个宽接口，允许它访问先前状态所需的所有数据。
 （3）Caretaker（管理者）：负责保存包备忘录Memento，不能对备忘录的内容进行操作或检查。
 什么时候用？
 Memento模式比较适用于功能比较复杂的，但需要维护或记录属性历史的类，或者需要保存的属性只是众多属性中的一小部分时，Originator可以根据保存的Memento信息还原到迁移状态。
 与命令模式的关系？
 如果在某个系统中使用命令模式时，需要实现命令的撤销功能，那么命令模式可以使用备忘录模式来存储可撤销操作的状态。
 
 
*/

#include "Memento.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    //大战Boss前
    GameRole* lixiaoyao=new GameRole();
    lixiaoyao->GetInitState();
    lixiaoyao->StateDisplay();
    
    //保存进度
    RoleStateCaretaker* stateAdmin=new RoleStateCaretaker();
    stateAdmin->SetMemento(lixiaoyao->SaveState());
    
    //大战Boss时，损耗严重
    lixiaoyao->Fight();
    lixiaoyao->StateDisplay();
    
    //恢复之前状态
    lixiaoyao->RocoveryState(*stateAdmin->GetMemento());
    lixiaoyao->StateDisplay();
    
    delete lixiaoyao;
    delete stateAdmin;

    return 0;
}
