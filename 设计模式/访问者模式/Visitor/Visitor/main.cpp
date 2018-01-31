//
//  main.cpp
//  Visitor
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//


/*
 二、概念
 访问者模式（Visitor）：表示一个作用于某对象结构中的各元素的操作。它是你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。
 
 三、说明
 （1）访问者模式适用于数据结构相对稳定的系统？
 是的。它把数据结构和作用于数据结构上的操作之间的耦合解脱开，使得操作集合可以相对自由地演化。
 （2）访问者模式的目的？
 访问者模式的目的是要把处理从数据结构分离出来。很多系统可以按照算法和数据机构分开，如果这样的系统有比较稳定的数据结构，又有易于变化的算法的话，使用访问者模式就是比较合适的，因为访问者模式使得算法操作的增加变得容易。反之，如果这样的系统的数据结构对象易于变化，经常要有新的数据对象增加进来，就不适合使用访问者模式。
 （3）访问者模式的优点？
 优点是增加新的操作很容易，因为增加新的操作就意味着增加一个新的访问者。访问者模式将有关的行为集中到一个访问者对象中。
 （4）访问者模式的缺点？
 缺点其实也就是使得增加新的数据结构变得困难了。
 （5）GoF四人中的一人说过：“大多数时候你并不需要访问者模式，但当一旦你需要访问者模式时，那就是真的需要它了”。
 （6）访问者模式包含哪些角色？
 Visitor类，为该对象结构中ConcreteElement的每一个类声明一个Visit操作。
 ConcreteVisitor类：具体访问者，实现每个由Visitor声明的操作。
 Element类：定义一个Accept操作，它以一个访问者为参数。
 ConcreteElementA类：具体元素，实现Accept操作。
 ObjectStructure类：能枚举它的元素，可以提供一个高层的接口以允许访问者访问它的元素。
 
*/


#include "ObjectStructure.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    ObjectStructure o;
    
    o.Attach(new Man());
    o.Attach(new Woman());
    
    Success v1;
    o.Display(&v1);
    
    Failing v2;
    o.Display(&v2);
    
    Amativeness v3;
    o.Display(&v3);
    return 0;
}
