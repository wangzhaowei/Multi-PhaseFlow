//
//  SPH.h
//  Multi-Phase
//
//  Created by ncut on 17/7/3.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#ifndef __Multi_Phase__SPH__
#define __Multi_Phase__SPH__

#include <stdio.h>
#include <vector>
#include "Particle.h"
#include "MathType.h"

namespace WZW {
    //  Traditional SPH
    class SPH{
    private:
        std::vector<Particle> _particles;
        WZW::Kernals _kernals;
        WZW_PRIVATE_PROPERTY(double, _smoothRadius);
        
    protected:
        virtual void computePressure();
        virtual void computeForce();
        virtual void advance();
        
    public:
        SPH(int numberOfParticles, double smoothKernalRadius):_kernals(smoothKernalRadius){
            _particles.reserve(numberOfParticles);
            _smoothRadius = smoothKernalRadius;
        }
        
        virtual void step(float dt);
    };
}

#endif /* defined(__Multi_Phase__SPH__) */
