//
//  main.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//
#include "Manager.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    try
    {
		Manager::manager.mainloop();
    }
    catch (string error)
    {
        cerr << error << endl;
    }
    return 0;
}
