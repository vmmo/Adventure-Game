#include "Area.h"

Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<Boss*> bosses, vector<StaticTree*> trees, vector<Orb*> orbs, vector<Friend*> friends)
{
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this-> bosses = bosses;
    this-> friends = friends;
    this->trees = trees;
    this->orbs = orbs;
}

/*Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, vector<Boss*> bosses, vector<StaticTree*> trees, vector<Orb*> orbs)
{

}*/

void Area::resetEnemies(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        enemies.at(i)->revive();
    }
}

int Area::getRemainingEnemies(){
    int count = 0;
    for(unsigned int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            count++;
        }
    }
    return count;
}

int Area::getRemainingBoss(){
    int count = 0;
    for(unsigned int i = 0; i < bosses.size(); i++){
        if(!bosses.at(i)->isDead()){
            count++;
        }
    }
    return count;
}
