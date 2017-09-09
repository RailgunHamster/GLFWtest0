//
//  Manager.hpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//

#ifndef Manager_hpp
#define Manager_hpp
#include <list>
using namespace std;
#include "Graphic.hpp"

class Manager
{
private:
	static Manager& initManager();
    list<Graphic*> graphics;
public:
	static void errorCallback(int error, const char* description);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static Manager& manager;
    Manager();
	void mainloop();
	void render();
    void bufferData();
};

#endif /* Manager_hpp */
