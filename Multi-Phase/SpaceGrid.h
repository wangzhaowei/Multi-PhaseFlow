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
    class SpaceGridParticleDelegate{
    public:
        virtual Vector3f getPosition() =0;
        virtual SpaceGridParticleDelegate* getNext() =0;
        virtual void setNext(SpaceGridParticleDelegate* next) =0;
    };
    
    class SpaceGrid {
    private:
        //  This array stores IDs that are the maximum in each cell
        std::vector<SpaceGridParticleDelegate*> _heads;
        Vector3f _min;
        Vector3f _max;
        Vector3i _resolution;
        
        Vector3i _cellSize;
        
        std::vector<SpaceGridParticleDelegate*>& getHeads(){
            return _heads;
        }
        
    public:
        SpaceGrid(Vector3f min, Vector3f max, Vector3i resolution);
        
        //  This method re-calculate which particles contained in each cell
        void resetCell(std::vector<SpaceGridParticleDelegate*>& particles);
        
        //  This method calculate cell number with position
        //  The cell number start at 0
        int findCell(Vector3f position);
    };

}

#endif /* defined(__Multi_Phase__SpaceGrid__) */
