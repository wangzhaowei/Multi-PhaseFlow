//
//  main.cpp
//  Multi-Phase
//
//  Created by ncut on 17/6/30.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#include <iostream>
#include "GLWrapper.h"
#include <GL/glew.h>
#include "SpaceGrid.h"

static const float vertex_list[][3] =
{
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
};

static const GLint index_list[][2] =
{
    {0, 1},
    {2, 3},
    {4, 5},
    {6, 7},
    {0, 2},
    {1, 3},
    {4, 6},
    {5, 7},
    {0, 4},
    {1, 5},
    {7, 3},
    {2, 6}
};

void DrawCube(void)
{
    int i,j;
    
    glColor3f(1.0, 0.0, 0.0);    // Red
    glBegin(GL_LINES);
    for(i=0; i<12; ++i) // 12 条线段
        
    {
        for(j=0; j<2; ++j) // 每条线段 2个顶点
            
        {
            glVertex3fv(vertex_list[index_list[i][j]]);
        }
    }
    glEnd();
}

void DrawTriangle(){
    /* Draw a triangle */
    glBegin(GL_TRIANGLES);
    
    glColor3f(1.0, 0.0, 0.0);    // Red
    glVertex3f(0.0, 1.0, 0.0);
    
    glColor3f(0.0, 1.0, 0.0);    // Green
    glVertex3f(-1.0, -1.0, 0.0);
    
    glColor3f(0.0, 0.0, 1.0);    // Blue
    glVertex3f(1.0, -1.0, 0.0);
    
    glEnd();
}

static float rotate = 0;
static int times = 0;

void render(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    
    times++;
    if(times > 10)
    {
        times = 0;
    }
    
    if(times % 10 == 0)
    {
        rotate += 0.3;
    }
    
    glTranslated(0, 0, -10);
    glRotatef(rotate, 0, 1, 0);
    glRotatef(rotate, 1, 0, 0);
    
    DrawCube();
    
    glPopMatrix();
    
    float color[3] = {0.f, 0.f, 255.f};
    float translation[5][3] = {
        {10.f, 0.f, -100.f},
        {-10.f, 0.f, -100.f},
        {0.f, 10.f, -100.f},
        {0.f, -10.f, -100.f},
        {0.f, 0.f, -100.f}
    };
    
    for (int i = 0; i < 5; i++) {
        WZW::GLWrapper::drawSphere(1, 25, 25, color, translation[i]);
    }
    
    //DrawTriangle();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    WZW::GLWrapper glWrapper;
    glWrapper.setRenderMethod(render);
    glWrapper.runMainLoop();
    
    return 0;
}
