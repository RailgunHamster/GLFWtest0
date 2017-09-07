//
//  Graphic.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//

#include "Graphic.hpp"
#include <string>
#include <memory>
using namespace std;

//for test
GLfloat testBuffer[] = {
    -1, -1, 0,
    1, -1, 0,
    0, 1, 0,
};

Graphic::Graphic() : number(9)
{
    vertexBuffer = new GLfloat[number];
    memcpy(&vertexBuffer, testBuffer, sizeof(testBuffer));
}

GLfloat& Graphic::operator[](int index)
{
    if (!(index >= 0 && index < number))
        throw string("out of range");
    return vertexBuffer[index];
}
