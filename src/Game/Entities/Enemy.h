#pragma once

#include "Entity.h"
#include "Fighting.h" 
#include "Animation.h"

class Enemy : public Entity , public Fighting{
    protected:
        Direction direction = Direction::down;
        int speed = 8;
        bool walking = false;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        string id;
        int moveTimer;
        bool dead = false;
        string enemyName;
        ofImage sprite;

    
    public:
        Enemy(string id, int health, int baseDamage, string enemyName, int ox, int oy);
        Enemy(string id, int health, int baseDamage, string enemyName, int ox, int oy, int ow, int oh, string overworlPath, string fightingsprite);
        ~Enemy();
        int getOX() { return ox; };
        int getOY() { return oy; };
        bool isDead() { return dead;};
        void kill() { this->dead = true;};
        void revive() { this->dead = false;};
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId(){ return id; };
        string getName(){ return enemyName; };
        ofImage getSprite() { return overworldSprite;};
};