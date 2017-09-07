//
//  Manager.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//

#include "Manager.hpp"
#include <iostream>
using namespace std;

Manager::Manager()
{
    graphics.push_back(new Graphic());
    cout << (*(graphics.front()))[0] << endl;
}
