//
//  Observer.hpp
//  observer
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <list>
#include <iostream>
#include <string>
#include "Subject.hpp"

//Observer,抽象观察者
class Observer
{
protected:
    std::string name;
    Subject* sub;
public:
    Observer();
    Observer(std::string name,Subject* sub);
    virtual void Update();
    bool operator==(const Observer&)const;
};

//ConcreteObserver,具体观察者，股票观察者
class StockObserver:public Observer
{
public:
    StockObserver();
    StockObserver(std::string name,Subject* sub);
    void Update();
};


//ConcreteObserver，具体观察者，NBA观察者
class NBAObserver:public Observer
{
public:
    NBAObserver();
    NBAObserver(std::string name,Subject* sub);
    void Update();
};


#endif /* Observer_hpp */
