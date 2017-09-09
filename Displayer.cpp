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
GLFWwindow* Displayer::window = nullptr;

Displayer::Displayer() : title("Hello World"), windowWidth(1024), windowHeight(768)
{
    ;
//    glad_glGenVertexArrays(1, &VertexArrayID);
//    glad_glBindVertexArray(VertexArrayID);
}

Displayer& Displayer::initDisplayer()
{
    return *(new Displayer());
}

void Displayer::mainloop()
{
    if (!glfwInit())
        throw string("displayer init error");
    
    Displayer::window = glfwCreateWindow(windowWidth, windowHeight, title.c_str(), NULL, NULL);
    
    if (!Displayer::window)
    {
        glfwTerminate();
        throw string("displayer window create error");
    }

	glfwSetErrorCallback(Manager::errorCallback);

	glfwSetKeyCallback(Displayer::window, Manager::keyCallback);
    
    glfwMakeContextCurrent(Displayer::window);
    
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    while (!glfwWindowShouldClose(Displayer::window))
    {
		Manager::manager.render();

        glfwSwapBuffers(Displayer::window);
        
        glfwPollEvents();
    }
    
    glfwTerminate();
}
