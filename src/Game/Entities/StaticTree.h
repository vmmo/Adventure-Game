#pragma once

#include "Entity.h"

class StaticTree : public Entity{
    
    public:
        StaticTree(string entityName, int ox, int oy);
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
};