//
//  Builder.hpp
//  Builder
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef Builder_hpp
#define Builder_hpp

#include <string>
#include <vector>
#include <iostream>


//Product Class，产品类，有多个部件组成。
class Product
{
private:
    std::vector<std::string> parts;
public:
    //添加产品部件
    void Add(std::string part)
    {
        parts.push_back(part);
    }
    //列举所有的产品部件
    void Show()
    {
        std::cout<<"产品  创建------"<<std::endl;
        std::vector<std::string>::iterator it;
        for(it=parts.begin();it!=parts.end();it++)
        {
            std::cout<<*it<<std::endl;
        }
    }
};

//Builder，抽象建造者
class Builder
{
public:
    virtual void BuildPartA()=0;
    virtual void BuildPartB()=0;
    virtual Product* GetResult()=0;
};

//ConcreteBuilder1,具体建造者类
class ConcreteBuilder1:public Builder
{
private:
    Product* product;
public:
    ConcreteBuilder1()
    {
        product=new Product();
    }
    ~ConcreteBuilder1()
    {
        delete product;
    }
    void BuildPartA()
    {
        product->Add("部件A");
    }
    void BuildPartB()
    {
        product->Add("部件B");
    }
    Product* GetResult()
    {
        return product;
    }
};

//ConcreteBuilder2,具体建造者类
class ConcreteBuilder2:public Builder
{
private:
    Product* product;
public:
    ConcreteBuilder2()
    {
        product=new Product();
    }
    ~ConcreteBuilder2()
    {
        delete product;
    }
    void BuildPartA()
    {
        product->Add("部件X");
    }
    void BuildPartB()
    {
        product->Add("部件Y");
    }
    Product* GetResult()
    {
        return product;
    }
};

//Director Class，指挥者类。
class Director
{
public:
    void Construct(Builder* builder)
    {
        builder->BuildPartA();
        builder->BuildPartB();
    }
};

#endif /* Builder_hpp */
