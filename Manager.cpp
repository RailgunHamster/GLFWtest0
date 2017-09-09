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
	cout << (*(graphics.front()))[0] << endl;
}

Manager& Manager::initManager()
{
	return *(new Manager());
}

void Manager::render()
{
    glad_glClearColor(0.2, 0.3, 0.3, 1.0);
	glad_glClear(GL_COLOR_BUFFER_BIT);
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
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
