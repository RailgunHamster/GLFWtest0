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
#include <string>
using namespace std;

class Displayer
{
private:
    //func
    static Displayer& initDisplayer();
    static void errorCallback(int error, const char* description);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static GLFWwindow* window;
    Displayer();
    //data
    GLuint VertexArrayID;
public:
    static Displayer& displayer;
    void mainloop();
    //data
    GLint windowWidth;
    GLint windowHeight;
    string title;
};

#endif /* Displayer_hpp */
