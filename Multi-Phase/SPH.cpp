//
//  SPH.cpp
//  Multi-Phase
//
//  Created by ncut on 17/7/3.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#include "SPH.h"

using namespace WZW;

void SPH::step(float dt){
    computePressure();
    computeForce();
    advance();
}

void SPH::computePressure(){
    wzw_assert("The method has not done");
    
    //h^2
    float h2 = _smoothRadius * _smoothRadius;
}

void SPH::computeForce(){
    wzw_assert("The method has not done");
}

void SPH::advance(){
    wzw_assert("The method has not done");
}