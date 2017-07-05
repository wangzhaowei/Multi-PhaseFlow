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

SpaceGrid::SpaceGrid(Vector3f min, Vector3f max, Vector3i resolution, float sim_scale, float border){
    
    // Ideal grid cell size (gs) = 2 * smoothing radius = 0.02*2 = 0.04
    // Ideal domain size = k*gs/d = k*0.02*2/0.005 = k*8 = {8, 16, 24, 32, 40, 48, ..}
    //    (k = number of cells, gs = cell size, d = simulation scale)
    _min = min;
    _max = max;
    _resolution = resolution;
    _heads.resize(resolution[0] * resolution[1] * resolution[2]);
    _gridSize = max - min;
    _cellSize = Vector3i::Vector3(_gridSize[0] / resolution[0], _gridSize[1] / resolution[1], _gridSize[2] / resolution[2]);
    
    //_cellSize[0] = 1;
}

void SpaceGrid::insertParticles(std::vector<SpaceGridParticle*> &particles){
    for (int i = 0; i < getHeads().size(); i++) {
        getHeads()[i] = nullptr;
    }
    
    for (int i = 0; i < particles.size(); i++) {
        SpaceGridParticle& particle = *(particles[i]);
        int cellIdx = getGridCellIndex(particle.getPosition());
        if (cellIdx >= 0 && cellIdx < getHeads().size()) {
            particle.setNext(getHeads()[cellIdx]);
            getHeads()[cellIdx] = &particle;
        }
        else {
            particle.setNext(nullptr);
        }
    }
}

int SpaceGrid::getGridCellIndex(Vector3f pos){
    Vector3i cellIdx = getGridCellIndexVec3i(pos);
    
    return (int)((cellIdx[2] * get_resolution()[2] + cellIdx[1]) * get_resolution()[0] + cellIdx[0]);
}

Vector3i SpaceGrid::getGridCellIndexVec3i(Vector3f pos){
    Vector3f disVec3f = pos - _min;
    return Vector3i::Vector3((int)floorf(disVec3f[0] / _cellSize[0]),
                             (int)floorf(disVec3f[1] / _cellSize[1]),
                             (int)floorf(disVec3f[2] / _cellSize[2]));
}

void SpaceGrid::findCells(Vector3f position, float radius, int* gridCell){
    for (int i = 0; i < 8; i++) {
        gridCell[i] = CELL_INDEX_EMPTY;
    }
    Vector3i cellIdx = getGridCellIndexVec3i(position);
    if ( cellIdx[0] < 0 ) cellIdx[0] = 0;
    if ( cellIdx[1] < 0 ) cellIdx[1] = 0;
    if ( cellIdx[2] < 0 ) cellIdx[2] = 0;
    
    Vector3i gridRes = getResolutionReference();
    gridCell[0] = (cellIdx[0] * gridRes[1] + cellIdx[1]) * gridRes[0] + cellIdx[0];
    gridCell[1] = gridCell[0] + 1;
    gridCell[2] = (int)(gridCell[0] + gridRes[0]);
    gridCell[3] = gridCell[2] + 1;
    
    if (cellIdx[2] + 1 < gridRes[2]) {
        gridCell[4] = (int)(gridCell[0] + gridRes[2] * gridRes[0]);
        gridCell[5] = gridCell[4] + 1;
        gridCell[6] = (int)(gridCell[4] + gridRes[0]);
        gridCell[7] = gridCell[6] + 1;
    }
    if (cellIdx[0] + 1 >= gridRes[0]) {
        gridCell[1] = -1;		gridCell[3] = -1;
        gridCell[5] = -1;		gridCell[7] = -1;
    }
    if (cellIdx[1] + 1 >= gridRes[1]) {
        gridCell[2] = -1;		gridCell[3] = -1;
        gridCell[6] = -1;		gridCell[7] = -1;
    }
}