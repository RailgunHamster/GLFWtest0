//
//  Graphic.cpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//

#include "Graphic.hpp"
#include <string>
using namespace std;

//for test
GLfloat testBuffer[] = {
    -0.5, -0.5, 0,
    0.5, -0.5, 0,
    0, 0.5, 0,
};

Graphic::Graphic() : number(9)
{
    vertexBuffer = new GLfloat[number];
	memcpy(vertexBuffer, testBuffer, sizeof(GLfloat) * number);
}

GLfloat& Graphic::operator[](int index)
{
    if (!(index >= 0 && index < number))
        throw string("out of range");
    return vertexBuffer[index];
}

int Graphic::size()
{
    return number * sizeof(GLfloat);
}

GLfloat* Graphic::pointer()
{
    return vertexBuffer;
}
