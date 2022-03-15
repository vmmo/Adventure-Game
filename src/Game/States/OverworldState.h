#pragma once

#include "State.h"
#include "Area.h"
#include "Player.h"
#include "Enemy.h"
#include "StaticTree.h"
#include "Orb.h"
#include "Boss.h"
#include "OverworldCamera.h"

class OverworldState : public State
{
    private:
        ofImage overworldImage;
        Player *player;
        OverworldCamera *camera;
        Area *area;
        std::vector<Enemy*> enemies;
        Enemy *enemy;
        StaticTree *tree;
        std::vector<Boss*> bosses;
        Boss *boss;
        Orb *orb;
        
    public:
        OverworldState(Player *player, Area *area);
        Player* getPlayer() { return player;};
        void setEnemy(Enemy *enemy) { this->enemy = enemy;};
        Enemy* getEnemy() { return enemy;};
        void setStaticTree(StaticTree *tree) { this->tree = tree;};
        StaticTree* getStaticTree() { return tree;};
        void setBoss(Boss *boss) { this->boss = boss;};
        Boss* getBoss() { return boss;};
        void setOrb(Orb *orb) { this->orb = orb;};
        Orb* getOrb() { return orb;};
        void loadArea(Area *Area);
        Area* getArea() { return area;};
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        bool otherAreas = false;
};