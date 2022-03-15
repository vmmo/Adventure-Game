#include "Boss.h"

Boss::Boss(string id, int health, int baseDamage, string enemyName, int ox, int oy, int ow, int oh, string overworlPath, string fightingsprite) : Enemy(id, health, baseDamage, enemyName, ox, oy, ow, oh, overworlPath, fightingsprite)
{
    this->id = id;
    this->enemyName = enemyName;
    vector<ofImage> fightingFrames = {};
    ofImage temp;

    temp.load("images/entities/" + enemyName + "/fightingframes/" + enemyName + "-f1.png");
    fightingFrames.push_back(temp);

    fighting = new Animation(7, fightingFrames);
}

Boss::Boss(string id, int health, int baseDamage, string enemyName, int ox, int oy) : Boss(id, health, baseDamage, enemyName, ox, oy, 120, 120, "images/entities/Boss1/Boss1.png", "images/entities/fightingframes/Boss1-f1.png")
{

}

void Boss::tickOverworld()
{

}

void Boss::renderOverworld()
{
    // uncomment these if you want the coordinates of the bosses in the current area
    // ofDrawBitmapString("rX:" + to_string(renderX), 100 + 125 * ((stoi(id) % 10) - 1), 100);
    // ofDrawBitmapString("rY:" + to_string(renderY), 100 + 125 * ((stoi(id) % 10) - 1), 120);
    // ofDrawBitmapString("ow:" + to_string(ox), 100 + 125 * ((stoi(id) % 10) - 1), 140);
    // ofDrawBitmapString("oy:" + to_string(oy), 100 + 125 * ((stoi(id) % 10) - 1), 160);
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void Boss::tickFighting()
{
    fightingSprite = fighting->getCurrentFrame();
    fighting->tick();
}

void Boss::keyPressed(int key)
{

}

void Boss::keyReleased(int key)
{

}

void Boss::reset()
{

}

Boss::~Boss()
{
    delete fighting;
}