//
//  SpaceGrid.cpp
//  Multi-Phase
//
//  Created by ncut on 17/7/4.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#include "SpaceGrid.h"

#define CELL_INDEX_EMPTY -1

using namespace WZW;

SpaceGrid::SpaceGrid(Vector3f min, Vector3f max, Vector3i resolution){
    _min = min;
    _max = max;
    _resolution = resolution;
    _heads.resize(resolution[0] * resolution[1] * resolution[2]);
    
    //_cellSize[0] = 1;
}

void SpaceGrid::resetCell(std::vector<SpaceGridParticleDelegate*> &particles){
    for (int i = 0; i < getHeads().size(); i++) {
        getHeads()[i] = nullptr;
    }
    
    for (int i = 0; i < particles.size(); i++) {
        SpaceGridParticleDelegate& particle = *(particles[i]);
        int cellIdx = findCell(particle.getPosition());
        if (cellIdx >= 0 && cellIdx < getHeads().size()) {
            particle.setNext(getHeads()[cellIdx]);
            getHeads()[cellIdx] = &particle;
        }
        else {
            particle.setNext(nullptr);
        }
    }
}

int SpaceGrid::findCell(Vector3f position){
    wzw_assert("WZW::SpaceGrid::findCell : The method has not done");
    return CELL_INDEX_EMPTY;
}