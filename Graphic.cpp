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
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f
};

GLuint testIndices[] = {
    0, 1, 3,
    1, 2, 3
};

Graphic::Graphic() : number(sizeof(testBuffer) / sizeof(GLfloat))
{
    vertexBuffer = new GLfloat[number];
    indices = new GLuint[sizeof(testIndices) / sizeof(GLuint)];
	memcpy(vertexBuffer, testBuffer, sizeof(GLfloat) * number);
    memcpy(indices, testIndices, sizeof(testIndices));
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
    return sizeof(testIndices);
}

GLuint* Graphic::getIndices()
{
    return indices;
}
