//
//  Flyweight.hpp
//  Flyweight
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Flyweight_hpp
#define Flyweight_hpp

#include <iostream>
#include <string>
#include <map>

//用户类
class User
{
private:
    std::string name;
public:
    User(std::string name)
    {
        this->name=name;
    }
    std::string GetName()
    {
        return this->name;
    }
};

//Flyweight类，此处为抽象网站类
class WebSite
{
public:
    virtual void Use(User user)=0;
};

//ConcreteFlyweight类，此处为具体网站类
class ConcreteWebSite:public WebSite
{
private:
    std::string name;
public:
    ConcreteWebSite(std::string name)
    {
        this->name=name;
    }
    void Use(User user)
    {
        std::cout<<"网站分类："<<name<<"  用户："+user.GetName()<<std::endl;
    }
};

//FlyweightFactory类，此处为网站工程类
class WebSiteFactory
{
private:
    std::map<std::string,WebSite*> flyweights;
public:
    WebSiteFactory(){}
    ~WebSiteFactory()
    {
        std::map<std::string,WebSite*>::iterator it;
        
        for(it=flyweights.begin();it!=flyweights.end();it++)
            delete it->second;
    }
    WebSite* GetWebSiteCategory(std::string key)
    {
        std::map<std::string,WebSite*>::iterator it;
        
        for(it=flyweights.begin();it!=flyweights.end();it++)
            if(it->first==key)
                return it->second;
        
        WebSite* website=new ConcreteWebSite(key);
        flyweights.insert(std::pair<std::string,WebSite*>(key,website));
        return website;
    }
    int GetWebSiteCount()
    {
        return flyweights.size();
    }
};

#endif /* Flyweight_hpp */
