//
//  Component.hpp
//  Component
//
//  Created by Haitao on 11/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class MenuComponent {
public:
    virtual void add(MenuComponent * menuComponent)
    {
        throw "add error!";
    }
    
    virtual void remove(MenuComponent* menuComponent)
    {
        throw "remove error!";
    }
    
    virtual MenuComponent* getChild(int i)
    {
        throw "getChild error";
    }
    
    virtual string getName()
    {
        throw "getName error";
    }
    
    virtual string getDescription()
    {
        throw "getDescription error";
    }
    
    virtual double getPrice()
    {
        throw "getPrice error";
    }
    
    virtual void print()
    {
        throw "print error";
    }
};


//菜单项类
class MenuItem : public MenuComponent
{
public:
    MenuItem(){}
    MenuItem(string na, string descrip, double pric)
    {
        name = na;
        description = descrip;
        price = pric;
    }
    
    string getName()
    {
        return name;
    }
    
    string getDescription()
    {
        return description;
    }
    
    double getPrice()
    {
        return price;
    }
    
    void print()
    {
        cout << " " << getName() << ",    " << getPrice()
        <<"   ---" << getDescription() << endl;
    }
private:
    string name;
    string description;
    double price;
};



//组合菜单类
class Menu : public MenuComponent
{
public:
    Menu(string nam, string descri)
    {
        name = nam;
        description = descri;
    }
    
    void add(MenuComponent* pMenuComponent)
    {
        pMenuComponents.push_back(pMenuComponent);
    }
    
    void remove(MenuComponent* pMenuComponent)
    {
        vector<MenuComponent*>::iterator iter = pMenuComponents.begin();
        for(; iter!=pMenuComponents.end(); ++iter)
        {
            if(*iter == pMenuComponent)
            {
                pMenuComponents.erase(iter);
            }
        }
    }
    
    MenuComponent* getChild(int i)
    {
        return pMenuComponents[i];
    }
    
    string getName()
    {
        return name;
    }
    
    string getDescription()
    {
        return description;
    }
    
    void print()
    {
        cout << endl << getName() << ",   " << getDescription() << endl << "--------------" << endl;
        vector<MenuComponent*>::iterator iter = pMenuComponents.begin();
        while(iter != pMenuComponents.end())
        {
            MenuComponent* pMenuComponent = *iter;
            pMenuComponent->print();
            ++iter;
        }
    }
private:
    vector<MenuComponent*> pMenuComponents;
    string name;
    string description;
};


//服务生类
class Waitress
{
public:
    Waitress(MenuComponent* all_Menus)
    {
        allMenus = all_Menus;
    }
    
    void printMenu()
    {
        allMenus->print();
    }
private:
    MenuComponent* allMenus;
};

#endif /* Component_hpp */
