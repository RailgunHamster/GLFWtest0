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
    /*
    -0.5, -0.5, 0,
    0.5, -0.5, 0,
    0, 0.5, 0,
     */
    0.5f, 0.5f, 0.0f,   // 右上角
    0.5f, -0.5f, 0.0f,  // 右下角
    -0.5f, -0.5f, 0.0f, // 左下角
    -0.5f, 0.5f, 0.0f   // 左上角
};

GLuint testIndices[] = {
    0, 1, 3,
    1, 2, 3
};

Graphic::Graphic() : number(12)
{
    vertexBuffer = new GLfloat[number];
    indices = new GLuint[sizeof(testIndices)];
	memcpy(vertexBuffer, testBuffer, sizeof(GLfloat) * number);
    memcpy(indices, testIndices, sizeof(GLuint) * sizeof(indices));
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

int Graphic::indicesSize()
{
    return sizeof(testIndices) * sizeof(GLuint);
}

GLuint* Graphic::getIndices()
{
    return indices;
}
