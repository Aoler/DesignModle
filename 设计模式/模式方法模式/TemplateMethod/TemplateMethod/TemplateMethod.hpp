//
//  TemplateMethod.hpp
//  TemplateMethod
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//

#ifndef TemplateMethod_hpp
#define TemplateMethod_hpp

#include <iostream>
#include <string>

//AbstractClass，实现了一个模板，定义了算法的骨架，组成骨架的具体步骤放在子类中实现
class TestPaper
{
public:
    void TestQuestion1()
    {
        std::cout<<"杨过得到，后来给了郭靖，练成倚天剑、屠龙刀的玄铁可能是【】a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维"<<std::endl;
        std::cout<<"答案："<<Answer1()<<std::endl;
    }
    void TestQuestion2()
    {
        std::cout<<"杨过、程英、陆无双铲除了情花，造成【】a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化"<<std::endl;
        std::cout<<"答案："<<Answer2()<<std::endl;
    }
    void TestQuestion3()
    {
        std::cout<<"蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药【】a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量牛奶"<<std::endl;
        std::cout<<"答案："<<Answer3()<<std::endl;
    }
protected:
    virtual std::string Answer1()
    {
        return "";
    }
    virtual std::string Answer2()
    {
        return "";
    }
    virtual std::string Answer3()
    {
        return "";
    }
};

//ConcreteClass，实现具体步骤
class TestPaperA:public TestPaper
{
protected:
    virtual std::string Answer1()
    {
        return "b";
    }
    virtual std::string Answer2()
    {
        return "c";
    }
    virtual std::string Answer3()
    {
        return "a";
    }
};

//ConcreteClass，实现具体步骤
class TestPaperB:public TestPaper
{
protected:
    virtual std::string Answer1()
    {
        return "c";
    }
    virtual std::string Answer2()
    {
        return "a";
    }
    virtual std::string Answer3()
    {
        return "a";
    }
};

#endif /* TemplateMethod_hpp */
