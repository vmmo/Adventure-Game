#pragma once

#include "Enemy.h"
#include "Animation.h"

class Boss : public Enemy{
    
    public:
        Boss(string id, int health, int baseDamage, string enemyName, int ox, int oy);
        Boss(string id, int health, int baseDamage, string enemyName, int ox, int oy, int ow, int oh, string overworlPath, string fightingsprite);
        ~Boss();
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
};