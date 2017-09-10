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
GLchar* Displayer::fragmentShaderSource = new GLchar[200];

Displayer::Displayer() : window(nullptr), title("Hello World"), windowWidth(800), windowHeight(600)
{
    ;
}

Displayer& Displayer::initDisplayer()
{
    //source
    vertexShaderSource = "#version 410 core\n\
        layout (location = 0) in vec3 position;\n\
        void main()\n\
        {\n\
            gl_Position = vec4(position.x, position.y, position.z, 1.0);\n\
        }";
    
    fragmentShaderSource = "#version 410 core\n\
        out vec4 color;\n\
        void main()\n\
        {\n\
            color = vec4(1.0, 0.5, 0.2, 1.0);\n\
        }";
    
    //
    Displayer& d = *(new Displayer());
    
    if (!glfwInit())
        throw string("displayer init error");
    
    //
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    //
    d.window = glfwCreateWindow(d.windowWidth, d.windowHeight, d.title.c_str(), nullptr, nullptr);
    
    if (!d.window)
    {
        glfwTerminate();
        throw string("displayer window create error");
    }
    
    glfwSetErrorCallback(Manager::errorCallback);
    
    glfwSetKeyCallback(d.window, Manager::keyCallback);
    
    glfwMakeContextCurrent(d.window);
    
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    //
    d.vertexShader = glad_glCreateShader(GL_VERTEX_SHADER);
    glad_glShaderSource(d.vertexShader, 1, &vertexShaderSource, nullptr);
    glad_glCompileShader(d.vertexShader);
    
    d.fragmentShader = glad_glCreateShader(GL_FRAGMENT_SHADER);
    glad_glShaderSource(d.fragmentShader, 1, &fragmentShaderSource, nullptr);
    glad_glCompileShader(d.fragmentShader);
    
    GLint success;
    GLchar infoLog[512];
    glad_glGetShaderiv(d.vertexShader, GL_COMPILE_STATUS, &success);
    
    if (!success)
    {
        glad_glGetShaderInfoLog(d.vertexShader, 512, nullptr, infoLog);
        throw string("shader compile error\n") + infoLog;
    }
    
    d.shaderProgram = glad_glCreateProgram();
    
    glad_glAttachShader(d.shaderProgram, d.vertexShader);
    glad_glAttachShader(d.shaderProgram, d.fragmentShader);
    glad_glLinkProgram(d.shaderProgram);
    
    glad_glGetProgramiv(d.shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
        glad_glGetProgramInfoLog(d.shaderProgram, 512, nullptr, infoLog);
        throw string("program link error\n") + infoLog;
    }
    
    
    glad_glDeleteShader(d.vertexShader);
    glad_glDeleteShader(d.fragmentShader);
    //
    glad_glGenVertexArrays(1, &d.VAO);
    glad_glGenBuffers(1, &d.VBO);
    
    glad_glBindVertexArray(d.VAO);
    
    glad_glBindBuffer(GL_ARRAY_BUFFER, d.VBO);
    
    Manager::manager.bufferData();
    
    glad_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
    glad_glEnableVertexAttribArray(0);
    
    glad_glBindVertexArray(0);
    
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
    
    //end
    glad_glDeleteVertexArrays(1, &VAO);
    glad_glDeleteBuffers(1, &VBO);
    
    glfwTerminate();
}
