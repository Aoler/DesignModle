//
//  main.cpp
//  facade
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 关键词：增加Facade层。
 
 二、概念
 外观模式：为子系统中的一组接口提供一个一致的界面，此模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。
 
 三、说明
 Q：外观模式在什么时候使用呢？
 A：分为三个阶段：
 （1）首先，在设计初期阶段，应该要有意识的将不同的两个层分离。
 （2）第二，在开发阶段，子系统往往因为不断的重构演化而变得越来越复杂，大多数的模式使用时也会产生很多很小的类，这本是好事儿，但是也给外部调用他们的用户程序带来了使用上的困难，增加外观Facade可以提供一个简单的接口，减少他们之间的依赖。
 （3）第三，在维护一个遗留的大型系统时，可能这个系统已经非常难以维护和扩展了，但因为它包含非常重要的功能，新的需求开发必须要依赖于它。此时用外观模式Facade也是非常合适的。
 
 具体而言：为新系统开发一个外观Facade类，来提供设计粗糙或高度复杂的遗留代码的比较清晰简单的接口，让新系统与Facade对象交互，Facade与遗留代码交互所有复杂的工作。
 
 好处是显而易见的，如下图所示：
 
*/

#include "Facade.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Facade* facade=new Facade();
    
    facade->MethodA();
    facade->MethodB();
    
    delete facade;
    return 0;
}
