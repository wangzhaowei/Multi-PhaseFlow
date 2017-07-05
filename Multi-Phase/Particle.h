//
//  Particle.h
//  Multi-Phase
//
//  Created by ncut on 17/6/30.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#ifndef __Multi_Phase__Particle__
#define __Multi_Phase__Particle__

#include <stdio.h>
#include "MathType.h"
#include "SpaceGrid.h"

namespace WZW {
    class Particle : public virtual SpaceGridParticleDelegate{
    private:
        Vector3f position;
        Vector3f velocity;
        Vector3f acceleration;
        float pressure;
        float density0;
        float density;
        
        SpaceGridParticleDelegate* _next;
        
    public:
        SpaceGridParticleDelegate* getNext(){
            return _next;
        }
        
        void setNext(SpaceGridParticleDelegate* next){
            _next = next;
        }
        
        Vector3f getPosition(){
            return position;
        }
    };
}

#endif /* defined(__Multi_Phase__Particle__) */
