//
//  Displayer.hpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//
#ifndef Displayer_hpp
#define Displayer_hpp

#include "OSinfo.h"

class Displayer
{
private:
    static Displayer& initDisplayer();
    static void errorCallback(int error, const char* description);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static GLFWwindow* window;
    Displayer();
public:
    static Displayer& displayer;
    void mainloop();
};

#endif /* Displayer_hpp */
