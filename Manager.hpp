//
//  Manager.hpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//

#ifndef Manager_hpp
#define Manager_hpp
#include <list>
using namespace std;
#include "Graphic.hpp"

class Manager
{
private:
    list<Graphic*> graphics;
public:
    Manager();
};

#endif /* Manager_hpp */
