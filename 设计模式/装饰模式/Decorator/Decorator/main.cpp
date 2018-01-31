//
//  main.cpp
//  Decorator
//
//  Created by Haitao on 12/10/17.
//  Copyright © 2017年 mess. All rights reserved.
//
#include "Decorator.hpp"
#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    Person* xc=NULL;
    xc=new Person("小菜");
    
    std::cout<<"第一种装扮："<<std::endl;
    
    Sneakers* pqx=NULL;
    pqx=new Sneakers();
    BigTrouser* kk=NULL;
    kk=new BigTrouser();
    TShirts* dtx=NULL;
    dtx=new TShirts();
    
    pqx->Decorator(xc);
    kk->Decorator(pqx);
    dtx->Decorator(kk);
    
    dtx->Show();
    
    std::cout<<"第二种装扮："<<std::endl;
    
    LeatherShoes* px=NULL;
    px=new LeatherShoes();
    Tie* ld=NULL;
    ld=new Tie();
    Suit* xz=NULL;
    xz=new Suit();
    
    px->Decorator(xc);
    ld->Decorator(px);
    xz->Decorator(ld);
    
    xz->Show();
    
    if(xc!=NULL)
    {
        delete xc;
        xc=NULL;
    }
    if(pqx!=NULL)
    {
        delete pqx;
        pqx=NULL;
    }
    if(kk!=NULL)
    {
        delete kk;
        kk=NULL;
    }
    if(dtx!=NULL)
    {
        delete dtx;
        dtx=NULL;
    }
    if(px!=NULL)
    {
        delete px;
        px=NULL;
    }
    if(ld!=NULL)
    {
        delete ld;
        ld=NULL;
    }
    if(xz!=NULL)
    {
        delete xz;
        xz=NULL;
    }  
    return 0;
}
