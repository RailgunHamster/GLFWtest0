//
//  main.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//
#include "Displayer.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    try
    {
        Displayer::displayer.mainloop();
    }
    catch (string errorInfo)
    {
        cerr << errorInfo << endl;
    }
    return 0;
}
