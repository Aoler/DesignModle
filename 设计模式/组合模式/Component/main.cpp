//
//  main.cpp
//  Component
//
//  Created by Haitao on 11/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

/*
 二、概念
 组合模式（Composite）：将对象组合成树形结构以表示“部分-整体”的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。
 
 三、说明
 角色：
 （1）Component：为组合中的对象声明接口，在适当情况下，实现所有类共有接口的默认行为。声明一个接口用于访问和管理Component 的子部件。
 （2）Leaf：在组合中白哦是叶节点对象，叶节点没有子节点。
 （3）Composite：定义有枝节点行为，用来存储子部件，在Component接口中实现与子部件有关的操作，比如增加Add和删除Remove。
 什么时候使用组合模式？
 当你发现需求中是体现部分与整体层次的结构时，以及你希望用户可以忽略组合对象与单个对象的不同，统一地使用组合结构中的所有对象时，就应该考虑用组合模式了。
 使用组合模式的好处？
 （1）组合模式定义了包含基本对象（Leaf）和组合对象（Composite）的类层次结构。基本对象可以被组合成更复杂的组合对象，而这个组合对象又可以被组合，这样不断地地柜下去，客户代码中，任何用到基本对象的地方都可以使用组合对象了。
 （2）用户不用关心到底是处理一个叶子节点还是处理一个组合组件，也就不用为定义组合而写一些判断语句了。
 （3）简而言之，组合模式让客户可以一致的使用组合结构和单个对象。

*/




#include "Component.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    MenuComponent* pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "Breakfast");
    MenuComponent* dinerMenu = new Menu("Diner MENU", "Lunch");
    MenuComponent* dessertMenu = new Menu("DESSERT MENU","Dessert of coure!");
    
    MenuComponent* allMenus = new Menu("ALL Menus", "All menus combined");
    
    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    dinerMenu->add(new MenuItem("Pasta","Spaheti with Sauce", 3.89));
    
    dinerMenu->add(dessertMenu);
    dessertMenu->add(new MenuItem("Apple Pie", "App pie with a cruse", 1.59));
    
    Waitress* waitress = new Waitress(allMenus);
    waitress->printMenu();
    return 0;
}
