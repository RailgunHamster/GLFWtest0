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
    Displayer();
    //friend
    friend class Manager;
	//data
    GLuint VBO;
    GLuint VAO;
    GLuint EBO;
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
    static GLchar *vertexShaderSource;
    static GLchar *fragmentShaderSource;
public:
    static Displayer& displayer;
    void mainloop();
    //data
    GLFWwindow* window;
    GLint windowWidth;
    GLint windowHeight;
    string title;
};

#endif /* Displayer_hpp */
