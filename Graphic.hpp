//
//  Graphic.hpp
//  GLFWosxTEST1
//
//  Created by 王宇鑫 on 2017/9/7.
//  Copyright © 2017年 王宇鑫. All rights reserved.
//

#ifndef Graphic_hpp
#define Graphic_hpp

#include "OSinfo.h"

class Graphic
{
private:
    GLfloat* vertexBuffer;
    int number;
public:
    Graphic();
    GLfloat& operator[](int index);
    int size();
    GLfloat* pointer();
};

#endif /* Graphic_hpp */
