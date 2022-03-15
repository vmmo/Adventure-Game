#pragma once

#include "Player.h"
#include "Enemy.h"
#include "StaticTree.h"
#include "Orb.h"
#include "Boss.h"
#include "Friend.h"
#include "OverworldCamera.h"

class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<Enemy*> enemies;
        std::vector<StaticTree*> trees;
        std::vector<Boss*> bosses;
        std::vector<Friend*> friends;
        std::vector<Orb*> orbs;
        Area *nextArea;
    public:
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<Boss*> bosses, vector<StaticTree*> trees, vector<Orb*> orbs, vector<Friend*> friends);
        //Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<Boss*> bosses, vector<StaticTree*> trees, vector<Orb*> orbs);
        void resetEnemies();
        ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        vector<Enemy*> getEnemies() { return enemies;};
        void setBoss(std::vector<Boss*> boss) { this->bosses = bosses;};
        std::vector<Boss*> getBoss() { return bosses;};
        std::vector<Friend*> getFriends() {return friends;};
        void setFriends(std::vector<Friend*> friends) {this-> friends = friends;};
        void setStaticTrees(std::vector<StaticTree*> trees) { this->trees = trees;};
        vector<StaticTree*> getTrees() { return trees;};
        void setOrbs(std::vector<Orb*> orbs) { this->orbs = orbs;};
        vector<Orb*> getOrbs() { return orbs;};
        int getRemainingEnemies();
        int getRemainingBoss();
        Area* getNextArea() { return nextArea;};
        
};