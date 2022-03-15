#pragma once

#include "Entity.h"

class Orb : public Entity{
    private:
        string orbType;
        bool used = false;

    
    public:
        Orb(string entityName, string orbType, int ox, int oy, string orb);
        bool isUsed() { return used;};
        void consume() { this->used = true;};
        void respawn() { this->used = false;};
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getOrbType() { return orbType; };
};