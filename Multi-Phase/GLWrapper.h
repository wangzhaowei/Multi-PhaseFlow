//
//  WZW_GLWrapper.h
//  Multi-Phase
//
//  Created by ncut on 17/6/30.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#ifndef __Multi_Phase__WZW_GLWrapper__
#define __Multi_Phase__WZW_GLWrapper__

#include <stdio.h>
#include <vector>
#include <GL/glew.h>

class GLFWwindow;
namespace WZW{
    typedef void (*RenderMethod)();
    
    class GLWrapper {
    private:
        GLFWwindow* window;
        
        RenderMethod render;
        
    public:
        GLWrapper();
        
        void runMainLoop();
        
        void setRenderMethod(RenderMethod render);
        
        static void drawSphere(GLdouble radius, GLint slices, GLint stacks, float* color, const float* translation);
        
    private:
        int createWindow();
        
        void init();
    };
};

#endif /* defined(__Multi_Phase__WZW_GLWrapper__) */
