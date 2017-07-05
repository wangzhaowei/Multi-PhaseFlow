//
//  SpaceGrid.h
//  Multi-Phase
//
//  Created by ncut on 17/7/4.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#ifndef __Multi_Phase__SpaceGrid__
#define __Multi_Phase__SpaceGrid__

#include <stdio.h>
#include <vector>
#include <MathType.h>

namespace WZW {
    class SpaceGridParticle{
    public:
        virtual Vector3f getPosition() =0;
        virtual SpaceGridParticle* getNext() =0;
        virtual void setNext(SpaceGridParticle* next) =0;
    };
    
    class SpaceGrid {
    private:
        //  This array stores IDs that are the maximum in each cell
        std::vector<SpaceGridParticle*> _heads;
        std::vector<SpaceGridParticle*>& getHeads(){
            return _heads;
        }
        
        Vector3i& getResolutionReference(){
            return _resolution;
        }
        
        WZW_PRIVATE_PROPERTY(Vector3f, _min);
        WZW_PRIVATE_PROPERTY(Vector3f, _max);
        WZW_PRIVATE_PROPERTY(Vector3i, _resolution);
        WZW_PRIVATE_PROPERTY(Vector3i, _cellSize);
        WZW_PRIVATE_PROPERTY(Vector3f, _gridSize);
        
//        Vector3f _min;
//        Vector3f _max;
//        Vector3i _resolution;
        
//        Vector3i _cellSize;
        
    public:
        
        SpaceGridParticle* getGridParticleAtIndex(int idx){
            if (idx < 0 || idx >= getHeads().size()) {
                wzw_assert("the idx out of range");
                return nullptr;
            }
            
            return getHeads()[idx];
        }
        
        SpaceGrid(Vector3f min, Vector3f max, Vector3i resolution, float sim_scale, float border);
        
        //  This method re-calculate which particles contained in each cell
        void insertParticles(std::vector<SpaceGridParticle*>& particles);
        
        //  This method calculate cell number with position
        //  The cell number start at 0
        int getGridCellIndex(Vector3f pos);
        
        Vector3i getGridCellIndexVec3i(Vector3f pos);
        
        
        void findCells(Vector3f pos, float radius, int* gridCell);
    };

}

#endif /* defined(__Multi_Phase__SpaceGrid__) */
