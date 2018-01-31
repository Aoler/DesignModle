//
//  main.cpp
//  Builder
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//


/*
 二、概念
 建造者模式（Builder）：将一个复杂对象的构建和它的表示分离，使得同样的构建过程可以创建不同的表示。
 
 三、说明
 角色：
 （1）Builder：是为创建一个Product对象的各个部件指定的抽象接口。
 （2）ConcreteBuilder：是具体创建者，实现Builder接口，构造和装配各个部件。
 （3）Product：具体的产品角色。
 （4）Director：指挥者，他是构建一个使用Builder接口的对象。
 Q：什么时候使用建造者模式？
 A：它主要是用于创建一些复杂的对象，这些对象内部构造间的建造顺序通常是稳定的，但对象内部的构建通常面临着复杂的变化。
 Q：使用建造者模式的好处？
 A：建造者模式的好处就是使得建造代码与表示代码分离，由于建造者隐藏了 该产品是如何组装的，所以若需要改变一个产品的内部表示，只需要再定义一个具体的建造者就可以了。
 

*/

#include "Builder.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Director* director=new Director();
    
    Builder* builder1=new ConcreteBuilder1();
    Builder* builder2=new ConcreteBuilder2();
    
    std::cout<<"指挥者用ConcreteBuilder1的方法建造产品："<<std::endl;
    director->Construct(builder1);
    Product* p1=builder1->GetResult();
    p1->Show();
    std::cout<<std::endl;
    
    std::cout<<"指挥者用ConcreteBuilder2的方法建造产品："<<std::endl;
    director->Construct(builder2);
    Product* p2=builder2->GetResult();
    p2->Show();
    std::cout<<std::endl;
    
    delete director;
    delete builder1;
    delete builder2;
    return 0;
}
