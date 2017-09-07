//
//  Displayer.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//
#include "Displayer.hpp"
#include <iostream>
#include <string>
using namespace std;

Displayer& Displayer::displayer = Displayer::initDisplayer();
GLFWwindow* Displayer::window = nullptr;

Displayer::Displayer()
{
    ;
}

Displayer& Displayer::initDisplayer()
{
    return *(new Displayer());
}

void Displayer::errorCallback(int error, const char* description)
{
    cerr << "error NO." << error << " : " << description << endl;
}

void Displayer::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Displayer::mainloop()
{
    if (!glfwInit())
        throw string("displayer init error");
    
    Displayer::window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    
    if (!Displayer::window)
    {
        glfwTerminate();
        throw string("displayer window create error");
    }

	glfwSetErrorCallback(Displayer::errorCallback);

	glfwSetKeyCallback(Displayer::window, Displayer::keyCallback);
    
    glfwMakeContextCurrent(Displayer::window);
    
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    while (!glfwWindowShouldClose(Displayer::window))
    {
        //render
        glClear(GL_COLOR_BUFFER_BIT);
		//
        
        glfwSwapBuffers(Displayer::window);
        
        glfwPollEvents();
    }
    
    glfwTerminate();
}
