//
//  WZW_GLWrapper.cpp
//  Multi-Phase
//
//  Created by ncut on 17/6/30.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#include "GLWrapper.h"
#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>

#define ERROR_CREATE_WINDOW_FAILED -1

using namespace WZW;

GLWrapper::GLWrapper(){
    int state = createWindow();
    if (state != ERROR_CREATE_WINDOW_FAILED) {
        init();
    }
}

void GLWrapper::drawSphere(GLdouble radius, GLint slices, GLint stacks, float* color, const float* translation){
    
    float speccolor [4] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR, speccolor);
    glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, 100.0);
    glColor3fv(color);
    
    glPushMatrix ();
    glTranslated ((translation)[0], (translation)[1], (translation)[2]);
    glutSolidSphere(radius, slices, stacks);
    glPopMatrix ();
}

void GLWrapper::init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.5f, 0.5f, -0.5f, 0.5f, 1.f, 1000.f);
    //glOrtho(-50.0f , 50.0f , -50.0f , 50.0f , -1.0f , 1000.0f );
}

void GLWrapper::setRenderMethod(RenderMethod render){
    this->render = render;
}

void GLWrapper::runMainLoop(){
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        if (render != nullptr) {
            render();
        }
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
}

int GLWrapper::createWindow(){
    
    /* Initialize the library */
    if (!glfwInit())
        return ERROR_CREATE_WINDOW_FAILED;
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(480, 320, "Hello World", nullptr, nullptr);
    if (window == nullptr){
        glfwTerminate();
        return ERROR_CREATE_WINDOW_FAILED;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glClearColor(255, 255, 255, 255);
    
    return 0;
}
