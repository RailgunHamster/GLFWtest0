//
//  Displayer.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//
#include "Displayer.hpp"
#include "Manager.hpp"
#include <iostream>
#include <string>
using namespace std;

Displayer& Displayer::displayer = Displayer::initDisplayer();

Displayer::Displayer() : window(nullptr), title("Hello World"), windowWidth(1024), windowHeight(768)
{
    ;
//    glad_glGenVertexArrays(1, &VertexArrayID);
//    glad_glBindVertexArray(VertexArrayID);
}

Displayer& Displayer::initDisplayer()
{
    Displayer& d = *(new Displayer());
    
    if (!glfwInit())
        throw string("displayer init error");
    
    d.window = glfwCreateWindow(d.windowWidth, d.windowHeight, d.title.c_str(), NULL, NULL);
    
    if (!d.window)
    {
        glfwTerminate();
        throw string("displayer window create error");
    }
    
    glfwSetErrorCallback(Manager::errorCallback);
    
    glfwSetKeyCallback(d.window, Manager::keyCallback);
    
    glfwMakeContextCurrent(d.window);
    
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    return d;
}

void Displayer::mainloop()
{
    while (!glfwWindowShouldClose(Displayer::window))
    {
		Manager::manager.render();

        glfwSwapBuffers(Displayer::window);
        
        glfwPollEvents();
    }
    
    glfwTerminate();
}
