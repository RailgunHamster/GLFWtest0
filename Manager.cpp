//
//  Manager.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//

#include "Manager.hpp"
#include "Displayer.hpp"
#include <iostream>
using namespace std;

Manager& Manager::manager = Manager::initManager();

Manager::Manager()
{
	graphics.push_back(new Graphic());
}

Manager& Manager::initManager()
{
	return *(new Manager());
}

void Manager::render()
{
    glad_glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glad_glClear(GL_COLOR_BUFFER_BIT);
    //
    glad_glUseProgram(Displayer::displayer.shaderProgram);
    glad_glBindVertexArray(Displayer::displayer.VAO);
//    glad_glDrawArrays(GL_TRIANGLES, 0, 3);
    glad_glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glad_glBindVertexArray(0);
}

void Manager::bufferData()
{
    glad_glBufferData(GL_ARRAY_BUFFER, graphics.front()->size(), graphics.front()->pointer(), GL_STATIC_DRAW);
    glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER, graphics.front()->indicesSize(), graphics.front()->getIndices(), GL_STATIC_DRAW);
}

void Manager::mainloop()
{
    Displayer::displayer.mainloop();
}

void Manager::errorCallback(int error, const char* description)
{
	cerr << "error NO." << error << " : " << description << endl;
}

void Manager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
    else if (key == GLFW_KEY_L && action == GLFW_PRESS)
        glad_glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else if (key == GLFW_KEY_F && action == GLFW_PRESS)
        glad_glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
