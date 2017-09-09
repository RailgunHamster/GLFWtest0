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
GLchar* Displayer::vertexShaderSource = new GLchar[200];

Displayer::Displayer() : window(nullptr), title("Hello World"), windowWidth(800), windowHeight(600)
{
    ;
}

Displayer& Displayer::initDisplayer()
{
    vertexShaderSource = "#version 410 core\nlayout (location = 0) in vec3 position;\nvoid main()\n{\ngl_Position = vec4(position.x, position.y, position.z, 1.0);\n}";
    
    Displayer& d = *(new Displayer());
    
    if (!glfwInit())
        throw string("displayer init error");
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    d.window = glfwCreateWindow(d.windowWidth, d.windowHeight, d.title.c_str(), nullptr, nullptr);
    
    if (!d.window)
    {
        glfwTerminate();
        throw string("displayer window create error");
    }
    
    glfwSetErrorCallback(Manager::errorCallback);
    
    glfwSetKeyCallback(d.window, Manager::keyCallback);
    
    glfwMakeContextCurrent(d.window);
    
//    cout << glad_glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    glad_glGenBuffers(1, &d.VBO);
    glad_glBindBuffer(GL_ARRAY_BUFFER, d.VBO);
    
    Manager::manager.bufferData();
    
    d.vertexShader = glad_glCreateShader(GL_VERTEX_SHADER);
    glad_glShaderSource(d.vertexShader, 1, &vertexShaderSource, nullptr);
    glad_glCompileShader(d.vertexShader);
    
    GLint success;
    GLchar infoLog[512];
    glad_glGetShaderiv(d.vertexShader, GL_COMPILE_STATUS, &success);
    
    cout << glad_glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    
    if (!success)
    {
        glad_glGetShaderInfoLog(d.vertexShader, 512, nullptr, infoLog);
        throw string("shader compile error\n") + infoLog;
    }
    
    return d;
}

void Displayer::mainloop()
{
    while (!glfwWindowShouldClose(Displayer::window))
    {
        glfwPollEvents();
        
        Manager::manager.render();

        glfwSwapBuffers(Displayer::window);
    }
    
    glfwTerminate();
}
