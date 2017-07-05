//
//  MathType.c
//  Multi-Phase
//
//  Created by ncut on 17/6/30.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#include "MathType.h"
#include <stdio.h>
#include <math.h>

using namespace WZW;

Kernals::Kernals(double smoothKernalRadius){
    Poly6Kernal = 315.0f / (64.0f * 3.141592f * pow(smoothKernalRadius, 9.0));
    SpikyKernal = -45.0f / (3.141592f * pow(smoothKernalRadius, 6.0));
    ViscosityKernal = 45.0f / (3.141592f * pow(smoothKernalRadius, 6.0));
}